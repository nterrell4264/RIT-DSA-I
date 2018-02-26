#pragma once
//Includes
#include "Box2D/box2d.h"

//Variables
b2Vec2 gravity(0.0f, -9.8f);
b2World world = b2World(gravity);
b2Body* snake;
b2Body* target;

float32 timeStep = 1 / 60.0f;
int32 velocityIterations = 6;
int32 positionIterations = 2;

//Functions
void update();
void display();
void applyForces();
void moveTarget(float& xPos, float& yPos);