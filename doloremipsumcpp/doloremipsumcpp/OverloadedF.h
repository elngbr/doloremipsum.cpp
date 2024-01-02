#pragma once
#pragma once
#include "elenaRows.h"
#include "elenaSeats.h"
#include "elenaZones.h"
#include<string>
#include<iostream>
#include<fstream>
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

//void addSeats(Row &rowname, int numberOfSeats1, SeatType auxType1, int numberOfSeats2, SeatType auxType2)
//{
//	for (int i = 0; i < numberOfSeats1; i++)
//	{
//		rowname.addSeats(auxType1);
//	}
//	for (int i = numberOfSeats1; i < numberOfSeats2; i++)
//	{
//		rowname.addSeats(auxType2);
//	}
//}
//void addSeats(Row rowname, int numberOfSeats1, SeatType auxType1)
//{
//	for (int i = 0; i < numberOfSeats1; i++)
//	{
//		rowname.addSeats(auxType1);
//	}
//}
//void addSeats(Row &rowname, int numberOfSeats1, SeatType auxType1, int numberOfSeats2, SeatType auxType2, int numberOfSeats3, SeatType auxType3, int numberOfSeats4, SeatType auxType4)
//{
//	for (int i = 0; i < numberOfSeats1; i++)
//	{
//		rowname.addSeats(auxType1);
//	}
//	for (int i = numberOfSeats1; i < numberOfSeats2; i++)
//	{
//		rowname.addSeats(auxType2);
//	}
//	for (int i = numberOfSeats2; i < numberOfSeats3; i++)
//	{
//		rowname.addSeats(auxType3);
//	}
//	for (int i = numberOfSeats3; i < numberOfSeats4; i++)
//	{
//		rowname.addSeats(auxType4);
//	}
//}
//
//void addSeats(Row &rowname, int numberOfSeats1, SeatType auxType1, int numberOfSeats2, SeatType auxType2, int numberOfSeats3, SeatType auxType3)
//{
//	for (int i = 0; i < numberOfSeats1; i++)
//	{
//		rowname.addSeats(auxType1);
//	}
//	for (int i = numberOfSeats1; i < numberOfSeats2; i++)
//	{
//		rowname.addSeats(auxType2);
//	}
//	for (int i = numberOfSeats2; i < numberOfSeats3; i++)
//	{
//		rowname.addSeats(auxType3);
//	}
//
//}
//void addSeats(Row& rowname, int numberOfSeats1, SeatType auxType1, int numberOfSeats2, SeatType auxType2, int numberOfSeats3,
//	SeatType auxType3, int numberOfSeats4, SeatType auxType4, int numberOfSeats5, SeatType auxType5)
//{
//	for (int i = 0; i < numberOfSeats1; i++)
//	{
//		rowname.addSeats(auxType1);
//	}
//	for (int i = numberOfSeats1; i < numberOfSeats2; i++)
//	{
//		rowname.addSeats(auxType2);
//	}
//	for (int i = numberOfSeats2; i < numberOfSeats3; i++)
//	{
//		rowname.addSeats(auxType3);
//	}
//	for (int i = numberOfSeats3; i < numberOfSeats4; i++)
//	{
//		rowname.addSeats(auxType4);
//	}
//	for (int i = numberOfSeats4; i < numberOfSeats5; i++)
//	{
//		rowname.addSeats(auxType5);
//	}
//	
//}
//
//void addSeats(Row &rowname, int numberOfSeats1, SeatType auxType1, int numberOfSeats2, SeatType auxType2, int numberOfSeats3, SeatType auxType3,
//	int numberOfSeats4, SeatType auxType4, int numberOfSeats5, SeatType auxType5, int numberOfSeats6, SeatType auxType6)
//{
//	for (int i = 0; i < numberOfSeats1; i++)
//	{
//		rowname.addSeats(auxType1);
//	}
//	for (int i = numberOfSeats1; i < numberOfSeats2; i++)
//	{
//		rowname.addSeats(auxType2);
//	}
//	for (int i = numberOfSeats2; i < numberOfSeats3; i++)
//	{
//		rowname.addSeats(auxType3);
//	}
//	for (int i = numberOfSeats3; i < numberOfSeats4; i++)
//	{
//		rowname.addSeats(auxType4);
//	}
//	for (int i = numberOfSeats4; i < numberOfSeats5; i++)
//	{
//		rowname.addSeats(auxType5);
//	}
//	for (int i = numberOfSeats5; i < numberOfSeats6; i++)
//	{
//		rowname.addSeats(auxType6);
//	}
//}
//
//void addSeats(Row &rowname, int numberOfSeats1, SeatType auxType1, int numberOfSeats2, SeatType auxType2, int numberOfSeats3, SeatType auxType3,
//	int numberOfSeats4, SeatType auxType4, int numberOfSeats5, SeatType auxType5, int numberOfSeats6, SeatType auxType6, int numberOfSeats7, SeatType auxType7)
//{
//	for (int i = 0; i < numberOfSeats1; i++)
//	{
//		rowname.addSeats(auxType1);
//	}
//	for (int i = numberOfSeats1; i < numberOfSeats2; i++)
//	{
//		rowname.addSeats(auxType2);
//	}
//	for (int i = numberOfSeats2; i < numberOfSeats3; i++)
//	{
//		rowname.addSeats(auxType3);
//	}
//	for (int i = numberOfSeats3; i < numberOfSeats4; i++)
//	{
//		rowname.addSeats(auxType4);
//	}
//	for (int i = numberOfSeats4; i < numberOfSeats5; i++)
//	{
//		rowname.addSeats(auxType5);
//	}
//	for (int i = numberOfSeats5; i < numberOfSeats6; i++)
//	{
//		rowname.addSeats(auxType6);
//	}
//	for (int i = numberOfSeats6; i < numberOfSeats7; i++)
//	{
//		rowname.addSeats(auxType7);
//	}
//
//}
//
//void addSeats(Row &rowname, int numberOfSeats1, SeatType auxType1, int numberOfSeats2, SeatType auxType2, int numberOfSeats3, SeatType auxType3,
//	int numberOfSeats4, SeatType auxType4, int numberOfSeats5, SeatType auxType5, int numberOfSeats6, SeatType auxType6, int numberOfSeats7,
//	SeatType auxType7, int numberOfSeats8, SeatType auxType8)
//{
//	for (int i = 0; i < numberOfSeats1; i++)
//	{
//		rowname.addSeats(auxType1);
//	}
//	for (int i = numberOfSeats1; i < numberOfSeats2; i++)
//	{
//		rowname.addSeats(auxType2);
//	}
//	for (int i = numberOfSeats2; i < numberOfSeats3; i++)
//	{
//		rowname.addSeats(auxType3);
//	}
//	for (int i = numberOfSeats3; i < numberOfSeats4; i++)
//	{
//		rowname.addSeats(auxType4);
//	}
//	for (int i = numberOfSeats4; i < numberOfSeats5; i++)
//	{
//		rowname.addSeats(auxType5);
//	}
//	for (int i = numberOfSeats5; i < numberOfSeats6; i++)
//	{
//		rowname.addSeats(auxType6);
//	}
//	for (int i = numberOfSeats6; i < numberOfSeats7; i++)
//	{
//		rowname.addSeats(auxType7);
//	}
//	for (int i = numberOfSeats7; i < numberOfSeats8; i++)
//	{
//		rowname.addSeats(auxType8);
//	}
//}
//
//void addSeats(Row &rowname, int numberOfSeats1, SeatType auxType1, int numberOfSeats2, SeatType auxType2, int numberOfSeats3,
//	SeatType auxType3, int numberOfSeats4, SeatType auxType4, int numberOfSeats5, SeatType auxType5, int numberOfSeats6, SeatType auxType6,
//	int numberOfSeats7, SeatType auxType7, int numberOfSeats8, SeatType auxType8, int numberOfSeats9, SeatType auxType9)
//{
//	for (int i = 0; i < numberOfSeats1; i++)
//	{
//		rowname.addSeats(auxType1);
//	}
//	for (int i = numberOfSeats1; i < numberOfSeats2; i++)
//	{
//		rowname.addSeats(auxType2);
//	}
//	for (int i = numberOfSeats2; i < numberOfSeats3; i++)
//	{
//		rowname.addSeats(auxType3);
//	}
//	for (int i = numberOfSeats3; i < numberOfSeats4; i++)
//	{
//		rowname.addSeats(auxType4);
//	}
//	for (int i = numberOfSeats4; i < numberOfSeats5; i++)
//	{
//		rowname.addSeats(auxType5);
//	}
//	for (int i = numberOfSeats5; i < numberOfSeats6; i++)
//	{
//		rowname.addSeats(auxType6);
//	}
//	for (int i = numberOfSeats6; i < numberOfSeats7; i++)
//	{
//		rowname.addSeats(auxType7);
//	}
//	for (int i = numberOfSeats7; i < numberOfSeats8; i++)
//	{
//		rowname.addSeats(auxType8);
//	}
//	for (int i = numberOfSeats8; i < numberOfSeats9; i++)
//	{
//		rowname.addSeats(auxType9);
//	}
//}
//
//void addSeats(Row& rowname, int numberOfSeats1, SeatType auxType1, int numberOfSeats2, SeatType auxType2, int numberOfSeats3,
//	SeatType auxType3, int numberOfSeats4, SeatType auxType4, int numberOfSeats5, SeatType auxType5, int numberOfSeats6, SeatType auxType6,
//	int numberOfSeats7, SeatType auxType7, int numberOfSeats8, SeatType auxType8, int numberOfSeats9, SeatType auxType9, int numberOfSeats10, SeatType auxType10)
//{
//	for (int i = 0; i < numberOfSeats1; i++)
//	{
//		rowname.addSeats(auxType1);
//	}
//	for (int i = numberOfSeats1; i < numberOfSeats2; i++)
//	{
//		rowname.addSeats(auxType2);
//	}
//	for (int i = numberOfSeats2; i < numberOfSeats3; i++)
//	{
//		rowname.addSeats(auxType3);
//	}
//	for (int i = numberOfSeats3; i < numberOfSeats4; i++)
//	{
//		rowname.addSeats(auxType4);
//	}
//	for (int i = numberOfSeats4; i < numberOfSeats5; i++)
//	{
//		rowname.addSeats(auxType5);
//	}
//	for (int i = numberOfSeats5; i < numberOfSeats6; i++)
//	{
//		rowname.addSeats(auxType6);
//	}
//	for (int i = numberOfSeats6; i < numberOfSeats7; i++)
//	{
//		rowname.addSeats(auxType7);
//	}
//	for (int i = numberOfSeats7; i < numberOfSeats8; i++)
//	{
//		rowname.addSeats(auxType8);
//	}
//	for (int i = numberOfSeats8; i < numberOfSeats9; i++)
//	{
//		rowname.addSeats(auxType9);
//	}
//	for (int i = numberOfSeats9; i < numberOfSeats10; i++)
//	{
//		rowname.addSeats(auxType10);
//	}
//}
//
//void addSeats(Row &rowname, int numberOfSeats1, SeatType auxType1, int numberOfSeats2, SeatType auxType2, int numberOfSeats3,
//	SeatType auxType3, int numberOfSeats4, SeatType auxType4, int numberOfSeats5, SeatType auxType5, int numberOfSeats6, SeatType auxType6,
//	int numberOfSeats7, SeatType auxType7, int numberOfSeats8, SeatType auxType8, int numberOfSeats9, SeatType auxType9, int numberOfSeats10,
//	SeatType auxType10, int numberOfSeats11, SeatType auxType11)
//{
//	for (int i = 0; i < numberOfSeats1; i++)
//	{
//		rowname.addSeats(auxType1);
//	}
//	for (int i = numberOfSeats1; i < numberOfSeats2; i++)
//	{
//		rowname.addSeats(auxType2);
//	}
//	for (int i = numberOfSeats2; i < numberOfSeats3; i++)
//	{
//		rowname.addSeats(auxType3);
//	}
//	for (int i = numberOfSeats3; i < numberOfSeats4; i++)
//	{
//		rowname.addSeats(auxType4);
//	}
//	for (int i = numberOfSeats4; i < numberOfSeats5; i++)
//	{
//		rowname.addSeats(auxType5);
//	}
//	for (int i = numberOfSeats5; i < numberOfSeats6; i++)
//	{
//		rowname.addSeats(auxType6);
//	}
//	for (int i = numberOfSeats6; i < numberOfSeats7; i++)
//	{
//		rowname.addSeats(auxType7);
//	}
//	for (int i = numberOfSeats7; i < numberOfSeats8; i++)
//	{
//		rowname.addSeats(auxType8);
//	}
//	for (int i = numberOfSeats8; i < numberOfSeats9; i++)
//	{
//		rowname.addSeats(auxType9);
//	}
//	for (int i = numberOfSeats9; i < numberOfSeats10; i++)
//	{
//		rowname.addSeats(auxType10);
//	}
//	for (int i = numberOfSeats10; i < numberOfSeats11; i++)
//	{
//		rowname.addSeats(auxType11);
//	}
//}
//
//void addSeats(Row &rowname, int numberOfSeats1, SeatType auxType1,
//	int numberOfSeats2, SeatType auxType2, int numberOfSeats3, SeatType auxType3, int numberOfSeats4,
//	SeatType auxType4, int numberOfSeats5, SeatType auxType5, int numberOfSeats6, SeatType auxType6, int numberOfSeats7,
//	SeatType auxType7, int numberOfSeats8, SeatType auxType8, int numberOfSeats9, SeatType auxType9, int numberOfSeats10, SeatType auxType10, int numberOfSeats11,
//	SeatType auxType11, int numberOfSeats12, SeatType auxType12)
//{
//	for (int i = 0; i < numberOfSeats1; i++)
//	{
//		rowname.addSeats(auxType1);
//	}
//	for (int i = numberOfSeats1; i < numberOfSeats2; i++)
//	{
//		rowname.addSeats(auxType2);
//	}
//	for (int i = numberOfSeats2; i < numberOfSeats3; i++)
//	{
//		rowname.addSeats(auxType3);
//	}
//	for (int i = numberOfSeats3; i < numberOfSeats4; i++)
//	{
//		rowname.addSeats(auxType4);
//	}
//	for (int i = numberOfSeats4; i < numberOfSeats5; i++)
//	{
//		rowname.addSeats(auxType5);
//	}
//	for (int i = numberOfSeats5; i < numberOfSeats6; i++)
//	{
//		rowname.addSeats(auxType6);
//	}
//	for (int i = numberOfSeats6; i < numberOfSeats7; i++)
//	{
//		rowname.addSeats(auxType7);
//	}
//	for (int i = numberOfSeats7; i < numberOfSeats8; i++)
//	{
//		rowname.addSeats(auxType8);
//	}
//	for (int i = numberOfSeats8; i < numberOfSeats9; i++)
//	{
//		rowname.addSeats(auxType9);
//	}
//	for (int i = numberOfSeats9; i < numberOfSeats10; i++)
//	{
//		rowname.addSeats(auxType10);
//	}
//	for (int i = numberOfSeats10; i < numberOfSeats11; i++)
//	{
//		rowname.addSeats(auxType11);
//	}
//	for (int i = numberOfSeats11; i < numberOfSeats12; i++)
//	{
//		rowname.addSeats(auxType12);
//	}
//}