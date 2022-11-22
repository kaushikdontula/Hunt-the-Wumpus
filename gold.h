#ifndef gold_h
#define gold_h

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>

#include "event.h"


using namespace std;



class Gold : public Event{
    
    private:
        // string adjacent;
        // string in_room;
        char output;

    public:
        //default constructor
        Gold();

        char get_symbool();

        //accessors
        string get_adjacent() const;
        string get_in_room() const;

        //destructor
        ~Gold();
      
};



#endif