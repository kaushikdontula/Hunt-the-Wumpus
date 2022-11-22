#ifndef event_h
#define event_h
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>

// #include "bats.h"
// #include "gold.h"
// #include "pit.h"
// #include "wumpus.h"

using namespace std;



class Event {
    
    protected:
        string adjacent;
        string in_room;
        char output;

    public:
        Event();
        char get_symbool();
        virtual string get_adjacent() const =0;
        virtual string get_in_room() const =0;
        virtual ~Event() =0;
     


};





#endif