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

enum zoneType { STAND, NORMAL, VIPZ, CATEGORY, CAMPING, PREMIUMZ, FAMILY, STUDENTZ, BACKSTAGE, GREEN, SRO, NETWORKING, GAME, FOOD, BALCONY, AMPHITHEATER };
//SRO-----seating room only

class Row;
class Zone :public Row
{
private:

	zoneType typeOfZone = NORMAL;
	int numberOfRowsPerZone = 0;
	Row** rows = nullptr;
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
	}

	Zone(zoneType auxType)
	{
		this->setType(auxType);
	}

	friend inline ostream& operator<<(ostream& console, Zone& auxZone);

	zoneType getType() const
	{
		return this->typeOfZone;
	}

};


inline ostream& operator<<(ostream& console, Zone& auxZone)
{
	console << endl << "***********************************************************************";
	console << endl << "This zone has type " << " ";
	//enum zoneType { STAND, NORMAL, VIP, CATEGORY, CAMPING, PREMIUM, FAMILY, STUDENT, BACKSTAGE, GREEN, SRO, NETWORKING, GAME, RESTAURANT, BALCONY, AMPHITEATHER };

	switch (auxZone.typeOfZone)
	{
	case(0):
		console << "Stand zone";
		break;
	case(1):
		console << "NORMAL zone";
		break;
	case(2):
		console << "VIP zone";
		break;
	case(3):
		console << "CATEGORY zone";
		break;
	case(4):
		console << " CAMPING zone";
		break;
	case(5):
		console << " PREMIUM zone";
		break;
	case(6):
		console << "FAMILY zone";
		break;
	case(7):
		console << " STUDENT zone";
		break;
	case(8):
		console << "BACKSTAGE zone";
		break;
	case(9):
		console << "GREEN zone";
		break;
	case(10):
		console << "SRO zone";
		break;
	case(11):
		console << "NETWORKING zone";
		break;
	case(12):
		console << "GAME zone";
		break;
	case(13):
		console << "FOOD zone";
		break;
	case(14):
		console << " BALCONY  zone";
		break;
	case(15):
		console << "AMPHITEATHER zone";
		break;
	}


	console << endl << "This zone has" << " " << auxZone.numberOfRowsPerZone << " " << "rows";

	/*for (int i = 0; i < auxZone.numberOfRowsPerZone; i++)
	{
		console << endl << "This row's identifier is:" << " " << i + 1;
		console << *(auxZone.rows[i]) << endl;
	}*/
	return console;
}