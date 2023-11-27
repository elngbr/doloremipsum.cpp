


#pragma once

#include <iostream>
#include <string>
using namespace std;
enum typeOfPlace { STADIUM, CONCERT_HALL, OPERA_HOUSE, EVENTS_HALL, SPORT_HALL, CINEMA_HALL, SQUARE };


class Util {
public:

	static char* copyString(const char* string)
	{
		if (string == nullptr)
		{
			return nullptr;
		}
		char* copy = new char[strlen(string) + 1];
		strcpy_s(copy, strlen(string) + 1, string);
		return copy;
	}

};

class EventPlace {
private:
	typeOfPlace name = typeOfPlace::CONCERT_HALL;
	int noRows = 0;
	int noZones = 0;
	//typeOfTicket;
	int noSeatsPerRow = 0;
	int* stateOfSeats = nullptr;
	bool istheEventaProtest = false;


public:
	int static const MAX_SEATS_ALLOWED = 1000;
	int static const MIN_ZONES = 1;
	int static const MIN_ROWS_PER_ZONE = 5;
	int static const MIN_SEATS_PER_ROW = 10;

	int* getStateOfSeats()
	{
		int* copy = new int[this->noRows * this->noSeatsPerRow];
		for (int i = 0; i < this->noRows * this->noSeatsPerRow; i++)
		{
			copy[i] = stateOfSeats[i];

		}

		return copy;
	}

	void setStateOfSeats(int* auxState, int auxRows, int auxSeatsPerRow)
	{
		if (auxState == nullptr || auxRows == NULL || auxRows < MIN_ZONES * MIN_ROWS_PER_ZONE || auxSeatsPerRow < MIN_SEATS_PER_ROW)
		{
			throw exception("Wrong Value!");
		}

		if (this->stateOfSeats != nullptr)
		{
			delete[]this->stateOfSeats;
		}

		this->stateOfSeats = new int[auxRows * auxSeatsPerRow];
		memcpy(this->stateOfSeats, auxState, sizeof(int) * auxRows * auxSeatsPerRow);  ///SA NU UITI DE SIZE OF
		this->noRows = auxRows;
		this->setNoOfSeatsPerRows(auxSeatsPerRow);


	}

	typeOfPlace getName()
	{
		return this->name;
	}

	void setName(typeOfPlace auxName)
	{
		if (auxName < typeOfPlace::STADIUM || auxName>typeOfPlace::SQUARE)
		{
			throw exception("Wrong input!");
		}

		this->name = auxName;
	}


	int getNumberOfRows()   ///if I create a setter for this one I risk to have someone modifying it and adding a number of rows which is less than my actual number
	{
		return this->noRows;
	}

	void setNumberOfRows(int auxNoRows)
	{
		if (auxNoRows < EventPlace::MIN_ROWS_PER_ZONE * MIN_ZONES)
		{
			throw exception("Wrong val!");
		}

		this->noRows = auxNoRows;
	}

	int getNoOfSeatsPerRows()   ///if I create a setter for this one I risk to have someone modifying it and adding a number of rows which is less than my actual number
	{
		return this->noSeatsPerRow;
	}


	void setNoOfSeatsPerRows(int auxNoSeats)
	{
		if (auxNoSeats < EventPlace::MIN_SEATS_PER_ROW)
		{
			throw exception("Wrong val!");
		}

		this->noSeatsPerRow = auxNoSeats;
	}

	int getNumberOfZones()
	{
		return this->noZones;
	}

	void setNumberofZones(int auxNumber)
	{
		if (auxNumber < EventPlace::MIN_ZONES)
		{
			throw exception("You can't have no zone!");
		}

		this->noZones = auxNumber;
	}



	EventPlace()
	{


	}

	EventPlace(int auxNoRows, int auxNoSeatsPerRow, int auxNoZones, typeOfPlace auxName, int* stateOfSeats)
	{

		this->setNumberofZones(auxNoZones);
		this->setName(auxName);
		this->setNoOfSeatsPerRows(auxNoSeatsPerRow);
		this->setNumberOfRows(auxNoRows);

	}

	EventPlace(typeOfPlace auxName)
	{
		this->setName(auxName);
	}

	~EventPlace()
	{
		delete[]this->stateOfSeats;
	}

	EventPlace(const EventPlace& place)///I MADE IT CONST BECAUSE I FEAR MYSELF:)
	{
		this->noRows = place.noRows;
		this->noSeatsPerRow = place.noSeatsPerRow;
		this->noZones = place.noZones;



	}
	///OVERLOADING THE OPERATOR FOR POSTFIX INCREMENTATION
	EventPlace operator++(int)
	{
		EventPlace copy = *this;
		this->noZones += 1;
		return copy;
	}


	//overloading the prefix operator

	EventPlace operator++()///no int in here
	{
		this->noZones++;
		return *this;
	}



	///overloading the indexing operator so that I can only pass the number of rows from an EVENTPLACE

	explicit operator int()
	{
		return this->noRows;
	}

	///overloading the negation operator for EVENT PLACES

	bool operator!()
	{
		if (this->name != 3) ////AND HERE WE CAN CLEARLY SEE WHY WE LOVE ENUMS INSTREAD OF ENUM CLASSES!!!!!
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator<=(EventPlace somePlace)
	{
		if (this->noZones <= somePlace.noZones)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	bool operator==(EventPlace& auxPlace)
	{
		if (this->name == auxPlace.name && this->noRows * this->noSeatsPerRow == auxPlace.noRows * auxPlace.noSeatsPerRow)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	///overloading the operator <= for noZones

	//bool areThereStillPlaces(int auxStateOfSeats, int auxNoRows, int auxSeatsPerRow)
	//{
	//	int i, j;

		//for(i=0; i<auxNoRows; i++)
		//	for(j=0; j<auxSeatsPerRow; j++)
		//		if (auxStateOfSeats[i][j])
		//		{

		//		}
	//}


	//GENERIC METHODS

	typeOfPlace changeNameToSquare()
	{
		this->name = SQUARE;
		return this->name;


	}

	bool isProtest()
	{
		if (this->name == SQUARE)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	EventPlace operator=(const EventPlace& auxLocation)
	{
		if (&auxLocation == this)
		{
			return *this;
		}
		delete[] this->stateOfSeats;
		//this->stateOfSeats = auxLocation.stateOfSeats;
		this->setName(auxLocation.name);
		this->setNoOfSeatsPerRows(auxLocation.noSeatsPerRow);
		this->setNumberofZones(auxLocation.noZones);
		this->setNumberOfRows(auxLocation.noRows);

		return *this;
	}


	friend void operator<<(ostream& console, const EventPlace& place);
	friend istream& operator>>(istream& read, EventPlace& event);
};

void operator<<(ostream& console, const EventPlace& place)
{
	console << endl << "No of rows:" << place.noRows;
	console << endl << "No of seats per row:" << place.noSeatsPerRow;
	console << endl << "No of zones:" << place.noZones;

	console << endl << "Oficially, there has been allocated" << " " << place.noRows * place.noSeatsPerRow << " " << "seats to this event, which will be devided in "
		<< place.noZones << " " << "zones.";
	//console << endl << "The place of the event is called" << " " << place.name;
	int noOfOccupiedSeats = 0;
	int noOfFreeSeats = 0;



	///check this error!!!!!
	///for (int i = 0; i < place.noRows * place.noSeatsPerRow; i++) {
		//if (place.stateOfSeats[i] == 0) {
		//	noOfFreeSeats++;
		//}
		//else if (place.stateOfSeats[i] == 1) {
		//	noOfOccupiedSeats++;
		//}
		////else {
			//console << endl << "Wrong value in stateOfSeats at index " << i << ": " << place.stateOfSeats[i];
		//}
	//}


	console << endl << "The evet occures at the" << " ";
	//console << std::endl << "Type of Place: ";
	switch (place.name) {
	case STADIUM:
		console << "Stadium";
		break;
	case CONCERT_HALL:
		console << "Concert Hall";
		break;
	case OPERA_HOUSE:
		console << "Opera House";
		break;
	case EVENTS_HALL:
		console << "Events Hall";
		break;
	case SPORT_HALL:
		console << "Sport Hall";
		break;
	case CINEMA_HALL:
		console << "Cinema Hall";
		break;
	case SQUARE:
		console << "Square";
		break;
	default:
		console << "Unknown type of place";
		break;
	}

	console << endl;
	//console << "There are" << " " << noOfFreeSeats << " " << "free seats and" << " " << noOfOccupiedSeats << " " << "occupied seats." << endl;

}



istream& operator>>(istream& read, EventPlace& event)
{
	cout << endl << "The number of rows is (at least 5):";
	read >> event.noRows;

	cout << endl << "The number of zones is (at least 1):";
	read >> event.noZones;

	cout << endl << "The number of seats per row is (at least 10):";
	read >> event.noSeatsPerRow;

	cout << endl << "The event occurs at:";



	//enum typeOfPlace { STADIUM, CONCERT_HALL, OPERA_HOUSE, EVENTS_HALL, SPORT_HALL, CINEMA_HALL, SQUARE };

	cout << endl << "Please insert an integer between the set of {0,1,2,3,4,5,6} ";
	cout << endl << "where: 0->Stadium";
	cout << endl << "1-> Concert Hall";
	cout << endl << "2-> Opera House";
	cout << endl << "3-> Events Hall";
	cout << endl << "4-> Sport Hall";
	cout << endl << "5-> Concert Hall";
	cout << endl << "6-> Square";

	int type;

	read >> type;

	switch (type)
	{
	case(0):
		event.name = typeOfPlace::STADIUM;
		break;
	case(1):
		event.name = typeOfPlace::CONCERT_HALL;
		break;
	case(2):
		event.name = typeOfPlace::OPERA_HOUSE;
		break;
	case(3):
		event.name = typeOfPlace::EVENTS_HALL;
		break;
	case(4):
		event.name = typeOfPlace::SPORT_HALL;
		break;
	case(5):
		event.name = typeOfPlace::CINEMA_HALL;
		break;
	case(6):
		event.name = typeOfPlace::SQUARE;
		break;
	default:
		cout << endl << "This location is not defined. Please set a defined location from the previous given set.";
		return read;

	}


	if (event.name == SQUARE)
	{
		event.istheEventaProtest = true;
	}
	else
	{
		event.istheEventaProtest = false;

	}


	return read;

}

