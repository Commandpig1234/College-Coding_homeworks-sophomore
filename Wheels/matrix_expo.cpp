#include <iostream>
using namespace std;

const int N = 4;

struct Matrix {
    long long a[N][N];
};

/* 矩阵乘法 */
Matrix multiply(const Matrix& A, const Matrix& B) {
    Matrix C = {};
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                C.a[i][j] += A.a[i][k] * B.a[k][j];
    return C;
}

/* 输出矩阵 */
void printMatrix(const Matrix& A) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << A.a[i][j] << " ";
        cout << endl;
    }
}

/* 单位矩阵 */
Matrix identity() {
    Matrix I = {};
    for (int i = 0; i < N; i++)
        I.a[i][i] = 1;
    return I;
}

int main() {
    Matrix A;

    // 输入矩阵
    // cout << "请输入 4x4 初始矩阵（按行输入）：\n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A.a[i][j];

    // A^2, A^3, A^4
    Matrix A2 = multiply(A, A);
    Matrix A3 = multiply(A2, A);
    Matrix A4 = multiply(A3, A);

    cout << "\nA^2 =\n";
    printMatrix(A2);

    cout << "\nA^3 =\n";
    printMatrix(A3);

    cout << "\nA^4 =\n";
    printMatrix(A4);
    system("pause");
    return 0;
}
