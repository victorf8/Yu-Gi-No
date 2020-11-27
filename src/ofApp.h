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
			eBoard[i] = NULL;
			pBoard[i] = NULL;
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
			if (pBoard[i] == NULL) {
				pBoard[i] = card;
				cout << pBoard[i]->name << endl;/////////////////////////
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


		x = 5;
		for (int i = 0; i < 5; i++) {
			if (pBoard[i] != NULL) {

				cout << "attempting to draw " << pBoard[i]->name << endl;////////////////////
				

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

		MonsterCard *mc = (MonsterCard *)hand[x];

		field.play(mc);

		hand[x] = NULL;


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

//////////////////////////////////////Start Of Button Class
class Buttons {
public:
	int gameState;
	int lastButton;

	Buttons() {
		gameState = 0;
	}

	void draw() {
		ofSetColor(0, 255, 0);
		ofDrawRectangle(1200, 47, 100, 50);
		ofDrawRectangle(1200, 153, 100, 50);
		ofDrawRectangle(1097, 100, 100, 50);
		ofDrawRectangle(1303, 100, 100, 50);

		if (gameState == 0) {
			ofDrawBitmapString("Which card would you like to play?", 1100, 40);
			ofDrawBitmapString("1", 1203, 63);
			ofDrawBitmapString("3", 1203, 169);
			ofDrawBitmapString("4", 1100, 116);
			ofDrawBitmapString("2", 1306, 116);
		}

		if (gameState == 1) {
			ofDrawBitmapString("Which card would you like to attack? (if empty attack player directly)", 1100, 40);
			ofDrawBitmapString("1", 1203, 63);
			ofDrawBitmapString("3", 1203, 169);
			ofDrawBitmapString("4", 1100, 116);
			ofDrawBitmapString("2", 1306, 116);
		}
	}

	void buttonPressed(int btn, Field field, Hand hand) {
		if (btn < 5) {
			if (gameState == 0) {
				btn = 1;
				cout << "attempting to play card from btn press" << endl;
				hand.play(field, btn - 1);
				gameState = 1;
			}
		}
	}
};
//////////////////////////////////////End Of Button Class


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
		Buttons buttons;

		
};
