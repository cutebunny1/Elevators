#ifndef _MOVE_H_
#define _MOVE_H_
#include <string>
#include "Utility.h"
#include "Floor.h"
#include "Elevator.h"

//////////////////////////////////////////////////
/////// DO NOT MODIFY ANY CODE IN THIS FILE //////
/////////// ANY CONSTANTS/ETC SHOULD /////////////
////////////// BE ADDED IN THE .CPP //////////////
//////////////////////////////////////////////////

class Move {
private:
    int elevatorId;
    int targetFloor;
    int peopleToPickup[MAX_PEOPLE_PER_FLOOR] = {};
    int numPeopleToPickup;
    int totalSatisfaction;
	bool isPass; //just hitting enter is a move
    bool isPickup;
    bool isSave;
    bool isQuit;

public:
    /**
     * Requires: commandString is a valid string
     * Modifies: Move object private variables
     * Effects:  creates a Move object based on
     *           the characters in commandString
     *           Ex:
     *           commandString = "e1f4"; // elevatorID of 1 has a targetFloor of 4
     *           commandString = "e1p";  // elevatorID of 1 will pickup people on its current floor
     */
    Move(string commandString);
    
    /**
     * Requires: elevators represents the elevator servicing states
     * Modifies: nothing
     * Effects:  returns true if this Move instance is valid, false otherwise
     *           
     *           The following are the criterion for validity:
     * 
     *           If a move is a Pass Move, a Quit Move, or a Save Move it is valid
     *           For both Pickup Moves and Servicing Moves:
     *               0 <= elevatorId < NUM_ELEVATORS
     *               The corresponding Elevator is currently not 
     *                  servicing a request.
     *           For Servicing Moves only:
     *               0 <= targetFloor < NUM_FLOORS
     *               targetFloor is different from the corresponding 
     *                  Elevator's currentFloor
     */
    bool isValidMove(Elevator elevators[NUM_ELEVATORS]) const;
    
    /**
     * Requires: pickupList is a valid list of indices
     *           currentFloor is the floor of the pickup request
     *           pickupFloor is the floor of the pickup request
     * Modifies: numPeopleToPickup, peopleToPickup, totalSatisfaction, targetFloor
     * Effects:  sets numPeopleToPickup and totalSatisfaction to 0
     *           adds the indices specified in pickupList to peopleToPickup
     *           increments numPeopleToPickup by 1 for each person being picked up
     *           adds satisfaction gained from each person picked up 
     *              to totalSatisfaction
     *           sets targetFloor to be the most extreme floor of those 
     *              being picked up (furthest up or down)
     */
    void setPeopleToPickup(const string& pickupList, const int currentFloor, 
        const Floor& pickupFloor);
    
    /**
     * Requires: nothing
     * Modifies: Move object
     * Effects: initializes a Move object
     *
     */
    Move();

    /**
     * Requires: nothing
     * Modifies: nothings
     * Effects: returns the value of isPass
     *
     */
	bool isPassMove() const;

     /**
     * Requires: nothing
     * Modifies: nothings
     * Effects: returns the value of isSave
     *
     */
	bool isSaveMove() const;

    /**
     * Requires: nothing
     * Modifies: nothings
     * Effects: returns the value of isQuit
     *
     */
	bool isQuitMove() const;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns the value of isPickup
     *
     */
    bool isPickupMove() const;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns the elevatorId
     *
     */
    int getElevatorId() const;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns the targetFloor
     *
     */
    int getTargetFloor() const;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns the number of people being picked up by 
     *          this move (-1 if not pickup move)
     *
     */
    int getNumPeopleToPickup() const;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns totalSatisfaction
     *
     */
    int getTotalSatisfaction() const;

    /**
     * Requires: inTargetFloor is a valid floor
     * Modifies: targetFloor
     * Effects: sets the targetFloor to inTargetFloor
     *
     */
    void setTargetFloor(int inTargetFloor);

    /**
     * Requires: newList is a valid array
     * Modifies: newList
     * Effects: copies peopleToPickup into newList
     */
    void copyListOfPeopleToPickup(int newList[MAX_PEOPLE_PER_FLOOR]) const;
};



#endif
