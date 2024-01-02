

#include "elenaRows.h"
#include "elenaSeats.h"
#include "elenaZones.h"
#include "OverloadedF.h"
#include<string>
#include<iostream>
#include<fstream>

int main()

{

	Seat standardSeat(STANDARD);
	Seat wheelchairSeat(WHEELCHAIR);
	Seat brokenseat(BROKEN);
	Seat occupiedSeat(OCCUPIED);
	Seat chosenSeat(CHOSEN);
	Seat studentSeat(STUDENT);
	Seat childrenSeat(CHILDREN);
	Seat coupleSeat(COUPLE);
	Seat flexibleSeat(FLEXIBLE);
	Seat vipSeat(VIP);
	Seat premiumSeat(PREMIUM);
	Seat beanbagSeat(BEANBAG);


	///creating a normal row with: 
	//first 5 seats=STANDARD,
	//the 6th OCCUPIED,
	//THE 7th STUDENT,
	//the 8th BROKEN,
	//the 9th&10th STUDENT,
	//11th&12th&13th STANDARD
	//the 14th OCCUPIED
	//the 15th CHILDREN

	Row normalRow;///////The best row to add anywhere, a combo of them all
	Row standardRow;///Creating a standard row full of standard seats
	Row studentRowWithWheelchair;//Creating a student row with 11 student seats and 4 wheelchairs
	Row studentRow;//full of student rows
	Row vipRow; //full of VIP
	Row premiumRow;//full of premium
	Row coupleRow;//full of couple
	Row beanbagRow;///full of beanbags
	Row vipWithWheelchairRow;
	normalRow.addSeats(standardSeat); //1st row
	normalRow.addSeats(standardSeat);
	normalRow.addSeats(standardSeat);
	normalRow.addSeats(standardSeat);
	normalRow.addSeats(standardSeat);
	normalRow.addSeats(occupiedSeat);
	normalRow.addSeats(studentSeat);
	normalRow.addSeats(brokenseat);
	normalRow.addSeats(studentSeat);
	normalRow.addSeats(studentSeat);
	normalRow.addSeats(standardSeat);
	normalRow.addSeats(wheelchairSeat);
	normalRow.addSeats(wheelchairSeat);
	normalRow.addSeats(occupiedSeat);
	normalRow.addSeats(childrenSeat);



	///Initializations for all rows created ********************************************************************************************

	/*for (int i = 0; i < Row::MAX_NUMBER_OF_SEATS; i++)
	{
		standardRow.addSeats(standardSeat);
	}*/

	addSeats(standardRow, 15, standardSeat);



	/*for (int i = 0; i < 12; i++)
	{
		studentRowWithWheelchair.addSeats(studentSeat);
	}
	for (int i = 12; i < Row::MAX_NUMBER_OF_SEATS; i++)
	{
		studentRowWithWheelchair.addSeats(wheelchairSeat);
	}*/
	addSeats(studentRowWithWheelchair, 12, studentSeat, Row::MAX_NUMBER_OF_SEATS, wheelchairSeat);




	/*for (int i = 0; i < Row::MAX_NUMBER_OF_SEATS; i++)
	{
		studentRow.addSeats(studentSeat);
	}*/
	addSeats(studentRow, Row::MAX_NUMBER_OF_SEATS, studentSeat);


	/*for (int i = 0; i < Row::MAX_NUMBER_OF_SEATS; i++)
	{
		vipRow.addSeats(vipSeat);
	}*/

	addSeats(vipRow, Row::MAX_NUMBER_OF_SEATS, vipSeat);

	/*for (int i = 0; i < Row::MAX_NUMBER_OF_SEATS; i++)
	{
		premiumRow.addSeats(premiumSeat);
	}*/
	addSeats(premiumRow, Row::MAX_NUMBER_OF_SEATS, premiumSeat);




	/*for (int i = 0; i < Row::MAX_NUMBER_OF_SEATS; i++)
	{
		coupleRow.addSeats(coupleSeat);
	}*/

	addSeats(coupleRow, Row::MAX_NUMBER_OF_SEATS, coupleSeat);

	/*for (int i = 0; i < Row::MAX_NUMBER_OF_SEATS; i++)
	{
		beanbagRow.addSeats(beanbagSeat);
	}*/

	addSeats(beanbagRow, Row::MAX_NUMBER_OF_SEATS, beanbagSeat);

	/*for (int i = 0; i < 10; i++)
	{
		vipWithWheelchairRow.addSeats(vipSeat);
	}

	for (int i = 10; i < Row::MAX_NUMBER_OF_SEATS; i++)
	{
		vipWithWheelchairRow.addSeats(wheelchairSeat);
	}*/
	addSeats(vipWithWheelchairRow, 10, vipSeat, Row::MAX_NUMBER_OF_SEATS, wheelchairSeat);

	cout << vipWithWheelchairRow;
	// *********************************************************************************************************************************************


	Zone standZone(STAND); ////standard, standardwithwhellchair, students
	Zone normalZone(NORMAL);
	Zone vipZone(VIPZ);
	Zone categoryZone(CATEGORY);
	Zone campingZone(CAMPING);
	Zone premiumZone(PREMIUMZ);
	Zone familyZone(FAMILY);
	Zone studentZone(STUDENTZ);
	Zone backstageZone(BACKSTAGE);
	Zone greenZone(GREEN);
	Zone sroZone(SRO);
	Zone networkingZone(NETWORKING);
	Zone gameZone(GAME);
	Zone restaurantZone(FOOD);
	Zone balconyZone(BALCONY);
	Zone amphitheaterZone(AMPHITHEATER);


	///Insertions of rows in zones**********************************************************************************************************************




	///**************************************************************************************************************************************************

	for (int i = 0; i < 3; i++)
	{
		standZone.addRows(standardRow);
	}
	for (int i = 3; i < 7; i++)
	{
		standZone.addRows(normalRow);
	}
	for (int i = 7; i < Zone::MAX_ROW_IDENTIFIER_PER_ZONE; i++)
	{
		standZone.addRows(standardRow);
	}





	for (int i = 0; i < Zone::MAX_ROW_IDENTIFIER_PER_ZONE; i++)
	{
		normalZone.addRows(normalRow);
	}


	for (int i = 0; i < 6; i++)
	{
		vipZone.addRows(vipWithWheelchairRow);
	}

	for (int i = 6; i < Zone::MAX_ROW_IDENTIFIER_PER_ZONE; i++)
	{
		vipZone.addRows(vipRow);
	}


	for (int i = 0; i < 6; i++)
	{
		categoryZone.addRows(normalRow);
	}

	for (int i = 6; i < Zone::MAX_ROW_IDENTIFIER_PER_ZONE; i++)
	{
		vipZone.addRows(standardRow);
	}

	for (int i = 0; i < 3; i++)
	{
		amphitheaterZone.addRows(premiumRow);
	}
	for (int i = 3; i < 6; i++)
	{
		categoryZone.addRows(standardRow);
	}

	for (int i = 6; i < Zone::MAX_ROW_IDENTIFIER_PER_ZONE; i++)
	{
		vipZone.addRows(studentRow);
	}



}