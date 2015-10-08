//
//  IntersectionFlowRate.hpp
//  341 Project 1
//
//  Created by David Udwin on 9/23/15.
//  Copyright © 2015 David Udwin. All rights reserved.
//

#ifndef IntersectionFlowRate_h
#define IntersectionFlowRate_h

#include <stdio.h>

class IntersectionFlowRate{
    
public:
    
    IntersectionFlowRate();
    
    IntersectionFlowRate(int motorCycleFlowRate, int carFlowRate, int truckFlowRate);
    
    int GetCarFlowRate() const;
    
    int GetTruckFlowRate() const;
    
    int GetMotorCycleFlowRate() const;
    
private:
    
    int m_flowRateMotorCycles;
    int m_flowRateCars;
    int m_flowRateTrucks;
    
};



#endif /* IntersectionFlowRate_h */
