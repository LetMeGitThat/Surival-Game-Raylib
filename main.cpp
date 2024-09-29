#include "includes/raylib.h"
#include "Entity.hpp"
#include "includes/raylib.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

#define SPACING 16
#define SEED 50
#define GRASS "img/grass.png"
#define WATER "img/water.png"

char* tiles[2] = {GRASS, WATER};

int RandomNumber(int x, int y, int seed) {
	srand(x * y * seed);

	return rand() % 2;
}

void LoadMap() {
    for (int j = 0; j < 17; j++) {
		for (int i = 0; i < 17; i++) {
			char* tile = tiles[RandomNumber(i, j, SEED)];

			Texture2D tileSprite = LoadTexture(tile);
			DrawTexture(tileSprite, i * SPACING, j * SPACING, WHITE);
			std::cout << i * SPACING << " " << j * SPACING << std::endl;
		}
	}
}

int main() {
	// Creating a window
	const int WIDTH = 600;
	const int HEIGHT = 600;
	const char* TITLE = "Survival Game";
	const int FPS = 60;

	const int TILESIZE = WIDTH / 16;

	InitWindow(WIDTH, HEIGHT, TITLE);
	SetTargetFPS(FPS);

	// Initializations

	// Generate map
	int mapData[5][5];

	while (WindowShouldClose() == false) {
		BeginDrawing();

		LoadMap();
		ClearBackground(BLACK);

		EndDrawing();
	}

	CloseWindow();
	return 0;
}
