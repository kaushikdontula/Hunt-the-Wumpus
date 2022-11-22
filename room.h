#ifndef room_h
#define room_h
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>

#include "event.h"


using namespace std;



class Room {
    private:
        Event *event;
        int num_event;
        bool has_event;

    public:
        Room();
        // ~Room();
        void get_i(int);
        void set_event(int);
        string getinroom();
        string getadjacent();
        char get_event();
        bool get_has_event();
        void delete_wumpus();

};







#endif