#ifndef _FLOOR_H_
#define _FLOOR_H_

#include "Person.h"
#include "Utility.h"
#include <iostream>

//////////////////////////////////////////////////
/////// DO NOT MODIFY ANY CODE IN THIS FILE //////
/////////// ANY CONSTANTS/ETC SHOULD /////////////
////////////// BE ADDED IN THE .CPP //////////////
//////////////////////////////////////////////////

class Floor {
private:
    Person people[MAX_PEOPLE_PER_FLOOR];
    int numPeople;
    bool hasUpRequest;
    bool hasDownRequest;

    /*
     * Requires: nothing
     * Modifies: hasUpRequest, hasDownRequest
     * Effects: Search through people to find if there are any
     *          pending up requests or down requests. Set the
     *          values of hasUpRequest and hasDownRequest appropriately.
     *          This function is used to recalculate requests whenever
     *          the people on this floor are added or removed
     */
    void resetRequests();

public:

    /*
     * Requires: request != 0
     * Modifies: hasUpRequest, hasDownRequest, numPeople, people
     * Effects:  If there is still room, add newPerson to people.
     *           Updates hasUpRequest or hasDownRequest based on value of request
     */
    void addPerson(Person newPerson, int request);

    /*
     * Requires: numPeopleToRemove >= 0, numPeopleToRemove <= MAX_PEOPLE_PER_FLOOR,
                 numPeopleToRemove >= 0, numPeopleToRemove <= numPeople,
     *           for all values of i such that 0 <= i < numPeopleToRemove, indicesToRemove[i] < numPeople
     * Modifies: people[], numPeople
     * Effects:  Removes objects from people[] at indices specified in
     *           indicesToRemove[].  The size of indicesToRemove is given by numPeopleToRemove
     */
	void removePeople(int indicesToRemove[MAX_PEOPLE_PER_FLOOR], const int numPeopleToRemove);

    /*
     * Requires: nothing
     * Modifies: people
     * Effects:  Ticks each person on this floor
     *           Also removes any Person who explodes
     *           Returns the number of exploded people
     */
    int tick(int currentTime);

    /*
     * Requires: nothing
     * Modifies: hasUpRequest, hasDownRequrest, numPeople
     * Effects:  Initializes all member variables to 0 or false
     */
    Floor();

    /*
     * Requires: 0 <= index < numPeople
     * Modifies: nothing
     * Effects:  Returns the person at given index of people array
     */
    Person getPersonByIndex(int index) const;

    /*
     * Requires: nothing
     * Modifies: nothing
     * Effects:  Returns the number of people on this floor
     */
    int getNumPeople() const;

    /*
     * Requires: nothing
     * Modifies: hasUpRequest
     * Effects:  Sets hasUpRequest to the given value
     */
    void setHasUpRequest(bool hasRequest);

    /*
     * Requires: nothing
     * Modifies: nothing
     * Effects:  Returns whether this floor has an upRequest
     */
    bool getHasUpRequest() const;

    /*
     * Requires: nothing
     * Modifies: hasDownRequrest
     * Effects:  Sets hasDownRequest to the given value
     */
    void setHasDownRequest(bool hasRequest);

    /*
     * Requires: nothing
     * Modifies: nothing
     * Effects:  Returns whether this floor has an downRequest
     */
    bool getHasDownRequest() const;

    /*
     * Requires: outs is in a good state
     * Modifies: outs
     * Effects:  Prints the pickup menu of this floor to outs.
     */
	void printFloorPickupMenu(ostream& outs) const;

    // Helpers for Building::prettyPrintBuilding
    void prettyPrintFloorLine1(ostream& outs) const;
    void prettyPrintFloorLine2(ostream& outs) const;
};
#endif
