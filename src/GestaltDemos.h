#pragma once

#include "ofMain.h"
#include "ofxSvg.h"

void setup_gestalt_demos();

void enable_outline();

void disable_outline();

void toggle_drawing_mode();

void law_of_proximity_simplified(int x_pos, int y_pos, int cols, int grid_scale, int gap_size, int circle_radius);

void law_of_proximity();

void law_of_pragnanz(int x_pos, int y_pos);

void law_of_pragnanz_simplified(int x_pos, int y_pos);