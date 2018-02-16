#include <iostream>
#include <string>

#include "parkinglot.h"

using namespace std;

void printAvailableSpaces(char[], int, bool[]);

parkinglot::parkinglot(string typeOfCar, string size)
{
    TypeOfCar = typeOfCar;
    CarSize = size;
}

parkinglot::~parkinglot()
{
    cout << "Leaving parking lot..." << endl;
}

int parkinglot::getHours()
{
    short int hours;
    do {
        cout << "Number of hours: ";
        cin >> hours;

        if (hours > MAX_HOURS) {
            cout << "The maxuim number of hours is " << MAX_HOURS << endl;
        }
    } while( !cin.fail() || ( hours >= 0 || hours <= MAX_HOURS ) );

    return hours;
}

/**
* This creates the bill for the ticket depending on the hours
*/
void parkinglot::formulateTicket()
{
    bill = (double) hours * TOLL;
    return printTicket();
}

/**
* Prints the price of the ticket, including the ammount of hours
* they are spending, and where they are parked at.
*/
void parkinglot::printTicket()
{
    cout << "Hours: " << hours << endl;
    cout << "Bill: " << bill << endl;

    if ( level == 0 || space == 0 ) {
        cout << "You do not have a parking space, You hours will be affected " <<
        "When you find a parking space." << endl;
    } else {
        cout << "You are parked at ";
        parkedAt(level, space);
    }
}

/**
* Returns a bolean value wether ther parking lot is available ot not.
*/
bool parkinglot::isParkinglotFull() {
    int spacesArraylen = sizeof(spaces)/sizeof(spaces[0]);
    for (int i = 0; i < spacesArraylen; i++) {
        for (int j = 0; i < spacesArraylen; j++) {
            if (!spaces[i][j]) {
                return false;
            }
        }
    }
    return true;
}

/**
* prints the location in which the car is parked ( human readable ).
*/
void parkinglot::parkedAt(int level, int space)
{
    cout << levels[level] << "-" << space << endl;
}

/**
* Sets the new level
*/
void parkinglot::setLevel(int newLevel)
{
    level = newLevel;
}

/**
* Prints the avaibles spaces on a certain level
*/
void parkinglot::printAvailableSpaces(bool parkingLevel[])
{
    int spacesArraylen = sizeof(spaces)/sizeof(spaces[0]);
    for (int i = 0; i < spacesArraylen; i++) {
        cout << "Availables Spaces on \'" << levels[level] << "\'" << endl;
        cout << "\n______________________________" << endl << "|";

        if ( parkingLevel[i] ) {
            cout << "taken ";
        } else {
            cout << "free";
        }

        if ( i == 4) {
            cout << "|" << endl;
        } else {
            cout << " | ";
        }
    }

    cout << "\n______________________________" << endl;
}


/**
* sets the location on the level and the space the car is parked at.
* And assigns true the false value space in the space multi deminsonal array.
*/
void parkinglot::park(int space)
{
    if ( isSpaceOccupied(level, space) ) {
        return setLevel(level + 1);
    }

    // printAvailableSpaces(levels, spaces[level], spaces);
}

/**
* returns a boolean value of wether a space is occupied or not.
*/
bool parkinglot::isSpaceOccupied(int level, int space)
{
    return spaces[level][space];
}

/**
* returns a boolean value of wether a whole level is occupied.
*/
bool parkinglot::isLevelOccupied(int level)
{
    for (int i = 0; i < 5; i++) {
        if ( !spaces[level][i] ) {
            return false;
        }
    }
    return true;
}

void parkinglot::parkinglotMenu() {
    cout << "============ Menu ============" << endl;
    cout << "Maximum Capacity: " << CAPACITY << endl;
    cout << "Levels: A - D" << endl;
    
    cout << "* There are a total of 5 spaces for each level.\n" << endl;

    cout << "Maximum number of hours you can park your here is "
        << MAX_HOURS << "hrs" << endl;
    
    cout << "The toll for for each hour is $" << TOLL << endl << endl;

    cout << "To leave the parking lot or quit this program press \'q\' or \'Q\'" << endl;
    cout << "============ Menu ============\n\n" << endl;
}


int main()
{
    parkinglot myCar("honda civic <sliver>", "small");
    
    if ( myCar.isParkinglotFull() ) {
        cout << "Sorry you can not enter this parking lot. It is a full capcity of " << myCar.getCapacity() << endl;
        return 1;
    }

    cout << "Welcome to the parking lot." << endl;

    myCar.parkinglotMenu();

    return 0;
}