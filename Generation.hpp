class TerrainGeneration {
	private:
	const int SEED;
	const int SPACING;
	const int RENDERDISTANCE;
	char* tiles[2] = {"img/grass.png", "img/water.png"};
	
	public:
	int RandomNumber(int x, int j);

	void GenerateMap();

	TerrainGeneration(int seed, int spacing, int renderDistance) : SEED(seed), SPACING(spacing), RENDERDISTANCE(renderDistance) {}
};
