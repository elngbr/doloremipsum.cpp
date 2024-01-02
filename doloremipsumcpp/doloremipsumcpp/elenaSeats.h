
#pragma once

#include "elenaRows.h"


#include<string>
#include<iostream>
#include<fstream>
using namespace std;



enum SeatType { STANDARD, WHEELCHAIR, BROKEN, OCCUPIED, CHOSEN, STUDENT, CHILDREN, COUPLE, FLEXIBLE, VIP, PREMIUM, BEANBAG, VIRTUAL };

class Seat {
private:

    SeatType type = SeatType::STANDARD;

public:

    SeatType getType() const {
        return type;
    }

    void setType(SeatType auxType) {
        this->type = auxType;
    }

    Seat(SeatType auxType) :type(auxType)
    {

    }

    friend inline ostream& operator <<(ostream& console, const Seat& auxSeat);

};


inline ostream& operator <<(ostream& console, const Seat& auxSeat)
{

    console << endl << "This seat's type is:" << " ";
    /*enum SeatType { STANDARD, WHEELCHAIR, BROKEN, OCCUPIED, CHOSEN };*/
    //enum SeatType { STANDARD, WHEELCHAIR, BROKEN, OCCUPIED, CHOSEN, STUDENT, CHILDREN, COUPLE, FLEXIBLE, VIP, PREMIUM };


    switch (auxSeat.getType())
    {
    case(0):
        console << "standard.";
        break;
    case(1):
        console << "for people with disabilities.";
        break;
    case(2):
        console << "broken. It cannot be reserved.";
        break;
    case(3):
        console << "occupied. Please choose another seat.";
        break;
    case(4):
        console << "the seat you have already chosen. Please go to the cart.";
        break;
    case(5):
        console << "Student";
        break;
    case(6):
        console << "this seat was specially designed for children.";
        break;
    case(7):
        console << "this seat was specially designed for couples. It has larger space";
        break;
    case(8):
        console << "this seat was specially designed to be easily folded or stacked";
        break;
    case(9):
        console << "VIP seat";
        break;
    case(10):
        console << "PREMIUM seat";
        break;
    case(11):
        console << "BEAN-BAG seat.very comfortable";
        break;
    case(12):
        console << "VIRTUAL seat. It means the zone with such a seat does not have seats, it has a capacity of persons.";
        break;
    default:
        console << "This type of seat has been added subsequently. Plase redefine the switch function";
    }



    return console;
}