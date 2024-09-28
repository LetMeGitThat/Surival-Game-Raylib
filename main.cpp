#include "includes/raylib.h"
#include "Entity.hpp"
#include "includes/raylib.h"
#include <iostream>

#define spacing 16

void GenerateMap(int mapData[5][5]) {
	int offset = 8;
	Color COLORS[2] = {GREEN, BLUE};

	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 5; i++) {
			int tileData = mapData[j][i];

			Color color = COLORS[tileData];

			std::cout << i * spacing << " " << j * spacing << std::endl;
			DrawRectangle(i * spacing + (offset * i), j * spacing + (offset * j), 16, 16, color);
		}
	}
}

int main() {
  // Creating a window
	const int WIDTH = 600;
	const int HEIGHT = 600;
	const char* TITLE = "Surival Game";
	const int FPS = 60;

	InitWindow(WIDTH, HEIGHT, TITLE);
	SetTargetFPS(FPS);

	// Initializations

	// Generate map
	int mapData[5][5] = {
		{0, 1, 1, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
	};


	while (WindowShouldClose() == false) {
		BeginDrawing();

		GenerateMap(mapData);

		EndDrawing();
	}

	CloseWindow();
	return 0;
}
