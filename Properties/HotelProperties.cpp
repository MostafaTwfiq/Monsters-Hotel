#include "HotelProperties.h"

void HotelProperties::setTotalUsers(int totUsers) {
    HotelProperties::currTotalUsers = totUsers;
}

void HotelProperties::setTotalMonRooms(int monRooms) {
    HotelProperties::totalMonRooms = monRooms;
}

void HotelProperties::setTotalHumanRooms(int humanRooms) {
    HotelProperties::totalHumanRooms = humanRooms;
}

int HotelProperties::getTotalUsersNum() {
    return HotelProperties::currTotalUsers;
}

int HotelProperties::getTotalMonRooms() {
    return HotelProperties::totalMonRooms;
}

int HotelProperties::getTotalHumanRooms() {
    return HotelProperties::totalHumanRooms;
}
