#include "Human.h"

Human::Human(string name, int numOfNights, int numOfRooms, bool dryC, bool spaC)
: Guest(move(name), HUMAN, 500, 70, 100, numOfNights, numOfRooms, dryC, spaC) {

}
