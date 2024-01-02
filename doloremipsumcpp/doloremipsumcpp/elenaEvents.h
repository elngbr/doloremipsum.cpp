#pragma once

#include "elenaRows.h"
#include "elenaSeats.h"
#include "elenaZones.h"
#include "elenaLocations.h"
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

class Event
{
private:

	string eventName = " ";
	int numberOfLocations = 0;
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

		this->eventName;

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

	Event(string auxEventName)
	{
		this->setEventName(auxEventName);
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


	inline friend ostream& operator<<(ostream& console, Event& auxEvent);

};

inline ostream& operator<<(ostream& console, Event& auxEvent)
{
	console << "*****************************************************************************************";
	console << endl << "This event's name is" << " " << auxEvent.eventName;
	console << endl << "This event has" << " " << auxEvent.numberOfLocations << " " << "locations";

	for (int i = 0; i < auxEvent.numberOfLocations; i++)
	{
		console << endl << "This location has identifier" << i + 1;
		console << endl << *(auxEvent.locations[i]);
	}

	return console;

}