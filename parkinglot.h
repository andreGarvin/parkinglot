#include <iostream>
#include <string>

using namespace std;

class parkinglot {
    public:
        bool isParked = false;
        string TypeOfCar;
        string CarSize;

        // the class contructor
        parkinglot(string typeOfCar, string size);
        // the class deconstructor
        ~parkinglot();
        
        /**
        * This creates the bill for the ticket depending on the hours
        */
        void formulateTicket();

        /**
        * Prints the price of the ticket, including the ammount of hours
        * they are spending, and where they are parked at.
        */
        void printTicket();

        /**
        * sets the location on the level and the space the car is parked at.
        * And assigns true the false value space in the space multi deminsonal array.
        */
        void park(int space);

        /**
        * Prints a human readable the location in which the car is parked.
        */
        void parkedAt(int level, int space);

        /**
        * removes the values of the cars location and
        * removes the thruthy value in the spaces multi deminsonal array.
        */
        void leaveSpace(int level, int space);

        /**
        * Sets a new level
        */
        void setLevel(int newLevel);

        /**
        * Adds more hours that the card woul like to stay.
        */
        void addMoreHours(int hours = 5);

        /**
        * This prompts the user for the hours and assigns
        * that hour to the memebr varible hours.
        */
        int getHours();

        /**
        * Assings the new number of available spaces in the parking lot
        */
        void setAvailablesSpaces();
        
        /**
        * Pays for parking ticket and makes sure the bill is fully paid for.
        */
        int payForTicket(int amount);

        /**
        * returns the number of avaible spaces that are left in the parking lot 
        */
        int getAvailbleSpaces() const;

        /**
        * This prints out prints out the number in the parking
        * lot depending on which level you are in.
        */
        int numberOfAvaibleSpaces() const;
        
        /**
        * returns a boolean value of wether a whole level is occupied.
        */
        bool isLevelOccupied(int level);

        /**
        * returns a boolean value of wether a space is occupied or not.
        */
        bool isSpaceOccupied(int level, int space);

        /**
        * Returns the parking lots capacity.
        */
        int getCapacity() { return CAPACITY; }
        
        /**
        * Returns a boolean value wether if the parking lot is availabe or not 
        */
        bool isParkinglotFull();

        /**
        * Displays the parking lots menu such as the levels there are,
        * how many spaces there are on each level, capacity of the parkinglot
        * and the total number of hours the car is allowed to stay for.
        */
        void parkinglotMenu();

        void printAvailableSpaces(bool parkingLevel[]);
        
    private:
        int hours = 5;
        double bill;
        int level = 0;
        int space = 0;

        int spacesAvailable = 25;

        const double TOLL = 5.00;
        const int MAX_HOURS = 10;
        const int CAPACITY = 25;

        const char levels[5] = {
            'A',
            'B',
            'C',
            'D',
            'E'
        };
        const bool spaces [5][5] = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false}
        };
};