#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "Primitive.h"
#include "PhysVehicle3D.h"
#include "PhysBody3D.h"
#include "ModuleSceneIntro.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled), vehicle(NULL)
{
	turn = acceleration = brake = 0.0f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	VehicleInfo car;

	// Car properties ----------------------------------------
	car.chassis_size.Set(3, 2, 4);
	car.chassis_offset.Set(0, 1.5, 0);
	car.mass = 700.0f;
	car.suspensionStiffness = 15.88f;
	car.suspensionCompression = 0.83f;
	car.suspensionDamping = 0.2f;
	car.maxSuspensionTravelCm = 1000.0f;
	car.frictionSlip = 50.5;
	car.maxSuspensionForce = 6000.0f;

	// Wheel properties ---------------------------------------
	float connection_height = 2.0f;
	float wheel_radius = 0.6f;
	float wheel_width = 0.5f;
	float suspensionRestLength = 1.2f;

	// Don't change anything below this line ------------------

	float half_width = car.chassis_size.x*0.5f;
	float half_length = car.chassis_size.z*0.5f;
	
	vec3 direction(0,-1,0);
	vec3 axis(-1,0,0);
	
	car.num_wheels = 4;
	car.wheels = new Wheel[4];

	// FRONT-LEFT ------------------------
	car.wheels[0].connection.Set(half_width - 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[0].direction = direction;
	car.wheels[0].axis = axis;
	car.wheels[0].suspensionRestLength = suspensionRestLength;
	car.wheels[0].radius = wheel_radius;
	car.wheels[0].width = wheel_width;
	car.wheels[0].front = true;
	car.wheels[0].drive = true;
	car.wheels[0].brake = false;
	car.wheels[0].steering = true;

	// FRONT-RIGHT ------------------------
	car.wheels[1].connection.Set(-half_width + 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[1].direction = direction;
	car.wheels[1].axis = axis;
	car.wheels[1].suspensionRestLength = suspensionRestLength;
	car.wheels[1].radius = wheel_radius;
	car.wheels[1].width = wheel_width;
	car.wheels[1].front = true;
	car.wheels[1].drive = true;
	car.wheels[1].brake = false;
	car.wheels[1].steering = true;

	// REAR-LEFT ------------------------
	car.wheels[2].connection.Set(half_width - 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[2].direction = direction;
	car.wheels[2].axis = axis;
	car.wheels[2].suspensionRestLength = suspensionRestLength;
	car.wheels[2].radius = wheel_radius;
	car.wheels[2].width = wheel_width;
	car.wheels[2].front = false;
	car.wheels[2].drive = true;
	car.wheels[2].brake = true;
	car.wheels[2].steering = false;

	// REAR-RIGHT ------------------------
	car.wheels[3].connection.Set(-half_width + 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[3].direction = direction;
	car.wheels[3].axis = axis;
	car.wheels[3].suspensionRestLength = suspensionRestLength;
	car.wheels[3].radius = wheel_radius;
	car.wheels[3].width = wheel_width;
	car.wheels[3].front = false;
	car.wheels[3].drive = true;
	car.wheels[3].brake = true;
	car.wheels[3].steering = false;

	vehicle = App->physics->AddVehicle(car);
	vehicle->SetPos(0, 1, 10);
	
	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	return true;
}

void ModulePlayer::Restart()
{
	float RestartPos[20];
	//LISTA D'OBJECTES DEL COTXE, NO SE CONTAR OSIGUI QUE EL 20 ES PER NO QUEDARME CURT NO PERQUE TINGUI 20
	for (int i = 0; i < 20; ++i)
	{
		RestartPos[i] = 0;
	}
	//PERQUE NO APAREGUI VOLCAT
	RestartPos[0] = 1;
	RestartPos[5] = 1;
	RestartPos[10] = 1;
	vehicle->SetTransform(RestartPos);

	vehicle->vehicle->getRigidBody()->setLinearVelocity({ 0,0,0, });
	vehicle->vehicle->getRigidBody()->setAngularVelocity({ 0,0,0 });
	vehicle->SetPos(0, 0, 10);

	App->scene_intro->BallPack1->SetPos(0, 2, 11);
	App->scene_intro->BallPack2->SetPos(0, 2, 9);
	App->scene_intro->CubePack1->SetPos(0, 2, 10);

	CheckpointActive = false;
	App->scene_intro->Have1, App->scene_intro->Have2, App->scene_intro->Have3, App->scene_intro->Have0 = false;
	App->scene_intro->GotPack1, App->scene_intro->GotPack2, App->scene_intro->GotPack3 = false;
}

void ModulePlayer::RestartLevel()
{
	
	
	//RESETING PACKS POSITION ( NI IDEA DE COM ES FA PER POSAR LA SEVA SPEED A 0)
	

	//RESETING LEVEL OBSTACLES (NI IDEA DE COM ES FA PER POSAR LA SEVA SPEED A 0)
	//CUBE MT 1
	App->scene_intro->CubMtB1->SetPos(-50, 0, 50);
	App->scene_intro->CubMtB2->SetPos(-53, 0, 50);
	App->scene_intro->CubMtB3->SetPos(-56, 0, 50);
	App->scene_intro->CubMtB4->SetPos(-59, 0, 50);
	App->scene_intro->CubMtB5->SetPos(-50, 0, 53);
	App->scene_intro->CubMtB6->SetPos(-53, 0, 53);
	App->scene_intro->CubMtB7->SetPos(-56, 0, 53);
	App->scene_intro->CubMtB8->SetPos(-59, 0, 53);
	App->scene_intro->CubMtB9->SetPos(-51.5, 2, 53);
	App->scene_intro->CubMtB10->SetPos(-54.5, 2, 53);
	App->scene_intro->CubMtB11->SetPos(-57.5, 2, 53);
	App->scene_intro->CubMtB12->SetPos(-51.5, 2, 50);
	App->scene_intro->CubMtB13->SetPos(-54.5, 2, 50);
	App->scene_intro->CubMtB14->SetPos(-57.5, 2, 50);
	App->scene_intro->CubMtB15->SetPos(-53, 4, 51.5);
	App->scene_intro->CubMtB16->SetPos(-56, 4, 51.5);
	App->scene_intro->CubMtB17->SetPos(-54.5, 6, 51.5);

	//CUBE MT 2
	if (App->player->CheckpointActive == false) {
		App->scene_intro->CubMtB20->SetPos(-50, 0, 103);
		App->scene_intro->CubMtB21->SetPos(-53, 0, 103);
		App->scene_intro->CubMtB22->SetPos(-56, 0, 103);
		App->scene_intro->CubMtB23->SetPos(-59, 0, 103);
		App->scene_intro->CubMtB24->SetPos(-50, 0, 106);
		App->scene_intro->CubMtB25->SetPos(-53, 0, 106);
		App->scene_intro->CubMtB26->SetPos(-56, 0, 106);
		App->scene_intro->CubMtB27->SetPos(-59, 0, 106);
		App->scene_intro->CubMtB28->SetPos(-51.5, 1.25, 106);
		App->scene_intro->CubMtB29->SetPos(-54.5, 1.25, 106);
		App->scene_intro->CubMtB30->SetPos(-57.5, 1.25, 106);
		App->scene_intro->CubMtB31->SetPos(-51.5, 1.25, 103);
		App->scene_intro->CubMtB32->SetPos(-54.5, 1.25, 103);
		App->scene_intro->CubMtB33->SetPos(-57.5, 1.25, 103);
		App->scene_intro->CubMtB34->SetPos(-53, 3.25, 104.5);
		App->scene_intro->CubMtB35->SetPos(-56, 3.25, 104.5);
		App->scene_intro->CubMtB36->SetPos(-54.5, 5.25, 104.5);

	}
	else {


		App->scene_intro->CubMtB1->SetPos(-50, 0, 50);
		App->scene_intro->CubMtB2->SetPos(-53, 0, 50);
		App->scene_intro->CubMtB3->SetPos(-56, 0, 50);
		App->scene_intro->CubMtB4->SetPos(-59, 0, 50);
		App->scene_intro->CubMtB5->SetPos(-50, 0, 53);
		App->scene_intro->CubMtB6->SetPos(-53, 0, 53);
		App->scene_intro->CubMtB7->SetPos(-56, 0, 53);
		App->scene_intro->CubMtB8->SetPos(-59, 0, 53);
		App->scene_intro->CubMtB9->SetPos(-51.5, 2, 53);
		App->scene_intro->CubMtB10->SetPos(-54.5, 2, 53);
		App->scene_intro->CubMtB11->SetPos(-57.5, 2, 53);
		App->scene_intro->CubMtB12->SetPos(-51.5, 2, 50);
		App->scene_intro->CubMtB13->SetPos(-54.5, 2, 50);
		App->scene_intro->CubMtB14->SetPos(-57.5, 2, 50);
		App->scene_intro->CubMtB15->SetPos(-53, 4, 51.5);
		App->scene_intro->CubMtB16->SetPos(-56, 4, 51.5);
		App->scene_intro->CubMtB17->SetPos(-54.5, 6, 51.5);

		App->scene_intro->CubMtB20->SetPos(-50, 0, 90);
		App->scene_intro->CubMtB21->SetPos(-53, 0, 90);
		App->scene_intro->CubMtB22->SetPos(-56, 0, 90);
		App->scene_intro->CubMtB23->SetPos(-59, 0, 90);
		App->scene_intro->CubMtB24->SetPos(-50, 0, 93);
		App->scene_intro->CubMtB25->SetPos(-53, 0, 93);
		App->scene_intro->CubMtB26->SetPos(-56, 0, 93);
		App->scene_intro->CubMtB27->SetPos(-59, 0, 93);
		App->scene_intro->CubMtB28->SetPos(-51.5, 2, 93);
		App->scene_intro->CubMtB29->SetPos(-54.5, 2, 93);
		App->scene_intro->CubMtB30->SetPos(-57.5, 2, 93);
		App->scene_intro->CubMtB31->SetPos(-51.5, 2, 90);
		App->scene_intro->CubMtB32->SetPos(-54.5, 2, 90);
		App->scene_intro->CubMtB33->SetPos(-57.5, 2, 90);
		App->scene_intro->CubMtB34->SetPos(-53, 4, 91.5);
		App->scene_intro->CubMtB35->SetPos(-56, 4, 91.5);
		App->scene_intro->CubMtB36->SetPos(-54.5, 6, 91.5);
	}
	

	
}

void ModulePlayer::RestartFromCheckpoint()
{



	float RestartPos[20];
	//LISTA D'OBJECTES DEL COTXE, NO SE CONTAR OSIGUI QUE EL 20 ES PER NO QUEDARME CURT NO PERQUE TINGUI 20
	for (int i = 0; i < 20; ++i)
	{
		RestartPos[i] = 0;
	}
	//PERQUE NO APAREGUI VOLCAT
	RestartPos[0] = 1;
	RestartPos[5] = 1;
	RestartPos[10] = 1;
	vehicle->SetTransform(RestartPos);
	//MOVIMENT
	vehicle->vehicle->getRigidBody()->setLinearVelocity({ 0,0,0, });
	vehicle->vehicle->getRigidBody()->setAngularVelocity({ 0,0,0 });
	//POSITION
	vehicle->SetPos(-54.5, 0, 110);

	App->scene_intro->BallPack1->SetPos(-54.5, 2, 111);
	App->scene_intro->BallPack2->SetPos(-54.5, 2, 109);
	App->scene_intro->CubePack1->SetPos(-54.5, 3, 110);


	App->scene_intro->Have1, App->scene_intro->Have2, App->scene_intro->Have3, App->scene_intro->Have0 = false;
	App->scene_intro->GotPack1, App->scene_intro->GotPack2, App->scene_intro->GotPack3 = false;


}

// Update: draw background
update_status ModulePlayer::Update(float dt)
{
	turn = acceleration = brake = 0.0f;

	if(App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
	{
		acceleration = MAX_ACCELERATION;
	}

	if(App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	{
		if(turn < TURN_DEGREES)
			turn +=  TURN_DEGREES;
	}

	if(App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	{
		if(turn > -TURN_DEGREES)
			turn -= TURN_DEGREES;
	}

	if(App->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT)
	{
		
		    if (acceleration == 0) {
				acceleration = -MAX_ACCELERATION;
			}
			else {
				brake = BRAKE_POWER;
			}
			
		
	}

	if (App->input->GetKey(SDL_SCANCODE_R) == KEY_REPEAT) {

		if (CheckpointActive != true) {

			Restart();
			RestartLevel();

		}
		else {
			RestartFromCheckpoint();
			RestartLevel();
		}

		

	}


	
	

	vehicle->ApplyEngineForce(acceleration);
	vehicle->Turn(turn);
	vehicle->Brake(brake);

	vehicle->Render();

	char title[80];
	sprintf_s(title, "%.1f Km/h", vehicle->GetKmh());
	App->window->SetTitle(title);

	return UPDATE_CONTINUE;
}



