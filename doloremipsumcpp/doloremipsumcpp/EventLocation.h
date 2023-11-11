#pragma once

#include <iostream>
#include <string>
using namespace std;
enum typeOfTicket{VIP, LAWN, TRIBUNE, BOXES};
class EventPlace {
private:
	int maximumSeats=0;
	int noRows=0;
	int noZones=0;
	string* matrixOfSeats=nullptr;

public:
};



class Event {
private:
	int static NO_OF_EVENTS; ///if you have such things, you can only decrement it in the destructor
	//so also define at least one dynamic attribute, so that the destructor will be called
	int eventId=0;
	char* nameOfEvent=nullptr;
	char dateOfEvent[11]="dd/mm/yyyy"; ///it will follow the standard dd/mm/yyyy. the previous sequence has 10 ch +1 =11
	char timeOfEvent[6]="hh:mm"; //will follow the satndard hh:mm. the previous sequence has 5 ch + 1=6

public:

};


class Ticket {
private:  //could be by default

	int static NO_OF_TICKETS;
	int ticketId = 0;
	typeOfTicket type = typeOfTicket::BOXES;

};
