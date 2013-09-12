//
//  Ramp.h
//  HW3
//
//  Created by Aakrit Prasad on 5/20/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __HW3__Ramp__
#define __HW3__Ramp__

#include <iostream>

#include "MachineControl.h"

class Hardware;

class Ramp: public MachineControl
{
    
public:
    Hardware *ha;
    
    Ramp(std::string, double);
    
    virtual void startRecipe();

};



#endif /* defined(__HW3__Ramp__) */
