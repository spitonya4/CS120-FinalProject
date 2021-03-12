//
// Created by Sam Pitonyak on 12/6/20.
//

#ifndef FINAL_PROJECT_SPITONYA_WATERTYPE_H
#define FINAL_PROJECT_SPITONYA_WATERTYPE_H


#include "Pokemon.h"

class WaterType : public Pokemon {
public:
    /**
     * Requires: nothing
     * Modifies: type the pokemon is
     * Effects: calls parent default constructor and sets caught to false
     */
    WaterType();

    /**
     * Requires: nothing
     * Modifies: type of pokemon
     * Effects: calls parent non-default constructor
     */
    explicit WaterType(type strain);

    /**
     * Requires: nothing
     * Modifies: name of pokemon
     * Effects: returns either "Blastoise shoots powerful streams of water out of its shoulder cannons"
     *          or "Swampert sprays water from its mouth"
     */
    std::string encounter() override;

};


#endif //FINAL_PROJECT_SPITONYA_WATERTYPE_H
