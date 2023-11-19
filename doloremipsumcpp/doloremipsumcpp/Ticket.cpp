


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

    event3[7] =  '5';   ////nu de 8, de 7. YOU COUNT FROM 0 IN programming. and 
    cout << endl << "**the dateOfIssue of the event is now:";
    cout << event3.getDateOfIssue();
    cout << endl << endl << endl << "NOW, THE 1st defined ticket looks like this:" << endl;
    cout << event3;

    event3= 0.8 + event3;

    cout << event3;
}

