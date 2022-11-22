/******************************************************************* ** 
** Program: event.cpp
** Author: Kaushik Dontula
** Date: 10/23/2022
** Description: This program creates the class deck
** Input: all class files
** Output: deck class 
*******************************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>


#include "event.h"

using namespace std;

//event constructor (default)
Event::Event(){
    adjacent = "";
    in_room = "";
    output = ' ';
}


/******************************************************************* 
** Function: get_symbol
** Description: this function gets the symbol for the child classes
** Parameters: none 
** Pre-conditions: none
** Post-conditions: returns the symbol
*******************************************************************/
char Event::get_symbool(){
    return output;
}


//event destructor
Event::~Event(){
    cout << "Inside the event destructor... " << endl;
}


