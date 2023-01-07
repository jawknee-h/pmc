#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(ofColor(131));
	slides.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
	slides.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	slides.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key)
	{
		// left arrow
		case 57356:
			slides.prev_slide();
			break;

		// right arrow
		case 57358:
			slides.next_slide();
			break;

		default:
			slides.key_pressed(key);
			break;
	}
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