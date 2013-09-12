//
//  Manual.cpp
//  HW3
//
//  Created by Aakrit Prasad on 5/20/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "Manual.h"
#include "Hardware.h"
#include <unistd.h>
#include <fstream>

using namespace std;

Manual::Manual(string name, double partsize): MachineControl(name, partsize)
{
    //set the values in the super abstract class and create a pointer to the hardware object in the Superclass contructor
    Hardware *hw = new Hardware(name, partsize);
    //save the pointer to the hardware object in this class and the super class
    
    ha = hw;
    h = hw;
}
//The machine control here is implementing the algorithm for controlling the Hardware layer
bool Manual::startManual(double i, double j, int t)
{
    if (ha->time == 100)
    {
        ha->exiting();
    }
    ofstream manfile;
    manfile.open("/Users/aakritprasad/OODesignClass/HWs_Labs/hw3/HW3/HW3/Manual.DAS.csv"); //, ofstream::out | ofstream::app);
    manfile << "Manual" << endl;
    manfile << "Time" << ", " << "Pressure" << ", " << "Current" << endl;
    ha->pressure = i;
    ha->current = j;
    while (ha->time <= t)
    {
        if(manfile.is_open())
        {
            cout << "Opened DAS FILE" << endl;
            manfile << ha->time << ", " << ha->pressure << ", " << ha->current << endl;
        }
        else
        {
            cout << "Error opening Manual File" << endl;
        }
        ha->printCurrent();
        ha->time++;
        sleep(1);
    }
    ha->partfinished();
    manfile.close();
    return true;
}
void Manual::manualRunStop()
{
    ha->manualRunStop();
}

void Manual::startRecipe()
{
    ;//do nothing
}
double Manual::setCurrent(double d)
{
    double z = h->setPressure(d);
    return z;
}
double Manual::setPressure(double d)
{
    double z = h->setPressure(d);
    return z;
}