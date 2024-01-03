#pragma once
#pragma once
#include "elenaRows.h"
#include "elenaSeats.h"
#include "elenaZones.h"
#include "elenaLocations.h"
#include "elenaTickets.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

class WrongIssueDate {
private:
	string message;
public:
	WrongIssueDate(const string& msg) : message(msg) {}

	string what()const
	{
		return message;
	}
};
class WrongIdentifierInput {
private:
	string message;
public:
	WrongIdentifierInput(const string& msg) : message(msg) {}

	string what()const
	{
		return message;
	}
};

class Ticket
{
private:
	string ticketID = "";
	char dateOfIssue[9] = "dd/mm/yy"; ///it will follow the standard dd/mm/yy. the previous sequence has 8ch +1 =9

public:
	int static const MIN_TICKET_ID_DIMENSION = 2;
	string getTicket()
	{
		return this->ticketID;
	}

	void setID(string auxTicketId)
	{
		if (auxTicketId[0] < 'A' || auxTicketId[0]>'Z' || auxTicketId.size() < Ticket::MIN_TICKET_ID_DIMENSION)
		{
			throw WrongIdentifierInput("Wrong input date for ticket identifier!");
		}

	}

	char* getDate() const
	{
		char* copy = new char[strlen(this->dateOfIssue) + 1];
		strcpy_s(copy, strlen(this->dateOfIssue) + 1, this->dateOfIssue);

		return copy;



	}
	///also compare with the event date, but not now, after inheritance.
	void setDate(const char* auxDate) {
		if (auxDate == nullptr || auxDate[2] != '/' || auxDate[5] != '/' ||
			(auxDate[0] > '3' && auxDate[1] > '1') ||
			(auxDate[0] == '3' && auxDate[1] > '1') ||
			(auxDate[3] > '1' && auxDate[4] > '2') ||
			(auxDate[3] == '1' && auxDate[4] > '2') ||
			(auxDate[6] < '2') ||
			(auxDate[3] == '0' && auxDate[4] == '2' && (auxDate[0] == '2' && auxDate[1] == '9'))
			)
		{
			throw WrongIssueDate("Wrong input for issue date!");
		}

		strcpy_s(this->dateOfIssue, strlen(auxDate) + 1, const_cast<char*>(auxDate));
	}
};
