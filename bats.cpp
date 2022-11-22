/******************************************************************* ** 
** Program: bats.cpp
** Author: Kaushik Dontula
** Date: 10/23/2022
** Description: This program creates the game class
** Input: all class files
** Output: game class 
*******************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <cstring>
#include <string>

#include "bats.h"
#include "event.h"

using namespace std;

Bats::Bats(){
    adjacent = "You hear wings flapping nearby...";
    in_room = "You have been taken by a bat. You are placed in a new random room";
    output = 'b';
}



/******************************************************************* 
** Function: get_symbol
** Description: this returns a symbol from the member variables
** Parameters: none 
** Pre-conditions: member variable
** Post-conditions: returns the symbol type
*******************************************************************/
char Bats::get_symbool(){
    return output;
}



/******************************************************************* 
** Function: get_adjacent
** Description: constant function that returns the string member variable for get adjacent
** Parameters: none 
** Pre-conditions: member variable for adjacent
** Post-conditions: returns the string percept
*******************************************************************/
string Bats::get_adjacent() const{
    return adjacent;
}



/******************************************************************* 
** Function: get_in_room
** Description: constant function that returns the string member variable for get_in_room
** Parameters: none 
** Pre-conditions: member variable for in_room
** Post-conditions: returns the string percept
*******************************************************************/
string Bats::get_in_room() const{
    return in_room;
}

Bats::~Bats(){
    cout << "Inside the bats destructor... " << endl;
}

