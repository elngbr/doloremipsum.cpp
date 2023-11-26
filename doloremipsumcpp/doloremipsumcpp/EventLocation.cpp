/*

#include "EventLocation.h"
#include<iostream>
using namespace std;


int main()



{


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

    cout << endl << endl << endl << "Testing the 2nd ctor with parameters";

    EventPlace alpha(OPERA_HOUSE);
    cout << alpha;

    cout <<endl<<endl<< endl << "testing the input operator for class EventPlace";
    EventPlace location;
    cin >> location;

    cout << location;

}

*/