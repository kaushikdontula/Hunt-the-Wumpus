#ifndef wumpus_h
#define wumpus_h
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>

#include "event.h"


using namespace std;



class Wumpus : public Event{

    private:
        // string adjacent;
        // string in_room;
        char output;

    public:
        Wumpus();

        char get_symbool();
        string get_adjacent() const;
        string get_in_room() const;
        ~Wumpus();
     
};


#endif