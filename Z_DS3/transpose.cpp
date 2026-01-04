#include <iostream>
#include <vector>

using namespace std;

struct Triple{
    int row;
    int col;
    int val;
};

void solve(){
    int rows, cols, nums;
    cin >> rows >> cols >> nums;

    vector<Triple> A(nums);
    for (int i = 0; i < nums; i++){
        cin >> A[i].row >> A[i].col >> A[i].val;
    }

    vector<int> num(cols + 1, 0);
    vector<int> cpot(cols + 1, 0);

    for (int i = 0; i < nums; i++){
        num[A[i].col]++;
    }

    cpot[1] = 1;
    for (int i = 2; i <= cols; i++){
        cpot[i] = cpot[i - 1] + num[i - 1];
    }

    vector<Triple> B(nums);
    for (int i = 0; i < nums; i++){
        int col = A[i].col;
        int pos = cpot[col];

        B[pos - 1].row = A[i].col;
        B[pos - 1].col = A[i].row;
        B[pos - 1].val = A[i].val;

        cpot[col]++;
    }

    cout << "num:";
    for (int i = 1; i <= cols; i++){
        cout << num[i] << ",";
    }
    cout << endl;

    cpot[1] = 1;
    for (int i = 2; i <= cols; i++){
        cpot[i] = cpot[i - 1] + num[i - 1];
    }

    cout << "cpot:";
    for (int i = 1; i <= cols; i++){
        cout << cpot[i] << ",";
    }
    cout << endl;

    for (int i = 0; i < nums; i++){
        cout << B[i].row << ","
             << B[i].col << ","
             << B[i].val << endl;
    }
    return;
}

int main(){
    // freopen("input/transpose.txt","r",stdin);

    solve();

    freopen("CON","r",stdin);
    system("pause");
}