#include "Guest.h"

Guest::Guest(string userName, UserType userT,
             int nightC, int dryClC, int spaC, int numOfN, int numOfRooms
             , bool dryCB, bool spaCB)
             : User(move(userName), userT) {
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

int Guest::getNumOfNights() {
    return Guest::numOfNights;
}

int Guest::calculateTotalCost() {
    return Guest::numOfNights * Guest::costPerNight
    + (dryCleaningB ? dryCleaningCost : 0)
    + (spaCleaningB ? spaCost : 0);
}

void Guest::extendReservation(int extraNights) {
    Guest::numOfNights += extraNights;
}

int Guest::calExtraNightsCost(int extraNights) {
    return extraNights * Guest::costPerNight;
}

int Guest::getNumOfRooms() {
    return Guest::numOfRooms;
}

Guest::~Guest() {

}
