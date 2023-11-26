
/*

#include "Ticket.h"
#include<iostream>
using namespace std;




int  main()
{
    cout << "****OFICIALLY TESTING THE OPERATORS FOR CLASS TICKET, THE 3rd class";


    cout << endl << endl << endl;

    Ticket event3(typeOfTicket::STAND1, "15/10/24");
    cout << endl << endl << endl << endl;
    cout << endl << "**TESTING THE OUTPUT OPERATOR for TICKET**";

   cout << event3;


   cout << endl << "***testing the INDEXING OPERATOR MEANT TO CHANGE year in dateOfIssue in 25   (currently ALL objects must be defined as issued in 24).***";
   cout << endl << "***so, this might be a way to trick the setter :):):):):):):)";

    event3[7] =  '5';   ////nu de 8, de 7. YOU COUNT FROM 0 IN programming. 
    cout << endl << "**the dateOfIssue of the event is now:";
    cout << event3.getDateOfIssue();
    cout << endl << endl << endl << "NOW, THE 1st defined ticket looks like this:" << endl;
    cout << event3;


    cout << endl << endl << endl;


    cout << endl << "Testing the + operator";
    Ticket eventZ= 0.8 + event3;
    //event3= event3 + 0.8;                        ///    PENTRU ASA CEVA ITI TREBUIE TESTING SELF EQUALITY CA NU DEGEABA SCRIE IN REQUIREMENTS SA-L DEFINESTI...   WHY DOESN.T IT WORK NOW?

    cout << event3;

    //cout << endl << event3;
    cout << endl << endl << endl;

    cout << endl << "**************************We display the new event";

    cout << endl << eventZ;
    cout << endl << endl << endl;


    cout << endl << "*******Testing the equal operator and the == operator of course";

    Ticket eventY = eventZ;

    if (eventY == eventZ) ///the == operator will receive by DEFAULT THIS as reffering to eventY!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
   {
       cout << endl << "These tickets are equal!";
    }
    else
   {
       cout << endl << "These events aren't equal!";
    }
    cout << endl << endl << endl;

    cout << endl << "***TESTING the ! operator. ALL TICKETS ARE BY DEFAULT BOXES AND the first defined ticket is FOR STAND 1. ";

    if (!event3)
    {
        cout << endl << "This is definitely not a VIP ticket. ";
    }
    else
    {
        cout << endl << "WOW! This is definitely a VIP ticket. ";

    }

    cout << endl << endl << endl;


    cout << endl << "***Testing the > operator to see which tickets were issued for category2";

    cout<<endl << event3;
    cout <<endl<< eventZ;
    cout<<endl << eventY;

    if (event3 > CATEGORY1)
    {
        cout << endl << "For sure, this ticket was issued for Category 2";
    }
    else
    {
        cout << endl << "For sure, this ticket was NOT issued for Category 2";
    }

    cout << endl << endl << endl;

    cout << endl << "***Testing the < operator to see which tickets were issued before 2025 (25). The only event that escape the only_24 condition was by index operator, so we'll try event3";

    if (event3 < '5')
    {
        cout << endl << "This event hasn't been used for index operator or copied after such an ticket";
    }
    else
    {
        cout << endl << "This ticket HAS BEEN used for index operator or copied after such an ticket";

    }
    cout << endl << endl << endl;
    cout << endl << "**Testing the cast operator to double.";
    double testCastOperatorForTicket = 0.0;
    testCastOperatorForTicket = (double)eventZ;

    cout << endl << "After applying the cast operator for the test variable (of type double, initialised at definition with 0.0), this one holds the value" << " " << testCastOperatorForTicket << ".";
   

    cout << endl << "which has to be the id of the 2nd defined event";

    cout << endl << endl << endl;

    cout << endl << "Testing the generic methods for class TICKET.";

    if (!eventY.isVIP())
    {
        cout << "This ticket is not for VIP";
    }

    if (!eventY.isIssuedInOctober())
    {

        cout << endl << endl << endl;

        cout << endl << "This ticket is not occuring in october.";
    }
    else
    {

        cout << endl << endl << endl;
        cout << endl << endl << endl;
        cout << endl << endl << endl;
        cout << endl << endl << endl;
        cout << endl << endl << endl;

        cout <<endl<< "this ticket is issued in october!";
    }


    cout << endl << "**Testing second constructor for ticket";

    Ticket t("12/12/24");
    cout << t;

    cout << endl << "**Testing input operator for class Ticket";

    Ticket newTicket1;

    cin >> newTicket1;
    cout << newTicket1;

    
}
*/


