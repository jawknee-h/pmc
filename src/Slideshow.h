#pragma once

#include "ofMain.h"
#include "ShadowScene.h"
#include "GestaltDemos.h"

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
		void draw_annotation(string text);
		Slideshow();

	private:
		int current_slide_num;
		ShadowScene shadow_scene;
		ofTrueTypeFont annotation_font;
};