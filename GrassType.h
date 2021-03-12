//
// Created by Sam Pitonyak on 12/6/20.
//

#ifndef FINAL_PROJECT_SPITONYA_GRASSTYPE_H
#define FINAL_PROJECT_SPITONYA_GRASSTYPE_H

#include "Pokemon.h"

class GrassType : public Pokemon {
public:
    /**
     * Requires: nothing
     * Modifies: type the pokemon is
     * Effects: calls parent default constructor and sets caught to false
     */
    GrassType();

    /**
     * Requires: nothing
     * Modifies: type of pokemon
     * Effects: calls parent non-default constructor
     */
    explicit GrassType(type strain);

    /**
     * Requires: nothing
     * Modifies: name of pokemon
     * Effects: returns either "Venusaur swings vines in the air that attached to its back"
     *          or "Chesnaught sprays seeds onto the ground surrounding it"
     */
    std::string encounter() override;

};

#endif //FINAL_PROJECT_SPITONYA_GRASSTYPE_H
