#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "ofxShadow.h"

class ShadowScene
{

	public:
		void setup();
		void update();
		void draw();
		void render_scene();
		void draw_shadow_scene();
		void disable_shadows();
		void enable_shadows();
		void set_cam_position(glm::vec3 new_pos);
		void set_cam_look_dir(glm::vec3 new_dir);
		void enable_shadow_debug_ray();
		void disable_shadow_debug_ray();
		void toggle_shadow_debug_ray();
		void set_shadow_source_pos(glm::vec3 pos);
		glm::vec3 get_shadow_source_pos();
		void draw_mesh_1();
		void draw_mesh_2();
		void toggle_mesh_1_or_2();

		ofxShadow text_shadow;	// a shadow
		ShadowScene();

	private:
		
		ofCamera cam;	// camera so we can control perspective easily.
		//ofEasyCam cam;

		struct {
			ofVec3f pos;
			ofVec3f look_at;
		} cam_target, cam_current;

		bool shadow_ray_enabled;

		ofxAssimpModelLoader model_1;	// the model
		ofMesh mesh_1;	// a mesh which will represent the model
		ofxAssimpModelLoader model_2; // the model
		ofMesh mesh_2;	// a mesh which will represent the model

		// whether to draw mesh 1 or 2
		bool draw_mesh_1_or_2;
		
		ofBoxPrimitive ground_plane;	// the ground mesh
		ofSpherePrimitive shadow_debug_sphere;	// debug sphere mesh

		ofVec3f shadow_look_at;	// the position the shadow will be cast to
		ofVec3f shadow_pos;	// the position the shadow will be cast from
};
