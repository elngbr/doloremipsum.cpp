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

void serializeString(string value, ofstream& file)
{
	int valueSize = strlen(value.c_str()) + 1;
	file.write((char*)&valueSize, sizeof(int));
	file.write(value.c_str(), sizeof(char) * valueSize);
}

char* deserializeDynamicCharArray(ifstream& file) {
	int arraySize = 0;
	file.read((char*)&arraySize, sizeof(int));
	char* buffer = new char[arraySize];
	file.read(buffer, sizeof(char) * arraySize);

	return buffer;
}


//string deserializeString(ifstream& file)
//{
//	int valueSize = 0;
//
//	file.read((char*)&valueSize, sizeof(int));
//	char buffer[50];
//	file.read(buffer, sizeof(char) * valueSize);
//	return string(buffer);
//}

string deserializeString(ifstream& file)
{
	int valueSize = 0;
	file.read((char*)&valueSize, sizeof(int));

	// Ensure buffer has enough space for valueSize + 1 (for null terminator)
	char* buffer = new char[valueSize + 1];
	file.read(buffer, sizeof(char) * valueSize);

	// Null-terminate the string
	buffer[valueSize] = '\0';

	string result(buffer);

	// Don't forget to free the dynamically allocated memory
	delete[] buffer;

	return result;
}


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

class WrongZoneIdentifierBasedOnType {
private:
	string message;
public:
	WrongZoneIdentifierBasedOnType(const string& msg) : message(msg) {}

	string what()const
	{
		return message;
	}
};

class WrongLocationIdentifierBasedOnType {
private:
	string message;
public:
	WrongLocationIdentifierBasedOnType(const string& msg) : message(msg) {}

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

	int identifierOfZoneBasedOnType = -1;
	int identifierOfLocationBasedOnType = -1;
	zoneType typeZone = NORMAL;
	locationType typeLocation = EVENTS_HALL;

	/*string zoneName = "";
	string locationName = "";*/


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

	void setZoneType(zoneType auxZoneType)
	{
		this->typeZone = auxZoneType;
	}

	void setSeatType(SeatType auxSeatType)
	{
		this->typeSeat = auxSeatType;
	}

	void setLocationType(locationType auxLocationType)
	{
		this->typeLocation = auxLocationType;
	}

	void setZoneIdentifierBasedOnType(int auxZoneIdBasedOnType)
	{
		if (auxZoneIdBasedOnType < 0)
		{
			throw WrongZoneIdentifierBasedOnType("The zone identifier based on type cannot be less than 0");
		}

		this->identifierOfZoneBasedOnType = auxZoneIdBasedOnType;
	}


	void setLocationIdentifierBasedOnType(int auxLocationIdBasedOnType)
	{
		if (auxLocationIdBasedOnType < 0)
		{
			throw WrongLocationIdentifierBasedOnType("The zone identifier based on type cannot be less than 0");
		}

		this->identifierOfLocationBasedOnType = auxLocationIdBasedOnType;
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
				" does not exist for event " + auxEvent.getEventName() + " in zone" + " " + std::to_string(this->zoneIdentifier) + "!");
		}

		this->rowIdentifier = auxRowIndex;
	}



	void setSeatIdentifier(int auxSeatId, int rowNumberOfSeats, Event& auxEvent)
	{
		if (auxSeatId < 0 || auxSeatId >rowNumberOfSeats - 1 || auxEvent.getLocationAtIndex(this->locationIdentifier)->getZoneAtIndex(this->zoneIdentifier)->getRowAtIndex(this->rowIdentifier)->getSeatAtIndex(auxSeatId)->getType() == BROKEN ||
			auxEvent.getLocationAtIndex(this->locationIdentifier)->getZoneAtIndex(this->zoneIdentifier)->getRowAtIndex(this->rowIdentifier)->getSeatAtIndex(auxSeatId)->getType() == OCCUPIED)
		{
			/*throw WrongLocationIdentifier("The location" + "" + to_string(auxLocationId - 1) + " does not exist for event" + " " + auxEvent.getEventName() + "!");*/
			throw WrongSeatIdentifier
			(
				"The seat " + std::to_string(auxSeatId) +
				" does not exist for event " + auxEvent.getEventName() + " " + "at zone" + std::to_string(this->zoneIdentifier) + " " + "at the row" +
				" " + std::to_string(this->rowIdentifier) + " or it is BROKEN or OCCUPIED!"
			);


		}

		this->seatIdentifier = auxSeatId;
	}

	Ticket(string auxTicketid, const char* auxIssueDate, Event auxEvent) : Event(auxEvent)
	{
		this->setDateOfIssue(auxIssueDate);
		this->setTicketID(auxTicketid);
	}

	Ticket(const char* auxIssueDate, Event auxEvent) : Event(auxEvent)
	{
		this->setDateOfIssue(auxIssueDate);
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


	string getStringTypeOfSeat()
	{
		switch (this->typeSeat)
		{
		case(0):
			return "STANDARD";
		case(1):
			return "WHEELCHAIR";
		case(2):
			return "BROKEN";
		case(3):
			return "OCCUPIED";
		case(4):
			return "YOUR CHOICE";
		case(5):
			return "STUDENT";
		case(6):
			return "CHILDREN";
		case(7):
			return "COUPLES";
		case(8):
			return "FLEXIBLE";
		case(9):
			return "VIP";
		case(10):
			return "PREMIUM";
		case(11):
			return "BEAN BAG";
		case(12):
			return "VIRTUAL";
		default:
			return "This type of seat did not exist when this structure was created. Plase redefine the switch structure";
		}
	}

	string getStringTypeOfZone()
	{
		switch (this->typeZone)
		{
		case(0):
			return "STAND";
		case(1):
			return "NORMAL";
		case(2):
			return "VIP";
		case(3):
			return "CATEGORY";
		case(4):
			return "CAMPING";
		case(5):
			return "PREMIUM";
			break;
		case(6):
			return "FAMILY";
		case(7):
			return "STUDENT";
		case(8):
			return "BACKSTAGE";
		case(9):
			return "GREEN";
		case(10):
			return "SRO";
		case(11):
			return "NETWORKING";
		case(12):
			return "GAME";
		case(13):
			return "FOOD";
		case(14):
			return "BALCONY";
		case(15):
			return "AMPHITHEATER";
		case(16):
			return "BOX";

		default:
			return "This type of zone did not exist when this structure was created. Plase redefine the switch structure";

		}
	}


	string getStringTypeOfLocation()
	{
		switch (this->typeLocation)
		{
		case(0):
			return "STADIUM";
		case(1):
			return "CONCERT HALL";
		case(2):
			return "OPERA HOUSE";
		case(3):
			return "EVENTS HALL";
		case(4):
			return "SPORT HALL";
		case(5):
			return "CINEMA HALL";
		case(6):
			return "SQUARE";
		case(7):
			return "THEATRE";
		case(8):
			return "MALL";
		case(9):
			return "PUBLIC INSTITUTION";
		case(10):
			return "SEA";
		case(11):
			return "FOREST";
		case(12):
			return "MOUNTAIN";
		case(13):
			return "PARK";
		case(14):
			return "SCHOOL";
		case(15):
			return "UNIVERSITY";
		case(16):
			return "CHURCH";
		case(17):
			return "lIBRARY";
		case(18):
			return "CEMETERY";
		case(19):
			return "RESTAURANT";
		case(20):
			return "OTHER";
		default:
			return "This type of zone did not exist when this structure was created. Plase redefine the switch structure";
		}
	}

	void serializeTickets(ofstream& file)
	{
		serializeString(this->ticketID, file);
		int sizeChar = strlen(this->dateOfIssue) + 1;
		file.write((char*)&sizeChar, sizeof(int));
		file.write(this->dateOfIssue, sizeof(char) * sizeChar);
		serializeString(this->eventName, file);

		sizeChar = strlen(this->dateOfEvent) + 1;
		file.write((char*)&sizeChar, sizeof(int));
		file.write(this->dateOfEvent, sizeof(char) * sizeChar);

		file.write((char*)&this->locationIdentifier, sizeof(int));
		serializeString(this->getStringTypeOfLocation(), file);
		file.write((char*)&this->identifierOfLocationBasedOnType, sizeof(int));

		file.write((char*)&this->zoneIdentifier, sizeof(int));
		serializeString(this->getStringTypeOfZone(), file);
		file.write((char*)&this->identifierOfZoneBasedOnType, sizeof(int));

		file.write((char*)&this->rowIdentifier, sizeof(int));
		file.write((char*)&this->seatIdentifier, sizeof(int));
		serializeString(this->getStringTypeOfSeat(), file);


	}

	void deserializeTickets(ifstream& file)
	{
		//serializeString(this->ticketID, file);
		this->ticketID = deserializeString(file);


		/*int sizeChar = strlen(this->dateOfIssue)+1;
		file.read((char*)&sizeChar, sizeof(int));
		file.read(this->dateOfIssue, sizeof(this->dateOfIssue));
		this->dateOfIssue[sizeChar] = '\0';
		*/
		char* dynamicCharArray = deserializeDynamicCharArray(file);
		strcpy_s(this->dateOfIssue, strlen(dynamicCharArray) + 1, dynamicCharArray);
		delete[] dynamicCharArray;

		this->eventName = deserializeString(file);

		/*sizeChar = strlen(this->dateOfEvent);
		file.read((char*)&sizeChar, sizeof(int));
		file.read(this->dateOfEvent, sizeof(this->dateOfEvent));
		this->dateOfEvent[sizeChar] = '\0';*/
		char* dynamicCharArray1 = deserializeDynamicCharArray(file);
		strcpy_s(this->dateOfIssue, strlen(dynamicCharArray1) + 1, dynamicCharArray1);
		delete[] dynamicCharArray1;

		file.read((char*)&this->locationIdentifier, sizeof(int));
		this->getStringTypeOfLocation() = deserializeString(file);
		file.read((char*)&this->identifierOfLocationBasedOnType, sizeof(int));

		file.read((char*)&this->zoneIdentifier, sizeof(int));
		this->getStringTypeOfZone() = deserializeString(file);
		file.read((char*)&this->identifierOfZoneBasedOnType, sizeof(int));

		file.read((char*)&this->rowIdentifier, sizeof(int));
		file.read((char*)&this->seatIdentifier, sizeof(int));
		this->getStringTypeOfSeat() = deserializeString(file);


	}
};


inline ostream& operator<<(ostream& console, Ticket& auxTicket)
{
	console << endl << "This ticket's unique identifier is:" << " " << auxTicket.ticketID << endl;
	console << "This ticket's was issued on the date:" << " " << auxTicket.dateOfIssue << endl;
	console << "Event name:" << " " << auxTicket.eventName << " " << endl;
	console << "Event date: " << auxTicket.dateOfEvent << endl;
	console << "Location identifier:" << " " << auxTicket.locationIdentifier << " " << endl;
	console << "Location identifier based on type:" << " " << auxTicket.identifierOfLocationBasedOnType << " " << endl;
	console << "Location type:" << " " << auxTicket.getStringTypeOfLocation() << endl;
	console << "Zone identifier:" << " " << auxTicket.zoneIdentifier << endl;
	console << "Zone identifier based on type:" << auxTicket.identifierOfZoneBasedOnType << endl;
	console << "Zone type:" << " " << auxTicket.getStringTypeOfZone() << endl;
	console << "Row identifier:" << " " << auxTicket.rowIdentifier << endl;
	console << "Seat identifier:" << auxTicket.seatIdentifier << endl;
	console << "Seat type:" << " " << auxTicket.getStringTypeOfSeat() << endl;

	return console;
}