#pragma region dependencies
#include "stdafx.h"
#include "conio.h"
#include "snake.h"
//SFML
/*#define SFML_STATIC
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>*/
#pragma endregion

float32 timeStep = 1 / 600.0f;
int32 velocityIterations = 6;
int32 positionIterations = 2;

void update(b2World& world, b2Body& snake) {
	applyForces(snake);
	world.Step(timeStep, velocityIterations, positionIterations);
}

void applyForces(b2Body& snake) {
	if (_kbhit() != 0) {
		int press = _getch();
		switch (press) {
		case('w'):
		case(38): {
			snake.ApplyForceToCenter(b2Vec2(0.0f, 200.0f),true);
			break;
		}
		case('a'):
		case(37): {
			snake.ApplyForceToCenter(b2Vec2(-100.0f, 0.0f), true);
			break;
		}
		case('d'):
		case(39): {
			snake.ApplyForceToCenter(b2Vec2(100.0f, 0.0f), true);
			break;
		}
		}
	}
}
void moveTarget(b2Body& target, float& xPos, float& yPos) {
	target.SetTransform(b2Vec2(xPos, yPos), 0);
}

void display(b2Body& snake, b2Body& target) {
	b2Vec2 prPos = snake.GetPosition();
	printf("Snake is at %f, %f\n", prPos.x, prPos.y);
	prPos = target.GetPosition();
	printf("Target is at %f, %f\n", prPos.x, prPos.y);
}