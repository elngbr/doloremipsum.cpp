#pragma once
#include "elenaRows.h"
#include "elenaSeats.h"
#include "elenaZones.h"
#include "elenaLocations.h"
#include "elenaEvents.h"
#include "elenaTickets.h"
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