#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"
#include "ModuleAudio.h"

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

	//Level Loading Functions

	void LoadLevelWalls();
	void DrawLevelWalls();
	void LoadStaticObstacles();
	void DrawStaticObstacles();
	void LoadDynamicObstacles();
	void DrawDynamicObstacles();
	void LoadBridge();
	void DrawBridge();
	void RewardsChoose();
	void LoadRewards();

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




	//FORMA Moving Obstacle
	Cube CubRot1;
	Cube CubRot2;
	Cube CubRot3;
	Cube CubRot4;
	Cylinder CylRot1;
	Cylinder CylRot2;

	//PHYSBODY Moving Obstacle
	PhysBody3D* CylRotB1;
	PhysBody3D* CylRotB2;

	PhysBody3D* CubRotB1;
	PhysBody3D* CubRotB2;
	PhysBody3D* CubRotB3;
	PhysBody3D* CubRotB4;

	//DETECT COLLIDERS
	Cube DetectorCube[18];
	PhysBody3D* Detector[18];


	//OBSTACLES PART 3 (CUBE MOUNTAIN1)
	//FORMA
	Cube CubMt1;
	Cube CubMt2;
	Cube CubMt3;
	Cube CubMt4;
	Cube CubMt5;
	Cube CubMt6;
	Cube CubMt7;
	Cube CubMt8;
	Cube CubMt9;
	Cube CubMt10;
	Cube CubMt11;
	Cube CubMt12;
	Cube CubMt13;
	Cube CubMt14;
	Cube CubMt15;
	Cube CubMt16;
	Cube CubMt17;

	
	//PHYSBODY
	PhysBody3D* CubMtB1;
	PhysBody3D* CubMtB2;
	PhysBody3D* CubMtB3;
	PhysBody3D* CubMtB4;
	PhysBody3D* CubMtB5;
	PhysBody3D* CubMtB6;
	PhysBody3D* CubMtB7;
	PhysBody3D* CubMtB8;
	PhysBody3D* CubMtB9;
	PhysBody3D* CubMtB10;
	PhysBody3D* CubMtB11;
	PhysBody3D* CubMtB12;
	PhysBody3D* CubMtB13;
	PhysBody3D* CubMtB14;
	PhysBody3D* CubMtB15;
	PhysBody3D* CubMtB16;
	PhysBody3D* CubMtB17;
	


	//OBSTACLES PART 3 (CUBE MOUNTAIN1)
	//FORMA
	Cube CubMt20;
	Cube CubMt21;
	Cube CubMt22;
	Cube CubMt23;
	Cube CubMt24;
	Cube CubMt25;
	Cube CubMt26;
	Cube CubMt27;
	Cube CubMt28;
	Cube CubMt29;
	Cube CubMt30;
	Cube CubMt31;
	Cube CubMt32;
	Cube CubMt33;
	Cube CubMt34;
	Cube CubMt35;
	Cube CubMt36;
	Cube CubMt37;

	//PHYSBODY
	PhysBody3D* CubMtB20;
	PhysBody3D* CubMtB21;
	PhysBody3D* CubMtB22;
	PhysBody3D* CubMtB23;
	PhysBody3D* CubMtB24;
	PhysBody3D* CubMtB25;
	PhysBody3D* CubMtB26;
	PhysBody3D* CubMtB27;
	PhysBody3D* CubMtB28;
	PhysBody3D* CubMtB29;
	PhysBody3D* CubMtB30;
	PhysBody3D* CubMtB31;
	PhysBody3D* CubMtB32;
	PhysBody3D* CubMtB33;
	PhysBody3D* CubMtB34;
	PhysBody3D* CubMtB35;
	PhysBody3D* CubMtB36;
	PhysBody3D* CubMtB37;


	//FINISH LINE
	//FORMA
	Cube FinishL1;
	Cube FinishL2;
	Cube FinishL3;
	Cube FinishL4;
	Cube FinishL5;
	Cube FinishL6;
	Cube FinishL7;
	Cube FinishL8;
	Cube FinishL9;
	Cube FinishL10;
	Cube FinishL11;
	Cube FinishL12;
	Cube FinishL13;
	Cube FinishL14;
	Cube FinishL15;
	Cube FinishL16;
	Cube FinishL17;
	Cube FinishL18;
	Cube FinishL19;
	Cube FinishL20;
	Cube FinishL21;
	Cube FinishL22;
	Cube FinishL23;
	Cube FinishL24;
	Cube FinishL25;
	Cube FinishL26;
	

	//PHYSBODY

	PhysBody3D* FinishBL1;
	PhysBody3D* FinishBL2;
	PhysBody3D* FinishBL3;
	PhysBody3D* FinishBL4;
	PhysBody3D* FinishBL5;
	PhysBody3D* FinishBL6;
	PhysBody3D* FinishBL7;
	PhysBody3D* FinishBL8;
	PhysBody3D* FinishBL9;
	PhysBody3D* FinishBL10;
	PhysBody3D* FinishBL11;
	PhysBody3D* FinishBL12;
	PhysBody3D* FinishBL13;
	PhysBody3D* FinishBL14;
	PhysBody3D* FinishBL15;
	PhysBody3D* FinishBL16;
	PhysBody3D* FinishBL17;
	PhysBody3D* FinishBL18;
	PhysBody3D* FinishBL19;
	PhysBody3D* FinishBL20;
	PhysBody3D* FinishBL21;
	PhysBody3D* FinishBL22;
	PhysBody3D* FinishBL23;
	PhysBody3D* FinishBL24;
	PhysBody3D* FinishBL25;
	PhysBody3D* FinishBL26;

	
	
	
	

	//Bridge

	Cube Bridge1;
	Cube Bridge2Dup;
	Cube Bridge2;
	Cube Bridge3;
	Cube Bridge4;
	Cube Bridge5;
	Cube Bridge6;
	Cube Bridge7;
	Cube Bridge8;
	Cube Bridge9;
	Cube Bridge10;
	Cube Bridge11;
	Cube Bridge12;
	Cube Bridge13;
	Cube Bridge14;
	Cube Bridge15;
	Cube Bridge16;
	
	

	PhysBody3D*  Bridge1B;
	PhysBody3D*  Bridge2B;
	PhysBody3D*  Bridge3B;
	PhysBody3D*  Bridge4B;
	PhysBody3D*  Bridge5B;
	PhysBody3D*  Bridge6B;
	PhysBody3D*  Bridge7B;
	PhysBody3D*  Bridge8B;
	PhysBody3D*  Bridge9B;
	PhysBody3D*  Bridge10B;

	PhysBody3D*  Bridge11B;
	PhysBody3D*  Bridge12B;
	PhysBody3D*  Bridge13B;
	PhysBody3D*  Bridge14B;
	PhysBody3D*  Bridge15B;
	PhysBody3D*  Bridge16B;
	

	//BOOST AREA
	Cube Boost1;
	PhysBody3D* BoostB1;
	
	

	bool OneSpawned1;


	//REWARD

	
	//---------------------------------------------------------------COLLIDERS BOOLS
	bool GotPack1, GotPack2, GotPack3;
	bool Have1, Have2, Have3, Have0;
	bool Pack1Fall, Pack2Fall, Pack3Fall;
	bool CheckpointPack1, CheckpointPack2, CheckpointPack3;
	bool BoostActive;
	


	//--------------------------------AUDIO I COSES

	char* Music;
	Mix_Chunk *Sortida;


	PhysBody3D* PartB1, *PartB2, *PartB3, *PartB4, *PartB5, *PartB6, *PartB7;
	Cube Part1, Part2, Part3, Part4, Part5, Part6, Part7;
};
