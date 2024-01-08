#pragma once
#include "elenaRows.h"
#include "elenaSeats.h"

#include<string>
#include<iostream>
#include<fstream>
using namespace std;



///a zone HAS a collection of rows

class WrongZoneNumberOfRowsException
{
private:
	string message;
public:
	WrongZoneNumberOfRowsException(const string& msg) : message(msg) {}

	string what()const
	{
		return message;
	}
};

class WrongExtensionException
{
private:
	string message;
public:
	WrongExtensionException(const string& msg) : message(msg) {}

	string what()const
	{
		return message;
	}
};

class WrongZonePrice
{
private:
	string message;
public:
	WrongZonePrice(const string& msg) : message(msg) {}

	string what()const
	{
		return message;
	}
};

enum zoneType { STAND, NORMAL, VIPZ, CATEGORY, CAMPING, PREMIUMZ, FAMILY, STUDENTZ, BACKSTAGE, GREEN, SRO, NETWORKING, GAME, FOOD, BALCONY, AMPHITHEATER, BOX };
//SRO-----seating room only

class Row;
class Zone :public Row
{
protected:

	zoneType typeOfZone = NORMAL;
	int numberOfRowsPerZone = 0;
	Row** rows = nullptr;

	//string zoneName = "";

private:

public:
	int const static MAX_ROW_IDENTIFIER_PER_ZONE = 15;


	int getNumberOfRowsPerZone()
	{
		return this->numberOfRowsPerZone;
	}

	////////////////////////////DO NOT MAKE A GETTER FOR A TYPE 

	void setType(zoneType auxType)
	{
		this->typeOfZone = auxType;
	}

	zoneType getSeatType()
	{
		return this->typeOfZone;
	}

	void setNumberOfRowsPerZone(int auxNo)
	{
		if (auxNo < 0)
		{
			throw WrongZoneNumberOfRowsException("You cannot have less than 0 rows in a zone");
		}
		else if (auxNo > Zone::MAX_ROW_IDENTIFIER_PER_ZONE)
		{
			throw WrongZoneNumberOfRowsException("You cannot have more than 15 rows in a zone");

		}

		this->numberOfRowsPerZone = auxNo;
	}

	string getStringTypeOfZone()
	{
		switch (this->typeOfZone)
		{
		case STAND:
			return "STAND";
		case NORMAL:
			return "NORMAL";
		case VIPZ:
			return "VIP";
		case CATEGORY:
			return "CATEGORY";
		case CAMPING:
			return "CAMPING";
		case PREMIUMZ:
			return "PREMIUM";
		case FAMILY:
			return "FAMILY";
		case STUDENTZ:
			return "STUDENT";
		case BACKSTAGE:
			return "BACKSTAGE";
		case GREEN:
			return "GREEN";
		case SRO:
			return "SRO";
		case NETWORKING:
			return "NETWORKING";
		case GAME:
			return "GAME";
		case FOOD:
			return "FOOD";
		case BALCONY:
			return "BALCONY";
		case AMPHITHEATER:
			return "AMPHITHEATER";
		case BOX:
			return "BOX";
		default:
			return "This type of zone did not exist when this structure was created. Please redefine the switch structure";
		}
	}


	void addRows(Row auxRow)
	{

		Row** newRows = new Row * [this->numberOfRowsPerZone + 1];
		for (int i = 0; i < this->numberOfRowsPerZone; i++)
		{
			newRows[i] = this->rows[i];
		}

		newRows[this->numberOfRowsPerZone] = new Row(auxRow);

		delete[] this->rows;
		this->rows = newRows;
		this->numberOfRowsPerZone++;
		//auxRow.setRowIdentifier(this->numberOfRowsPerZone);
	}

	//void extendZoneName(string auxExtension)
	//{
	//	if (auxExtension.size() < 0)
	//	{
	//		throw WrongExtensionException("An extention cannot have a nwgative size!"); ////this will never, ever happen. I just had to validate :) 
	//	}

	//	this->zoneName = this->zoneName + " " + auxExtension;
	//}

	Zone(zoneType auxType)
	{
		this->setType(auxType);



	}

	friend inline ostream& operator<<(ostream& console, Zone& auxZone);

	zoneType getType() const
	{
		return this->typeOfZone;
	}

	Row* getRowAtIndex(int givenIndex) const {
		if (givenIndex >= 0 && givenIndex < this->numberOfRowsPerZone) {
			return rows[givenIndex];
		}
		else {
			return nullptr;
		}
	}


	void returnZone()
	{

		for (int i = 0; i < this->numberOfRowsPerZone; i++)
		{
			if (i / 10 == 0)
			{
				{
					cout << "Row:" << i << " " << " " << " " << " ";
					rows[i]->returnRow();
					cout << endl;
				}
			}
			else
			{
				cout << "Row" << i << " " << " " << " " << " ";
				rows[i]->returnRow();
				cout << endl;
			}
		}
	}
};


inline ostream& operator<<(ostream& console, Zone& auxZone)
{
	//console << endl << "***********************************************************************";
	console << endl << "This zone has type " << " ";
	//enum zoneType { STAND, NORMAL, VIP, CATEGORY, CAMPING, PREMIUM, FAMILY, STUDENT, BACKSTAGE, GREEN, SRO, NETWORKING, GAME, RESTAURANT, BALCONY, AMPHITEATHER };

	switch (auxZone.typeOfZone)
	{
	case STAND:
		console << "STAND. ";
		break;
	case NORMAL:
		console << "NORMAL.";
		break;
	case VIPZ:
		console << "VIP. ";
		break;
	case CATEGORY:
		console << "CATEGORY.";
		break;
	case CAMPING:
		console << " CAMPING. ";
		break;
	case PREMIUMZ:
		console << " PREMIUM. ";
		break;
	case FAMILY:
		console << "FAMILY. ";
		break;
	case STUDENTZ:
		console << " STUDENT. ";
		break;
	case BACKSTAGE:
		console << "BACKSTAGE. ";
		break;
	case GREEN:
		console << "GREEN. ";
		break;
	case SRO:
		console << "SRO. ";
		break;
	case NETWORKING:
		console << "NETWORKING.";
		break;
	case GAME:
		console << "GAME. ";
		break;
	case FOOD:
		console << "FOOD. ";
		break;
	case BALCONY:
		console << " BALCONY. ";
		break;
	case AMPHITHEATER:
		console << "AMPHITHEATER. ";
		break;
	case BOX:
		console << "BOX.";
		break;
	default:
		console << "This type did not exist at the moment of creation. Please, redefine the switch structure.";
	}




	console << endl << "This zone has" << " " << auxZone.numberOfRowsPerZone << " " << "rows.";

	for (int i = 0; i < auxZone.numberOfRowsPerZone; i++)
	{
		console << endl << "This row's identifier is:" << " " << i + 1;
		console << *(auxZone.rows[i]) << endl;
	}
	return console;
}