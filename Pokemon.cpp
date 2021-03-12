//
// Created by Sam Pitonyak on 12/6/20.
//


#include "Pokemon.h"

// Default constructor
Pokemon::Pokemon() {
    caught = false;
}

// Constructor with type assigned already
Pokemon::Pokemon(type strain) {
    pokeType = strain;
    caught = false;
}

// Getters
type Pokemon::getType() {
    return pokeType;
}

std::string Pokemon::getName() {
    return name;
}

bool Pokemon::getCaught() {
    return caught;
}

// Setters
void Pokemon::setType(int variety) {
    // Make a switch statement to set the type
    switch (variety) {
        case 0:
            pokeType = water;
            break;
        case 1:
            pokeType = fire;
            break;
        case 2:
            pokeType = grass;
            break;
    }
}

void Pokemon::setName(std::string label) {
    name = label;
}

void Pokemon::setCaught(bool val) {
    caught = val;
}
