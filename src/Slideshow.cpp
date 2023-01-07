#include "Slideshow.h"

// constructor
Slideshow::Slideshow()
{
	cout << "slideshow constructed" << endl;

	annotation_font.load("fonts/TitilliumWeb-Regular.ttf", 16);
}

//--------------------------------------------------------------
void Slideshow::setup() {
	// setting up the shadow scene for when we need it
	shadow_scene.setup();

	// setting up the gestalt demos for when we need it
	setup_gestalt_demos();

	// starting off on the first slide
	change_slide(0);
}

//--------------------------------------------------------------
void Slideshow::update(){
	// clamping the current slide number so it can't go out of range to empty slides
	current_slide_num = CLAMP(current_slide_num, 0, 13);
}

//--------------------------------------------------------------
void Slideshow::draw(){
	// doing different things based on the current slide num
	switch (current_slide_num)
	{
		case 0:
		{
			shadow_scene.update();
			shadow_scene.draw();

			draw_annotation(
				"in text citations eg '[2]' refer to the full reference list in the write up pdf.\n\n"
				"[CLICK AND DRAG TO ORBIT AROUND]\n"
				"what do you see?\n\n"
				"[RIGHT ARROW KEY TO CONTINUE]"
			);
			break;
		}
		case 1:
		{
			shadow_scene.update();
			shadow_scene.lerp_cam_to({ -1, 600, 0 });
			shadow_scene.set_cam_look_dir({ 0, 0, 0 });
			shadow_scene.draw();

			draw_annotation(
				"NOW what do you see?"
				);
			break;
		}
		case 2:
		{
			shadow_scene.update();
			shadow_scene.lerp_cam_to({ -300, 500, 0 });
			shadow_scene.set_cam_look_dir({ 20, 0, 0 });
			shadow_scene.draw();

			draw_annotation(
				"The text you see is actually a shadow being cast by those seemingly random shapes, "
				"but this is a very delicate effect - changing anything even slightly can break it. "
				"I'll show you."
				);
			break;
		}
		case 3:
		{
			shadow_scene.update();
			shadow_scene.draw();

			draw_annotation(
				"Currently the light in this scene is being cast with orthographic projection; "
				"This means that the light is coming from a single direction, rather than a point in space - "
				"a bit like sunlight [2] as opposed to a lightbulb.\n\n"
				"so what happens if we CHANGE the direction the light is coming from?"
				);
			break;
		}
		case 4:
		{
			// moving the light source based on mouse input
			glm::vec3 base_pos = { -231, 139, -2 };
			int x_offset = ofMap(ofGetMouseY(), 0, ofGetHeight(), 800, -800);
			int z_offset = ofMap(ofGetMouseX(), 0, ofGetWidth(), -800, 800);
			shadow_scene.set_shadow_source_pos({
				base_pos.x + x_offset,	// forward and back
				base_pos.y,
				base_pos.z + z_offset	// left and right
			});

			shadow_scene.update();
			shadow_scene.lerp_cam_to({ -300, 500, 0 });
			shadow_scene.set_cam_look_dir({ 20, 0, 0 });
			shadow_scene.draw();

			draw_annotation(
				"[MOUSE TO CONTROL LIGHT DIRECTION]\n\n"
				"As you can see, changing the direction the light is coming from even slightly "
				"can start to distort the text until we no longer even recognize it as text, or anything for that matter. "
				"But why do we recognize the shadows as a distinct form at all? "
				"Why don't we just see them as the 'random' shapes they are? "
				);
			break;
		}
		case 5:
		{
			// moving the light source based on mouse input
			glm::vec3 base_pos = { -231, 139, -2 };
			int x_offset = ofMap(ofGetMouseY(), 0, ofGetHeight(), 800, -400);
			int z_offset = ofMap(ofGetMouseX(), 0, ofGetWidth(), -300, 300);
			shadow_scene.set_shadow_source_pos({
				base_pos.x + x_offset,	// forward and back
				base_pos.y,
				base_pos.z + z_offset	// left and right
				});

			shadow_scene.update();
			shadow_scene.draw();

			draw_annotation(
				"[SPACEBAR TO CHANGE SHAPE]\n\n"
				"The most intuitive explanation is that we know what text looks like "
				"and so when the shadows look similar to text, we recognize them as such; "
				"We could expect a similar effect to emerge with other familiar forms "
				"like faces, and primitive shapes, but this can't be the only explanation, "
				"because what if I told you it still works even with forms that are unfamiliar?"
				);
			break;
		}
		case 6:
		{
			// moving the light source based on mouse input
			glm::vec3 base_pos = { -231, 139, -2 };
			int x_offset = ofMap(ofGetMouseY(), 0, ofGetHeight(), 800, -400);
			int z_offset = ofMap(ofGetMouseX(), 0, ofGetWidth(), -300, 300);
			shadow_scene.set_shadow_source_pos({
				base_pos.x + x_offset,	// forward and back
				base_pos.y,
				base_pos.z + z_offset	// left and right
				});

			shadow_scene.update();
			shadow_scene.draw();

			draw_annotation(
				"Even now with these abstract rectangles, without knowing what they are or what they mean, we are "
				"able to identify larger shapes being formed by smaller ones when the light is "
				"cast from a specific direction. So context can't be the only reason we recognized the text before.\n\n"
				"To understand this phenomenon better we can look to the Gestalt Laws [1, 5], "
				"the Law of Pragnanz specifically."
				);
			break;
		}
		case 7:
		{
			law_of_pragnanz_simplified(ofGetWidth() / 2, ofGetHeight() / 2 - 100);

			draw_annotation(
				"The Gestalt Law of Pragnanz states that our brain will tend to perceive "
				"ambiguous shapes in as simple a manner as possible [1]. "
				"In this example, we will tend to perceive this image as a circle, rectangle "
				"and a triangle close together, despite there being no evidence to tell us that "
				"there is more than one shape here at all; All we are shown is a single polygon.\n\n"
				"[SPACEBAR TO SWITCH MODES]"
			);
			break;
		}
		case 8:
		{
			law_of_pragnanz(ofGetWidth() / 2, ofGetHeight() / 2 - 100);

			draw_annotation(
				"This same law applies with our 'hello' example. We see the word 'hello' amongst this cluster of shapes "
				"but pressing the [SPACEBAR] shows it for what it really is. "
				"Our brains choose to see the simpler solution here, the one that we can understand easily, "
				"so we see the word 'hello'.\n\n"
				"So now we know about the Law of Pragnanz, but this isn't the only Gestalt Law at play here.."
			);
			break;
		}
		case 9:
		{
			// Drawing a demonstration of the Gestalt Law of Proximity
			int deadzone = 30; // how close to the middle of the screen you need to be for the circles to be at their closest
			int gap_size = ofMap(
				abs(ofGetMouseX() - ofGetWidth()/2) - deadzone, // finding distance of cursor from center of the window, minus deadzone
				0, ofGetWidth()/2,
				0, 300,
				true
			);

			law_of_proximity_simplified(ofGetWidth()/2, ofGetHeight()/2 - 100, 6, 300, gap_size, 46);
			
			draw_annotation(
				"The Law of Proximity states that when individual elements are "
				"clustered into one area or group, people will tend to recognize them "
				"as a single entity [5].\n"
				"[MOVE MOUSE TO SEE IN ACTION]\n"
				"You should see a large 'block' of circles, but then they should appear to split into distinct rows, "
				"and merge back into one again. We naturally divide the circles into groups based on nothing but how close we see them to each other. "
				"This same law applies with our 'hello' example; We are shown lots of small shapes, but because they're clustered close together "
				"we recognize them as 5 large shapes instead of many small ones."
				);
			break;
		}
		case 10:
		{
			// moving the light source based on mouse input
			glm::vec3 base_pos = { -231, 139, -2 };
			int x_offset = ofMap(ofGetMouseY(), 0, ofGetHeight(), 800, -400);
			int z_offset = ofMap(ofGetMouseX(), 0, ofGetWidth(), -300, 300);
			shadow_scene.set_shadow_source_pos({
				base_pos.x + x_offset,	// forward and back
				base_pos.y,
				base_pos.z + z_offset	// left and right
				});

			shadow_scene.update();
			shadow_scene.draw();

			draw_annotation(
				"So we know the effect only works if the light is coming from a certain direction, "
				"but direction isn't the only factor here; "
				"The light also needs to be projected a certain way, it needs to be projected orthographically. "
				"\n But what does that mean?"
				);

			break;
		}
		case 11:
		{
			// moving the light source based on mouse input
			glm::vec3 base_pos = { -231, 139, -2 };
			int x_offset = ofMap(ofGetMouseY(), 0, ofGetHeight(), 800, -400);
			int z_offset = ofMap(ofGetMouseX(), 0, ofGetWidth(), -300, 300);
			shadow_scene.set_shadow_source_pos({
				base_pos.x + x_offset,	// forward and back
				base_pos.y,
				base_pos.z + z_offset	// left and right
				});

			shadow_scene.update();
			shadow_scene.draw();

			draw_annotation(
				"Well, in real life light must come from a source, "
				"a lightsource which occupies a point in space - like a lightbulb for example. The lightbulb is casting light out "
				"in every direction, all around it. In other words, the rays of light are all going off in different directions; they're not parallel. "
				"This leads to distortion in the shadows, like shadows becoming wider as distance from the lightsource increases. "
				"But for the 'hello' example the light is being projected orthographically, meaning all of the rays of light are parallel to each other [3]; "
				"The light is all coming from the same DIRECTION, rather than from the same POINT IN SPACE [2]. "
				"This means that the shadows are not distorted in the same way and so the 'hello' message can be seen clearly. "
				"Currently our light source is using orthographic projection, but what happens if we change it to perspective?\n\n"
				"[PRESS SPACEBAR TO SWITCH BETWEEN MODES]");
			break;
		}
		case 12:
		{
			// moving the light source based on mouse input
			glm::vec3 base_pos = { -231, 139, -2 };
			int x_offset = ofMap(ofGetMouseY(), 0, ofGetHeight(), 800, -400);
			int z_offset = ofMap(ofGetMouseX(), 0, ofGetWidth(), -300, 300);
			shadow_scene.set_shadow_source_pos({
				base_pos.x + x_offset,	// forward and back
				base_pos.y,
				base_pos.z + z_offset	// left and right
				});

			shadow_scene.update();
			shadow_scene.draw();

			draw_annotation(
				"That is all.\n\n"
				"Experiment with the shadows until you feel that you understand\n"
				"- [MOUSE TO CONTROL LIGHT DIRECTION]\n"
				"- [SPACEBAR TO TOGGLE BETWEEN SHAPES]\n"
				"- ['M' TO TOGGLE BETWEEN PROJECTION MODES]"
				);
			break;
		}
		case 13:
		{
			draw_annotation(
				"THE END"
				);

			break;
		}
	}
}

int Slideshow::get_slide_num()
{
	return current_slide_num;
}

void Slideshow::change_slide(int slide_num)
{
	current_slide_num = slide_num;
	cout << "changed to slide num " << current_slide_num << endl;
	switch (slide_num)
	{
		// the case for the slide that was just changed to will be run when first changed to that slide
		case 0:
			shadow_scene.disable_shadows();
			shadow_scene.set_cam_position({ -1, 600, 0 });
			shadow_scene.set_cam_look_dir({ 0, 0, 0 });
			shadow_scene.set_shadow_source_pos({ -231, 139, -2 });
			
			shadow_scene.draw_mesh_1();
			shadow_scene.disable_shadow_debug_ray();
			break;
		case 1:
			shadow_scene.enable_shadows();
			//shadow_scene.set_cam_position({ -1, 600, 0 });
			//shadow_scene.set_cam_look_dir({ 0, 0, 0 });
			break;
		case 2:
			//shadow_scene.set_cam_position({ -300, 500, 0 });
			shadow_scene.set_cam_look_dir({ 20, 0, 0 });
			shadow_scene.disable_shadow_debug_ray();
			break;
		case 3:
			shadow_scene.set_shadow_source_pos({ -231, 139, -2 });
			shadow_scene.enable_shadow_debug_ray();
			break;
		case 4:
			break;
		case 5:
			shadow_scene.draw_mesh_1();
			break;
		case 6:
			shadow_scene.draw_mesh_2();
			break;
		case 7:
			disable_outline();
			break;
		case 8:
			disable_outline();
			break;
		case 9:
			ofSetColor(255);
			break;
		case 10:
			shadow_scene.draw_mesh_1();
			shadow_scene.set_shadow_source_pos({ -231, 139, -2 });
			break;
		case 11:
			break;
		case 12:
			break;
		case 13:
			break;
	}
}
void Slideshow::next_slide()
{
	change_slide(get_slide_num() + 1);
}
void Slideshow::prev_slide()
{
	change_slide(get_slide_num() - 1);
}

void Slideshow::key_pressed(int key)
{
	switch (current_slide_num)
	{
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			if (key == 32)	// 32 == spacebar
			{
				shadow_scene.toggle_mesh_1_or_2();
			}
			break;
		case 6:
			break;
		case 7:
			if (key == 32)	// 32 == spacebar
			{
				toggle_drawing_mode();
			}
			break;
		case 8:
			if (key == 32)	// 32 == spacebar
			{
				toggle_drawing_mode();
			}
			break;
		case 9:
			break;
		case 10:
			if (key == 32) // 32 == spacebar
			{
				shadow_scene.toggle_perspective_mode();
			}
			break;
		case 11:
			if (key == 32) // 32 == spacebar
			{
				shadow_scene.toggle_perspective_mode();
			}
			break;
		case 12:
			if (key == 32) // 32 == spacebar
			{
				shadow_scene.toggle_mesh_1_or_2();
			}
			else if (key == int('m'))
			{
				shadow_scene.toggle_perspective_mode();
			}
			break;
		case 13:
			break;
	}
}


void Slideshow::draw_annotation(string text)
{
	string annotation = text;
	int max_line_length = 120; // how long the line can be before entering a new line character

	// automatic line break code adapted from user 'zea' on the openframeworks forums
	// https://forum.openframeworks.cc/t/text-box/5387/2
	for (int i = max_line_length; i < annotation.length(); i = i + max_line_length)
	{
		// finding the next ' ' in the string, starting from position i
		int p = annotation.find(' ', i);

		// replacing that space with a new line character '\n'
		if (p != string::npos) {
			annotation.replace(p, 1, "\n");
		}
	}

	ofPushStyle();

	// drawing semi-transparent background so the text more visible
	ofSetColor(0, 0, 0, 200);
	int padding = 37;	// how much taller the text background should be than the text itself
	ofPushMatrix();
	ofTranslate(0, ofGetHeight() - (annotation_font.stringHeight(annotation) + padding));
	ofDrawRectangle({ 0, 0 }, ofGetWidth(), annotation_font.stringHeight(annotation) + padding);
	ofPopMatrix();

	// translating so that the center of the text is always at the position passed in
	ofPushMatrix();
	ofTranslate(-annotation_font.stringWidth(annotation) / 2, -annotation_font.stringHeight(annotation));

	// drawing the text
	ofSetColor(250);
	annotation_font.drawString(
		annotation,
		ofGetWidth() / 2,
		ofGetHeight()
	);

	ofPopMatrix();
	ofPopStyle();
}