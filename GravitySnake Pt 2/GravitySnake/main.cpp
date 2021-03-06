#include "stdafx.h"
#include "snake.h"
#include <iostream>
using namespace std;

//Variables
b2Vec2 gravity(0.0f, -9.8f);
b2World world = b2World(gravity);
b2Body* snake;
b2Body* target;

b2Vec2* targetLocations;
b2Vec2 currentLocation;
const int maxTargets = 200;
int targetNum = 0;

int hits = 0;
int score = 0;

//Methods
void setupTargets(int cnt) {
	targetLocations = new b2Vec2[cnt + 1]{};
	for (size_t i = 0; i < cnt; i++) {
		targetLocations[i] = b2Vec2((rand() / 100 % 10 - 5), (rand() / 100 % 10 - 5));
	}
	targetLocations[cnt] = b2Vec2(-1000.0f, -1000.0f);
	currentLocation = *targetLocations;
}
bool selectNextTarget() {
	targetNum++;
	currentLocation = targetLocations[targetNum];
	target->SetTransform(currentLocation, target->GetAngle());
	return !(currentLocation.x == -1000);
}

int main()
{
	//Instructions
	printf("Welcome to Gravity Snake!\n");
	printf("How many targets would you like? ");
	int numTargets;
	cin >> numTargets;
	while (numTargets < 1 || numTargets > maxTargets) {
		printf("That is not a valid number of targets. Try again.\n");
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> numTargets;
	}
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
	setupTargets(numTargets);

	b2BodyDef targetBody = b2BodyDef();
	targetBody.position = currentLocation;

	b2PolygonShape targetShape = b2PolygonShape();
	targetShape.SetAsBox(0.3f, 0.3f);

	target = world.CreateBody(&targetBody);
	#pragma endregion
	RenderWindow window(VideoMode(600, 600), "Gravity Snake");

	//Run game
	while (true) {
		processInput(*snake);
		update(world);
		if (!window.isOpen()) return 0;
		display(window, *snake, *target, hits, score);
		if ((snake->GetPosition() - target->GetPosition()).LengthSquared() <= .3) { //Snake hits target
			hits++;
			score += 100 * snake->GetLinearVelocity().LengthSquared(); //Score is based on speed when hitting the target, because it's harder to hit when going fast.
			printf("Hits: %i\n", hits);
			printf("Score: %i\n", score);
			if (!selectNextTarget()) { //Victory
				printf("You win!\n");
				return 0;
			}
		}
	}
}

