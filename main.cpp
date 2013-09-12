//
//  main.cpp
//  HW3
//
//  Created by Aakrit Prasad on 5/15/13.
//  Copyright (c) 2013 Aakrit Prasad. All rights reserved.
//

#include <iostream>
#include <thread>
#include <csignal>
#include "UserInterface.h"

using namespace std;

UserInterface *sign;
//void handler2(int sig)
//{
//	psignal(sig, "Calling Machine Control Stop Function");
//    sign->manualRunStop();
//}
int main(int argc, const char * argv[])
{
//the program below works as follows:
    // create a loop to ask the user if they want to create a recipe part or if they want to create a manual part.
        // if they want to create a manual part, ask them for a name and part size and creat a user interface object and pass the part size and widget name
        // if they want to create a recipe part, ask them for which recipe they want to createand then a name and part size and creat a user interface object and pass the part size and widget name
            // depending on the recipe they choose create that object via strategy pattern interface and pass it to the machine control object
            // wait for return of part created and loop back
    cout << "Welcome to the Phoenix Fictitious Manufacturing Machine" << endl;
    while(1)
    {
        cout << "To create a Manual Part press 1, to choose from a recipe press 2, to exit press 3" << endl;
        int i = 0;
        if(!(cin >> i))
        {
            cout << "Error, only numbers can be entered!" << endl;
            break;
        }
        if (i == 1)
        {
            cout << "Please enter a name and part size: " << endl;
            cout << "Name: ";
            string name;
            cin >> name;
            cout << "Partsize: ";
            double partsize;
            if(!(cin >> partsize))
            {
                cout << "Error, only numbers can be entered!" << endl;
                break;
            }
            UserInterface *u = new UserInterface(name, partsize, i);
            //sign = u;
            cout << "Enter the Pressure and Current you wish to start at " << endl;
            cout << "Pressure: ";
            double pressure;
            if(!(cin >> pressure))
            {
                cout << "Error, only numbers can be entered!" << endl;
                break;
            }
            cout << "Current: ";
            double current;
            if(!(cin >> current))
            {
                cout << "Error, only numbers can be entered!" << endl;
                break;
            }
            cout << "Enter your running time in seconds (must be less than 100) " << endl;
            cout << "Time: ";
            int time;
            if(!(cin >> time))
            {
                cout << "Error, only numbers can be entered!" << endl;
                break;
            }
            if(time > 100)
            {
                cout << "Error: cannot run the machine for more than 100 seconds" << endl;
                break;
            }
            //signal(SIGINT, handler2);
            u->manualRun(pressure, current, time);
            cout << "To get the Pressure type 1, to get the Current type 2, to get both type 3" << endl;
            int input;
            if(!(cin >> input))
            {
                cout << "Error, only numbers can be entered!" << endl;
                break;
            }
            if (input == 1)
            {
                double z = u->getPressure();
                cout << "The Pressure was: " << z << endl;
            }
            else if (input == 2)
            {
                double z = u->getCurrent();
                cout << "The Current was: " << z << endl;
            }
            else if (input == 3)
            {
                double z = u->getCurrent();
                double x = u->getPressure();
                cout << "The Pressure was: " << x << endl;
                cout << "The Current was: " << z << endl;
            }
            else
            {
                cout << "Error invalid entry!" << endl;
                break;
            }
            delete u;
        }
        else if (i == 2)
        {
            cout << "Please enter a name and part size: " << endl;
            cout << "Name: ";
            string name;
            cin >> name;
            cout << "Partsize: ";
            double partsize;
            if(!(cin >> partsize))
            {
                cout << "Error, only numbers can be entered!" << endl;
                break;
            }
            cout << "Please select from one of the following options: ConstPressure Part type 2; ConstCurrent type 3; Ramp part type 4: " << endl;
            int j = 0;
            if(!(cin >> j))
            {
                cout << "Error, only numbers can be entered!" << endl;
                break;
            }
            UserInterface *u = new UserInterface(name, partsize, j);
//            sign = u;
            u->executeRecipe();
//            cout << "To get the Pressure type 1, to get the Current type 2" << endl;
            delete u;
        }
        else if (i == 3)
        {
            cout << "Thank you and Goodbye!" << endl;
            break;
        }
        else
        {
            cout << "You have entered an incorrect choice, please retry" << endl;
            break;
        }
    }    
    
    return 0;
}



//Things to add
    // writing to files
    // comparing files
