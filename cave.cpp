/******************************************************************* ** 
** Program: cave.cpp
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
#include <vector>
#include <ncurses.h>

#include "cave.h"
#include "room.h"

using namespace std;

Cave::Cave (){
    int size=0;
    while(size <4){
    cout << "What is the size of the cave you want (in rooms)";
    cin >> size;
    }
    this->dimension = size;

    arrows =3;
    gold =false;
    wumpus=1;

    game_over = false;

    cave_rooms.resize(size,vector<Room> (size));

}



/******************************************************************* 
** Function: get_player_position
** Description: this creates random coordiantes for the players position
** Parameters: none 
** Pre-conditions: startx starty
** Post-conditions: creates random position
*******************************************************************/
void Cave::get_player_position(){
    startx = random();
    starty = random();
}



/******************************************************************* 
** Function: get_direction
** Description: this gets the user input for the direction 
** Parameters: none 
** Pre-conditions: movement string
** Post-conditions:creates the movement string and equals it to the players choice
*******************************************************************/
void Cave::get_direction(){
    cout << "w = up " << endl;
    cout << "a = left " << endl;
    cout << "s = down " << endl;
    cout << "d = right " << endl;
    cout << "Please enter a space before the direction to shoot an arrow (arrows can only travel up to 3 rooms)" << endl;
    system("stty -echo");
    system("stty cbreak");

    movement = getchar();

    system ("stty echo");
    system ("stty -cbreak");
    //getline(cin,movement);
    if(movement == " "){
        cout << "Please enter the direction of the arrow... ";
        system("stty -echo");
        system("stty cbreak");
        movementa = getchar();
        system ("stty echo");
        system ("stty -cbreak");
        shoot_arrows();
    }
}



/***************************************************************** 
** Function: random
** Description: this creates a random number for the coordinates
** Parameters: none  
** Pre-conditions: none
** Post-conditions: returns random number
*******************************************************************/
int Cave::random(){

    int random=0;
    //cout << dimension << endl;
    random = rand()%dimension;
    //cout << "Random number = " << random << endl;
    return random;
}


/******************************************************************* 
** Function: set_events
** Description: this initializes the events for all the rooms 
** Parameters: none 
** Pre-conditions: Room class
** Post-conditions: creates events in random rooms in the vector
*******************************************************************/
void Cave::set_events(){
    srand(time(NULL));

    get_player_position();
    ropex = startx;
    ropey = starty;
    cave_rooms[startx][starty];

    wumpusx = random();
    wumpusy = random();
    goldx = random();
    goldy = random();

    cave_rooms[wumpusx][wumpusy].set_event(0);
    cave_rooms[goldx][goldy].set_event(1);
    cave_rooms[random()][random()].set_event(2);
    cave_rooms[random()][random()].set_event(2);
    cave_rooms[random()][random()].set_event(3);
    cave_rooms[random()][random()].set_event(3);
}



/******************************************************************* 
** Function: move_player
** Description: this function moves the player based on the user input
** Parameters: none 
** Pre-conditions: user enters the movement type
** Post-conditions: users movement is created
*******************************************************************/
void Cave::move_player(){

    while(check_bounds() == true){
        if (movement== "w"){
            startx = startx-1;
        }
        if (movement== "a"){
            starty = starty-1;
        }
        if (movement== "s"){
            startx = startx+1;
        }
        if (movement== "d"){
            starty = starty +1;
        }
        break;
    }
    bool check;
    while (check_bounds() == false){
        error_handle_movement(check);
        break;
    }
}



/******************************************************************* 
** Function: error_handle_movement
** Description: this function requires the user to continue inputting 
** Parameters: none 
** Pre-conditions: user enters the movement type
** Post-conditions: users movement is created
*******************************************************************/
void Cave::error_handle_movement(bool &check){
        cout << "You cant go that way, try again...." << endl;
        get_direction();
        if (movement== "w"){
            startx = startx-1;
            check = check_bounds();
        }
        if (movement== "a"){
            starty = starty-1;
            check = check_bounds();
        }
        if (movement== "s"){
            startx = startx+1;
            check = check_bounds();
        }
        if (movement== "d"){
            starty = starty +1;
            check = check_bounds();
        }
}

/******************************************************************* 
** Function: check_conditionals
** Description: this function checks if the room has an event what action is to be taken
** Parameters: none 
** Pre-conditions: check_in_room function
** Post-conditions: implements the games rules
*******************************************************************/
void Cave:: check_conditionals(){
    if(cave_rooms[startx][starty].get_event() == 'B'){
        startx = random();
        starty = random();
    }
    else if((cave_rooms[startx][starty].get_event() == 'W') && (wumpus == true)){
        player = false;
    }
    else if(cave_rooms[startx][starty].get_event() == 'G'){
        gold = true;
        cave_rooms[startx][starty].delete_wumpus();
    }
    else if(cave_rooms[startx][starty].get_event() == 'P'){
        player = false;
    }
    else{

    }
}



/******************************************************************* 
** Function: check_game_over
** Description: this funciton checks if the game is over
** Parameters: none 
** Pre-conditions: game has to be created and initialized
** Post-conditions: returns true or false based on conditions
*******************************************************************/
bool Cave:: check_game_over(){
    if(arrows <1){
        cout << "You are out of arrows, you have lost the game... " << endl;
        return true;
    }
    else if (player == false){
        return true;
    }
    else if ((player == true) && (gold == true) && (wumpus == false) && (startx == ropex) && (starty == ropey)){
        cout << "YOU ESCAPED WITH THE ROPE AND WON THE GAME!!!!" << endl;
        return true;
    }
    else {
        return false;
    }
}



/******************************************************************* 
** Function: get_debug_mode
** Description: this function asks user if they want to play in debug mode, and holds it in debug mode variable
** Parameters:none 
** Pre-conditions: debugmode variable
** Post-conditions: holds the debug mode input
*******************************************************************/
void Cave::get_debug_mode(){
    cout << "Do you want to play in debug mode (0-no 1-yes): " ;
    cin >> debug_mode;
}



/******************************************************************* 
** Function: print_cave
** Description: this function prints the cave of rooms whenever called
** Parameters: none 
** Pre-conditions: vector of rooms to be created and initialized
** Post-conditions:prints out the cave
*******************************************************************/
void Cave:: print_cave(){
    for (int i =0; i<dimension; i++){
        cout << "____";
    }
    cout << endl;
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j <= dimension-1; j++){
            if ((startx == i) && (starty== j)){
                cout << "| * ";
            }
                else if((cave_rooms[i][j].get_has_event() == true) && (debug_mode == 1)){
                    cout << "| " << cave_rooms[i][j].get_event() << " ";
                }
                    else{
                        cout << "|   ";
                    }
        }
        cout << endl;
        for(int i = 0; i < dimension; i++){
            cout << "____";
        }
        cout << endl;
    }
}



/******************************************************************* 
** Function: get_in_rooms
** Description: this function is polymorphic and gets the event percept from the rooms that they player goes into
** Parameters: none 
** Pre-conditions: event class and child classes of it
** Post-conditions: outputs the in room percept
*******************************************************************/
void Cave::get_in_rooms(){
    if(cave_rooms[startx][starty].get_has_event() == true){
        cout << cave_rooms[startx][starty].getinroom() << endl;
        check_conditionals();
    }
}



/******************************************************************* 
** Function: get_adjacents
** Description: This function checks the adjacent roooms for events and if it has an event it outputs the adjacent percept
** Parameters: none
** Pre-conditions: adjacent percept in event class and its children
** Post-conditions:outputs the percepts of the adjacent rooms
*******************************************************************/
void Cave::get_adjacents(){
    //fix this
    if((startx >0)){
        if(cave_rooms[startx-1][starty].get_has_event() == true){
            cout << cave_rooms[startx-1][starty].getadjacent() << endl;
        }
    }
    if((startx != dimension-1)){
        if(cave_rooms[startx+1][starty].get_has_event() == true){
            cout << cave_rooms[startx+1][starty].getadjacent() << endl;
        }
    }
    if(starty>0){
        if(cave_rooms[startx][starty-1].get_has_event() == true){
            cout << cave_rooms[startx][starty-1].getadjacent() << endl;
        }
    }
    if(starty != dimension-1){
        if(cave_rooms[startx][starty+1].get_has_event() == true){
            cout << cave_rooms[startx][starty+1].getadjacent() << endl;

        }
    }
}



/******************************************************************* 
** Function: move_wumpus
** Description: this function moves the wumpus
** Parameters: none 
** Pre-conditions: wumpus event
** Post-conditions:this moves the wumpus 75% of the time everytime an arrow is missed
*******************************************************************/
void Cave:: move_wumpus(){
    srand(time(NULL));
    int temp = rand()%4;
    cout << temp << endl;
    if((temp == 0)|| (temp == 1) || (temp == 2)){
        cave_rooms[wumpusx][wumpusy].delete_wumpus();
        wumpusx = random();
        wumpusy = random();
        cave_rooms[wumpusx][wumpusy].set_event(0);
    }
}


/******************************************************************* 
** Function: shoot_north
** Description: this function checks the 3 rooms in the adjacent direction to it to see if there is a wumpus and if there is it kills it
** Parameters: none
** Pre-conditions: wumpus event
** Post-conditions: wumpus either dies, or moves, and arrows get lost
*******************************************************************/
void Cave:: shoot_north(){
    if(startx>0){
        if((cave_rooms[startx-1][starty].get_has_event() == true)){
            if(cave_rooms[startx-1][starty].get_event() == 'W'){
                cout << "Great job! You killed the wumpus!!!" << endl;
                wumpus = 0;
            }
        }
    }
    if((startx>1)){
        if((cave_rooms[startx-2][starty].get_has_event() == true)){
            if(cave_rooms[startx-2][starty].get_event() == 'W'){
                cout << "Great job! You killed the wumpus!!!" << endl;
                wumpus = 0;
            }
        }
    }
    if((startx>2)){
         if((cave_rooms[startx-3][starty].get_has_event() == true)){
            if(cave_rooms[startx-3][starty].get_event() == 'W'){
                cout << "Great job! You killed the wumpus!!!" << endl;
                wumpus = 0;
            }
        }
    }
    if (wumpus ==1){
        cout << "You missed the wumpus! There is a 75% chance that the wumpus moved to another random room..." << endl;
        move_wumpus();
    }
        else { cave_rooms[wumpusx][wumpusy].delete_wumpus();
        }

}



/******************************************************************* 
** Function: shoot_south
** Description: this function checks the 3 rooms in the adjacent direction to it to see if there is a wumpus and if there is it kills it
** Parameters: none
** Pre-conditions: wumpus event
** Post-conditions: wumpus either dies, or moves, and arrows get lost
*******************************************************************/
void Cave:: shoot_south(){
    if(startx<dimension-1){
        if((cave_rooms[startx+1][starty].get_has_event() == true)){
            if(cave_rooms[startx+1][starty].get_event() == 'W'){
                cout << "Great job! You killed the wumpus!!!" << endl;
                wumpus = 0;
            }
        }
    }
    if((startx<dimension-2)){
        if((cave_rooms[startx+2][starty].get_has_event() == true)){
            if(cave_rooms[startx+2][starty].get_event() == 'W'){
                cout << "Great job! You killed the wumpus!!!" << endl;
                wumpus = 0;
            }

        }
    }
    if((startx<dimension-3)){
         if((cave_rooms[startx+3][starty].get_has_event() == true)){
            if(cave_rooms[startx+3][starty].get_event() == 'W'){
                cout << "Great job! You killed the wumpus!!!" << endl;
                wumpus = 0;
            }
        }
    }
    if (wumpus ==1){
        cout << "You missed the wumpus! There is a 75% chance that the wumpus moved to another random room..." << endl;
        move_wumpus();
    }
        else { cave_rooms[wumpusx][wumpusy].delete_wumpus();
        }
}



/******************************************************************* 
** Function: shoot_west
** Description: this function checks the 3 rooms in the adjacent direction to it to see if there is a wumpus and if there is it kills it
** Parameters: none
** Pre-conditions: wumpus event
** Post-conditions: wumpus either dies, or moves, and arrows get lost
*******************************************************************/
void Cave::shoot_west(){
    if(starty>0){
        if((cave_rooms[startx][starty-1].get_has_event() == true)){
            if(cave_rooms[startx][starty-1].get_event() == 'W'){
                cout << "Great job! You killed the wumpus!!!" << endl;
                wumpus = 0;
            }
        }
    }
    if((starty>1)){
        if((cave_rooms[startx][starty-2].get_has_event() == true)){
            if(cave_rooms[startx][starty-2].get_event() == 'W'){
                cout << "Great job! You killed the wumpus!!!" << endl;
                wumpus = 0;
            }
        }
    }
    if((starty>2)){
         if((cave_rooms[startx][starty-3].get_has_event() == true)){
            if(cave_rooms[startx][starty-3].get_event() == 'W'){
                cout << "Great job! You killed the wumpus!!!" << endl;
                wumpus = 0;
            }
        }
    }
    if (wumpus ==1){
        cout << "You missed the wumpus! There is a 75% chance that the wumpus moved to another random room..." << endl;
        move_wumpus();
    }
        else { cave_rooms[wumpusx][wumpusy].delete_wumpus();
        }
}




/******************************************************************* 
** Function: shoot_east
** Description: this function checks the 3 rooms in the adjacent direction to it to see if there is a wumpus and if there is it kills it
** Parameters: none
** Pre-conditions: wumpus event
** Post-conditions: wumpus either dies, or moves, and arrows get lost
*******************************************************************/
void Cave:: shoot_east(){
    if(starty<dimension-1){
        if((cave_rooms[startx][starty+1].get_has_event() == true)){
            if(cave_rooms[startx][starty+1].get_event() == 'W'){
                cout << "Great job! You killed the wumpus!!!" << endl;
                wumpus = 0;
            }
        }
    }
    if((starty<dimension-2)){
        if((cave_rooms[startx][starty+2].get_has_event() == true)){
            if(cave_rooms[startx][starty+2].get_event() == 'W'){
                cout << "Great job! You killed the wumpus!!!" << endl;
                wumpus = 0;
            }
        }
    }
    if((starty<dimension-3)){
         if((cave_rooms[startx][starty+3].get_has_event() == true)){
            if(cave_rooms[startx][starty+3].get_event() == 'W'){
                cout << "Great job! You killed the wumpus!!!" << endl;
                wumpus = 0;
            }
        }
    }
    if (wumpus ==1){
        cout << "You missed the wumpus! There is a 75% chance that the wumpus moved to another random room..." << endl;
        move_wumpus();
    }
        else { cave_rooms[wumpusx][wumpusy].delete_wumpus();
        }
}




/******************************************************************* 
** Function: shoot_arrows
** Description: this function checks the user input to see which direction they want to shoot an arrow
** Parameters: none
** Pre-conditions: wumpus event
** Post-conditions: shoots an arrow and subtracts an arrow
*******************************************************************/
void Cave:: shoot_arrows(){
    if(movementa == "w" && arrows >0){
        cout << "HEYYY" << endl;
        arrows--;
        shoot_north();
    }
    if(movementa == "a"){
        arrows--;
        shoot_west();
    }
    if(movementa == "s"){
        arrows--;
        shoot_south();
    }
    if(movementa == "d"){
        arrows--;
        shoot_east();
    }
}




/******************************************************************* 
** Function: check_bounds
** Description: this function checks whether the player is in bounds of the game or not
** Parameters: none
** Pre-conditions: player position updated
** Post-conditions:returns true or false depending on if the player is in bounds or not
*******************************************************************/
bool Cave::check_bounds(){
    if (startx>dimension-1){
        startx--;
        return false;
    }
    else if(startx<0){
        startx++;
        return false;
    }
    else if (starty>dimension-1){
        starty--;
        return false;
    }
    else if(starty<0){
        starty++;
        return false;
    }
    else
        return true;
}



/******************************************************************* 
** Function: reset_game
** Description: this function resets the game after the game is over
** Parameters: int playagain
** Pre-conditions: game_over function and playagain input
** Post-conditions:resets the member variables to be able to play the game again
*******************************************************************/
void Cave::reset_game(int playagain){
    if(playagain==1){
        get_player_position();
        if(wumpus == 0){
            cave_rooms[wumpusx][wumpusy].set_event(0);
        }
        if(gold == true){
            cave_rooms[goldx][goldy].set_event(1);
        }
    }
    if(playagain == 2){
        if(wumpus == 1){
            cave_rooms[wumpusx][wumpusy].delete_wumpus();
        }
        if(gold == false){
            cave_rooms[goldx][goldy].delete_wumpus();
        }
    }
    ropex = startx;
    ropey = starty;
    wumpus = true;
    player = true;
    game_over = false;
    gold =true;
    arrows = 3;
}



/******************************************************************* 
** Function: play_game
** Description: this function contains the order of functions in order to play the game
** Parameters: int &playagain
** Pre-conditions: all functions to play game
** Post-conditions: allows the user to play the game
*******************************************************************/
void Cave::play_game(int &playagain){
        get_debug_mode();
        set_events();
        print_cave();
        do{
            do{
                
                get_direction();
                move_player();
                print_cave();
                get_adjacents();
                get_in_rooms();
                print_cave();
            }while(check_game_over() == false);
            cout << "Do you want to play again (0-quit 1-same map 2-new map)";
            cin >> playagain;
            reset_game(playagain);
        }while (playagain == 1);
        delete_events();
        cout << "Game Over... " << endl;
}



/******************************************************************* 
** Function: AI_game
** Description: this function simulates an AI version of the game
** Parameters: none
** Pre-conditions: the user needs to input whether they want to play AI or not
** Post-conditions: plays an AI game
*******************************************************************/
void Cave::AI_game(int &playagain){
    string userinput;
    debug_mode =1;
    set_events();
    print_cave();
    do{
        choose_direction();
        move_player();
        print_cave();
        get_adjacents();
        get_in_rooms();
        print_cave();
        cout << "Press enter for next turn: " << endl;
        getline(cin, userinput);
    }while(check_game_over() == false);
    delete_events();
    cout << "Do you want to play again? (1-no 2-yes): ";
    cin >> playagain;
    
}



/******************************************************************* 
** Function: choose direction
** Description: this function allows AI to choose the direction to go
** Parameters: none 
** Pre-conditions: AI game and all functions to play game
** Post-conditions: chooses the direction that AI wants to go into
*******************************************************************/
void Cave::choose_direction(){
    
    random_direction(0," ");

}



/******************************************************************* 
** Function: AI_shoots
** Description: this function checks if the AI shoots an arrow
** Parameters: int direction
** Pre-conditions: AI game
** Post-conditions: chooses the direction to shoot
*******************************************************************/
void Cave:: AI_shoots(int direction){
        if (direction == 4){
            arrows--;
            shoot_north();
        }
        else if (direction == 5){
            arrows--;
            shoot_west();
        }
        else if (direction == 6){
            arrows--;
            shoot_south();
        }
        else if (direction == 7){
            arrows--;
            shoot_east();
        }
}



/******************************************************************* 
** Function: random_direction
** Description: this simulates a random direction generator for the AI
** Parameters: int i, string type 
** Pre-conditions: AI game
** Post-conditions: returns a random direction
*******************************************************************/
void Cave::random_direction(int i, string type){
    srand(time(NULL));
    int direction;
    string temp;
        direction = rand()%8;
        cout << direction << endl;
        if (direction == 0){
            movement = "w";
        }
        else if (direction == 1){
            movement = "a";
        }
        else if (direction == 2){
            movement = "s";
        }
        else if (direction == 3){
            movement = "d";
        }
        AI_shoots(direction);
       
}

    



/******************************************************************* 
** Function: delete_events
** Description: this function deletes all dynamic memory
** Parameters: none
** Pre-conditions: events have been created dynamically
** Post-conditions: deletes all dynamic memory
*******************************************************************/
void Cave::delete_events(){
    for(int i =0;i<dimension;i++){
        for(int j =0; j<dimension; j++){
            if(cave_rooms[i][j].get_has_event() == 1){
                cave_rooms[i][j].delete_wumpus();
            }
        }
    }
}


