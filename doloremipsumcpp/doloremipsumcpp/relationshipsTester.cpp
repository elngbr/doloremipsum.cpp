
#include "elenaRows.h"
#include "elenaSeats.h"
#include<string>
#include<iostream>
#include<fstream>

int main() {
	Seat seat1;

	while (true)
	{
		try {
			cout << endl << "Insert the seat number. It shall be less or equal than 15:";
			int auxSeatNumber;
			cin >> auxSeatNumber;
			seat1.setSeatNumber(auxSeatNumber);

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
			switch (auxType)
			{
			case(0):
				seat1.setType(STANDARD);
				break;
			case(1):
				seat1.setType(WHEELCHAIR);
				break;
			case(2):
				seat1.setType(BROKEN);
				break;
			case(3):
				seat1.setType(OCCUPIED);
				break;
			case(4):
				seat1.setType(CHOSEN);
				break;
			default:
				seat1.setType(OCCUPIED);
			}


			break;

		}
		catch (const SeatException& ex)
		{
			cout << endl << "Wrong seat number";
		}
		catch (...)
		{
			cout << endl << "We have an issue!";

		}


	}

	cout << seat1;
	
	Seat* seats=new Seat[Seat::MAX_IDENTIFIER_OF_SEAT];

	while (true)
	{
		for (int i = 0; i < Seat::MAX_IDENTIFIER_OF_SEAT; i++)
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
	}



}


	