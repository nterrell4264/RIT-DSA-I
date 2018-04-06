#pragma region dependencies
#include "stdafx.h"
#include "snake.h"
#include "conio.h"
#pragma endregion

#pragma region variables
float32 timeStep = 1 / 2000.0f;
int32 velocityIterations = 6;
int32 positionIterations = 2;
#pragma endregion

void update(b2World& world) {
	world.Step(timeStep, velocityIterations, positionIterations);
}

void processInput(b2Body& snake) {
	void(*force)(b2Body& player) = nullptr;
	if (Keyboard::isKeyPressed(Keyboard::Up)) force = ApplyForceUp;
	if (Keyboard::isKeyPressed(Keyboard::Down)) force = ApplyForceDown;
	if (Keyboard::isKeyPressed(Keyboard::Right)) force = ApplyForceRight;
	if (Keyboard::isKeyPressed(Keyboard::Left)) force = ApplyForceLeft;
	if(force != nullptr) force(snake);
}
void ReverseGravity(b2World& world) {
	b2Vec2 reverse = world.GetGravity();
	reverse *= -1;
	world.SetGravity(reverse);
}

void applyForces(b2Body& snake) {
	int press = _getch();
	switch (press) {
		case('w'):
		case(38): {
			ApplyForceUp(snake);
			break;
		}
		case('s'):
		case(40): {
			ApplyForceDown(snake);
			break;
		}
		case('a'):
		case(37): {
			ApplyForceLeft(snake);
			break;
		}
		case('d'):
		case(39): {
			ApplyForceRight(snake);
			break;
		}
	}
}
void ApplyForceUp(b2Body& player) {
	player.ApplyForceToCenter(b2Vec2(0.0f, 100.0f), true);
}
void ApplyForceDown(b2Body& player) {
	player.ApplyForceToCenter(b2Vec2(0.0f, -100.0f), true);
}
void ApplyForceRight(b2Body& player) {
	player.ApplyForceToCenter(b2Vec2(100.0f, 0.0f), true);
}
void ApplyForceLeft(b2Body& player) {
	player.ApplyForceToCenter(b2Vec2(-100.0f, 0.0f), true);
}

void moveTarget(b2Body& target) {
	target.SetTransform(b2Vec2((rand() / 100 % 10 - 5), (rand() / 100 % 10 - 5)),target.GetAngle());
}
void StopMoving(b2Body& player) {
	player.SetLinearVelocity(b2Vec2(0, 0));
}

void display(RenderWindow& window, b2Body& snake, b2Body& target, int hits, int score) {
	Event event;
	window.pollEvent(event);
	if (event.type == Event::Closed)
		window.close();
	CircleShape snakehead(12);
	snakehead.setFillColor(Color(0, 191, 0));
	snakehead.setPosition(Vector2f((snake.GetPosition().x + 5) * 40, (snake.GetPosition().y - 5) * -40));

	RectangleShape goal(Vector2f(12, 12));
	goal.setFillColor(Color(191, 127, 127));
	goal.setPosition(Vector2f((target.GetPosition().x + 5) * 40, (target.GetPosition().y - 5) * -40));

	/*Text hitText();
	hitText.setString(hits);

	Text scoreText();
	scoreText.setString(score);
	scoreText.setPosition(Vector2f(0, 5));*/

	window.clear(Color::Black);
	window.draw(snakehead);
	window.draw(goal);
	//window.draw(hitText);
	//window.draw(scoreText);
	window.display();
	/*b2Vec2 prPos = snake.GetPosition();
	printf("Snake is at %f, %f; ", prPos.x, prPos.y);
	prPos = target.GetPosition();
	printf("Target is at %f, %f\n", prPos.x, prPos.y);*/
}