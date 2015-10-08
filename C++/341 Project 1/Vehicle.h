//
//  Vehicle.hpp
//  341 Project 1
//
//  Created by David Udwin on 9/23/15.
//  Copyright © 2015 David Udwin. All rights reserved.
//

#ifndef Vehicle_h
#define Vehicle_h

#include <stdio.h>
#include <iostream>

using namespace std;

class Vehicle{
    
public:
    
    Vehicle();
    
    Vehicle(char type, int timeEntered);
    
    char GetType() const;
    
    int GetTimeEntered() const;
    
    int GetClearTime() const;
    
    void SetTimeEntered(int timeEntered);
    
    void SetClearTime(int clearTime);
    
    void SetType(char vehicleType);
    
private:
    
    char m_vehicleType;
    int m_timeEntered;
    int m_clearTime;

};
#endif /* Vehicle_h */
