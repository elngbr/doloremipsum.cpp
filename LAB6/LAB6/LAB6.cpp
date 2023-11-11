#include<iostream>
#include<string>

using namespace std;

class Util {
public:
	static char* copyString(const char* string)
	{
		if (string == nullptr)
		{
			return nullptr;

		}

		char* copy = new char[strlen(string) + 1];
		strcpy_s(copy, strlen(string) + 1, string);
		return copy;
	}
};


class Concert {
	const string name = "";
	char* openingBand = nullptr; // 12345678910    11
	char date[11] = "";   ///     dd/mm//yyyy + "\0"  /////vezi ca ti cont de caracterul null la decLarare
	int capacity = 0;
	static int TOTAL_EVENTS;

public:

	static int getTotalNoOfEvents()
	{
		return Concert::TOTAL_EVENTS;
	}

	string getName()
	{
		return this->name;

	}

	char* getOpeningBand()
	{
		char* copy = Util::copyString(this->openingBand);
		return copy;
	}

	void setOpeningBand(const char* auxBand)
	{
		if (auxBand == nullptr)
		{
			throw exception("Wrong number!");
		}

		delete[] this->openingBand;
		this->openingBand = new char[strlen(auxBand) + 1];
		strcpy_s(this->openingBand, strlen(auxBand) + 1, auxBand);

	}

	char* getDate() {  ///vezi aici!!!!!!!!!!!!!!!!!!!!!!
		return Util::copyString(this->date);
	}

	void setDate(const char* newDate) {
		if (strlen(newDate) != 10)
		{
			throw exception("Wrong input!");
		}

		else if (newDate[2] != '/' || newDate[5] != '/')
		{
			throw exception("Wrong format!");

		}
		delete[] this->date;
		strcpy_s(this->date, strlen(newDate) + 1, newDate);
	}

	int getCapacity()
	{
		return this->capacity;
	}

	void setCapacity(int auxCapacity)
	{
		if (auxCapacity == 0)
		{
			throw exception("No capacity!");
		}

		this->capacity = auxCapacity;
		Concert::TOTAL_EVENTS++;
	}



	//default Constructor

	Concert() : name("no name"), capacity(0) {
		this->setOpeningBand("none");
		this->setDate("00/00/0000");

		Concert::TOTAL_EVENTS++;
	}

	///CONSTRUCTOR
	Concert(string name) : name(name), capacity(1000)
	{
		this->setOpeningBand("None");
		this->setDate("00/00/0000");
		Concert::TOTAL_EVENTS++;
	}

	//CONSTRUCTOR
	Concert(string auxNAME, const char* auxDate, string auxBAND, int auxCapacity) : capacity(auxCapacity), name(auxNAME)
	{

		this->setOpeningBand(auxBAND.c_str());
		this->setDate(auxDate);

	}
	//DESTRUCTOR

	~Concert()
	{
		cout << endl << "You used the destructor!!";
		delete[] this->openingBand;
		delete[] this->date;
		Concert::TOTAL_EVENTS--;
	}

	Concert(Concert& c) : name(c.name)
	{
		cout << endl << "You used the copy-constructor!!";

		this->capacity = c.getCapacity();
		this->setDate(c.getDate());
		this->setOpeningBand(c.getOpeningBand());
	}
};

int Concert::TOTAL_EVENTS = 0;

void doSomething(Concert c)
{


}

int main()
{
	cout << endl << "No of concerts: " << Concert::getTotalNoOfEvents();


	Concert concert;

	concert.setCapacity(100);
	concert.setDate("03/06/2024");
	concert.setOpeningBand("Abba");

	Concert concert1("2024 New Year Party", "31/12/2023", "Abba", 100);

	cout << endl << "Date: " << concert.getDate();
	cout << endl << "Name: " << concert.getName();
	cout << endl << "Band: " << concert.getOpeningBand();
	cout << endl << "Capacity: " << concert.getCapacity();

	cout << endl << "No of Concerts: " << Concert::getTotalNoOfEvents();

	cout << endl << "I will ccreate a copy of my concert";

	Concert newConcert = concert;
	cout << endl << "I did a copy of my concert";




	doSomething(concert);
}

