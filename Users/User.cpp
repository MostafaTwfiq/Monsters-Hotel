#include "User.h"

#include <utility>


User::User() {}

User::User(string name, UserType userType) : name(move(name)), userType(userType) {

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
