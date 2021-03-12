//
// Created by Sam Pitonyak on 12/6/20.
//


#include "FireType.h"
#include "GrassType.h"
#include "WaterType.h"
#include "Pokemon.h"
#include "Pokeball.h"
#include "Trainer.h"
#include <ctime>
#include <iostream>
using namespace std;

bool testFireType();
bool testGrassType();
bool testWaterType();
bool testPokemon();
bool testPokeball();
bool testTrainer();


int main() {
    srand(time(NULL));
    if (testFireType()) {
        cout << "Passed all FireType test cases" << endl;
    }
    if (testGrassType()) {
        cout << "Passed all GrassType test cases" << endl;
    }
    if (testWaterType()) {
        cout << "Passed all WaterType test cases" << endl;
    }
    if (testPokemon()) {
        cout << "Passed all Pokemon test cases" << endl;
    }
    if (testPokeball()) {
        cout << "Passed all Pokeball test cases" << endl;
    }
    if (testTrainer()) {
        cout << "Passed all Trainer test cases" << endl;
    }

    return 0;
}

bool testFireType() {
    bool passed = true;
    FireType fireOne;
    if (fireOne.getType() != fire && fireOne.getCaught()) {
        passed = false;
        cout << "FAILED default constructor test case" << endl;
    }

    FireType fireTwo(fire);
    if (fireTwo.getType() != fire) {
        passed = false;
        cout << "FAILED non-default constructor test case" << endl;
    }

    string testReturn = fireOne.encounter();
    if (testReturn != "Blaziken starts to charge with a fire trailing" && testReturn != "Charizard creates a burst of fire") {
        passed = false;
        cout << "FAILED encounter return string test case" << endl;
    }

    if (fireOne.getName() != "Blaziken" && fireOne.getName() != "Charizard") {
        passed = false;
        cout << "FAILED name test case" << endl;
    }

    return passed;
}

bool testGrassType() {
    bool passed = true;
    GrassType grassOne;
    if (grassOne.getType() != grass && grassOne.getCaught()) {
        passed = false;
        cout << "FAILED default constructor test case" << endl;
    }

    GrassType grassTwo(grass);
    if (grassTwo.getType() != grass) {
        passed = false;
        cout << "FAILED non-default constructor test case" << endl;
    }

    string testReturn = grassOne.encounter();
    if (testReturn != "Venusaur swings vines in the air that attached to its back" && testReturn != "Chesnaught sprays seeds onto the ground surrounding it") {
        passed = false;
        cout << "FAILED encounter return string test case" << endl;
    }

    if (grassOne.getName() != "Venusaur" && grassOne.getName() != "Chesnaught") {
        passed = false;
        cout << "FAILED name test case" << endl;
    }

    return passed;
}

bool testWaterType() {
    bool passed = true;
    WaterType waterOne;
    if (waterOne.getType() != water && waterOne.getCaught()) {
        passed = false;
        cout << "FAILED default constructor test case" << endl;
    }

    WaterType waterTwo(water);
    if (waterTwo.getType() != water) {
        passed = false;
        cout << "FAILED non-default constructor test case" << endl;
    }

    string testReturn = waterOne.encounter();
    if (testReturn != "Blastoise shoots powerful streams of water out of its shoulder cannons" && testReturn != "Swampert sprays water from its mouth") {
        passed = false;
        cout << "FAILED encounter return string test case" << endl;
    }

    if (waterOne.getName() != "Blastoise" && waterOne.getName() != "Swampert") {
        passed = false;
        cout << "FAILED name test case" << endl;
    }

    return passed;
}

bool testPokemon() {
    bool passed = true;
    FireType pokemon;
    if (pokemon.getCaught()) {
        passed = false;
        cout << "FAILED default constructor test" << endl;
    }

    GrassType pokemonTwo(fire);
    if (pokemonTwo.getType() != fire && pokemonTwo.getCaught()) {
        passed = false;
        cout << "FAILED non-default constructor test case" << endl;
    }

    pokemonTwo.setType(0);
    if (pokemonTwo.getType() != water) {
        passed = false;
        cout << "FAILED setType water test case" << endl;
    }
    pokemonTwo.setType(1);
    if (pokemonTwo.getType() != fire) {
        passed = false;
        cout << "FAILED setType fire test case" << endl;
    }
    pokemonTwo.setType(2);
    if (pokemonTwo.getType() != grass) {
        passed = false;
        cout << "FAILED setType grass test case" << endl;
    }

    pokemon.setCaught(true);
    if (!pokemon.getCaught()) {
        passed = false;
        cout << "FAILED setCaught test case" << endl;
    }

    pokemon.setName("Poke");
    if (pokemon.getName() != "Poke") {
        passed = false;
        cout << "FAILED setName test case" << endl;
    }

    return passed;
}

bool testPokeball() {
    bool passed = true;
    Pokeball ball;
    if (ball.getNormalBall() != false || ball.getMasterBall() != false || ball.getMasterBall() != false) {
        passed = false;
        cout << "FAILED default constructor test case" << endl;
    }

    ball.setNormalBall(true);
    if (!ball.getNormalBall()) {
        passed = false;
        cout << "FAILED setNormalBall test case" << endl;
    }
    ball.setUltraBall(true);
    if (!ball.getUltraBall()) {
        passed = false;
        cout << "FAILED setUltraBall test case" << endl;
    }
    ball.setMasterBall(true);
    if (!ball.getMasterBall()) {
        passed = false;
        cout << "FAILED setMasterBall test case" << endl;
    }


    return passed;
}

bool testTrainer() {
    bool passed = true;
    Trainer user;
    vector<Pokeball> bag;
    if (user.getNumCaught() != 0 && user.getBalls() != 0) {
        passed = false;
        cout << "FAILED default constructor test case" << endl;
    }
    user.setBalls(3);
    if (user.getBalls() != 3) {
        passed = false;
        cout << "FAILED setBalls test case" << endl;
    }
    // Add such a large number of pokeBalls to bag that there is bound to be at least
    // one type of each ball
    user.setBalls(5);
    user.addToBag();
    bag = user.getBag();
    if (bag.size() != 5) {
        passed = false;
        cout << "FAILED addToBag test case" << endl;
    }
    bag.clear();
    Trainer userTwo;
    // Set balls to a very large number so each ball is represented at least once
    userTwo.setBalls(100);
    userTwo.addToBag();
    bool result = userTwo.findBall("normal");
    if (!result) {
        passed = false;
        cout << "FAILED findBall 'normal' test case" << endl;
    }
    result = userTwo.findBall("ultra");
    if (!result) {
        passed = false;
        cout << "FAILED findBall 'ultra' test case" << endl;
    }
    result = userTwo.findBall("master");
    if (!result) {
        passed = false;
        cout << "FAILED findBall 'master' test case" << endl;
    }
    int caught = userTwo.throwBall("normal");
    if (caught != 1 && caught != 0) {
        passed = false;
        cout << "FAILED throwBall 'normal' test case" << endl;
    }
    caught = userTwo.throwBall("ultra");
    if (caught != 1 && caught != 0) {
        passed = false;
        cout << "FAILED throwBall 'ultra' test case" << endl;
    }
    caught = userTwo.throwBall("master");
    if (caught != 1) {
        passed = false;
        cout << "FAILED throwBall 'master' test case" << endl;
    }

    return passed;
}