//
//  MachineControl.cpp
//  HW3
//
//  Created by Aakrit Prasad on 5/18/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//
#include "MachineControl.h"
#include "Hardware.h"

using namespace std;

MachineControl::MachineControl(string name, double partsize):time(0)
{

}


double MachineControl::getCurrent()
{
    return h->getCurrent();
}
double MachineControl::getPressure()
{
    return h->getPressure();
}

