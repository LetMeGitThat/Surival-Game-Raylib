#include "includes/raylib.h"
#include "Entity.hpp"
#include <iostream>

#define SPACING 16
#define SEED 1000
#define TREESPAWNCHANCE 2


// Store this into another file called Map generation or something
int RandomNumber(int x, int y, int seed, int max) {
	srand(x * y * seed);

	return rand() % max;
}

const int RENDERDISTANCE = 20;

void LoadMap() {
	Texture2D tiles[2] = {LoadTexture("img/grass.png"), LoadTexture("img/water.png")};
	Texture2D treeSprite = LoadTexture("img/tree.png");

    for (int j = 0; j < RENDERDISTANCE; j++) {
		for (int i = 0; i < RENDERDISTANCE; i++) {
			int tileIndex = RandomNumber(i, j, SEED, 2);
			Texture2D tileSprite = tiles[tileIndex];

			DrawTexture(tileSprite, i * SPACING, j * SPACING, WHITE);

			if (tileIndex == 0 && RandomNumber(i+5, j+5, SEED, 10) < TREESPAWNCHANCE) {
				DrawTexture(treeSprite, i * SPACING, j * SPACING, WHITE);
			}
		}
	}
}

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
	Entity player({50, 50}, playerSprite);

	while (WindowShouldClose() == false) {
		BeginDrawing();
		
		// Clear
		ClearBackground(BLACK);

		// Generate Map
		LoadMap();

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
