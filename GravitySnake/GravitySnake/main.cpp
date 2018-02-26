#include "stdafx.h"
#include "snake.h"
using namespace std;

int main()
{
	//Instructions
	printf("Welcome to Gravity Snake!");
	printf("Apply forces to the snake using WASD or the arrow keys.");

	//Create game
	#pragma region Snake
	b2BodyDef snakeBody = b2BodyDef();
	snakeBody.type = b2_dynamicBody;
	snakeBody.position.Set(3.0f, 3.0f);

	b2PolygonShape snakeShape = b2PolygonShape();
	snakeShape.SetAsBox(1.0f, 1.0f);

	b2FixtureDef snakeFix = b2FixtureDef();
	snakeFix.shape = &snakeShape;
	snakeFix.density = 1.0f;
	snakeFix.friction = 0.0f;

	snake = world.CreateBody(&snakeBody);
	snake->CreateFixture(&snakeFix);
	#pragma endregion
	#pragma region Target
	b2BodyDef targetBody = b2BodyDef();
	targetBody.position.Set((rand() % 10 - 5), (rand() % 10 - 5));

	b2PolygonShape targetShape = b2PolygonShape();
	targetShape.SetAsBox(0.3f, 0.3f);

	target = world.CreateBody(&targetBody);
	target->CreateFixture(&targetShape, 0.0f);
	#pragma endregion

	//Run game
	while (true) {
		update();
	}

    return 0;
}

