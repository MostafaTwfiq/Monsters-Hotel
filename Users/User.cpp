#include "User.h"
#include "../Properties/HotelProperties.h"

User::User(string name, UserType userType) : name(move(name)), userType(userType) {
    User::ID = HotelProperties::IDCounter;
    HotelProperties::IDCounter += 1;
}

int User::getID() {
    return User::ID;
}

string User::getName() {
    return User::name;
}

UserType User::getUserType() {
    return User::userType;
}

User::~User() {

}
