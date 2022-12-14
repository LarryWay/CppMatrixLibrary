#include "MatA.cpp"
#include <iostream>
#include <array>





int main(){

    std::array<int, 4> mArr{4,3,2,1};

    Matrix<2,2> m = {mArr};
    Matrix<2,2> n{{1,2}, {3,4}};
    Matrix<2,2> o = m;
    Matrix<2,2> p{n};
    
    std::cout << "--- END OF PROGRAM ---" << std::endl;



}
