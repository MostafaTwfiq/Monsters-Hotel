#include <iostream>
#include <stdio.h>
#include <string.h>

#include "Properties/HotelProperties.h"
#include "Users/User.h"
#include "Users/Guest.h"
#include "Users/Monster.h"
#include "Users/Human.h"
#include "Users/Receptionist.h"

using namespace std;

User *signNewUser(int reservedMonRooms, int reservedHumanRooms);
User **addNewUser(User **usersArr, int length, int usersCount, User *user);
bool checkIfPositiveInteger(const string& s);

int countMonstersResRooms(User **usersArr, int length) {
    int counter = 0;
    for (int i = 0; i < length; i++) {
        if (usersArr[i]->getUserType() == MONSTER)
            counter += ((Monster *) usersArr[i])->getNumOfNights();

    }

    return counter;
}

int countHumansResRooms(User **usersArr, int length) {
    int counter = 0;
    for (int i = 0; i < length; i++) {
        if (usersArr[i]->getUserType() == HUMAN)
            counter += ((Human *) usersArr[i])->getNumOfNights();

    }

    return counter;
}

User *findUserByID(User **usersArr, int length, int ID) {
    for (int i = 0; i < length; i++) {
        if (usersArr[i]->getID() == ID)
            return usersArr[i];

    }

    return nullptr;
}

void receptionistMenu(User **usersArr, int length) {
    string input;
    while (true) {
    cout << "Please choose from the following:-\n1- View number of available and reserved rooms.\n2- List guests.\n3- Logout." << endl;
    cin >> input;
    if (input == "1") {
        int reservedMonRooms = countMonstersResRooms(usersArr, length);
        int reservedHumansRooms = countHumansResRooms(usersArr, length);
        printf("Total available rooms: %d\n", HotelProperties::totalMonRooms - reservedMonRooms + HotelProperties::totalHumanRooms - reservedHumansRooms);
        printf("Total available monsters rooms: %d\n", HotelProperties::totalMonRooms - reservedMonRooms);
        printf("Total available human rooms: %d\n",  HotelProperties::totalHumanRooms - reservedHumansRooms);
        printf("Total reserved monsters rooms: %d\n", reservedMonRooms);
        printf("Total reserved human rooms: %d\n", reservedHumansRooms);
    } else if (input == "2") {
        for (int i = 0; i < length; i++) {
            if (usersArr[i]->getUserType() != RECEPTIONIST) {
                printf("User number %d:-\n", i + 1);
                cout << ((Guest *) usersArr[i])->toString() << endl;
                cout << "\n" << endl;
            }
        }
    } else if (input == "3") {
        return;
    } else {
        cout << "Invalid input !." << endl;
    }
}

void guestMenu() {

}

void printMenu() {
    string input;
    int length = 5;
    int usersCount = 0;
    User **users = (User **) malloc(sizeof (User) * length);


    while (true) {
        cout << "Please choose from the following:\n" << endl;
        cout << "1- New customer.\n2- Old customer\n3- End program\n:- " << endl;
        cin >> input;

        if (input == "1") {
            User *newUser = signNewUser(countMonstersResRooms(users, usersCount), countHumansResRooms(users, usersCount));
            if (newUser != nullptr) {
                users = addNewUser(users, length, usersCount, newUser);
            }

        } else if (input == "2") {
            cout << "Enter your ID or enter E exit:- " << endl;
            User *user = nullptr;
            while (true) {
                cin >> input;
                if (input == "E" || input == "e") {
                    break;
                } else if (checkIfPositiveInteger(input) && (user = findUserByID(users, usersCount, stoi(input))) != nullptr) {
                    break;
                } else
                    cout << "Please enter a valid ID !." << endl;
            }

            if (user == nullptr) {
                continue;
            } else if (user->getUserType() == RECEPTIONIST) {
                receptionistMenu();
            } else {
                guestMenu();
            }

        } else if (input == "3") {
            break;
        } else {
            cout << "Invalid input!." << endl;
        }
    }
}


bool checkIfPositiveInteger(const string& s) {
    for (char c : s) {
        if (c < '0' || c > '9')
            return false;
    }

    return !(s == "0");
}

User *signNewUser(int reservedMonRooms, int reservedHumanRooms) {
    string input, name;
    int numOfRooms = 0, numOfNights = 0;
    bool dryClean, spaClean;
    UserType userType;
    cout << "Please choose the user type:-\n1- Receptionist\n2- Monster\n3- Human\n:-" << endl;
    while (true) {
        cin >> input;
        if (input == "1") {
            userType = RECEPTIONIST;
        } else if (input == "2") {
            userType = MONSTER;
        } else if (input == "3") {
            userType = HUMAN;
        } else {
            cout << "Please enter a valid input !." << endl;
            continue;
        }
        break;
    }
    if (userType == MONSTER && HotelProperties::totalMonRooms == reservedMonRooms
    || userType == HUMAN && HotelProperties::totalHumanRooms == reservedHumanRooms) {
        cout << "Sorry the hotel is full." << endl;
        return nullptr;
    }

    cout << "Please enter user name: " << endl;
    cin >> input;
    name = move(input);
    cout << "Please enter number of nights: " << endl;
    while (userType != RECEPTIONIST && !numOfNights) {
        cin >> input;
        if (checkIfPositiveInteger(input))
            numOfNights = stoi(input);
        else
            cout << "Please enter a valid input!." << endl;

    }

    cout << "Please enter number of rooms: " << endl;
    while (userType != RECEPTIONIST && !numOfRooms) {
        cin >> input;
        if (checkIfPositiveInteger(input)) {
            numOfRooms = stoi(input);
            if (userType == MONSTER && HotelProperties::totalMonRooms < reservedMonRooms + numOfRooms) {
                printf("There is only %d available", HotelProperties::totalMonRooms - reservedMonRooms);
            } else if (userType == HUMAN && HotelProperties::totalHumanRooms < reservedHumanRooms + numOfRooms) {
                printf("There is only %d available", HotelProperties::totalHumanRooms - reservedHumanRooms);
            }

        } else
            cout << "Please enter a valid input!." << endl;

    }

    cout << "Do you want a dry clean ?[Y/N]:" << endl;
    while (userType != RECEPTIONIST) {
        cin >> input;
        if (input == "Y" || !strcasecmp(input.c_str(), "yes")) {
            dryClean = true;
            break;
        } else if (input == "N" || !strcasecmp(input.c_str(), "no")) {
            dryClean = false;
            break;
        } else
            cout << "Please enter a valid input!." << endl;

    }

    cout << "Do you want a spa clean ?[Y/N]:" << endl;
    while (userType != RECEPTIONIST) {
        cin >> input;
        if (input == "Y" || !strcasecmp(input.c_str(), "yes")) {
            spaClean = true;
            break;
        } else if (input == "N" || !strcasecmp(input.c_str(), "no")) {
            spaClean = false;
            break;
        } else
            cout << "Please enter a valid input!." << endl;

    }

    switch (userType) {
        case RECEPTIONIST:
            return new Receptionist(name);
        case MONSTER:
            return new Monster(name, numOfNights, numOfRooms, dryClean, spaClean);
        case HUMAN:
            return new Human(name, numOfNights, numOfRooms, dryClean, spaClean);
    }

}


User **addNewUser(User **usersArr, int length, int usersCount, User *user) {
    if (usersCount == length) {
        length *= 2;
        usersArr = (User **) realloc(usersArr, sizeof (User) * length);
    }

    usersArr[usersCount] = user;
    return usersArr;
}


int main() {

    return 0;
}
