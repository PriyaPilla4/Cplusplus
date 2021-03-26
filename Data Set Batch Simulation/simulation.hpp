
#ifndef simulation_hpp
#define simulation_hpp
#include "customer.hpp"
#include <stdio.h>
#include <vector>
#include <queue>

class Simulation{
private:
    float arrivals; //n
    float avgArrivals; //l (lambda)
    float avgCustomers; //mu
    float serviceChannels; //M
    float serverAvailableCnt;
    float currentTime;
    float currentWaitTime;
    float customerWaitedCnt;
    float totalWaitTime;
    float totalServiceTime;
    float simTime;
    float accIdleTime;
  
    std::vector<Customer*> customerVector;
    std::priority_queue<float, std::vector<float>, std::greater<std::vector<float>::value_type>> pqueue_greater;
    
public:
    Simulation(float arrivals, float avgArrivals, float avgCustomers, float serviceChannels);
    
    void setArrivals(float arrivals);
    void setAvgArrivals(float avgArrivals);
    void setAvgCustomers(float avgCustomers);
    void setServiceChannels(float serviceChannels);
    void setCurrentTime(float currentTime);
    void setServerAvailableCnt(float serverAvailableCnt);
    void setCurrentWaitTime(float currentWaitTime);
    void setCustomerWaitedCnt(float customerWaitedCnt);
    void setTotalWaitTime(float totalWaitTime);
    
    float getArrivals();
    float getAvgArrivals();
    float getAvgCustomers();
    float getServiceChannels();
    float getCurrentTime();
    float getServerAvailableCnt();
    float getCurrentWaitTime();
    float getCustomerWaitedCnt();
    float getTotalWaitTime();
    
    void RunSimulation();
    float GetNextRandomInterval(float avg);
    float NegativeExponentialDistribution(float avg);
    void PriorityQueue(std::vector<Customer*> customers);
    void ProcessStatistics();
    void ProcessNextEvent();
    //void FIFO();
    
    
    
};

#endif /* simulation_hpp */
