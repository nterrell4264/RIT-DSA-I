#pragma once
//Includes
#include "Box2D/box2d.h"

//Functions
void setupTargets(int cnt);
bool selectNextTarget();

void update(b2World& world);
void display(b2Body& snake, b2Body& target);

void processInput();
void ReverseGravity(b2World& world);

void applyForces(b2Body& snake);
void ApplyForceUp(b2Body& player);
void ApplyForceDown(b2Body& player);
void ApplyForceRight(b2Body& player);
void ApplyForceLeft(b2Body& player);

void moveTarget(b2Body& target);
void StopMoving(b2Body& player);