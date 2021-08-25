#ifndef MONSTERSHOTEL_HUMAN_H
#define MONSTERSHOTEL_HUMAN_H

#include "Guest.h"

class Human : public Guest{

    Human(string name, int numOfNights, int numOfRooms, bool dryC, bool spaC);

};


#endif //MONSTERSHOTEL_HUMAN_H
