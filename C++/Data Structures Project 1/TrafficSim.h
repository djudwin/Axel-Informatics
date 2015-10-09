//
//  TrafficSim.h
//  341 Project 1
//
//  Created by David Udwin on 9/23/15.
//  Copyright © 2015 David Udwin. All rights reserved.
//

#ifndef TrafficSim_h
#define TrafficSim_h

#include <stdio.h>
#include <iostream>
#include <queue>
#include <string>
#include <fstream>
#include <ctype.h>
#include "Vehicle.h"
#include "IntersectionFlowRate.h"
#include "Linked_List.h"
#include "ResultVehicle.h"
//#include "Clear.h"

using namespace std;

class TrafficSim {
    
public:
   
    TrafficSim();
    
    TrafficSim(string fileName);
    
    ~TrafficSim();
    
    void printBoard();
    
    void readFromFile(string fileName);
    
    void addVehicle(int direction, Vehicle x);
    
    void doRun();
    
    
private:
    
    queue<Vehicle> m_traffic[4];
    IntersectionFlowRate *m_flowRate;
    int m_clock;
    Linked_List m_results;
    bool m_trafficLight; //True is north/south, false is east/west
    
};



#endif /* TrafficSim_h */
