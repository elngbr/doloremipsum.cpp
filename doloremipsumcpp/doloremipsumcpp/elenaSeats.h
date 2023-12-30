#pragma once
#include<iostream>
#include<string>
#include<fstream>

using namespace std;


enum seatType{STANDARD, WHEELCHAIR, BROKEN, OCCUPIED, CHOSEN };


//exceptions for SEATS
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


//exceptions for ROWS
class WrongValueForRows: public exception
{
public:
	WrongValueForRows(string msg) : exception(msg.c_str())
	{

	}

	WrongValueForRows()
	{

	}
};

///class ROW
class Row
{
protected:
	int rowIdentifier = 0;
	int seatsNumber = 0;
	int* seats = nullptr;
	Row()
	{

	}
public:

	int const static MAX_NUMBER_OF_SEATS = 15;

	int getNoOfSeats() const
	{
		return this->seatsNumber;
	}

	void setNoOfSeats(int auxSeatsNo)
	{
		if (auxSeatsNo > MAX_NUMBER_OF_SEATS)
		{
			throw WrongValueForRows("Too many rows. Such number is not available");
		}
		else if (auxSeatsNo < 0)
		{
			throw WrongValueForRows("You cannot have a row identified by a negative number");
		}
		else throw WrongValueForRows();

		this->seatsNumber = auxSeatsNo;
	}

	int* getSeats()
	{
		int* copy = new int[this->seatsNumber];

		for (int i = 0; i < this->seatsNumber; i++)
		{
			copy[i] = this->seats[i];
		}

		return copy;
	}

	void setSeats(int* auxSeats, int auxSeatsNo)
	{
		if (auxSeats == nullptr)
		{
			throw WrongValueForRows("The seats you inserted are null");

		}
		else if (auxSeatsNo > MAX_NUMBER_OF_SEATS)
		{
			throw WrongValueForRows("Too many rows. Such number is not available");
		}
		else if (auxSeatsNo < 0)
		{
			throw WrongValueForRows("You cannot have a row identified by a negative number");
		}
		else throw WrongValueForRows();

		delete[]this->seats;

		this->seats = new int[auxSeatsNo];

		for (int i = 0; i < auxSeatsNo; i++)
		{
			this->seats[i] = auxSeats[i];
		}

		this->seatsNumber = auxSeatsNo;

	}

	int getRowNo()
	{
		return this->rowIdentifier;
	}

	void setRowIdentifier(int auxIdentifier)
	{
		if (auxIdentifier < Zone::MAX_NO_ROWS_PER_ZONE)
		{
			throw WrongValueForRows("The identifier excedees the number accepted rows by a zone");
		}
		else if (auxIdentifier < 0)
		{
			throw WrongValueForRows("You cannot identify a row by a negatove number");

		}
		this->rowIdentifier = auxIdentifier;
	}

	Row(int auxRowNumber, int auxSeatsNumber)
	{
		this->setNoOfSeats(auxSeatsNumber);
		this->setRowIdentifier(auxRowNumber);
	}

	~Row()
	{
		delete[] seats;
	}
};

//CLASS SEATS
class Seat
{
private:
	int seatNumber = 0;
	seatType type = seatType::STANDARD;

	const Row& rowNumber;

	Seat() : rowNumber(*new Row(0,0))
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
			throw WrongValueForSeat("More seats than allowed!");
		}
		else if (auxNo < 0)
		{
			throw WrongValueForSeat("A seat cannot be negative!");
		}
		else throw WrongValueForSeat();

		this->seatNumber = auxNo;


	}

	int getType()
	{
		return this->type;
	}

	void setType(seatType auxType)
	{
		this->type = auxType;
	}
	int getRowNumber() const
	{
		return rowNumber.getNoOfSeats();
	}
	
	///CONSTRUCTOR
	Seat(int auxSeatNo, seatType auxType, int auxRowNumber, const Row& auxRow): rowNumber(auxRow)
	{
		this->setSeatNumber(auxSeatNo);
		this->setType(auxType);

	}

	Seat(int auxSeatNo, seatType auxType, const Row& auxRow) : seatNumber(auxSeatNo), type(auxType), rowNumber(auxRow)
	{

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