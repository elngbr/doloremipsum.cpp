#pragma once
#include<iostream>
#include<string>
#include<fstream>

using namespace std;


enum seatType{STANDARD, WHEELCHAIR, BROKEN, OCCUPIED, CHOSEN };

class WrongValueForSeat : public exception
{
public:
	WrongValueForSeat(string msg) : exception(msg.c_str())
	{

	}

	WrongValueForSeat()
	{

	}
};
class Seat
{
protected:
	int seatNumber = 0;
	seatType type = seatType::STANDARD;

	Seat()
	{

	}
public:
	Seat(int auxNo, seatType auxType)
	{

	}

	int getSeatNumber()
	{
		return this->seatNumber;
	}

	void setSeatNumber(int auxNo)
	{
		if (auxNo > Row::MAX_NUMBER_OF_SEATS)
		{
			throw WrongValueForSeat("More seats than allowed!");
		}
		else if (auxNo < 0)
		{
			throw WrongValueForSeat("A seat cannot be negative!");
		}
		else throw WrongValueForSeat();


	}
};

class Row
{
protected:
	int seatsNumber = 0;
	int* seats = nullptr;
	Row()
	{

	}
public:

	int const static MAX_NUMBER_OF_SEATS = 15;
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
};

class Location
{
protected:
	int noZones = 0;
	string* zones=nullptr;
	string* locationName = nullptr;
	Location()
	{

	}
public:
};

class Ticket
{
protected:
	int ticketId = 0;
	//Seat seatNumber;  
	Ticket()
	{

	}
public:


};