#include "elenaSeats.h"
#include "elenaRows.h"
#include<string>
#include<iostream>
#include<fstream>

int main()
{
	Row row1(2, 5);

	Seat seat(1, OCCUPIED, row1);

	cout << "Seat number: " << seat.getSeatNumber() << endl;
	cout << "Seat type: " << seat.getType() << endl;
	cout << "Row identifier: : " << seat.getRowIdentifier() << endl;
	
}
