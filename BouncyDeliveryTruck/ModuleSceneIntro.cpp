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
	//PACK2
	Pack2.radius = { 0.5f };
	Pack2.SetPos(0, 5, 9);
	BallPack2 = App->physics->AddBody(Pack2, 50);
	//PACK3
	Pack3.size = { 1,1,1};
	Pack3.SetPos(0, 5, 10);
	CubePack1=App->physics->AddBody(Pack3, 100);
	

	//LEVEL

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
	/*Cube wall19(115, 3, 2);
	wall19.SetPos(-48, 1, -20);
	App->physics->AddBody(wall19, 100000);
	wall19.wire = true;
	wall19.color.Set(1.0f, 1.0f, 1.0f);
	wall19.axis = true;*/

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
	Cylinder CylBache9(0.5, 25);
	CylBache9.SetRotation(90, vec3(0, 1, 0));
	CylBache9.SetPos(12.5, -0.25, 124);
	App->physics->AddBody(CylBache9, 100000);
	
	

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
	//PIS1 FILA 1 MT1
	CubMt1.size = { 2,2,2 };
	CubMt1.SetPos(-50, 0, 50);
	CubMtB1 = App->physics->AddBody(CubMt1, 100);

	CubMt2.size = { 2,2,2 };
	CubMt2.SetPos(-53, 0, 50);
	CubMtB2 = App->physics->AddBody(CubMt2, 100);

	CubMt3.size = { 2,2,2 };
	CubMt3.SetPos(-56, 0, 50);
	CubMtB3 = App->physics->AddBody(CubMt3, 100);

	CubMt4.size = { 2,2,2 };
	CubMt4.SetPos(-59, 0, 50);
	CubMtB4 = App->physics->AddBody(CubMt4, 100);
	//PIS 1 FILA 2 MT1
	CubMt5.size = { 2,2,2 };
	CubMt5.SetPos(-50, 0, 53);
	CubMtB5 = App->physics->AddBody(CubMt5, 100);

	CubMt6.size = { 2,2,2 };
	CubMt6.SetPos(-53, 0, 53);
	CubMtB6 = App->physics->AddBody(CubMt6, 100);

	CubMt7.size = { 2,2,2 };
	CubMt7.SetPos(-56, 0, 53);
	CubMtB7 = App->physics->AddBody(CubMt7, 100);

	CubMt8.size = { 2,2,2 };
	CubMt8.SetPos(-59, 0, 53);
	CubMtB8 = App->physics->AddBody(CubMt8, 100);
	//PIS 2 FILA 2 MT1
	CubMt9.size = { 2,2,2 };
	CubMt9.SetPos(-51.5, 2, 53);
	CubMtB9 = App->physics->AddBody(CubMt9, 100);

	CubMt10.size = { 2,2,2 };
	CubMt10.SetPos(-54.5, 2, 53);
	CubMtB10 = App->physics->AddBody(CubMt10, 100);

	CubMt11.size = { 2,2,2 };
	CubMt11.SetPos(-57.5, 2, 53);
	CubMtB11 = App->physics->AddBody(CubMt11, 100);
	//PIS 2 FILA 1 MT1
	CubMt12.size = { 2,2,2 };
	CubMt12.SetPos(-51.5, 2, 50);
	CubMtB12 = App->physics->AddBody(CubMt12, 100);

	CubMt13.size = { 2,2,2 };
	CubMt13.SetPos(-54.5, 2, 50);
	CubMtB13 = App->physics->AddBody(CubMt13, 100);

	CubMt14.size = { 2,2,2 };
	CubMt14.SetPos(-57.5, 2, 50);
	CubMtB14 = App->physics->AddBody(CubMt14, 100);
	//PIS 3 FILA MIG MT1
	CubMt15.size = { 2,2,2 };
	CubMt15.SetPos(-53, 4, 51.5);
	CubMtB15 = App->physics->AddBody(CubMt15, 100);

	CubMt16.size = { 2,2,2 };
	CubMt16.SetPos(-56, 4, 51.5);
	CubMtB16 = App->physics->AddBody(CubMt16, 100);

	//PIS 4 FILA MIG MT1
	CubMt17.size = { 2,2,2 };
	CubMt17.SetPos(-54.5, 6, 51.5);
	CubMtB17 = App->physics->AddBody(CubMt17, 100);
	//MT2-----------------------------------------------------------------------------------------------------------------------------------------------------
	//MTTTTTTTTTTTT2
	//PIS1 FILA 1 MT2
	CubMt20.size = { 2,2,2 };
	CubMt20.SetPos(-50, 0, 90);
	CubMtB20 = App->physics->AddBody(CubMt20, 100);

	CubMt21.size = { 2,2,2 };
	CubMt21.SetPos(-53, 0, 90);
	CubMtB21 = App->physics->AddBody(CubMt21, 100);

	CubMt22.size = { 2,2,2 };
	CubMt22.SetPos(-56, 0, 90);
	CubMtB22 = App->physics->AddBody(CubMt22, 100);

	CubMt23.size = { 2,2,2 };
	CubMt23.SetPos(-59, 0, 90);
	CubMtB23 = App->physics->AddBody(CubMt23, 100);
	//PIS 1 FILA 2 MT2
	CubMt24.size = { 2,2,2 };
	CubMt24.SetPos(-50, 0, 93);
	CubMtB24 = App->physics->AddBody(CubMt24, 100);

	CubMt25.size = { 2,2,2 };
	CubMt25.SetPos(-53, 0, 93);
	CubMtB25 = App->physics->AddBody(CubMt25, 100);

	CubMt26.size = { 2,2,2 };
	CubMt26.SetPos(-56, 0, 93);
	CubMtB26 = App->physics->AddBody(CubMt26, 100);

	CubMt27.size = { 2,2,2 };
	CubMt27.SetPos(-59, 0, 93);
	CubMtB27 = App->physics->AddBody(CubMt27, 100);
	//PIS 2 FILA 2 MT2
	CubMt28.size = { 2,2,2 };
	CubMt28.SetPos(-51.5, 2, 93);
	CubMtB28 = App->physics->AddBody(CubMt28, 100);

	CubMt29.size = { 2,2,2 };
	CubMt29.SetPos(-54.5, 2, 93);
	CubMtB29 = App->physics->AddBody(CubMt29, 100);

	CubMt30.size = { 2,2,2 };
	CubMt30.SetPos(-57.5, 2, 93);
	CubMtB30 = App->physics->AddBody(CubMt30, 100);
	//PIS 2 FILA 1 MT2
	CubMt31.size = { 2,2,2 };
	CubMt31.SetPos(-51.5, 2, 90);
	CubMtB31 = App->physics->AddBody(CubMt31, 100);

	CubMt32.size = { 2,2,2 };
	CubMt32.SetPos(-54.5, 2, 90);
	CubMtB32 = App->physics->AddBody(CubMt32, 100);

	CubMt33.size = { 2,2,2 };
	CubMt33.SetPos(-57.5, 2, 90);
	CubMtB33 = App->physics->AddBody(CubMt33, 100);
	//PIS 3 FILA MIG MT2
	CubMt34.size = { 2,2,2 };
	CubMt34.SetPos(-53, 4, 91.5);
	CubMtB34 = App->physics->AddBody(CubMt34, 100);

	CubMt35.size = { 2,2,2 };
	CubMt35.SetPos(-56, 4, 91.5);
	CubMtB35 = App->physics->AddBody(CubMt35, 100);

	//PIS 4 FILA MIG MT2
	CubMt36.size = { 2,2,2 };
	CubMt36.SetPos(-54.5, 6,91.5);
	CubMtB36 = App->physics->AddBody(CubMt36, 100);



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

	//CHECKPOINT1
	DetectorCube[4].SetPos(-54.5, 2, 110);
	DetectorCube[4].size = vec3{ 25, 1, 5 };

	for (int i = 0; i < 10; i++)
	{
		Detector[i] = App->physics->AddBody(DetectorCube[i], 0.0f);
		Detector[i]->SensorDetector(true);
		Detector[i]->collision_listeners.add(this);
		
	}
	Have1, Have2, Have3, Have0 = false;
	GotPack1, GotPack2, GotPack3 = false;
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
	//DRAW SPHERES COLOUR PACKS

	BallPack1->GetTransform(&Pack1.transform);
	Pack1.Render();

	BallPack2->GetTransform(&Pack2.transform);
	Pack2.Render();

	CubePack1->GetTransform(&Pack3.transform);
	Pack3.Render();


	
	
	//PINTA Y COLOREA CON PEPA PIG (OBSTACLES)

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
	Cylinder CylBache9(0.5, 28);
	CylBache9.SetRotation(90, vec3(0, 1, 0));
	CylBache9.SetPos(12.5, 0.25, 124);
	CylBache9.color = LightBlue;
	CylBache9.Render();


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


	//CUBE MOUNTAIN1

	CubMtB1->GetTransform(&CubMt1.transform);
	CubMtB2->GetTransform(&CubMt2.transform);
	CubMtB3->GetTransform(&CubMt3.transform);
	CubMtB4->GetTransform(&CubMt4.transform);
	CubMtB5->GetTransform(&CubMt5.transform);
	CubMtB6->GetTransform(&CubMt6.transform);
	CubMtB7->GetTransform(&CubMt7.transform);
	CubMtB8->GetTransform(&CubMt8.transform);
	CubMtB9->GetTransform(&CubMt9.transform);
	CubMtB10->GetTransform(&CubMt10.transform);
    CubMtB11->GetTransform(&CubMt11.transform);
	CubMtB12->GetTransform(&CubMt12.transform);
	CubMtB13->GetTransform(&CubMt13.transform);
	CubMtB14->GetTransform(&CubMt14.transform);
    CubMtB15->GetTransform(&CubMt15.transform);
	CubMtB16->GetTransform(&CubMt16.transform);
    CubMtB17->GetTransform(&CubMt17.transform);

	CubMt1.color = Brown;
	CubMt2.color = Brown;
	CubMt3.color = Brown;
	CubMt4.color = Brown;
	CubMt5.color = Brown;
	CubMt6.color = Brown;
	CubMt7.color = Brown;
	CubMt8.color = Brown;
	CubMt9.color = Pink2;
	CubMt10.color = Pink2;
	CubMt11.color = Pink2;
	CubMt12.color = Pink2;
	CubMt13.color = Pink2;
	CubMt14.color = Pink2;
	CubMt15.color = Yellow;
	CubMt16.color = Yellow;
	CubMt17.color = Yellow;

	CubMt1.Render();
	CubMt2.Render();
	CubMt3.Render();
	CubMt4.Render();
	CubMt5.Render();
	CubMt6.Render();
	CubMt7.Render();
	CubMt8.Render();
	CubMt9.Render();
	CubMt10.Render();
	CubMt11.Render();
	CubMt12.Render();
	CubMt13.Render();
	CubMt14.Render();
	CubMt15.Render();
	CubMt16.Render();
	CubMt17.Render();
	
	//CUBE MOUNTAIN 2

	CubMtB20->GetTransform(&CubMt20.transform);
	CubMtB21->GetTransform(&CubMt21.transform);
	CubMtB22->GetTransform(&CubMt22.transform);
	CubMtB23->GetTransform(&CubMt23.transform);
	CubMtB24->GetTransform(&CubMt24.transform);
	CubMtB25->GetTransform(&CubMt25.transform);
	CubMtB26->GetTransform(&CubMt26.transform);
	CubMtB27->GetTransform(&CubMt27.transform);
	CubMtB28->GetTransform(&CubMt28.transform);
	CubMtB29->GetTransform(&CubMt29.transform);
	CubMtB30->GetTransform(&CubMt30.transform);
	CubMtB31->GetTransform(&CubMt31.transform);
	CubMtB32->GetTransform(&CubMt32.transform);
	CubMtB33->GetTransform(&CubMt33.transform);
	CubMtB34->GetTransform(&CubMt34.transform);
	CubMtB35->GetTransform(&CubMt35.transform);
	CubMtB36->GetTransform(&CubMt36.transform);

	CubMt20.color = Brown;
	CubMt21.color = Brown;
	CubMt22.color = Brown;
	CubMt23.color = Brown;
	CubMt24.color = Brown;
	CubMt25.color = Brown;
	CubMt26.color = Brown;
	CubMt27.color = Brown;
	CubMt28.color = Brown;
	CubMt29.color =Pink2;
	CubMt30.color =Pink2;
	CubMt31.color =Pink2;
	CubMt32.color =Pink2;
	CubMt33.color =Pink2;
	CubMt34.color = Yellow;
	CubMt35.color = Yellow;
	CubMt36.color = Yellow;

	CubMt20.Render();
	CubMt21.Render();
	CubMt22.Render();
	CubMt23.Render();
	CubMt24.Render();
	CubMt25.Render();
	CubMt26.Render();
	CubMt27.Render();
	CubMt28.Render();
	CubMt29.Render();
	CubMt30.Render();
	CubMt31.Render();
	CubMt32.Render();
	CubMt33.Render();
	CubMt34.Render();
	CubMt35.Render();
	CubMt36.Render();
	

	//PINTA Y COLOREA CON DORA LA EXPLORADORA(NIVELL)

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

	////WALL19
	//Cube wall19(115, 3, 2);
	//wall19.SetPos(-48, 1, -20);
	//wall19.color = Green;
	//wall19.Render();

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

	

	




	


	//WIN LOSE

	if (Have3==true) {
		LOG("ALL 3 DELIVERED");
		
	}
	else if (Have2==true) {
		LOG("2 DELIVERED");
	}
	else if (Have1==true) {
		LOG("1 DELIVERED");
	}
	else if (Have0==true) {
		LOG("0 DELIVERED");
	}
	

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

	if (body1 == Detector[4]) {

		App->player->CheckpointActive = true;
		LOG("CHECKPOINT SAVED");
		
	}

	//FINISHLINE
	if (body1 == Detector[0]) {

		App->player->CheckpointActive = false;
		if (GotPack1 == true && GotPack2 == true && GotPack3 == true) {

			//win
			LOG("WIN ALL 3 PACKS");
			Have3 = true;
			Have1, Have2, Have0 = false;
		}
		else if ((GotPack1 == true && GotPack2 == true) || (GotPack1==true && GotPack3==true)|| (GotPack2 == true &&GotPack2==true)) {

			LOG("WIN 2 OUT OF 3")
				Have2 = true;
			Have1, Have3, Have0 = false;
		}
		else if( (GotPack1==true) ||( GotPack2==true)||(GotPack3==true)) {

			LOG("WIN 1 OUF OF 3")
				Have1 = true;
			Have2, Have3, Have0 = false;;
		}
		else {
			LOG("LOSE 0 OUT OF 3");
			Have0 = true;
			Have1, Have2, Have3 = false;
		}
		
	}



}

