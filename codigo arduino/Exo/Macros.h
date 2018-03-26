/* ----- Start push button ----- */
#define START   12

/* ----- Navigation ----- */
//NODES
#define NODE1     (New_Xp==3) && (New_Yp==3)
#define NODE2     (New_Xp==2) && (New_Yp==3)
#define NODE3     (New_Xp==1) && (New_Yp==3)
#define NODE4     (New_Xp==0) && (New_Yp==3)
#define NODE5     (New_Xp==3) && (New_Yp==2)
#define NODE6     (New_Xp==2) && (New_Yp==2)
#define NODE7     (New_Xp==1) && (New_Yp==2)
#define NODE8     (New_Xp==0) && (New_Yp==2)
#define NODE9     (New_Xp==3) && (New_Yp==1)
#define NODE10    (New_Xp==2) && (New_Yp==1)
#define NODE11    (New_Xp==1) && (New_Yp==1)
#define NODE12    (New_Xp==0) && (New_Yp==1)
#define NODE13    (New_Xp==3) && (New_Yp==0)
#define NODE14    (New_Xp==2) && (New_Yp==0)
#define NODE15    (New_Xp==1) && (New_Yp==0)
#define NODE16    (New_Xp==0) && (New_Yp==0)

//NODE1
//NODE2
//NODE3
//NODE4
//NODE5
//NODE6
//NODE7
//NODE8
//NODE9
//NODE10
//NODE11
//NODE12
//NODE13
//NODE14
//NODE15
//NODE16

//Vectors
#define Y1        getAct_Axis() && getAct_Direction()
#define Y0        getAct_Axis() && !getAct_Direction()
#define X1        !getAct_Axis() && getAct_Direction()
#define X0        !getAct_Axis() && !getAct_Direction()

/* ----- Handling Motors ----- */
// General Purpose
// General Purpose
#define L_VEL_MAX   255
#define R_VEL_MAX   255

#define L_VEL_MED   90
#define R_VEL_MED   90

#define L_VEL_MIN   170
#define R_VEL_MIN   170

#define FAST_VEL    200

//Square
#define VEL_IN_S    50//50
#define TIME_IN_S   500//500

#define VEL_OUT_S   50
#define TIME_OUT_S  500

// Breaks
#define Vel_Break   255//255
#define Time_Break  15 //15
#define Vel_Out     43 //30

//H bridge Pins
#define IN1       2       //DIGITAL
#define IN2       4       //DIGITAL
#define IN3       7       //DIGITAL
#define IN4       8       //DIGITAL
#define ENB_RIGHT 11      //PWM
#define ENB_LEFT  5      //10 //PWM

/* ----- Handling Sensors ----- */
//General Purpose
#define WHITE       0
#define BLACK       1
#define OBSTACLE    0
#define OPENING     1
#define BF_Delay    200
#define Cal_Delay   500
#define Node_Delay  150
// getSensors
/*#define S1        getSen(1);
  #define S2        getSen(2);
  #define S3        getSen(3);
  #define S4        getSen(4);
  #define S5        getSen(5);
  #define S6        getSen(6);*/
//Sensors ID
#define S_1       A5
#define S_2       A4
#define S_3       A3
#define S_4       A2
#define S_5       A0
#define S_6       A1
#define PS        13
#define TRIG      3//PWM
#define ECO       13
//Sensors Values Home
#define DS1_L   300
#define DS2_L   300
#define DS3_L   300
#define DS4_L   300
#define DS5_L   300
#define DS6_L   300
/**/
//Sensors Values Home Night
/*#define DS1_L   79
  #define DS2_L   80
  #define DS3_L   123
  #define DS4_L   124
  #define DS5_L   141
  #define DS6_L   108
  /**/
//Sensors Values 2
/*#define DS1_L     890
  #define DS2_L     402
  #define DS3_L     252
  #define DS4_L     116
  #define DS5_L     243
  #define DS6_L     295
  /**/

/* ----- Scara Arm & Gripper ----- */
// Ser1      Ser2 //
// Ser3      Ser4 //
//servo ID
#define Ser1   9
#define Ser2   10//5
#define Ser3   6
//#define Ser4   3//?
// servo Default Positon
#define Pos1   135
#define Pos2   0
#define Pos3   180
#define Pos4   90
// 
#define servo_vel 4//15
//#define servo_pos_init 90




//


