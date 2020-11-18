#pragma once

#include "ofMain.h"

/////////////////////CARD CLASSES
class Card {
public:

	string name;
	string type;

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

	void play() {
		if (LVL > 6) {
			//request 2 tributes
		}
		else if (LVL > 4) {
			//request 1 tribute
		}
		else {
			//add card to board array
		}
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


////////////////////////////////////////Start hand class
class Hand {
public:

	Card hand[6];

	Hand() {
		for (int i = 0; i < 6; i++) {
			hand[i].name = "";
		}
	}

	void draw() {
		
		ofNoFill();

		int btm = ofGetHeight();
		int x = 200;

		for (int i = 0; i < 7; i++) {
			if (hand[i].name == "") {
				ofSetColor(255, 255, 255);
				ofDrawRectangle(x, btm - 350, 200, 350);
				x += 201;
			}
			else {
				ofSetColor(0, 255, 0);
				ofDrawRectangle(x, btm - 350, 200, 350);
				x += 201;
				//draw card components

			}
			
		}

	}

};
/////////////////////////////////////end of hand class


/////////////////////////START OF FIELD CLASS
class Field {
public:

	Card eBoard[5];
	Card pBoard[5];

	void play(Card curr, int position) {
		pBoard[position - 1] = curr;
	}

	void remove(int pos) {

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
	}
};
//////////////////////////////////////end of field class



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

		string lowLVL[10] = { "1 KuriBro 400 500" ,
		"4 Henry_MadCock 1900 0",
		"3 Baby_Knight_of_Valkyrie 1500 1700",
		"2 Peter_McSkeeter 900 700" ,
		"3 Gatorade 1500 1500",
		"4 Zangles 2000 0",
		"1 Peggi-18 300 1100",
		"4 Succulent_Face_Melter 2100 1500",
		"2 Puffmíster 1100 1200",
		"3 Goat_Goblin 1600 1600" };

		string highLVL[5] = { "6 Winged_Knight_of_Valyrie 2400 3000",
			"5 Zad 2200 2000",
			"7 Organ_Blender 2600 400",
			"8 Choco_StarFish_Devourer 1300 3500",
			"6 Marc_Rubbindorf 2500 2500" };

		string spells[5] = { "Flip 'n' Flop",
			"Destuto",
			"Talk To The Hand",
			"GameStop Trade",
			"Don't Mind If I Do" };

		vector <Card> deck;
		//vector <Card> hand;
		Field field;
		Hand hand;

		
};
