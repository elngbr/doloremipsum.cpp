#pragma once

#include <iostream>
#include <string>
using namespace std;
enum typeOfPlace { STADIUM, CONCERT_HALL, OPERA_HOUSE, EVENTS_HALL, SPORT_HALL, CINEMA_HALL, SQUARE };
enum typeOfEvent { CONCERT, FOOTBALL, THEATRE, FILM, CHARITY, FAIR, PROTEST };
enum typeOfTicket { VIP, LAWN, TRIBUNE, BOXES, STAND1, STAND2, CATEGORY1, CATEGORY2 }; ///also type of zone OR NOT?

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

	int setNumberOfRows(int auxNoRows)
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


	int setNoOfSeatsPerRows(int auxNoSeats)
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

	EventPlace(int auxNoRows, int auxNoSeatsPerRow, int auxNoZones, typeOfPlace auxName)
	{

		this->setNumberofZones(auxNoZones);
		this->setName(auxName);
		this->setNoOfSeatsPerRows(auxNoSeatsPerRow);
		this->setNumberOfRows(auxNoRows);

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
		if (this->name == auxPlace.name && this->noRows*this->noSeatsPerRow==auxPlace.noRows*auxPlace.noSeatsPerRow)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	///overloading the operator <= for noZones
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
	console << endl << "No of seats per row:" << place.noSeatsPerRow;
	console << endl << "No of zones:" << place.noZones;

	console << endl << "Oficially, there has been allocated" << " " << place.noRows * place.noSeatsPerRow << " " << "seats to this event, which will be devided in "
		<< place.noZones << " " << "zones.";
	//console << endl << "The place of the event is called" << " " << place.name;
	int noOfOccupiedSeats = 0;
	int noOfFreeSeats = 0;


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

	cout << endl;
	console << "There are" << " " << noOfFreeSeats << " " << "free seats and" << " " << noOfOccupiedSeats << " " << "occupied seats." << endl;






}

class Event {
private:
	int  static NO_OF_EVENTS; ///if you have such things, you can only decrement it in the destructor
	//so also define at least one dynamic attribute, so that the destructor will be called
	int const eventId = 0;//no setter for this one
	char* nameOfEvent = nullptr; ///so that NO ONE CAN MODIFY
	char dateOfEvent[9] = "dd/mm/yy"; ///it will follow the standard dd/mm/yyyy. the previous sequence has 8ch +1 =9
	char timeOfEvent[6] = "hh:mm"; //will follow the satndard hh:mm. the previous sequence has 5 ch + 1=6
	typeOfEvent type = typeOfEvent::FOOTBALL;
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
		if (auxDate == nullptr ||
			auxDate[2] != '/' ||
			auxDate[5] != '/' ||
			(auxDate[0] != '0' && auxDate[0] != '1' && auxDate[0] != '2' && auxDate[0] != '3') ||
			(auxDate[3] != '0' && auxDate[3] != '1') ||
			((auxDate[3] == '0' && (auxDate[4] > '9' || auxDate[4] < '0')) || (auxDate[3] == '1' && (auxDate[4] > '2' || auxDate[4] < '0'))) ||
			auxDate[6] != '2' ||
			auxDate[7] != '4')
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
		if (auxTime == nullptr ||
			auxTime[2] != ':' ||
			(auxTime[0] != '0' && auxTime[0] != '1') ||
			(auxTime[1] < '0' || auxTime[1] > '9') ||
			(auxTime[3] < '0' || auxTime[3] > '5') ||
			(auxTime[4] < '0' || auxTime[4] > '9'))
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
	Event(const char* auxNameOfEvent, const char* auxDate, const char* auxTime) : eventId(++NO_OF_EVENTS)
	{
		this->setNameOfEvent(const_cast<char*>(auxNameOfEvent));
		this->setDate(auxDate);
		this->setTime(auxTime);

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
	friend void operator<<(ostream& console, const Event& auxEvent);

};

int Event::NO_OF_EVENTS = 0;

void operator<<(ostream& console, const Event& auxEvent)
{
	console << endl << "This event is called" << " " << auxEvent.nameOfEvent;
	console << endl << "This event has an unique ID, this being" << "" << auxEvent.eventId;
	console << endl << "The event starts at " << " " << auxEvent.timeOfEvent;
	console << endl << "The events is occuring on" << " " << auxEvent.dateOfEvent;

	console << endl << "The type of event is" << " ";

	switch (auxEvent.type)
	{
	case FOOTBALL:
		console << "Footbal";
		break;
	case CONCERT:
		console << "Concert";
		break;
	case THEATRE:
		console << "Theatre";
		break;
	case FILM:
		console << "Film";
		break;
	case CHARITY:
		console << "Charity";
		break;
	case FAIR:
		console << "Fair";
		break;
	case PROTEST:
		console << "Protest";
		break;
	default:
		console << "Unknown type of event";
		break;
	}
	console << endl;
	console << endl;
	console << endl;

}


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


	void setDateOfIssue(const char* auxDate)   ///all tickets can be issued in 2024
	{
		if (auxDate == nullptr ||
			auxDate[2] != '/' ||
			auxDate[5] != '/' ||
			(auxDate[0] != '0' && auxDate[0] != '1' && auxDate[0] != '2' && auxDate[0] != '3') ||
			(auxDate[3] != '0' && auxDate[3] != '1') ||
			((auxDate[3] == '0' && (auxDate[4] > '9' || auxDate[4] < '0')) || (auxDate[3] == '1' && (auxDate[4] > '2' || auxDate[4] < '0'))) ||
			auxDate[6] != '2' ||
			auxDate[7] != '4')
		{
			throw exception("Wrong input! All tickets can be issued in 2024!");
		}

		delete[]this->dateOfIssue;
		this->dateOfIssue = new char[strlen(auxDate) + 1];

		strcpy_s(this->dateOfIssue, strlen(auxDate) + 1, const_cast<char*>(auxDate));

	}

	//Default Constructor

	Ticket() : ticketId(++NO_OF_TICKETS)
	{


	}


	///CTOR WITH AT LEAST ONE PARAMETER
	Ticket(typeOfTicket auxType, const char* auxDateOfIssue) :ticketId(++NO_OF_TICKETS)
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

	friend void operator<<(ostream& console, const Ticket& ticket);

};

int Ticket::NO_OF_TICKETS = 0;

void operator<<(ostream& console, const Ticket& ticket)
{
	//console << "This is a ticket that allows you to go to the" <<" " << ticket.type;
	console << endl << "This ticket is uniquely defined by the Id" << " " << ticket.ticketId;
	console << endl << "This ticket was issued at this date: " << ticket.dateOfIssue;
	console << endl << "This is a ticket that allows you to go to the" << " ";

	switch (ticket.type)/////////////////////IF U RETURNED INSTEAD OF DISPLAYING WITH CONSOLE, YOU NEED'NT USE BREAK. BUT WE NEVER NEVER NEVER RETURN IN A VOID :)
	{
	case VIP:
		console << "Vip";
		break;
	case LAWN:
		console << "Lawn";
		break;
	case CATEGORY1:
		console << "Category 1";
		break;
	case CATEGORY2:
		console << "Category 2";
		break;
	case BOXES:
		console << "Boxes";
		break;
	case STAND1:
		console << "Stand 1";
		break;
	case STAND2:
		console << "Stand 2";
		break;
	case TRIBUNE:
		console << "Tribune";
		break;
	default:
		console << "Unrecognizable type of ticket!";
		break;

	}

	console << endl;

}