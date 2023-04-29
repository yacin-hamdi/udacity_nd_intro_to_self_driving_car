#include "matrix.h"


Matrix::Matrix(){
    std::vector<std::vector<float>> grid(5, std::vector<float>(5,0.5));
    this->grid_ = grid;
    this->rows_ = grid.size();
    this->cols_ = grid[0].size();
}

Matrix::Matrix(std::vector<std::vector<float>> grid){
    this->grid_ = grid;
    this->rows_ = grid.size();
    this->cols_ = grid[0].size();
}

void Matrix::setGrid(std::vector<std::vector<float>> grid){
    this->grid_ = grid;
    this->rows_ = grid.size();
    this->cols_ = grid[0].size();
}


std::vector<std::vector<float>> Matrix::getGrid(){
    return this->grid_;
}


std::vector<float>::size_type Matrix::getRows(){
    return this->rows_;
}

std::vector<float>::size_type Matrix::getCols(){
    return this->cols_;
}


/* TODO: Define a matrix_addition function
**   INPUT: a matrix
**   OUPUT: the sum of the grid variable and the input matrix
**
** STEPS:
**  1. check that the matrix in the grid variable
**     and the input matrix have the same size
**
**     if not, throw an error like
**         throw std::invalid_argument("matrices are not the same size");
**
** 2. add the matrices together and return
**       the result as a Matrix. You can do this part
**       with nested for loops. If you use an intermediate
**       vector to store a row, the vector.clear() 
**       method might be useful.
**
*/

Matrix Matrix::matrix_addition(Matrix grid2){
    if(this->rows_ == grid2.getRows() and this->cols_ == grid2.getCols()){
        std::vector<std::vector<float>> sum(this->rows_, std::vector<float>(this->cols_, 0));
        for(int i = 0; i < this->rows_; i++){
            for(int j = 0; j < this->cols_; j++){
                sum[i][j] = this->grid_[i][j] + grid2.getGrid()[i][j];
            }
        }
        return Matrix(sum);
    }else{
        throw std::invalid_argument("matrices are not the same size");
    }
    return Matrix();
    
}

/* TODO: Define a matrix_print function
** This function has no inputs and no outputs
** The purpose of the function is to display the matrix in
** the terminal using std::cout. 
**
**
** The output should look something like:
** 4    9   1   10
** 5    11  6   17
** 8    4   15  2
*/

void Matrix::matrix_print(){
    for(int i=0;i<this->rows_;i++){
        for(int j=0; j<this->cols_;j++){
            std::cout << this->grid_[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

Matrix Matrix::matrix_transpose(){
    std::vector<std::vector<float>> trans(this->cols_, std::vector<float>(this->rows_, 0));
    for(int i = 0; i < this->rows_; i++){
        for(int j = 0; j < this->cols_; j++){
            trans[j][i] = this->getGrid()[i][j];
        }
    }
    return Matrix(trans);
}


