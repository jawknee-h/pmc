#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// penrose triangle
	// for the illusion to work:
	// - ortho
	//		- button to toggle ortho mode
	// - lighting so there are shadows
	//		- button to toggle lighting (possibly move it too?)
	// - correct camera angle
	//		- button to lerp camera to dif pos, then lerp back when button released
	/*penrose_triangle.loadModel("/models/penrose_tri.obj");
	cam.enableOrtho();*/
	ofSetBackgroundColor(ofColor(20));
	slides.setup();
	//shadow_scene.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
	//shadow_scene.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

	//shadow_scene.draw();
	slides.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	cout << "key pressed in ofApp" << endl;
	cout << key << endl;
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

		case int('s'):
			//shadow_scene.enable_shadows();
			break;
		
		case int('d'):
			//shadow_scene.disable_shadows();
			break;

		default:
			slides.key_pressed(key);
			break;
	}
	//shadow_scene.toggle_camera_pos();
	/*cout << key;
	switch (key)
	{
		case 57356:
			shadow_scene.text_shadow.setPosition(shadow_scene.text_shadow.getPosition() + ofVec3f(10, 0, 0));
			break;
		case 57358:
			shadow_scene.text_shadow.setPosition(shadow_scene.text_shadow.getPosition() + ofVec3f(-10, 0, 0));
			break;
		case 57357:
			shadow_scene.text_shadow.setPosition(shadow_scene.text_shadow.getPosition() + ofVec3f(0, 10, 0));
			break;
		case 57359:
			shadow_scene.text_shadow.setPosition(shadow_scene.text_shadow.getPosition() + ofVec3f(0, -10, 0));
			break;
		case 44:
			shadow_scene.text_shadow.setPosition(shadow_scene.text_shadow.getPosition() + ofVec3f(0, 0, 10));
			break;
		case 46:
			shadow_scene.text_shadow.setPosition(shadow_scene.text_shadow.getPosition() + ofVec3f(0, 0, -10));
			break;
	}*/

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