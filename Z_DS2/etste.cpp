#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <chrono>

// 定义矩阵类型，方便使用
using Matrix = std::vector<std::vector<double>>;
using Vector = std::vector<double>;

// 函数：打印矩阵
void printMatrix(const Matrix& mat) {
    for (const auto& row : mat) {
        for (double val : row) {
            std::cout << std::fixed << std::setprecision(4) << std::setw(12) << val;
        }
        std::cout << std::endl;
    }
}

// 函数：打印向量
void printVector(const Vector& vec, const std::vector<std::string>& labels) {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << "  " << labels[i] << " = " << std::fixed << std::setprecision(6) << vec[i] << std::endl;
    }
}

// 主函数：执行高斯消元法求解线性方程组
Vector gaussianElimination(Matrix A, Vector b) {
    int n = A.size();

    // 构建增广矩阵
    for (int i = 0; i < n; ++i) {
        A[i].push_back(b[i]);
    }

    // --- 前向消元 ---
    for (int i = 0; i < n; ++i) {
        // 部分主元法：寻找当前列的最大主元
        int max_row = i;
        for (int k = i + 1; k < n; ++k) {
            if (std::abs(A[k][i]) > std::abs(A[max_row][i])) {
                max_row = k;
            }
        }
        // 交换行，将最大主元所在行换到当前行
        std::swap(A[i], A[max_row]);

        // 对当前主元下的所有行进行消元
        for (int k = i + 1; k < n; ++k) {
            double factor = A[k][i] / A[i][i];
            for (int j = i; j < n + 1; ++j) {
                A[k][j] -= factor * A[i][j];
            }
        }
    }

    // -- 输出2：打印消元后的上三角矩阵 --
    std::cout << "\n2. A消元后的上三角矩阵:" << std::endl;
    // 提取上三角部分进行打印
    Matrix upperTriangular(n, Vector(n));
    for(int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            upperTriangular[i][j] = A[i][j];
        }
    }
    printMatrix(upperTriangular);


    // --- 反向代入 ---
    Vector x(n);
    for (int i = n - 1; i >= 0; --i) {
        double sum = 0.0;
        for (int j = i + 1; j < n; ++j) {
            sum += A[i][j] * x[j];
        }
        x[i] = (A[i][n] - sum) / A[i][i];
    }

    return x;
}

int main() {
    const int N_POINTS = 5;
    std::vector<std::pair<double, double>> points(N_POINTS);

    points[0].first = -2.3120,points[0].second = 0.5027;
    points[1].first = 2.0610,points[1].second = -1.2570;
    points[2].first = -0.8545,points[2].second = -2.9150;
    points[3].first = -3.5190,points[3].second = -1.1560;
    points[4].first = 2.8150,points[4].second = -2.8150;

    // 构建系数矩阵A和常数向量b
    Matrix A(N_POINTS, Vector(N_POINTS));
    Vector b(N_POINTS);

    for (int i = 0; i < N_POINTS; ++i) {
        double x = points[i].first;
        double y = points[i].second;
        A[i][0] = x * y;      // a的系数
        A[i][1] = y * y;      // b的系数
        A[i][2] = x;          // c的系数
        A[i][3] = y;          // d的系数
        A[i][4] = 1.0;        // e的系数
        b[i] = -x * x;
    }

    // -- 输出1：打印原始系数矩阵 --
    std::cout << "\n1. A系数矩阵:" << std::endl;
    printMatrix(A);

    // --- 计时并求解 ---
    auto start_time = std::chrono::high_resolution_clock::now();
    
    Vector coeffs = gaussianElimination(A, b);
    
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed_time = end_time - start_time;

    // -- 输出3：打印求得的椭圆方程系数 --
    std::cout << "\n3. 求得的椭圆方程系数 (x^2 + axy + by^2 + cx + dy + e = 0):" << std::endl;
    std::vector<std::string> labels = {"a", "b", "c", "d", "e"};
    printVector(coeffs, labels);
    
    // -- 输出4：打印求解时间 --
    std::cout << "\n4. 求解方程所用的时间:" << std::endl;
    std::cout << "  " << std::fixed << std::setprecision(6) << elapsed_time.count() << " 毫秒 (ms)" << std::endl;

    system("pause");
    return 0;
}