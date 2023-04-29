#include"matrix.h"


int main(){
    Matrix mat({{1,2,1},
                 {4,1,3}});

    mat.matrix_print();
    std::cout << "-------------------\n";

    Matrix mat3 = mat.matrix_addition(mat);
    mat3.matrix_print();

    std::cout << "-------------------\n";

    mat3 = mat3.matrix_transpose();
    mat3.matrix_print();


}