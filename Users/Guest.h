#ifndef MONSTERSHOTEL_GUEST_H
#define MONSTERSHOTEL_GUEST_H

#include "User.h"

class Guest : public User {

private:
    int costPerNight;
    int dryCleaningCost;
    int spaCost;
    int numOfNights;
    bool dryCleaningB;
    bool spaCleaningB;

protected:
    Guest(string userName, UserType userT, int nightC, int dryClC, int spaC, int numOfN, bool dryCB, bool spaCB);
    int getCostPerNight();
    int getDryCleanCost();
    int getSpaCost();

};


#endif //MONSTERSHOTEL_GUEST_H
