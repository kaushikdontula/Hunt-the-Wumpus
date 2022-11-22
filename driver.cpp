
/******************************************************************* ** 
** Program: assignment4.cpp
** Author: Kaushik Dontula
** Date: 10/23/2022
** Description: This program simulates a game of go fish
** Input: all class files
** Output: gofish game 
*******************************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>

#include "cave.h"



using namespace std;






int main(){

     bool gamemode;
     cout << "Do you want to play in AI mode (0-no 1-yes): ";
     cin >> gamemode;
     int playagain =0;
     
     do{
          //Cave* cave = new Cave();
          Cave cave;
          if(gamemode == 0){
               cave.play_game(playagain);
          }
          else if(gamemode == 1){
               cave.AI_game(playagain);
          }
          
     }while(playagain == 2);



     
     return 0;
}