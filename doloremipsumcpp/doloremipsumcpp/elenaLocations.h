#pragma once
#include "elenaRows.h"
#include "elenaSeats.h"
#include "elenaZones.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

class WrongLocationNumberOfZonesException
{
private:
	string message;
public:
	WrongLocationNumberOfZonesException(const string& msg) : message(msg) {}

	string what()const
	{
		return message;
	}
};
enum locationType {
	STADIUM, CONCERT_HALL, OPERA_HOUSE, EVENTS_HALL, SPORT_HALL, CINEMA_HALL, SQUARE,
	THEATRE, MALL, PUBLIC_INSTITUTION, SEA, FOREST, MOUNTAIN, PARK, SCHOOL, UNIVERSITY, CHURCH, LIBRARY, CEMETERY, RESTAURANT, OTHER
};

class Location
{
private:
	locationType type = EVENTS_HALL;
	int numberOfZones = 0;
	Zone** zones = nullptr;
public:
	int static const MAX_IDENTIFIER_OF_ZONE = 6;

	int getNumberOfZones()
	{
		return this->numberOfZones;
	}

	void setNumberOfZones(int auxNumberOfZones)
	{
		if (auxNumberOfZones < 0)
		{
			throw WrongZoneNumberOfRowsException("You cannot have less than 0 zones in a location");
		}
		else if (auxNumberOfZones > MAX_IDENTIFIER_OF_ZONE)
		{
			throw WrongZoneNumberOfRowsException("You cannot have more  than 6 zones in a location");

		}

		this->numberOfZones = auxNumberOfZones;

	}
	void setType(locationType auxType)
	{
		this->type = auxType;
	}
	void addZones(Zone auxZone)
	{

		Zone** newZones = new Zone * [this->numberOfZones + 1];
		for (int i = 0; i < this->numberOfZones; i++)
		{
			newZones[i] = this->zones[i];
		}

		newZones[this->numberOfZones] = new Zone(auxZone);

		delete[] this->zones;
		this->zones = newZones;
		this->numberOfZones++;
	}

	Location(locationType auxType)
	{
		this->setType(auxType);
	}

	friend inline ostream& operator<<(ostream& console, Location& auxLocation);

};


inline ostream& operator<<(ostream& console, Location& auxLocation)
{
	console << endl << "*******************************************************************************************************************";
	console << endl << "This location has the following type" << " ";
	switch (auxLocation.type)
	{
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
	case THEATRE:
		console << "Theatre";
		break;
	case MALL:
		console << "Mall";
		break;
	case PUBLIC_INSTITUTION:
		console << "Public institution";
		break;
	case SEA:
		console << "Sea";
		break;
	case FOREST:
		console << "Forest";
		break;
	case MOUNTAIN:
		console << "Mountain";
		break;
	case PARK:
		console << "Park";
		break;
	case SCHOOL:
		console << "School";
		break;
	case UNIVERSITY:
		console << "University";
		break;
	case CHURCH:
		console << "Church";
		break;
	case LIBRARY:
		console << "Library";
		break;
	case CEMETERY:
		console << "CEMETERY";
		break;
	case RESTAURANT:
		console << "Restaurant";
		break;
	case OTHER:
		console << "OTHER";
		break;

	default:
		console << "Unknown type of location. Please redefine the switch structure";
		break;
	}

	console << endl << "This location has the following number of zones" << " " << auxLocation.numberOfZones;
	console << endl << "The zones are:";

	zoneType typeChecker = auxLocation.zones[0]->getType();
	int zoneTypeCounter = 0;
	for (int i = 0; i < auxLocation.numberOfZones; i++)
	{
		console << endl << "This zone's identifier is" << " " << i + 1;
		console << endl << "This is zone" << " ";
		switch (auxLocation.zones[i]->getType())
		{
		case(0):
			console << "STAND ";
			break;
		case(1):
			console << "NORMAL";
			break;
		case(2):
			console << "VIP ";
			break;
		case(3):
			console << "CATEGORY";
			break;
		case(4):
			console << " CAMPING ";
			break;
		case(5):
			console << " PREMIUM ";
			break;
		case(6):
			console << "FAMILY ";
			break;
		case(7):
			console << " STUDENT ";
			break;
		case(8):
			console << "BACKSTAGE ";
			break;
		case(9):
			console << "GREEN ";
			break;
		case(10):
			console << "SRO ";
			break;
		case(11):
			console << "NETWORKING ";
			break;
		case(12):
			console << "GAME ";
			break;
		case(13):
			console << "FOOD ";
			break;
		case(14):
			console << " BALCONY ";
			break;
		case(15):
			console << "AMPHITEATHER ";
			break;
		}


		if (typeChecker == auxLocation.zones[i]->getType())
		{
			zoneTypeCounter++;
		}
		else
		{
			typeChecker = auxLocation.zones[i]->getType();
			zoneTypeCounter = 1;

		}

		console << zoneTypeCounter;
		console << *(auxLocation.zones[i]) << endl;


	}

	return console;
}