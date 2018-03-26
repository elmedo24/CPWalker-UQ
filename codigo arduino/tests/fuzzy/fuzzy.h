#include <math.h>


#define GN -2
#define PN -1
#define Z  0
#define PP 1
#define GP 2

#define ERR   0
#define D_ERR 1


 

class fuzzy
{


public:
    fuzzy(short w_d, short ref);
    int ref;
    float plant_ouput;
    float ts;
    void updateVars(short ref);
    void fuzzyfication(void);
    unsigned char defuzzyfication(char pwmcont);
    char fuzzyOutput;
    short w_d;


private:

    
    float e_t;
    float e_t_ant;
    float de_t_dt;

    float rulesRecommendation[4];
    char rulesActivated[4];
    int nRulesActivated;
    

    float belonging(short nivel,short var, float valor);
    void inference(int e,int dedt,float belErr, float belDErr);
    float minimo(float belErr, float belDErr);
};
