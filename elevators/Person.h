#ifndef _PERSON_H_
#define _PERSON_H_

#include <cmath>
#include "Utility.h"

//////////////////////////////////////////////////
/////// DO NOT MODIFY ANY CODE IN THIS FILE //////
/////////// ANY CONSTANTS/ETC SHOULD /////////////
////////////// BE ADDED IN THE .CPP //////////////
//////////////////////////////////////////////////

class Person {
private:
    int turn;
    int currentFloor;
    int targetFloor;
    int angerLevel;

public:
    /**
     * Requires: nothing
     * Modifies: angerLevel
     * Effects:  Every TICKS_PER_ANGER_INCREASE, this function increases the
     *           person's anger level by 1. If, after increasing, the person
     *           has an anger level of MAX_ANGER, the function will return 
     *           true. If the person has an anger level less than MAX_ANGER,
     *           the function will return false.
     */
    bool tick(int currentTime); 

    /**
     * Requires: nothing
     * Modifies: outs
     * Effects:  Prints the infoString of the person NOT including the turn
     * 
     * Example:  Person p("7f4t8a3");
     *           cout << "\nThe person you just entered is: ";
     *           p.print(cout);
     * 
     *           This will print "f4t8a3"
     */
    void print(ostream &outs);

    /**
     * Requires: nothing
     * Modifies: turn, currentFloor, targetFloor, angerLevel
     * Effects:  sets turn, currentFloor, targetFloor, angerLevel, to 0
     */
    Person();

    /*
     * Requires: input_string is correctly formatted
     * Modifies: turn, startingFloor, targetFloor, angerLevel
     * Effects:  Parses the infoString to set member variables
    */
    Person(string input_string);

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects:  Returns the turn of the person.
     */
    int getTurn() const;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects:  Returns the current floor of the person.
     */
    int getCurrentFloor() const;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects:  Returns the target floor of the person.
     */
    int getTargetFloor() const;
    
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects:  Returns the anger level of the person.
     */
    int getAngerLevel() const; 
};

/**
 * Overloading << for printing a Person to a stream.
 * 
 * Example on how to use this:
 * Person p("7f4t8a3");
 * cout << "\nThe person you just entered is: ";
 * cout << p << endl;
 * 
 * This will print "f4t8a3"
 */

ostream& operator << (ostream& outs, Person pt);

#endif
