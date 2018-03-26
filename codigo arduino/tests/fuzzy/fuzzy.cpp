#include "fuzzy.h"
#include "fuzzyMat.h"
#define REF 800
#define T_S_ENC 100000.0
void fuzzy::updateVars(short ref)
{
    e_t=ref-w_d;
    de_t_dt=((float)e_t-e_t_ant)/T_S_ENC;
    e_t_ant=e_t;

}

fuzzy::fuzzy(short w_d, short ref)
{
    ///leer sensor
    e_t=ref-w_d;
    e_t_ant=e_t;
}

void fuzzy::fuzzyfication(void)
{
    int i,j;
    float belErr, belDErr;

    nRulesActivated=0;

    for(i=-2; i<=2; i++)
    {
        belErr=belonging(i,ERR,e_t);
        if(belErr)
        {
            for(j=-2; j<=2; j++)
            {
                belDErr=belonging(j,D_ERR,de_t_dt);
                if(belDErr)
                {
                    inference(i,j,belErr,belDErr);
                    nRulesActivated++;
                    //break;
                }
            }
        }

    }




}

float fuzzy::minimo(float belErr, float belDErr)
{
  

  if(belErr<=belDErr)
     return belErr;
  else
    return belDErr;
 
}

void fuzzy::inference(int e,int dedt,float belErr, float belDErr){
    float uPremise;

    uPremise=minimo(belErr,belDErr);
    rulesRecommendation[nRulesActivated]=uPremise;
    rulesActivated[nRulesActivated]=fuzzyMat[e+2][dedt+2];

}

float fuzzy::belonging(short nivel,short var, float valor)
{
    short centro,ancho, belong;
    switch(nivel)
    {
    case GN:
        if(var==ERR)
        {
            centro=-40;
            ancho=40;
        }
        else
        {
            centro=-10;
            ancho=10;
        }
        break;
    case PN:
        if(var==ERR)
        {
            centro=-10;
            ancho=20;
        }
        else
        {
            centro=-5;
            ancho=10;
        }
        break;
    case Z:
        if(var==ERR)
        {
            centro=0;
            ancho=20;
        }
        else
        {
            centro=0;
            ancho=10;
        }
        break;
    case PP:
        if(var==ERR)
        {
            centro=10;
            ancho=20;
        }
        else
        {
            centro=5;
            ancho=10;
        }
        break;
    case GP:
        if(var==ERR)
        {
            centro=40;
            ancho=40;
        }
        else
        {
            centro=10;
            ancho=10;
        }
        break;
    }



    if(valor<centro)
    {
        if(nivel==GN)
            belong=1;
        else
            belong=2.0/ancho*(valor-centro)+1;
    }
    else
    {
        if(nivel==GP)
            belong=1;
        else
            belong=2.0/ancho*(centro-valor)+1;
    }

    


    if(belong>0)
        return belong;
    else
        return 0;

}


unsigned char fuzzy::defuzzyfication(char pwmcont){
    int ancho=3;
    float denominator=0,centro;
    fuzzyOutput=0;
    for(int i=0;i<nRulesActivated;i++){
        switch(rulesActivated[i]){
            case -2:
                centro=-2;
                break;
            case -1:
                centro=-1;
                break;
            case 0:
                centro=0;
                break;
            case 1:
                centro=1;
                break;
            case 2:
                centro=2;
                break;
        }
        float area=ancho*(rulesRecommendation[i]-rulesRecommendation[i]*rulesRecommendation[i]/2);
        fuzzyOutput+=centro*area;
        denominator+=area;
    }
    fuzzyOutput/=denominator;

    return pwmcont=pwmcont+fuzzyOutput;
    


}

