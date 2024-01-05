
#pragma once

#include "elenaRows.h"


#include<string>
#include<iostream>
#include<fstream>
using namespace std;

//class WrongSeatIdentifier {
//private:
//    string message;
//public:
//    WrongSeatIdentifier(const string& msg) : message(msg) {}
//
//    string what()const
//    {
//        return message;
//    }
//};

enum SeatType { STANDARD, WHEELCHAIR, BROKEN, OCCUPIED, CHOSEN, STUDENT, CHILDREN, COUPLE, FLEXIBLE, VIP, PREMIUM, BEANBAG, VIRTUAL };

class Seat {
protected:

    SeatType typeOfSeat = SeatType::STANDARD;
    int seatIndentifier = 0;

public:

    int getSeatIdentifier() const
    {
        return this->seatIndentifier;
    }

    /*void setSeatIdentifier(int auxSeatIdentifier)
    {
        if (auxSeatIdentifier < 0)
        {
            throw WrongSeatIdentifier("A seat identifier cannot be less than 0!");
            this->seatIndentifier = auxSeatIdentifier;
        }
    }*/

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
            return "S";
        case(1):
            return "D";
        case(2):
            return "B";
        case(3):
            return "O";
        case(4):
            return "Y";
        case(5):
            return "STUD";
        case(6):
            return "KID";
        case(7):
            return "LOVE";
        case(8):
            return "FLEX";
        case(9):
            return "V";
        case(10):
            return "P";
        case(11):
            return "BB";
        case(12):
            return "VIR";
        }

    }

};


inline ostream& operator <<(ostream& console, const Seat& auxSeat)
{
    //console << endl << "This seats; identifier is:" << auxSeat.getSeatIdentifier();
    console << endl << "This seat's type is:" << " " << " ";
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