#include <iostream>
#include <algorithm>
#include <array>
#include <initializer_list>


struct SubMat{

    int* ptr;
    int size;
    int cnt;

    SubMat(int* p, int column_size) : ptr(p), size(column_size) { printf("SubMat created!\n");}

    int operator[](int index){
        if(index >= size) { 
            printf("INVALID INDEX");
            return -1;
        }
        return *(ptr + index);
    }

};




template <int r, int c>
struct Matrix{

    std::array<int, r * c> m_Data;

    Matrix(){  // DEFAULT CONSTRUCTOR
        std::fill(m_Data.begin(), m_Data.end(), 0);
        printf("Default contructor\n");
    }

    Matrix(const Matrix<r,c>& m){  // COPY CONSTRUCTOR
        std::copy(m.m_Data.begin(), m.m_Data.end(), m_Data.begin());
        printf("Copy Constructor\n");
    }

    Matrix(Matrix<r,c>&& m) : m_Data(std::move(m.m_Data)) {
        printf("I DID SOME SHIT YEAHHHH");
     } // TODO - MOVE CONSTRUCTOR

    Matrix(const std::array<int, r * c>& arr){
        std::copy(arr.begin(), arr.end(), m_Data.begin());
        printf("Copy Array\n");
    }

    Matrix(std::initializer_list<std::array<int, c>>&& ini){
        if(ini.size() != r){ printf("Invalid Size\n");}

        int pos = 0;
        for(auto it_r = ini.begin() ; it_r != ini.end() ; it_r++){
            for(auto it_c = it_r->begin() ; it_c != it_r->end() ; it_c++){
                m_Data[pos] = *(it_c);
                //std::cout << m_Data[pos] << "\t";
                pos++;
            }
        }
        //std::cout << "\n";

        printf("Initializer\n");

    }

    ~Matrix(){printf("Deleted\n");}

    Matrix& operator=(const Matrix<r,c>& m){
        std::copy(m.m_Data.begin(), m.m_Data.end(), m_Data.begin());
        printf("Copy operator\n");
        return *this;
        
    } 

    Matrix& operator=(Matrix<r,c>&& m){
        delete m_Data;
        m_Data = m.m_Data;
        m.m_Data = nullptr;
        printf("Move operator\n");
        return *this;
        

    }

    Matrix operator+(const Matrix<r,c>& m) {
        std::array<int, r * c> tempArr;
        for(int x = 0 ; x < (r * c) ; x++){
            tempArr[x] = m.m_Data[x] + m_Data[x];
        }
        return Matrix<r,c>{tempArr};
    } 



    SubMat operator[](int index){
        if(index >= r){printf("BAD ROW SIZE\n");}
        return SubMat((&m_Data[0] + (r * index)), c);
    }







};