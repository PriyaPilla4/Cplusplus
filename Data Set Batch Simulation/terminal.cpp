
#include "terminal.hpp"
#include "simulation.hpp"
#include "analytical.hpp"
#include <iostream>
#include <iomanip>

Terminal::Terminal(){
    
}

void Terminal::Run(){
    float arrivals; //n
    float avgArrivals; //l (lambda)
    float avgCustomers; //mu
    float serviceChannels; //M
    bool errorcheck = false;
    
    std::cout << "Enter values for: " << std::endl
    << "No. of arrivals to simulate (1000 - 5000) (n)" << std::endl
    << "Avg. arrivals in a time period (l)" << std::endl
    << "Avg. no. of customers served in a time period (mu)" << std::endl
    << "No. of service channels (1 - 10) (M)" << std::endl;
    
    //for error check in input values
    do {
        std::cin >> arrivals >> avgArrivals >> avgCustomers >> serviceChannels;
        
        if (!(arrivals <= 5000 && arrivals >= 1000)) { //change lower limit to 1000, 0 for trials now
            std::cout << "No. of arrivals must be between 1000 and 5000, enter values again:" << std::endl;
            errorcheck = true;
        }else if (!(serviceChannels <= 10 && serviceChannels >= 1)) {
            std::cout << "No. of service channels must be between 1 and 10, enter values again:" << std::endl;
            errorcheck = true;
        }else{
            errorcheck = false;
        }
        
    } while (errorcheck == true);
    
    Analytical* analytical = new Analytical(avgArrivals, avgCustomers, serviceChannels);
       std::cout << "Analytical Results: " << std::endl;
       std::cout << "Po = " << std::fixed << std::setprecision(4) << analytical->percentIdleTime() << std::endl;
       std::cout << "L = " << std::fixed << std::setprecision(4) << analytical->avgNoOfPeopleInSystem() << std::endl;
       std::cout << "W = " << std::fixed << std::setprecision(4) << analytical->avgTimeCustSpentInSys() << std::endl;
       std::cout << "Lq = " << std::fixed << std::setprecision(4) << analytical->avgNoOfCustInQueue() << std::endl;
       std::cout << "Wq = " << std::fixed << std::setprecision(4) << analytical->avgTimeCustSpentWaitInQueue() << std::endl;
       std::cout << "rho = " << std::fixed << std::setprecision(4) << analytical->untilizationFactor() << std::endl;
    
    Simulation* simulation = new Simulation(arrivals, avgArrivals, avgCustomers, serviceChannels);
    //do simulation stuff
    simulation->RunSimulation();
   
   
    
    
}
