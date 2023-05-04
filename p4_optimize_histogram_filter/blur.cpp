#include "headers/blur.h"

using namespace std;

vector < vector <float> > blur(vector < vector < float> > grid, float blurring) {

	int height = grid.size();
	int width = grid[0].size();
	float center_prob = 1.0-blurring;
	float adjacent_prob = blurring/6.0;
	float corner_prob = blurring/12.0;
	vector<vector<float>> window {{corner_prob, adjacent_prob, corner_prob},
									{adjacent_prob, center_prob, adjacent_prob},
									{corner_prob, adjacent_prob, corner_prob}};

	vector<vector<float>> newGrid(height, vector<float>(width, 0));

	for (int i = 0;i<window.size();i++){
		for(int j = 0; j < window[0].size();j++){
			for(int dx = -1; dx < 2; dx++){
				for(int dy = -1; dy < 2; dy++){
					 float mul = window[dx+1][dy+1];
					 int new_x = (i+dx+height)%height;
					 int new_y = (j+dy+width)%width;
					 newGrid[new_x][new_y] += mul * grid[i][j];

				}
			}
		}
		
	}
	
	// your code here

	return newGrid;
}
