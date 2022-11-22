#ifndef bats_h
#define bats_h
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>

#include "event.h"

using namespace std;


class Bats : public Event{
    
    private:
        // string adjacent;
        // string in_room;
        char output;

    public:
        Bats();
        char get_symbool();
        string get_adjacent() const;
        string get_in_room() const;
        ~Bats();
      
};






#endif