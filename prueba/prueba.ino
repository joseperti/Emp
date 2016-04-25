// Basic Bluetooth sketch HC-05_AT_MODE_01
// Communicate with a HC-05 using the serial monitor
//
// The HC-05 defaults to communication mode when first powered on you will need to manually enter AT mode
// The default baud rate for AT mode is 38400
// See www.martyncurrey.com for details
//
 
 
#include <SoftwareSerial.h>
#include <Servo.h>
Servo myservo;
Servo myservo2;
SoftwareSerial BTserial(10,11); // RX | TX
// Connect the HC-05 TX to Arduino pin 2 RX. 
// Connect the HC-05 RX to Arduino pin 3 TX through a voltage divider.
// 

int val1 = 50;
int val2 = 110;
int a = 1;
char c = ' ';
boolean motor = false;
boolean motor3 = false;
 
void setup() 
{ 
    myservo.attach(8);
    myservo.write(50);
    myservo2.attach(7);
    myservo2.write(50);
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    Serial.begin(9600);
    Serial.println("Arduino is ready");
    Serial.println("Remember to select Both NL & CR in the serial monitor");
    Serial.println("Enter AT commands:");
 
    // HC-05 default serial speed for AT mode is 38400
    BTserial.begin(9600);  
}
 
void loop()
{
 
    // Keep reading from HC-05 and send to Arduino Serial Monitor
    if (BTserial.available())
    {  
        c = BTserial.read();
        Serial.write(c);
        if (c=='2'){
          if (motor){
            Serial.write("\nParando motor");
            digitalWrite(2,LOW);
            motor = false;
          }else{
            Serial.write("\nArrancando motor");
            digitalWrite(2,HIGH);
            motor = true;
          }
        }
        if (c == '3'){
          if (motor3){
            Serial.write("\nParando motor");
            digitalWrite(3,LOW);
            motor3 = false;
          }else{
            Serial.write("\nArrancando motor");
            digitalWrite(3,HIGH);
            motor3 = true;
          }
          
        }
        if (c=='0'){
          digitalWrite(2,LOW);
          digitalWrite(3,LOW);
        }
    }
 
    // Keep reading from Arduino Serial Monitor and send to HC-05
    if (Serial.available())
    {
        c =  Serial.read();
        BTserial.write(c);  
    }
}

