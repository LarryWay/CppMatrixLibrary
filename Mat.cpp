#define _rows r;
#define _cols c;
#define _size r*c

template <int r, int c>
struct Matrix{

    int arr[r][c];



    //Terrible. 
    Matrix<r,c> operator+(const Matrix<r,c>& m){
        Matrix<r,c> M_return;
        int* ptr;

        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                ptr = &(M_return[i][j]);
                *ptr = arr[i][j] + m.arr[i][j];
            }
        }
        return M_return;
    }




    //Element Access - Not very secure, but doesn't really have to be
    int* operator[](size_t n) {return arr[n];}


    //public getters
    std::size_t size() const {return _size;}
    int rows() const {return _rows;}
    int cols() const {return _cols;}


};



/*
NOTES: 
    Using implicitely defined special member functions -
        Default Constructor: Nice and readable constructor. Syntax is a bit off
        Copy Constructor: Shallow copies the arguement's pointer. Pointer sharing - not good
        Destructor: No comments
        Move Constructor: Works, but cannot be used in tangent with the operator+() function. 
        Copy Assignment: No comments

*/