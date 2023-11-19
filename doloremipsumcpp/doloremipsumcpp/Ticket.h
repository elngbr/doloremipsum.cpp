#pragma once
#include<iostream>
#include<string>
using namespace std;



//enum typeOfPlace { STADIUM, CONCERT_HALL, OPERA_HOUSE, EVENTS_HALL, SPORT_HALL, CINEMA_HALL, SQUARE };
//enum typeOfEvent { CONCERT, FOOTBALL, THEATRE, FILM, CHARITY, FAIR, PROTEST };
enum typeOfTicket { VIP, LAWN, TRIBUNE, BOXES, STAND1, STAND2, CATEGORY1, CATEGORY2 }; ///also type of zone OR NOT?



class Ticket {
private:  //could be by default

	double static Id_COUNTER;
	int static NO_OF_TICKETS;
	double ticketId = 0.0;
	typeOfTicket type = typeOfTicket::BOXES;
	char* dateOfIssue = nullptr;     ///IT IS A REQUIREMENT THAT THE DATE WILL BE ONLY INTRODUCED IN THE FOLLOWING FORMAT:    DD/MM/YY


public:

	double getId()
	{
		return this->ticketId;
	}

	typeOfTicket getType()
	{
		return this->type;
	}

	void setTypeOfTicket(typeOfTicket auxType)
	{
		this->type = auxType;
	}

	char* getDateOfIssue()
	{
		char* copy = new char[strlen(this->dateOfIssue) + 1];
		strcpy_s(copy, strlen(this->dateOfIssue) + 1, this->dateOfIssue);

		return copy;
	}


	void setDateOfIssue(const char* auxDate)   ///all tickets can be issued in 2024
	{
		if (auxDate == nullptr ||
			auxDate[2] != '/' ||
			auxDate[5] != '/' ||
			(auxDate[0] != '0' && auxDate[0] != '1' && auxDate[0] != '2' && auxDate[0] != '3') ||
			(auxDate[3] != '0' && auxDate[3] != '1') ||
			((auxDate[3] == '0' && (auxDate[4] > '9' || auxDate[4] < '0')) || (auxDate[3] == '1' && (auxDate[4] > '2' || auxDate[4] < '0'))) ||
			auxDate[6] != '2' ||
			auxDate[7] != '4')
		{
			throw exception("Wrong input! All tickets can be issued in 2024!");
		}

		delete[]this->dateOfIssue;
		this->dateOfIssue = new char[strlen(auxDate) + 1];

		strcpy_s(this->dateOfIssue, strlen(auxDate) + 1, const_cast<char*>(auxDate));
		this->dateOfIssue[strlen(this->dateOfIssue)] = '\0';

	}

	//Default Constructor

	Ticket() : ticketId(++Id_COUNTER)
	{

		NO_OF_TICKETS++;
	}


	///CTOR WITH AT LEAST ONE PARAMETER
	Ticket(typeOfTicket auxType, const char* auxDateOfIssue) :ticketId(++Id_COUNTER)
	{
		this->setTypeOfTicket(auxType);
		this->setDateOfIssue(auxDateOfIssue);
		NO_OF_TICKETS++;
	}

	///DESTRUCTOR
	~Ticket()
	{
		delete[]this->dateOfIssue;
		NO_OF_TICKETS--;
	}

	//CPY-CONSTRUCTOR

	/*Ticket(Ticket& ticket) :ticketId(++ID_COUNTER)
	{
		this->setDateOfIssue(ticket.getDateOfIssue());
		this->setTypeOfTicket(ticket.getType());
		NO_OF_TICKETS++;
	}
	*/

	Ticket(const Ticket& ticket) : ticketId(++Id_COUNTER)
	{
		
		this->type = ticket.type;

		
		this->dateOfIssue = new char[strlen(ticket.dateOfIssue) + 1];
		strcpy_s(this->dateOfIssue, strlen(ticket.dateOfIssue) + 1, ticket.dateOfIssue);

		NO_OF_TICKETS++;
	}


	friend void operator<<(ostream& console, const Ticket& ticket);


	///INDEXING OPERATOR

	/*char& operator[](int index)
	{

		if (index < 0 || index>8 )
		{
			return;
		}

		return this->dateOfIssue[index];

		
	}
	*/
	char& operator[](int index)
	{
		if (index < 0 || index > 8)
		{
			
			throw exception ("Index out of bounds");
		}

		return this->dateOfIssue[index];
	}


	Ticket operator+(double value)
	{
		Ticket copy = *this;
		copy.ticketId += value;

		return copy;
	}

	Ticket& operator=(const Ticket& auxTicket)
	{
		if (&auxTicket == this)///dereferentiere
		{
			return *this;
		}

		delete[]this->dateOfIssue;
		this->dateOfIssue = auxTicket.dateOfIssue;


		return *this;
	}

	bool operator == (const Ticket& auxTicket )
	{
		return (strcmp(this->dateOfIssue, auxTicket.dateOfIssue) == 0); ////////////////////MEREU COMPARA CU 0!!!!!!
	}

	bool operator!()
	{
		if (this->type != 0)
		{
			return true;
		}

		else
		{
			return false;
		}

	}


	bool operator>(typeOfTicket value)
	{
		if (this->type > value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator<(char number)
	{
		if (this->dateOfIssue[7] > number)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	explicit operator double()
	{
		return this->ticketId;
	}
};

Ticket operator+(double value, Ticket auxTicket)
{
	return auxTicket+value;
}

int Ticket::NO_OF_TICKETS=0;
double Ticket::Id_COUNTER=-1;

void operator<<(ostream& console, const Ticket& ticket)
{
	//console << "This is a ticket that allows you to go to the" <<" " << ticket.type;
	console << endl << "This ticket is uniquely defined by the Id" << " " << ticket.ticketId;
	console << endl << "This ticket was issued at this date: " << ticket.dateOfIssue;
	console << endl << "This is a ticket that allows you to go to the" << " ";

	switch (ticket.type)/////////////////////IF U RETURNED INSTEAD OF DISPLAYING WITH CONSOLE, YOU NEED'NT USE BREAK. BUT WE NEVER NEVER NEVER RETURN IN A VOID :)
	{
	case VIP:
		console << "Vip";
		break;
	case LAWN:
		console << "Lawn";
		break;
	case CATEGORY1:
		console << "Category 1";
		break;
	case CATEGORY2:
		console << "Category 2";
		break;
	case BOXES:
		console << "Boxes";
		break;
	case STAND1:
		console << "Stand 1";
		break;
	case STAND2:
		console << "Stand 2";
		break;
	case TRIBUNE:
		console << "Tribune";
		break;
	default:
		console << "Unrecognizable type of ticket!";
		break;

	}

	console << endl;

}