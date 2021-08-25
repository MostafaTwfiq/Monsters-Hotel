#include "Guest.h"

Guest::Guest(string userName, UserType userT, int nightC, int dryClC, int spaC) : User(userName, userT) {
    Guest::costPerNight = nightC;
    Guest::dryCleaningCost = dryClC;
    Guest::spaCost = spaC;
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
