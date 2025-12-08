#include <iostream>
#include <vector>
using namespace std;

// Lomuto Partition：用 A[l] 作为 pivot，将 A[l..r] 划分
int LomutoPartition(vector<int>& A, int l, int r) {
    int p = A[l];  // pivot
    int s = l;

    for (int i = l + 1; i <= r; i++) {
        if (A[i] < p) {
            s = s + 1;
            swap(A[s], A[i]);
        }
    }

    swap(A[l], A[s]);
    return s;  // pivot 的最终位置
}

// Quickselect：返回 A[l..r] 中第 k 小元素
int Quickselect(vector<int>& A, int l, int r, int k) {
    // k 是 1-based：1 ≤ k ≤ r-l+1

    int s = LomutoPartition(A, l, r);

    // pivot 恰好是第 k 小
    if (s == l + k - 1)   
        return A[s];

    // pivot 在第 k 小的后面 → 递归左侧
    else if (s > l + k - 1)
        return Quickselect(A, l, s - 1, k);

    // pivot 在第 k 小的前面 → 递归右侧
    else
        return Quickselect(A, s + 1, r, k - (s - l + 1));
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << Quickselect(A, 0, n - 1, k) << endl;
    system("pause");
    return 0;
}
