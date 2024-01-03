#pragma once
#include "elenaRows.h"
#include "elenaSeats.h"
#include "elenaZones.h"
#include "elenaLocations.h"
#include "elenaTickets.h"
#include "elenaEvents.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

class WrongIssueDate {
private:
	string message;
public:
	WrongIssueDate(const string& msg) : message(msg) {}

	string what()const
	{
		return message;
	}
};

class WrongIdentifierInput {
private:
	string message;
public:
	WrongIdentifierInput(const string& msg) : message(msg) {}

	string what()const
	{
		return message;
	}
};

class WrongZoneIdentifier {
private:
	string message;
public:
	WrongZoneIdentifier(const string& msg) : message(msg) {}

	string what()const
	{
		return message;
	}
};





class WrongSeatIdentifier {
private:
	std::string message;

public:
	WrongSeatIdentifier(const std::string& msg) : message(msg) {}

	std::string what() const {
		return message;
	}
};






class WrongRowIdentifier {
private:
	string message;
public:
	WrongRowIdentifier(const string& msg) : message(msg) {}

	string what()const
	{
		return message;
	}
};







class WrongLocationIdentifier {
private:
	string message;
public:
	WrongLocationIdentifier(const string& msg) : message(msg) {}

	string what()const
	{
		return message;
	}
};



class Ticket : public Event
{
private:
	string ticketID = "";
	char dateOfIssue[9] = "dd/mm/yy"; ///it will follow the standard dd/mm/yy. the previous sequence has 8ch +1 =9
	SeatType typeSeat = BROKEN;
	int seatIdentifier = -1;
	int rowIdentifier = -1;
	int zoneIdentifier = -1;
	int locationIdentifier = -1;
	zoneType typeZone = NORMAL;
	locationType typeLocation = EVENTS_HALL;


public:
	int static const MIN_TICKET_ID_DIMENSION = 2;

	int getSeatIdentifier()
	{
		return this->seatIdentifier;
	}

	int getZoneIdentifier()
	{
		return this->zoneIdentifier;
	}


	int getRowIdentifier()
	{
		return this->rowIdentifier;
	}


	int getLocationIdentifier()
	{
		return this->locationIdentifier;
	}
	string getTicketId()
	{
		return this->ticketID;
	}

	void setTicketID(string auxTicketId)
	{
		if (auxTicketId[0] < 'A' || auxTicketId[0]>'Z' || auxTicketId.size() < Ticket::MIN_TICKET_ID_DIMENSION)
		{
			throw WrongIdentifierInput("Wrong input date for ticket identifier!");
		}

		this->ticketID = auxTicketId;

	}

	char* getDate() const
	{
		char* copy = new char[strlen(this->dateOfIssue) + 1];
		strcpy_s(copy, strlen(this->dateOfIssue) + 1, this->dateOfIssue);

		return copy;



	}
	///also compare with the event date, but not now, after inheritance.
	void setDateOfIssue(const char* auxDate) {
		if (auxDate == nullptr || auxDate[2] != '/' || auxDate[5] != '/' ||
			(auxDate[0] > '3' && auxDate[1] > '1') ||
			(auxDate[0] == '3' && auxDate[1] > '1') ||
			(auxDate[3] > '1' && auxDate[4] > '2') ||
			(auxDate[3] == '1' && auxDate[4] > '2') ||
			(auxDate[6] < '2') ||
			(auxDate[3] == '0' && auxDate[4] == '2' && (auxDate[0] == '2' && auxDate[1] == '9'))
			)
		{
			throw WrongIssueDate("Wrong input for issue date!");
		}

		strcpy_s(this->dateOfIssue, strlen(auxDate) + 1, const_cast<char*>(auxDate));
	}



	Ticket() :Event("MyEvent", "01/01/24")
	{

	}

	Ticket(string auxTicketid, const char* auxIssueDate,
		string eventName, const char* auxEventDate,
		int auxLocationId, int auxZoneIndex, int auxRowIndex, int auxSeatIndex) : Event(eventName, auxEventDate)
	{
		this->setDateOfIssue(auxIssueDate);
		this->setTicketID(auxTicketid);
		this->zoneIdentifier = auxZoneIndex;
		this->locationIdentifier = auxLocationId;
		this->rowIdentifier = auxRowIndex;
		this->seatIdentifier = auxSeatIndex;

	}

	void setLocationIdentifier(int auxLocationId, Event& auxEvent)
	{
		if (auxLocationId < 0 || auxLocationId > auxEvent.getNumberOfLocations())
		{
			/*throw WrongLocationIdentifier("The location" + "" + to_string(auxLocationId - 1) + " does not exist for event" + " " + auxEvent.getEventName() + "!");*/
			throw WrongLocationIdentifier("The location " + std::to_string(auxLocationId) +
				" does not exist for event " + auxEvent.getEventName() + "!");


		}

		this->locationIdentifier = auxLocationId;
	}



	void setZoneIdentifier(int auxZoneId, Event& auxEvent)
	{
		if (auxZoneId < 0 || auxZoneId > auxEvent.getLocationAtIndex(this->locationIdentifier)->getNumberOfZones())
		{

			throw WrongZoneIdentifier("The zone " + std::to_string(auxZoneId) + " " +
				"does not exist for event " + auxEvent.getEventName() + " " + "in the location" + " " + std::to_string(this->locationIdentifier) + "!");


		}

		this->zoneIdentifier = auxZoneId;
	}




	void setRowIdentifier(int auxRowIndex, int zoneNumberOfRows, Event& auxEvent)
	{


		if (auxRowIndex < 0 || auxRowIndex > zoneNumberOfRows - 1)
		{
			throw WrongRowIdentifier("The row " + std::to_string(auxRowIndex) +
				" does not exist for event " + auxEvent.getEventName() + " in the zone " + " " + std::to_string(this->zoneIdentifier) + "!");
		}

		this->rowIdentifier = auxRowIndex;
	}



	void setSeatIdentifier(int auxSeatId, int rowNumberOfSeats, Event& auxEvent)
	{
		if (auxSeatId < 0 || auxSeatId >rowNumberOfSeats - 1)
		{
			/*throw WrongLocationIdentifier("The location" + "" + to_string(auxLocationId - 1) + " does not exist for event" + " " + auxEvent.getEventName() + "!");*/
			throw WrongSeatIdentifier
			(
				"The seat " + std::to_string(auxSeatId) +
				" does not exist for event " + auxEvent.getEventName() + " " + "at zone" + std::to_string(this->zoneIdentifier) + " " + "at the row" +
				" " + std::to_string(this->rowIdentifier) + "!"
			);


		}

		this->seatIdentifier = auxSeatId;
	}

	Ticket(string auxTicketid, const char* auxIssueDate, Event auxEvent) : Event(auxEvent)
	{
		this->setDateOfIssue(auxIssueDate);
		this->setTicketID(auxTicketid);
	}

	Ticket(int auxLocationId, int auxZoneIndex, int auxRowIndex, int auxSeatIndex, Event auxEvent) : Event(auxEvent)
	{
		if (auxLocationId > 0 && auxLocationId < auxEvent.getNumberOfLocations())
		{
			this->locationIdentifier = auxLocationId;

		}
		if (auxZoneIndex > 0 && auxZoneIndex < auxEvent.getLocationAtIndex(this->locationIdentifier)->getNumberOfZones())
		{
			this->zoneIdentifier = auxZoneIndex;
		}

		if (auxRowIndex > 0 && auxRowIndex < auxEvent.getLocationAtIndex(this->locationIdentifier)->getZoneAtIndex(this->zoneIdentifier)->getNumberOfRowsPerZone())
		{
			this->rowIdentifier = auxRowIndex;
		}


		if (auxSeatIndex > 0 && auxSeatIndex < auxEvent.getLocationAtIndex(this->locationIdentifier)->getZoneAtIndex(this->zoneIdentifier)->getRowAtIndex(this->rowIdentifier)->getNoOfSeatsForRow())
		{
			this->seatIdentifier = auxSeatIndex;
		}

	}


	void extendTicketIdentifier(string extension)
	{
		this->ticketID += extension;

	}
	inline friend ostream& operator<<(ostream& console, Ticket& auxTicket);

};

inline ostream& operator<<(ostream& console, Ticket& auxTicket)
{
	console << endl << "This ticket's unique identifier is:" << " " << auxTicket.ticketID;
	/*console << endl << "This ticket's was issued on the date" << " " << auxTicket.dateOfIssue << " " << "for the event" << " " << auxTicket.eventName << " " << endl << "which occures on";
	console << " " << auxTicket.dateOfEvent << endl;
	console << endl << "The location for which the ticket was selled is" << " " << auxTicket.locationIdentifier << " " << "the type of this zone being" << " " << auxTicket.typeLocation;
	console << endl << "The zone for which the ticket was selled is" << " " << auxTicket.zoneIdentifier << " " << "the type of this zone being" << " " << auxTicket.typeZone;
	console << endl << "The row for which the ticket was selled is" << " " << auxTicket.rowIdentifier << " ";
	console << endl << "The seat reserved by this ticket is:" << auxTicket.seatIdentifier << " " << "having type" << " " << auxTicket.typeSeat << " " << "on the row" << " " << auxTicket.rowIdentifier;*/

	return console;
}