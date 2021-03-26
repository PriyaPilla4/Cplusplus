
#include "customer.hpp"

Customer::Customer(){
    
}

Customer::Customer(float arrivalTime, float startOfServiceTime, float departureTime, float queueTime){
    setArrivalTime(arrivalTime);
    setStartOfServiceTime(startOfServiceTime);
    setDepartureTime(departureTime);
    setQueueTime(queueTime);
}

void Customer::setArrivalTime(float arrivalTime){
    this->arrivalTime = arrivalTime;
}

void Customer::setStartOfServiceTime(float startOfServiceTime){
    this->startOfServiceTime = startOfServiceTime;
}

void Customer::setDepartureTime(float departureTime){
    this->departureTime = departureTime;
}

void Customer::setQueueTime(float queueTime){
    this->queueTime = queueTime;
}

void Customer::setNextCust(Customer* nextCust){ //for FIFO
    this->nextCust = nextCust;
}

float Customer::getArrivalTime(){
    return arrivalTime;
}

float Customer::getStartOfServiceTime(){
    return startOfServiceTime;
}

float Customer::getDepartureTime(){
    return departureTime;
}

float Customer::getQueueTime(){
    return queueTime;
}

Customer* Customer::getNextCust(){
    return nextCust;
}
