//
//  IntersectionFlowRate.cpp
//  341 Project 1
//
//  Created by David Udwin on 9/23/15.
//  Copyright © 2015 David Udwin. All rights reserved.
//

#include "IntersectionFlowRate.h"
#include <iostream>

using namespace std;

IntersectionFlowRate::IntersectionFlowRate(){
  
    m_flowRateCars = 0;
    m_flowRateMotorCycles = 0;
    m_flowRateTrucks = 0;
    
}

IntersectionFlowRate::IntersectionFlowRate(int motorCycleFlowRate, int carFlowRate, int truckFlowRate){
    
    m_flowRateCars = carFlowRate;
    m_flowRateMotorCycles = motorCycleFlowRate;
    m_flowRateTrucks = truckFlowRate;
}

int IntersectionFlowRate::GetCarFlowRate() const{
    return m_flowRateCars;
}

int IntersectionFlowRate::GetMotorCycleFlowRate() const{
    return m_flowRateMotorCycles;
}

int IntersectionFlowRate::GetTruckFlowRate() const{
    return m_flowRateTrucks;
}