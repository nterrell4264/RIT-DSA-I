#include "stdafx.h"
#include "snake.h"
using namespace std;

//Variables
b2Vec2 gravity(0.0f, -9.8f);
b2World world = b2World(gravity);
b2Body* snake;
b2Body* target;

int hits = 0;
int score = 0;

int main()
{
	//Instructions
	printf("Welcome to Gravity Snake!\n");
	printf("Apply forces to the snake using WASD or the arrow keys.\n");

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
	//target->CreateFixture(&targetShape, 0.0f);
	#pragma endregion

	//Run game
	while (true) {
		applyForces(*snake);
		update(world);
		display(*snake, *target);
		if ((snake->GetPosition() - target->GetPosition()).LengthSquared() <= .3) { //Snake hits target
			hits++;
			score += 100 * snake->GetLinearVelocity().LengthSquared(); //Score is based on speed when hitting the target, because it's harder to hit when going fast.
			printf("Hits: %i; Score: %i\n", hits, score);
			if (hits >= 10) { //Victory
				printf("You win!\n");
				return 0;
			}
			moveTarget(*target);
		}
	}

    return 0;
}

