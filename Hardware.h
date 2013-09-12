//
//  Hardware.h
//  HW3
//
//  Created by Aakrit Prasad on 5/18/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __HW3__Hardware__
#define __HW3__Hardware__

#include <iostream>
#include <fstream>

class MachineControl;

class Hardware
{

    
public:
    double pressure;
    double current;
    double time;
    double part_size;
    std::string name;
    
    Hardware(std::string, double);
    
    double getPressure();
    double getCurrent();
    double setPressure(double);
    double setCurrent(double);
    
    bool startMaunal(double, double);
    void manualRunStop();
    
    void startConstantPressure();
    void startConstantCurrent();
    void startRamp();

    void stop();
    void exiting();
    void printCurrent();
    void printtofile();
    void partfinished();
    
};





#endif /* defined(__HW3__Hardware__) */
