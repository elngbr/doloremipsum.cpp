#pragma once
#include "elenaSeats.h"
#include<string>
#include<iostream>
#include<fstream>


class RowException : public exception {
public:
    RowException(const string& msg) : exception(msg.c_str()) {}
};

class Row {
private:
    int rowIdentifier = 0;
    int noOfSeatsForRow = 0;
    Seat** seats = nullptr;


public:

    static const int MAX_NUMBER_OF_SEATS = 10;

    int getRowIdentifier() const {
        return rowIdentifier;
    }

    void setRowIdentifier(int auxIdentifier) {
        if (auxIdentifier < 0) {
            throw RowException("Row identifier cannot be negative");
        }
        rowIdentifier = auxIdentifier;
    }

    int getNoOfSeatsForRow() const {
        return noOfSeatsForRow;
    }

    void setNoOfSeatsForRow(int auxNoOfSeats) {
        if (auxNoOfSeats <= 0 || auxNoOfSeats > MAX_NUMBER_OF_SEATS) {
            throw RowException("Invalid number of seats for the row");
        }
        noOfSeatsForRow = auxNoOfSeats;
    }

    Seat** getSeats() const {
        return seats;
    }

    void setSeats(Seat** newSeats, int numberOfSeats) {
        if (numberOfSeats <= 0 || numberOfSeats > MAX_NUMBER_OF_SEATS) {
            throw RowException("Invalid number of seats");
        }

        for (int i = 0; i < numberOfSeats; ++i) {
            if (newSeats[i] == nullptr) {
                throw RowException("Null seat encountered");
            }
        }

        seats = newSeats;
    }

    Row(int auxRowIdentifier, int auxNoOfSeatsForRow, Seat** initialSeats, int numberOfSeats)
        : rowIdentifier(auxRowIdentifier), noOfSeatsForRow(auxNoOfSeatsForRow) {
        setSeats(initialSeats, numberOfSeats);
    }

    ~Row() {
        delete[] seats;
    }
};