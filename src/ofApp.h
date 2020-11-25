#pragma once

#include "ofMain.h"

/////////////////////CARD CLASSES
class Card {
public:

	string name;
	string type;
	string descrip;

	void destroy() {
		//remove card completely
	}

	virtual MonsterCard* play() = 0;

};


class MonsterCard : public Card {
public:


	int LVL;
	int ATK;
	int DEF;

	int pos;

	MonsterCard::MonsterCard() {
		type = "Monster";
	}

	MonsterCard* play() {


		MonsterCard* current = new MonsterCard();
		current = this;
		return current;
	}

	
	void attack(MonsterCard target) {
		if (target.pos == 0) {
			target.flip();
		}

	}

	void flip() {
		if (pos == 0) {
			pos = 1;
		}
		else if (pos == 1) {
			pos = 1;
		}
		else if (pos == 2) {
			pos = 1;
		}
	}
};



class SpellCard : public Card {
public:


	SpellCard::SpellCard() {
		type = "Spell";
	}

	MonsterCard* play() {

	}
};
///////////////////////////////////////////end of card classes





/////////////////////////START OF FIELD CLASS
class Field {
public:

	MonsterCard* eBoard[5];
	MonsterCard* pBoard[5];
	int pos;

	Field() {
		for (int i = 0; i < 5; i++) {
			eBoard[i]->name = "";
			pBoard[i]->name = "";
		}
	}

	void remove(MonsterCard* card, int player) {
		if (player == 1) {
			for (int i = 0; i < 5; i ++) {
				if (pBoard[i]->name == card->name) {
					pBoard[i] = NULL;
				}
			}
		}else if (player == 0) {
			for (int i = 0; i < 5; i++) {
				if (eBoard[i]->name == card->name) {
					eBoard[i] = NULL;
				}
			}
		}
	}

	void play(MonsterCard* card) {
		for (int i = 0; i < 5; i++) {
			if (pBoard[i]->name == "") {
				pBoard[i] = card;
				i = 5;
			}
		}
	}
	

	void draw() {
		ofSetColor(255, 0, 0);
		ofNoFill();
		int x = 5;
		int y = 5;

		for (int u = 0; u < 2; u++) {
			for (int i = 0; i < 5; i++) {
				ofDrawRectangle(x, y, 200, 350);
				x += 201;
			}
			ofSetColor(0, 0, 255);
			y += 450;
			x = 5;
		}

		for (int i = 0; i < 5; i++) {
			if (pBoard[i]->name != "") {
				x = 5;

				ofSetColor(0, 255, 0);
				ofDrawBitmapString(pBoard[i]->name, x + 5, y + 5);
				ofDrawBitmapString(pBoard[i]->type, x + 5, y + 10);
			}
		}
	}
};
//////////////////////////////////////end of field class

////////////////////////////////////////Start hand class
class Hand {
public:

	Card* hand[4];

	Hand() {
		for (int i = 0; i < 4; i++) {
			hand[i] = NULL;
		}

	}

	void drawCard(Card* c) {

		int i = 0;
		while (i != 4) {
			if (hand[i] == NULL) {
				hand[i] = c;
				return;
			}
			else { i++; }
		}
	}

	void play(Field field, int x) {

		field.play(hand[x]->play());

		hand[x] == NULL;

	}


	void draw() {

		ofNoFill();

		int btm = ofGetHeight();
		int x = 1050;

		for (int i = 0; i < 4; i++) {
			if (hand[i] == NULL) {
				ofSetColor(255, 255, 255);
				ofDrawRectangle(x, btm - 400, 200, 350);
				x += 201;
			}
			else {
				ofSetColor(0, 255, 0);
				ofDrawRectangle(x, btm - 400, 200, 350);


				ofBitmapFont();
				ofDrawBitmapString(hand[i]->name, x + 5, btm - 385);
				ofDrawBitmapString(hand[i]->type, x + 5, btm - 370);

				if (hand[i]->type == "Monster") {
					MonsterCard *mc = (MonsterCard *)hand[i];
					ofDrawBitmapString(mc->LVL, x + 185, btm - 385);
					ofDrawBitmapString(mc->ATK, x + 120, btm - 370);
					ofDrawBitmapString("/", x + 155, btm - 370);
					ofDrawBitmapString(mc->DEF, x + 165, btm - 370);
				}
				else if (hand[i]->type == "Spell") {
					SpellCard *mc = (SpellCard *)hand[i];

				}

				x += 201;
			}

		}

	}

};
/////////////////////////////////////end of hand class


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);



		vector <Card*> deck;
		//vector <Card> hand;
		Field field;
		Hand hand;

		
};
