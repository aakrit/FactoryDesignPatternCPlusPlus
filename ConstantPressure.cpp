//
//  ConstantPressure.cpp
//  HW3
//
//  Created by Aakrit Prasad on 5/20/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "ConstantPressure.h"
#include "Hardware.h"
#include <unistd.h>
#include <fstream>

using namespace std;

ConstantPressure::ConstantPressure(string name, double partsize): MachineControl(name, partsize)
{
    //set the values in the super abstract class and create a pointer to the hardware object in the Superclass contructor
    Hardware *hw = new Hardware(name, partsize);
    //save the pointer to the hardware object in this class and the super class
    
    ha = hw;
    h = hw;
}


void ConstantPressure::startRecipe()
{
    if (ha->time == 100)
    {
        ha->exiting();
    }
    ofstream cp;
    cp.open("/Users/aakritprasad/OODesignClass/HWs_Labs/hw3/HW3/HW3/ConstantPressure.DAS.csv"); //, ofstream::out | ofstream::app);
    cp << ha->name << ", " << "Constant Pressure" << ", " << ha->part_size << endl;
    cp << "Time" << ", " << "Pressure" << ", " << "Current" << endl;
    //takes in a vector of current/amp values from the Macine Control
    ha->pressure = ha->part_size+100;
    while (ha->time <= 10)
    {
        if(cp.is_open())
        {
            cout << "Opened DAS FILE" << endl;
            cp << ha->time << ", " << ha->pressure << ", " << ha->current << endl;
        }
        else
        {
            cout << "Error opening Manual File" << endl;
        }
        ha->printCurrent();
        ha->time++;
        ha->current = 2 * ha->time; //for 10 seconds of time
        sleep(1);
    }
    ha->partfinished();
}