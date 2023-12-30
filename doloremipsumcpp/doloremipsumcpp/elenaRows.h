#pragma once
#include "elenaSeats.h"
#include<string>
#include<iostream>
#include<fstream>
//exceptions for ROWS
class WrongValueForRows : public exception
{
public:
	WrongValueForRows(string msg) : exception(msg.c_str())
	{

	}

	WrongValueForRows()
	{

	}
};

//****************************************************************************************************

///class ROW
class Row
{
protected:
	int rowIdentifier = 0;
	int seatsNumber = 0;
	int* seats = nullptr;

public:

	Row()
	{

	}
	int const static MAX_NUMBER_OF_SEATS = 15;

	int getNoOfSeats()
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

	int getRowIdentifier() const
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

	Row(int auxRowIdentifier, int auxSeatsNumber)
	{
		this->setNoOfSeats(auxSeatsNumber);
		this->setRowIdentifier(auxRowIdentifier);
	}

	~Row()
	{
		delete[] seats;
	}
};