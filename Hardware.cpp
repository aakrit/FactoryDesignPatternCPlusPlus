//
//  Hardware.cpp
//  HW3
//
//  Created by Aakrit Prasad on 5/18/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "Hardware.h"
#include "unistd.h"
#include "MachineControl.h"
#include <fstream>

using namespace std;

Hardware::Hardware(string name, double partsize): name(name), part_size(partsize), time(0)
{
    cout << "Starting the HardWare to create a Widget named: " << this->name << " with a part size of " << this->part_size << endl;
}

bool Hardware::startMaunal(double pressure, double current)
{
//Although the algorithm for this is implemented in the machine control layer the work is still being done by the Harware layer by the Manual machine controlling it
    return true;
}
void Hardware::manualRunStop()
{
    //it sets the timer value from what ever it current is to be 100 second so the start manual loop finishes and the part is done
    stop();
}

//The 3 methods below (startConstantPressure, startConstantCurrent, startRamp are never called since we've being asked to have the machine control layer control the hardware. Hence the Machine control is controlling the hardware to do what this method could be called to do (from the Machine Control layer) By having it here its very easy for us to switch the control based on vendor preferences
void Hardware::startConstantPressure()
{
    if (this->time == 10)
    {
        exiting();
    }
    //takes in a vector of current/amp values from the Macine Control
    pressure = part_size+100;
    while (time <= 10)
    {
        printCurrent();
        time++;
        current = 2 * time; //for 10 seconds of time
        sleep(1);
    }
    partfinished();
    
}

void Hardware::startConstantCurrent()
{
    if (this->time == 20)
    {
        exiting();
    }
    //takes in a vector of pressure values from the Machine Control
//    time = 0;
    pressure = 50;
    current = part_size+50;
    while (time <= 20)
    {
        printCurrent();
        time++;
        pressure = (50 - (time * 2)); //for 20 seconds of time
        
        sleep(1);
    }
    partfinished();

}
void Hardware::startRamp()
{
    if (this->time == 30)
    {
        exiting();
    }
    if(part_size <= 50)
    {
        //cannot use Ramp recipie, send error to user
        cout << "Cannot use Ramp, part size too low" << endl;
        exit(0); //need to make it loop back to user
    }
//    time = 0;
    while (time <= 30)
    {
        printCurrent();
        time++;
        if(pressure <= 100)
        {
            pressure += 10;
        }
        current += part_size+20;

        sleep(1);
    }
    partfinished();
}
void Hardware::stop()
{
    time = 100;
}
void Hardware::exiting()
{
    cout << "Exiting Widget " << name << " creation ..." << " current part size is: " << part_size << endl;
    exit(0);
}
void Hardware::printCurrent()
{
    cout << "Creating Part...." << endl;
    cout << "time: " << time << " seconds, pressure: " << pressure << " PSI, current: " << current << " AMPS" << endl;
}
void Hardware::partfinished()
{
    cout << "Part CREATED!! " << endl << endl;
}
double Hardware::getCurrent()
{
    return this->current;
}
double Hardware::getPressure()
{
    return this->pressure;
}
double Hardware::setCurrent(double d)
{
    this->current = d;
    return current;
}
double Hardware::setPressure(double d)
{
    this->pressure = d;
    return pressure;
}
void Hardware::printtofile()
{

}
