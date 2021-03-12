//
// Created by Sam Pitonyak on 12/6/20.
//

#ifndef FINAL_PROJECT_SPITONYA_FIRETYPE_H
#define FINAL_PROJECT_SPITONYA_FIRETYPE_H

#include "Pokemon.h"

class FireType : public Pokemon {
public:
    /**
     * Requires: nothing
     * Modifies: type the pokemon is
     * Effects: calls parent default constructor and sets caught to false
     */
    FireType();

    /**
     * Requires: nothing
     * Modifies: type of pokemon
     * Effects: calls parent non-default constructor
     */
    explicit FireType(type strain);

    /**
     * Requires: nothing
     * Modifies: name of pokemon
     * Effects: returns either "Blaziken starts to charge with a fire trailing"
     *          or "Charizard creates a burst of fire"
     */
    std::string encounter() override;

};

#endif //FINAL_PROJECT_SPITONYA_FIRETYPE_H
