//
// Created by Sam Pitonyak on 12/6/20.
//

#include "Pokemon.h"
#include "FireType.h"
#include "GrassType.h"
#include "WaterType.h"
#include "Trainer.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void validBall(std::string &ballVariation, Trainer &user);
void fireCaught(FireType &fire, int num);
void fireAgain(FireType &fire, Trainer &user, int caught, char choice, std::string ballThrow);
void grassCaught(GrassType &grass, int num);
void grassAgain(GrassType &grass, Trainer &user, int caught, char choice, std::string ballThrow);
void waterCaught(WaterType &water, int num);
void waterAgain(WaterType &water, Trainer &user, int caught, char choice, std::string ballThrow);
void outputCaught(FireType &fire, GrassType &grass, WaterType &water, Trainer &user);

// Keep track of the specific number of balls
double normalUsed = 0;
double normalSuccess = 0;
double ultraUsed = 0;
double ultraSuccess = 0;
double masterUsed = 0;
double masterSuccess = 0;

//const string python = "py";
const string python = "python3";


int main() {
    cout << "Got to cpp file" << endl;
    string firePoke;
    string grassPoke;
    string waterPoke;
    // Make sure there are 3 arguments
//    if (argc == 4) {
//        firePoke = argv[1];
//        grassPoke = argv[2];
//        waterPoke = argv[3];
//    }

//    cout << firePoke << endl;
//    cout << grassPoke << endl;
//    cout << waterPoke << endl;


    srand((unsigned)time(NULL));

    // Explain to the user that they are a Pokemon trainer looking to catch pokemon
    cout << "You are a Pokemon trainer looking to catch pokemon encountered!" << endl;

    // Tell them that they are able to place up to 3 pokeballs in their bag to which
    // they will have a certain probability of catching the pokemon that appear
    // to them
    cout << "You have a bag with you that can hold poke balls in it." << endl;
    cout << "You will encounter 3 different pokemon!" << endl;
    cout << endl;
    // Ask the user how many balls they want to place in their bag
    int numberOfBalls;
    cout << "How many balls would you like to carry (up to 10): ";
    cin >> numberOfBalls;
    // Input validation
    while (numberOfBalls < 1 || numberOfBalls > 10) {
        cin.clear();
        string junk;
        getline(cin, junk);
        cout << "Please enter an integer between 1-5:";
        cin >> numberOfBalls;
    }
    // Create a number of pokemon objects based on how many balls they place in
    // their bag
    // For each pokeball assign a type to the pokemon and call that
    // specific types output

    // Create a trainer object
    Trainer user;
    // Add the number of balls to the bag
    user.setBalls(numberOfBalls);


    user.addToBag();
    cout << "Looking in the bag..." << endl;
    cout << endl;
    cout << "You have a" + user.getBallsFromBag() + " in your bag." << endl;

    // For each pokeball assign a type to the pokemon and call that
    // specific types output
    FireType fireO;
    WaterType waterO;
    GrassType grassO;

    fireO.setName("Chimchar");
    cout << endl;
    // Tell the user to get a pokeball from their bag and throw it
    cout << "You've encountered a pokemon!" << endl;
    cout << fireO.encounter() << endl;
    cout << endl;
    cout << "Which pokeball do you want to throw? (normal/ultra/master): ";
    std::string ballThrow;
    cin >> ballThrow;

    // Make sure the user selects a ball that is in their bag
    validBall(ballThrow, user);
    int caught = user.throwBall(ballThrow, normalUsed, normalSuccess, ultraUsed,
                                    ultraSuccess, masterUsed, masterSuccess);

    // Check to see if the pokemon has been caught
    fireCaught(fireO, caught);
    char choice;
    if (caught == 0 && user.getBalls() > 0) {
        choice = 'y';
        // If it hasn't been caught ask the user if they wish to throw another ball at it
        fireAgain(fireO, user, caught, choice, ballThrow);
    }

    // Make sure the user has balls left before encountering their next pokemon
    if (user.getBalls() > 0) {
        // Tell the user to get a pokeball from their bag and throw it
        cout << endl;
        cout << "You've encountered another pokemon!" << endl;
        cout << grassO.encounter() << endl;
        cout << endl;
        cout << "Which pokeball do you want to throw? (normal/ultra/master): ";
        cin >> ballThrow;

        // Make sure the user selects a ball that is in their bag
        validBall(ballThrow, user);
        caught = user.throwBall(ballThrow, normalUsed, normalSuccess, ultraUsed,
                                ultraSuccess, masterUsed, masterSuccess);

        // Check to see if the pokemon has been caught
        grassCaught(grassO, caught);

        if (caught == 0 && user.getBalls() > 0) {
            choice = 'y';
            // If it hasn't been caught ask the user if they wish to throw another ball at it
            grassAgain(grassO, user, caught, choice, ballThrow);
        }
    }

    // Make sure the user has balls left before encountering their next pokemon
    if (user.getBalls() > 0) {
        // Tell the user to get a pokeball from their bag and throw it
        cout << endl;
        cout << "You've encountered another pokemon!" << endl;
        cout << waterO.encounter() << endl;
        cout << endl;
        cout << "Which pokeball do you want to throw? (normal/ultra/master): ";
        cin >> ballThrow;

        // Make sure the user selects a ball that is in their bag
        validBall(ballThrow, user);
        caught = user.throwBall(ballThrow, normalUsed, normalSuccess, ultraUsed,
                                ultraSuccess, masterUsed, masterSuccess);

        // Check to see if the pokemon has been caught
        waterCaught(waterO, caught);

        if (caught == 0 && user.getBalls() > 0) {
            choice = 'y';
            // If it hasn't been caught ask the user if they wish to throw another ball at it
            waterAgain(waterO, user, caught, choice, ballThrow);
        }
    }

    // Once the user has used all of their pokeballs, tell the user the type
    // of pokemon they caught and how many
    // Tell the user that they are either out of balls and tell them how many pokemon they caught
    if (user.getBalls() == 0) {
        cout << "You have used all of your pokeBalls." << endl;
        cout << endl;
        if (fireO.getCaught() || grassO.getCaught() || waterO.getCaught()) {
            cout << "You caught " <<  user.getNumCaught() << " pokemon!" << endl;
            cout << "You caught: ";
            outputCaught(fireO, grassO, waterO, user);
        } else {
            cout << "You did not catch anything." << endl;
        }

    } else {
        cout << endl;
        cout << "You caught: ";
        outputCaught(fireO, grassO, waterO, user);
    }
    
    float percentNormal = normalSuccess / (double)normalUsed;
    float percentUltra = ultraSuccess / (double)ultraUsed;
    float percentMaster = masterSuccess / (double)masterUsed;

    cout << "Percentage success of normal: " << (percentNormal) * 100 << "%" << endl;
    cout << "Percentage success of ultra: " << (percentUltra) * 100 << "%" << endl;
    cout << "Percentage success of master: " << (percentMaster) * 100 << "%" << endl;

    string normalPercent = to_string(percentNormal);
    string ultraPercent = to_string(percentUltra);
    string masterPercent = to_string(percentMaster);


    string send = python + " ../graphPercentages.py " + normalPercent + " " + ultraPercent + " " + masterPercent;
    system(send.c_str());

    return 0;
}

void validBall(std::string &ballVariation, Trainer &user) {
    // Check that the user has that ball
    bool inBag = user.findBall(ballVariation);
    while ((ballVariation != "normal" && ballVariation != "ultra" && ballVariation != "master") || !inBag) {
        cin.clear();
        string junk;
        getline(cin, junk);
        cout << "Please enter valid input: ";
        cin >> ballVariation;
        inBag = user.findBall(ballVariation);
    }
    cout << endl;
}

void fireCaught(FireType &fire, int caught) {
    // Set caught boolean
    if (caught == 1) {
        fire.setCaught(true);
    } else {
        fire.setCaught(false);
    }
}

void fireAgain(FireType &fireO, Trainer &user, int caught, char choice, std::string ballThrow) {
    // Check if they have pokeballs and haven't caught the pokemon yet
    while (!fireO.getCaught() && choice == 'y' && user.getBalls() > 0) {
        cout << "Would you like to throw another ball at " << fireO.getName() << " ?: (y/n) ";
        cin >> choice;
        // Input validation
        while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
            cin.clear();
            string junk;
            getline(cin, junk);
            cout << "Please enter valid input: ";
            cin >> choice;
        }
        // If they choose yes, ask them which of their remaining pokeballs they
        // would like to throw
        if (choice == 'y' || choice == 'Y') {
            cout << "Which ball would you like to throw? (normal/ultra/master): ";
            cin >> ballThrow;
            validBall(ballThrow, user);
            caught = user.throwBall(ballThrow, normalUsed, normalSuccess, ultraUsed,
                                    ultraSuccess, masterUsed, masterSuccess);
            fireCaught(fireO, caught);
            choice = 'y';
        } else {
            choice = 'n';
        }
    }
}

void grassCaught(GrassType &grass, int caught) {
    // Set caught boolean
    if (caught == 1) {
        grass.setCaught(true);
    } else {
        grass.setCaught(false);
    }
}

void grassAgain(GrassType &grassO, Trainer &user, int caught, char choice, std::string ballThrow) {
    // Check if they have pokeballs and haven't caught the pokemon yet
    while (!grassO.getCaught() && choice == 'y' && user.getBalls() > 0) {
        cout << "Would you like to throw another ball at " << grassO.getName() << " ?: (y/n) ";
        cin >> choice;
        // Input validation
        while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
            cin.clear();
            string junk;
            getline(cin, junk);
            cout << "Please enter valid input: ";
            cin >> choice;
        }
        // If they choose yes, ask them which of their remaining pokeballs they
        // would like to throw
        if (choice == 'y' || choice == 'Y') {
            cout << "Which ball would you like to throw? (normal/ultra/master): ";
            cin >> ballThrow;
            validBall(ballThrow, user);
            caught = user.throwBall(ballThrow, normalUsed, normalSuccess, ultraUsed,
                                    ultraSuccess, masterUsed, masterSuccess);
            grassCaught(grassO, caught);
            choice = 'y';
        } else {
            choice = 'n';
        }
    }
}

void waterCaught(WaterType &water, int caught) {
    // Set caught boolean
    if (caught == 1) {
        water.setCaught(true);
    } else {
        water.setCaught(false);
    }
}

void waterAgain(WaterType &waterO, Trainer &user, int caught, char choice, std::string ballThrow) {
    // Check if they have pokeballs and haven't caught the pokemon yet
    while (!waterO.getCaught() && choice == 'y' && user.getBalls() > 0) {
        cout << "Would you like to throw another ball at " << waterO.getName() << " ?: (y/n) ";
        cin >> choice;
        // Input validation
        while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
            cin.clear();
            string junk;
            getline(cin, junk);
            cout << "Please enter valid input: ";
            cin >> choice;
        }
        // If they choose yes, ask them which of their remaining pokeballs they
        // would like to throw
        if (choice == 'y' || choice == 'Y') {
            cout << "Which ball would you like to throw? (normal/ultra/master): ";
            cin >> ballThrow;
            validBall(ballThrow, user);
            caught = user.throwBall(ballThrow, normalUsed, normalSuccess, ultraUsed,
                                    ultraSuccess, masterUsed, masterSuccess);
            waterCaught(waterO, caught);
            choice = 'y';
        } else {
            choice = 'n';
        }
    }
}

void outputCaught(FireType &fire, GrassType &grass, WaterType &water, Trainer &user) {
    if (user.getNumCaught() == 1) {
        if (fire.getCaught()) {
            cout << fire.getName() << " ";
        }
        if (grass.getCaught()) {
            cout << grass.getName() << " ";
        }
        if (water.getCaught()) {
            cout << water.getName() << " ";
        }
    } else if (user.getNumCaught() == 2) {
        if (fire.getCaught()) {
            cout << fire.getName() << " & ";
        }
        if (grass.getCaught() && fire.getCaught()) {
            cout << grass.getName() << " ";
        } else if (grass.getCaught() && !fire.getCaught()) {
            cout << grass.getName() << " & ";
        }
        if (water.getCaught()) {
            cout << water.getName() << " ";
        }
    } else if (user.getNumCaught() == 3) {
        if (fire.getCaught()) {
            cout << fire.getName() << " , ";
        }
        if (grass.getCaught()) {
            cout << grass.getName() << " , & ";
        }
        if (water.getCaught()) {
            cout << water.getName() << " ";
        }
    }

}