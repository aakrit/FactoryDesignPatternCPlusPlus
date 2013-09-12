//
//  ConstantCurrent.cpp
//  HW3
//
//  Created by Aakrit Prasad on 5/20/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "ConstantCurrent.h"
#include "Hardware.h"
#include <unistd.h>
#include <fstream>

using namespace std;

ConstantCurrent::ConstantCurrent(string name, double partsize): MachineControl(name, partsize)
{
    //set the values in the super abstract class and create a pointer to the hardware object in the Superclass contructor
    Hardware *hw = new Hardware(name, partsize);
    //save the pointer to the hardware object in this class and the super class
    
    ha = hw;
    h = hw;
}


void ConstantCurrent::startRecipe()
{
    if (ha->time == 100)
    {
        ha->exiting();
    }
    ofstream cc;
    cc.open("/Users/aakritprasad/OODesignClass/HWs_Labs/hw3/HW3/HW3/ConstantCurrent.DAS.csv"); //, ofstream::out | ofstream::app);
    cc << ha->name << ", " << "Constant Current" << ", " << ha->part_size << endl;
    cc << "Time" << ", " << "Pressure" << ", " << "Current" << endl;
    //takes in a vector of pressure values from the Machine Control
    //    time = 0;
    ha->pressure = 50;
    ha->current = ha->part_size+50;
    while (ha->time <= 20)
    {
        if(cc.is_open())
        {
            cout << "Opened DAS FILE" << endl;
            cc << ha->time << ", " << ha->pressure << ", " << ha->current << endl;
        }
        else
        {
            cout << "Error opening Manual File" << endl;
        }
        ha->printCurrent();
        ha->time++;
        ha->pressure = (50 - (ha->time * 2)); //for 20 seconds of time
        
        sleep(1);
    }
    ha->partfinished();
}