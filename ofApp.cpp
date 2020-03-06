#include "ofApp.h"

void ofApp::setup(){
    
    currentSound = 0;
    playedListSize = 35;
    ofxMC::Matrix matrix("transitionMatrix.txt");
    dice_1.setup(matrix, 0);
    dice_2.setup(matrix, 0);
    int numSamples = 11;
    for (int i = 0; i< numSamples; i++){
        ofSoundPlayer newSample;
        newSample.load(ofToString( i+2 ) + ".mp3");
        newSample.setLoop(false);
        samples.push_back(newSample);
    }
}

void ofApp::draw(){
    /*
     to draw from 1 to 6
     go to ofxMarkovChain.cpp
     change markov draw in line 61 from
     ofDrawBitmapString(ofToString(i), x+25*i-4, y+4);
     to
     ofDrawBitmapString(ofToString(i+1), x+25*i-4, y+4);
     */
    dice_1.draw(40, 60);
    dice_2.draw(40, 85);
    
    ofSetColor(200);
    ofDrawBitmapString("Dice Music:\nPress 'r' to roll", 30, 30);
    ofDrawBitmapString("Sum of two dice: "+ofToString(currentSound+2)+"\nTrack history\n"+ofToString(playedList), 30, 120);
    ofDrawBitmapString("Track Count", 30, 170);
    ofDrawBitmapString("Track 2:  " + ofToString(cnt[0]), 30, 185);
    ofDrawBitmapString("Track 3:  " + ofToString(cnt[1]), 30, 200);
    ofDrawBitmapString("Track 4:  " + ofToString(cnt[2]), 30, 215);
    ofDrawBitmapString("Track 5:  " + ofToString(cnt[3]), 30, 230);
    ofDrawBitmapString("Track 6:  " + ofToString(cnt[4]), 30, 245);
    ofDrawBitmapString("Track 7:  " + ofToString(cnt[5]), 30, 260);
    ofDrawBitmapString("Track 8:  " + ofToString(cnt[6]), 30, 275);
    ofDrawBitmapString("Track 9:  " + ofToString(cnt[7]), 30, 290);
    ofDrawBitmapString("Track 10: " + ofToString(cnt[8]), 30, 305);
    ofDrawBitmapString("Track 11: " + ofToString(cnt[9]), 30, 320);
    ofDrawBitmapString("Track 12: " + ofToString(cnt[10]), 30, 335);
    

    
    ofxMC::Matrix mat = dice_1.getTransitionMatrix();
    stringstream ss;
    ss << "Transition matrix of each die:\n\n";
    for(uint i = 0; i < mat.size(); ++i){
        for(uint j = 0; j < mat[i].size(); ++j){
            ss << mat[i][j] << "  ";
        }
        ss << "\n";
    }
    ofDrawBitmapString( ss.str(), 30, 390);
}

void ofApp::keyPressed(int key){
    switch (key) {
        case 'f':
            ofToggleFullscreen();
            break;
        case 'r':
            if ( samples[currentSound].isPlaying() == true){    // if sample is not finished
                samples[currentSound].stop(); //stop sample
            }
            dice_1.update();
            dice_2.update();
            currentSound = dice_1.getState() + dice_2.getState();
            cnt[currentSound]++;
            samples[currentSound].play();
            samples[currentSound].setLoop(true);
            if (playedList.size() > playedListSize){
                playedList.erase(playedList.begin());

            }
            playedList.push_back(currentSound+2);
            break;
        default:
            break;
    }
}

