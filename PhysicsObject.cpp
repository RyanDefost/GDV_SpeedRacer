#include "PhysicsObject.h"
#include <iostream>

void PhysicsObject::CheckVelocity()
{
	for (size_t i = 0; i < 100; i++)
	{
		AddForce({ 0,10 });
		UpdatePhysics();

		if (this->velocity.x > this->maxSpeed || this->velocity.y > this->maxSpeed) 
		{
			std::cout << "MaxSpeed To high: " << this->velocity.x << " | " << this->velocity.y << "\n";
		}
	}
}

void PhysicsObject::UpdatePhysics()
{
	AddForce(Vector2{-this->velocity.x, -this->velocity.y} *this->friction);
	CalculateAcceleration();
	
	this->velocity = this->velocity * this->time + (Vector2{0.5,0.5} *this->acceleration) * (this->time * this->time);
	this->position = this->position + (this->velocity * this->speed);

	this->currentForce = { 0,0 };
}

void PhysicsObject::AddForce(Vector2 force)
{
	this->currentForce = this->currentForce + force;
}

void PhysicsObject::SetForce(Vector2 force)
{
	this->currentForce = force;
	this->velocity = { 0,0 };
}

void PhysicsObject::CalculateAcceleration()
{
	float force = this->currentForce.Magnitude();
	Vector2 Normalized = this->currentForce.Normalized(this->currentForce);
	this->acceleration = (Normalized * force) / this->mass;
}

void PhysicsObject::CapVelocity()
{
	if (this->velocity.x > this->maxSpeed) 
	{
		this->velocity.x = this->maxSpeed;
	}

	if (this->velocity.y > this->maxSpeed) 
	{
		this->velocity.y = this->maxSpeed;
	}
}

//Credit: Bas de Reus [Helped make sense of the Physics on paper.]
