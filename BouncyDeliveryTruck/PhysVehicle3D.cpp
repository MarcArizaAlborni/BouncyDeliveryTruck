#include "PhysVehicle3D.h"
#include "Primitive.h"
#include "Bullet/include/btBulletDynamicsCommon.h"

// ----------------------------------------------------------------------------
VehicleInfo::~VehicleInfo()
{
	//if(wheels != NULL)
		//delete wheels;
}

// ----------------------------------------------------------------------------
PhysVehicle3D::PhysVehicle3D(btRigidBody* body, btRaycastVehicle* vehicle, const VehicleInfo& info) : PhysBody3D(body), vehicle(vehicle), info(info)
{
}

// ----------------------------------------------------------------------------
PhysVehicle3D::~PhysVehicle3D()
{
	delete vehicle;
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Render()
{
	//NOMES DIBUIX

	Cylinder wheel;

	wheel.color = Blue;

	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		wheel.radius = info.wheels[0].radius;
		wheel.height = info.wheels[0].width;

		vehicle->updateWheelTransform(i);
		vehicle->getWheelInfo(i).m_worldTransform.getOpenGLMatrix(&wheel.transform);

		wheel.Render();
	}

	//Main Body
	Cube chassis(info.chassis_size.x, info.chassis_size.y-1.5, info.chassis_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis.transform);
	btQuaternion q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset(info.chassis_offset.x, info.chassis_offset.y, info.chassis_offset.z);
	offset = offset.rotate(q.getAxis(), q.getAngle());

	chassis.transform.M[12] += offset.getX();
	chassis.transform.M[13] += offset.getY();
	chassis.transform.M[14] += offset.getZ();


	chassis.Render();

	//Left Wall

	Cube chassis2(info.chassis_size.x-2.8f, info.chassis_size.y-1.0f, info.chassis_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis2.transform);
	btQuaternion q2 = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset2(info.chassis_offset.x+1.4f, info.chassis_offset.y+0.75f, info.chassis_offset.z);
	offset2 = offset2.rotate(q2.getAxis(), q2.getAngle());

	chassis2.transform.M[12] += offset2.getX();
	chassis2.transform.M[13] += offset2.getY();
	chassis2.transform.M[14] += offset2.getZ();
	chassis2.color.Set(1.75f, 0.3f, 0.0f);

	chassis2.Render();

	//Right Wall

	Cube chassis3(info.chassis_size.x - 2.8f, info.chassis_size.y - 1.0f, info.chassis_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis3.transform);
	btQuaternion q3 = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset3(info.chassis_offset.x - 1.4f, info.chassis_offset.y + 0.75f, info.chassis_offset.z);
	offset3 = offset3.rotate(q3.getAxis(), q3.getAngle());

	chassis3.transform.M[12] += offset3.getX();
	chassis3.transform.M[13] += offset3.getY();
	chassis3.transform.M[14] += offset3.getZ();
	chassis3.color.Set(1.75f, 0.3f, 0.0f);

	chassis3.Render();

	//Back Wall

	Cube chassis4(info.chassis_size.x , info.chassis_size.y - 1.0f, info.chassis_size.z - 3.8f);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis4.transform);
	btQuaternion q4 = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset4(info.chassis_offset.x , info.chassis_offset.y + 0.75f, info.chassis_offset.z-1.9f);
	offset4 = offset4.rotate(q4.getAxis(), q4.getAngle());

	chassis4.transform.M[12] += offset4.getX();
	chassis4.transform.M[13] += offset4.getY();
	chassis4.transform.M[14] += offset4.getZ();
	chassis4.color.Set(1.75f, 0.3f, 0.0f);

	chassis4.Render();

	//Front Wall

	Cube chassis5(info.chassis_size.x, info.chassis_size.y - 1.0f, info.chassis_size.z - 3.8f);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis5.transform);
	btQuaternion q5 = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset5(info.chassis_offset.x, info.chassis_offset.y + 0.75f, info.chassis_offset.z + 1.9f);
	offset5 = offset5.rotate(q5.getAxis(), q5.getAngle());

	chassis5.transform.M[12] += offset5.getX();
	chassis5.transform.M[13] += offset5.getY();
	chassis5.transform.M[14] += offset5.getZ();
	chassis5.color.Set(1.75f, 0.3f, 0.0f);

	chassis5.Render();

	//Front Chassis

	Cube chassis6(info.chassis_size.x-0.5f, info.chassis_size.y - 1.0f, info.chassis_size.z - 3.75f);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis6.transform);
	btQuaternion q6 = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset6(info.chassis_offset.x, info.chassis_offset.y+0.25f , info.chassis_offset.z + 2.0f);
	offset6 = offset6.rotate(q6.getAxis(), q6.getAngle());

	chassis6.transform.M[12] += offset6.getX();
	chassis6.transform.M[13] += offset6.getY();
	chassis6.transform.M[14] += offset6.getZ();
	chassis6.color = Green;

	chassis6.Render();
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::ApplyEngineForce(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].drive == true)
		{
			vehicle->applyEngineForce(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Brake(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].brake == true)
		{
			vehicle->setBrake(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Turn(float degrees)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].steering == true)
		{
			vehicle->setSteeringValue(degrees, i);
		}
	}
}

// ----------------------------------------------------------------------------
float PhysVehicle3D::GetKmh() const
{
	return vehicle->getCurrentSpeedKmHour();
}