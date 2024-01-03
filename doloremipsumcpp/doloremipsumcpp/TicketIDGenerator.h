
#pragma once
#include "elenaRows.h"
#include "elenaSeats.h"
#include "elenaZones.h"
#include "elenaLocations.h"
#include "elenaEvents.h"
#include "elenaTickets.h"
#include "OverloadedF.h"
#include "OverloadedF1.h"

#include<string>
#include<iostream>
#include<fstream>


void generateTicketId(Ticket& auxTicket, int& counter)
{
	counter++;
	auxTicket.setTicketID("TICK");
	auxTicket.extendTicketIdentifier(to_string(counter * 5 / 3));
	auxTicket.extendTicketIdentifier(to_string(counter * 7));
	auxTicket.extendTicketIdentifier(to_string(counter));
	auxTicket.extendTicketIdentifier(to_string(auxTicket.getRowIdentifier()));
	auxTicket.extendTicketIdentifier(to_string(auxTicket.getSeatIdentifier() * 6));
	auxTicket.extendTicketIdentifier(to_string(auxTicket.getRowIdentifier() * 2));
	auxTicket.extendTicketIdentifier(to_string(auxTicket.getRowIdentifier() * 5));





}

//void generateTicketId(string& ceva, int& counter)
//{
//	counter++;
//	auxTicket.setTicketID("T" + static_cast<char>(counter));
//	auxTicket.extendTicketIdentifier(to_string(counter * 5 / 3));
//	auxTicket.extendTicketIdentifier(to_string(counter * 7));
//	auxTicket.extendTicketIdentifier(to_string(counter));
//	auxTicket.extendTicketIdentifier(to_string(auxTicket.getRowIdentifier()));
//	auxTicket.extendTicketIdentifier(to_string(auxTicket.getSeatIdentifier() * 6));
//	auxTicket.extendTicketIdentifier(to_string(auxTicket.getRowIdentifier() * 2));
//	auxTicket.extendTicketIdentifier(to_string(auxTicket.getRowIdentifier() * 5));
//
//
//
//
//
//}