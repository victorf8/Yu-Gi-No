#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetBackgroundColor(0, 0, 0);
	
	ifstream file;
	file.open("CardDirectory.txt", ofstream::in);

	if (!file.is_open()) {
		cerr << "SOMETHING IS WRONG ABANDON SHIP!!!";
	}//if

	int lvl, atk, def;
	string name, type, des;

	cout << "Processing text file to construct cards." << endl << endl;

	while (file >> type >> lvl >> name >> atk >> def >> des) {
		
		cout << "Processing line:" << endl;
		cout << type << " " << lvl << " " << name << " " << atk << " " << def << " " << des << endl;

		if (type == "m") {
			MonsterCard* current = new MonsterCard();
			current->type = "Monster";
			current->name = name;
			current->descrip = des;
			current->LVL = lvl;
			current->ATK = atk;
			current->DEF = def;

			deck.push_back(current);

			cout << "Monster Card : " << current->name << " is lvl " << current->LVL << " with an attack of " << current->ATK << " and defence of " << current->DEF << endl << endl;
		}
		else if (type == "s") {
			SpellCard* current = new SpellCard();
			current->type = "Spell";
			current->name = name;

			deck.push_back(current);

			cout << "Spell " << name << " processed." << endl << endl;
		}

	}
	hand.drawCard(deck[0]);
	hand.drawCard(deck[18]);
	hand.play(field, 0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	field.draw();
	hand.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
