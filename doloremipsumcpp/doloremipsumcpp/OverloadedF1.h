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
}
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


//void setLocationIdentifierBasedOnItsType(Ticket& auxTicket, Event& auxEvent)
//{
//	Location *tiketLocation = auxEvent.getLocationAtIndex(auxTicket.getLocationIdentifier());
//	locationType auxLocationType = auxEvent.getLocationAtIndex(auxTicket.getLocationIdentifier())->getLocationType();
//	int locationIdentifierBasedOnType = 1;
//	for (int i = 0; i < auxTicket.getLocationIdentifier(); i++)
//	{
//		locationType comparisonLocationType = auxEvent.getLocationAtIndex(i)->getLocationType();
//		if (auxLocationType == comparisonLocationType)
//		{
//			locationIdentifierBasedOnType++;
//		}
//	}
//
//	auxTicket.setLocationIdentifierBasedOnType(locationIdentifierBasedOnType);
//}