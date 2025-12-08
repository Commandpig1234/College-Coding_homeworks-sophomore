#include <iostream>
#include <vector>
using namespace std;

int interpolationSearch(const vector<int>& A, int key) {
    int l = 0, r = A.size() - 1;

    while (l <= r && key >= A[l] && key <= A[r]) {

        // 防止除 0（当 A[l] == A[r] 时无法插值）
        if (A[l] == A[r]) {
            if (A[l] == key) return l;
            else return -1;
        }

        // 插值公式
        int mid = l + (long long)(key - A[l]) * (r - l) / (A[r] - A[l]);

        if (A[mid] == key)
            return mid;
        else if (A[mid] < key)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return -1; // not found
}

int main() {
    int n, key;
    cin >> n;
    vector<int> A(n);

    for (int i = 0; i < n; i++)
        cin >> A[i];

    cin >> key;

    int pos = interpolationSearch(A, key);

    if (pos != -1)
        cout << "Found at index " << pos << endl;
    else
        cout << "Not found" << endl;
    system("pause");

    return 0;
}
