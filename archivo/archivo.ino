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
boolean servo = false;
boolean servo2 = false;
boolean motor = false;
 
void setup() 
{ 
    myservo.attach(8); // asocia el servo al pin 8
    myservo2.attach(7);
    pinMode(2,OUTPUT);
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
        if (c=='1'){
          if (servo){
            Serial.write("\nParando servo");
            servo = false;
          }else{
            Serial.write("\nArrancando servo");
            servo = true;
          }
          
        }
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
          if (servo2){
            Serial.write("\nParando servo");
            servo2 = false;
          }else{
            Serial.write("\nArrancando servo");
            servo2 = true;
          }
          
        }
        if (c=='0'){
          motor = false;
          servo = false;
          digitalWrite(2,LOW);
        }
    }
 
    // Keep reading from Arduino Serial Monitor and send to HC-05
    if (Serial.available())
    {
        c =  Serial.read();
        BTserial.write(c);  
    }
    if (servo or servo2){
      if (servo){
        myservo.write(val2);
      }
      if (servo2){
        myservo2.write(val1);
        
      }
      val1 = val1 + a;// espera a que el servo se posicione
      val2 = val2 - a;
      if (val1 > 120 or val1 < 40){
        a = -a;        
      }
      delay(15);
    }
}

