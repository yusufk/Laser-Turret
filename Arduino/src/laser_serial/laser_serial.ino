#include <TinkerKit.h>
#include <Servo.h> 

TKLed led(O2);
Servo servo1;  
Servo servo2;  

void setup() 
{ 
  servo1.attach(O0);
  servo2.attach(O1);
  Serial.begin(9600);
  Serial.println("Power on, Ready.");
} 

void loop()
{
  

  static int v = 0;

  if ( Serial.available()) {
    char ch = Serial.read();

    switch(ch) {
      case '0'...'9':
        v = v * 10 + ch - '0';
        break;
      case 'x':
        servo1.write(v);
        v = 0;
        Serial.print(servo1.read());
        Serial.print(',');
        Serial.println(servo2.read()); 
        break;
      case 'a':
        led.on();
        break;
      case 'z':
        led.off();
        break;
      case 'y':
        servo2.write(v);
        v = 0;
        Serial.print(servo1.read());
        Serial.print(',');
        Serial.println(servo2.read()); 
        break;
      //case 'd':
      //  servo2.detach();
      //  break;
      //case 'a':
      //  servo2.attach(15);
      //  break;
    }
  }
}
