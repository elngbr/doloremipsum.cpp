#pragma once


#pragma once

#include <iostream>
#include <string>
using namespace std;



enum typeOfPlace { STADIUM, CONCERT_HALL, OPERA_HOUSE, EVENTS_HALL, SPORT_HALL, CINEMA_HALL, SQUARE };
enum typeOfEvent { CONCERT, FOOTBALL, THEATRE, FILM, CHARITY, FAIR, PROTEST };
enum typeOfTicket { VIP, LAWN, TRIBUNE, BOXES, STAND1, STAND2, CATEGORY1, CATEGORY2 }; ///also type of zone OR NOT?



class Event {
private:
	int  static NO_OF_EVENTS; ///if you have such things, you can only decrement it in the destructor
	int static const MAX_PREVIOUS_RANKING = 9;    ////SO THAT I CAN INCREMENT IT MANY MANY TIMES                   THE PREVIOUS RANKING IS ALWAYS IS OUT OF 10
	int static ID_COUNTER;
	//so also define at least one dynamic attribute, so that the destructor will be called
	int const eventId = 0;//no setter for this one
	char* nameOfEvent = nullptr; ///so that NO ONE CAN MODIFY
	char dateOfEvent[9] = "dd/mm/yy"; ///it will follow the standard dd/mm/yyyy. the previous sequence has 8ch +1 =9
	char timeOfEvent[6] = "hh:mm"; //will follow the satndard hh:mm. the previous sequence has 5 ch + 1=6
	typeOfEvent type = typeOfEvent::FOOTBALL;
	int eventPreviousRanking = 0;
public:

	int getRanking() const
	{
		return this->eventPreviousRanking;
	}

	void setEventPreviousRanking(int auxRanking)
	{
		if (auxRanking > MAX_PREVIOUS_RANKING || auxRanking == NULL)
		{
			throw exception("If this kind of event existed before, it shall have a grade which is at least 1. However, these days, 10 is the Lord's grade :)");
		}

		this->eventPreviousRanking = auxRanking;
	}

	int getEventId() const
	{
		return this->eventId;

	}

	char* getNameOfEvent() const
	{
		char* copy = new char[strlen(this->nameOfEvent) + 1];
		strcpy_s(copy, strlen(this->nameOfEvent) + 1, this->nameOfEvent);

		return copy;
	}

	void setNameOfEvent(char* auxName)
	{
		if (auxName == nullptr || auxName[0] < 'A' || auxName[0]>'Z')
		{
			throw exception("Wrong name!");
		}

		delete[] this->nameOfEvent;
		this->nameOfEvent = new char[strlen(auxName) + 1];
		strcpy_s(this->nameOfEvent, strlen(auxName) + 1, auxName);

	}

	char* getDate() const
	{
		char* copy = new char[strlen(this->dateOfEvent) + 1];
		strcpy_s(copy, strlen(this->dateOfEvent) + 1, this->dateOfEvent);

		return copy;



	}

	void setDate(const char* auxDate)///all events will occur in 2024
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
			throw exception("Wrong input!");
		}


		strcpy_s(this->dateOfEvent, strlen(auxDate) + 1, const_cast<char*>(auxDate));


	}

	char* getTime() const
	{
		char* copy = new char[strlen(this->timeOfEvent) + 1];
		strcpy_s(copy, strlen(this->timeOfEvent) + 1, this->timeOfEvent);

		return copy;

	}

	void setTime(const char* auxTime)
	{
		if (auxTime == nullptr ||
			auxTime[2] != ':' ||
			(auxTime[0] != '0' && auxTime[0] != '1') ||
			(auxTime[1] < '0' || auxTime[1] > '9') ||
			(auxTime[3] < '0' || auxTime[3] > '5') ||
			(auxTime[4] < '0' || auxTime[4] > '9'))
		{
			throw exception("Wrong input! All events will occur in 2024 ");
		}

		strcpy_s(this->timeOfEvent, strlen(auxTime) + 1, auxTime);
	}

	//enum typeOfEvent { CONCERT, FOOTBALL, THEATRE, FILM, CHARITY, FAIR, PROTEST };

	typeOfEvent getType() const
	{

		return this->type;
	}




	//////////DEFAULT CONSTRUCTOR


	Event() :eventId(++ID_COUNTER)
	{
		NO_OF_EVENTS++;

	}
	///CONSTRUCTOR WITH PARAMETERS
	Event(const char* auxNameOfEvent, const char* auxDate, const char* auxTime, int auxRanking) : eventId(++ID_COUNTER)
	{
		this->setNameOfEvent(const_cast<char*>(auxNameOfEvent));
		this->setDate(auxDate);
		this->setTime(auxTime);
		this->setEventPreviousRanking(auxRanking);
		NO_OF_EVENTS++;
	}

	///DESTRUCTOR
	~Event()
	{
		delete[] this->nameOfEvent;

		Event::NO_OF_EVENTS--;
	}
	///COPY-CONSTRUCTOR
	Event(const Event& newEvent) : eventId(++ID_COUNTER)
	{
		//strcpy_s(dateOfEvent, sizeof(dateOfEvent), newEvent.getDate());
		//strcpy_s(this->timeOfEvent, strlen(timeOfEvent) + 1, newEvent.getTime());
		this->setDate(newEvent.getDate());
		this->setTime(newEvent.getTime());

		this->setEventPreviousRanking(newEvent.getRanking());
		this->setNameOfEvent(newEvent.getNameOfEvent());
		this->type = newEvent.type;
		NO_OF_EVENTS++;
	}
	//friend void operator<<(ostream& console, const Event& auxEvent);


	Event operator-(int value)
	{
		Event copy = *this;
		copy.eventPreviousRanking -= value;
		return copy;;

	}

	explicit operator char* ()
	{
		return this->dateOfEvent;
	}


	Event& operator()(int index, char number)
	{
		if (index > 5 || index < 0 || number < '0' || number>'9')
		{
			throw exception("Wrong val!");

		}

		this->timeOfEvent[index] = number;

		return *this;  //vreau obiectul cu totul
	}

	Event& operator=(const Event& other) {

		//source.setName(this->getName());


		//test for self equality
		if (&other == this) {
			return *this;
		}

		//this->id = source.id;
		delete[] this->nameOfEvent;
		this->setNameOfEvent(other.getNameOfEvent());

		return *this;
	}

	bool operator ==(const Event& auxEvent) const
	{

		//ALWAYS  USE strcmp for string comparison
		return (strcmp(this->nameOfEvent, auxEvent.getNameOfEvent()) == 0);       ///////////////////MEREU VERIFICA DACA E EGAL CU 0!!!!!!!!!!!!!!


	}


	bool operator!()
	{
		if (this->type != 5)
		{
			return true;
		}
		else {
			return false;
		}

	}

};

int Event::NO_OF_EVENTS = 0;
int Event::ID_COUNTER = 0;
void operator<<(ostream& console, const Event& auxEvent)
{
	console << endl << "This event is called:" << " " << auxEvent.getNameOfEvent();
	console << endl << "This event has an unique ID, this being: " << " " << auxEvent.getEventId();
	console << endl << "The event starts at:" << " " << auxEvent.getTime();
	console << endl << "The events is occuring on:" << " " << auxEvent.getDate();
	console << endl << "The previous ranking of an event of such kind was" << " " << auxEvent.getRanking();

	console << endl << "The type of event is:" << " ";

	switch (auxEvent.getType())
	{
	case FOOTBALL:
		console << "Footbal";
		break;
	case CONCERT:
		console << "Concert";
		break;
	case THEATRE:
		console << "Theatre";
		break;
	case FILM:
		console << "Film";
		break;
	case CHARITY:
		console << "Charity";
		break;
	case FAIR:
		console << "Fair";
		break;
	case PROTEST:
		console << "Protest";
		break;
	default:
		console << "Unknown type of event";
		break;
	}
	console << endl;
	console << endl;
	console << endl;

	//return console;
}

/*void operator<<(ostream& console, const Event& auxEvent)
{
	console << endl << "This event is called:" << " " << auxEvent.nameOfEvent;
	console << endl << "This event has an unique ID, this being:" << "" << auxEvent.eventId;
	console << endl << "The event starts at: " << " " << auxEvent.timeOfEvent;
	console << endl << "The events is occuring on:" << " " << auxEvent.dateOfEvent;

	console << endl << "The type of event is:" << " ";

	switch (auxEvent.type)
	{
	case FOOTBALL:
		console << "Footbal";
		break;
	case CONCERT:
		console << "Concert";
		break;
	case THEATRE:
		console << "Theatre";
		break;
	case FILM:
		console << "Film";
		break;
	case CHARITY:
		console << "Charity";
		break;
	case FAIR:
		console << "Fair";
		break;
	case PROTEST:
		console << "Protest";
		break;
	default:
		console << "Unknown type of event";
		break;
	}
	console << endl;
	console << endl;
	console << endl;

}
*/
