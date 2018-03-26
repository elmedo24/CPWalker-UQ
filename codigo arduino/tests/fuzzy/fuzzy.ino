#include <Timer.h>
#include "fuzzy.h"
#include <EEPROM.h>
#include "velocidad.h"
//Motor 1
#define PINPWMIZQ 10
#define SENTIDODERIZQ 13
#define SENTIDOIZQIZQ 12
#define PININTIZQ 2
//Motor 2
#define PINPWMDER 9
#define SENTIDODERDER 11
#define SENTIDOIZQDER 8
#define PININTDER 3


#define TS 50

Timer t;
short ID;

volatile int pulsosDer = 0;
volatile int pulsosIzq = 0;

fuzzy controlmotorIzq(0,0);
fuzzy controlmotorDer(0,0);

short Velgs;

char pwmcont = 0;
char pwmcontDer = 0;
unsigned char i=0;


void setup()
{ Serial.begin(9600);
  attachInterrupt( digitalPinToInterrupt(PININTIZQ), EncoderIzq, CHANGE);
  attachInterrupt( digitalPinToInterrupt(PININTDER), EncoderDer, CHANGE);
   pinMode(PINPWMIZQ,OUTPUT);
   pinMode(SENTIDODERIZQ,OUTPUT);
   pinMode(SENTIDOIZQIZQ,OUTPUT);
   pinMode(PINPWMDER,OUTPUT);
   pinMode(SENTIDODERDER,OUTPUT);
   pinMode(SENTIDOIZQDER,OUTPUT);
   ID = t.every( TS, execute);
   //pinMode(13,LOW);
   
}
void loop()
{
 t.update();//Timer update
 //digitalWrite(13,HIGH);
}

void EncoderIzq()
  { 
  pulsosIzq++ ;
  }

  void EncoderDer()
  { 
  pulsosDer++ ;
  }

void execute()
   {   controlmotorIzq.w_d=(short)(pulsosIzq)*(1000.0/TS)*360/960.0;//grados *s
       pulsosIzq=0;
       controlmotorDer.w_d=(short)(pulsosDer)*(1000.0/TS)*360/960.0;
       pulsosDer=0;
       //digitalWrite(13,HIGH);
      /* Serial.print("pwm: ");
       Serial.print(pwmcont);
       Serial.print("\t ");
       Serial.print("vel: ");
       Serial.println(controlmotorIzq.w_d);
       Serial.print("\t ");
       Serial.print("pulsos: ");
       Serial.println(pulsosIzq);*/
  
       
      Velgs=(((int8_t)pgm_read_byte(&vel[i]))*(30/*referencia interfaz*/))/7.33; // ((2*pi*r)/360)*100=7.33
  
      controlmotorIzq.updateVars(Velgs);
      controlmotorIzq.fuzzyfication();
      pwmcont=controlmotorIzq.defuzzyfication(pwmcont);
      
      controlmotorDer.updateVars(Velgs);
      controlmotorDer.fuzzyfication();
      pwmcontDer=controlmotorDer.defuzzyfication(pwmcontDer);
      
      digitalWrite(SENTIDODERIZQ,HIGH);
      digitalWrite(SENTIDOIZQIZQ,LOW);  
      analogWrite(PINPWMIZQ,pwmcont);
    
      digitalWrite(SENTIDODERDER,HIGH);
      digitalWrite(SENTIDOIZQDER,LOW);
      analogWrite(PINPWMDER,pwmcontDer);
      
      i+=5;
      
      if(i>=202)
          i=0;
    
   }
