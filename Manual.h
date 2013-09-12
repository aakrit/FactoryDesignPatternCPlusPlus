//
//  Manual.h
//  HW3
//
//  Created by Aakrit Prasad on 5/20/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __HW3__Manual__
#define __HW3__Manual__

#include <iostream>

#include "MachineControl.h"

class Hardware;

class Manual: public MachineControl
{
    
public:
    Hardware *ha;
    
    Manual(std::string, double);
    
    virtual void startRecipe();
    
    bool startManual(double, double, int);
    void manualRunStop();
    double setPressure(double);
    double setCurrent(double);
};



#endif /* defined(__HW3__Manual__) */
