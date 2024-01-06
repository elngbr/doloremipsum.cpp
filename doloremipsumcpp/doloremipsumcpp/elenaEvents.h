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

	void returnEvent()
	{
		int stadiumLocationC = 0;
		int concerthallLocationC = 0;
		int operahouseLocationC = 0;
		int eventshallLocationC = 0;
		int sporthallLocationC = 0;
		int cinemahallLocationC = 0;
		int squareLocationC = 0;
		int theatreLocationC = 0;
		int mallLocationC = 0;
		int publicinstitutionLocationC = 0;
		int seaLocationC = 0;
		int forestLocationC = 0;
		int mountainLocationC = 0;
		int parkLocationC = 0;
		int schoolLocationC = 0;
		int universityLocationC = 0;
		int churchLocationC = 0;
		int libraryLocationC = 0;
		int cemeteryLocationC = 0;
		int restaurantLocationC = 0;
		cout << "This is the virtual reprezentation of the" << " " << this->eventName << "'s venues:" << endl;
		for (int i = 0; i < this->numberOfLocations; i++)
		{
			/*cout << endl << endl << endl*/;
			cout << endl << "Location UNIQUE ID:" << i;

			cout << endl << "This location's name is:" << locations[i]->getStringTypeOfLocation() << " ";
			switch (this->locations[i]->getLocationType())
			{
			case STADIUM:
				cout << ++stadiumLocationC;
				break;
			case CONCERT_HALL:
				cout << ++concerthallLocationC;
				break;
			case OPERA_HOUSE:
				cout << ++operahouseLocationC;
				break;
			case EVENTS_HALL:
				cout << ++eventshallLocationC;
				break;
			case SPORT_HALL:
				cout << ++sporthallLocationC;
				break;
			case CINEMA_HALL:
				cout << ++cinemahallLocationC;
				break;
			case SQUARE:
				cout << ++squareLocationC;
				break;
			case THEATRE:
				cout << ++theatreLocationC;
				break;
			case MALL:
				cout << ++mallLocationC;
				break;
			case PUBLIC_INSTITUTION:
				cout << ++publicinstitutionLocationC;
				break;
			case SEA:
				cout << ++seaLocationC;
				break;
			case FOREST:
				cout << ++forestLocationC;
				break;
			case MOUNTAIN:
				cout << ++mountainLocationC;
				break;
			case PARK:
				cout << ++parkLocationC;
				break;
			case SCHOOL:
				cout << ++schoolLocationC;
				break;
			case UNIVERSITY:
				cout << ++universityLocationC;
				break;
			case CHURCH:
				cout << ++churchLocationC;
				break;
			case LIBRARY:
				cout << ++libraryLocationC;
				break;
			case CEMETERY:
				cout << ++cemeteryLocationC;
				break;
			case RESTAURANT:
				cout << ++restaurantLocationC;
				break;
			}
			cout << endl << endl << endl << endl << endl << endl << endl;
			cout << " " << "The" << " " << this->locations[i]->getStringTypeOfLocation() << endl;
			cout << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "-------------------------------------------------------------------------------------------------------------------" << endl;
			cout << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
			cout << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "-------------------------------------------------------------------------------------------------------------------" << endl;


			cout << endl << endl << endl;
			cout << endl << endl << endl;
			locations[i]->returnLocation();
		}

	}

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