/******************************************************************* ** 
** Program: player.cpp
** Author: Kaushik Dontula
** Date: 10/23/2022
** Description: This program creates the class player
** Input: all class files
** Output: card player 
*******************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <cstring>
#include <string>

#include "gold.h"

Gold::Gold(){
    adjacent = "You see a glimmer nearby... ";
    in_room = "You have captured the gold... ";
    output = 'G';

}


/******************************************************************* 
** Function: get_symbol
** Description: this returns a symbol from the member variables
** Parameters: none 
** Pre-conditions: member variable
** Post-conditions: returns the symbol type
*******************************************************************/
char Gold::get_symbool(){
    return output;
}


/******************************************************************* 
** Function: get_adjacent
** Description: constant function that returns the string member variable for get adjacent
** Parameters: none 
** Pre-conditions: member variable for adjacent
** Post-conditions: returns the string percept
*******************************************************************/
string Gold::get_adjacent() const{
    return adjacent;
}


/******************************************************************* 
** Function: get_in_room
** Description: constant function that returns the string member variable for get_in_room
** Parameters: none 
** Pre-conditions: member variable for in_room
** Post-conditions: returns the string percept
*******************************************************************/
string Gold::get_in_room() const{
    return in_room;
}

//gold destructor
Gold::~Gold(){
    cout << "Inside the gold destructor... " << endl;
}

using namespace std;

