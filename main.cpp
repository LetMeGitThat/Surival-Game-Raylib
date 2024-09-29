#include "includes/raylib.h"
#include "Entity.hpp"
#include <iostream>

#define SPACING 16
#define SEED 51

char* tiles[2] = {"img/grass.png", "img/water.png"};

int RandomNumber(int x, int y, int seed) {
	srand(x * y * seed);

	return rand() % 2;
}

const int RENDERDISTANCE = 37;

void LoadMap() {
    for (int j = 0; j < RENDERDISTANCE; j++) {
		for (int i = 0; i < RENDERDISTANCE; i++) {
			char* tile = tiles[RandomNumber(i, j, SEED)];

			Texture2D tileSprite = LoadTexture(tile);
			DrawTexture(tileSprite, i * SPACING, j * SPACING, WHITE);
		}
	}
}

void Input() {
	if (IsKeyPressed(KEY_W)) {
		
	}
	if (IsKeyPressed(KEY_A)) {
		
	}
	if (IsKeyPressed(KEY_S)) {
		
	}
	if (IsKeyPressed(KEY_D)) {
		
	}
	
	if (IsKeyReleased(KEY_W)) {

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
		
		ClearBackground(BLACK);
		LoadMap();
		player.Draw();

		EndDrawing();
	}

	CloseWindow();
	return 0;
}
