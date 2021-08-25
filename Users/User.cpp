#include "User.h"


User::User() {}

User::User(string name, UserType userType) : name(name), userType(userType) {
    User::ID_counter = 0;
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
