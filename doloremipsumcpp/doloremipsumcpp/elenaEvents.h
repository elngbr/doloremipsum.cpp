#pragma once
#include "elenaSeats.h"
#include "elenaZones.h"
#include "elenaLocations.h"
#include "elenaRows.h"
#include "OverloadedF.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;


class WrongNumberOfLocationsForEvent {
private:
	string message;
public:
	WrongNumberOfLocationsForEvent(const string& msg) : message(msg) {}

	string what()const
	{
		return message;
	}
};

class WrongNameForEvent {
private:
	string message;
public:
	WrongNameForEvent(const string& msg) : message(msg) {}

	string what()const
	{
		return message;
	}
};

class WrongDateForEvent {
private:
	string message;
public:
	WrongDateForEvent(const string& msg) : message(msg) {}

	string what()const
	{
		return message;
	}
};

class Event
{
protected:
	char dateOfEvent[9] = "dd/mm/yy"; ///it will follow the standard dd/mm/yy. the previous sequence has 8ch +1 =9
	string eventName = " ";
	int numberOfLocations = 0;
private:

	Location** locations = nullptr;

public:
	int static const MAX_IDENTIFIER_FOR_LOCATION = 3;
	int static const MIN_EVENT_NAME_SIZE = 2;



	int getNumberOfLocations()
	{
		return this->numberOfLocations;
	}

	void setNumberOfLocations(int auxNumberOfLocations)
	{
		if (auxNumberOfLocations < 0)
		{
			throw WrongNumberOfLocationsForEvent("An event cannot have less than 0 locations");
		}
		else if (auxNumberOfLocations > Event::MAX_IDENTIFIER_FOR_LOCATION)
		{
			throw WrongNumberOfLocationsForEvent("An event cannot have more than 3 locations");

		}
	}

	string getEventName()const
	{

		return this->eventName;

	}

	void setEventName(string auxName)
	{
		if (auxName[0] < 'A' || auxName[0]>'Z')
		{
			throw WrongNameForEvent("The name of the event has to start with capital letters!");
		}
		else if (auxName.size() < Event::MIN_EVENT_NAME_SIZE)
		{
			throw WrongNameForEvent("The name of the event has to contain at least 2 letters!");

		}
		this->eventName = auxName;

	}


	char* getDate() const
	{
		char* copy = new char[strlen(this->dateOfEvent) + 1];
		strcpy_s(copy, strlen(this->dateOfEvent) + 1, this->dateOfEvent);

		return copy;



	}

	Event()
	{

	}

	void setDate(const char* auxDate) {
		if (auxDate == nullptr || auxDate[2] != '/' || auxDate[5] != '/' ||
			(auxDate[0] > '3' && auxDate[1] > '1') ||
			(auxDate[0] == '3' && auxDate[1] > '1') ||
			(auxDate[3] > '1' && auxDate[4] > '2') ||
			(auxDate[3] == '1' && auxDate[4] > '2') ||
			(auxDate[6] < '2') ||
			(auxDate[3] == '0' && auxDate[4] == '2' && (auxDate[0] == '2' && auxDate[1] == '9'))
			)
		{
			throw WrongDateForEvent("Wrong input for event date!");
		}

		strcpy_s(this->dateOfEvent, strlen(auxDate) + 1, const_cast<char*>(auxDate));
	}


	Event(string auxEventName, const char* auxEventDate)
	{
		this->setEventName(auxEventName);
		this->setDate(auxEventDate);
	}


	void addLocations(Location auxLocation)
	{
		Location** newLocations = new Location * [this->numberOfLocations + 1];
		for (int i = 0; i < this->numberOfLocations; i++)
		{
			newLocations[i] = this->locations[i];
		}

		newLocations[this->numberOfLocations] = new Location(auxLocation);
		delete[]this->locations;
		this->locations = newLocations;
		this->numberOfLocations++;
	}

	Location* getLocationAtIndex(int givenIndex) const {

		if (givenIndex >= 0 && givenIndex < this->numberOfLocations) {
			return locations[givenIndex];
		}
		else {
			// Handle error, return nullptr, throw an exception, or handle it according to your design
			return nullptr;
		}
	}

	inline friend ostream& operator<<(ostream& console, Event& auxEvent);

};

inline ostream& operator<<(ostream& console, Event& auxEvent)
{
	console << "*****************************************************************************************";
	console << endl << "This event's name is:" << " " << auxEvent.eventName;
	console << endl << "This event's happens on:" << " " << auxEvent.dateOfEvent;
	console << endl << "This event has" << " " << auxEvent.numberOfLocations << " " << "locations.";

	for (int i = 0; i < auxEvent.numberOfLocations; i++)
	{
		console << endl << "This location has identifier:" << " " << i + 1;
		console << endl << *(auxEvent.locations[i]);
	}

	return console;

}