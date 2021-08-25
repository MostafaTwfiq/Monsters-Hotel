#ifndef MONSTERSHOTEL_USER_H
#define MONSTERSHOTEL_USER_H

#include <string>
using namespace std;

enum UserType {
    RECEPTIONIST, MONSTER, HUMAN
};

class User {

private:
    string name;
    UserType userType;
    int ID;
    static int ID_counter;


protected:
    User();
    User(string name, UserType userType);

public:
    string getName();
    int getID();
    UserType getUserType();
    ~User();

};


#endif //MONSTERSHOTEL_USER_H
