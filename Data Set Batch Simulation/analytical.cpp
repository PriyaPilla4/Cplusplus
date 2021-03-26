
#include "analytical.hpp"
#include <math.h>
#include <stdio.h>
#include <iostream>

Analytical::Analytical(float l, float mu, float M){
    setLambda(l);
    setMu(mu);
    setM(M);
}

void Analytical::setLambda(float l){
    this->l = l;
}

void Analytical::setMu(float mu){
    this->mu = mu;
}

void Analytical::setM(float M){
    this->M = M;
}

float Analytical::getLambda(){
    return l;
}

float Analytical::getMu(){
    return mu;
}

float Analytical::getM(){ 
    return M;
}

float Analytical::factorial(float num){
    if(num > 1){
        return num * factorial(num - 1);
    }else{
        return 1;
    }
}

float Analytical::percentIdleTime(){
    float Po = 0;
    //first part of denominator
    for (int i = 0; i <= M-1; i++) {
        Po = Po + (1/factorial(i)) * (pow ((l / mu), i));
    }
    //calculates second part of denominator and adds it to the first part
    Po = Po + (1 / factorial(M)) * pow((l / mu), M) * ((M * mu) / (M * mu - l));
    Po = 1 / Po;
    return Po;
}

float Analytical::avgNoOfPeopleInSystem(){
    float L = 0;
    //calculates numerator
    L = (l * mu) * pow((l / mu), M);
    //calculates denominator and divides it by numerator
    L = L / (factorial(M - 1) * pow((M * mu - l), 2));
    L = L * percentIdleTime() + (l / mu);
    return L;
}

float Analytical::avgTimeCustSpentInSys(){
    float W = 0;
    //calculates numerator
    W = mu * pow((l / mu), M);
    //calculates denominator and divides it by numerator
    W = W / (factorial(M - 1) * pow((M * mu - l), 2));
    W = W * percentIdleTime() + (1 / mu);
    return W;
}

float Analytical::avgNoOfCustInQueue(){
    float Lq = 0;
    Lq = avgNoOfPeopleInSystem() - (l / mu);
    return Lq;
}

float Analytical::avgTimeCustSpentWaitInQueue(){
    float Wq = 0;
    Wq = avgTimeCustSpentInSys() - (1 / mu);
    return Wq;
}

float Analytical::untilizationFactor(){
    float rho = 0;
    rho = l / (M * mu);
    return rho;
}
