#pragma once
#include "includes/raylib.h"

class Entity {
	private:
	Vector2 position;
	Vector2 velocity;
	Texture2D sprite;

	public:
	void Draw() {
		DrawTexture(sprite, position.x, position.y, WHITE);
	}

	void SetVelocity(Vector2 newVel) {
		velocity = newVel;
	}

	void Update() {

		// Check for collision here if they can move on the x allow them and if they can move on the y allow them
		position.x += velocity.x;
		position.y += velocity.y;
	}

	Entity(Vector2 Position, Texture2D Sprite) : position(Position), sprite(Sprite) {}
};
