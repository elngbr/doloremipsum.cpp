
#pragma once

#include "elenaRows.h"


#include<string>
#include<iostream>
#include<fstream>
using namespace std;

enum SeatType { STANDARD, WHEELCHAIR, BROKEN, OCCUPIED, CHOSEN, STUDENT, CHILDREN, COUPLE, FLEXIBLE, VIP, PREMIUM, BEANBAG, VIRTUAL };

class Seat {
protected:

    SeatType typeOfSeat = SeatType::STANDARD;

public:

    SeatType getType() const {
        return typeOfSeat;
    }

    void setType(SeatType auxType) {
        this->typeOfSeat = auxType;
    }

    Seat(SeatType auxType) :typeOfSeat(auxType)
    {

    }
    //Seat(SeatType auxType, int auxSeatIdentifier) :typeOfSeat(auxType) {
    //    setSeatIdentifier(auxSeatIdentifier);
    //}
    //friend inline ostream& operator <<(ostream& console, const Seat& auxSeat);

    string returnSeat()
    {
        switch (this->typeOfSeat)
        {
        case(0):
            return "STDARD";
        case(1):
            return "SNEEDS";
        case(2):
            return "BROKEN";
        case(3):
            return "OCPIED";
        case(4):
            return "**YC**";
        case(5):
            return "STDENT";
        case(6):
            return "CHILDR";
        case(7):
            return "COUPLE";
        case(8):
            return "FLEXIB";
        case(9):
            return "VIP***";
        case(10):
            return "PRMIUM";
        case(11):
            return "BEANBG";
        case(12):
            return "VRTUAL";
        }

    }

};


inline ostream& operator <<(ostream& console, const Seat& auxSeat)
{
    console << endl << "This seat's type is:" << " " << " ";


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