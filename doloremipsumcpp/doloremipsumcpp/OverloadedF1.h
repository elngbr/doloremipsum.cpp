

#pragma once
#include "elenaRows.h"
#include "elenaSeats.h"
#include "elenaZones.h"
#include "elenaLocations.h"
#include "elenaEvents.h"
#include<string>
#include<iostream>
#include<fstream>
void addLocations(Event& auxEvent, int locationsNumber1, Location auxLocation1)
{
    for (int i = 0; i < locationsNumber1; i++)
    {
        auxEvent.addLocations(auxLocation1);
    }

}

void addLocations(Event& auxEvent, int locationsNumber1, Location auxLocation1, int locationsNumber2, Location auxLocation2)
{
    for (int i = 0; i < locationsNumber1; i++)
    {
        auxEvent.addLocations(auxLocation1);
    }
    for (int i = locationsNumber1; i < locationsNumber2; i++)
    {
        auxEvent.addLocations(auxLocation2);
    }
}

void addLocations(Event& auxEvent, int locationsNumber1, Location auxLocation1, int locationsNumber2, Location auxLocation2, int locationsNumber3, Location auxLocation3)
{
    for (int i = 0; i < locationsNumber1; i++)
    {
        auxEvent.addLocations(auxLocation1);
    }
    for (int i = locationsNumber1; i < locationsNumber2; i++)
    {
        auxEvent.addLocations(auxLocation2);
    }
    for (int i = locationsNumber2; i < locationsNumber3; i++)
    {
        auxEvent.addLocations(auxLocation3);
    }
}