#pragma once
#include<iostream>
#include "elenaRows.h"
#include<string>
#include<fstream>

using namespace std;


enum seatType{STANDARD, WHEELCHAIR, BROKEN, OCCUPIED, CHOSEN };

class Row;

////exceptions for SEATS
//class WrongValueForSeat : public exception
//{
//public:
//	WrongValueForSeat(string msg) : exception(msg.c_str())
//	{
//
//	}
//
//	WrongValueForSeat()
//	{
//
//	}
//};




//CLASS SEATS
class Seat
{
private:
	int seatNumber = 0;
	seatType type = seatType::STANDARD;


	const Row& rowIdentifier;


	Seat() : rowIdentifier(*new Row(0, 0))
	{

	}
public:


	
	int getSeatNumber() const
	{
		return this->seatNumber;
	}

	void setSeatNumber(int auxNo)
	{
		if (auxNo > Row::MAX_NUMBER_OF_SEATS)
		{
			throw exception("More seats than allowed!");
		}
		else if (auxNo < 0)
		{
			throw exception("A seat cannot be negative!");
		}
		else throw exception();

		this->seatNumber = auxNo;


	}

	int getType() const
	{
		return this->type;
	}

	void setType(seatType auxType)
	{
		this->type = auxType;
	}
	int getRowIdentifier() const
	{
		return rowIdentifier.getRowIdentifier();

	}


	
	
	///CONSTRUCTOR
	Seat(int auxSeatNo, seatType auxType, const Row& auxRow) : rowIdentifier(auxRow) 
	{
		this->setSeatNumber(auxSeatNo);
		this->setType(auxType);

	}

	
};



class Zone
{
protected:
	string* zoneName = nullptr;
	int rowsNumber = 0;
	int* rows = 0;
	Zone()
	{

	}
public:
	int static const MAX_NO_ROWS_PER_ZONE = 50;
};

//class Location
//{
//protected:
//	int noZones = 0;
//	string* zones=nullptr;
//	string* locationName = nullptr;
//	Location()
//	{
//
//	}
//public:
//};
//
//class Ticket
//{
//protected:
//	int ticketId = 0;
//	//Seat seatNumber;  
//	Ticket()
//	{
//
//	}
//public:
//
//
//};