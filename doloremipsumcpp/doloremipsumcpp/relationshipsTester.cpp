
#include "elenaRows.h"
#include "elenaSeats.h"
#include<string>
#include<iostream>
#include<fstream>
void decodeSeats(int noSeats)
{
	while (noSeats < 0|| noSeats > Row::MAX_NUMBER_OF_SEATS)
	{
		cout << "No seats less than 0 ore more than 15. Please insert again no of seats:";
		cin >> noSeats;
		
	}

	
}

void decodeRows(int noRows)
{
	while (noRows < 0 || noRows > Row::MAX_ROW_IDENTIFIER)
	{
		cout << "No rows less than 0 ore more than 50. Please insert again no of rows:";
		cin >> noRows;

	}
}

void decodeTypeOfSeat(int auxType)
{
	while (auxType != 0 && auxType != 1 && auxType != 2 && auxType != 3 && auxType != 4)
	{
		cout << endl << "Your choice is not from the available set. Insert type again:";

		
		cin >> auxType;
	}


}
int main() {


	int noSeats = 0;
	int noRows = 0;
	cout << "Please insert no of seats:";
	cin >> noSeats;

	decodeSeats(noSeats);

	cout << "Please insert no of rows:";
	cin >> noRows;

	decodeRows(noRows);
	
	Seat* seats=new Seat[noSeats];

	while (true)
	{
		for (int i = 0; i < noSeats; i++)
		{
			cout << endl << "let's build seat" << " " << i + 1 << endl;
			try {	
					cout << endl << "Insert the seat number. It shall be less or equal than 15:";
					int auxSeatNumber;
					cin >> auxSeatNumber;
					seats[i].setSeatNumber(auxSeatNumber);

					cout << endl << "Insert the seat type. It shall be an integer from the set {0, 1, 2, 3, 4}";
					cout << endl << "Where";
					cout << endl << "0->STANDARD seat";
					cout << endl << "1->WHEELCHAIR seat";
					cout << endl << "2->BROKEN seat";
					cout << endl << "3->OCCUPIED seat";
					cout << endl << "4->CHOSEN seat";
					cout << endl << "Your choice is:";

					int auxType;
					cin >> auxType;
					decodeTypeOfSeat(auxType);
					switch (auxType)
					{
					case(0):
						seats[i].setType(STANDARD);
						break;
					case(1):
						seats[i].setType(WHEELCHAIR);
						break;
					case(2):
						seats[i].setType(BROKEN);
						break;
					case(3):
						seats[i].setType(OCCUPIED);
						break;
					case(4):
						seats[i].setType(CHOSEN);
						break;
					default:
						seats[i].setType(OCCUPIED);
					}


					//break;
			}
			catch (const SeatException& ex)
			{
				cout << endl << "Wrong seat number for seat";
				break;
			}
			catch (...)
			{
				cout << endl << "We have an issue!";
				break;

			}

		}
		break;
	}

	for (int i = 0; i < noSeats; i++)
	{
		cout << endl << "******Seat" << " " << i + 1;
		cout << seats[i];
	}

	Row* rows=new Row[noRows];

	rows[0].addSeats(&seats[0]);
	rows[1].addSeats(&seats[0]);

	cout << rows[0] << endl << rows[1];


	/*while (true)
	{
		for (int i = 0; i <noRows; i++)
		{
			cout << endl << "Let's create row"<<" "<<i+1;
			try
			{
				cout << endl << "Please insert the row identifier";
				int auxRowIdentifier;
				cin >> auxRowIdentifier;
				rows[i].setRowIdentifier(auxRowIdentifier);

				cout << endl << "Please insert a number of seats per row";
				int auxNoSeatsPerRow;
				cin >> auxNoSeatsPerRow;
				rows[i].setNoOfSeatsForRow(auxNoSeatsPerRow);

				cout << endl << "**insertion for seats occuring...";
				for (int j = 0; j < noSeats; j++)
				{
					rows[j].addSeats(&seats[j]);
				}

				break;
			}
			catch (const RowException& ex)
			{
				cout<<endl << "Row identifier negative or more than 50 or number of seats negative or more than 15";
				continue;
			}
			catch (...)
			{
				cout << endl << "Exception thrown at rows";
				continue;
			}
		}

		break;
	}*/

	for (int i = 0; i < noRows; i++)
	{
		cout << endl << "******Row" << " " << i + 1;
		cout << rows[i];
	}




}


	