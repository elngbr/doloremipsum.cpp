


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

    int locuri1[rows][seatsPerRow] =
    {
        {0, 0, 1},
        {1, 1, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

    EventPlace event1(rows, seatsPerRow, auxNoZones, typeOfPlace::STADIUM);


    cout << event1;


    Event event2("Cupa Romaniei", "15/04/24", "15:00");

    cout << event2;

    Ticket event3(STAND1, "01/01/24");

    cout << event3;

    //return 0;
}



