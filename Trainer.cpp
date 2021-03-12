//
// Created by Sam Pitonyak on 12/6/20.
//


#include "Trainer.h"
#include <iostream>

Trainer::Trainer() : numCaught(0), balls(0) {
    bag.clear();
}

// Getters
int Trainer::getNumCaught() const {
    return numCaught;
}

int Trainer::getBalls() const {
    return balls;
}

vector<Pokeball> Trainer::getBag() const {
    return bag;
}

std::string Trainer::getBallsFromBag() const {
    std::string ballType = "";
    //int typeBall;
    for (int i = 0; i < bag.size(); ++i) {
        //int ball = (rand() % 3 + 1);
        if (bag[i].getNormalBall()) {
            ballType += " normal ball,";
        } else if (bag[i].getUltraBall()) {
            ballType += " ultra ball,";
        } else if (bag[i].getMasterBall()) {
            ballType += " master ball,";
        }
    }
    // Remove the last comma from string
    std::string ballString = "";
    ballString += ballType.substr(0, ballType.size() - 1);
    return ballString;
}

// Setter
void Trainer::setBalls(int value) {
    // This sets the number of balls to add into the bag
    balls = value;
}

void Trainer::addToBag() {
    // This randomly selects a value and adds one of the three balls to the
    // bag based on the number
    int i;
    int master = 0;
    for (i = 0; i < balls; ++i) {
        Pokeball ball;
        // Generate random value
        int ballType = (rand() % 3 + 1);
        if (ballType == 1) {
            ball.setNormalBall(true);
            bag.push_back(ball);
        } else if (ballType == 2) {
            ball.setUltraBall(true);
            bag.push_back(ball);
        } else if (ballType == 3 && master < 2) {
            ball.setMasterBall(true);
            master += 1;
            bag.push_back(ball);
        }
    }
}

bool Trainer::findBall(std::string ballString) {
    if (ballString == "normal") {
        //int val = 2;
        for (int i = 0; i < bag.size(); ++i) {
            if (bag[i].getNormalBall()) {
                return true;
            }
        }
        return false;
    } else if (ballString == "ultra") {
        //int val = 4;
        for (int i = 0; i < bag.size(); ++i) {
            if (bag[i].getUltraBall()) {
                return true;
            }
        }
        return false;
    } else if (ballString == "master") {
        //int val = 10;
        for (int i = 0; i < bag.size(); ++i) {
            if (bag[i].getMasterBall()) {
                return true;
            }
        }
        return false;
    }
}

int Trainer::throwBall(std::string type, double &normalUsed, double &normalSuccess, double &ultraUsed,
                       double &ultraSuccess, double &masterUsed, double &masterSuccess) {
    balls -= 1;
    // Simulates the throwing of a pokeball and if the pokemon is caught
    // Generate random value to compare to ball value
    int chances = (rand() % 9 + 1);
    // Search for the position in the bag to delete it
    if (type == "normal") {
        for (int i = 0; i < bag.size(); ++i) {
            if (bag[i].getNormalBall()) {
                if (2 > chances) {
                    std::cout << "You caught it!" << std::endl;
                    numCaught += 1;
                    normalSuccess += 1;
                    normalUsed += 1;
                    bag.erase(bag.begin() + i);
                    return 1;
                } else {
                    std::cout << "You did not catch it..." << std::endl;
                    normalUsed += 1;
                    bag.erase(bag.begin() + i);
                    return 0;
                }
            }
        }
    } else if (type == "ultra") {
        for (int i = 0; i < bag.size(); ++i) {
            if (bag[i].getUltraBall()) {
                if (4 > chances) {
                    std::cout << "You caught it!" << std::endl;
                    numCaught += 1;
                    ultraSuccess += 1;
                    ultraUsed += 1;
                    bag.erase(bag.begin() + i);
                    return 1;
                } else {
                    std::cout << "You did not catch it..." << std::endl;
                    ultraUsed += 1;
                    bag.erase(bag.begin() + i);
                    return 0;
                }
            }
        }
    } else if (type == "master") {
        for (int i = 0; i < bag.size(); ++i) {
            if (bag[i].getMasterBall()) {
                if (10 > chances) {
                    std::cout << "You caught it!" << std::endl;
                    numCaught += 1;
                    masterSuccess += 1;
                    masterUsed += 1;
                    bag.erase(bag.begin() + i);
                    return 1;
                }
            }
        }
    }
}