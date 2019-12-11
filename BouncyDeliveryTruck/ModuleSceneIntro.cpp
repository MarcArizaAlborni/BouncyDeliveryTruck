#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{



	LOG("Loading Intro assets");
	bool ret = true;
	plane = true;
	count = 0.0f;

	App->camera->Move(vec3(1.0f, 100.0f, 60.0f));
	App->camera->LookAt(vec3(0, 0, 60));


	//INITIAL PACKAGES

	//PACK1
	Pack1.radius={ 0.5f };
	Pack1.SetPos(0, 5, 11);
	BallPack1=App->physics->AddBody(Pack1, 50);

	Pack2.radius = { 0.5f };
	Pack2.SetPos(0, 5, 9);
	BallPack2 = App->physics->AddBody(Pack2, 50);

	Pack3.size = { 1,1,1};
	Pack3.SetPos(0, 5, 10);
	CubePack1=App->physics->AddBody(Pack3, 100);
	
	//WALL1
	Cube wall1(2, 3, 70);
	wall1.SetPos(10, 1, 15);
	App->physics->AddBody(wall1, 100000);
	wall1.wire = true;
	wall1.color.Set(1.0f, 1.0f, 1.0f);
	wall1.axis = true;

	//WALL2
	Cube wall2(2, 3, 100);
	wall2.SetPos(-10, 1, 60);
	App->physics->AddBody(wall2, 100000);
	wall2.wire = true;
	wall2.color.Set(1.0f, 1.0f, 1.0f);
	wall2.axis = true;
	
	//WALL3
	Cube wall3(50, 3, 2);
	wall3.SetPos(35, 1, 50);
	App->physics->AddBody(wall3, 100000);
	wall3.wire = true;
	wall3.color.Set(1.0f, 1.0f, 1.0f);
	wall3.axis = true;

	//WALL4
	Cube wall4(50, 3, 2);
	wall4.SetPos(15, 1, 70);
	App->physics->AddBody(wall4, 100000);
	wall4.wire = true;
	wall4.color.Set(1.0f, 1.0f, 1.0f);
	wall4.axis = true;

	//WALL5
	Cube wall5(2, 3, 90);
	wall5.SetPos(60, 1, 95);
	App->physics->AddBody(wall5, 100000);
	wall5.wire = true;
	wall5.color.Set(1.0f, 1.0f, 1.0f);
	wall5.axis = true;

	//WALL6
	Cube wall6(50, 3, 2);
	wall6.SetPos(35, 1, 90);
	App->physics->AddBody(wall6, 100000);
	wall6.wire = true;
	wall6.color.Set(1.0f, 1.0f, 1.0f);
	wall6.axis = true;

	//WALL7
	Cube wall7(50, 3, 2);
	wall7.SetPos(15, 1, 110);
	App->physics->AddBody(wall7, 100000);
	wall7.wire = true;
	wall7.color.Set(1.0f, 1.0f, 1.0f);
	wall7.axis = true;

	//WALL8
	Cube wall8(100, 3, 2);
	wall8.SetPos(10, 1, 138);
	App->physics->AddBody(wall8, 100000);
	wall8.wire = true;
	wall8.color.Set(1.0f, 1.0f, 1.0f);
	wall8.axis = true;

	//WALL9
	Cube wall9(2, 3, 100);
	wall9.SetPos(-40, 1, 85);
	App->physics->AddBody(wall9, 100000);
	wall9.wire = true;
	wall9.color.Set(1.0f, 1.0f, 1.0f);
	wall9.axis = true;

	//WALL10
	Cube wall10(60, 3, 2);
	wall10.SetPos(-40, 1, 10);
	App->physics->AddBody(wall10, 100000);
	wall10.wire = true;
	wall10.color.Set(1.0f, 1.0f, 1.0f);
	wall10.axis = true;

	//WALL11
	Cube wall11(2, 3, 100);
	wall11.SetPos(-70, 1, 60);
	App->physics->AddBody(wall11, 100000);
	wall11.wire = true;
	wall11.color.Set(1.0f, 1.0f, 1.0f);
	wall11.axis = true;

	//WALL12
	Cube wall12(65, 3, 2);
	wall12.SetPos(-72, 1, 138);
	App->physics->AddBody(wall12, 100000);
	wall12.wire = true;
	wall12.color.Set(1.0f, 1.0f, 1.0f);
	wall12.axis = true;

	//WALL13
	Cube wall13(65, 3, 2);
	wall13.SetPos(-105, 1, 110);
	App->physics->AddBody(wall13, 100000);
	wall13.wire = true;
	wall13.color.Set(1.0f, 1.0f, 1.0f);
	wall13.axis = true;

	//WALL14
	Cube wall14(2, 3, 100);
	wall14.SetPos(-140, 1, 160);
	App->physics->AddBody(wall14, 100000);
	wall14.wire = true;
	wall14.color.Set(1.0f, 1.0f, 1.0f);
	wall14.axis = true;

	//WALL15
	Cube wall15(70, 3, 2);
	wall15.SetPos(-105, 1, 210);
	App->physics->AddBody(wall15, 100000);
	wall15.wire = true;
	wall15.color.Set(1.0f, 1.0f, 1.0f);
	wall15.axis = true;

	//WALL16
	Cube wall16(2, 3, 40);
	wall16.SetPos(-105, 1, 160);
	App->physics->AddBody(wall16, 100000);
	wall16.wire = true;
	wall16.color.Set(1.0f, 1.0f, 1.0f);
	wall16.axis = true;

	//WALL17
	Cube wall17(2, 3, 70);
	wall17.SetPos(-70, 1, 175);
	App->physics->AddBody(wall17, 100000);
	wall17.wire = true;
	wall17.color.Set(1.0f, 1.0f, 1.0f);
	wall17.axis = true;

	//RAMP1
	Cube Ramp1(35, 2, 50);
	Ramp1.SetPos(-87, 2, 145);
	Ramp1.SetRotation(20, vec3(1, 0, 0));
	App->physics->AddBody(Ramp1, 0);

	//RAMP2
	Cube Ramp2(35, 2, 45);
	Ramp2.SetPos(-87, 2, 100);
	Ramp2.SetRotation(20, vec3(-1, 0, 0));
	App->physics->AddBody(Ramp2, 0);

	//WALL 18
	Cube wall18(2, 3, 130);
	wall18.SetPos(-105, 1, 45);
	App->physics->AddBody(wall18, 100000);
	wall18.wire = true;
	wall18.color.Set(1.0f, 1.0f, 1.0f);
	wall18.axis = true;

	//WALL19
	Cube wall19(115, 3, 2);
	wall19.SetPos(-48, 1, -20);
	App->physics->AddBody(wall19, 100000);
	wall19.wire = true;
	wall19.color.Set(1.0f, 1.0f, 1.0f);
	wall19.axis = true;

	//WALL20
	Cube wall20(3, 3, 28);
	wall20.SetPos(-10, 1, -5);
	App->physics->AddBody(wall20, 100000);
	wall20.color.Set(1.0f, 1.0f, 1.0f);

	//OBSTACLES PART 1

	//FILA CYLINDRES 1
	//CylBache5
	Cylinder CylBache5(0.5, 5);
	CylBache5.SetPos(25, -0.25, 124);
	CylBache5.SetRotation(90, vec3(0, 0, 1));
	App->physics->AddBody(CylBache5, 0);

	//CylBache7
	Cylinder CylBache7(0.5, 5);
	CylBache7.SetPos(25, -0.25, 131);
	CylBache7.SetRotation(90, vec3(0, 0, 1));
	App->physics->AddBody(CylBache7, 0);

	//CylBache8
	Cylinder CylBache8(0.5, 5);
	CylBache8.SetPos(25, -0.25, 117);
	CylBache8.SetRotation(90, vec3(0, 0, 1));
	App->physics->AddBody(CylBache8, 0);

	//FILA BACHES 1
	//BACHE1
	Cylinder CylBache9(0.5, 10);
	CylBache9.SetRotation(90, vec3(0, 1, 0));
	CylBache9.SetPos(12.5, -0.25, 116);
	App->physics->AddBody(CylBache9, 100000);
	
	//BACHE2
	Cylinder CylBache10(0.5, 10);
	CylBache10.SetRotation(90, vec3(0, 1, 0));
	CylBache10.SetPos(12.5, -0.25, 132);
	App->physics->AddBody(CylBache10, 100000);

	//FILA CYLINDRES 2
	//CylBache1
	Cylinder CylBache1(0.5, 5);
	CylBache1.SetPos(0, -0.25, 121);
	CylBache1.SetRotation(90, vec3(0, 0, 1));
	App->physics->AddBody(CylBache1, 0);
	
	//CylBache4
	Cylinder CylBache4(0.5, 5);
	CylBache4.SetPos(0, -0.25, 133);
	CylBache4.SetRotation(90, vec3(0, 0, 1));
	App->physics->AddBody(CylBache4, 0);

	//CylBache3
	Cylinder CylBache3(0.5, 5);
	CylBache3.SetPos(0, -0.25, 127);
	CylBache3.SetRotation(90, vec3(0, 0, 1));
	App->physics->AddBody(CylBache3, 0);

	//CylBache2
	Cylinder CylBache2(0.5, 5);
	CylBache2.SetPos(0, -0.25, 115);
	CylBache2.SetRotation(90, vec3(0, 0, 1));
	App->physics->AddBody(CylBache2, 0);

	//OBSTACLES PART 2

	//OBJECTE 1
	
	CubRot1.SetPos(-25.5, 7.5, 90);
	CubRot1.size = { 6,7.5,6 };
	CubRotB1 = App->physics->AddBody(CubRot1, 1000000);
    CubRot2.SetPos(8, 10, 75);
    CubRot2.size = { 4, 5, 1 };
	CubRotB2 = App->physics->AddBody(CubRot2, 100);

	btHingeConstraint* Hinge1 = App->physics->AddConstraintHinge(*CubRotB1, *CubRotB2, vec3{ 0,0,0 }, vec3{ 10, 0,0 }, vec3{ 0,1,0 }, vec3{ 0,1,0 }, true);
	Hinge1->setLimit(1, 0);
	
	//OBJECTE 2

	CubRot3.SetPos(-25.5, 7.5, 60);
	CubRot3.size = { 6,7.5,6 };
	CubRotB3 = App->physics->AddBody(CubRot3, 1000000);
	CubRot4.SetPos(8, 10, 45);
	CubRot4.size = { 4, 5, 1 };
	CubRotB4 = App->physics->AddBody(CubRot4, 100);

	btHingeConstraint* Hinge2 = App->physics->AddConstraintHinge(*CubRotB3, *CubRotB4, vec3{ 0,0,0 }, vec3{ 10, 0,0 }, vec3{ 0,-1,0 }, vec3{ 0,1,0 }, true);
	Hinge2->setLimit(1, 0);

	//OBSTACLES PART 3


	//-----------------------------------------------------------------------------------------------------------------------------------------//
	//DETECT COLLIDERS

	//FINISH LINE
	DetectorCube[0].SetPos(-15, 2,-5);
	DetectorCube[0].size=vec3{ 5, 1, 25 };

	//DETECT PACK1
	DetectorCube[1].SetPos(-20, 2, -5);
	DetectorCube[1].size = vec3{ 5, 1, 25 };
	//DETECT PACK2
	DetectorCube[2].SetPos(-20, 2, -5);
	DetectorCube[2].size = vec3{ 5, 1, 25 };
	//DETECT PACK3
	DetectorCube[3].SetPos(-20, 2, -5);
	DetectorCube[3].size = vec3{ 5, 1, 25 };

	for (int i = 0; i < 4; i++)
	{
		Detector[i] = App->physics->AddBody(DetectorCube[i], 0.0f);
		Detector[i]->SensorDetector(true);
		Detector[i]->collision_listeners.add(this);
		
	}

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	//DRAW SPHERES COLOUR

	BallPack1->GetTransform(&Pack1.transform);
	Pack1.Render();

	BallPack2->GetTransform(&Pack2.transform);
	Pack2.Render();

	CubePack1->GetTransform(&Pack3.transform);
	Pack3.Render();


	
	
	//PINTA Y COLOREA CON PEPA PIG

	//ROTATORIS 1
	//ROTATORI1
	CubRotB1->GetTransform(&CubRot1.transform);
	CubRot1.color = LightBlue;
	CubRot1.Render();
	CubRotB2->GetTransform(&CubRot2.transform);
	CubRot2.color = Pink;
	CubRot2.Render();
	//ROTATORI2
	CubRotB3->GetTransform(&CubRot3.transform);
	CubRot3.color = LightBlue;
	CubRot3.Render();
	CubRotB4->GetTransform(&CubRot4.transform);
	CubRot4.color = Pink;
	CubRot4.Render();
	//FILA CYLINDRES 1
	//CylBache5
	Cylinder CylBache5(0.5, 5);
	CylBache5.SetPos(25, -0.25, 124);
	CylBache5.SetRotation(90, vec3(0, 0, 1));
	CylBache5.color = Yellow;
	CylBache5.Render();



	//CylBache7
	Cylinder CylBache7(0.25, 5);
	CylBache7.SetPos(25, -0.25, 131);
	CylBache7.SetRotation(90, vec3(0, 0, 1));
	CylBache7.color = Yellow;
	CylBache7.Render();

	//CylBache8
	Cylinder CylBache8(0.25, 5);
	CylBache8.SetPos(25, -0.25, 117);
	CylBache8.SetRotation(90, vec3(0, 0, 1));
	CylBache8.color = Yellow;
	CylBache8.Render();

	//FILA BACHES 1

	//BACHE1
	Cylinder CylBache9(1, 10);
	CylBache9.SetRotation(90, vec3(0, 1, 0));
	CylBache9.SetPos(12.5, -0.25, 116);

	CylBache9.color = Yellow;
	CylBache9.Render();

	//BACHE2
	Cylinder CylBache10(1, 10);
	CylBache10.SetRotation(90, vec3(0, 1, 0));
	CylBache10.SetPos(12.5, -0.25, 132);

	CylBache10.color = Yellow;
	CylBache10.Render();




	//FILA CYLINDRES 2
	//CylBache1
	Cylinder CylBache1(0.5, 5);
	CylBache1.SetPos(0, -0.25, 121);
	CylBache1.SetRotation(90, vec3(0, 0, 1));
	CylBache1.color = Yellow;
	CylBache1.Render();

	//CylBache4
	Cylinder CylBache4(0.5, 5);
	CylBache4.SetPos(0, -0.25, 133);
	CylBache4.SetRotation(90, vec3(0, 0, 1));
	CylBache4.color = Yellow;
	CylBache4.Render();

	//CylBache3
	Cylinder CylBache3(0.5, 5);
	CylBache3.SetPos(0, -0.25, 127);
	CylBache3.SetRotation(90, vec3(0, 0, 1));
	CylBache3.color = Yellow;
	CylBache3.Render();

	//CylBache2
	Cylinder CylBache2(0.5, 5);
	CylBache2.SetPos(0, -0.25, 115);
	CylBache2.SetRotation(90, vec3(0, 0, 1));
	CylBache2.color = Yellow;
	CylBache2.Render();




	//PINTA Y COLOREA CON DORA LA EXPLORADORA

	//WALL1
	Cube wall1(2, 3, 70);
	wall1.SetPos(10, 1, 15);
	wall1.color = Green;
	wall1.Render();

	//WALL2
	Cube wall2(2, 3, 100);
	wall2.SetPos(-11, 1, 60);
	wall2.color = Green;
	wall2.Render();
	
	//WALL3
	Cube wall3(50, 3, 2);
	wall3.SetPos(35, 1, 50);
	wall3.color = Green;
	wall3.Render();

	//WALL4
	Cube wall4(50, 3, 2);
	wall4.SetPos(15, 1, 70);
	wall4.color = Green;
	wall4.Render();

	//WALL5
	Cube wall5(2, 3, 90);
	wall5.SetPos(61, 1, 95);
	wall5.color = Green;
	wall5.Render();

	//WALL6
	Cube wall6(50, 3, 2);
	wall6.SetPos(35, 1, 90);
	wall6.color = Green;
	wall6.Render();

	//WALL7
	Cube wall7(50, 3, 2);
	wall7.SetPos(15, 1, 110);
	wall7.color = Green;
	wall7.Render();

	//WALL8
	Cube wall8(100, 3, 2);
	wall8.SetPos(10, 1, 138);
	wall8.color = Green;
	wall8.Render();

	//WALL9
	Cube wall9(2, 3, 100);
	wall9.SetPos(-40, 1, 85);
	wall9.color = Green;
	wall9.Render();

	//WALL10
	Cube wall10(60, 3, 2);
	wall10.SetPos(-40, 1, 10);
	wall10.color = Green;
	wall10.Render();

	//WALL11
	Cube wall11(2, 3, 100);
	wall11.SetPos(-69, 1, 60);
	wall11.color = Green;
	wall11.Render();

	//WALL12
	Cube wall12(65, 3, 2);
	wall12.SetPos(-72, 1, 138);
	wall12.color = Green;
	wall12.Render();

	//WALL13
	Cube wall13(65, 3, 2);
	wall13.SetPos(-105, 1, 111);
	wall13.color = Green;
	wall13.Render();

	//WALL14
	Cube wall14(2, 3, 100);
	wall14.SetPos(-140.5, 1, 160);
	wall14.color = Green;
	wall14.Render();

	//WALL15
	Cube wall15(70, 3, 2);
	wall15.SetPos(-105, 1, 210);
	wall15.color = Green;
	wall15.Render();

	//WALL16
	Cube wall16(2, 3, 40);
	wall16.SetPos(-105, 1, 160);
	wall16.color = Green;
	wall16.Render();

	//WALL17
	Cube wall17(2, 3, 70);
	wall17.SetPos(-68.5, 1, 175);
	wall17.color = Green;
	wall17.Render();

	//RAMP1
	Cube Ramp1(35, 2, 50);
	Ramp1.SetPos(-87, 2, 145);
	Ramp1.SetRotation(20, vec3(1, 0, 0));
	Ramp1.color = Green;
	Ramp1.Render();


	//RAMP2
	Cube Ramp2(35, 2, 45);
	Ramp2.SetPos(-87, 2, 100);
	Ramp2.SetRotation(20, vec3(-1, 0, 0));
	Ramp2.color = Green;
	Ramp2.Render();	

	//WALL 18
	Cube wall18(2, 3, 130);
	wall18.SetPos(-105.5, 1, 45);
	wall18.color = Green;
	wall18.Render();

	//WALL19
	Cube wall19(115, 3, 2);
	wall19.SetPos(-48, 1, -20);
	wall19.color = Green;
	wall19.Render();

	//WALL20
	Cube wall20(3, 3, 28);
	wall20.SetPos(-10, 1, -5);
	wall20.color = Green;
	wall20.Render();

	//TERRA
	Plane FloorPlane(0, 1, 0, 0);
	FloorPlane.axis = false;
	FloorPlane.wire = false;
	FloorPlane.color = Grey;
	FloorPlane.Render();


	

	Cube FloorDrawn(300, 1, 300);
	FloorDrawn.SetPos(-50, -1, 70);
	
	FloorDrawn.Render();
	

	
	//OBSTACLES

	

	




	




	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{

	
	if (body1 == Detector[1]) {

		if (body2 == BallPack1) {

			GotPack1 = true;
			LOG("PACK 1 DELIVERED");
		}
	}

	if (body1 == Detector[2]) {

		if (body2 == BallPack2) {

			GotPack2 = true;
			LOG("PACK 2 DELIVERED");
		}
	}

	if (body1 == Detector[3]) {

		if (body2 == CubePack1) {

			LOG("PACK 3 DELIVERED")
			GotPack3 = true;
		}
	}

	if (body1 == Detector[0]) {

		if (GotPack1 == true && GotPack2 && true && GotPack3 == true) {

			//win
			LOG("WIN");
		}
		
	}



}

