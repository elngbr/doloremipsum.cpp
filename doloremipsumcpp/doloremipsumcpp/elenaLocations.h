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
protected:
	locationType typeOfLocation = EVENTS_HALL;
	int numberOfZones = 0;
	Zone** zones = nullptr;
private:

	int standZoneCounter = 0;
	int normalZoneCounter = 0;
	int vipZoneCounter = 0;
	int categoryZoneCounter = 0;
	int campingZoneCounter = 0;
	int premiumZoneCounter = 0;
	int familyZoneCounter = 0;
	int studentZoneCounter = 0;
	int backstageZoneCounter = 0;
	int greenZoneCounter = 0;
	int sroZoneCounter = 0;
	int networkingZoneCounter = 0;
	int gameZoneCounter = 0;
	int foodZoneCounter = 0;
	int balconyZoneCounter = 0;
	int amphitheaterZoneCounter = 0;
	int boxZoneCounter = 0;

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
		this->typeOfLocation = auxType;
	}
	void initializeCounterOfZoneType(Zone auxZone)
	{

		switch (auxZone.getType())
		{
		case(STAND):
			this->standZoneCounter++;
			break;
		case(NORMAL):
			this->normalZoneCounter++;
			break;
		case(VIPZ):
			this->vipZoneCounter++;

			break;
		case(CATEGORY):
			this->categoryZoneCounter++;

			break;
		case(CAMPING):
			this->campingZoneCounter++;

			break;
		case(PREMIUMZ):
			this->premiumZoneCounter++;

			break;
		case(FAMILY):
			this->familyZoneCounter++;
			break;
		case(STUDENTZ):
			this->studentZoneCounter++;
			break;
		case(BACKSTAGE):
			this->backstageZoneCounter++;
			break;
		case(GREEN):
			this->greenZoneCounter++;
			break;
		case(SRO):
			this->sroZoneCounter++;
			break;
		case(NETWORKING):
			this->networkingZoneCounter++;
			break;
		case(GAME):
			this->gameZoneCounter++;
			break;
		case(FOOD):
			this->foodZoneCounter++;
			break;
		case(BALCONY):
			this->balconyZoneCounter++;
			break;
		case(AMPHITHEATER):
			this->amphitheaterZoneCounter++;
			break;
		case(BOX):
			this->boxZoneCounter++;
			break;
		}

	}
	void addZones(Zone auxZone)
	{
		initializeCounterOfZoneType(auxZone);
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

	locationType getLocationType()
	{
		return this->typeOfLocation;
	}

	Location(locationType auxType)
	{
		this->setType(auxType);
	}

	friend inline ostream& operator<<(ostream& console, Location& auxLocation);

	Zone* getZoneAtIndex(int givenIndex) const {
		if (givenIndex >= 0 && givenIndex < this->numberOfZones) {
			return zones[givenIndex];
		}
		else {

			return nullptr;
		}
	}
	string getStringTypeOfLocation()
	{
		switch (this->typeOfLocation)
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
	void returnLocation()
	{
		int standZoneC = 0;
		int normalZoneC = 0;
		int vipZoneC = 0;
		int categoryZoneC = 0;
		int campingZoneC = 0;
		int premiumZoneC = 0;
		int familyZoneC = 0;
		int studentZoneC = 0;
		int backstageZoneC = 0;
		int greenZoneC = 0;
		int sroZoneC = 0;
		int networkingZoneC = 0;
		int gameZoneC = 0;
		int foodZoneC = 0;
		int balconyZoneC = 0;
		int amphitheaterZoneC = 0;
		int boxZoneC = 0;
		for (int i = 0; i < numberOfZones; i++)
		{
			cout << endl << "Zone UNIQUE ID:" << i;
			cout << endl << "Zone name:" << zones[i]->getStringTypeOfZone() << " "; ////this                                  WILL BE MODIFIED AT SOME POINT!
			switch (this->zones[i]->getType())
			{
			case(0):
			{
				cout << ++standZoneC;
				break;
			}
			case(1):
				cout << ++normalZoneC;
				break;
			case(2):
				cout << ++vipZoneC;
				break;
			case(3):
				cout << ++categoryZoneC;
				break;
			case(4):
				cout << ++campingZoneC;
				break;
			case(5):
				cout << ++premiumZoneC;
				break;
			case(6):
				cout << ++familyZoneC;
				break;
			case(7):
				cout << ++studentZoneC;
				break;
			case(8):
				cout << ++backstageZoneC;
				break;
			case(9):
				cout << ++greenZoneC;
				break;
			case(10):
				cout << ++sroZoneC;
				break;
			case(11):
				cout << ++networkingZoneC;
				break;
			case(12):
				cout << ++gameZoneC;
				break;
			case(13):
				cout << ++foodZoneC;
				break;
			case(14):
				cout << ++balconyZoneC;
				break;
			case(15):
				cout << ++amphitheaterZoneC;
				break;
			case(16):
				cout << ++boxZoneC;
				break;
			}


			cout << endl;
			zones[i]->returnZone();
			cout << endl;
		}
	}

};


inline ostream& operator<<(ostream& console, Location& auxLocation)
{
	//console << endl << "*******************************************************************************************************************";
	console << endl << "This location has the following type" << " ";
	switch (auxLocation.typeOfLocation)
	{
	case STADIUM:
		console << "STADIUM.";
		break;
	case CONCERT_HALL:
		console << "CONCERT HALL.";
		break;
	case OPERA_HOUSE:
		console << "OPERA HOUSE.";
		break;
	case EVENTS_HALL:
		console << "EVENTS HALL.";
		break;
	case SPORT_HALL:
		console << "SPORT HALL.";
		break;
	case CINEMA_HALL:
		console << "CINEMA HALL.";
		break;
	case SQUARE:
		console << "SQUARE.";
		break;
	case THEATRE:
		console << "THEATRE.";
		break;
	case MALL:
		console << "MALL.";
		break;
	case PUBLIC_INSTITUTION:
		console << "PUBLIC INSTITUTION.";
		break;
	case SEA:
		console << "SEA.";
		break;
	case FOREST:
		console << "FOREST.";
		break;
	case MOUNTAIN:
		console << "MOUNTAIN.";
		break;
	case PARK:
		console << "PARK.";
		break;
	case SCHOOL:
		console << "SCHOOL.";
		break;
	case UNIVERSITY:
		console << "UNIVERSITY.";
		break;
	case CHURCH:
		console << "CHURCH.";
		break;
	case LIBRARY:
		console << "LIBRARY.";
		break;
	case CEMETERY:
		console << "CEMETERY.";
		break;
	case RESTAURANT:
		console << "RESTAURANT.";
		break;
	case OTHER:
		console << "OTHER.";
		break;

	default:
		console << "Unknown type of location. Please redefine the switch structure";
		break;
	}

	console << endl << "This location has the following number of zones:" << " " << auxLocation.numberOfZones;
	console << endl << "The zones are:";

	zoneType typeChecker = auxLocation.zones[0]->getType();
	int zoneTypeCounter = 0;
	for (int i = 0; i < auxLocation.numberOfZones; i++)
	{
		console << endl << "This zone's identifier is:" << " " << i + 1;
		console << endl << "This is zone:" << " ";
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
			console << "CAMPING ";
			break;
		case(5):
			console << "PREMIUM ";
			break;
		case(6):
			console << "FAMILY ";
			break;
		case(7):
			console << "STUDENT ";
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
			console << "BALCONY ";
			break;
		case(15):
			console << "AMPHITHEATER ";
			break;
		case(16):
			console << "BOX";
			break;
		default:
			console << "This type did not exist at the moment of creation. Please redefine the switch structure.";
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