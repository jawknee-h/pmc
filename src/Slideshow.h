#pragma once

#include "ofMain.h"
#include "ShadowScene.h"
//#include "ProximityScene.h"

class Slideshow
{

	public:
		void setup();
		void update();
		void draw();
		int get_slide_num();
		void change_slide(int slide_num);
		void next_slide();
		void prev_slide();
		void key_pressed(int key);
		Slideshow();

	private:
		int current_slide_num;
		ShadowScene shadow_scene;
		ofTrueTypeFont annotation_font;
};
