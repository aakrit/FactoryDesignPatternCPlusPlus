//
//  MachineControl.h
//  HW3
//
//  Created by Aakrit Prasad on 5/18/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __HW3__MachineControl__
#define __HW3__MachineControl__

#include <iostream>


//The Machine Control creates a hardware object to execute the hardware functions and returns the information to the user by essentially controlling the hardware (the machine) using the strategy pattern
class Hardware;

class MachineControl
{
    //Each Machine control object stores a pointer to the harware object its using to execute the creation of the widget
protected:
    
    //RecipeStrategy *rs;
    
public:
    
    Hardware *h;
    std::string name;
    double partsize;
    int time;
    
    MachineControl(std::string, double);
    
    double getPressure();
    double getCurrent();

    
    virtual void startRecipe() = 0; //pure virtual function
    // this function gets implemented in the inherited base classes
    


};




#endif /* defined(__HW3__MachineControl__) */
