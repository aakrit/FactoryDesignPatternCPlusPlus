//
//  UserInterface.cpp
//  HW3
//
//  Created by Aakrit Prasad on 5/18/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include "UserInterface.h"
#include "MachineControl.h"
#include "Manual.h"
#include "Ramp.h"
#include "ConstantCurrent.h"
#include "ConstantPressure.h"

using namespace std;

UserInterface::UserInterface(string name, double partsize, int recipetype)
{
    if(recipetype == 1)
    {
        MachineControl *mc = new Manual(name, partsize);
        m = mc; //store the location of the machine control object
    }else if (recipetype == 2)
    {
        MachineControl *mc = new ConstantPressure(name, partsize);
        m = mc; //store the location of the machine control object
    }else if (recipetype == 3)
    {
        MachineControl *mc = new ConstantCurrent(name, partsize);
        m = mc; //store the location of the machine control object
    }else if (recipetype == 4)
    {
        MachineControl *mc = new Ramp(name, partsize);
        m = mc; //store the location of the machine control object
    }else
    {
        cout << "ERROR no matching Recipe!" << endl;
        exit(0);
    }
}
bool UserInterface::manualRun(double i, double j, int time)
{
    //takes in the initial control parameters, amps and psi and passes that to the Machine Control layer
    Manual *ma = dynamic_cast<Manual* >(m);
    ma->startManual(i, j, time);
    
    return true;
}
void UserInterface::manualRunStop()
{
    //tells the machine to stop running if less than 100 seconds have passed
    Manual *ma = dynamic_cast<Manual* >(m);
    ma->manualRunStop();
}
void UserInterface::executeRecipe()
{
    //takes a pointer to a machine control object and calls that objects execute recipie function
    if(dynamic_cast<ConstantPressure*>(m))
    {
        ConstantPressure* ra = dynamic_cast<ConstantPressure*>(m);
        ra->startRecipe();
    }
    else if(dynamic_cast<ConstantCurrent*>(m))
    {
        ConstantCurrent* ra = dynamic_cast<ConstantCurrent*>(m);
        ra->startRecipe();
    }
    if(dynamic_cast<Ramp*>(m))
    {
        Ramp* ra = dynamic_cast<Ramp*>(m);
        ra->startRecipe();
    }
}

double UserInterface::setPressure(double d)
{
    Manual *ma = dynamic_cast<Manual* >(m);
    double z = ma->setPressure(d);
    return z;
}
double UserInterface::getCurrent()
{
    return m->getCurrent();
}
double UserInterface::getPressure()
{
    return m->getPressure();
}
double UserInterface::setCurrent(double d)
{
    Manual *ma = dynamic_cast<Manual* >(m);
    double z = ma->setPressure(d);
    return z;
}
