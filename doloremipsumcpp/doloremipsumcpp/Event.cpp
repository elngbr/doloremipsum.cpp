
/*
#include "Event.h"
//#include"Ticket.h"
#include<iostream>
using namespace std;








int main() {
    int const rows = 6;
    int const seatsPerRow = 10;
    int const auxNoZones = 2;

    int locuri1[rows * seatsPerRow];

    cout << "NOW LET'S CHECK THE OPERATORS FOR a new calss:EVENT";

    cout << endl << endl << endl << endl;




    cout << endl << "**TESTING THE OUTPUT OPERATOR for event**";





    ///ACESTA                         ESTE                          PRIMUL                     EVENT               DEFINED.     i use this one for testing almost all operators

    Event event2("Cupa Romaniei", "15/04/24", "15:00", 8);








    cout << event2;
    cout << endl << "***********Testing the - operator for the previous ranking of the 1st defined event. The grade was 8. now it shall be 7";
    Event eventA = event2 - 1; ///aparent trebuia sa fac constructorul const :)

    cout << endl << eventA;

    cout << endl << "****************Now, we shall ckeck is the operator + really modified my first defined event. I SHOULDN'T, SINCE it's neither postfix, nor pre:) . TAKE CARE IN HERE";
    cout << endl << event2;

    cout << endl << "****WE CHECK THE CAST OPERATOR FOR CHAR*.   PARTICULAR CASE:   WE ASSIGN BY STRCPY_S, SINCE THEY ARE ARRAYS OF CHARACTERS!!!!";
    char* testCastToDate = new char[9];

    strcpy_s(testCastToDate, strlen(testCastToDate) + 1, static_cast<char*>(event2));              ///actually thats why strcpy was created!!!!!!!!!!!!!!!!!

    cout << endl << "The date of the 1st defined event is" << " " << testCastToDate;


    cout << endl << "***WE are checking the indexing operator for char. Is meant to make the event start at A PARTICULAR TIME which ends in 1.";
    cout << endl << "**So if the event started at 15:00, now it'll start at 15:01";

    event2 = event2(4, '1');

    cout << endl << event2;


    cout << endl << "*********Checking the equal operator for 2 events. Testing self equality.";

    Event eventX = event2;

    // event2 = event2;

    if (eventX == event2)
    {
        cout << endl << "They are equal.";
    }
    else
    {
        cout << endl << "They are not equal.";
    }
    cout << endl << endl << endl;
    cout << endl << "****Checking the ! operator for an object of type event. checks the typeOfEvent. default is always football. Since none of my ctors receives the type, all are footballs ";
    cout << endl << endl << endl << endl << endl << endl;
    cout << endl << "********So if my ! operator checks if the event is a fair (which is actually what it does), it shall be false for all objects, regardless of the constructor they are build with";



    cout << endl << "************************************************";
    if (!event2)
    {
        cout << endl << "The event is not a fair!";
    }
    else
    {
        cout << endl << "The event is a fair!";
    }


    cout << endl << endl << endl << endl << endl << endl << endl << endl;

    cout << endl << "****************Testing ther generic methods for calss EVENT";

    if (!event2.isTheEventHappeningInJanuary())
    {

        cout << endl << endl << endl << "This event is not occurig in january!";
    }


    if (!event2.isOccuringInaSqaure())
    {
        cout << endl << endl << endl << "This event is definitely not a protest!";
    }


    cout << endl<<endl<<endl<<endl << "************88Testing the second ctor for class Event";

    Event eventAlpha("EventAlpha", "25/12/24", "18:00");
    cout << eventAlpha;

    cout << endl<<endl<<endl<<endl << "**Testing input oprator for class Event";

    Event newEvent;
    cin >> newEvent;
    cout << newEvent;

}
*/
