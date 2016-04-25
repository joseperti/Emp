// Controlando la posición de un servo usando un potenciómetro (resistencia variable)
// Por Michal Rinott

#include <Servo.h> // Carga la librería Servo.h que contiene métodos para trabajar con servos

Servo myservo;  // Crea un objeto servo para controlar el servomotor
int potpin = 0; // Pin analógico usado para conectar el potenciómetro
int val = 50;        // variable para leer el valor del pin analógico
int c = 1;

void setup()
{
myservo.attach(9); // asocia el servo al pin 9
pinMode(8,OUTPUT);
digitalWrite(8,HIGH);
}

void loop()
{
myservo.write(val);        // fija la posición del servo de acuerdo
                           //al valor escalado
delay(15);     
val = val + c;// espera a que el servo se posicione
if (val > 120 or val < 40){
  c = -c;
  if( c<0){
    digitalWrite(8,LOW);
  }else{
    digitalWrite(8,HIGH);
  }
  
}
}
