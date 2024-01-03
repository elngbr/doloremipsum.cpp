

#include "elenaRows.h"
#include "elenaSeats.h"
#include "elenaZones.h"
#include "elenaLocationS.h"
#include "elenaEvents.h"
#include "OverloadedF.h"
#include "OverloadedF1.h"

#include<string>
#include<iostream>
#include<fstream>
using namespace std;

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
	Seat virtualSeat(VIRTUAL);


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
	Row premiumRowWithWheelchair;
	Row childrenRowWithStandardAndWheelchair;
	Row flexibleRow;
	Row virtualRow;

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





	addSeats(standardRow, 15, standardSeat);
	addSeats(studentRowWithWheelchair, 12, studentSeat, Row::MAX_NUMBER_OF_SEATS, wheelchairSeat);
	addSeats(studentRow, Row::MAX_NUMBER_OF_SEATS, studentSeat);
	addSeats(vipRow, Row::MAX_NUMBER_OF_SEATS, vipSeat);
	addSeats(premiumRow, Row::MAX_NUMBER_OF_SEATS, premiumSeat);
	addSeats(coupleRow, Row::MAX_NUMBER_OF_SEATS, coupleSeat);
	addSeats(beanbagRow, 5, beanbagSeat, 10, wheelchairSeat, Row::MAX_NUMBER_OF_SEATS, beanbagSeat);
	addSeats(vipWithWheelchairRow, 10, vipSeat, Row::MAX_NUMBER_OF_SEATS, wheelchairSeat);
	addSeats(premiumRowWithWheelchair, 7, wheelchairSeat, Row::MAX_NUMBER_OF_SEATS, premiumSeat);
	addSeats(childrenRowWithStandardAndWheelchair, 4, childrenSeat, 7, wheelchairSeat, 8, chosenSeat, Row::MAX_NUMBER_OF_SEATS, standardSeat);
	addSeats(flexibleRow, 15, flexibleSeat);
	addSeats(virtualRow, 4, virtualSeat, 7, wheelchairSeat, 8, virtualSeat, Row::MAX_NUMBER_OF_SEATS, wheelchairSeat);

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
	Zone beanbagZone(STAND);
	Zone flexibleRowsZone(NORMAL);
	Zone boxZone(NORMAL);


	///Insertions of rows in zones**********************************************************************************************************************







	addRows(standZone, 3, standardRow, 7, normalRow, Zone::MAX_ROW_IDENTIFIER_PER_ZONE, standardRow);
	addRows(normalZone, Zone::MAX_ROW_IDENTIFIER_PER_ZONE, normalRow);
	addRows(boxZone, Zone::MAX_ROW_IDENTIFIER_PER_ZONE, normalRow);
	addRows(vipZone, 6, vipWithWheelchairRow, Zone::MAX_ROW_IDENTIFIER_PER_ZONE, vipRow);
	addRows(categoryZone, 6, normalRow, Zone::MAX_ROW_IDENTIFIER_PER_ZONE, standardRow);
	addRows(amphitheaterZone, 3, standardRow, 6, studentRow, Zone::MAX_ROW_IDENTIFIER_PER_ZONE, premiumRow);
	addRows(campingZone, 3, beanbagRow, 6, standardRow, Zone::MAX_ROW_IDENTIFIER_PER_ZONE, beanbagRow);
	addRows(premiumZone, 6, premiumRow, 9, premiumRowWithWheelchair, Zone::MAX_ROW_IDENTIFIER_PER_ZONE, premiumRow);
	addRows(familyZone, 3, coupleRow, 12, childrenRowWithStandardAndWheelchair, Zone::MAX_ROW_IDENTIFIER_PER_ZONE, standardRow);
	addRows(studentZone, 3, studentRow, 12, studentRowWithWheelchair, Zone::MAX_ROW_IDENTIFIER_PER_ZONE, studentRow);
	addRows(backstageZone, 3, vipRow, 12, beanbagRow, Zone::MAX_ROW_IDENTIFIER_PER_ZONE, vipWithWheelchairRow);
	addRows(greenZone, Zone::MAX_ROW_IDENTIFIER_PER_ZONE, beanbagRow);
	addRows(sroZone, Zone::MAX_ROW_IDENTIFIER_PER_ZONE, virtualRow);
	addRows(networkingZone, 4, standardRow, 6, virtualRow, 8, flexibleRow, Zone::MAX_ROW_IDENTIFIER_PER_ZONE, beanbagRow);
	addRows(gameZone, 5, virtualRow, 10, beanbagRow, 13, virtualRow, Zone::MAX_ROW_IDENTIFIER_PER_ZONE, beanbagRow);
	addRows(balconyZone, 2, premiumRowWithWheelchair, 2, premiumRow);
	addRows(beanbagZone, 3, beanbagRow);
	addRows(flexibleRowsZone, 6, flexibleRow);





	///Insertions of rows in zones****************************************************************************END





	//************************************************************************************************************************************
	///requested
	Location stadiumLocation(STADIUM);
	Location concertHallLocation(CONCERT_HALL);
	Location operaHouseLocation(OPERA_HOUSE);


	Location eventsHallLocation(EVENTS_HALL);
	Location sportHallLocation(SPORT_HALL);
	Location cinemaHallLocation(CINEMA_HALL);
	Location squareLocation(SQUARE);
	Location theatreLocation(THEATRE);
	Location mallLocation(MALL);
	Location publicInstitutionLocation(PUBLIC_INSTITUTION);
	Location seaLocation(SEA);
	Location forestLocation(FOREST);
	Location mountainLocation(MOUNTAIN);
	Location parkLocation(PARK);
	Location schoolLocation(SCHOOL);
	Location libraryLocation(LIBRARY);
	Location cemeteryLocation(CEMETERY);
	Location restaurantLocation(RESTAURANT);



	////Insertions for zones in Locations*************************************************************************************************************





	addZones(stadiumLocation, 2, standZone);//requested
	addZones(cinemaHallLocation, 1, normalZone, 2, vipZone);//requested
	addZones(theatreLocation, 2, categoryZone, 3, boxZone);//requested







	addZones(concertHallLocation, 1, premiumZone, 2, vipZone, 3, normalZone, 4, balconyZone, 5, amphitheaterZone, Location::MAX_IDENTIFIER_OF_ZONE, sroZone);
	addZones(operaHouseLocation, 1, premiumZone, 2, amphitheaterZone, 4, standZone, Location::MAX_IDENTIFIER_OF_ZONE, balconyZone);
	addZones(eventsHallLocation, 2, standZone, 4, normalZone, 5, amphitheaterZone, 6, balconyZone);
	addZones(sportHallLocation, 1, premiumZone, Location::MAX_IDENTIFIER_OF_ZONE, standZone);
	addZones(mallLocation, 1, vipZone, 2, sroZone, 3, beanbagZone);
	addZones(squareLocation, Location::MAX_IDENTIFIER_OF_ZONE, sroZone);
	addZones(publicInstitutionLocation, 1, standZone, 5, networkingZone);
	addZones(seaLocation, 1, greenZone, 3, flexibleRowsZone, Location::MAX_IDENTIFIER_OF_ZONE, sroZone);
	addZones(forestLocation, 3, greenZone, 5, sroZone);
	addZones(mountainLocation, 3, standZone, 4, vipZone, 5, premiumZone, Location::MAX_IDENTIFIER_OF_ZONE, normalZone);
	addZones(parkLocation, 2, sroZone, 4, standZone, Location::MAX_IDENTIFIER_OF_ZONE, normalZone);
	addZones(schoolLocation, 5, studentZone, Location::MAX_IDENTIFIER_OF_ZONE, standZone);
	addZones(libraryLocation, 1, sroZone, 2, beanbagZone);
	addZones(cemeteryLocation, 1, sroZone);
	addZones(restaurantLocation, 3, restaurantZone, 5, networkingZone);

	////Insertions for zones in Locations*************************************************************************************************************END



	/////*************************************************************************************************************************************************

	/*Event event("Cupa Romaniei");
	event.addLocations(stadiumLocation);
	event.addLocations(stadiumLocation);

	addLocations(event, 1, stadiumLocation, 2, publicInstitutionLocation);

	cout << event;*/










	///requested events
	Event EURO2024("EURO2024", "14/06/24");
	Event Filantropica("Filantropica", "01/04/25");
	Event Straini_in_noapte("Straini in noapte", "03/07/26");


	//requested locations
	EURO2024.addLocations(stadiumLocation);
	Filantropica.addLocations(cinemaHallLocation);
	Straini_in_noapte.addLocations(theatreLocation);

	//cout << EURO2024;
	//cout << Filantropica;
	//cout << Straini_in_noapte;

	int asciiCode = 65;  // ASCII code for 'A'
	char character = static_cast<char>(65);

	// Print the result
	cout << "ASCII Code: " << asciiCode << ", Character: " << character << endl;


	Row c;

	c.addSeats(Seat(SeatType::STANDARD));
	c.addSeats(Seat(SeatType::STANDARD));
	c.addSeats(Seat(SeatType::STANDARD));
	c.addSeats(Seat(SeatType::STANDARD));
	c.addSeats(Seat(SeatType::STANDARD));


	cout << c;



}