#include <iostream>
#include <algorithm>
#include <array>
#include <initializer_list>


struct SubMat{

    int* ptr;
    int size;

    SubMat(int* p, int column_size) : ptr(p), size(column_size) { printf("SubMat created\n");}

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


    Matrix(const std::array<int, r * c>& arr){  // COPY ARRAY CONSTRUCTOR
        std::copy(arr.begin(), arr.end(), m_Data.begin());
        printf("Copy Array\n");
    }


    Matrix(std::initializer_list<std::array<int, c>>&& ini){  // INITIALIZER_LIST CONSTRUCTOR
        if(ini.size() != r){ printf("Invalid Size\n");}

        int pos = 0;
        for(auto it_r = ini.begin() ; it_r != ini.end() ; it_r++){
            for(auto it_c = it_r->begin() ; it_c != it_r->end() ; it_c++){
                m_Data[pos] = *(it_c);
                pos++;
            }
        }
        
        printf("Initialize_list constructor\n");
    }


    Matrix(Matrix<r,c>&& m) = delete;  // DELETED MOVE CONSTRUCTOR


    ~Matrix(){printf("Deleted\n");}


    Matrix& operator=(const Matrix<r,c>& m){  // COPY ASSIGNMENT OPERATOR
        std::copy(m.m_Data.begin(), m.m_Data.end(), m_Data.begin());
        printf("copy assignment\n");
        return *this;
    } 


    Matrix& operator=(Matrix<r,c>&& m) = delete;  // DELTED MOVE OPERATOR


    Matrix operator+(const Matrix<r,c>& m) {
        std::array<int, r * c> tempArr;
        for(int x = 0 ; x < (r * c) ; x++){
            tempArr[x] = m.m_Data[x] + m_Data[x];
        }
        Matrix<r,c> returnMatrix{tempArr};
        return returnMatrix;
    } 


    SubMat operator[](int index){
        if(index >= r){printf("BAD ROW SIZE\n");}
        return SubMat((&m_Data[0] + (r * index)), c);
    }


    size_t size(){
        return (r * c);
    }

    int rows(){
        return r;
    }

    int cols(){
        return c;
    }



};