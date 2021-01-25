#ifndef _BUILDING_H_
#define _BUILDING_H_

#include "Elevator.h"
#include "Floor.h"
#include "Person.h"
#include "Utility.h"
#include "Move.h"
#include "BuildingState.h"
#include <string>
#include <iostream>
#include <fstream>

//////////////////////////////////////////////////
/////// DO NOT MODIFY ANY CODE IN THIS FILE //////
/////////// ANY CONSTANTS/ETC SHOULD /////////////
////////////// BE ADDED IN THE .CPP //////////////
//////////////////////////////////////////////////

class Building {
private:
    Elevator elevators[NUM_ELEVATORS];
    Floor floors[NUM_FLOORS];
    int time;

    /*
    * Requires: move is a valid move
    * Modifies: The building member variables affected by the move
    * Effects: Applies the move to the building:
    *          * If the move is a Pass Move, nothing happens
    *          * If the move is a Pickup Move, copies the list of people to
    *            pickup into an array, and calls removePeople() on the
    *            appropriate floor
    *          * For both Pickup Moves and Service Moves, the appropriate
    *            elevator should be sent to service the targetFloor of the move
    */
	void update(Move move);

public:
    /*
     * Requires: newPerson is a valid Person object
     * Modifies: A floor in the building - floors
     * Effects:  Adds a person to the Floor corresponding to currentFloor
     *           of the person
     */
    void spawnPerson(Person newPerson);

    /*
     * Requires: move is a valid move
     * Modifies: The private member variables of building
     * Effects: Increments time and calls update() on the input move
     *          Then, ticks all of the elevators with the new time
     *          Next, ticks all of the buildingfloors, keeping track of new
     *          exploded people
     *          Returns the total number of people that exploded in this tick
     */
    int tick(Move move);

    /*
    * Requires: Nothing
    * Modifies: Building State
    * Effects: Default constructor. Sets time to 0
    */
    Building();

    /*
    * Requires: elevatorInfo is a well-formed info string.
    *           0 <= elevatorId < NUM_ELEVATORS
    * Modifies: Building's elevator at elevatorId
    * Effects: Parses elevatorInfo and updates elevator into correct state.
    *          The elevator string will come in the form <num>[s<num>:w]
    *               Ex: 0w
    *                   6s8
    *                   5w
    *                   9s5
    *          The first number represents the currentFloor of the elevator
    *          The 's' means that the elevator is currently servicing, with target
    *          floor being the number after the 's'
    *          The 'w' means that the elevator is waiting, so it has no target floor
    *          and is ready to service requests
    *          This is used when reloading a game from a save file
    */
    void setElevator(string elevatorInfo, int elevatorId);

    /*
    * Requires: Nothing
    * Modifies: Nothing
    * Effects: Returns the current time for the building
    */
    int getTime() const;

    /*
    * Requires: timeIn >= 0
    * Modifies: Nothing
    * Effects: Sets the current time for the building to timeIn
    */
    void setTime(int timeIn);

    /*
    * Requires: outs is in a good state, building is in a valid state
    * Modifies: outs
    * Effects: Prints the building state to terminal in a nice way for
    *          gameplay
    */
    void prettyPrintBuilding(ostream& outs) const;

    /*
    * Requires: 0 <= elevatorId < NUM_ELEVATORS
    * Modifies: Nothing
    * Effects: Returns an Elevator object containing the
    *          info of the elevator at index elevatorID in the building
    */
    Elevator getElevatorById(int elevatorId) const;

    /*
    * Requires: 0 <= floorNum < NUM_FLOORS
    * Modifies: Nothing
    * Effects: Returns an Floor object containing the
    *          info of the floor at index floorNum in the building
    */
    Floor getFloorByFloorNum(int floorNum) const;

    /*
    * Requires: Nothing
    * Modifies: Nothing
    * Effects: Returns a BuildingState object for use by AI
    *          to decide its move with the same information a
    *          human player would use. See BuildingState.h for more
    *          info
    */
    BuildingState getBuildingState() const;
};


#endif
