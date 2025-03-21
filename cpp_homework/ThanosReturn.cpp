#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>
#include <string>
#define mod 10007
const int MAX_N = 102;
class Matrix {
    public:
        Matrix() {
            row = col = 0;
            memset(mat, 0, sizeof(mat));
        }
        // TODO
        Matrix(int r, int c);
        const int &getrow() {
            return row;
        }
        const int &getcol() {
            return col;
        }
        // TODO
        int *operator[] (const int &x);
        const int *operator[] (const int &x) const {
            return mat[x];
        }
        // TODO
        Matrix operator+ (const Matrix &x) const;
        // TODO: note that this function is declared with the keyword "friend"
        friend Matrix operator* (const Matrix &x, const Matrix &y);
        void print() {
            for(int i=0;i<row;i++) {
                if(i==0) std::cout << "/";
                else if(i==row-1) std::cout << "\\";
                else std::cout << "|";
                for(int j=0;j<col;j++) {
                    std::cout << std::right << std::setw(8) << mat[i][j];
                }
                if(i==0) std::cout << " \\\n";
                else if(i==row-1) std::cout << " /\n";
                else std::cout << " |\n";
            }
        }
    private:
        int mat[MAX_N][MAX_N];
        int row, col;
};
// 下面是Matrix的ans
Matrix::Matrix(int r, int c) {
    row = r;
    col = c;
    memset(mat, 0, sizeof(mat));
}

int *Matrix::operator[] (const int &x) {
    return mat[x];
}

Matrix Matrix::operator+ (const Matrix &x)const
{
    Matrix res(row, col);
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            res[i][j] = ((mat[i][j] + x[i][j]) % mod+mod)%mod;
        }
    }
    return res;
}

Matrix operator* (const Matrix &x,const Matrix &y)
{
    Matrix res(x.row, y.col);
    for(int i=0;i<x.row;i++) {
        for(int j=0;j<y.col;j++) {
            for(int k=0;k<x.col;k++) {
                res[i][j] += (x[i][k] * y[k][j])%mod;
                res[i][j] =((res[i][j])%mod+mod)%mod;
            }
            }
    }
    return res;
}


