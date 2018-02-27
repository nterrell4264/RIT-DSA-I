#pragma once
//Includes
#include "Box2D/box2d.h"



//Functions
void update(b2World& world, b2Body& snake);
void display(b2Body& snake, b2Body& target);
void applyForces(b2Body& snake);
void moveTarget(b2Body& target, float& xPos, float& yPos);