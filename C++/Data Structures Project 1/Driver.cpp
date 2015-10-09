//
//  Driver.cpp
//  341 Project 1
//
//  Created by David Udwin on 9/23/15.
//  Copyright © 2015 David Udwin. All rights reserved.
//

#include <iostream>
#include <queue>
#include "TrafficSim.h"
#include "IntersectionFlowRate.h"
#include "Linked_List.h"
#include "ResultVehicle.h"
#include "Vehicle.h"
#include "Node.h"
#include "Clear.h"


using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
   /*queue<Vehicle> vehicleQueue;
    Vehicle myCar;
  
    string fileName;
    cout<<"Please enter a file name: ";
    cin>>fileName;
    
    TrafficSim mySim(fileName);*/
    
    //If there is an input file listed
    if (argc > 1) {
        TrafficSim *Sim = new TrafficSim(argv[1]);
        Sim->doRun();
        delete Sim;
        Sim = NULL;
        
        //If no input file is specified.
    } else {
        TrafficSim *Sim = new TrafficSim();
        Sim->doRun();
        delete Sim;
        Sim = NULL;
    }
    
    // endl(cout << clock() / (float)CLOCKS_PER_SEC);
    
    
    
    return 0;
}
