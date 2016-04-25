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

int val = 50;
int a = 1;
char c = ' ';
String cadena = "";
int valor;
boolean aleteo = false;
int pos = 1;
boolean motor = false;
 
void setup() 
{ 
    Serial.begin(9600);
    myservo.attach(8); // asocia el servo al pin 8
    myservo.write(120);
}
 
void loop()
{
 
    if (val > 90 or val < 40){
      a = -a;
    }
    val += a;
    Serial.print("Escrito valor: ");
    Serial.println(val);
    myservo.write(val);
    delay(30);

}

