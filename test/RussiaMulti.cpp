#include <iostream>
using namespace std;

long long russianMultiply(long long n, long long m) {
    // 基本情况
    if (n == 1)
        return m;

    // n 为偶数
    if (n % 2 == 0) {
        return russianMultiply(n / 2, m * 2);
    }
    // n 为奇数
    else {
        return russianMultiply((n - 1) / 2, m * 2) + m;
    }
}

int main() {
    long long n, m;
    cin >> n >> m;

    cout << russianMultiply(n, m) << endl;
    system("pause");
    return 0;
}
