#ifndef cave_h
#define cave_h

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <ncurses.h>

#include "room.h"


using namespace std;



class Cave {
      private:

      //vector <Room *> cave;
      vector<vector<Room> > cave_rooms;
      int dimension;
      string movement;
      string movementa;
      int arrows;
      bool gold = false;
      bool wumpus = true;
      bool player = true;

      bool not_this = false;

      int goldx;
      int goldy;

      int wumpusx;
      int wumpusy;

      int startx;
      int starty;

      int ropex;
      int ropey;

      bool game_over;

      bool debug_mode =0;

      public:
      Cave();
      void print_cave();
      void set_events();
      int random();
      void play_game(int&);
      void get_direction();
      void get_player_position();
      void move_player();
      void get_in_rooms();
      bool check_bounds();
      void get_adjacents();
      void check_conditionals();
      bool check_game_over();
      void get_debug_mode();
      void shoot_arrows();
      void shoot_north();
      void shoot_south();
      void shoot_west();
      void shoot_east();
      void reset_game(int);
      void AI_game(int&);
      void choose_direction();
      void AI_shoots(int);
      void random_direction(int, string);
      void move_wumpus();
      void delete_events();
      void error_handle_movement(bool&);
      // ~Cave();
};



#endif