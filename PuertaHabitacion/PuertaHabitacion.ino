// Pines de Led`s//
int pinR = 50;
int pinG = 51;

int led_azul_1 = 22;
int led_azul_2 = 23;
int led_azul_3 = 24;
int led_azul_4 = 25;


// Pines de Botones//
int boton1 = 44;
int boton2 = 42;
int boton3 = 45;
int boton4 = 43;
int estadoboton1 = 0;
int estadoboton2 = 0;
int estadoboton3 = 0;
int estadoboton4 = 0;
bool est_bot1 = false;
bool est_bot2 = false;
bool est_bot3 = false;
bool est_bot4 = false;
bool est_bot_reset = false;

//Pin Servo//
#include<Servo.h>
Servo servo;
int posicion = 0;

//Pin LCD//
#include<LiquidCrystal.h>
const int rs = 37, en = 36, d4 = 32, d5 = 33, d6 = 34, d7 = 35;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {

  //Tipo de pin LED's//
  pinMode(pinR,OUTPUT);
  pinMode(pinG,OUTPUT);
  pinMode(led_azul_1, OUTPUT);
  pinMode(led_azul_2, OUTPUT);
  pinMode(led_azul_3, OUTPUT);
  pinMode(led_azul_4, OUTPUT);
  
  //Tipo de pin Botones//
  pinMode(boton1,INPUT);
  pinMode(boton2,INPUT);
  pinMode(boton3,INPUT);
  pinMode(boton4,INPUT);
  Serial.begin(9600);

  //Pin del Servo//
  servo.attach(3);
  servo.write(100);
  

  //Pin LCD//
  lcd.begin(16,2);
  lcd.print("contrasena porfa");
 
}

void loop() {
  estadoboton1 = digitalRead(boton1);
  estadoboton2 = digitalRead(boton2);
  estadoboton3 = digitalRead(boton3);
  estadoboton4 = digitalRead(boton4);
 

    if (estadoboton2 == HIGH && est_bot1 == false && est_bot3 == false && est_bot4 == false ){
      digitalWrite(led_azul_2, HIGH);
      est_bot2 = true;
      servo.write(80);
    }
      
    if(estadoboton3 == HIGH && est_bot2 == true && est_bot1 == false && est_bot4 == false){
      digitalWrite(led_azul_3, HIGH);
      est_bot3 = true;
      servo.write(50);
      }

    if (estadoboton1 == HIGH && est_bot2 == true && est_bot3 == true && est_bot4 == false){
      digitalWrite(led_azul_1, HIGH);
      est_bot1 = true;
      servo.write(25);  
      } 
      
    if (estadoboton4 == HIGH && est_bot2 == true && est_bot3 == true && est_bot1 == true){
      digitalWrite(pinG, HIGH);
      digitalWrite(led_azul_4,HIGH);
      servo.write(0);
      lcd.print("adelante pase");
      }
   
}
