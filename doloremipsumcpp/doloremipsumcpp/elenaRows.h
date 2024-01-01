#pragma once
#include "elenaRows.h"

#include "elenaSeats.h"
#include<string>
#include<iostream>
#include<fstream>

using namespace std;

class RowIdentifierException {
private:
    string message;
public:
    RowIdentifierException(const string& msg) : message(msg) {}

    string what()const
    {
        return message;
    }
};

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

class NullSeatException {
private:
    string message;
public:
    NullSeatException(const string& msg) : message(msg) {}

    string what()const
    {
        return message;
    }
};

class Row 
{
private:
    int rowIdentifier = 0;
    int noOfSeatsForRow = 0;
    Seat** seats = nullptr;


public:


    
    static const int MAX_NUMBER_OF_SEATS = 15;
    static const int MAX_ROW_IDENTIFIER = 50;

    int getRowIdentifier() const {
        return rowIdentifier;
    }

    void setRowIdentifier(int auxIdentifier) {
        if (auxIdentifier < 0 || auxIdentifier>MAX_ROW_IDENTIFIER) {
            throw RowIdentifierException("Row identifier cannot be negative or more than 50");
        }
        

        rowIdentifier = auxIdentifier;
    }

    int getNoOfSeatsForRow() const {
        return noOfSeatsForRow;
    }

    void setNoOfSeatsForRow(int auxNoOfSeats) {
        if (auxNoOfSeats <= 0 || auxNoOfSeats > MAX_NUMBER_OF_SEATS) {
            throw NoOfSeatsForRowException("Invalid number of seats for the row");
        }
       
        noOfSeatsForRow = auxNoOfSeats;
    }

    Seat** getSeats() const {
        return seats;
    }



    //void setSeats(Seat** newSeats, int numberOfSeats)
    //{
    //    if (numberOfSeats <= 0 || numberOfSeats > MAX_NUMBER_OF_SEATS) {
    //        throw NoOfSeatsForRowException("Invalid number of seats");
    //    }
    //    else throw NoOfSeatsForRowException("Something wrong with the number of seats per row");


    //    for (int i = 0; i < numberOfSeats; ++i) {
    //        if (newSeats[i] == nullptr) {
    //            throw NullSeatException("Null seat encountered");
    //        }
    //    }

    //    seats = newSeats;
    //}

    void addSeats(Seat auxSeat)
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

    Row(int auxRowIdentifier, Seat singleSeat)
        : rowIdentifier(auxRowIdentifier), noOfSeatsForRow(1) {
        initializeSeats();
        seats[0] = &singleSeat;
    }

    Row( Seat singleSeat)
        : noOfSeatsForRow(1) {
        initializeSeats();
        seats[0] = &singleSeat;
    }

    Row(int auxRowIdentifier, int auxNoOfSeatsForRow, Seat seatArray)
        : rowIdentifier(auxRowIdentifier), noOfSeatsForRow(auxNoOfSeatsForRow) {
        initializeSeats();
        addSeats(seatArray);
    }

    void initializeSeats() {
        seats = new Seat * [noOfSeatsForRow];
        for (int i = 0; i < noOfSeatsForRow; ++i) {
            seats[i] = nullptr; 
        }
    }

    Row()
    {

    }


    /*void addSeats(Seat& auxSeat, int seatIndex) {
        if (seatIndex >= 0 && seatIndex < noOfSeatsForRow) {
            seats[seatIndex] = &auxSeat;
        }
    }*/
    /*Row()
    {
        seats = nullptr;
    }*/

   

    /*~Row() {
        for (int i = 0; i < this->noOfSeatsForRow; ++i)
        {
            delete seats[i];
        }
        delete[] seats;
    }*/


    
    friend  ostream& operator <<(ostream& console, const Row& auxRow);
};

ostream& operator <<(ostream& console, const Row& auxRow)
{
    console << "******************************************************************************************************";

    console << endl << "This row's identifier is" << " " << auxRow.getRowIdentifier();
    console << endl << "This row's number of seats is" << " " << auxRow.getNoOfSeatsForRow();


    if (auxRow.getSeats() != nullptr)
    {
        console << endl << "This row has the following seats:" << endl;
        for (int i = 0; i < auxRow.noOfSeatsForRow; i++)
        {
            console << endl << "This seat has identifier" << " " << i + 1;
            console << *(auxRow.seats[i]) << endl;
        }
      
    }

    console << "******************************************************************************************************";

    return  console;
}