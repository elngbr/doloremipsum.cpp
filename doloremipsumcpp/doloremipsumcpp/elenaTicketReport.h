#pragma once

#include "elenaRows.h"
#include "elenaSeats.h"
#include "elenaZones.h"
#include "elenaLocations.h"
#include "elenaEvents.h"
#include "elenaTickets.h"
#include "OverloadedF.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;


class TicketReport
{
protected:
	Ticket** tickets = nullptr;
	int numberOfTickets = 0;
public:

	int getNumberOfTickets()
	{
		return this->numberOfTickets;
	}

	void addTickets(Ticket auxTicket)
	{
		Ticket** newTickets = new Ticket * [this->numberOfTickets + 1];
		for (int i = 0; i < this->numberOfTickets; i++)
		{
			newTickets[i] = this->tickets[i];
		}

		newTickets[this->numberOfTickets] = new Ticket(auxTicket);
		delete[]this->tickets;
		this->tickets = newTickets;
		this->numberOfTickets++;
	}
	//good
	void generateReport(ofstream& report)
	{
		if (!report.is_open())
		{
			cout << endl << "The report does not open!";
		}

		report << "\t \t Tickets report.";
		report << endl << "No of tickets:" << this->numberOfTickets << endl;

		for (int i = 0; i < this->numberOfTickets; i++)
		{
			report << endl << "Ticket" << " " << i + 1;
			report << *this->tickets[i];
		}
	}
	//good
	void serializeTicketReport(ofstream& file)
	{
		file.write((char*)&this->numberOfTickets, sizeof(int));
		for (int i = 0; i < this->numberOfTickets; i++)
		{
			this->tickets[i]->serializeTickets(file);
		}
	}
	//good
	void deserializeTicketReport(ifstream& file)
	{
		for (int i = 0; i < this->numberOfTickets; i++)
		{
			delete this->tickets[i];
		}

		delete[] this->tickets;


		file.read((char*)&this->numberOfTickets, sizeof(int));


		this->tickets = new Ticket * [this->numberOfTickets];
		for (int i = 0; i < this->numberOfTickets; i++)
		{
			this->tickets[i] = new Ticket();
			this->tickets[i]->deserializeTickets(file);
		}
	}
	inline friend ostream& operator<<(ostream& console, TicketReport& auxReport);
};

inline ostream& operator<<(ostream& console, TicketReport& auxReport)
{
	console << endl << "Report ADMIN";
	console << endl << "This report has" << " " << auxReport.numberOfTickets << " " << "tickets.";

	for (int i = 0; i < auxReport.numberOfTickets; i++)
	{
		console << endl << "Ticket" << " " << i + 1;
		console << *(auxReport.tickets[i]);
	}

	return console;
}