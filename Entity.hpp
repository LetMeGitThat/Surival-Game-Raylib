#pragma once
#include "includes/raylib.h"

class Entity {
	private:
	Texture2D sprite;

	public:
	Vector2 position;

	void Draw() {
		DrawTexture(sprite, position.x, position.y, WHITE);
	}

	Entity(Vector2 Position, Texture2D Sprite) : position(Position), sprite(Sprite) {}
};
