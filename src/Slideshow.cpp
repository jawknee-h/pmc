#include "Slideshow.h"

// constructor
Slideshow::Slideshow()
{
	cout << "slideshow constructed" << endl;

	annotation_font.load("fonts/theconf.ttf", 20);
}

//--------------------------------------------------------------
void Slideshow::setup() {
	shadow_scene.setup();
	// starting off on the first slide
	change_slide(0);
}

//--------------------------------------------------------------
void Slideshow::update(){
	
}

//--------------------------------------------------------------
void Slideshow::draw(){
	switch (current_slide_num)
	{
		case 0:
		{
			shadow_scene.update();
			shadow_scene.draw();

			ofSetColor(20);
			annotation_font.drawString(
				"click and drag to orbit around.\n"
				"what do you see?\n\n"
				"(press the right arrow key to continue)", 50, 50);
			break;
		}
		case 1:
		{
			shadow_scene.update();
			shadow_scene.draw();

			annotation_font.drawString(
				"NOW what do you see?"
				, 50, 200);
			break;
		}
		case 2:
		{
			shadow_scene.update();
			shadow_scene.draw();

			annotation_font.drawString(
				"The text you see is actually a shadow being cast by those seemingly random shapes,\n"
				"but this is a very delicate effect - changing anything even slightly can break it.\n"
				"I'll show you."
				, 50, ofGetHeight() - 300);
			break;
		}
		case 3:
		{
			shadow_scene.update();
			shadow_scene.draw();

			annotation_font.drawString(
				"Currently the light in this scene is being cast with orthographic projection.\n"
				"This means that the light is coming from a single direction, rather than a point in space -\n"
				"A bit like sunlight as opposed to a lightbulb\n\n"
				"so what happens if we CHANGE the direction the light is coming from?"
				, 50, ofGetHeight() - 300);
			break;
		}
		case 4:
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

			annotation_font.drawString(
				"(Move your mouse to change the direction the light is coming from)\n\n"
				"As you can see, changing the direction the light is coming from even slightly\n"
				"can start to distort the text until we no longer even recognize it as text, or anything for that matter.\n\n"
				"But why do we recognize the shadows as a distinct form at all?\n"
				"Why don't we just see them as the 'random' shapes they are?"
				, 50, ofGetHeight() - 300);
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

			annotation_font.drawString(
				"The most intuitive explanation is that we know what text looks like\n"
				"and so when the shadows look similar to text, we recognize it.\n"
				"We could expect a similar effect to emerge with other familiar forms\n"
				"like faces, and primitive shapes. But this can't be the only explanation,\n"
				"because what if I told you it still works even with forms that are unfamiliar.\n\n"
				"(press spacebar to change shape)"
				, 50, ofGetHeight() - 300);
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

			annotation_font.drawString(
				"even now, without the context of text or any other familiar forms, we are still\n"
				"able to identify larger shapes being formed by smaller ones when the light is being\n"
				"cast from a specific direction.\n\n"
				"We can understand this phenomenon better by looking to the Gestalt Laws,\n"
				"the Law of Proximity specifically."
				, 50, ofGetHeight() - 300);
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
			shadow_scene.set_cam_position({ -1, 600, 0 });
			shadow_scene.set_cam_look_dir({ 0, 0, 0 });
			break;
		case 2:
			shadow_scene.set_cam_position({ -300, 500, 0 });
			shadow_scene.set_cam_look_dir({ 20, 0, 0 });
			shadow_scene.disable_shadow_debug_ray();
			break;
		case 3:
			shadow_scene.set_shadow_source_pos({ -231, 139, -2 });
			shadow_scene.enable_shadow_debug_ray();
			break;
		case 4:
			//shadow_scene.set_cam_position({-300, 500, 0});
			//shadow_scene.orbit_light();
			break;
		case 5:
			shadow_scene.draw_mesh_1();
			break;
		case 6:
			shadow_scene.draw_mesh_2();
			break;
		case 7:
			//gestalt_proximity();
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
	cout << key << " from slideshow keypressed" << endl;
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
			break;
	}
}