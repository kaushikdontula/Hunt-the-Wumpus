/******************************************************************* ** 
** Program: wumpus.cpp
** Author: Kaushik Dontula
** Date: 10/23/2022
** Description: This program creates the wumpus class
** Input: all class files
** Output: hand class 
*******************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <cstring>
#include <string>

#include "wumpus.h"
#include "event.h"

using namespace std;

Wumpus:: Wumpus(){
    adjacent = "You semll a terrible stench nearby... ";
    in_room = "You have been eaten by the Wumpus, game is now over... ";
    output = 'W';
}




/******************************************************************* 
** Function: get_symbol
** Description: this returns a symbol from the member variables
** Parameters: none 
** Pre-conditions: member variable
** Post-conditions: returns the symbol type
*******************************************************************/
char Wumpus::get_symbool(){
    return output;
}



/******************************************************************* 
** Function: get_adjacent
** Description: constant function that returns the string member variable for get adjacent
** Parameters: none 
** Pre-conditions: member variable for adjacent
** Post-conditions: returns the string percept
*******************************************************************/
string Wumpus::get_adjacent() const{
    return adjacent;
}



/******************************************************************* 
** Function: get_in_room
** Description: constant function that returns the string member variable for get_in_room
** Parameters: none 
** Pre-conditions: member variable for in_room
** Post-conditions: returns the string percept
*******************************************************************/
string Wumpus::get_in_room() const{
    return in_room;
}

Wumpus::~Wumpus(){
    cout << "Inside the wumpus destructor... " << endl;
}

