#pragma once
#include "elenaRows.h"
#include "elenaSeats.h"
#include "elenaZones.h"
#include "elenaLocations.h"
#include "elenaEvents.h"
#include "elenaTickets.h"
#include "TicketIDGenerator.h"
#include<string>
#include<iostream>
#include<fstream>
void addLocations(Event& auxEvent, int locationsNumber1, Location auxLocation1)
{
	for (int i = 0; i < locationsNumber1; i++)
	{
		auxEvent.addLocations(auxLocation1);
	}

}

void addLocations(Event& auxEvent, int locationsNumber1, Location auxLocation1, int locationsNumber2, Location auxLocation2)
{
	for (int i = 0; i < locationsNumber1; i++)
	{
		auxEvent.addLocations(auxLocation1);
	}
	for (int i = locationsNumber1; i < locationsNumber2; i++)
	{
		auxEvent.addLocations(auxLocation2);
	}
}

void addLocations(Event& auxEvent, int locationsNumber1, Location auxLocation1, int locationsNumber2, Location auxLocation2, int locationsNumber3, Location auxLocation3)
{
	for (int i = 0; i < locationsNumber1; i++)
	{
		auxEvent.addLocations(auxLocation1);
	}
	for (int i = locationsNumber1; i < locationsNumber2; i++)
	{
		auxEvent.addLocations(auxLocation2);
	}
	for (int i = locationsNumber2; i < locationsNumber3; i++)
	{
		auxEvent.addLocations(auxLocation3);
	}
}


//void addLocationZoneRowSeat(Ticket auxTicket, int auxLocationId, int auxZoneIndex, int auxRowIndex, int auxSeatIndex, Event auxEvent, int numberOfRowsAtZone, int numberOfSeatsAtRow)
//{
//
//
//
//    while (true) {
//        try
//        {
//            {
//                auxTicket.setLocationIdentifier(auxLocationId, auxEvent); //merge
//                auxTicket.setZoneIdentifier(auxZoneIndex, auxEvent);  //merge
//                //auxTicket.setRowIdentifier(auxRowIndex, *auxEvent.getLocationAtIndex(auxLocationId), auxEvent);
//                //auxTicket.setRowIdentifier(auxRowIndex, *auxEvent.getLocationAtIndex(auxLocationId)->getZoneAtIndex(auxZoneIndex), auxEvent);
//
//
//                auxTicket.setRowIdentifier(auxRowIndex, numberOfRowsAtZone, auxEvent);
//                auxTicket.setSeatIdentifier(auxSeatIndex, numberOfSeatsAtRow, auxEvent);
//            }
//
//            break;
//        }
//        catch (WrongLocationIdentifier e)
//        {
//            cout << endl << e.what();
//        }
//        catch (WrongRowIdentifier f)
//        {
//            cout << endl << f.what();
//        }
//        catch (WrongZoneIdentifier g)
//        {
//            cout << endl << g.what();
//        }
//        catch (WrongSeatIdentifier h)
//        {
//            cout << endl << h.what();
//        }
//        catch (...) {
//            cout << endl << "We have at identifiers!";
//        }
//    }
//}


//void updateTicketMatrix(Ticket& auxTicket, string* matrix, int& counter)
//{
//	string* copy = new string[counter + 1];
//
//	for (int i = 0; i < counter; i++)
//		copy[i] = matrix[i];
//	copy[counter] = auxTicket.getTicketId();
//
//	delete[] matrix;
//	matrix = copy;
//	counter++;
//}

void setZoneIdentifierBasedOnItsType(Ticket& auxTicket, Event& auxEvent)
{
	Zone* tiketZone = auxEvent.getLocationAtIndex(auxTicket.getLocationIdentifier())->getZoneAtIndex(auxTicket.getZoneIdentifier());
	zoneType auxZoneType = auxEvent.getLocationAtIndex(auxTicket.getLocationIdentifier())->getZoneAtIndex(auxTicket.getZoneIdentifier())->getType();
	int zoneIdentifierBasedOnType = 1;
	for (int i = 0; i < auxTicket.getZoneIdentifier(); i++)
	{
		zoneType comparisonZoneType = auxEvent.getLocationAtIndex(auxTicket.getLocationIdentifier())->getZoneAtIndex(i)->getType();
		if (auxZoneType == comparisonZoneType)
		{
			zoneIdentifierBasedOnType++;
		}
	}

	auxTicket.setZoneIdentifierBasedOnType(zoneIdentifierBasedOnType);
}

void setLocationIdentifierBasedOnItsType(Ticket& auxTicket, Event& auxEvent)
{
	Location* tiketLocation = auxEvent.getLocationAtIndex(auxTicket.getLocationIdentifier());
	locationType auxLocationType = auxEvent.getLocationAtIndex(auxTicket.getLocationIdentifier())->getLocationType();
	int locationIdentifierBasedOnType = 1;
	for (int i = 0; i < auxTicket.getLocationIdentifier(); i++)
	{
		locationType comparisonLocationType = auxEvent.getLocationAtIndex(i)->getLocationType();
		if (auxLocationType == comparisonLocationType)
		{
			locationIdentifierBasedOnType++;
		}
	}

	auxTicket.setLocationIdentifierBasedOnType(locationIdentifierBasedOnType);
}



void createTicketWithDetails(Ticket& auxTicket, Event auxEvent, int locationIdentifier, int zoneIdentifier, int rowIdentifier, int seatIdentifier, int& counterID)
{

	int numberOfRowsPerZone = auxEvent.getLocationAtIndex(locationIdentifier)->getZoneAtIndex(zoneIdentifier)->getNumberOfRowsPerZone();
	int numberOfSeatsPerRow = auxEvent.getLocationAtIndex(locationIdentifier)->getZoneAtIndex(zoneIdentifier)->getRowAtIndex(rowIdentifier)->getNoOfSeatsForRow();
	/*SeatType auxSeatType = auxEvent.getLocationAtIndex(locationIdentifier)->getZoneAtIndex(zoneIdentifier)->getRowAtIndex(rowIdentifier)->getSeatAtIndex(seatIdentifier)->getType();
	auxTicket.setSeatType(auxSeatType);
	zoneType auxZoneType = auxEvent.getLocationAtIndex(locationIdentifier)->getZoneAtIndex(zoneIdentifier)->getType();
	auxTicket.setZoneType(auxZoneType);*/


	while (true) {
		try
		{
			{
				auxTicket.setLocationIdentifier(locationIdentifier, auxEvent); //merge
				auxTicket.setZoneIdentifier(zoneIdentifier, auxEvent);  //merge
				//auxTicket.setRowIdentifier(auxRowIndex, *auxEvent.getLocationAtIndex(auxLocationId), auxEvent);
				//auxTicket.setRowIdentifier(auxRowIndex, *auxEvent.getLocationAtIndex(auxLocationId)->getZoneAtIndex(auxZoneIndex), auxEvent);


				auxTicket.setRowIdentifier(rowIdentifier, numberOfRowsPerZone, auxEvent);
				auxTicket.setSeatIdentifier(seatIdentifier, numberOfSeatsPerRow, auxEvent);
			}

			break;
		}
		catch (WrongLocationIdentifier e)
		{
			cout << endl << e.what();
		}
		catch (WrongRowIdentifier f)
		{
			cout << endl << f.what();
		}
		catch (WrongZoneIdentifier g)
		{
			cout << endl << g.what();
		}
		catch (WrongSeatIdentifier h)
		{
			cout << endl << h.what();
		}
		catch (...) {
			cout << endl << "We have at identifiers!";
		}
	}
	//addLocationZoneRowSeat(auxTicket, 0, 2, 11, 14, auxEvent, numberOfRowsPerZone, numberOfSeatsPerRow);

	SeatType auxSeatType = auxEvent.getLocationAtIndex(locationIdentifier)->getZoneAtIndex(zoneIdentifier)->getRowAtIndex(rowIdentifier)->getSeatAtIndex(seatIdentifier)->getType();
	auxTicket.setSeatType(auxSeatType);
	zoneType auxZoneType = auxEvent.getLocationAtIndex(locationIdentifier)->getZoneAtIndex(zoneIdentifier)->getType();
	auxTicket.setZoneType(auxZoneType);
	setZoneIdentifierBasedOnItsType(auxTicket, auxEvent);
	locationType auxLocationType = auxEvent.getLocationAtIndex(locationIdentifier)->getLocationType();
	auxTicket.setLocationType(auxLocationType);
	setLocationIdentifierBasedOnItsType(auxTicket, auxEvent);

	generateTicketId(auxTicket, counterID);

	//auxEvent.getLocationAtIndex(locationIdentifier)->getZoneAtIndex(zoneIdentifier)->getRowAtIndex(rowIdentifier)->getSeatAtIndex(seatIdentifier)->setType(CHOSEN);
}



///we use this one for try catch
void addLocationZoneRowSeat(Ticket& auxTicket, int auxLocationId, int auxZoneIndex, int auxRowIndex, int auxSeatIndex, Event auxEvent, int numberOfRowsAtZone, int numberOfSeatsAtRow)
{



	while (true) {
		try
		{
			{
				auxTicket.setLocationIdentifier(auxLocationId, auxEvent); //merge
				auxTicket.setZoneIdentifier(auxZoneIndex, auxEvent);  //merge
				//auxTicket.setRowIdentifier(auxRowIndex, *auxEvent.getLocationAtIndex(auxLocationId), auxEvent);
				//auxTicket.setRowIdentifier(auxRowIndex, *auxEvent.getLocationAtIndex(auxLocationId)->getZoneAtIndex(auxZoneIndex), auxEvent);


				auxTicket.setRowIdentifier(auxRowIndex, numberOfRowsAtZone, auxEvent);
				auxTicket.setSeatIdentifier(auxSeatIndex, numberOfSeatsAtRow, auxEvent);
			}

			break;
		}
		catch (WrongLocationIdentifier e)
		{
			cout << endl << e.what();
		}
		catch (WrongRowIdentifier f)
		{
			cout << endl << f.what();
		}
		catch (WrongZoneIdentifier g)
		{
			cout << endl << g.what();
		}
		catch (WrongSeatIdentifier h)
		{
			cout << endl << h.what();
		}
		catch (...) {
			cout << endl << "We have at identifiers!";
		}
	}
}

//
//void updateTicketMatrix(Ticket &auxTicket, string* matrix, int &counter)
//{
//	string* copy = new string[counter + 1];
//
//	for (int i = 0; i < counter; i++)
//		copy[i] = matrix[i];
//	copy[counter] = auxTicket.getTicketId();
//
//	delete[] matrix;
//	matrix = copy;
//	counter++;
//}


//void serializeString(string value, ofstream& file)
//{
//	int valueSize = strlen(value.c_str()) + 1;
//	file.write((char*)&valueSize, sizeof(int));
//	file.write(value.c_str(), sizeof(char) * valueSize);
//}
//
//string deserializeString(ifstream& file)
//{
//	int valueSize = 0;
//
//	file.read((char*)&valueSize, sizeof(int));
//	char buffer[1000];
//	file.read(buffer, sizeof(char) * valueSize);
//	return string(buffer);
//}
//




//addRows(amphitheaterZone, 3, standardRow, 6, studentRow, Zone::MAX_ROW_IDENTIFIER_PER_ZONE, premiumRow);
	//addRows(campingZone, 3, beanbagRow, 6, standardRow, Zone::MAX_ROW_IDENTIFIER_PER_ZONE, beanbagRow);
	//addRows(premiumZone, 6, premiumRow, 9, premiumRowWithWheelchair, Zone::MAX_ROW_IDENTIFIER_PER_ZONE, premiumRow);
	//addRows(familyZone, 3, coupleRow, 12, childrenRowWithStandardAndWheelchair, Zone::MAX_ROW_IDENTIFIER_PER_ZONE, standardRow);
	//addRows(studentZone, 3, studentRow, 12, studentRowWithWheelchair, Zone::MAX_ROW_IDENTIFIER_PER_ZONE, studentRow);
	//addRows(backstageZone, 3, vipRow, 12, beanbagRow, Zone::MAX_ROW_IDENTIFIER_PER_ZONE, vipWithWheelchairRow);
	///addRows(greenZone, Zone::MAX_ROW_IDENTIFIER_PER_ZONE, beanbagRow);
	//addRows(sroZone, Zone::MAX_ROW_IDENTIFIER_PER_ZONE, virtualRow);
	//addRows(networkingZone, 4, standardRow, 6, virtualRow, 8, flexibleRow, Zone::MAX_ROW_IDENTIFIER_PER_ZONE, beanbagRow);
	//addRows(gameZone, 5, virtualRow, 10, beanbagRow, 13, virtualRow, Zone::MAX_ROW_IDENTIFIER_PER_ZONE, beanbagRow);
	//addRows(balconyZone, 2, premiumRowWithWheelchair, 2, premiumRow);
	//addRows(beanbagZone, 3, beanbagRow);
	//addRows(flexibleRowsZone, 6, flexibleRow);






//Location eventsHallLocation(EVENTS_HALL);
	//Location sportHallLocation(SPORT_HALL);
	//Location squareLocation(SQUARE);
	//Location theatreLocation(THEATRE);
	//Location mallLocation(MALL);
	//Location publicInstitutionLocation(PUBLIC_INSTITUTION);
	//Location seaLocation(SEA);
	//Location forestLocation(FOREST);
	//Location mountainLocation(MOUNTAIN);
	//Location parkLocation(PARK);
	//Location schoolLocation(SCHOOL);
	//Location libraryLocation(LIBRARY);
	//Location cemeteryLocation(CEMETERY);
	//Location restaurantLocation(RESTAURANT);
	//Location operaHouseLocation(OPERA_HOUSE);



/*addZones(concertHallLocation, 1, premiumZone, 2, vipZone, 3, normalZone, 4, balconyZone, 5, amphitheaterZone, Location::MAX_IDENTIFIER_OF_ZONE, sroZone);
	addZones(operaHouseLocation, 1, premiumZone, 2, amphitheaterZone, 4, standZone, Location::MAX_IDENTIFIER_OF_ZONE, balconyZone);
	addZones(eventsHallLocation, 2, standZone, 4, normalZone, 5, amphitheaterZone, 6, balconyZone);
	addZones(sportHallLocation, 1, premiumZone, Location::MAX_IDENTIFIER_OF_ZONE, standZone);
	addZones(mallLocation, 1, vipZone, 2, sroZone, 3, beanbagZone);
	addZones(squareLocation, Location::MAX_IDENTIFIER_OF_ZONE, sroZone);
	addZones(publicInstitutionLocation, 1, standZone, 5, networkingZone);
	addZones(seaLocation, 1, greenZone, 3, flexibleRowsZone, Location::MAX_IDENTIFIER_OF_ZONE, sroZone);
	addZones(forestLocation, 3, greenZone, 5, sroZone);
	addZones(mountainLocation, 3, standZone, 4, vipZone, 5, premiumZone, Location::MAX_IDENTIFIER_OF_ZONE, normalZone);
	addZones(parkLocation, 2, sroZone, 4, standZone, Location::MAX_IDENTIFIER_OF_ZONE, normalZone);
	addZones(schoolLocation, 5, studentZone, Location::MAX_IDENTIFIER_OF_ZONE, standZone);
	addZones(libraryLocation, 1, sroZone, 2, beanbagZone);
	addZones(cemeteryLocation, 1, sroZone);
	addZones(restaurantLocation, 3, restaurantZone, 5, networkingZone);*/


	/*while (true)
				{
					try
					{
						cout << endl << " Customize your ticket! Please insert the location UNIQUE identifier from the map: ";
						int locationId = -1;
						cout << endl << "Your response:";
						cin >> locationId;
						testTicket2.setLocationIdentifier(locationId, Straini_in_noapte);

						cout << endl << "Please insert the UNIQUE zone identifier from the map";
						int zoneId = -1;
						cout << endl << "Your response:";
						cin >> zoneId;
						testTicket2.setZoneIdentifier(zoneId, Straini_in_noapte);


						cout << endl << "Please insert the UNIQUE row identifier from the map";
						int rowId = -1;
						cout << endl << "Your response:";
						cin >> rowId;
						testTicket2.setRowIdentifier(rowId, Straini_in_noapte.getLocationAtIndex(locationId)->getZoneAtIndex(zoneId)->getNumberOfRowsPerZone(), Straini_in_noapte);

						cout<<endl<< "Please insert the UNIQUE seat identifier from the map";
						int seatId = -1;
						cout << endl << "Your response:";
						cin >> seatId;
						testTicket2.setSeatIdentifier(seatId, Straini_in_noapte.getLocationAtIndex(locationId)->getZoneAtIndex(zoneId)->getRowAtIndex(rowId)->getNoOfSeatsForRow(),Straini_in_noapte);

						createTicketWithDetails(testTicket2, Straini_in_noapte, locationId, zoneId, rowId, seatId, counter);
						mainReport.addTickets(testTicket2);
						cout << endl << "Your ticket has been created. Please give us a name for the file that will contain the virtual ticket. It MUST end in .txt :).";
						char fileName[50];
						cout << endl << "Your response:";
						cin >> fileName;

						ofstream file(fileName, ios::ate);
						testTicket1.serializeTickets(file);
						file.close();

						cout << endl << "This is your ticket:" << endl;
						cout << testTicket1;

						cout << endl << "Now, go to File Explorer and get your ticket";
						break;
					}
					catch (WrongLocationIdentifier e)
					{
						cout << endl << e.what();
					}
					catch (WrongZoneIdentifier e)
					{
						cout << endl << e.what();
					}
					catch (WrongRowIdentifier e)
					{
						cout << endl << e.what();
					}
					catch (WrongSeatIdentifier e)
					{
						cout << endl << e.what();
					}


				}*/

