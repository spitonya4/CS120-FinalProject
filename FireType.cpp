//
// Created by Sam Pitonyak on 12/6/20.
//

#include "FireType.h"
using namespace std;

// Default constructor
FireType::FireType() : Pokemon() {
    pokeType = fire;
    caught = false;
}

// Constructor that accepts type
FireType::FireType(type fire) : Pokemon(fire) {
}

string FireType::encounter() {
    return name + " starts to singe the earth surrounding them";
//    if (rand() % 2 == 0) {
//        name = "Blaziken";
//        return "Blaziken starts to charge with a fire trailing";
//    }
//    name = "Charizard";
//    return "Charizard creates a burst of fire";
}


