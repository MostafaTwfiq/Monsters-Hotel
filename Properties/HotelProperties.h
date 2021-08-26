#ifndef MONSTERSHOTEL_HOTELPROPERTIES_H
#define MONSTERSHOTEL_HOTELPROPERTIES_H


class HotelProperties {

public:
    static int currTotalUsers;
    const static int totalMonRooms = 15;
    const static int totalHumanRooms = 5;

    static int getCurrTotalUsers() {
        return HotelProperties::currTotalUsers;
    }
    static void increaseTotalUsers();


};

#endif //MONSTERSHOTEL_HOTELPROPERTIES_H
