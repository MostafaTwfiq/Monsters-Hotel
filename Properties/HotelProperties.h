#ifndef MONSTERSHOTEL_HOTELPROPERTIES_H
#define MONSTERSHOTEL_HOTELPROPERTIES_H


class HotelProperties {

private:
    static int currTotalUsers;
    static int totalMonRooms;
    static int totalHumanRooms;

public:
    void setTotalUsers(int totUsers);
    void setTotalMonRooms(int monRooms);
    void setTotalHumanRooms(int humanRooms);
    int getTotalUsersNum();
    int getTotalMonRooms();
    int getTotalHumanRooms();
};


#endif //MONSTERSHOTEL_HOTELPROPERTIES_H
