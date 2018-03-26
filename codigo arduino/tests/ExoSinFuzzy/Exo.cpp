#include "Exo.h"
//Trajectories
#include "Hip.h"
#include "Knee.h"


void Exo::Begin(void) {//Builder
  // Servo
  //Right Hip
  prev_pos[RHIP_ID] = IPRH;
  servo[RHIP_ID].attach(RHIP_PIN);
  servo[RHIP_ID].write(IPRH);
  
  //Left Hip
  prev_pos[LHIP_ID] = IPLH;
  servo[LHIP_ID].attach(LHIP_PIN);
  servo[LHIP_ID].write(IPLH);
  
  //Right Knee
  prev_pos[RKNEE_ID] = IPRK;
  servo[RKNEE_ID].attach(RKNEE_PIN);
  servo[RKNEE_ID].write(IPRK);
  
  //Left Knee
  prev_pos[LKNEE_ID] = IPLK;
  servo[LKNEE_ID].attach(LKNEE_PIN);
  servo[LKNEE_ID].write(IPLK);

  //Walker
  pos_t = 0;//Trajectory position
  pos_t2 = 100;
  vel_t = 1;//Trajectory vel
  amp_t = 1;//Trajectory amp
}

/* ----- Servos ----- */
void Exo::reset(void) {
  //Right Hip
  servo[RHIP_ID].write(IPRH);
  //Right Knee
  servo[RKNEE_ID].write(IPRK);
  //Left Knee
  servo[LKNEE_ID].write(IPLK);
  //Left Hip
  servo[LHIP_ID].write(IPLH);
}

void Exo::softReset(void) {
  //Right Hip
  if (prev_pos[RHIP_ID] < IPRH) {
    prev_pos[RHIP_ID]++;
    servo[RHIP_ID].write(prev_pos[RHIP_ID]);  
  }
  else if (prev_pos[RHIP_ID] > IPRH) {
    prev_pos[RHIP_ID]--;
    servo[RHIP_ID].write(prev_pos[RHIP_ID]);  
  }
  
  //Right Knee
  if (prev_pos[RKNEE_ID] < IPRK) {
    prev_pos[RKNEE_ID]++;
    servo[RKNEE_ID].write(prev_pos[RKNEE_ID]);  
  }
  else if (prev_pos[RKNEE_ID] < IPRK) {
    prev_pos[RKNEE_ID]--;
    servo[RKNEE_ID].write(prev_pos[RKNEE_ID]);  
  }
  
  //Left Knee  
  if (prev_pos[LKNEE_ID] < IPLK) {
    prev_pos[LKNEE_ID]++;
    servo[LKNEE_ID].write(prev_pos[LKNEE_ID]);  
  }
  else if (prev_pos[LKNEE_ID] < IPLK) {
    prev_pos[LKNEE_ID]--;
    servo[LKNEE_ID].write(prev_pos[LKNEE_ID]);  
  }
  
  //Left Hip
  servo[LHIP_ID].write(IPLH);
  
  if (prev_pos[LHIP_ID] < IPLH) {
    prev_pos[LHIP_ID]++;
    servo[LHIP_ID].write(prev_pos[LHIP_ID]);
  }
  else if (prev_pos[LHIP_ID] < IPLH) {
    prev_pos[LHIP_ID]--;
    servo[LHIP_ID].write(prev_pos[LHIP_ID]);
  }
}

void Exo::set(int ID, int angle) {
  servo[ID].write(angle);
}

void Exo::setAngle(int ID, int angle) {
  switch (ID) {
    case RHIP_ID://IPRH      130
    angle = (angle*55)/60;
    ser_pos = -angle+IPRH+RHIP_CF; //y=-x+130
    servo[RHIP_ID].write(ser_pos);
    prev_pos[RHIP_ID] = ser_pos;
    break;

    case LHIP_ID://IPLH      65
    ser_pos = angle+IPLH+LHIP_CF; //y=x+45
    servo[LHIP_ID].write(ser_pos);
    prev_pos[LHIP_ID] = ser_pos;
    break;

    case RKNEE_ID://IPRK      65
    angle = (angle*80)/90;
    ser_pos = angle+IPRK+RKNEE_CF; //y=x+65
    servo[RKNEE_ID].write(ser_pos);
    prev_pos[RKNEE_ID] = ser_pos;
    break;

    case LKNEE_ID://IPLK      125
    ser_pos = -angle+IPLK+LKNEE_CF; //y=-x+125s
    servo[LKNEE_ID].write(ser_pos);
    prev_pos[LKNEE_ID] = ser_pos;
    break;

    default:
    break;
  }
}

void Exo::steps(void) {
  //Right Hip
  setAngle(RHIP_ID,Hip_T[pos_t]);
  //Right Knee
  setAngle(RKNEE_ID,Knee_T[pos_t]);
  
  //Left Hip
  setAngle(LHIP_ID,Hip_T[pos_t2]);
  //Left Knee
  setAngle(LKNEE_ID,Knee_T[pos_t2]);
  
  pos_t++;
  pos_t2++;

  if (pos_t>200) {
    pos_t = 0;  
  }
  if (pos_t2>200) {
    pos_t2 = 0;  
  }
}

void Exo::setAmp(float amp) {
  if(amp>1) {
    amp = 1;
  }
  for (i=0;i<P;i++) {
    Hip_T[i] = amp*((int8_t)pgm_read_byte(&Hip_T_template[i]));
    Knee_T[i] = amp*((int8_t)pgm_read_byte(&Knee_T_template[i]));
  }
}

void Exo::walk(int vel) {
  //amp_t,vel_t,pos_t,pos_t2,
  //Right Hip
  setAngle(RHIP_ID,Hip_T[pos_t]);
  //Right Knee
  setAngle(RKNEE_ID,Knee_T[pos_t]);
  
  //Left Hip
  setAngle(LHIP_ID,Hip_T[pos_t2]);
  //Left Knee
  setAngle(LKNEE_ID,Knee_T[pos_t2]);
  
  pos_t+=SALTO_POS_PLANTILLA;
  pos_t2+=SALTO_POS_PLANTILLA;

  //Vel Control
  if (vel_t<vel){
    pos_t--;
    pos_t2--;
  }
  vel_t++;
  //Reset
  if (vel_t>vel) {
    vel_t = 1;  
  }

  //Amp Control
  
  //Reset Position
  if (pos_t>200) {
    pos_t = 0;
  }
  if (pos_t2>200) {
    pos_t2 = 0;
  }
}

void Exo::conect(void) {
  //Right Hip
  servo[RHIP_ID].attach(RHIP_PIN);
  //pinMode(RHIP_PIN,OUTPUT);
  servo[RHIP_ID].write(prev_pos[RHIP_ID]);
  
  //Left Hip
  servo[LHIP_ID].attach(LHIP_PIN);
  //pinMode(LHIP_PIN,OUTPUT);
  servo[LHIP_ID].write(prev_pos[LHIP_ID]);
  
  //Right Knee
  servo[RKNEE_ID].attach(RKNEE_PIN);
  //pinMode(RKNEE_PIN,OUTPUT);
  servo[RKNEE_ID].write(prev_pos[RKNEE_ID]);
  
  //Left Knee
  servo[LKNEE_ID].attach(LKNEE_PIN);
  //pinMode(LKNEE_PIN,OUTPUT);
  servo[LKNEE_ID].write(prev_pos[LKNEE_ID]);
}

void Exo::disconect(void) {
  //Right hip
  servo[RHIP_ID].detach();
  
  //Left Hip
  servo[LHIP_ID].detach();
  
  //Right Knee
  servo[RKNEE_ID].detach();
  
  //Left Knee
  servo[LKNEE_ID].detach();
}


