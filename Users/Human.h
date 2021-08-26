#ifndef MONSTERSHOTEL_HUMAN_H
#define MONSTERSHOTEL_HUMAN_H

#include "Guest.h"

class Human : public Guest{

public:
    Human(string name, int numOfNights, int numOfRooms, bool dryC, bool spaC);
    ~Human();

};


#endif //MONSTERSHOTEL_HUMAN_H
