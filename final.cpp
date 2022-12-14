#include "MatA.cpp"
#include <iostream>
#include <array>
#include <initializer_list>





int main(){

    Matrix<2,2> m = Matrix<2,2>{{1,2}, {3,4}};
    Matrix<2,2> n{{1,2}, {3,4}};
    Matrix<2,2> z{Matrix<2,2>{{1,2}, {3,4}}};

    Matrix<2,2> o = m + n;

    //Matrix<2,2> n = m;
    std::cout << o[0][1] << "\n";
    
}
