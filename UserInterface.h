//
//  UserInterface.h
//  HW3
//
//  Created by Aakrit Prasad on 5/18/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __HW3__UserInterface__
#define __HW3__UserInterface__

#include <iostream>

//The user interface class is instantiated in the main function call and interacts with the user as well as the machine control layer passing information

class MachineControl;

class UserInterface
{
    
    //each UnseInterface object stores a pointer to the MachineControl object it using to get to the hardware layer
    MachineControl *m;
    
public:
    //the user passes widget name and partsize to the UserInterface
    UserInterface(std::string, double, int);
    
    double setCurrent(double);
    double setPressure(double);
    
    double getCurrent();
    double getPressure();
    
    bool manualRun(double, double, int);
    void manualRunStop();
    void executeRecipe();


    
};



#endif /* defined(__HW3__UserInterface__) */
