#pragma once
#pragma once

#include "elenaRows.h"
#include "elenaSeats.h"
#include "elenaZones.h"
#include "elenaLocations.h"
#include "elenaEvents.h"
#include "elenaTickets.h"
#include "OverloadedF.h"
#include "OverloadedF1.h"
#include "TicketIDGenerator.h"

#include"elenaTicketReport.h"

#include<string>
#include<iostream>
#include<fstream>
using namespace std;


class FileUtils {
public:

	static void generateReport(TicketReport& auxTicketReport, string fileName)
	{
		ofstream report(fileName, ios::ate);

		if (!report.is_open())
		{
			cout << endl << "The file does NOT open for the raport generator!";
		}

		auxTicketReport.generateReport(report);

		report.close();
	}


	static void backup(TicketReport& auxTicketReport, string fileName)
	{
		ofstream file(fileName, ios::binary | ios::ate);

		if (!file.is_open())
		{
			cout << endl << "The file does not open for backup!";
		}

		auxTicketReport.serializeTicketReport(file);

		file.close();

	}



	static void restore(TicketReport& auxTicketReport, string fileName)
	{
		ifstream file(fileName, ios::binary);

		if (!file.is_open())
		{
			cout << endl << "The file does not open for restore!";
		}


		auxTicketReport.deserializeTicketReport(file);

		file.close();
	}
};
