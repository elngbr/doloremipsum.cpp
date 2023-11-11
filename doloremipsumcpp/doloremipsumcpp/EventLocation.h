#pragma once

#include <iostream>
#include <string>
using namespace std;
enum typeOfTicket{VIP, LAWN, TRIBUNE, BOXES, STAND}; ///also type of zone
enum typeOfEvent{CONCERT, FOOTBALL, THEATRE, FILM, CHARITY, FAIR};

class EventPlace {
private:
	int noRows = 0;
	int noZones = 0;
	//typeOfTicket;
	int noSeatsPerRow = 0;
	int** stateOfSeats = nullptr;

public:
	int static const MAX_SEATS_ALLOWED = 1000;
	int static const MIN_ZONES = 1;
	int static const MIN_ROWS_PER_ZONE = 5;
	int static const MIN_SEATS_PER_ROW = 10;


	int getNumberOfRows()   ///if I create a setter for this one I risk to have someone modifying it and adding a number of rows which is less than my actual number
	{
		return this->noRows;
	}

	int getNoOfSeatsPerRows()   ///if I create a setter for this one I risk to have someone modifying it and adding a number of rows which is less than my actual number
	{
		return this->noSeatsPerRow;
	}


	int getNumberOfZones()
	{
		return this->noZones;
	}

	void setNumberofZones(int auxNumber)
	{
		if (auxNumber < EventPlace::MIN_ZONES)
		{
			throw exception("You can't have no zone!");
		}
	}

	int** getStateOfSeats()
	{
		int** copy = new int* [this->noRows];
		for (int i = 0; i < noRows; i++) {
			copy[i] = new int[this->noSeatsPerRow];

			for (int j = 0; j < noSeatsPerRow; j++)
				copy[i][j] = this->stateOfSeats[i][j];
		}

		return copy;
	}


	void setStateOfSeats(int** matrix, int auxNoRows, int auxNoSeatsPerRow) {
		if (matrix == nullptr || auxNoRows < EventPlace::MIN_ROWS_PER_ZONE || auxNoSeatsPerRow < EventPlace::MIN_SEATS_PER_ROW) {
			throw exception("Wrong value!");
		}


		for (int i = 0; i < noRows; i++) {
			delete[] stateOfSeats[i];
		}
		delete[] stateOfSeats;

		stateOfSeats = new int* [auxNoRows];
		for (int i = 0; i < auxNoRows; i++) {
			stateOfSeats[i] = new int[auxNoSeatsPerRow];
		}


		for (int i = 0; i < auxNoRows; i++) {
			for (int j = 0; j < auxNoSeatsPerRow; j++) {
				stateOfSeats[i][j] = matrix[i][j];
			}
		}


		noRows = auxNoRows;
		noSeatsPerRow = auxNoSeatsPerRow;
	}

	EventPlace()
	{

	}

	EventPlace(int auxNoRows, int auxNoSeatsPerRow, int** auxMatrix)
	{
		this->setStateOfSeats(auxMatrix, auxNoRows, auxNoSeatsPerRow);
	}

	~EventPlace()
	{

		for (int i = 0; i < noRows; i++) {
			delete[] stateOfSeats[i];
		}
		delete[] stateOfSeats;
	}

		
	EventPlace(const EventPlace & place) 
		{
			this->noRows = place.noRows;
			this->noSeatsPerRow = place.noSeatsPerRow;
			this->noZones = place.noZones;

			
			this->stateOfSeats = new int* [noRows];
			for (int i = 0; i < noRows; i++) {
				this->stateOfSeats[i] = new int[noSeatsPerRow];
			}

					for (int i = 0; i < noRows; i++) {
				for (int j = 0; j < noSeatsPerRow; j++) {
					this->stateOfSeats[i][j] = place.stateOfSeats[i][j];
				}
			}
	}


	

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


	Event()
	{

	}

	Event() {

	}

	~Event()
	{
		delete[] this->nameOfEvent;

		Event::NO_OF_EVENTS--;
	}

};


class Ticket {
private:  //could be by default

	int static NO_OF_TICKETS;
	int ticketId = 0;
	typeOfTicket type = typeOfTicket::BOXES;


};
