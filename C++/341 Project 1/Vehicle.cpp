//
//  Vehicle.cpp
//  341 Project 1
//
//  Created by David Udwin on 9/23/15.
//  Copyright © 2015 David Udwin. All rights reserved.
//

#include "Vehicle.h"

Vehicle::Vehicle(){
    char vehicle = 'v';
    m_vehicleType = vehicle;
    m_timeEntered = 0;
    m_clearTime = 0;
    
}

Vehicle::Vehicle(char type, int timeEntered){
    
    m_vehicleType = type;
    m_timeEntered = timeEntered;
    m_clearTime = 0;
    
}

char Vehicle::GetType() const{
    
    return m_vehicleType;
}

int Vehicle::GetTimeEntered() const{
    return m_timeEntered;
}

int Vehicle::GetClearTime() const{
    return m_clearTime;
}

void Vehicle::SetTimeEntered(int timeEntered){
    m_timeEntered = timeEntered;
}

void Vehicle::SetClearTime(int clearTime){
    m_clearTime = clearTime;
}

void Vehicle::SetType(char vehicleType){
    m_vehicleType = vehicleType;
}