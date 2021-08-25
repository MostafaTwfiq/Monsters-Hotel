#include "Monster.h"

Monster::Monster(string name, int numOfNights, bool dryC, bool spaC)
: Guest(move(name), MONSTER, 200, 30, 50, numOfNights, dryC, spaC) {

}
