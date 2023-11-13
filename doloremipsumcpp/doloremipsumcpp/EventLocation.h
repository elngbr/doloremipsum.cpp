#pragma once

#include <iostream>
#include <string>
using namespace std;
enum typeOfPlace {STADIUM, CONCERT_HALL, OPERA_HOUSE, EVENTS_HALL, SPORT_HALL, CINEMA_HALL};
enum typeOfEvent { CONCERT, FOOTBALL, THEATRE, FILM, CHARITY, FAIR };
enum typeOfTicket { VIP, LAWN, TRIBUNE, BOXES, STAND }; ///also type of zone OR NOT?

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
	int** stateOfSeats = nullptr;

public:
	int static const MAX_SEATS_ALLOWED = 1000;
	int static const MIN_ZONES = 1;
	int static const MIN_ROWS_PER_ZONE = 5;
	int static const MIN_SEATS_PER_ROW = 10;

	typeOfPlace getName()
	{
		return this->name;
	}

	void setName(typeOfPlace auxName)
	{
		if (auxName < typeOfPlace::STADIUM || auxName>typeOfPlace::CINEMA_HALL)
		{
			throw exception("Wrong input!");
		}

		this->name = auxName;
	}


	int getNumberOfRows()   ///if I create a setter for this one I risk to have someone modifying it and adding a number of rows which is less than my actual number
	{
		return this->noRows;
	}

	int getNoOfSeatsPerRows()   ///if I create a setter for this one I risk to have someone modifying it and adding a number of rows which is less than my actual number
	{
		return this->noSeatsPerRow;
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

	int** getStateOfSeats()
	{
		int** copy = new int* [this->noRows];
		for (int i = 0; i < noRows; i++) {
			copy[i] = new int[this->noSeatsPerRow];

			for (int j = 0; j < noSeatsPerRow; j++)
				copy[i][j] = this->stateOfSeats[i][j];
		}

		return copy;
	}


	void setStateOfSeats(int** matrix, int auxNoRows, int auxNoSeatsPerRow) {
		if (matrix == nullptr || auxNoRows < EventPlace::MIN_ROWS_PER_ZONE || auxNoSeatsPerRow < EventPlace::MIN_SEATS_PER_ROW) {
			throw exception("Wrong value!");
		}


		for (int i = 0; i < noRows; i++) {
			delete[] stateOfSeats[i];
		}
		delete[] stateOfSeats;

		stateOfSeats = new int* [auxNoRows];
		for (int i = 0; i < auxNoRows; i++) {
			stateOfSeats[i] = new int[auxNoSeatsPerRow];
		}


		for (int i = 0; i < auxNoRows; i++) {
			for (int j = 0; j < auxNoSeatsPerRow; j++) {
				stateOfSeats[i][j] = matrix[i][j];
			}
		}


		noRows = auxNoRows;
		noSeatsPerRow = auxNoSeatsPerRow;
	}

	EventPlace()
	{


	}

	EventPlace(int auxNoRows, int auxNoSeatsPerRow, int** auxMatrix, int auxNoZones, typeOfPlace auxName)
	{
		this->setStateOfSeats(auxMatrix, auxNoRows, auxNoSeatsPerRow);
		this->setNumberofZones(auxNoZones);
		this->setName(auxName);
	}

	~EventPlace()
	{

		for (int i = 0; i < noRows; i++) {
			delete[] stateOfSeats[i];
		}
		delete[] stateOfSeats;
	}


	EventPlace(const EventPlace& place)
	{
		this->noRows = place.noRows;
		this->noSeatsPerRow = place.noSeatsPerRow;
		this->noZones = place.noZones;


		this->stateOfSeats = new int* [noRows];
		for (int i = 0; i < noRows; i++) {
			this->stateOfSeats[i] = new int[noSeatsPerRow];
		}

		for (int i = 0; i < noRows; i++) {
			for (int j = 0; j < noSeatsPerRow; j++) {
				this->stateOfSeats[i][j] = place.stateOfSeats[i][j];
			}
		}
	}

	/*
	bool areThereStillPlaces(int auxStateOfSeats, int auxNoRows, int auxSeatsPerRow)
	{
		int i, j;

		for(i=0; i<auxNoRows; i++)
			for(j=0; j<auxSeatsPerRow; j++)
				if (auxStateOfSeats[i][j])
				{

				}
	}
	*/

	friend void operator<<(ostream& console, const EventPlace& place);
};

/**/void operator<<(ostream& console, const EventPlace& place)
{
	console << endl << "No of rows:" << place.noRows;
	console << endl << "No of seats per row" << place.noSeatsPerRow;
	console << endl << "No of zones" << place.noZones;
	int noOfOccupiedSeats = 0;
	int noOfFreeSeats = 0;
	for (int i = 0; i < place.noRows; i++)
	{
		for (int j = 0; j < place.noSeatsPerRow; j++)
			if (place.stateOfSeats[i][j] == 0)
			{
				noOfFreeSeats++;
			}
			else
			{
				noOfOccupiedSeats++;
			}

	}

	console << endl << "In this" << " ";
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
	default:
		console << "Unknown type of place";
		break;
	}

	console << " " << "there are" << " " << noOfFreeSeats << " " << "free seats and" << " " << noOfOccupiedSeats << " " << "occupied seats." << endl;

	for (int i = 0; i < place.noRows; i++)
	{
		for (int j = 0; j < place.noSeatsPerRow; j++)
			if (place.stateOfSeats[i][j] == 0)
				console << endl << "The seat" << " " << j << " " << "on row" << " " << i << " " << "is not occupied yet. Feel free to buy a ticket here.";

	}




}


class Event {
private:
	int  static NO_OF_EVENTS; ///if you have such things, you can only decrement it in the destructor
	//so also define at least one dynamic attribute, so that the destructor will be called
	int const eventId = 0;//no setter for this one
	char* nameOfEvent = nullptr; ///so that NO ONE CAN MODIFY
	char dateOfEvent[9] = "dd/mm/yy"; ///it will follow the standard dd/mm/yyyy. the previous sequence has 8ch +1 =9
	char timeOfEvent[6] = "hh:mm"; //will follow the satndard hh:mm. the previous sequence has 5 ch + 1=6

public:

	int getEventId()
	{
		return this->eventId;

	}

	char* getNameOfEvent()
	{
		char* copy = new char[strlen(this->nameOfEvent) + 1];
		strcpy_s(copy, strlen(this->nameOfEvent) + 1, this->nameOfEvent);

		return copy;
	}

	void setNameOfEvent(char* auxName)
	{
		if (auxName == nullptr || auxName[0] < 'A' || auxName[0]>'Z')
		{
			throw exception("Wrong name!");
		}

		delete[] this->nameOfEvent;
		this->nameOfEvent = new char[strlen(auxName) + 1];
		strcpy_s(this->nameOfEvent, strlen(auxName) + 1, auxName);

	}

	char* getDate()
	{
		char* copy = new char[strlen(this->dateOfEvent) + 1];
		strcpy_s(copy, strlen(this->dateOfEvent) + 1, this->dateOfEvent);

		return copy;



	}

	void setDate(const char* auxDate)///all events will occur in 2024
	{
		if (auxDate == nullptr || auxDate[2] != '/' || auxDate[5] != '/' || (auxDate[0] == '3' && (auxDate[1] > '1' || auxDate[1] < '0')) || auxDate[0] != '0' || auxDate[0] != '1' || auxDate[0] != '2' || auxDate[0] != '3' || auxDate[3] != '1' || auxDate[3] != '0' || (auxDate[3] == '0' && (auxDate[4] > '9' || auxDate[4] < '0')) || (auxDate[3] == '1' && (auxDate[4] > '2' || auxDate[4] < '0')) || auxDate[6] != '2' || auxDate[7] != '4')
		{
			throw exception("Wrong input!");
		}


		strcpy_s(this->dateOfEvent, strlen(auxDate) + 1, const_cast<char*>(auxDate));


	}

	char* getTime()
	{
		char* copy = new char[strlen(this->timeOfEvent) + 1];
		strcpy_s(copy, strlen(this->timeOfEvent) + 1, this->timeOfEvent);

		return copy;

	}

	void setTime(const char* auxTime)
	{
		if (auxTime[2] != ':' || auxTime[0] != '0' || auxTime[0] != '1' || auxTime[1] < '0' || auxTime[1]>'9' || auxTime[3] < '0' || auxTime[3]>'5' || auxTime[4] < '0' || auxTime[4]>'9' || auxTime == nullptr)
		{
			throw exception("Wrong input! All events will occur in 2024 ");

		}

		strcpy_s(this->timeOfEvent, strlen(auxTime) + 1, auxTime);
	}


	//////////DEFAULT CONSTRUCTOR


	Event() :eventId(++NO_OF_EVENTS)
	{

	}
///CONSTRUCTOR WITH PARAMETERS
	Event(char* auxNameOfEvent) : eventId(++NO_OF_EVENTS)
	{
		this->setNameOfEvent(auxNameOfEvent);

	}
	~Event()
	{
		delete[] this->nameOfEvent;

		Event::NO_OF_EVENTS--;
	}

	Event(Event& newEvent) : eventId(++NO_OF_EVENTS)
	{
		strcpy_s(dateOfEvent, sizeof(dateOfEvent), newEvent.getDate());
		strcpy_s(this->timeOfEvent, strlen(timeOfEvent) + 1, newEvent.getTime());
		this->nameOfEvent = newEvent.getNameOfEvent();
	}

};

int Event::NO_OF_EVENTS = 0;

class Ticket {
private:  //could be by default

	int static NO_OF_TICKETS;
	int ticketId = 0;
	typeOfTicket type = typeOfTicket::BOXES;
	char* dateOfIssue = nullptr;

public:

	int getId()
	{
		return this->ticketId;
	}

	typeOfTicket getType()
	{
		return this->type;
	}

	void setTypeOfTicket(typeOfTicket auxType)
	{
		this->type = auxType;
	}

	char* getDateOfIssue()
	{
		char* copy = new char[strlen(this->dateOfIssue) + 1];
		strcpy_s(copy, strlen(this->dateOfIssue) + 1, this->dateOfIssue);

		return copy;
	}


	void setDateOfIssue(const char*auxDate)   ///all tickets can be issued in 2024
	{
		if (auxDate == nullptr || auxDate[2] != '/' || auxDate[5] != '/' || (auxDate[0] == '3' && (auxDate[1] > '1' || auxDate[1] < '0')) || auxDate[0] != '0' || auxDate[0] != '1' || auxDate[0] != '2' || auxDate[0] != '3' || auxDate[3] != '1' || auxDate[3] != '0' || (auxDate[3] == '0' && (auxDate[4] > '9' || auxDate[4] < '0')) || (auxDate[3] == '1' && (auxDate[4] > '2' || auxDate[4] < '0')) || auxDate[6] != '2' || auxDate[7] != '4')
		{
			throw exception("Wrong input! All tickets can be issued in 2024!");
		}


		strcpy_s(this->dateOfIssue, strlen(auxDate) + 1, const_cast<char*>(auxDate));

	}

	//Default Constructor

	Ticket(): ticketId(++NO_OF_TICKETS)
	{


	}


	///CTOR WITH AT LEAST ONE PARAMETER
	Ticket(typeOfTicket auxType, char*auxDateOfIssue):ticketId(++NO_OF_TICKETS)
	{
		this->setTypeOfTicket(auxType);
		this->setDateOfIssue(auxDateOfIssue);
	}

	///DESTRUCTOR
	~Ticket()
	{
		delete[]this->dateOfIssue;
		NO_OF_TICKETS--;
	}

	//CPY-CONSTRUCTOR

	Ticket(Ticket& ticket) :ticketId(++NO_OF_TICKETS)
	{
		this->setDateOfIssue(ticket.getDateOfIssue());
		this->setTypeOfTicket(ticket.getType());
	}

};

int Ticket::NO_OF_TICKETS = 0;