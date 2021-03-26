
#include "simulation.hpp"
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <queue>
#include <vector>
#include <functional>
#include <iomanip>

Simulation::Simulation(float arrivals, float avgArrivals, float avgCustomers, float serviceChannels){
    setArrivals(arrivals);
    setAvgArrivals(avgArrivals);
    setAvgCustomers(avgCustomers);
    setServiceChannels(serviceChannels);
    setCurrentTime(0);
    setServerAvailableCnt(0);
    setCurrentWaitTime(0);
    setCustomerWaitedCnt(0);
    setTotalWaitTime(0);
    
    for (int i = 0; i < arrivals; i++) {
        customerVector.push_back(new Customer);
    }
}

void Simulation::setArrivals(float arrivals){
    this->arrivals = arrivals;
}

void Simulation::setAvgArrivals(float avgArrivals){
    this->avgArrivals = avgArrivals;
}

void Simulation::setAvgCustomers(float avgCustomers){
    this->avgCustomers = avgCustomers;
}

void Simulation::setServiceChannels(float serviceChannels){
    this->serviceChannels = serviceChannels;
}

void Simulation::setCurrentTime(float currentTime){
    this->currentTime = currentTime;
}

void Simulation::setServerAvailableCnt(float serverAvailableCnt){
    this->serverAvailableCnt = serverAvailableCnt;
}

void Simulation::setCurrentWaitTime(float currentWaitTime){
    this->currentWaitTime = currentWaitTime;
}

void Simulation::setCustomerWaitedCnt(float customerWaitedCnt){
    this->customerWaitedCnt = customerWaitedCnt;
}

void Simulation::setTotalWaitTime(float totalWaitTime){
    this->totalWaitTime = totalWaitTime;
}

float Simulation::getArrivals(){
    return arrivals;
}

float Simulation::getAvgArrivals(){
    return avgArrivals;
}

float Simulation::getAvgCustomers(){
    return avgCustomers;
}

float Simulation::getServiceChannels(){
    return serviceChannels;
}

float Simulation::getCurrentTime(){
    return currentTime;
}

float Simulation::getServerAvailableCnt(){
    return serverAvailableCnt;
}

float Simulation::getCurrentWaitTime(){
    return currentWaitTime;
}

float Simulation::getCustomerWaitedCnt(){
    return customerWaitedCnt;
}

float Simulation::getTotalWaitTime(){
    return totalWaitTime;
}

void Simulation::RunSimulation(){
    float interval = 0;
    float count = 0;
    std::vector<Customer*> custs;
    
    //insert do while loop
    //get next 200
    //pass them to priority queue function
    for (int j = count; j < (count+200); j++) {
        //assigns random intervals
        customerVector.at(j)->setArrivalTime(interval);
        interval = interval + GetNextRandomInterval(avgArrivals);
        custs.push_back(customerVector.at(j));
    }
    
    //for iterating 200 each time
    if (customerVector.size() > count+201) {
        count = count + 201;
    }else{
        count = customerVector.size() - count;
    }
    
    //set serverAvailableCnt equal to M
    setServerAvailableCnt(serviceChannels);
    
    while (!(pqueue_greater.empty())) {
        ProcessNextEvent();
        if ((count < arrivals) && (pqueue_greater.size() <= serviceChannels + 1)) {
            //add arivals to PQ
            PriorityQueue(custs);
        }
    }
    //show simulation results
    std::cout << "Simulation results:" << std::endl;
    std::cout << "Po = " << std::fixed << std::setprecision(4) << accIdleTime/simTime << std::endl;
    std::cout << "W = " << std::fixed << std::setprecision(4) << (totalWaitTime+totalServiceTime)/arrivals << std::endl;
    std::cout << "Wq = " << std::fixed << std::setprecision(4) << totalWaitTime/arrivals << std::endl;
    std::cout << "rho = " << std::fixed << std::setprecision(4) << totalServiceTime/(serviceChannels*simTime) << std::endl;
    
}

//avg can be avgArrivals or avgCustomers
float Simulation::GetNextRandomInterval(float avg){
    float f = ((float) rand() / (RAND_MAX));
    float lnf = log10(f) * 2.303; // computes natural log of f
    float intervalTime = -1 * (1.0/avg) * lnf;
    return intervalTime;
}

float Simulation::NegativeExponentialDistribution(float avg){
    return 0;
}

void Simulation::PriorityQueue(std::vector<Customer*> customers){  //Priority queue holds arrival times float values
    if (!(customers.size() <= 200)) {
        std::cout << "vector size not 200 or less" << std::endl;
    }
    
    for (int i = 0; i < 200; i++) {
        std::cout << i << ": " << customers.at(i)->getArrivalTime() << std::endl;
    }
    
    //insert first 200 into priority queue by arrivaltime
    //for (int i = 0; i < customers.size(); i++) {
        //pqueue_greater.push(customers.at(i)->getArrivalTime());
    //}
    
   //output arrival times
    while (!pqueue_greater.empty())
        {
            float value = pqueue_greater.top();
            std::cout << " : " << value << std::endl;
            pqueue_greater.pop();
        }
}

void Simulation::ProcessStatistics(){
    if (currentWaitTime > 0) {
        customerWaitedCnt++;
    }
    totalWaitTime = totalWaitTime + currentWaitTime;
    //accumulate serviceTime
    if (serverAvailableCnt == serviceChannels) {
        //accumulate idleTime
    }
}

void Simulation::ProcessNextEvent(){
        
}
