//
// Created by mosta on 8/25/2021.
//

#ifndef MONSTERSHOTEL_MONSTER_H
#define MONSTERSHOTEL_MONSTER_H

#include "Guest.h"

class Monster : public Guest {

public:
    Monster(string name, int numOfNights, bool dryC, bool spaC);

};


#endif //MONSTERSHOTEL_MONSTER_H
