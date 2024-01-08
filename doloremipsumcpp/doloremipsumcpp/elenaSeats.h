
#pragma once

#include "elenaRows.h"


#include<string>
#include<iostream>
#include<fstream>
using namespace std;

enum SeatType { STANDARD = 50, WHEELCHAIR = 45, BROKEN = -2, OCCUPIED, CHOSEN = 0, STUDENT = 35, CHILDREN = 44, COUPLE = 75, FLEXIBLE = 70, VIP = 90, PREMIUM = 85, BEANBAG = 87, VIRTUAL = 48 };

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
        case(STANDARD):
            return "STDARD";
        case(WHEELCHAIR):
            return "SNEEDS";
        case(BROKEN):
            return "BROKEN";
        case(OCCUPIED):
            return "OCPIED";
        case(CHOSEN):
            return "*YOURS*";
        case(STUDENT):
            return "STDENT";
        case(CHILDREN):
            return "CHILDR";
        case(COUPLE):
            return "COUPLE";
        case(FLEXIBLE):
            return "FLEXIB";
        case(VIP):
            return "V.I.P.";
        case(PREMIUM):
            return "PRMIUM";
        case(BEANBAG):
            return "BEANBG";
        case(VIRTUAL):
            return "VRTUAL";
        }

    }

};


inline ostream& operator <<(ostream& console, const Seat& auxSeat)
{
    console << endl << "This seat's price is" << " " << auxSeat.getType();
    console << endl << "This seat's type is:" << " " << " ";



    switch (auxSeat.getType())
    {
    case(STANDARD):
        console << "standard.";
        break;
    case(WHEELCHAIR):
        console << "for people with disabilities.";
        break;
    case(BROKEN):
        console << "broken. It cannot be reserved.";
        break;
    case(OCCUPIED):
        console << "occupied. Please choose another seat.";
        break;
    case(CHOSEN):
        console << "the seat you have already chosen. Please go to the cart.";
        break;
    case(STUDENT):
        console << "Student";
        break;
    case(CHILDREN):
        console << "this seat was specially designed for children.";
        break;
    case(COUPLE):
        console << "this seat was specially designed for couples. It has larger space";
        break;
    case(FLEXIBLE):
        console << "this seat was specially designed to be easily folded or stacked";
        break;
    case(VIP):
        console << "VIP seat";
        break;
    case(PREMIUM):
        console << "PREMIUM seat";
        break;
    case(BEANBAG):
        console << "BEAN-BAG seat.very comfortable";
        break;
    case(VIRTUAL):
        console << "VIRTUAL seat. It means the zone with such a seat does not have seats, it has a capacity of persons.";
        break;
    default:
        console << "This type of seat has been added subsequently. Plase redefine the switch function";
    }

    console << endl;

    return console;
}