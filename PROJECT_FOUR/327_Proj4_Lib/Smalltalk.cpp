/*
 * Smalltalk.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: raymond_sutton
 */

#include "./includes/Smalltalk.h"
#include "./includes/constants.h"
#include <sstream>

using namespace std;

//derived class will set Nationality, iPerson. iPerson is just a counter used to distinguish objects of the same type
Smalltalk::Smalltalk(std::string myNationality, int iPerson) :
        nationality(myNationality), iPerson(iPerson), current_phrase(0), pWatch(
        NULL) {

}

Smalltalk::~Smalltalk(void) {
    if (this->pWatch) {
        delete this->pWatch;
        this->pWatch = 0;
    }
}

//cycles through and returns phrases created in populatePhrases
//takes the form Nationality iPerson: phrase
//for instance the following string comes from an American instance, the 10th iPerson and it is printing AMERICAN_PHRASE_2
//AMERICAN 10:Why yes, I would like to supersize that
std::string Smalltalk::saySomething() {
    stringstream result;
    result << nationality << " " << to_string(iPerson) << ":"
           << mySmallTalk[current_phrase];
    if (mySmallTalk.size() == 7) {
        current_phrase++;
        current_phrase = current_phrase % 7;
    } else {
        current_phrase++;
        current_phrase = current_phrase % 5;
    }

    return result.str();
}

//returns the time or I_DO_NOT_HAVE_A_WATCH string
std::string Smalltalk::getTime() {
    stringstream result;
    result << nationality << " " << to_string(iPerson) << ":";
    if (!pWatch) {
        result << I_DO_NOT_HAVE_A_WATCH;
        return result.str();
    } else {
        result << pWatch->getTime();
    }
    return result.str();
}

//if this object has a watch it is taken away,
//this means return the pointer and set this->pWatch =NULL;
Watch* Smalltalk::takeWatch() {
    if (this->pWatch) {
        Watch *p = pWatch;
        this->pWatch = NULL;
        return p;
    }
    return NULL;
}

//if already have a watch then return false and dont change pWatch pointer
//otherwise accept watch (return true) and set this->pWatch=pWatch
bool Smalltalk::giveWatch(Watch *pWatch) {
    if (this->pWatch) {
        return false;
    } else {
        this->pWatch = pWatch;
        return true;
    }
}

