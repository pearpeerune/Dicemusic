/*
 Project Title: markovChainDrum
 Description: markov chain drum machine
 ©Daniel Buzzo 2020
 dan@buzzo.com
 http://buzzo.com
 https://github.com/danbz
 */

// dependencies: ofxMarkovChain addon //

#pragma once

#include "ofMain.h"
#include "ofxMarkovChain.h"


class ofApp : public ofBaseApp{

    public:
        void setup();
        void draw();
        void keyPressed(int key);
        
    
    vector<ofSoundPlayer> samples;
    ofxMC::MarkovChain dice_1, dice_2;
    int currentSound, playedListSize, cnt[11] = {0};
    vector<int> playedList;

};
