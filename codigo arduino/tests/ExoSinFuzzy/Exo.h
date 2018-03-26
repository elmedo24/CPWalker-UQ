#ifndef Exo_H_
#define Exo_H_
#include "Arduino.h"
#include <Servo.h>
#include <Timer.h>

#define IPRK      80//Init Pos
#define IPLK      70
#define IPRH      72
#define IPLH      70/*
#define IPRK      68//Init Pos
#define IPLK      125
#define IPRH      135
#define IPLH      55*/
#define RHIP_PIN  6//Pins
#define LHIP_PIN  7//check
#define RKNEE_PIN 4//check
#define LKNEE_PIN 5//check
#define RHIP_ID   0//ID's //0
#define LHIP_ID   1     //1
#define RKNEE_ID  2     //2
#define LKNEE_ID  3     //3
#define RHIP_CF   0//Correction Factors
#define LHIP_CF   0
#define RKNEE_CF  0
#define LKNEE_CF  0

#define SALTO_POS_PLANTILLA 3

class Exo {
      public:
        /*Methods*/
        void Begin(void);

        /* Walker */
        void reset(void);
        void softReset(void);
        void setAngle(int ID, int angle);
        void set(int ID, int angle);
        void steps(void);//walk walk indefinitely
        void walk(int vel);//walk with determined speed and amplitude
        void setAmp(float amp);
        void conect(void);
        void disconect(void);
        Servo servo[4];
        
      private:
        /* Servo */
        
        uint8_t prev_pos[4]; // previus position of servo 1,2,3,4
        short ser_pos;
        
        //General purpose
        uint8_t i,j;
        
        /* Timer */
        //Timer t;  
        //short ID;

        /* Walker */
        short pos_t,pos_t2,vel_t,amp_t;
        
    };
    #endif
