#include <AFMotor.h>
# include <SoftwareSerial.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

SoftwareSerial serial(9,10); //rx tx

char val;

void setup() {

  motor1.setSpeed(250);
  motor2.setSpeed(250);
  motor3.setSpeed(250);
  motor4.setSpeed(250);

  serial.begin(9600);

}

void loop() {

if (serial.available()> 0){
  val = serial.read (); 
  }
  switch (val){

    case 'a':
adelante ();
  break;

    case 'b':
atras ();
    break;
    
    case 'c':
derecha_360 ();
    break;
    
    case 'd':
izquierda_360 ();
    break;
    
case 'e':
derecha ();
    break;
    
case 'f':
izquierda ();
    break;
    
   default:
para ();
    break;
}
}

void adelante ()// letra a
{
  
motor1.run (FORWARD); 
motor2.run (FORWARD); 
motor3.run (FORWARD); 
motor4.run (FORWARD); 

}

void atras () // letra b
{
  
motor1.run (BACKWARD); 
motor2.run (BACKWARD); 
motor3.run (BACKWARD); 
motor4.run (BACKWARD); 

}

void derecha_360 () // letra c
{
  
motor1.run (BACKWARD); 
motor2.run (FORWARD); 
motor3.run (FORWARD); 
motor4.run (BACKWARD); 

}

void izquierda_360() // letra d
{
  
motor1.run (FORWARD); 
motor2.run (BACKWARD); 
motor3.run (BACKWARD); 
motor4.run (FORWARD); 

}


void derecha () // letra e 
{
  
motor1.run (FORWARD); 
motor2.run (RELEASE); 
motor3.run (RELEASE); 
motor4.run (FORWARD); 

}

void izquierda () // letra f 
{
  
motor1.run (RELEASE); 
motor2.run (FORWARD); 
motor3.run (FORWARD); 
motor4.run (RELEASE); 

}

void para () // boton para parra 
{
  
motor1.run (RELEASE); 
motor2.run (RELEASE); 
motor3.run (RELEASE); 
motor4.run (RELEASE); 

}
