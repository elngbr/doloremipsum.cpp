


#include "EventLocation.h"
#include<iostream>
using namespace std;


/*
Definition of at least 5 classes related to the project requirement:

Each class must contain at least one dynamically defined field managed by a pointer and at least one statically defined array; both character strings (char* or string*) and vectors of numerical values must be taken into account
at least one class defines a static field
at least one class defines a constant field
all attributes are defined on the private area of the class
for each attribute, a public interface (accessory functions) is defined that allows reading and writing the value; setter methods must validate input values and throw exception if they are not valid
each class contains at least 2 generic methods for processing/displaying the attributes
each class contains at least 2 constructors with parameters, a copy constructor, a destructor and the overloaded form of the operator =
>> and << must be overloaded for each class
for each class, the following must be overloaded: indexing operator [], at least one mathematical operator (+,-,* or /), ++ or -- (with the 2 forms), the cast operator (to any type) explicitly or implicitly, the negation operator !, a conditional operator (<.>,=<,>=), operator for testing equality between 2 objects ==
All classes can be defined in a single source file or in separate header files

Solution main method can be placed in another source file

Phase 1 is considered completed if at least 75% of the requirements are implemented*/






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


    //Event event2("Cupa Romaniei", "15/04/24", "15:00");


   

    //cout << event2;

    Ticket event3(STAND1, "01/01/24");
    cout << endl << endl << endl << endl;
    cout << endl << "**TESTING THE OUTPUT OPERATOR for TICKET**";

    cout << event3;

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
        cout <<endl<<"The 1st defined place is not held in an EVENT_HALL!";
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

    cout << "NOW LET'S CHECK THE OPERATORS FOR EVENTS";

    cout << endl << endl << endl << endl;
    cout << endl << "**TESTING THE OUTPUT OPERATOR for event**";
    Event event2("Cupa Romaniei", "15/04/24", "15:00", 8);
    cout << event2;
    cout<<endl << "***********Testing the - operator fo the previous ranking of the 1st defined event. The grade was 8. now it shall be 7";
    Event eventA = event2 - 1; ///aparent trebuia sa fac constructorul const :)

    cout << endl << eventA;

    cout << endl << "****************Now, we shall ckeck is the operator + really modified my first defined event. I SHOULDN'T, SINCE it's neither postfix, nor pre:) . TAKE CARE IN HERE";
    cout << endl << event2;


    char* testCastToDate = static_cast<char*>(event2);              ///actualy thats why strcpy was created!!!!!!!!!!!!!!!!!

    cout << testCastToDate;

}



