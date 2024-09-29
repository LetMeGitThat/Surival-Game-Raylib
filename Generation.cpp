#pragma once
#include "Generation.hpp"
#include "includes/raylib.h"
#include <iostream>

int TerrainGeneration::RandomNumber(int x, int y) {
	srand(x * y * SEED);

	return rand() % 2;
}

void TerrainGeneration::GenerateMap() {
	for (int j = 0; j < RENDERDISTANCE; j++) {
		for (int i = 0; i < RENDERDISTANCE; i++) {
			char* tile = tiles[RandomNumber(i, j)];

			Texture2D tileSprite = LoadTexture(tile);
			DrawTexture(tileSprite, i * SPACING, j * SPACING, WHITE);
		}
	}
}

