#include "Guest.h"

#include <utility>

Guest::Guest(string userName, UserType userT, int nightC, int dryClC, int spaC, int numOfN
             ,  bool dryCB, bool spaCB) : User(move(userName), userT) {
    Guest::costPerNight = nightC;
    Guest::dryCleaningCost = dryClC;
    Guest::spaCost = spaC;
    Guest::numOfNights = numOfN;
    Guest::dryCleaningB = dryCB;
    Guest::spaCleaningB = spaCB;

}

int Guest::getCostPerNight() {
    return Guest::costPerNight;
}

int Guest::getDryCleanCost() {
    return Guest::dryCleaningCost;
}

int Guest::getSpaCost() {
    return spaCost;
}
