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
void addNewUser(User *user);
bool checkIfPositiveInteger(const string& s);
User *deleteUser(int ID);

// These if the global variables, any way it's not a good practice but it's not the main purpose in this project.
int HotelProperties::IDCounter = 1;
int length = 5;
int usersCount = 0;
User **users = (User **) malloc(sizeof (User) * length);


/**
 * This function will count the number if reserved monsters rooms.
 * @return the number of reserved monsters rooms
 */
int countMonstersResRooms() {
    int counter = 0;
    for (int i = 0; i < usersCount; i++) {
        if (users[i]->getUserType() == MONSTER)
            counter += ((Monster *) users[i])->getNumOfRooms();

    }

    return counter;
}

/**
 * This function will return the number of reserved humans rooms.
 * @return the number of reserved humans rooms.
 */
int countHumansResRooms() {
    int counter = 0;
    for (int i = 0; i < usersCount; i++) {
        if (users[i]->getUserType() == HUMAN)
            counter += ((Human *) users[i])->getNumOfRooms();

    }

    return counter;
}

/**
 * This function will return the user with the passed ID if found, other wise it will return null
 * @param ID the id of the user
 * @return it will return the user pointer if found, other wise it will return null
 */
User *findUserByID(int ID) {
    for (int i = 0; i < usersCount; i++) {
        if (users[i]->getID() == ID)
            return users[i];

    }

    return nullptr;
}

/**
 * This function will print and interact with the receptionist user interface.
 */
void receptionistMenu() {
    string input;
    while (true) {
        cout << "Please choose from the following:-\n1- View number of available and reserved rooms.\n2- List guests.\n3- Logout." << endl;
        cin >> input;
        if (input == "1") {
            int reservedMonRooms = countMonstersResRooms();
            int reservedHumansRooms = countHumansResRooms();
            printf("Total available rooms: %d\n",
                   HotelProperties::totalMonRooms - reservedMonRooms + HotelProperties::totalHumanRooms -
                   reservedHumansRooms);
            printf("Total available monsters rooms: %d\n", HotelProperties::totalMonRooms - reservedMonRooms);
            printf("Total available human rooms: %d\n", HotelProperties::totalHumanRooms - reservedHumansRooms);
            printf("Total reserved monsters rooms: %d\n", reservedMonRooms);
            printf("Total reserved human rooms: %d\n", reservedHumansRooms);
        } else if (input == "2") {
            for (int i = 0; i < usersCount; i++) {
                if (users[i]->getUserType() != RECEPTIONIST) {
                    printf("User ID %d:-\n", users[i]->getID());
                    cout << ((Guest *) users[i])->toString() << endl;
                    cout << "\n" << endl;
                }
            }
        } else if (input == "3") {
            return;
        } else {
            cout << "Invalid input !." << endl;
        }
    }
}

/**
 * This function will print and interact with the guests interface.
 * @param guest
 */
void guestMenu(Guest *guest) {
    string input;
    while (true) {
        cout << "Please choose from the following:-\n1- Extend reservation.\n2- Cancel reservation.\n3- Exit.\n:-" << endl;
        cin >> input;
        if (input == "1") {
             int extendedNights = 0;
             cout << "Please enter the number of extra nights:- " << endl;
            while (!extendedNights) {
                cin >> input;
                if (checkIfPositiveInteger(input))
                    extendedNights = stoi(input);
                else
                    cout << "Please enter a valid input!." << endl;
            }
            printf("Extra cost will be: %d\n", guest->calExtraNightsCost(extendedNights));
            guest->extendReservation(extendedNights);

        } else if (input == "2") {
            deleteUser(guest->getID());
            usersCount -= 1;
            return;
        } else if (input == "3") {
            return;
        } else {
            cout << "Invalid input !." << endl;
        }
    }

}


/**
 * This function will print the main menu and interact with the user
 */
void printMenu() {
    string input;

    while (true) {
        cout << "Please choose from the following:\n" << endl;
        cout << "1- New customer.\n2- Old customer or receptionist\n3- End program\n:- " << endl;
        cin >> input;

        if (input == "1") {
            User *newUser = signNewUser(countMonstersResRooms(), countHumansResRooms());
            if (newUser != nullptr) {
                addNewUser(newUser);
                cout << "Your ID: " + to_string(newUser->getID()) << endl;
            }

        } else if (input == "2") {
            cout << "Enter your ID or enter E exit:- " << endl;
            User *user = nullptr;
            while (true) {
                cin >> input;
                if (input == "E" || input == "e") {
                    continue;
                } else if (checkIfPositiveInteger(input)) {
                    int id = stoi(input);
                    user = findUserByID(id);
                }

                if (user != nullptr) {
                    break;
                } else
                    cout << "Please enter a valid ID !." << endl;

            }

            if (user->getUserType() == RECEPTIONIST) {
                receptionistMenu();
            } else {
                guestMenu((Guest *) user);
            }

        } else if (input == "3") {
            break;
        } else {
            cout << "Invalid input!." << endl;
        }
    }
}


/**
 * This function will check if the passed string is an positive non-zero integer
 * @param s the string
 * @return it will return true if the passed integer is an integer larger than zero
 */
bool checkIfPositiveInteger(const string& s) {
    for (char c : s) {
        if (c < '0' || c > '9')
            return false;
    }

    return !(s == "0");
}


/**
 * This function will take user data as input and it will create a new instance
 *
 * <<This function should been splitted into multiple function for more readable and maintainable code>>
 * @param reservedMonRooms the number of reserved monsters rooms
 * @param reservedHumanRooms the number of reserved humans rooms
 * @return it will return the new user instance
 */
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

    if (userType == RECEPTIONIST)
        return new Receptionist(name);

    cout << "Please enter number of nights: " << endl;
    while (!numOfNights) {
        cin >> input;
        if (checkIfPositiveInteger(input))
            numOfNights = stoi(input);
        else
            cout << "Please enter a valid input!." << endl;

    }

    cout << "Please enter number of rooms: " << endl;
    while (!numOfRooms) {
        cin >> input;
        if (checkIfPositiveInteger(input)) {
            numOfRooms = stoi(input);
            if (userType == MONSTER && HotelProperties::totalMonRooms < reservedMonRooms + numOfRooms) {
                printf("There is only %d available\n", HotelProperties::totalMonRooms - reservedMonRooms);
                numOfRooms = 0;
            } else if (userType == HUMAN && HotelProperties::totalHumanRooms < reservedHumanRooms + numOfRooms) {
                printf("There is only %d available\n", HotelProperties::totalHumanRooms - reservedHumanRooms);
                numOfRooms = 0;
            }

        } else
            cout << "Please enter a valid input!." << endl;

    }

    cout << "Do you want a dry clean ?[Y/N]:" << endl;
    while (true) {
        cin >> input;
        if (input == "Y" || input == "y" || !strcasecmp(input.c_str(), "yes")) {
            dryClean = true;
            break;
        } else if (input == "N" || input == "n" || !strcasecmp(input.c_str(), "no")) {
            dryClean = false;
            break;
        } else
            cout << "Please enter a valid input!." << endl;

    }

    cout << "Do you want a spa clean ?[Y/N]:" << endl;
    while (true) {
        cin >> input;
        if (input == "Y" || input == "y" || !strcasecmp(input.c_str(), "yes")) {
            spaClean = true;
            break;
        } else if (input == "N" || input == "n" || !strcasecmp(input.c_str(), "no")) {
            spaClean = false;
            break;
        } else
            cout << "Please enter a valid input!." << endl;

    }

    return (userType == MONSTER ? (User *) new Monster(name, numOfNights, numOfRooms, dryClean, spaClean)
    : (User *) new Human(name, numOfNights, numOfRooms, dryClean, spaClean));

}


/**
 * This function will add a new user into the users array
 * @param user the new user to be added
 */
void addNewUser(User *user) {
    if (usersCount == length) {
        length *= 2;
        users = (User **) realloc(users, sizeof (User) * length);
    }

    users[usersCount++] = user;
}

/**
 * This function will delete the user with the passed id from users array if found
 * @param ID the user id
 * @return it will return the deleted user if found, other wise it will return null;
 */
User *deleteUser(int ID) {
    User *deletedUser = nullptr;
    for (int i = 0; i < usersCount; i++) {
        if (users[i]->getUserType() == ID) {
            deletedUser = users[i];
            for (int j = i; j < length - 1; j++)
                users[j] = users[j + 1];
        }
    }

    return deletedUser;
}


int main() {
    cout << "Welcome to the hotel !\n\n" << endl;
    cout << "**Please note that all the inputs must not contain any spaces because i used cin function**\n\n" << endl;

    printMenu();
    return 0;
}
