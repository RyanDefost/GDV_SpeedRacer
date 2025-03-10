#include "PhysicsObject.h"
#include <iostream>

void PhysicsObject::CheckVelocity()
{
	for (size_t i = 0; i < 100; i++)
	{
		AddForce({ 0,10 });
		UpdatePhysics();

		if (velocity.x > maxSpeed || velocity.y > maxSpeed) {
			std::cout << "MaxSpeed To high: " << velocity.x << " | " << velocity.y << "\n";
		}
	}
}

void PhysicsObject::UpdatePhysics()
{
	AddForce(Vector2{-velocity.x, -velocity.y} * friction);
	CalculateAcceleration();
	
	velocity = velocity * _time + (Vector2{0.5,0.5} * acceleration) * (_time * _time);
	position = position + (velocity * speed);

	currentForce = { 0,0 };
}

void PhysicsObject::AddForce(Vector2 force)
{
	currentForce = currentForce + force;
}

void PhysicsObject::SetForce(Vector2 force)
{
	currentForce = force;
	velocity = { 0,0 };
}

void PhysicsObject::CalculateAcceleration()
{
	float force = currentForce.magnitude();
	Vector2 normalized = currentForce.normalized(currentForce);
	acceleration = (normalized * force) / mass;
}

void PhysicsObject::CapVelocity()
{
	if (velocity.x > maxSpeed) {
		velocity.x = maxSpeed;
	}

	if (velocity.y > maxSpeed) {
		velocity.y = maxSpeed;
	}
}

//Credit: Bas de Reus [Helped make sense of the Physics on paper.]
