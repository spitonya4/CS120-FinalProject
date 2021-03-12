//
// Created by Sam Pitonyak on 12/6/20.
//

#ifndef FINAL_PROJECT_SPITONYA_POKEBALL_H
#define FINAL_PROJECT_SPITONYA_POKEBALL_H

// The pokeball class is an object that creates a pokeball object, there are
// three different types of pokeballs which each have a different likelihood of
// catching a pokemon

class Pokeball {
private:
    bool normalBall;
    bool ultraBall;
    bool masterBall;
public:
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: sets all three fields to private
     */
    Pokeball();

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns boolean value of normal ball
     */
    bool getNormalBall() const;
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns boolean value of ultra ball
     */
    bool getUltraBall()  const;
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns boolean value of master ball
     */
    bool getMasterBall() const;

    /**
     * Requires: nothing
     * Modifies: normal ball
     * Effects: modifies boolean value of normal ball
     */
    void setNormalBall(bool value);
    /**
     * Requires: nothing
     * Modifies: ultra ball
     * Effects: modifies boolean value of ultra ball
     */
    void setUltraBall(bool value);
    /**
     * Requires: nothing
     * Modifies: master ball
     * Effects: modifies boolean value of master ball
     */
    void setMasterBall(bool value);


};

#endif //FINAL_PROJECT_SPITONYA_POKEBALL_H
