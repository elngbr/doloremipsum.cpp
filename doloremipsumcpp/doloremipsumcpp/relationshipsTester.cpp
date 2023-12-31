//#include "elenaSeats.h"
//#include "elenaRows.h"
//#include<string>
//#include<iostream>
//#include<fstream>
//
//int main()
//{
//	Row row1(2, 5);
//
//	Seat seat(1, OCCUPIED, row1);
//
//	cout << "Seat number: " << seat.getSeatNumber() << endl;
//	cout << "Seat type: " << seat.getType() << endl;
//	cout << "Row identifier: : " << seat.getRowIdentifier() << endl;
//	
//}
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

enum seatType { STANDARD, WHEELCHAIR, BROKEN, OCCUPIED, CHOSEN };

class Row {
private:
    int rowNumber = 0;
    int seatsNumber = 0;
    int* seats = nullptr;

    // Private default constructor
    Row() {}

public:
    int const static MAX_NUMBER_OF_SEATS = 15;

    int getNoOfSeats() const {
        return this->seatsNumber;
    }

    void setNoOfSeats(int auxSeatsNo) {
        this->seatsNumber = auxSeatsNo;
    }

    // Other methods...

    // Destructor to free dynamically allocated memory
    ~Row() {
        delete[] seats;
    }

    // Public constructor
    Row(int rowNumber, int seatsNumber) : rowNumber(rowNumber), seatsNumber(seatsNumber) {
        seats = new int[seatsNumber];
        // Initialize other members as needed...
    }
};

class Seat {
private:
    int seatNumber = 0;
    seatType type = seatType::STANDARD;

    // Using a reference to represent the association with a Row
    const Row& rowNumber;

    // Private default constructor
    Seat() : rowNumber(*new Row(0, 0)) {}

public:
    int getSeatNumber() const {
        return this->seatNumber;
    }

    void setSeatNumber(int auxNo) {
        this->seatNumber = auxNo;
    }

    int getType() const {
        return this->type;
    }

    void setType(seatType auxType) {
        this->type = auxType;
    }

    // Accessor to get the associated row number
    int getRowNumber() const {
        return rowNumber.getNoOfSeats();
    }

    // Constructor with Row as a parameter
    Seat(int auxSeatNo, seatType auxType, const Row& auxRow) : rowNumber(auxRow) {
        this->setSeatNumber(auxSeatNo);
        this->setType(auxType);
    }
};

int main() {
    // Example usage
    Row row(1, 10);

    Seat seat(1, STANDARD, row);

    cout << "Seat Number: " << seat.getSeatNumber() << endl;
    cout << "Seat Type: " << seat.getType() << endl;
    cout << "Associated Row Number: " << seat.getRowNumber() << endl;

    return 0;
}
