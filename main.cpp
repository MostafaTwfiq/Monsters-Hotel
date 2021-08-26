#include <iostream>
#include <stdio.h>
#include <string.h>

#include "Properties/HotelProperties.h"
#include "Users/User.h"
#include "Users/Guest.h"
#include "Users/Monster.h"
#include "Users/Human.h"

using namespace std;

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

        } else if (input == "2") {
            cout << "Enter your ID:- " << endl;
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

    return true;
}

User *signNewUser() {
    string input, name;
    int numOfRooms = 0, numOfNights = 0;
    bool dryClean, spaClean;
    cout << "Please enter user name: " << endl;
    cin >> input;
    name = move(input);
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
        if (checkIfPositiveInteger(input))
            numOfRooms = stoi(input);
        else
            cout << "Please enter a valid input!." << endl;

    }

    cout << "Do you want a dry clean ?[Y/N]:" << endl;
    while (true) {
        cin >> input;
        if (input == "Y" || strcasecmp(input.c_str(), "yes")) {
            dryClean = true;
            break;
        } else if (input == "N" || strcasecmp(input.c_str(), "no")) {
            dryClean = false;
            break;
        } else
            cout << "Please enter a valid input!." << endl;

    }

    cout << "Do you want a spa clean ?[Y/N]:" << endl;
    while (true) {
        cin >> input;
        if (input == "Y" || strcasecmp(input.c_str(), "yes")) {
            spaClean = true;
            break;
        } else if (input == "N" || strcasecmp(input.c_str(), "no")) {
            spaClean = false;
            break;
        } else
            cout << "Please enter a valid input!." << endl;

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
    Human *human = new Human("Mostafa", 3, 2, true, false);
    cout << human->getName() << endl;
    //Human human("Mostafa", 3, 2, true, false);
    //cout << human.calculateTotalCost() << endl;
    printMenu();
    return 0;
}
