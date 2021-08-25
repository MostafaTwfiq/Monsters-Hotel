#ifndef MONSTERSHOTEL_GUEST_H
#define MONSTERSHOTEL_GUEST_H

#include "User.h"

class Guest : public User {

private:
    int costPerNight;
    int dryCleaningCost;
    int spaCost;

protected:
    Guest(string userName, UserType userT, int nightC, int dryClC, int spaC);
    int getCostPerNight();
    int getDryCleanCost();
    int getSpaCost();

};


#endif //MONSTERSHOTEL_GUEST_H
