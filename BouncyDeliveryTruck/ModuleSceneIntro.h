#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"

#define MAX_SNAKE 2

struct PhysBody3D;
struct PhysMotor3D;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);

public:
	
	


	float count;
	bool plane;

	PhysBody3D* pb_chassis;
	Cube p_chassis;

	PhysBody3D* pb_wheel;
	Cylinder p_wheel;

	PhysBody3D* pb_wheel2;
	Cylinder p_wheel2;

	PhysMotor3D* left_wheel;
	PhysMotor3D* right_wheel;



	//PACK FORMA
	Sphere Pack1;
	Sphere Pack2;
	//Sphere Pack3;
	Cube   Pack3;
	//Pack PhysBody
	PhysBody3D* BallPack1;
	PhysBody3D* BallPack2;
	PhysBody3D* BallPack3;
	PhysBody3D* CubePack1;


	//FORMA
	Cube CubRot1;
	Cube CubRot2;
	Cube CubRot3;
	Cube CubRot4;
	

	Cylinder CylRot1;
	Cylinder CylRot2;
	//PHYSBODY
	PhysBody3D* CylRotB1;
	PhysBody3D* CylRotB2;

	PhysBody3D* CubRotB1;
	PhysBody3D* CubRotB2;
	PhysBody3D* CubRotB3;
	PhysBody3D* CubRotB4;

	//DETECT COLLIDERS
	Cube DetectorCube[4];
	PhysBody3D* Detector[4];

	bool GotPack1, GotPack2, GotPack3;


};
