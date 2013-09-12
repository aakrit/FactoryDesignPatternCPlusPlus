//
//  ConstantPressure.h
//  HW3
//
//  Created by Aakrit Prasad on 5/20/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#ifndef __HW3__ConstantPressure__
#define __HW3__ConstantPressure__

#include <iostream>

#include "MachineControl.h"

class Hardware;

class ConstantPressure: public MachineControl
{
    
public:
    Hardware *ha;
    
    ConstantPressure(std::string, double);
    
    virtual void startRecipe();
    
};



#endif /* defined(__HW3__ConstantPressure__) */
