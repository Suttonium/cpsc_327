/*
 * Functions.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: keith
 */

#include "./includes/Functions.h"
#include "./includes/Smalltalk_American.h"
#include "includes/ST_Donut_Enthusiest.h"
#include "./includes/Smalltalk_Brit.h"
#include "./includes/Watch.h"
#include "./includes/constants.h"

using namespace std;

//create a vector with a brit,american, donut enthusiest using unique pointers
//use c++11 and then returning by value is fine since the compiler will move the vector
//on return rather than recreate it(if using C++11).
std::vector<std::unique_ptr<Smalltalk>> getPeople(int numBrit, int numAmerican,
                                                  int numbAmericanDonutEnthusiest, int numWatches) {

    //create a vector to hold SmallTalk unique pointers
    vector<unique_ptr<Smalltalk>> talking_small;

    //add brits to vector
    int brit_counter = 0;
    while (brit_counter < numBrit) {
        talking_small.push_back(
                unique_ptr<Smalltalk>(new Smalltalk_Brit(brit_counter++)));
        //brit_counter++;
    }
    //add americans  to vector
    int american_counter = 0;
    while (american_counter < numAmerican) {
        talking_small.push_back(
                unique_ptr<Smalltalk>(
                        new Smalltalk_American(american_counter++)));
        //american_counter++;
    }
    //add american donut enthusiest  to vector
    int DE_counter = 0;
    while (DE_counter < numbAmericanDonutEnthusiest) {
        talking_small.push_back(
                unique_ptr<Smalltalk>(
                        new ST_American_DonutEnthusiest(DE_counter++)));
        //DE_counter++;
    }

    //create some watches (as long as number watches <= numb people)
//	int current_person = 0;
//	int num_watches = 0;
//	while (num_watches != numWatches && num_watches <= talking_small.size) {
//		Watch *p = new Watch();
//		talking_small[current_person]->giveWatch(p);
//		current_person++;
//		num_watches++;
//	}
    int num_watches_left = numWatches;
    for (unsigned int i = 0; i < talking_small.size(); i++) {
        if (num_watches_left != 0) {
            Watch *p = new Watch();
            talking_small[i].get()->giveWatch(p);
            p = NULL;
            num_watches_left--;
        }
    }

    //then give the watches away to first NUM_WATCHES people in the vector
    //keep in mind that you are responsible for deleting any pointers to
    //watches allocated on the heap when you are finished using the vector you return
    //from this function(see Smalltalk header for hints)

    //return your vector
    return talking_small;
}
