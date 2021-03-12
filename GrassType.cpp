//
// Created by Sam Pitonyak on 12/6/20.
//

#include "GrassType.h"
using namespace std;

// Default constructor
GrassType::GrassType() : Pokemon() {
    pokeType = grass;
    caught = false;
}

// Constructor that accepts type
GrassType::GrassType(type grass) : Pokemon(grass) {
}

string GrassType::encounter() {
    if (rand() % 2 == 0) {
        name = "Venusaur";
        return "Venusaur swings vines in the air that attached to its back";
    }
    name = "Chesnaught";
    return "Chesnaught sprays seeds onto the ground surrounding it";
}
