//Partie Evan :
#include <Stepper.h>

// nombre_pas;
//nombre_pass_code;
int nombre_pas_actuel;
int hauteur_personne;
int pas_vis=2;

float nombre_pas_code=hauteur_personne/2;
float nombre_pas=(nombre_pas_code-nombre_pas_actuel);

// nombre_pas_enrolement;
// hauteur_personne_enregistree;
int sequences;
int x;

float nombre_pas_enrolement=x*sequences; //problème: comment récupérer x?
float hauteur_personne_enregistree=nombre_pas_enrolement*2;

int sequences_montees;

int pinI1=2;//define I1 port
int pinI2=3;//define I2 port

int speedpin1=10;//define EA(PWM speed regulation)port

int pinI3=4;//define I1 port
int pinI4=5;//define I2 port

int speedpin2=11;//define EA(PWM speed regulation)port

int capteur_init = 12; //microrupteur
//int capteur_camera = 8;




//Partie Guilhem
#include <Wire.h>
int valeur;
int boutton;
int etat;







void setup() {
  // put your setup code here, to run once:

//Partie Evan
pinMode(pinI1,OUTPUT);//define this port as output
pinMode(pinI2,OUTPUT);

pinMode(pinI3,OUTPUT);//define this port as output
pinMode(pinI4,OUTPUT);

pinMode(speedpin1,OUTPUT);
pinMode(speedpin2,OUTPUT);

pinMode(capteur_init,INPUT);




//Partie Guilhem
pinMode(3, OUTPUT); //Pins LED
pinMode(6, OUTPUT); 

pinMode(7, INPUT); //Pins retour Cam

pinMode(8, INPUT); //Pins Boutton 

Serial.begin(9600);

etat = 0;

}






void loop() {
  // put your main code here, to run repeatedly:






//Partie Evan
// séquence d'initialisation: le système va chercher sa position basse pour initialiser le pas courant
 do
 {
   analogWrite(speedpin1,255);//input a value to set the speed
   analogWrite(speedpin2,255);//input a value to set the speed
   
   delay(5);
   
   digitalWrite(pinI1,HIGH);// DC motor rotates clockwise
   digitalWrite(pinI2,LOW);
   digitalWrite(pinI3,LOW);// DC motor rotates clockwise
   digitalWrite(pinI4,LOW);
   
   delay(5);
   
   digitalWrite(pinI1,LOW);// DC motor rotates clockwise
   digitalWrite(pinI2,HIGH);
   digitalWrite(pinI3,LOW);// DC motor rotates clockwise
   digitalWrite(pinI4,LOW);
   
   delay(5);
   
   digitalWrite(pinI1,LOW);// DC motor rotates clockwise
   digitalWrite(pinI2,LOW);
   digitalWrite(pinI3,HIGH);// DC motor rotates clockwise
   digitalWrite(pinI4,LOW);
   
   delay(5);
   
   digitalWrite(pinI1,LOW);// DC motor rotates clockwise
   digitalWrite(pinI2,LOW);
   digitalWrite(pinI3,LOW);// DC motor rotates clockwise
   digitalWrite(pinI4,HIGH);
   
   delay(5);

 }
 
 while(capteur_init == 0);
 nombre_pas_actuel=0;
 
 




//Partie Guilhem 
 if (digitalRead(8)==1) {
  etat = etat+1;
  
  if (etat > 1) {
   etat = 0;
  }
  
  digitalWrite(13, HIGH);  
  Serial.println("L'état du boutton est : ");
  Serial.println(etat);
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  




//Partie Evan
 //Descend jusqu'à actionner le bouton
 do{
   analogWrite(speedpin1,255);//input a value to set the speed
   analogWrite(speedpin2,255);//input a value to set the speed
   
   delay(5);
   
   digitalWrite(pinI1,HIGH);// DC motor rotates clockwise
   digitalWrite(pinI2,LOW);
   digitalWrite(pinI3,LOW);// DC motor rotates clockwise
   digitalWrite(pinI4,LOW);
   
   delay(5);
   
   digitalWrite(pinI1,LOW);// DC motor rotates clockwise
   digitalWrite(pinI2,HIGH);
   digitalWrite(pinI3,LOW);// DC motor rotates clockwise
   digitalWrite(pinI4,LOW);
   
   delay(5);
   
   digitalWrite(pinI1,LOW);// DC motor rotates clockwise
   digitalWrite(pinI2,LOW);
   digitalWrite(pinI3,HIGH);// DC motor rotates clockwise
   digitalWrite(pinI4,LOW);
   
   delay(5);
   
   digitalWrite(pinI1,LOW);// DC motor rotates clockwise
   digitalWrite(pinI2,LOW);
   digitalWrite(pinI3,LOW);// DC motor rotates clockwise
   digitalWrite(pinI4,HIGH);
   
   delay(5);
  
 }while(capteur_init == 0);


 
 
 
 //Partie Guilhem
 Serial.println("##########");
 valeur = digitalRead(8);
 
 delay(1000);
 
 Serial.println("Détection des yeux : ");
 Serial.println(valeur);
 
 Serial.println("L'état du boutton est : ");
 Serial.println(etat);





 //Partie Evan
 //dès que microrupteur actionné, passer à la phase de montée
 do{
   analogWrite(speedpin1,255);//input a value to set the speed
   analogWrite(speedpin2,255);//input a value to set the speed
   
   delay(5);
   
   digitalWrite(pinI1,LOW);// DC motor rotates clockwise
   digitalWrite(pinI2,LOW);
   digitalWrite(pinI3,LOW);// DC motor rotates clockwise
   digitalWrite(pinI4,HIGH);
   
   delay(5);
   
   digitalWrite(pinI1,LOW);// DC motor rotates clockwise
   digitalWrite(pinI2,LOW);
   digitalWrite(pinI3,HIGH);// DC motor rotates clockwise
   digitalWrite(pinI4,LOW);
   
   delay(5);
   
   digitalWrite(pinI1,LOW);// DC motor rotates clockwise
   digitalWrite(pinI2,HIGH);
   digitalWrite(pinI3,LOW);// DC motor rotates clockwise
   digitalWrite(pinI4,LOW);
   
   delay(5);
   
   digitalWrite(pinI1,HIGH);// DC motor rotates clockwise
   digitalWrite(pinI2,LOW);
   digitalWrite(pinI3,LOW);// DC motor rotates clockwise
   digitalWrite(pinI4,LOW);
   
   delay(5);

 }
 
 while(valeur==0);
 
  
 }

  //Partie Guilhem
 if (etat == 0) {
  
 delay(1000);
 
 Serial.println("Détection des yeux : ");
 Serial.println(valeur);  
 Serial.println("/////");
 delay(1000);
 Serial.println("L'état du boutton est : ");
 Serial.println(etat);
 delay(1000);
 Serial.println("/////");
 Serial.println("EVAN =");
 Serial.println(capteur_init);

 
  digitalWrite(13, LOW);
  digitalWrite(3,HIGH);
  digitalWrite(2,LOW);
 } 

}
