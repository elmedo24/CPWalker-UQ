#include "Exo.h"
#include <Timer.h>
#include "wifi.h"
//Variables
Exo myExo;
wifi comunicacion;
//Timer
Timer t;
short ID;
float amp;
int vel;
char aux = 0;
//General Purpouse
uint8_t Ts = 50;  // Setting Ts = 0.01s
String n;

int protocolo[7];
// comunicacion

void setup() {
  myExo.Begin(); //Set initial angle in each servo
  /*
  myExo.setAngle(RKNEE_ID,90);
  myExo.setAngle(LKNEE_ID,90);
  myExo.setAngle(RHIP_ID,60);
  myExo.setAngle(LHIP_ID,60);
  /**/
  
  delay(500);
  myExo.disconect();
  //while(1);
  
  // Wifi
  comunicacion.wifi_setup();

  myExo.conect();
  //Timer
  ID = t.every( Ts, execute);
}

void loop() {
  t.update();//Timer update
  
  comunicacion.wifi_recepcion(myExo.servo);

   if(comunicacion.disponible()==true) {
    comunicacion.readData(protocolo);
    //Serial.println(protocolo[2]);
    //Serial.println(protocolo[1]);
    Serial.print("amp:\t");
    amp = protocolo[2]/78.0;
    Serial.println(amp);

    Serial.print("vel:\t");
    vel = round(((float)protocolo[1]*-0.16)+5.8);//ajustar en funcion de la velocidad del smartwalker
    
    Serial.println(vel);

    Serial.print("Metodo: ");
    Serial.println(protocolo[0]);
  }
  
}

void execute() {   //Timer Loop
  //myExo.steps(); //walk walk indefinitely
  
  //Exo & SmartWalker
  if(protocolo[0]==2) {
    myExo.conect();
    myExo.setAmp(amp); //walk with determined amplitude
  
    //walk(vel) //vel=1-> faster;  vel>1 -> slower
    myExo.walk(vel); //walk with determined speed
    aux = 0;
  }

  //Only Exo
  if(protocolo[0]==1) {
    myExo.conect();
  
    myExo.setAmp(amp); //walk with determined amplitude
  
    //walk(vel) //vel=1-> faster;  vel>1 -> slower
    myExo.walk(1); //walk with determined speed
    aux = 0;
  }

  //Stop
  if(protocolo[0]==0) {
    if (aux == 0) {
      myExo.conect();
      myExo.reset();
      aux = 1;  
    }
    
    //myExo.disconect();
  }
  else
  {
  }
  
}

