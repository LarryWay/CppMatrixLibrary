#include <iostream>
#include "Mat.cpp"
#include <array>


int main(){

    Matrix<2,3> m{{{1,2,3},{4,5,6}}};
    Matrix<2,3> n{{{1,2,3},{4,5,6}}};

    //std::cout << (m+n)[0][0] << std::endl;

    Matrix<2,3> a;
    //a.operator=(m + n);
    a = m + n;

    std::cout << "------------------ END OF PROGRAM ------------------" << std::endl;





}