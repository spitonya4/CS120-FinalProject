//
// Created by Sam Pitonyak on 12/6/20.
//


#include "WaterType.h"
using namespace std;

// Default constructor
WaterType::WaterType() : Pokemon() {
    pokeType = water;
    caught = false;
}

// Constructor that accepts type
WaterType::WaterType(type water) : Pokemon(water) {
}

string WaterType::encounter() {
    if (rand() % 2 == 0) {
        name = "Blastoise";
        return "Blastoise shoots powerful streams of water out of its shoulder cannons";
    }
    name = "Swampert";
    return "Swampert sprays water from its mouth";
}
