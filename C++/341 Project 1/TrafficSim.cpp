//
//  TrafficSim.cpp
//  341 Project 1
//
//  Created by David Udwin on 9/23/15.
//  Copyright © 2015 David Udwin. All rights reserved.
//

#include "TrafficSim.h"

using namespace std;


TrafficSim::TrafficSim(){
    m_flowRate = new IntersectionFlowRate[4];
    
}

TrafficSim::TrafficSim(string fileName){
    m_flowRate = new IntersectionFlowRate[4]; //create flowrates object
    TrafficSim::readFromFile(fileName);  //populate object with data from file
    
    
    TrafficSim::printBoard();
}

TrafficSim::~TrafficSim(){
    delete [] m_flowRate;
    m_flowRate = NULL;
    
}

void TrafficSim::printBoard(){
    cout<<"printing board\n";
   
        cout<<"    SB    "<<m_traffic[1].size()<<endl<<endl<<endl;
        cout<<"EB     X"<<endl;
        cout<<m_traffic[2].size()<<"      C"<<endl;
        cout<<"     XC CX"<<endl;
        cout<<"       C"<<endl;
        cout<<"       X      WB"<<endl;
        cout<<"               "<<m_traffic[3].size()<<endl;
        cout<<endl<<endl<<endl<<endl;
        cout<<"    NB     "<<m_traffic[0].size()<<endl;
        cout<<"at clock:     "<<m_clock<<endl;
        cout<<"------------------------------------------------"<<endl<<endl;
    
}

void TrafficSim::readFromFile(string fileName){
    
    cout<<"the file name is "<<fileName<<endl;
    ifstream infile;
    infile.open(fileName.c_str());
    
    if (infile.fail()){
        cout<<"The file was not successfully opened.\n";
    }
    
    int rate[12];
    int twelve = 12;
    
   for (int i = 0;i<twelve;i++){
        char temp = 0;
        int number = 0;
        bool flag = false;
        while (flag == false){
            infile >> temp;
            if (isdigit(temp)){
                number = temp - '0';
                rate[i] = number;
                flag = true;
            }
            else{
                //cout<<"junk "<<temp<<" ";
            }
        }
    }
    

 
    for (int i = 0; i<twelve;i++){
      if (((i)%3) == 0){
            cout<<endl;
        }
        cout<<rate[i]<<" ";
    }
    cout<<endl;
    
    infile.close();
    
    m_flowRate[0] = IntersectionFlowRate(rate[0], rate[1], rate[2]);
    m_flowRate[1] = IntersectionFlowRate(rate[3], rate[4], rate[5]);
    m_flowRate[2] = IntersectionFlowRate(rate[6], rate[7], rate[8]);
    m_flowRate[3] = IntersectionFlowRate(rate[9], rate[10], rate[11]);
}

void TrafficSim::addVehicle(int direction, Vehicle x){
    
    m_traffic[direction].push(x);
    
}

void TrafficSim::doRun(){
    
    //each side starts with 2 cars
    char c = 'c';
    char m = 'm';
    char t = 't';
    TrafficSim::addVehicle(0,Vehicle(c,0));
    TrafficSim::addVehicle(0,Vehicle(c,0));
    TrafficSim::addVehicle(1,Vehicle(c,0));
    TrafficSim::addVehicle(1,Vehicle(c,0));
    TrafficSim::addVehicle(2,Vehicle(c,0));
    TrafficSim::addVehicle(2,Vehicle(c,0));
    TrafficSim::addVehicle(3,Vehicle(c,0));
    TrafficSim::addVehicle(3,Vehicle(c,0));
    
    m_clock = 0;
    int lastLightChange = 0;
    int endTime = 120;
    int thirty = 30;
    int ten = 10;
    m_trafficLight = true; //True is north/south, false is east/west
    for (;m_clock < endTime;m_clock++){
        //should light change?
        if (m_trafficLight == true){
            if ((m_clock - lastLightChange) > thirty){
                if (!m_traffic[2].empty() || !m_traffic[3].empty()){
                    m_trafficLight = false;
                }
            }
        }
        else{
            if ((m_clock - lastLightChange) > ten){
                if ((m_clock - lastLightChange) > thirty){
                    m_trafficLight = true;
                }
                if (m_traffic[2].empty() && m_traffic[3].empty()){
                    m_trafficLight = true;
                }
            }
        }
        
        //remove cars from queue
        int carsRemoved = 0;
        int motorCyclesRemoved = 0;
        int trucksRemoved = 0;
        
        
        /*for (int i = 0; i < 4 ; i++){
            bool popFlag = true;
            while (popFlag == true){
                //remove cars from not empty queue
                Vehicle tempVehicle = m_traffic[i].front();
                m_traffic[i].pop();
                m_results.insert(tempVehicle.GetType(), m_clock);
                switch(tempVehicle.GetType()){
                        case 'c':
                        carsRemoved++;
                        break;
                        case 'm':
                        motorCyclesRemoved++;
                        break;
                        case 't':
                        trucksRemoved++;
                        break;
                }
                /*if (carsRemoved >= carClear1){
                    popFlag = false;
                }
                else if (motorCyclesRemoved >= motorCycleClear1){
                    popFlag = false;
                }
                else if (trucksRemoved >= truckClear1){
                    popFlag = false;
                }
                else if (m_traffic[i].empty()){
                    popFlag = false;
                }*//*
                popFlag = false;
   
                    }*/
        
        // Add cars from queue
        int four = 4;
        int sixty = 60;
        for (int i = 0; i<four;i++){
            IntersectionFlowRate tempRate = m_flowRate[i];
            
        }
        
        
        
        TrafficSim::printBoard(); //print intersection board
    }
       
        

    cout<<"Determine if light should change: done\n";
    cout<<"Remove cars from queue\n";
    cout<<"Add cars from queue\n";
    cout<<"Print intersection (board): done\n";
}
