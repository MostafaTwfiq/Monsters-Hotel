#ifndef MONSTERSHOTEL_MONSTER_H
#define MONSTERSHOTEL_MONSTER_H

#include "Guest.h"

class Monster : public Guest {

public:
    Monster(string name, int numOfNights, int numOfRooms, bool dryC, bool spaC);
    ~Monster();

};


#endif //MONSTERSHOTEL_MONSTER_H
