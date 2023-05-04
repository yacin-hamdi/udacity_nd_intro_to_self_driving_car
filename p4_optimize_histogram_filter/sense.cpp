#include "headers/sense.h"

using namespace std;

vector< vector <float> > sense(char color, vector< vector <char> > grid, vector< vector <float> > beliefs,  float p_hit, float p_miss) 
{
	int height = grid.size();
	int width = grid[0].size();
	vector< vector <float> > newGrid(height, vector<float>(width));

	bool hit = false;
	int i, j;

	for (i=0; i<height; i++) {
		for (j=0; j<width; j++) {
			hit = grid[i][j] == color;
			newGrid[i][j] = beliefs[i][j] * (p_hit * hit + (1-hit) * p_miss);
		}
	}
	return newGrid;
}
