//
// Created by Sam Pitonyak on 12/6/20.
//

#ifndef FINAL_PROJECT_SPITONYA_POKEMON_H
#define FINAL_PROJECT_SPITONYA_POKEMON_H


#include <string>

enum type {water, fire, grass};

class Pokemon {

public:
    /**
     * Requires: nothing
     * Modifies: pokeType
     * Effects: sets pokeType to water
     */
    Pokemon();

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: does nothing
     */
    virtual ~Pokemon() = default;

    /**
     * Requires: nothing
     * Modifies: pokeType
     * Effects: sets pokeType equal to strain
     */
    explicit Pokemon(type strain);

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns pokeType
     */
    virtual type getType();

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns name
     */
    virtual std::string getName();

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns caught
     */
    virtual bool getCaught();

    /**
     * Requires: nothing
     * Modifies: pokeType 
     * Effects: uses switch case statement to set the pokeType field to
     *              either water, fire, or grass
     */
    void setType(int variety);

    /**
     * Requires: nothing
     * Modifies: name 
     * Effects: sets name to whatever the string passed into it is
     */
    void setName(std::string label);

    /**
     * Requires: nothing
     * Modifies: caught 
     * Effects: sets caught to the boolean value passed into it
     */
    void setCaught(bool val);

    // Action method describes what the pokemon does for encounter
    virtual std::string encounter() = 0;

protected:
    type pokeType;
    std::string name;
    bool caught;

};

#endif //FINAL_PROJECT_SPITONYA_POKEMON_H
