
#ifndef analytical_hpp
#define analytical_hpp

#include <stdio.h>

class Analytical{
private:
    float l;
    float mu;
    float M;
    
public:
    Analytical(float l, float mu, float M);
    void setLambda(float l);
    void setMu(float mu);
    void setM(float M);
    
    float getLambda();
    float getMu();
    float getM();
    
    float factorial(float num);
    
    float percentIdleTime();
    float avgNoOfPeopleInSystem();
    float avgTimeCustSpentInSys();
    float avgNoOfCustInQueue();
    float avgTimeCustSpentWaitInQueue();
    float untilizationFactor();
};

#endif /* analytical_hpp */
