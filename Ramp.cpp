//
//  Ramp.cpp
//  HW3
//
//  Created by Aakrit Prasad on 5/20/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "Ramp.h"
#include "Hardware.h"
#include <unistd.h>
#include <fstream>

using namespace std;

Ramp::Ramp(string name, double partsize): MachineControl(name, partsize)
{
    //set the values in the super abstract class and create a pointer to the hardware object in the Superclass contructor
    Hardware *hw = new Hardware(name, partsize);
    //save the pointer to the hardware object in this class and the super class
    
    ha = hw;
    h = hw;
}


void Ramp::startRecipe()
{
    if (ha->time == 100)
    {
        ha->exiting();
    }
    if(ha->part_size <= 50)
    {
        //cannot use Ramp recipie, send error to user
        cout << "Cannot use Ramp, part size too low" << endl;
        exit(0); //need to make it loop back to user
    }
    ofstream ra;
    ra.open("/Users/aakritprasad/OODesignClass/HWs_Labs/hw3/HW3/HW3/Ramp.DAS.csv"); //, ofstream::out | ofstream::app);
    ra << ha->name << ", " << "Ramp" << ", " << ha->part_size << endl;
    ra << "Time" << ", " << "Pressure" << ", " << "Current" << endl;
    //    time = 0;
    ha->current = ha->part_size;
    while (ha->time <= 30)
    {
        if(ra.is_open())
        {
            cout << "Opened DAS FILE" << endl;
            ra << ha->time << ", " << ha->pressure << ", " << ha->current << endl;
        }
        else
        {
            cout << "Error opening Manual File" << endl;
        }
        ha->printCurrent();
        ha->time++;
        if(ha->pressure < 99)
        {
            ha->pressure += 10;
        }
        ha->current += 20;
        
        sleep(1);
    }
    ha->partfinished();
}