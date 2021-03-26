
#ifndef customer_hpp
#define customer_hpp

#include <stdio.h>

class Customer{
private:
    float arrivalTime;
    float startOfServiceTime;
    float departureTime;
    float queueTime;
    Customer * nextCust; // for linked FIFO
public:
    Customer();
    Customer(float arrivalTime, float startOfServiceTime, float departureTime, float queueTime);
    void setArrivalTime(float arrivalTime);
    void setStartOfServiceTime(float startOfServiceTime);
    void setDepartureTime(float departureTime);
    void setQueueTime(float queueTime);
    void setNextCust(Customer* nextCust);
    float getArrivalTime();
    float getStartOfServiceTime();
    float getDepartureTime();
    float getQueueTime();
    Customer* getNextCust();
};
#endif /* customer_hpp */
