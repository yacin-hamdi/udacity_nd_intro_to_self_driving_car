import pdb
from helpers import normalize, blur

def initialize_beliefs(grid):
    height = len(grid)
    width = len(grid[0])
    area = height * width
    belief_per_cell = 1.0 / area
    beliefs = []
    for i in range(height):
        row = []
        for j in range(width):
            row.append(belief_per_cell)
        beliefs.append(row)
    return beliefs

def sense(color, grid, beliefs, p_hit, p_miss):
    new_beliefs = [[0 for i in range(len(grid[0]))]for j in range(len(grid))]
    
    #
    # TODO - implement this in part 2
    #
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            hit = grid[i][j] == color
            new_beliefs[i][j] = beliefs[i][j] * ((hit * p_hit) + (1-hit) * p_miss)
            
    sum_row = 0
    for i in new_beliefs:
        sum_row += sum(i)
    return [[new_beliefs[j][i]/sum_row for i in range(len(grid[0]))] for j in range(len(grid))]

def move(dy, dx, beliefs, blurring):
    height = len(beliefs)
    width = len(beliefs[0])
    #print('height', height)
    #print('width', width)
    new_G = [[0.0 for i in range(width)] for j in range(height)]
    #print('new_G', new_G)
    for i, row in enumerate(beliefs):
        new_i = 0
        for j, cell in enumerate(row):
            new_i = (i + dy ) % height
            new_j = (j + dx ) % width
            #pdb.set_trace()
            new_G[int(new_i)][int(new_j)] = beliefs[i][j]
    return blur(new_G, blurring)