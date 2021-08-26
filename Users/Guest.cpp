#include "Guest.h"

Guest::Guest(string userName, UserType userT,
             int nightC, int dryClC, int spaC, int numOfN, int numOfRooms
             , bool dryCB, bool spaCB)
             : User(move(userName), userT) {
    Guest::costPerNight = nightC;
    Guest::dryCleaningCost = dryClC;
    Guest::spaCost = spaC;
    Guest::numOfNights = numOfN;
    Guest::numOfRooms = numOfRooms;
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
    return Guest::numOfNights * Guest::costPerNight * Guest::numOfRooms
    + (dryCleaningB ? dryCleaningCost : 0)
    + (spaCleaningB ? spaCost : 0);
}

void Guest::extendReservation(int extraNights) {
    Guest::numOfNights += extraNights;
}

int Guest::calExtraNightsCost(int extraNights) {
    return extraNights * Guest::costPerNight * Guest::numOfRooms;
}

int Guest::getNumOfRooms() {
    return Guest::numOfRooms;
}

Guest::~Guest() {

}

string Guest::toString() {
    string s;
    s.append("User type: ");
    s.append(Guest::getUserType() == MONSTER ? "Monster\n" : "Human\n");
    s.append("Number of reserved rooms: ");
    s.append(to_string(Guest::getNumOfRooms()));
    s.append("\n");
    s.append("Number of nights: ");
    s.append(to_string(Guest::getNumOfNights()));
    s.append("\n");
    s.append("Dry cleaning: ");
    s.append(Guest::dryCleaningB ? "Yes\n" : "No\n");
    s.append("Spa cleaning: ");
    s.append(Guest::spaCleaningB ? "Yes\n" : "No\n");
    s.append("Total cost: ");
    s.append(to_string(Guest::calculateTotalCost()));
    return s;
}
