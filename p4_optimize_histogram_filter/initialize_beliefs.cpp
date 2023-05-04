#include "headers/initialize_beliefs.h"

using namespace std;

vector< vector <float> > initialize_beliefs(vector<vector<char>> const grid) {
	int height = grid.size();
	int width = grid[0].size();


	return vector<vector<float>>(height, 
								vector<float>(width, 
												1.0 / (float(width * height))));

	
}