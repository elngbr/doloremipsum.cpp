#pragma once
#include "elenaRows.h"
#include"elenaSeats.h"
#include<string>
#include<iostream>
#include<fstream>

using namespace std;

///a zone IS a collection of rows

class WrongZoneIdentifierException
{
private:
		string message;
public:
	WrongZoneIdentifierException(const string& msg) : message(msg) {}

	string what()const
	{
		return message;
	}
};

enum zoneType{STAND, NORMAL, VIPZ, CATEGORY, CAMPING, PREMIUMZ, FAMILY, STUDENTZ, BACKSTAGE, GREEN, SRO, NETWORKING, GAME, RESTAURANT, BALCONY, AMPHITEATHER};
//SRO-----seating room only



class Zone :public Row 
{
private:
	int zoneIdentifier = 0;
	zoneType typeOfZone = NORMAL;
	int numberOfRowsPerZone = 0;
	int numberOfSeatsPerRowPerZone = 0;
	Row** rows = nullptr;
public:
	int const static MAX_ZONE_IDENTIFIER = 6;
	int getZoneIdentifier()
	{
		return this->zoneIdentifier;
	}

	void setZoneIdentifier(int auxZoneIdentifier)
	{
		if (auxZoneIdentifier < 0)
		{
			throw WrongZoneIdentifierException("An identifier cannot be less than 0.");
		}
		else if (auxZoneIdentifier > Zone::MAX_ZONE_IDENTIFIER)
		{
			throw WrongZoneIdentifierException("A location cannot have more that 6 zones.");
		}
		
		this->zoneIdentifier = auxZoneIdentifier;
	}

	int getNumberOfRowsPerZone()
	{
		return this->numberOfRowsPerZone;
	}

	void setNumberOfRowsPerZone(int auxNumberOfRowsPerZone)
	{
		if (auxNumberOfRowsPerZone < 0)
		{
			throw RowIdentifierException("You cannot have less than 0 rows per zone.");
		}
		else if (auxNumberOfRowsPerZone > Row::MAX_ROW_IDENTIFIER)
		{
			throw RowIdentifierException("You cannot have more than 50 rows per zone.");

		}
		
		this->numberOfRowsPerZone = auxNumberOfRowsPerZone;
	}


	int getNumberOfSeatsPerRowPerZone()
	{
		return this->numberOfSeatsPerRowPerZone;
	}


	void setNumberOfSeatsPerRowPerZone(int auxNumberOfSeatsPerRowPerZone)
	{
		if (auxNumberOfSeatsPerRowPerZone < 0)
		{
			throw SeatException("A row cannot have less than 0 seats.");
		}
		else if (auxNumberOfSeatsPerRowPerZone > Seat::MAX_IDENTIFIER_OF_SEAT)
		{
			throw SeatException("A row cannot have more than seats.");

		}
		

		this->numberOfSeatsPerRowPerZone = auxNumberOfSeatsPerRowPerZone;

	}

	////////////////////////////DO NOT MAKE A GETTER FOR A TYPE 

	void setType(zoneType auxType)
	{
		this->typeOfZone = auxType;
	}


	void initializeRows() {
		rows = new Row * [this->numberOfSeatsPerRowPerZone];
		for (int i = 0; i < numberOfSeatsPerRowPerZone; ++i) {
			rows[i] = nullptr;
		}
	}
	void addRows(int auxRowIdentifier,Seat auxRow)
	{

		Row** newRows = new Row * [this->numberOfSeatsPerRowPerZone + 1];
		for (int i = 0; i < this->numberOfSeatsPerRowPerZone; i++)
		{
			newRows[i] = this->rows[i];
		}

		newRows[this->numberOfSeatsPerRowPerZone] = new Row(auxRowIdentifier,auxRow);

		delete[] this->rows;
		this->rows = newRows;
		this->numberOfSeatsPerRowPerZone++;
	}


	/*Zone(int auxZoneIdentifier, Row auxRow)
		: zoneIdentifier(auxZoneIdentifier), numberOfSeatsPerRowPerZone(auxRow.getNoOfSeatsForRow())
	{

		initializeRows();
		rows[0] = &auxRow;
	}*/

	Zone( Row auxRow)
		
	{

		initializeRows();
		rows[0] = &auxRow;
		this->numberOfRowsPerZone++;
		this->numberOfSeatsPerRowPerZone = auxRow.getNoOfSeatsForRow();
	}

	/*Zone() :Row(STANDARD)
	{

	}*/

	Zone()
	{

	}

	friend ostream& operator<<(ostream& console, Zone& auxZone);
};


ostream& operator<<(ostream& console, Zone& auxZone)
{

	console << endl << "This zone has identifier" << " " << auxZone.zoneIdentifier;
	console << endl << "This zone has " << " " << auxZone.numberOfRowsPerZone<<" "<<"rows.";
	console << endl << "This zone has " << " " << auxZone.numberOfSeatsPerRowPerZone << " " << "row.";

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
		console << "RESTAURANT, BALCONY, AMPHITEATHER zone";
		break;
	case(14):
		console << " BALCONY  zone";
		break; 
	case(15):
		console << "AMPHITEATHER zone";
		break;
	}
	


	for (int i = 0; i < auxZone.numberOfRowsPerZone; i++)
	{
		console << endl << (*auxZone.rows[i]);
	}
	return console;

}
