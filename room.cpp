/******************************************************************* ** 
** Program: room.cpp
** Author: Kaushik Dontula
** Date: 10/23/2022
** Description: This program creates the class card
** Input: all class files
** Output: card class 
*******************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>



#include "room.h"
#include "event.h"
#include "wumpus.h"
#include "gold.h"
#include "bats.h"
#include "pit.h"

using namespace std;

Room::Room(){
    num_event = 0;
    //cout << "This is a room fjkdlafjakld" << endl;
    has_event = false;
}



void Room::get_i(int i){
    cout << "Room " << i << endl;
}


/******************************************************************* 
** Function: get_event
** Description: this function returns the type of event that is in that room
** Parameters: none 
** Pre-conditions: the vector has to be created
** Post-conditions: returns the character of the event
*******************************************************************/
char Room::get_event(){
    if (num_event == 0){
        return 'W';
    }
    if (num_event == 1){
        return 'G';
    }
    if (num_event == 2){
       return 'B';
    }
    if (num_event == 3){
        return 'P';
    }
    //else return;
}


/******************************************************************* 
** Function: get_has_event
** Description: this function checks if that room has an event
** Parameters: none 
** Pre-conditions: has_event variable
** Post-conditions: returns if the room has an event or not
*******************************************************************/
bool Room:: get_has_event(){
    return this->has_event;
}



/******************************************************************* 
** Function: delete_wumpus
** Description: this function deletes the event at a specific room and resets all variables to do with it
** Parameters: none 
** Pre-conditions: room event
** Post-conditions: resets the room event to NULL
*******************************************************************/
void Room:: delete_wumpus(){
    has_event = false;
    num_event = 4;
    delete this->event;
    event = NULL;
}



/******************************************************************* 
** Function: set_event
** Description: this function sets the event
** Parameters: i 
** Pre-conditions: int i and vector of rooms
** Post-conditions: creates a new event with dynamic memory in the random room
*******************************************************************/
void Room:: set_event(int i){
    this->num_event = i;
    if (i == 0){
        //cout << "This Room got Wumpus" << endl;
        event = new Wumpus;
        has_event = true;
    }
    else if (i == 1){
        //cout << "This Room got Gold" << endl;
        event = new Gold;
        has_event = true;
    }
    else if (i == 2){
        //cout << "This Room got Bats" << endl;
        event = new Bats;
        has_event = true;
    }
    else if (i == 3){
        //cout << "This Room got Pit" << endl;
        event = new Pit;
        has_event = true;
    }
    else{
        event = NULL;
    }
    
}



/******************************************************************* 
** Function: get_in_room
** Description: this returns the percept for going into the room
** Parameters: none 
** Pre-conditions: child classes for event
** Post-conditions: returns a string that outputs the percept
*******************************************************************/
string Room:: getinroom(){
    return event->get_in_room();
}


/******************************************************************* 
** Function: getadjacent
** Description: this function gets the adjacent percepts and returns it
** Parameters: none 
** Pre-conditions: child classes for event
** Post-conditions: returns the adjacent percept
*******************************************************************/
string Room:: getadjacent(){
    return event->get_adjacent();
}


