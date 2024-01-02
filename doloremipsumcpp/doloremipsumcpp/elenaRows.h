#pragma once
#include "elenaSeats.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;


class NoOfSeatsForRowException {
private:
    string message;
public:
    NoOfSeatsForRowException(const string& msg) : message(msg) {}

    string what()const
    {
        return message;
    }
};










class Row {
private:


    int noOfSeatsForRow = 0;
    Seat** seats = nullptr;


public:
    Row()
    {

    }
    static const int MAX_NUMBER_OF_SEATS = 15;

    int getNoOfSeatsForRow() const {
        return noOfSeatsForRow;
    }

    void setNoOfSeatsForRow(int auxNoOfSeats)
    {
        if (auxNoOfSeats <= 0 || auxNoOfSeats > MAX_NUMBER_OF_SEATS) {
            throw NoOfSeatsForRowException("Invalid number of seats for the row");
        }

        this->noOfSeatsForRow = auxNoOfSeats;
    }

    void addSeats(Seat auxSeat)
    {
        if (this->noOfSeatsForRow <= MAX_NUMBER_OF_SEATS)
        {
            Seat** newSeats = new Seat * [this->noOfSeatsForRow + 1];
            for (int i = 0; i < this->noOfSeatsForRow; i++)
            {
                newSeats[i] = this->seats[i];
            }

            newSeats[this->noOfSeatsForRow] = new Seat(auxSeat);

            delete[] this->seats;
            this->seats = newSeats;
            this->noOfSeatsForRow++;
        }




    }


    friend inline ostream& operator <<(ostream& console, const Row& auxRow);
};

inline ostream& operator <<(ostream& console, const Row& auxRow)
{
    console << "******************************************************************************************************";
    console << endl << "This row's number of seats is" << " " << auxRow.getNoOfSeatsForRow();




    console << endl << "This row has the following seats:" << endl;
    for (int i = 0; i < auxRow.getNoOfSeatsForRow(); i++)
    {
        console << endl << "The identifier of this seat is" << " " << i + 1;
        console << *(auxRow.seats[i]) << endl;
    }



    console << "******************************************************************************************************";

    return  console;
}