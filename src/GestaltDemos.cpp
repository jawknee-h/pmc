#include <iostream>
#include "GestaltDemos.h"

using namespace std;

// SVG path used for demos
ofxSVG hello_svg;
vector<ofPath> paths;

// the drawing mode for the simplified pragnanz example
// whether to draw as individual shapes or one shape
bool draw_mode;


/// function to setup the demos
void setup_gestalt_demos()
{
	// setting circle resolution a bit higher than default so the circle is smoother
	ofSetCircleResolution(64);

	// loading the svg file into the ofxSVG variable
	hello_svg.load("svg/hello_svg.svg");

	// getting the individual paths from the svg and..
	for (int i = 0; i < hello_svg.getNumPath(); i++)
	{
		// pushing them to a vector to store them all,
		paths.push_back(hello_svg.getPathAt(i));

		// offsetting the paths slightly by a random amount so the cracks between them are visible
		paths[i].translate({ ofRandom(10), ofRandom(10) });
	}

	// disabling outline by default
	disable_outline();
}

/// function to switch to draw mode 1
/// where everything will be drawn with different fill colours
void enable_outline()
{
	// for each path..
	for (int i = 0; i < paths.size(); i++)
	{
		// generate a fill colour which will be:
		// - 'step' amt different from the paths next to it
		// - brighter than 'min' amt
		int step = 80;
		int min = 50;
		int col = ofMap(
			(i*step)%255,
			0, 
			255,
			min,
			255
		);
		paths[i].setFillColor(col);
	}

	// switch draw mode
	draw_mode = 1;
}

/// function to switch to draw mode 0
/// where everything will be drawn with the same fill colour
void disable_outline()
{
	// for each path..
	for (int i = 0; i < paths.size(); i++)
	{
		// set the fill colour to a constant value
		paths[i].setFillColor(100);
	}

	// switch draw mode
	draw_mode = 0;
}

/// function to toggle the drawing mode
///		-> draw_mode 0 == all one fill colour
///		-> draw_mode 1 == all different fill colours
void toggle_drawing_mode()
{
	if (draw_mode == 0)
	{
		enable_outline();
	}
	else if (draw_mode == 1)
	{
		disable_outline();
	}
}

/// function to draw the simplified law of proximity example
/// (this is the example with the grid of circles)
void law_of_proximity_simplified(int x_pos, int y_pos, int cols, int grid_scale, int gap_size, int circle_radius)
{
	// how wide the column is (the distance between circles when gap_size is 0)
	int col_width = grid_scale/cols;

	// translating so that the grid is centered at the position passed in
	ofPushMatrix();
	ofTranslate(
		x_pos - (grid_scale/3 + col_width/2 + gap_size),
		y_pos - grid_scale/2 + col_width/2
	);

	// drawing the grid
	for (int x = 0; x < cols; x++)
	{
		// every two cols, make a gap
		if (x % 2 == 0)
		{
			// so that the whole table isn't translated when x is 0, only when it's 2 and 4
			if (x != 0)
			{
				ofTranslate(gap_size, 0);
			}
		}
		for (int y = 0; y < cols; y++)
		{
			// drawing the shape
			ofPushStyle();
			ofSetColor(220);
			ofDrawEllipse({x * col_width, y * col_width}, circle_radius, circle_radius);
			ofPopStyle();
		}
	}
	ofPopMatrix();
}

/// function to draw the complex law of proximity example
/// (this is the example with the 'hello' text)
void law_of_proximity()
{

}

/// function to draw the complex law of pragnanz example
/// (this is the example with the 'hello' text)
void law_of_pragnanz(int x_pos, int y_pos)
{
	// translate to the position passed in and..
	ofPushMatrix();
	ofTranslate({ x_pos, y_pos });
	// draw each path
	for (int i = 0; i < paths.size(); i++)
	{
		paths[i].draw();
	}
	ofPopMatrix();
}

/// function to draw the simplified law of pragnanz example
/// (this is the example with the overlapping primitive shapes)
void law_of_pragnanz_simplified(int x_pos, int y_pos)
{
	// translating drawing to the passed in position..
	// then offsetting slightly so the drawing is perfectly centered
	ofPushMatrix();
	ofTranslate(x_pos, y_pos);
	ofTranslate(-100, -20);

	// drawing all the shapes with the same fill
	if (draw_mode == 0)
	{
		// setting colour to a constant amount
		ofSetColor({100});

		// drawing ellipse
		ofDrawEllipse({ 0, 0 }, 200, 200);

		// drawing rectangle
		ofDrawRectangle({ 45, 45 }, 200, 200);

		// drawing triangle
		ofPushMatrix();
		ofTranslate(150, -108);
		ofRotateDeg(20);
		ofDrawTriangle({ 0, -80 }, { 80, 80 }, { -80, 80 });
		ofPopMatrix();

	}
	// drawing all of the shapes with different fills
	else if (draw_mode == 1)
	{
		// drawing ellipse with its own colour
		ofSetColor(60);
		ofDrawEllipse({ 0, 0 }, 200, 200);

		// drawing rectangle with its own colour
		ofSetColor(120);
		ofDrawRectangle({ 45, 45 }, 200, 200);

		// drawing triangle with its own colour
		ofSetColor(250);
		ofPushMatrix();
		ofTranslate(150, -108);
		ofRotateDeg(20);
		ofDrawTriangle({ 0, -80 }, { 80, 80 }, { -80, 80 });
		ofPopMatrix();
	}
	ofPopMatrix();
}