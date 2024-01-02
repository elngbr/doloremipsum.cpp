#pragma once
#include "elenaRows.h"
#include "elenaSeats.h"
#include "elenaZones.h"
#include "elenaLocations.h"
#include<string>
#include<iostream>
#include<fstream>
////////////////////////*******************************************************************************************INSERTIONS FOR SEATS
void addSeats(Row& rowname, int numberOfSeats1, Seat auxSeat1, int numberOfSeats2, Seat auxSeat2)
{
	for (int i = 0; i < numberOfSeats1; i++)
	{
		rowname.addSeats(auxSeat1);
	}
	for (int i = numberOfSeats1; i < numberOfSeats2; i++)
	{
		rowname.addSeats(auxSeat2);
	}
}

void addSeats(Row& rowname, int numberOfSeats1, Seat auxSeat1)
{
	for (int i = 0; i < numberOfSeats1; i++)
	{
		rowname.addSeats(auxSeat1);
	}
}

void addSeats(Row& rowname, int numberOfSeats1, Seat auxSeat1, int numberOfSeats2, Seat auxSeat2, int numberOfSeats3, Seat auxSeat3, int numberOfSeats4, Seat auxSeat4)
{
	for (int i = 0; i < numberOfSeats1; i++)
	{
		rowname.addSeats(auxSeat1);
	}
	for (int i = numberOfSeats1; i < numberOfSeats2; i++)
	{
		rowname.addSeats(auxSeat2);
	}
	for (int i = numberOfSeats2; i < numberOfSeats3; i++)
	{
		rowname.addSeats(auxSeat3);
	}
	for (int i = numberOfSeats3; i < numberOfSeats4; i++)
	{
		rowname.addSeats(auxSeat4);
	}
}

void addSeats(Row& rowname, int numberOfSeats1, Seat auxSeat1, int numberOfSeats2, Seat auxSeat2, int numberOfSeats3, Seat auxSeat3)
{
	for (int i = 0; i < numberOfSeats1; i++)
	{
		rowname.addSeats(auxSeat1);
	}
	for (int i = numberOfSeats1; i < numberOfSeats2; i++)
	{
		rowname.addSeats(auxSeat2);
	}
	for (int i = numberOfSeats2; i < numberOfSeats3; i++)
	{
		rowname.addSeats(auxSeat3);
	}
}

void addSeats(Row& rowname, int numberOfSeats1, Seat auxSeat1, int numberOfSeats2, Seat auxSeat2, int numberOfSeats3,
	Seat auxSeat3, int numberOfSeats4, Seat auxSeat4, int numberOfSeats5, Seat auxSeat5)
{
	for (int i = 0; i < numberOfSeats1; i++)
	{
		rowname.addSeats(auxSeat1);
	}
	for (int i = numberOfSeats1; i < numberOfSeats2; i++)
	{
		rowname.addSeats(auxSeat2);
	}
	for (int i = numberOfSeats2; i < numberOfSeats3; i++)
	{
		rowname.addSeats(auxSeat3);
	}
	for (int i = numberOfSeats3; i < numberOfSeats4; i++)
	{
		rowname.addSeats(auxSeat4);
	}
	for (int i = numberOfSeats4; i < numberOfSeats5; i++)
	{
		rowname.addSeats(auxSeat5);
	}
}

void addSeats(Row& rowname, int numberOfSeats1, Seat auxSeat1, int numberOfSeats2, Seat auxSeat2, int numberOfSeats3, Seat auxSeat3,
	int numberOfSeats4, Seat auxSeat4, int numberOfSeats5, Seat auxSeat5, int numberOfSeats6, Seat auxSeat6)
{
	for (int i = 0; i < numberOfSeats1; i++)
	{
		rowname.addSeats(auxSeat1);
	}
	for (int i = numberOfSeats1; i < numberOfSeats2; i++)
	{
		rowname.addSeats(auxSeat2);
	}
	for (int i = numberOfSeats2; i < numberOfSeats3; i++)
	{
		rowname.addSeats(auxSeat3);
	}
	for (int i = numberOfSeats3; i < numberOfSeats4; i++)
	{
		rowname.addSeats(auxSeat4);
	}
	for (int i = numberOfSeats4; i < numberOfSeats5; i++)
	{
		rowname.addSeats(auxSeat5);
	}
	for (int i = numberOfSeats5; i < numberOfSeats6; i++)
	{
		rowname.addSeats(auxSeat6);
	}
}

void addSeats(Row& rowname, int numberOfSeats1, Seat auxSeat1, int numberOfSeats2, Seat auxSeat2, int numberOfSeats3, Seat auxSeat3,
	int numberOfSeats4, Seat auxSeat4, int numberOfSeats5, Seat auxSeat5, int numberOfSeats6, Seat auxSeat6, int numberOfSeats7, Seat auxSeat7)
{
	for (int i = 0; i < numberOfSeats1; i++)
	{
		rowname.addSeats(auxSeat1);
	}
	for (int i = numberOfSeats1; i < numberOfSeats2; i++)
	{
		rowname.addSeats(auxSeat2);
	}
	for (int i = numberOfSeats2; i < numberOfSeats3; i++)
	{
		rowname.addSeats(auxSeat3);
	}
	for (int i = numberOfSeats3; i < numberOfSeats4; i++)
	{
		rowname.addSeats(auxSeat4);
	}
	for (int i = numberOfSeats4; i < numberOfSeats5; i++)
	{
		rowname.addSeats(auxSeat5);
	}
	for (int i = numberOfSeats5; i < numberOfSeats6; i++)
	{
		rowname.addSeats(auxSeat6);
	}
	for (int i = numberOfSeats6; i < numberOfSeats7; i++)
	{
		rowname.addSeats(auxSeat7);
	}
}

void addSeats(Row& rowname, int numberOfSeats1, Seat auxSeat1, int numberOfSeats2, Seat auxSeat2, int numberOfSeats3, Seat auxSeat3,
	int numberOfSeats4, Seat auxSeat4, int numberOfSeats5, Seat auxSeat5, int numberOfSeats6, Seat auxSeat6, int numberOfSeats7,
	Seat auxSeat7, int numberOfSeats8, Seat auxSeat8)
{
	for (int i = 0; i < numberOfSeats1; i++)
	{
		rowname.addSeats(auxSeat1);
	}
	for (int i = numberOfSeats1; i < numberOfSeats2; i++)
	{
		rowname.addSeats(auxSeat2);
	}
	for (int i = numberOfSeats2; i < numberOfSeats3; i++)
	{
		rowname.addSeats(auxSeat3);
	}
	for (int i = numberOfSeats3; i < numberOfSeats4; i++)
	{
		rowname.addSeats(auxSeat4);
	}
	for (int i = numberOfSeats4; i < numberOfSeats5; i++)
	{
		rowname.addSeats(auxSeat5);
	}
	for (int i = numberOfSeats5; i < numberOfSeats6; i++)
	{
		rowname.addSeats(auxSeat6);
	}
	for (int i = numberOfSeats6; i < numberOfSeats7; i++)
	{
		rowname.addSeats(auxSeat7);
	}
	for (int i = numberOfSeats7; i < numberOfSeats8; i++)
	{
		rowname.addSeats(auxSeat8);
	}
}

void addSeats(Row& rowname, int numberOfSeats1, Seat auxSeat1, int numberOfSeats2, Seat auxSeat2, int numberOfSeats3,
	Seat auxSeat3, int numberOfSeats4, Seat auxSeat4, int numberOfSeats5, Seat auxSeat5, int numberOfSeats6, Seat auxSeat6,
	int numberOfSeats7, Seat auxSeat7, int numberOfSeats8, Seat auxSeat8, int numberOfSeats9, Seat auxSeat9)
{
	for (int i = 0; i < numberOfSeats1; i++)
	{
		rowname.addSeats(auxSeat1);
	}
	for (int i = numberOfSeats1; i < numberOfSeats2; i++)
	{
		rowname.addSeats(auxSeat2);
	}
	for (int i = numberOfSeats2; i < numberOfSeats3; i++)
	{
		rowname.addSeats(auxSeat3);
	}
	for (int i = numberOfSeats3; i < numberOfSeats4; i++)
	{
		rowname.addSeats(auxSeat4);
	}
	for (int i = numberOfSeats4; i < numberOfSeats5; i++)
	{
		rowname.addSeats(auxSeat5);
	}
	for (int i = numberOfSeats5; i < numberOfSeats6; i++)
	{
		rowname.addSeats(auxSeat6);
	}
	for (int i = numberOfSeats6; i < numberOfSeats7; i++)
	{
		rowname.addSeats(auxSeat7);
	}
	for (int i = numberOfSeats7; i < numberOfSeats8; i++)
	{
		rowname.addSeats(auxSeat8);
	}
	for (int i = numberOfSeats8; i < numberOfSeats9; i++)
	{
		rowname.addSeats(auxSeat9);
	}
}

void addSeats(Row& rowname, int numberOfSeats1, Seat auxSeat1, int numberOfSeats2, Seat auxSeat2, int numberOfSeats3,
	Seat auxSeat3, int numberOfSeats4, Seat auxSeat4, int numberOfSeats5, Seat auxSeat5, int numberOfSeats6, Seat auxSeat6,
	int numberOfSeats7, Seat auxSeat7, int numberOfSeats8, Seat auxSeat8, int numberOfSeats9, Seat auxSeat9, int numberOfSeats10, Seat auxSeat10)
{
	for (int i = 0; i < numberOfSeats1; i++)
	{
		rowname.addSeats(auxSeat1);
	}
	for (int i = numberOfSeats1; i < numberOfSeats2; i++)
	{
		rowname.addSeats(auxSeat2);
	}
	for (int i = numberOfSeats2; i < numberOfSeats3; i++)
	{
		rowname.addSeats(auxSeat3);
	}
	for (int i = numberOfSeats3; i < numberOfSeats4; i++)
	{
		rowname.addSeats(auxSeat4);
	}
	for (int i = numberOfSeats4; i < numberOfSeats5; i++)
	{
		rowname.addSeats(auxSeat5);
	}
	for (int i = numberOfSeats5; i < numberOfSeats6; i++)
	{
		rowname.addSeats(auxSeat6);
	}
	for (int i = numberOfSeats6; i < numberOfSeats7; i++)
	{
		rowname.addSeats(auxSeat7);
	}
	for (int i = numberOfSeats7; i < numberOfSeats8; i++)
	{
		rowname.addSeats(auxSeat8);
	}
	for (int i = numberOfSeats8; i < numberOfSeats9; i++)
	{
		rowname.addSeats(auxSeat9);
	}
	for (int i = numberOfSeats9; i < numberOfSeats10; i++)
	{
		rowname.addSeats(auxSeat10);
	}
}

void addSeats(Row& rowname, int numberOfSeats1, Seat auxSeat1, int numberOfSeats2, Seat auxSeat2, int numberOfSeats3,
	Seat auxSeat3, int numberOfSeats4, Seat auxSeat4, int numberOfSeats5, Seat auxSeat5, int numberOfSeats6, Seat auxSeat6,
	int numberOfSeats7, Seat auxSeat7, int numberOfSeats8, Seat auxSeat8, int numberOfSeats9, Seat auxSeat9, int numberOfSeats10,
	Seat auxSeat10, int numberOfSeats11, Seat auxSeat11)
{
	for (int i = 0; i < numberOfSeats1; i++)
	{
		rowname.addSeats(auxSeat1);
	}
	for (int i = numberOfSeats1; i < numberOfSeats2; i++)
	{
		rowname.addSeats(auxSeat2);
	}
	for (int i = numberOfSeats2; i < numberOfSeats3; i++)
	{
		rowname.addSeats(auxSeat3);
	}
	for (int i = numberOfSeats3; i < numberOfSeats4; i++)
	{
		rowname.addSeats(auxSeat4);
	}
	for (int i = numberOfSeats4; i < numberOfSeats5; i++)
	{
		rowname.addSeats(auxSeat5);
	}
	for (int i = numberOfSeats5; i < numberOfSeats6; i++)
	{
		rowname.addSeats(auxSeat6);
	}
	for (int i = numberOfSeats6; i < numberOfSeats7; i++)
	{
		rowname.addSeats(auxSeat7);
	}
	for (int i = numberOfSeats7; i < numberOfSeats8; i++)
	{
		rowname.addSeats(auxSeat8);
	}
	for (int i = numberOfSeats8; i < numberOfSeats9; i++)
	{
		rowname.addSeats(auxSeat9);
	}
	for (int i = numberOfSeats9; i < numberOfSeats10; i++)
	{
		rowname.addSeats(auxSeat10);
	}
	for (int i = numberOfSeats10; i < numberOfSeats11; i++)
	{
		rowname.addSeats(auxSeat11);
	}
}

void addSeats(Row& rowname, int numberOfSeats1, Seat auxSeat1, int numberOfSeats2, Seat auxSeat2, int numberOfSeats3,
	Seat auxSeat3, int numberOfSeats4, Seat auxSeat4, int numberOfSeats5, Seat auxSeat5, int numberOfSeats6, Seat auxSeat6,
	int numberOfSeats7, Seat auxSeat7, int numberOfSeats8, Seat auxSeat8, int numberOfSeats9, Seat auxSeat9, int numberOfSeats10,
	Seat auxSeat10, int numberOfSeats11, Seat auxSeat11, int numberOfSeats12, Seat auxSeat12)
{
	for (int i = 0; i < numberOfSeats1; i++)
	{
		rowname.addSeats(auxSeat1);
	}
	for (int i = numberOfSeats1; i < numberOfSeats2; i++)
	{
		rowname.addSeats(auxSeat2);
	}
	for (int i = numberOfSeats2; i < numberOfSeats3; i++)
	{
		rowname.addSeats(auxSeat3);
	}
	for (int i = numberOfSeats3; i < numberOfSeats4; i++)
	{
		rowname.addSeats(auxSeat4);
	}
	for (int i = numberOfSeats4; i < numberOfSeats5; i++)
	{
		rowname.addSeats(auxSeat5);
	}
	for (int i = numberOfSeats5; i < numberOfSeats6; i++)
	{
		rowname.addSeats(auxSeat6);
	}
	for (int i = numberOfSeats6; i < numberOfSeats7; i++)
	{
		rowname.addSeats(auxSeat7);
	}
	for (int i = numberOfSeats7; i < numberOfSeats8; i++)
	{
		rowname.addSeats(auxSeat8);
	}
	for (int i = numberOfSeats8; i < numberOfSeats9; i++)
	{
		rowname.addSeats(auxSeat9);
	}
	for (int i = numberOfSeats9; i < numberOfSeats10; i++)
	{
		rowname.addSeats(auxSeat10);
	}
	for (int i = numberOfSeats10; i < numberOfSeats11; i++)
	{
		rowname.addSeats(auxSeat11);
	}

	for (int i = numberOfSeats11; i < numberOfSeats12; i++)
	{
		rowname.addSeats(auxSeat12);
	}
}
////////////////////////*******************************************************************************************END INSERTIONS FOR SEATS




////////////////////////******************************************************************************************INSERTIONS FOR ROWS--------> OVERLOADED FUNCTIONS


void addRows(Zone& auxName, int numberOfRows1, Row auxRow1)
{
	for (int i = 0; i < numberOfRows1; i++)
	{
		auxName.addRows(auxRow1);
	}
}

void addRows(Zone& auxName, int numberOfRows1, Row auxRow1, int numberOfRows2, Row auxRow2)
{
	for (int i = 0; i < numberOfRows1; i++)
	{
		auxName.addRows(auxRow1);
	}
	for (int i = numberOfRows1; i < numberOfRows2; i++)
	{
		auxName.addRows(auxRow2);
	}
}

void addRows(Zone& auxName, int numberOfRows1, Row auxRow1, int numberOfRows2, Row auxRow2, int numberOfRows3, Row auxRow3)
{
	for (int i = 0; i < numberOfRows1; i++)
	{
		auxName.addRows(auxRow1);
	}
	for (int i = numberOfRows1; i < numberOfRows2; i++)
	{
		auxName.addRows(auxRow2);
	}
	for (int i = numberOfRows2; i < numberOfRows3; i++)
	{
		auxName.addRows(auxRow3);
	}
}

void addRows(Zone& auxName, int numberOfRows1, Row auxRow1, int numberOfRows2, Row auxRow2, int numberOfRows3, Row auxRow3, int numberOfRows4, Row auxRow4)
{
	for (int i = 0; i < numberOfRows1; i++)
	{
		auxName.addRows(auxRow1);
	}
	for (int i = numberOfRows1; i < numberOfRows2; i++)
	{
		auxName.addRows(auxRow2);
	}
	for (int i = numberOfRows2; i < numberOfRows3; i++)
	{
		auxName.addRows(auxRow3);
	}
	for (int i = numberOfRows3; i < numberOfRows4; i++)
	{
		auxName.addRows(auxRow4);
	}
}

void addRows(Zone& auxName,
	int numberOfRows1, Row auxRow1,
	int numberOfRows2, Row auxRow2,
	int numberOfRows3, Row auxRow3,
	int numberOfRows4, Row auxRow4,
	int numberOfRows5, Row auxRow5)
{
	for (int i = 0; i < numberOfRows1; i++)
	{
		auxName.addRows(auxRow1);
	}
	for (int i = numberOfRows1; i < numberOfRows2; i++)
	{
		auxName.addRows(auxRow2);
	}
	for (int i = numberOfRows2; i < numberOfRows3; i++)
	{
		auxName.addRows(auxRow3);
	}
	for (int i = numberOfRows3; i < numberOfRows4; i++)
	{
		auxName.addRows(auxRow4);
	}
	for (int i = numberOfRows4; i < numberOfRows5; i++)
	{
		auxName.addRows(auxRow5);
	}
}

void addRows(Zone& auxName,
	int numberOfRows1, Row auxRow1,
	int numberOfRows2, Row auxRow2,
	int numberOfRows3, Row auxRow3,
	int numberOfRows4, Row auxRow4,
	int numberOfRows5, Row auxRow5,
	int numberOfRows6, Row auxRow6)
{
	for (int i = 0; i < numberOfRows1; i++)
	{
		auxName.addRows(auxRow1);
	}
	for (int i = numberOfRows1; i < numberOfRows2; i++)
	{
		auxName.addRows(auxRow2);
	}
	for (int i = numberOfRows2; i < numberOfRows3; i++)
	{
		auxName.addRows(auxRow3);
	}
	for (int i = numberOfRows3; i < numberOfRows4; i++)
	{
		auxName.addRows(auxRow4);
	}
	for (int i = numberOfRows4; i < numberOfRows5; i++)
	{
		auxName.addRows(auxRow5);
	}
	for (int i = numberOfRows5; i < numberOfRows6; i++)
	{
		auxName.addRows(auxRow6);
	}
}

void addRows(Zone& auxName,
	int numberOfRows1, Row auxRow1,
	int numberOfRows2, Row auxRow2,
	int numberOfRows3, Row auxRow3,
	int numberOfRows4, Row auxRow4,
	int numberOfRows5, Row auxRow5,
	int numberOfRows6, Row auxRow6,
	int numberOfRows7, Row auxRow7)
{
	for (int i = 0; i < numberOfRows1; i++)
	{
		auxName.addRows(auxRow1);
	}
	for (int i = numberOfRows1; i < numberOfRows2; i++)
	{
		auxName.addRows(auxRow2);
	}
	for (int i = numberOfRows2; i < numberOfRows3; i++)
	{
		auxName.addRows(auxRow3);
	}
	for (int i = numberOfRows3; i < numberOfRows4; i++)
	{
		auxName.addRows(auxRow4);
	}
	for (int i = numberOfRows4; i < numberOfRows5; i++)
	{
		auxName.addRows(auxRow5);
	}
	for (int i = numberOfRows5; i < numberOfRows6; i++)
	{
		auxName.addRows(auxRow6);
	}
	for (int i = numberOfRows6; i < numberOfRows7; i++)
	{
		auxName.addRows(auxRow7);
	}
}

///**************************************************************************************************************INSERTIONS FOR ZONES IN LOCATIONS
void addZones(Location& auxLocation, int numberOfZones1, Zone auxZone1)
{
	for (int i = 0; i < numberOfZones1; i++) {
		auxLocation.addZones(auxZone1);
	}
}

void addZones(Location& auxLocation, int numberOfZones1, Zone auxZone1, int numberOfZones2, Zone auxZone2)
{
	for (int i = 0; i < numberOfZones1; i++) {
		auxLocation.addZones(auxZone1);
	}
	for (int i = numberOfZones1; i < numberOfZones2; i++) {
		auxLocation.addZones(auxZone2);
	}
}

void addZones(Location& auxLocation, int numberOfZones1, Zone auxZone1, int numberOfZones2, Zone auxZone2, int numberOfZones3, Zone auxZone3)
{
	for (int i = 0; i < numberOfZones1; i++) {
		auxLocation.addZones(auxZone1);
	}
	for (int i = numberOfZones1; i < numberOfZones2; i++) {
		auxLocation.addZones(auxZone2);
	}
	for (int i = numberOfZones2; i < numberOfZones3; i++) {
		auxLocation.addZones(auxZone3);
	}
}

void addZones(Location& auxLocation, int numberOfZones1, Zone auxZone1, int numberOfZones2, Zone auxZone2, int numberOfZones3, Zone auxZone3, int numberOfZones4, Zone auxZone4)
{
	for (int i = 0; i < numberOfZones1; i++) {
		auxLocation.addZones(auxZone1);
	}
	for (int i = numberOfZones1; i < numberOfZones2; i++) {
		auxLocation.addZones(auxZone2);
	}
	for (int i = numberOfZones2; i < numberOfZones3; i++) {
		auxLocation.addZones(auxZone3);
	}
	for (int i = numberOfZones3; i < numberOfZones4; i++) {
		auxLocation.addZones(auxZone4);
	}
}

void addZones(Location& auxLocation, int numberOfZones1, Zone auxZone1, int numberOfZones2, Zone auxZone2, int numberOfZones3, Zone auxZone3, int numberOfZones4, Zone auxZone4, int numberOfZones5, Zone auxZone5)
{
	for (int i = 0; i < numberOfZones1; i++) {
		auxLocation.addZones(auxZone1);
	}
	for (int i = numberOfZones1; i < numberOfZones2; i++) {
		auxLocation.addZones(auxZone2);
	}
	for (int i = numberOfZones2; i < numberOfZones3; i++) {
		auxLocation.addZones(auxZone3);
	}
	for (int i = numberOfZones3; i < numberOfZones4; i++) {
		auxLocation.addZones(auxZone4);
	}
	for (int i = numberOfZones4; i < numberOfZones5; i++) {
		auxLocation.addZones(auxZone5);
	}
}

void addZones(Location& auxLocation, int numberOfZones1, Zone auxZone1, int numberOfZones2, Zone auxZone2, int numberOfZones3, Zone auxZone3, int numberOfZones4, Zone auxZone4, int numberOfZones5, Zone auxZone5, int numberOfZones6, Zone auxZone6)
{
	for (int i = 0; i < numberOfZones1; i++) {
		auxLocation.addZones(auxZone1);
	}
	for (int i = numberOfZones1; i < numberOfZones2; i++) {
		auxLocation.addZones(auxZone2);
	}
	for (int i = numberOfZones2; i < numberOfZones3; i++) {
		auxLocation.addZones(auxZone3);
	}
	for (int i = numberOfZones3; i < numberOfZones4; i++) {
		auxLocation.addZones(auxZone4);
	}
	for (int i = numberOfZones4; i < numberOfZones5; i++) {
		auxLocation.addZones(auxZone5);
	}
	for (int i = numberOfZones5; i < numberOfZones6; i++) {
		auxLocation.addZones(auxZone6);
	}
}

///**************************************************************************************************************INSERTIONS FOR ZONES IN LOCATIONS
