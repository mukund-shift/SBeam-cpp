// 2. Implement a Matrix class (int rows, int cols, int **mat - dynamically allocated 2-d array).
//  Implement copy ctor, assign operator, matrix addition, insertion and extraction operators.

// matrix[m][n] -> m = rows, n = cols;

#include <iostream>
using namespace std;

class Matrix{
    int rows;
    int cols;
    int** mat;

    public:
    Matrix(int r, int c){
        rows = r;
        cols = c;
        mat = m;
    }
    void display(){
        for (int i = 0; i < cols; i++){
            for (int j = 0; j < rows; j++){
                cout << mat[i][j];
            }
            cout << endl;
        }
    }
};

int main(){
    int** m;
    m[0][0] = 1;

    // Matrix m1(3, 3, m);
}