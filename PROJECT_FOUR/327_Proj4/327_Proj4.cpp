//
// Created by Austin Sutton on 12/11/2017.
//
// smalltalk_VirtualAbstractVector.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "../327_Proj4_Lib/includes/Functions.h"
#include <memory>
#include <vector>
#include <sstream>
using namespace std;
//TODO make sure you have the right number of watches
//TODO make sure you consider the case where you have more watches than people
//TODO make sure you do not do a deep copy any watches when giving or taking them
//     the simplest way is give and take the watch a few times and verify that the old recipients have
//     a null pWatch pointer
//     and that the pointer returned from the last takeWatch is the same as the one you began with on giveWatch
//TODO make sure saySomething() cycles through appropriate phrases

void demo() {
    int numEachGroup = 2;
    int numwatches = 2;

    std::vector<std::unique_ptr<Smalltalk> > myv1 = getPeople(numEachGroup,
                                                              numEachGroup, numEachGroup, numwatches);
    int cntr = 0;
    for (int i = 0; i < myv1.size(); i++) {
        std::cout << myv1[i]->saySomething() << endl;
        std::cout << myv1[i]->getTime() << endl;
    }
}

void test_one() {
    cout << "TEST ONE:   MAKE SURE YOU HAVE THE RIGHT NUMBER OF WATCHES"
         << endl;

    int numAmericansTestOne = 2;
    int numDETestOne = 2;
    int numBritsTestOne = 2;
    int numWatchesTestOne = 4;

    vector<unique_ptr<Smalltalk>> talking_small = getPeople(numBritsTestOne,
                                                            numAmericansTestOne, numDETestOne, numWatchesTestOne);

    int watch_counter = 0;

    for (unsigned int i = 0; i < talking_small.size(); i++) {
        string get_time_output = talking_small[i]->getTime(); // get the Smalltalk::getTime() string
        int colon_index = get_time_output.find(":"); // find the index of the colon to ignore the returned nationality and iPerson
        string after_colon = get_time_output.substr(colon_index + 1,
                                                    get_time_output.size()); // substring the getTime() string to everything after the colon
        if (after_colon != "I do not have a watch") { // if the substring is not I_DO_NOT_HAVE_A_WATCH, the object has a watch
            watch_counter++;
        }
    }

    cout << "Number of watches that was supposed to be given: "
         << numWatchesTestOne << ". Number of watches gathered from vector: "
         << watch_counter << endl;

}

void test_two() {
    cout
            << "TEST TWO:   CONSIDER THE CASE WHERE YOU HAVE MORE WATCHES THAN PEOPLE"
            << endl;

    int numAmericansTestTwo = 1;
    int numDETestTwo = 1;
    int numBritsTestTwo = 1;
    int numWatchesTestTwo = 6;

    vector<unique_ptr<Smalltalk>> talking_small_two = getPeople(numBritsTestTwo,
                                                                numAmericansTestTwo, numDETestTwo, numWatchesTestTwo);

    int remaining_watches = numWatchesTestTwo;

    for (unsigned int i = 0; i < talking_small_two.size(); i++) {
        string get_time_output = talking_small_two[i]->getTime(); // get the Smalltalk::getTime() string
        int colon_index = get_time_output.find(":"); // find the index of the colon to ignore the returned nationality and iPerson
        string after_colon = get_time_output.substr(colon_index + 1,
                                                    get_time_output.size()); // substring the getTime() string to everything after the colon
        if (after_colon != "I do not have a watch") { // if the substring is not I_DO_NOT_HAVE_A_WATCH, the object has a watch
            remaining_watches--;
        }
    }

    cout << "Number of watches to be given out: " << numWatchesTestTwo
         << ". Number of people to receive watches: "
         << numAmericansTestTwo + numDETestTwo + numBritsTestTwo
         << ". Number of watches remaining: " << remaining_watches << endl;
}

void test_three() {
    cout << "TEST THREE: MAKE SURE NO DEEP COPIES OCCUR" << endl;

    int numAmericansTestThree = 1;
    int numDETestThree = 1;
    int numBritsTestThree = 1;
    int numWatchesTestThree = 3;  // only one watch given

    vector<unique_ptr<Smalltalk>> talking_small_three = getPeople(
            numBritsTestThree, numAmericansTestThree, numDETestThree,
            numWatchesTestThree);

    unique_ptr<Watch> watch_pointer(std::move(new Watch()));
    Watch *normal_pointer_one = watch_pointer.get();
    talking_small_three[1]->giveWatch(normal_pointer_one);

    cout << "Time before removing watch: " << normal_pointer_one->getTime()
         << endl;

    unique_ptr<Watch> watch_pointer_two(
            std::move(talking_small_three[1]->takeWatch()));
    talking_small_three[2]->giveWatch(normal_pointer_one);

    cout << "Time after replacing removed watch: "
         << normal_pointer_one->getTime() << endl;


}

void test_four() {
    cout
            << "TEST FOUR:  MAKE SURE SAYSOMETHING() CYCLES THROUGH CORRECT PHRASES"
            << endl;

    int numAmericansTestFour = 1;
    int numDETestFour = 1;
    int numBritsTestFour = 1;
    int numWatchesTestFour = 0;

    vector<unique_ptr<Smalltalk>> talking_small_four = getPeople(
            numBritsTestFour, numAmericansTestFour, numDETestFour,
            numWatchesTestFour);

    for (unsigned int i = 0; i < talking_small_four.size(); i++) {
        int phrase_counter = 0;
        while (phrase_counter < 15) { // using 15 to assure the brits can iterate through the phrases at least twice to assure they cycle currectly
            cout << "PHRASE: " << phrase_counter + 1
                 << " "
                 << talking_small_four[i]->saySomething()
                 << endl;
            phrase_counter++;
        }
    }
}

int main() {
    //demo();
    test_one();
    test_two();
    test_three();
    test_four();
}

