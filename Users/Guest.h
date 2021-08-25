#ifndef MONSTERSHOTEL_GUEST_H
#define MONSTERSHOTEL_GUEST_H

#include "User.h"

class Guest : public User {

private:
    int costPerNight;
    int dryCleaningCost;
    int spaCost;
    int numOfNights;
    int numOfRooms;
    bool dryCleaningB;
    bool spaCleaningB;

protected:
    Guest(string userName, UserType userT,
          int nightC, int dryClC, int spaC, int numOfN, int numOfRooms,
          bool dryCB, bool spaCB);

public:
    int getCostPerNight();
    int getDryCleanCost();
    int getSpaCost();
    int getNumOfNights();
    int getNumOfRooms();
    int calculateTotalCost();
    int calExtraNightsCost(int extraNights);
    void extendReservation(int extraNights);


};


#endif //MONSTERSHOTEL_GUEST_H
