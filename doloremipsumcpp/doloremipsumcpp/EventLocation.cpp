
/*

#include "EventLocation.h"
#include "Event.h"
//#include"Ticket.h"
#include<iostream>
using namespace std;








int main() {
    int const rows = 6;
    int const seatsPerRow = 10;
    int const auxNoZones = 2;

    int locuri1[rows * seatsPerRow];

    for (int i = 0; i < 30; i++)
    {
        locuri1[i] = 1;              /////////////im filling the first 30 seats
    }


    for (int i = 30; i < rows * seatsPerRow; i++)
    {
        locuri1[i] = 1;              /////////////im decalring as empty the last 30 seats
    }

    EventPlace event1(rows, seatsPerRow, auxNoZones, typeOfPlace::STADIUM, locuri1);

    cout << endl << "**TESTING THE OUTPUT OPERATOR FOR EVENTPLACE**";
    cout << event1;





    cout << endl << endl << endl << endl;

    cout << endl << "***************testing the postfix operator for EventPlace class";

    EventPlace auxEvent;

    auxEvent = event1++;


    cout << endl << "**************HERE THE 2ST EVENTPLACE HAS TO BE ALLOCATED WITH 2 ZONES(copy.noZones++). IT IS POSTINCREMENTATION, IT SHOULD'T MODIFY THE IT HERE. here we only assignate!";

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << auxEvent;  ////this one will have exactly the number of events I have in event one, since is post incrementation.
    //NOW LET SEE HOW MANY ZONES i have in event 1, after the post incrementation


    cout << endl << "*********HERE THE 1ST EVENTPLACE HAS TO BE ALLOCATED WITH 3 ZONES(2++)";
    cout << event1; ////this one has to have 3 nr of zones. It has

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl << "testing the prefix operator for EventPlace class";

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;


    EventPlace auxNewEvent;
    auxNewEvent = ++event1;
    cout << endl << "***********************Here we shall have the number of zones=3, since it takes the nr of zones of auxEvent(which is 2) preincremented";
    cout << auxNewEvent;
    cout << endl;
    cout << endl;
    cout << endl << "*********HERE THE 1ST EVENTPLACE HAS TO BE ALLOCATED WITH 4 ZONES(++3)l but it really didn't matter if post or pre. The event passed with incrementation always takes last value.";

    cout << event1;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;


    cout << endl << "Testing the cast operator: It shall pass the number of rows on an object of type EVENTPLACE to a  new defined var of type int (since the noRows is int).";

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl << "**We know it shall be 6!******";

    int testCastToIntOperator = int(event1);
    cout << endl << "The number of rows of the first defined EVENTPLACE passed by AN EXPLICIT CAST OPERATOR is:" << testCastToIntOperator;

    cout << endl << "**Testing the !operator for EVENTPLACE. Ckecking if the event is held in an Event_Hall or not.";
    cout << endl << endl << endl << endl << endl << endl;
    if (!event1)
    {
        cout << endl << "The 1st defined place is not held in an EVENT_HALL!";
    }



    cout << endl << "**Testing the <= operator for EventPlace.    It shall show which events have less or equal noZones than the object to which they are compared*****";
    cout << endl << endl << endl << endl << endl << endl;

    EventPlace fourthEventPlace(9, 15, 4, typeOfPlace::SQUARE, locuri1);   ///this one is a protest

    if (fourthEventPlace <= event1)
    {
        cout << endl << "The 4th event palce has less or equal noZones than the fisrts defined palce";
    }
    else
    {
        cout << endl << "The 4th event palce DOES NOT HAVE less or equal noZones than the fisrts defined palce";

    }

    cout << endl << endl << endl << endl;

    cout << endl << "Now we are testing the == operator for two objects(Event places) which I selected to be the same!";

    if (auxEvent == auxNewEvent)
    {
        cout << endl << "This events are the same!";
    }
    else
    {
        cout << endl << "The events are different!";
    }


    cout << endl << endl << endl << endl << endl << endl << endl;
    cout << endl << endl << endl << endl << endl << endl << endl;


    cout << endl << "Using the 2 generic methods FOR CLASS EVENTPLACE";
    if (!event1.isProtest())
    {
        cout << endl << " event1 is not a protest!";
    }

    event1.changeNameToSquare();
    cout << endl << event1;

    if (event1.isProtest())
    {
        cout << endl << "now, event1 is not a protest!";
    }







    cout << endl << endl << endl << endl << endl << endl << endl;

    cout << "NOW LET'S CHECK THE OPERATORS FOR a new calss:EVENT";

    cout << endl << endl << endl << endl;




    cout << endl << "**TESTING THE OUTPUT OPERATOR for event**";





    ///ACESTA                         ESTE                          PRIMUL                     EVENT               DEFINED.     i use this one for testing almost all operators

    Event event2("Cupa Romaniei", "15/04/24", "15:00", 8);








    cout << event2;
    cout << endl << "***********Testing the - operator fo the previous ranking of the 1st defined event. The grade was 8. now it shall be 7";
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


    cout << endl << "**Checking the equal operator for 2 events. Testing self equality.";

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

    cout << endl << "Testing ther generic methods for calss EVENT";

    if (!event2.isTheEventHappeningInJanuary())
    {

        cout <<endl<<endl<<endl<< "This event is not occurig in january!";
    }


    if (!event2.isOccuringInaSqaure())
    {
        cout << endl << endl << endl << "This event is definitely not a protest!";
    }



}

*/