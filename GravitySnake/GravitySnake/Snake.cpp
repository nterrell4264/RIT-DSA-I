#pragma region dependencies
#include "stdafx.h"
#include "conio.h"
#include "snake.h"
//SFML
#define SFML_STATIC
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#pragma endregion

void update() {
	applyForces();
	world.Step(timeStep, velocityIterations, positionIterations);
	display();
}

void applyForces() {
	if (_kbhit != 0) {
		switch (_getch()) {
		case('W'):
		case(38): {
			snake->ApplyForceToCenter(b2Vec2(0.0f, 1.0f),true);
			break;
		}
		case('A'):
		case(37): {
			snake->ApplyForceToCenter(b2Vec2(-1.0f, 0.0f), true);
			break;
		}
		case('D'):
		case(39): {
			snake->ApplyForceToCenter(b2Vec2(1.0f, 0.0f), true);
			break;
		}
		}
	}
}
void moveTarget(float& xPos, float& yPos) {
	target->SetTransform(b2Vec2(xPos, yPos), 0);
}

void display() {
	b2Vec2 prPos = snake->GetPosition();
	printf("Snake is at %f, %f\n", prPos.x, prPos.y);
	prPos = target->GetPosition();
	printf("Target is at %f, %f\n", prPos.x, prPos.y);
}