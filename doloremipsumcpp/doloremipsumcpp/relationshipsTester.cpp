

#include "elenaRows.h"
#include "elenaSeats.h"
#include "elenaZones.h"
#include "elenaLocations.h"
#include "elenaEvents.h"
#include "elenaTickets.h"
#include "elenaReportGenerator.h"
#include "elenaTicketReport.h"
#include "OverloadedF.h"
#include "OverloadedF1.h"
#include "TicketIDGenerator.h"

#include<string>
#include<iostream>
#include<fstream>
using namespace std;




int main()

{
	//char* uniqueIdentifiers = nullptr;
	int counter = 0;

	Seat standardSeat(STANDARD);
	Seat wheelchairSeat(WHEELCHAIR);
	Seat brokenseat(BROKEN);
	Seat occupiedSeat(OCCUPIED);
	Seat chosenSeat(CHOSEN);
	Seat studentSeat(STUDENT);
	Seat childrenSeat(CHILDREN);
	Seat coupleSeat(COUPLE);
	Seat flexibleSeat(FLEXIBLE);
	Seat vipSeat(VIP);
	Seat premiumSeat(PREMIUM);
	Seat beanbagSeat(BEANBAG);
	Seat virtualSeat(VIRTUAL);


	///creating a normal row with: 
	//first 5 seats=STANDARD,
	//the 6th OCCUPIED,
	//THE 7th STUDENT,
	//the 8th BROKEN,
	//the 9th&10th STUDENT,
	//11th&12th&13th STANDARD
	//the 14th OCCUPIED
	//the 15th CHILDREN

	Row normalRow;///////The best row to add anywhere, a combo of them all
	Row standardRow;///Creating a standard row full of standard seats
	Row studentRowWithWheelchair;//Creating a student row with 11 student seats and 4 wheelchairs
	Row studentRow;//full of student rows
	Row vipRow; //full of VIP
	Row premiumRow;//full of premium
	Row coupleRow;//full of couple
	Row beanbagRow;///full of beanbags
	Row vipWithWheelchairRow;
	Row premiumRowWithWheelchair;
	Row childrenRowWithStandardAndWheelchair;
	Row flexibleRow;
	Row virtualRow;

	normalRow.addSeats(standardSeat); //1st row
	normalRow.addSeats(standardSeat);
	normalRow.addSeats(standardSeat);
	normalRow.addSeats(standardSeat);
	normalRow.addSeats(standardSeat);
	normalRow.addSeats(occupiedSeat);
	normalRow.addSeats(studentSeat);
	normalRow.addSeats(brokenseat);
	normalRow.addSeats(studentSeat);
	normalRow.addSeats(studentSeat);
	normalRow.addSeats(standardSeat);
	normalRow.addSeats(wheelchairSeat);
	normalRow.addSeats(wheelchairSeat);
	normalRow.addSeats(occupiedSeat);
	normalRow.addSeats(childrenSeat);




	///->>here with the overloaded function
	addSeats(standardRow, 15, standardSeat);
	addSeats(studentRowWithWheelchair, 12, studentSeat, Row::MAX_NUMBER_OF_SEATS, wheelchairSeat);
	addSeats(studentRow, Row::MAX_NUMBER_OF_SEATS, studentSeat);
	addSeats(vipRow, Row::MAX_NUMBER_OF_SEATS, vipSeat);
	addSeats(premiumRow, Row::MAX_NUMBER_OF_SEATS, premiumSeat);
	addSeats(coupleRow, Row::MAX_NUMBER_OF_SEATS, coupleSeat);
	addSeats(beanbagRow, 5, beanbagSeat, 10, wheelchairSeat, Row::MAX_NUMBER_OF_SEATS, beanbagSeat);
	addSeats(vipWithWheelchairRow, 10, vipSeat, Row::MAX_NUMBER_OF_SEATS, wheelchairSeat);
	addSeats(premiumRowWithWheelchair, 7, wheelchairSeat, Row::MAX_NUMBER_OF_SEATS, premiumSeat);
	addSeats(childrenRowWithStandardAndWheelchair, 4, childrenSeat, 7, wheelchairSeat, 8, chosenSeat, Row::MAX_NUMBER_OF_SEATS, standardSeat);
	addSeats(flexibleRow, 15, flexibleSeat);
	addSeats(virtualRow, 4, virtualSeat, 7, wheelchairSeat, 8, virtualSeat, Row::MAX_NUMBER_OF_SEATS, wheelchairSeat);

	// *********************************************************************************************************************************************


	Zone standZone(STAND); ////standard, standardwithwhellchair, students
	Zone normalZone(NORMAL);
	Zone vipZone(VIPZ);
	Zone categoryZone(CATEGORY);
	Zone boxZone(NORMAL);


	///Insertions of rows in zones**********************************************************************************************************************







	addRows(standZone, 3, standardRow, 7, normalRow, Zone::MAX_ROW_IDENTIFIER_PER_ZONE, standardRow);
	addRows(normalZone, Zone::MAX_ROW_IDENTIFIER_PER_ZONE, normalRow);
	addRows(boxZone, Zone::MAX_ROW_IDENTIFIER_PER_ZONE, normalRow);
	addRows(vipZone, 6, vipWithWheelchairRow, Zone::MAX_ROW_IDENTIFIER_PER_ZONE, vipRow);
	addRows(categoryZone, 6, normalRow, Zone::MAX_ROW_IDENTIFIER_PER_ZONE, standardRow);





	///Insertions of rows in zones****************************************************************************END





	//************************************************************************************************************************************
	///requested
	Location stadiumLocation(STADIUM);
	Location cinemaHallLocation(CINEMA_HALL);
	Location theatreLocation(THEATRE);



	////Insertions for zones in Locations*************************************************************************************************************





	addZones(stadiumLocation, 2, standZone);//requested
	addZones(cinemaHallLocation, 1, normalZone, 2, vipZone);//requested
	addZones(theatreLocation, 2, categoryZone, 3, boxZone);//requested








	////Insertions for zones in Locations*************************************************************************************************************END



	/////*************************************************************************************************************************************************

	/*Event event("Cupa Romaniei");
	event.addLocations(stadiumLocation);
	event.addLocations(stadiumLocation);

	addLocations(event, 1, stadiumLocation, 2, publicInstitutionLocation);

	cout << event;*/





	///requested events
	Event EURO2024("EURO2024", "14/06/24");
	Event Filantropica("Filantropica", "01/04/25");
	Event Straini_in_noapte("Straini in noapte", "03/07/26");


	//requested locations
	EURO2024.addLocations(stadiumLocation);
	Filantropica.addLocations(cinemaHallLocation);
	Straini_in_noapte.addLocations(theatreLocation);





	//cout << EURO2024;
	//cout << Filantropica;
	//cout << Straini_in_noapte;

	//int asciiCode = 65;  // ASCII code for 'A'
	//char character = static_cast<char>(65);

	// Print the result
	//cout << "ASCII Code: " << asciiCode << ", Character: " << character << endl;


	/*Row c;

	c.addSeats(Seat(SeatType::STANDARD));
	c.addSeats(Seat(SeatType::STANDARD));
	c.addSeats(Seat(SeatType::STANDARD));
	c.addSeats(Seat(SeatType::STANDARD));
	c.addSeats(Seat(SeatType::STANDARD));


	cout << c;*/


	/*Seat* x=normalRow.getSeatAtIndex(3);
	cout << *x;

	Row* y = standZone.getRowAtIndex(4);
	cout << *y;*/

	/*SeatType u = normalRow.getSeatAtIndex(3)->getType();
	cout << u;

	Seat* k = normalZone.getRowAtIndex(4)->getSeatAtIndex(5);
	cout << *k;*/

	/*Seat* j = Filantropica.getLocationAtIndex(0)->getZoneAtIndex(0)->getRowAtIndex(5)->getSeatAtIndex(8);
	cout << *j;

	SeatType u = normalRow.getSeatAtIndex(3)->getType();
	SeatType m = normalRow.getSeatAtIndex(7)->getType();

	cout << endl<< u;
	cout <<endl<< m;

	u = m;
	cout << endl << u;*/


	//char* e = Filantropica.getDate();

	//cout << e;  //merge

	/*Location* r = Filantropica.getLocationAtIndex(0);
	cout << *r;*/
	//string as = "C9898";

	//Ticket ticket(as, "13/11/2024", "Filantropica", "01/04/25", 0, 0, 0, 0); ////this shall not exist. the ticket was issued AFTER THE EVENT OCCURED

	//cout << ticket;   //merge

	//Ticket rrt("F77", "13/11/2024", Filantropica);
	//addLocationZoneRowSeat(rrt, 0, 2, 14, 0, Filantropica);
	//cout << rrt;

	int numberOfRowsPerZone = Filantropica.getLocationAtIndex(0)->getZoneAtIndex(0)->getNumberOfRowsPerZone();
	int numberOfSeatsPerRow = Filantropica.getLocationAtIndex(0)->getZoneAtIndex(0)->getRowAtIndex(0)->getNoOfSeatsForRow();

	//cout << numberOfSeatsPerRow;

	//addLocationZoneRowSeat(rrt, 0, 2, 11, 14, Filantropica, numberOfRowsPerZone, numberOfSeatsPerRow);

	//cout << rrt;
	//int value = 9;
	//rrt.extendTicketIdentifier(to_string(rrt.getRowIdentifier()));
	//cout << rrt;

	//cout<< to_string(rrt.getRowIdentifier());

	/*generateTicketId(rrt, counter);
	cout << rrt;

	generateTicketId(rrt, counter);
	cout << rrt;

	generateTicketId(rrt, counter);
	cout << rrt;

	generateTicketId(rrt, counter);
	cout << rrt;

	generateTicketId(rrt, counter);*/
	//cout << rrt;

	////////////////////////////////////////////////////////////////////////////////////////THIS IS HOW YOU PROPERLY CREATE A TICKET
	//Ticket newTicket("12/06/28", Filantropica);
	//createTicketWithDetails(newTicket, Filantropica, 0, 1, 4, 8, counter);
	////////////////////////////////////////////////////////////////////////////////////////THIS IS HOW YOU PROPERLY CREATE A TICKET

	//cout << newTicket;

	/*zoneType x = Filantropica.getLocationAtIndex(0)->getZoneAtIndex(1)->getType();
	cout << x;*/

	/*Zone* ticketZone = Filantropica.getLocationAtIndex(newTicket.getLocationIdentifier())->getZoneAtIndex(newTicket.getZoneIdentifier());

	cout << *ticketZone;*/   ///THIS THING WORKS ON MAIN STACK

	/*Ticket w("12/08/25", Straini_in_noapte);

	createTicketWithDetails(w, Straini_in_noapte, 0, 2, 5, 8, counter);*/

	//cout << w;

	//cout << strcmp("14/06/2024", "15/06/2024");
	//cout << strcmp("14/06/2024", "14/07/2024");
	//cout << strcmp("14/06/2024", "14/06/2028");

	/*try
	{
		Ticket elenaT("15/08/2024", Filantropica);
	}
	catch (WrongIssueDate e)
	{
		cout << endl << e.what();
	}*/  //////////////////////////////////////////////////Deci try catch NU merge cu constructorul, oricare ar fie el :(

	//Ticket elenaT("15/04/2024", Filantropica);
	//cout << strcmp("14/06/2024", "15/04/2024");                         DECI NU POT SA COMPAR ASA DOUA DATE CALENDARISTICE



	/*cout << endl;
	cout << " "<<" " << " " << " " << vipSeat.returnSeat();
	cout << " "<<" " << " " << " " << vipSeat.returnSeat();
	cout << " "<<" " << " " << " " << vipSeat.returnSeat();
	cout << " "<<" " << " " << " " << vipSeat.returnSeat();
	cout << " "<<" " << " " << " " <<standardSeat.returnSeat();
	cout << " "<<" " << " " << " " << vipSeat.returnSeat();
	cout << " "<<" " << " " << " " << vipSeat.returnSeat();
	cout << " "<<" " << " " << " " << vipSeat.returnSeat();
	cout << " "<<" " << " " << " " << vipSeat.returnSeat();
	cout << " "<<" " << " " << " " << vipSeat.returnSeat();
	cout << " "<<" " << " " << " " << vipSeat.returnSeat();
	cout << " "<<" " << " " << " " << vipSeat.returnSeat();
	cout << " "<<" " << " " << " " << vipSeat.returnSeat();
	cout << " "<<" " << " " << " " << vipSeat.returnSeat();
	cout << " "<<" " << " " << " " << vipSeat.returnSeat();*/


	//normalRow.returnRow();

	/*string ceva = "Elena";
	ceva += " Eftimie";

	cout << ceva;*/

	//normalZone.returnZone();

	//cinemaHallLocation.returnLocation();

	/*Filantropica.returnEvent();
	Straini_in_noapte.returnEvent();
	EURO2024.returnEvent();*/












	Ticket t("13/02/2024", Filantropica);
	createTicketWithDetails(t, Filantropica, 0, 1, 3, 5, counter);
	t.setClientFirstName("Nae");
	t.setClientLastName("Carafil");
	Ticket newTicket("12/06/24", Filantropica);
	createTicketWithDetails(newTicket, Filantropica, 0, 1, 4, 8, counter);
	newTicket.setClientFirstName("Gheorghe");
	newTicket.setClientLastName("Dinica");
	Ticket w("12/08/25", Straini_in_noapte);
	createTicketWithDetails(w, Straini_in_noapte, 0, 2, 5, 8, counter);
	w.setClientFirstName("Florin");
	w.setClientLastName("Piersic");
	Ticket v("12/08/24", Straini_in_noapte);
	createTicketWithDetails(v, Straini_in_noapte, 0, 2, 9, 8, counter);
	v.setClientFirstName("Medeea");
	v.setClientLastName("Marinescu");
	Ticket ticket1("12/01/24", EURO2024);
	createTicketWithDetails(ticket1, EURO2024, 0, 1, 9, 8, counter);
	ticket1.setClientFirstName("Dorinel");
	ticket1.setClientLastName("Munteanu");
	Ticket ticket2("12/01/24", EURO2024);
	createTicketWithDetails(ticket2, EURO2024, 0, 1, 7, 5, counter);
	ticket2.setClientFirstName("Gheorghe");
	ticket2.setClientLastName("Hagi");
	Ticket ticket3("12/01/24", EURO2024);
	createTicketWithDetails(ticket3, EURO2024, 0, 1, 4, 2, counter);
	ticket3.setClientFirstName("Ilie");
	ticket3.setClientLastName("Dumitrescu");
	Ticket ticket4("12/01/24", EURO2024);
	createTicketWithDetails(ticket4, EURO2024, 0, 1, 1, 2, counter);
	ticket4.setClientFirstName("Gica");
	ticket4.setClientLastName("Popescu");
	Ticket ticket5("12/01/24", EURO2024);
	createTicketWithDetails(ticket5, EURO2024, 0, 1, 4, 9, counter);
	ticket5.setClientFirstName("Viorel");
	ticket5.setClientLastName("Moldovan");
	Ticket ticket6("12/01/24", Filantropica);
	createTicketWithDetails(ticket6, Filantropica, 0, 1, 4, 9, counter);
	ticket6.setClientFirstName("Olga");
	ticket6.setClientLastName("Tudorache");

	TicketReport mainReport;


	mainReport.addTickets(t);
	mainReport.addTickets(newTicket);
	mainReport.addTickets(v);
	mainReport.addTickets(w);
	mainReport.addTickets(ticket1);
	mainReport.addTickets(ticket2);
	mainReport.addTickets(ticket3);
	mainReport.addTickets(ticket4);
	mainReport.addTickets(ticket5);
	mainReport.addTickets(ticket6);



	FileUtils::generateReport(mainReport, "MAIN REPORT 1.txt");

	//FileUtils::backup(mainReport, "MAIN REP 1.txt");

	/*ofstream file("test.bin", ios::binary);
	ticket1.serializeTickets(file);
	file.close();*/
	//FileUtils::restore(mainReport, "MAIN REPORT 1.txt");


	cout << endl << "Menu:";
	cout << endl << "Hello! Do you want to start the app?" << endl << "If yes, write doloremipsum.cpp";
	char response[30];
	cout << endl << "Your response:";
	cin >> response;

	if (strcmp(response, "doloremipsum.cpp") == 0)
	{
		cout << endl << "You have started the app! Please, open the console in FULL SCREEN mode!";

		cout << "Are you an user or the administrator? If user, then type 0. Otherwise, type 1";
		int userOrAdmin = -1;
		cout << endl << "Your answer:"; cin >> userOrAdmin;

		switch (userOrAdmin)
		{
		case 0:
		{
			cout << endl << "Hello user! The following events are available";
			cout << endl << Filantropica.getEventName() << " " << "on" << " " << Filantropica.getDate();
			cout << endl << EURO2024.getEventName() << " " << "on" << " " << EURO2024.getDate();
			cout << endl << Straini_in_noapte.getEventName() << " " << "on" << " " << Filantropica.getDate();

			cout << endl << "\n\n\n\nWhich one would you like to buy a ticket for? Insert a number:";
			cout << endl << "1->Film: Filantropica";
			cout << endl << "2->Fotball event: EURO2024";
			cout << endl << "3->Theatre: Straini in noapte";
			cout << endl << "Your response:";
			int number;
			cin >> number;

			cout << endl << "The map for your event:";
			switch (number)
			{
			case 1:
			{
				Filantropica.returnEvent();
				Ticket testTicket("09/01/2024", Filantropica);
				Seat::givePricesOfSeats();

				int locationId = -1;
				int zoneId = -1;
				int rowId = -1;
				int seatId = -1;
				while (true)
				{
					try
					{
						cout << endl << " Customize your ticket! Please insert the location UNIQUE identifier from the map. ";
						cout << endl;
						cout << endl;
						cout << endl;
						cout << endl;
						//Seat::givePricesOfSeats();
						//int locationId = -1;
						cout << endl << "Your response:";
						cin >> locationId;
						testTicket.setLocationIdentifier(locationId, Filantropica);
						break;
					}
					catch (WrongLocationIdentifier e)
					{
						cout << endl << e.what();
					}

				}

				while (true)
				{
					try {

						cout << endl << "Please insert the UNIQUE zone identifier from the map";
						//int zoneId = -1;
						cout << endl << "Your response:";
						cin >> zoneId;
						testTicket.setZoneIdentifier(zoneId, Filantropica);
						break;
					}
					catch (WrongZoneIdentifier e)
					{
						cout << endl << e.what();
					}
				}

				while (true)
				{
					try {
						cout << endl << "Please insert the UNIQUE row identifier from the map. Plase have in mind that the row identifier is a numerical value.";
						//int rowId = -1;
						cout << endl << "Your response:";
						cin >> rowId;
						testTicket.setRowIdentifier(rowId, Filantropica.getLocationAtIndex(locationId)->getZoneAtIndex(zoneId)->getNumberOfRowsPerZone(), Filantropica);
						break;
					}
					catch (WrongRowIdentifier e)
					{
						cout << endl << e.what();
					}
				}
				while (true)
				{
					try
					{
						cout << endl << "Please insert the UNIQUE seat identifier from the map. Plase have in mind that the seat identifier is a numerical value!" << endl;
						//int seatId = -1;
						cout << endl << "Your response:";
						cin >> seatId;
						testTicket.setSeatIdentifier(seatId, Filantropica.getLocationAtIndex(locationId)->getZoneAtIndex(zoneId)->getRowAtIndex(rowId)->getNoOfSeatsForRow(), Filantropica);
						break;
					}
					catch (WrongSeatIdentifier e)
					{
						cout << endl << e.what();
					}
				}

				while (true)
				{
					try
					{
						cout << endl << "Please insert your first name:";
						string firstName = "";
						cin >> firstName;
						testTicket.setClientFirstName(firstName);
						break;
					}
					catch (WrongFirstNameInput e)
					{
						cout << endl << e.what();
					}
				}

				while (true)
				{
					try
					{
						cout << endl << "Please insert your last name:";
						string lastName = "";
						cin >> lastName;
						testTicket.setClientLastName(lastName);


						createTicketWithDetails(testTicket, Filantropica, locationId, zoneId, rowId, seatId, counter);
						//Straini_in_noapte.getLocationAtIndex(locationId)->getZoneAtIndex(zoneId)->getRowAtIndex(rowId)->getSeatAtIndex(seatId)->setType(CHOSEN);
						mainReport.addTickets(testTicket);
						cout << endl << "Your ticket has been created. Then go to File Explorer and find it as FilmTicket1.txt.";
						/*char fileName[50];
						cout << endl << "Your response:";
						cin >> fileName;

						ofstream file(fileName, ios::ate);
						testTicket.serializeTickets(file);
						file.close();*/


						/*cout << endl << "Here is the updated map of the event:";
						cout << endl;  Straini_in_noapte.returnEvent();*/


						TicketReport testTicketReport;

						FileUtils::generateReport(testTicket, "FilmTicket1.txt");


						cout << endl << "This is your ticket:" << endl;
					    cout<<testTicket;

						cout << endl << "Now, go to File Explorer and get your ticket";
						break;
					}

					catch (WrongLastNameInput e)
					{
						cout << endl << e.what();
					}




				}

			}
			break;
			case 2:
			{
				EURO2024.returnEvent();
				Ticket testTicket1("09/01/2024", EURO2024);
				Seat::givePricesOfSeats();

				int locationId = -1;
				int zoneId = -1;
				int rowId = -1;
				int seatId = -1;
				while (true)
				{
					try
					{
						//cout << endl << " Customize your ticket! Please insert the location UNIQUE identifier from the map. ";
						cout << endl;
						cout << endl;
						cout << endl;
						cout << endl;
						//Seat::givePricesOfSeats();
						//int locationId = -1;
						cout << endl << " Customize your ticket! Please insert the location UNIQUE identifier from the map. ";
						cout << endl << "Your response:";
						cin >> locationId;
						testTicket1.setLocationIdentifier(locationId, EURO2024);
						break;
					}
					catch (WrongLocationIdentifier e)
					{
						cout << endl << e.what();
					}

				}

				while (true)
				{
					try {

						cout << endl << "Please insert the UNIQUE zone identifier from the map";
						//int zoneId = -1;
						cout << endl << "Your response:";
						cin >> zoneId;
						testTicket1.setZoneIdentifier(zoneId, EURO2024);
						break;
					}
					catch (WrongZoneIdentifier e)
					{
						cout << endl << e.what();
					}
				}

				while (true)
				{
					try {
						cout << endl << "Please insert the UNIQUE row identifier from the map. Plase have in mind that the row identifier is a numerical value.";
						//int rowId = -1;
						cout << endl << "Your response:";
						cin >> rowId;
						testTicket1.setRowIdentifier(rowId, EURO2024.getLocationAtIndex(locationId)->getZoneAtIndex(zoneId)->getNumberOfRowsPerZone(), EURO2024);
						break;
					}
					catch (WrongRowIdentifier e)
					{
						cout << endl << e.what();
					}
				}
				while (true)
				{
					try
					{
						cout << endl << "Please insert the UNIQUE seat identifier from the map. Plase have in mind that the seat identifier is a numerical value.";
						//int seatId = -1;
						cout << endl << "Your response:";
						cin >> seatId;
						testTicket1.setSeatIdentifier(seatId, EURO2024.getLocationAtIndex(locationId)->getZoneAtIndex(zoneId)->getRowAtIndex(rowId)->getNoOfSeatsForRow(), EURO2024);
						break;
					}
					catch (WrongSeatIdentifier e)
					{
						cout << endl << e.what();
					}
				}

				while (true)
				{
					try
					{
						cout << endl << "Please insert your first name:";
						string firstName = "";
						cin >> firstName;
						testTicket1.setClientFirstName(firstName);
						break;
					}
					catch (WrongFirstNameInput e)
					{
						cout << endl << e.what();
					}
				}

				while (true)
				{
					try
					{
						cout << endl << "Please insert your last name:";
						string lastName = "";
						cin >> lastName;
						testTicket1.setClientLastName(lastName);


						createTicketWithDetails(testTicket1, EURO2024, locationId, zoneId, rowId, seatId, counter);
						//Straini_in_noapte.getLocationAtIndex(locationId)->getZoneAtIndex(zoneId)->getRowAtIndex(rowId)->getSeatAtIndex(seatId)->setType(CHOSEN);
						mainReport.addTickets(testTicket1);
						cout << endl << "Your ticket has been created. Then go to File Explorer and find it as FootballTicket1.txt.";
						/*char fileName[50];
						cout << endl << "Your response:";
						cin >> fileName;

						ofstream file(fileName, ios::ate);
						testTicket2.serializeTickets(file);
						file.close();*/


						/*cout << endl << "Here is the updated map of the event:";
						cout << endl;  Straini_in_noapte.returnEvent();*/


						TicketReport testTicket1Report;

						FileUtils::generateReport(testTicket1, "FootballTicket1.txt");


						cout << endl << "This is your ticket:" << endl;
						cout<<testTicket1;

						cout << endl << "Now, go to File Explorer and get your ticket";
						break;
					}

					catch (WrongLastNameInput e)
					{
						cout << endl << e.what();
					}


				}
				break;
			}

			break;
			case 3:
			{
				int locationId = -1;
				int zoneId = -1;
				int rowId = -1;
				int seatId = -1;
				Straini_in_noapte.returnEvent();
				Ticket testTicket2("09/01/2024", Straini_in_noapte);
				Seat::givePricesOfSeats();

				while (true)
				{
					try
					{
						cout << endl << " Customize your ticket! Please insert the location UNIQUE identifier from the map. ";
						cout << endl;
						cout << endl;
						cout << endl;
						cout << endl;
						//Seat::givePricesOfSeats();
						//int locationId = -1;
						cout << endl << "Your response:";
						cin >> locationId;
						testTicket2.setLocationIdentifier(locationId, Straini_in_noapte);
						break;
					}
					catch (WrongLocationIdentifier e)
					{
						cout << endl << e.what();
					}

				}

				while (true)
				{
					try {

						cout << endl << "Please insert the UNIQUE zone identifier from the map";
						//int zoneId = -1;
						cout << endl << "Your response:";
						cin >> zoneId;
						testTicket2.setZoneIdentifier(zoneId, Straini_in_noapte);
						break;
					}
					catch (WrongZoneIdentifier e)
					{
						cout << endl << e.what();
					}
				}

				while (true)
				{
					try {
						cout << endl << "Please insert the UNIQUE row identifier from the map. Plase have in mind that the row identifier is a numerical value.";
						//int rowId = -1;
						cout << endl << "Your response:";
						cin >> rowId;
						testTicket2.setRowIdentifier(rowId, Straini_in_noapte.getLocationAtIndex(locationId)->getZoneAtIndex(zoneId)->getNumberOfRowsPerZone(), Straini_in_noapte);
						break;
					}
					catch (WrongRowIdentifier e)
					{
						cout << endl << e.what();
					}
				}
				while (true)
				{
					try
					{
						cout << endl << "Please insert the UNIQUE seat identifier from the map. Plase have in mind that the seat identifier is a numerical value.";
						//int seatId = -1;
						cout << endl << "Your response:";
						cin >> seatId;
						testTicket2.setSeatIdentifier(seatId, Straini_in_noapte.getLocationAtIndex(locationId)->getZoneAtIndex(zoneId)->getRowAtIndex(rowId)->getNoOfSeatsForRow(), Straini_in_noapte);
						break;
					}
					catch (WrongSeatIdentifier e)
					{
						cout << endl << e.what();
					}
				}

				while (true)
				{
					try
					{
						cout << endl << "Please insert your first name:";
						string firstName = "";
						cin >> firstName;
						testTicket2.setClientFirstName(firstName);
						break;
					}
					catch (WrongFirstNameInput e)
					{
						cout << endl << e.what();
					}
				}

				while (true)
				{
					try
					{
						cout << endl << "Please insert your last name:";
						string lastName = "";
						cin >> lastName;
						testTicket2.setClientLastName(lastName);


						createTicketWithDetails(testTicket2, Straini_in_noapte, locationId, zoneId, rowId, seatId, counter);
						//Straini_in_noapte.getLocationAtIndex(locationId)->getZoneAtIndex(zoneId)->getRowAtIndex(rowId)->getSeatAtIndex(seatId)->setType(CHOSEN);
						mainReport.addTickets(testTicket2);
						cout << endl << "Your ticket has been created. Then go to File Explorer and find it as TheatreTicket1.txt.";
						/*char fileName[50];
						cout << endl << "Your response:";
						cin >> fileName;

						ofstream file(fileName, ios::ate);
						testTicket2.serializeTickets(file);
						file.close();*/


						/*cout << endl << "Here is the updated map of the event:";
						cout << endl;  Straini_in_noapte.returnEvent();*/


						TicketReport testTicket2Report;

						FileUtils::generateReport(testTicket2, "TheatreTicket1.txt");


						cout << endl << "This is your ticket:" << endl;
						cout<<testTicket2;

						cout << endl << "Now, go to File Explorer and get your ticket";
						break;
					}

					catch (WrongLastNameInput e)
					{
						cout << endl << e.what();
					}
				}
				break;
			}


			}

			break;
		}
		case 1:
		{
			cout << endl << "Hello admin!";
			cout << endl << "Here's the up-to-date Report with the tickets";
			FileUtils::generateReport(mainReport, "ADMIN_REPORT.txt");
			cout << endl << mainReport;
			cout << endl << "You can also find the .txt report in the File Explorer. It's called ADMIN_REPORT.txt" << endl << endl << endl << endl << endl << endl;
			break;
		}
		default:
			cout << endl << "Hmmmm...even a robot would type the correct number. Retry. Choose between 0 and 1 :) :) :) :)";

			break;
		}
	}
	else
	{
		cout << endl << "The app has not been started";
	}







}