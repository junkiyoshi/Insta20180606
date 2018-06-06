#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");

	ofSetColor(39);

	ofTrueTypeFontSettings font_settings("fonts/EmojiSymbols-Regular.ttf", 30);
	font_settings.antialiased = true;
	font_settings.addRanges(ofAlphabet::Emoji);
	this->font.load(font_settings);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	vector<string> words = {
		u8"💪", u8"😋", u8"💘", u8"😍", u8"👙",
	};

	for (int x = 20; x < ofGetWidth(); x += 50) {

		for (int y = 50; y < ofGetHeight(); y += 50) {

			int words_index = ofNoise(x * 0.0005, y * 0.0005, ofGetFrameNum() * 0.005) * words.size();
			std::string moji = words[words_index];
			this->font.drawString(moji, x, y);
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}