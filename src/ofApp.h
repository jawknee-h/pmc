#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "ShadowScene.h"
#include "Slideshow.h"

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

		Slideshow slides;
		
		// draw the impossible triangle, or penrose triangle
		void draw_penrose_triangle_scene();

		//ShadowScene shadow_scene;

		//void setup_shadow_scene();
		//void draw_shadow_scene();

		//// camera so we can control perspective easily.
		//ofEasyCam cam;

		//// penrose triangle - perspective
		//ofxAssimpModelLoader penrose_triangle;
};
