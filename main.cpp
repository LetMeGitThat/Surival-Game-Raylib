#include "includes/raylib.h"
#include "Entity.hpp"
#include "Generation.hpp"
#include <iostream>

// Generation Settings
#define SPACING 16
#define SEED 1000
#define RENDERDISTANCE 20

// Player Movement Input
void Input(Entity& player) {
	if (IsKeyDown(KEY_W)) {
		player.position.y += -1;
	}
	if (IsKeyDown(KEY_A)) {
		player.position.x += -1;
	}
	if (IsKeyDown(KEY_S)) {
		player.position.y += 1;
	}
	if (IsKeyDown(KEY_D)) {
		player.position.x += 1;
	}
}

int main() {
	// Creating a window
	const int WIDTH = 600;
	const int HEIGHT = 600;
	const char* TITLE = "Survival Game";
	const int FPS = 60;

	InitWindow(WIDTH, HEIGHT, TITLE);
	SetTargetFPS(FPS);

	// Initializations
	Texture2D playerSprite = LoadTexture("img/player.png");
	TerrainGeneration terrainGeneration(SEED, SPACING, RENDERDISTANCE);
	Entity player({50, 50}, playerSprite);

	while (WindowShouldClose() == false) {
		BeginDrawing();
		
		// Clear
		ClearBackground(BLACK);

		// Generate Map
		terrainGeneration.GenerateMap();

		// Input
		Input(player);
		
		// Draw
		player.Draw();
		DrawFPS(10, 10);

		EndDrawing();
	}

	CloseWindow();
	return 0;
}
