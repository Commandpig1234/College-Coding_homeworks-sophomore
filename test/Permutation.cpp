#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 手动实现 "生成下一个字典序排列"
// 返回 true 表示成功生成下一排列；返回 false 表示已经是最后一项
bool nextPermutation(vector<int>& a) {
    int n = a.size() -1;

    // 1. 找到最后一个满足 a[i] < a[i+1] 的 i
    int i = n - 1;
    while (i >= 1 && a[i] >= a[i+1]) {
        i--;
    }
    if (i < 1)
        return false;   // 已经到达最大排列（完全降序）

    // 2. 找到最后一个满足 a[j] > a[i] 的 j
    int j = n;
    while (j > i && a[j] <= a[i]) {
        j--;
    }

    // 3. 交换 a[i] 和 a[j]
    swap(a[i], a[j]);

    // 4. 反转 a[i+1 .. n-1] 使之成为升序
    reverse(a.begin() + i + 1, a.end());

    return true;
}

int main() {
    int n;
    cin >> n;

    // 初始排列：1,2,3,...,n
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i)
        a[i] = i;

    // 输出第一条排列
    do {
        for (int x : a){
            if (x==0) continue;
            cout << x << " ";
        }
        cout << "\n";
    } while (nextPermutation(a)); // 按图中算法生成下一排列并输出
    system("pause");
    return 0;
}
