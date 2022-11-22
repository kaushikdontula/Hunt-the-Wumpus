#ifndef pit_h
#define pit_h

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>

#include "event.h"


using namespace std;



class Pit : public Event{
    
    private:
        // string adjacent;
        // string in_room;
        char output;
    
    public:
        Pit();

        char get_symbool();
        string get_adjacent() const;
        string get_in_room() const;
        ~Pit();
     
};


#endif