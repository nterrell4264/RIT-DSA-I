#pragma once
//Includes
#include "Box2D/box2d.h"
//SFML
#define SFML_STATIC
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
using namespace sf;

//Functions
void setupTargets(int cnt);
bool selectNextTarget();

void update(b2World& world);
void display(RenderWindow& window, b2Body& snake, b2Body& target, int hits, int score);

void processInput(b2Body& snake);
void ReverseGravity(b2World& world);

void applyForces(b2Body& snake);
void ApplyForceUp(b2Body& player);
void ApplyForceDown(b2Body& player);
void ApplyForceRight(b2Body& player);
void ApplyForceLeft(b2Body& player);

void moveTarget(b2Body& target);
void StopMoving(b2Body& player);