#pragma once
#include "includes/raylib.h"

class Entity {
	Vector2 position;
	Texture2D sprite;

	Entity(Vector2 Position, Texture2D Sprite) : position(Position), sprite(Sprite) {}
};
