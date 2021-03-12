//
// Created by Sam Pitonyak on 12/6/20.
//

#ifndef FINAL_PROJECT_SPITONYA_TRAINER_H
#define FINAL_PROJECT_SPITONYA_TRAINER_H


#include "Pokeball.h"
#include <string>
#include <vector>
using std::vector;

// The Trainer class is going to have a bag that contains random pokeballs
class Trainer {
private:
    int numCaught;
    int balls;
    vector<Pokeball> bag;

public:
    /**
     * Requires: nothing
     * Modifies: number_of_eyes 
     * Effects: numCaught and balls equal to 0 and clears everything in bag
     */
    Trainer();

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns numCaught
     */
    int getNumCaught() const;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns balls
     */
    int getBalls() const;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns bag
     */
    vector<Pokeball> getBag() const;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns balls that are in bag
     */
    std::string getBallsFromBag() const;

    /**
     * Requires: nothing
     * Modifies: balls 
     * Effects: sets balls equal to num
     */
    void setBalls(int num);

    /**
     * Requires: nothing
     * Modifies: bag 
     * Effects: adds number of balls to bag that user inputs, randomly chooses
     *              which balls are put in bag
     */
    void addToBag();

    /**
     * Requires: nothing
     * Modifies: nothing 
     * Effects: looks in bag for ball that user inputs and returns boolean value
     *              based on if it is or is not in the bag
     */
    bool findBall(std::string ballString);

    /**
     * Requires: nothing
     * Modifies: balls and bag
     * Effects: takes user input of ball and randomly calculates if pokemon is caught
     *              or not, it subtracts one from balls and also erases that ball from
     *              the bag and returns a value of 1 or 0 depending on if the pokemon
     *              was caught
     */
    int throwBall(std::string type, double &normalUsed, double &normalSucces, double &ultraUsed,
                  double &ultraSuccess, double &masterUsed, double &masterSuccess);


};

#endif //FINAL_PROJECT_SPITONYA_TRAINER_H
