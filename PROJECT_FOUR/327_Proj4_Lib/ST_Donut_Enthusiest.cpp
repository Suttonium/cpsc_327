/*
 * ST_American_DonutEthusiest.cpp
 *
 *  Created on: Nov 15, 2017
 *      Author: raymond_sutton
 */
#include "./includes/constants.h"
#include "includes/Smalltalk_American.h"
#include "includes/ST_Donut_Enthusiest.h"


ST_American_DonutEnthusiest::ST_American_DonutEnthusiest(int iPerson) :
        Smalltalk_American::Smalltalk_American(AMERICAN_DE, iPerson) {
    populatePhrases();

}

ST_American_DonutEnthusiest::~ST_American_DonutEnthusiest(void) {

}

void ST_American_DonutEnthusiest::populatePhrases() {
    mySmallTalk.push_back(AMERICAN_DE_PHRASE_1);
    mySmallTalk.push_back(AMERICAN_DE_PHRASE_2);
    mySmallTalk.push_back(AMERICAN_DE_PHRASE_3);
    mySmallTalk.push_back(AMERICAN_DE_PHRASE_4);
    mySmallTalk.push_back(AMERICAN_DE_PHRASE_5);
}
