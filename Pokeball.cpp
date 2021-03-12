//
// Created by Sam Pitonyak on 12/6/20.
//


#include "Pokeball.h"

// Default constructor, setting the likelihood of the effectiveness of the pokeball
Pokeball::Pokeball() : normalBall(false), ultraBall(false), masterBall(false){
}
//
// Getters
bool Pokeball::getNormalBall() const {
    return normalBall;
}

bool Pokeball::getUltraBall() const {
    return ultraBall;
}

bool Pokeball::getMasterBall() const {
    return masterBall;
}

// Setters
void Pokeball::setNormalBall(bool value) {
    normalBall = value;
}

void Pokeball::setUltraBall(bool value){
    ultraBall = value;
}

void Pokeball::setMasterBall(bool value){
    masterBall = value;
}
