#include <iostream>
using namespace std;

int josephus(int n, int m) {
    int result = 0; // f(1)=0
    for (int i = 2; i <= n; ++i) {
        result = (result + m) % i;
    }
    return result + 1; // 转为 1-based 编号
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << josephus(n, m) << endl;
    system("pause");
    return 0;
}
