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

enum zoneType { STAND, NORMAL, VIPZ, CATEGORY, CAMPING, PREMIUMZ, FAMILY, STUDENTZ, BACKSTAGE, GREEN, SRO, NETWORKING, GAME, FOOD, BALCONY, AMPHITHEATER, BOX };
//SRO-----seating room only

class Row;
class Zone :public Row
{
protected:

	zoneType typeOfZone = NORMAL;
	int numberOfRowsPerZone = 0;
	Row** rows = nullptr;
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
			// Handle error, return nullptr, throw an exception, or handle it according to your design
			return nullptr;
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
	case(0):
		console << "STAND. ";
		break;
	case(1):
		console << "NORMAL.";
		break;
	case(2):
		console << "VIP. ";
		break;
	case(3):
		console << "CATEGORY.";
		break;
	case(4):
		console << " CAMPING. ";
		break;
	case(5):
		console << " PREMIUM. ";
		break;
	case(6):
		console << "FAMILY. ";
		break;
	case(7):
		console << " STUDENT. ";
		break;
	case(8):
		console << "BACKSTAGE. ";
		break;
	case(9):
		console << "GREEN. ";
		break;
	case(10):
		console << "SRO. ";
		break;
	case(11):
		console << "NETWORKING.";
		break;
	case(12):
		console << "GAME. ";
		break;
	case(13):
		console << "FOOD. ";
		break;
	case(14):
		console << " BALCONY. ";
		break;
	case(15):
		console << "AMPHITHEATER. ";
		break;
	case(16):
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