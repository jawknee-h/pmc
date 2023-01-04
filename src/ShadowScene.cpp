#include "ShadowScene.h"

ShadowScene::ShadowScene()
{
	cout << "constructed ShadowScene()" << endl;
}

void ShadowScene::setup()
{
	// setting up the shadow
	text_shadow.setup();
	text_shadow.setPerspective(false);
	text_shadow.setSoftShadow(true);
	text_shadow.setBlurSize(5);
	text_shadow.setSigma(5);
	text_shadow.setShadowFactor(20);
	shadow_look_at = { 189, 0, 0 };

	// disabling the shadow debug ray by default
	shadow_ray_enabled = false;

	// drawing mesh 1 by default
	draw_mesh_1_or_2 = false;

	// setting up the meshes
	model_1.loadModel("models/hello.obj");
	mesh_1 = model_1.getMesh(0);
	model_2.loadModel("models/shape_shadow.obj");
	mesh_2 = model_2.getMesh(0);

	// setting up the ground plane
	ground_plane.setWidth(3000);
	ground_plane.setHeight(1);
	ground_plane.setDepth(3000);

	// setting up the debug sphere for the light source
	shadow_debug_sphere.set(8, 12);
}

void ShadowScene::update()
{
	text_shadow.lookAt(shadow_look_at);

	shadow_pos = text_shadow.getPosition();
	shadow_debug_sphere.setPosition(shadow_pos);
}

void ShadowScene::draw()
{
	glEnable(GL_DEPTH_TEST);
	text_shadow.beginDepth();
	render_scene();
	text_shadow.endDepth();

	text_shadow.begin(cam);
	render_scene();
	text_shadow.end(cam);
	glDisable(GL_DEPTH_TEST);
}

void ShadowScene::render_scene()
{
	if (draw_mesh_1_or_2 == true)
	{
		mesh_1.draw();
	}
	else
	{
		mesh_2.draw();
	}

	if (shadow_ray_enabled)
	{
		ofDrawLine(
			shadow_look_at.x,
			shadow_look_at.y,
			shadow_look_at.z,
			shadow_pos.x,
			shadow_pos.y,
			shadow_pos.z
		);

		shadow_debug_sphere.draw();
	}
	
	ground_plane.draw();
}

void ShadowScene::draw_shadow_scene()
{

}

void ShadowScene::disable_shadows()
{
	text_shadow.setResolution(2);
}

void ShadowScene::enable_shadows()
{
	text_shadow.setResolution(1920);
}

void ShadowScene::set_cam_position(glm::vec3 new_pos)
{
	cam.setPosition(new_pos);
}

void ShadowScene::set_cam_look_dir(glm::vec3 new_dir)
{
	
	cam.lookAt(new_dir);
	//cam.setTarget(new_dir);
}

void ShadowScene::enable_shadow_debug_ray()
{
	shadow_ray_enabled = true;
}

void ShadowScene::disable_shadow_debug_ray()
{
	shadow_ray_enabled = false;
}

void ShadowScene::toggle_shadow_debug_ray()
{
	shadow_ray_enabled = !shadow_ray_enabled;
}

void ShadowScene::set_shadow_source_pos(glm::vec3 pos)
{
	text_shadow.setPosition(pos);
}

glm::vec3 ShadowScene::get_shadow_source_pos()
{
	return text_shadow.getPosition();
}

void ShadowScene::draw_mesh_1()
{
	draw_mesh_1_or_2 = true;
}

void ShadowScene::draw_mesh_2()
{
	draw_mesh_1_or_2 = false;
}

void ShadowScene::toggle_mesh_1_or_2()
{
	draw_mesh_1_or_2 = !draw_mesh_1_or_2;
}

void ShadowScene::toggle_perspective_mode()
{
	if (text_shadow.isPerspective())
	{
		text_shadow.setPerspective(false);
	}
	else
	{
		text_shadow.setPerspective(true);
	}
}