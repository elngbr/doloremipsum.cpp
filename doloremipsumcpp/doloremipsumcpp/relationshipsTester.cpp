#include "elenaRows.h"
#include "elenaSeats.h"
#include "elenaZones.h"
#include<string>
#include<iostream>
#include<fstream>

class Row;
class Seat;
class Zone;
void decodeSeats(int noSeats)
{
	while (noSeats < 0 || noSeats > Row::MAX_NUMBER_OF_SEATS)
	{
		cout << "No seats less than 0 ore more than 15. Please insert again no of seats:";
		cin >> noSeats;

	}


}

void decodeRows(int noRows)
{
	while (noRows < 0 || noRows > Row::MAX_ROW_IDENTIFIER)
	{
		cout << "No rows less than 0 ore more than 50. Please insert again no of rows:";
		cin >> noRows;

	}
}

void decodeTypeOfSeat(int auxType)
{
	while (auxType != 0 && auxType != 1 && auxType != 2 && auxType != 3 && auxType != 4)
	{
		cout << endl << "Your choice is not from the available set. Insert type again:";


		cin >> auxType;
	}


}

void decodeRowIdentifier(int auxRowIdentifier, int noRows)
{
	if (auxRowIdentifier<0 || auxRowIdentifier>noRows)
	{
		cout << "The identifier cannot be negative.Please insert a positive unique value.";
		cin >> auxRowIdentifier;
	}
}
int main() {


	int  noSeats = 0;
	int noRows = 0;



	cout << "Please insert no of rows:";
	cin >> noRows;

	decodeRows(noRows);

	cout << "Please insert no of seats per row:";
	cin >> noSeats;

	decodeSeats(noSeats);




	Seat normalCollectionOfSeats[15]
	{
		Seat(1, STANDARD),
		Seat(2, STANDARD),
		Seat(3, STANDARD),
		Seat(4, STANDARD),
		Seat(5, STANDARD),
		Seat(6, PREMIUM),
		Seat(7,PREMIUM),
		Seat(8, PREMIUM),
		Seat(9, COUPLE),
		Seat(10, STANDARD),
		Seat(11, STANDARD),
		Seat(12, WHEELCHAIR),
		Seat(13, WHEELCHAIR),
		Seat(14, STANDARD),
		Seat(15, STUDENT)
	};

	Seat standardCollectionOfSeatsWithBrokenChair[15]
	{
		Seat(1, STANDARD),
		Seat(2, STANDARD),
		Seat(3, STANDARD),
		Seat(4, STANDARD),
		Seat(5, STANDARD),
		Seat(6, PREMIUM),
		Seat(7,PREMIUM),
		Seat(8, PREMIUM),
		Seat(9, COUPLE),
		Seat(10, BROKEN),
		Seat(11, BROKEN),
		Seat(12, WHEELCHAIR),
		Seat(13, WHEELCHAIR),
		Seat(14, STANDARD),
		Seat(15, STUDENT)
	};

	Seat standardCollectionOfSeats[15]
	{
		Seat(1, STANDARD),
		Seat(2, STANDARD),
		Seat(3, STANDARD),
		Seat(4, STANDARD),
		Seat(5, STANDARD),
		Seat(6, STANDARD),
		Seat(7,STANDARD),
		Seat(8,STANDARD),
		Seat(9,STANDARD),
		Seat(10,STANDARD),
		Seat(11,STANDARD),
		Seat(12,STANDARD),
		Seat(13,STANDARD),
		Seat(14,STANDARD),
		Seat(15,STANDARD)
	};




	Seat standardCollectionOfSeatsWithWheelchairs[15]
	{
		Seat(1, STANDARD),
		Seat(2, STANDARD),
		Seat(3, STANDARD),
		Seat(4, CHILDREN),
		Seat(5, COUPLE),
		Seat(6, BROKEN),
		Seat(7, STANDARD),
		Seat(8, STANDARD),
		Seat(9, STANDARD),
		Seat(10, STANDARD),
		Seat(11, STANDARD),
		Seat(12, WHEELCHAIR),
		Seat(13, WHEELCHAIR),
		Seat(14, STANDARD),
		Seat(15, STANDARD)
	};

	Seat vipCollectionOfSeatsWithWhellchairAndPremium[15]
	{
		Seat(1, VIP),
		Seat(2, VIP),
		Seat(3, VIP),
		Seat(4, VIP),
		Seat(5, PREMIUM),
		Seat(6, PREMIUM),
		Seat(7, VIP),
		Seat(8, VIP),
		Seat(9, VIP),
		Seat(10,VIP),
		Seat(11,VIP),
		Seat(12,WHEELCHAIR),
		Seat(13,WHEELCHAIR),
		Seat(14,WHEELCHAIR),
		Seat(15,WHEELCHAIR)
	};
	
	///*********************************************************************************************************************************************************************8


	//Row normalRows[Row::MAX_ROW_IDENTIFIER];



	//for (int i = 0; i < Row::MAX_ROW_IDENTIFIER; i++)
	//{
	//	normalRows[i]=Row(i+1, normalCollectionOfSeats[0]);

	//	for (int j = 1; j < Row::MAX_IDENTIFIER_OF_SEAT; j++)
	//	{
	//		normalRows[i].addSeats(normalCollectionOfSeats[j]);
	//	}
	//}
	///*for (int i = 0; i < Row::MAX_ROW_IDENTIFIER; i++)
	//cout << normalRows[i];*/

	//Row standardRows[Row::MAX_ROW_IDENTIFIER];
	//for (int i = 0; i < Row::MAX_ROW_IDENTIFIER; i++)
	//{
	//	standardRows[i] = Row(i + 1, standardCollectionOfSeats[0]);

	//	for (int j = 1; j < Row::MAX_IDENTIFIER_OF_SEAT; j++)
	//	{
	//		standardRows[i].addSeats(standardCollectionOfSeats[j]);
	//	}
	//}

	////for (int i = 0; i < Row::MAX_ROW_IDENTIFIER; i++)
	////	cout << standardRows[i];


	//Row standardRowsWithBrokenChair[Row::MAX_ROW_IDENTIFIER];
	//for (int i = 0; i < Row::MAX_ROW_IDENTIFIER; i++)
	//{
	//	standardRowsWithBrokenChair[i] = Row(i + 1, standardCollectionOfSeatsWithBrokenChair[0]);

	//	for (int j = 1; j < Row::MAX_IDENTIFIER_OF_SEAT; j++)
	//	{
	//		standardRowsWithBrokenChair[i].addSeats(standardCollectionOfSeatsWithBrokenChair[j]);
	//	}
	//}




	//Row standardRowsWithWheelchairs[Row::MAX_ROW_IDENTIFIER];
	//for (int i = 0; i < Row::MAX_ROW_IDENTIFIER; i++)
	//{
	//	standardRowsWithWheelchairs[i] = Row(i + 1, standardCollectionOfSeatsWithWheelchairs[0]);

	//	for (int j = 1; j < Row::MAX_IDENTIFIER_OF_SEAT; j++)
	//	{
	//		standardRowsWithWheelchairs[i].addSeats(standardCollectionOfSeatsWithWheelchairs[j]);
	//	}
	//}


	///*for (int i = 0; i < Row::MAX_ROW_IDENTIFIER; i++)
	//	cout << standardRowsWithWheelchairs[i];*/

	//Row vipRowsWithWheelchairAndPremium[Row::MAX_ROW_IDENTIFIER];
	//for (int i = 0; i < Row::MAX_ROW_IDENTIFIER; i++)
	//{
	//	vipRowsWithWheelchairAndPremium[i] = Row(i + 1, vipCollectionOfSeatsWithWhellchairAndPremium[0]);

	//	for (int j = 1; j < Row::MAX_IDENTIFIER_OF_SEAT; j++)
	//	{
	//		vipRowsWithWheelchairAndPremium[i].addSeats(vipCollectionOfSeatsWithWhellchairAndPremium[j]);
	//	}
	//}

	//for (int i = 0; i < Row::MAX_ROW_IDENTIFIER; i++)
	//	cout << vipRowsWithWheelchairAndPremium[i];

	/////********************************************************************************************************************************************************************************

	////enum zoneType { STAND, NORMAL, VIP, CATEGORY, CAMPING, PREMIUM, FAMILY, STUDENT, BACKSTAGE, GREEN, SRO, NETWORKING, GAME, RESTAURANT, BALCONY, AMPHITEATHER };








	/////*******************************************************************************************************************************************************************************
	//Zone standZone[Zone::MAX_ZONE_IDENTIFIER];

	//for (int i = 0; i < Zone::MAX_ZONE_IDENTIFIER; i++)
	//{
	//	standZone[i] = Zone(i + 1, standardRows[0]);

	//	for (int j =0; j < 4;j++)
	//	{
	//		standZone[i].addRows(j, standardRows[j]);
	//	}

	//	for (int j = 4; j<6; j++)
	//	{
	//		standZone[i].addRows(j, standardRowsWithWheelchairs[j]);

	//	}

	//	
	//}



	Seat seat(BROKEN);
	//cout << seat;
	Row row(seat);
	Zone zone(row);

	cout << zone;
	

}