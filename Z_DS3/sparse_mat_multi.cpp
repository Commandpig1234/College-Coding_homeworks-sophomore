#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Triple{
    int row;
    int col;
    int val;
};

void solve(){
    int row1, col1, group1;
    cin >> row1 >> col1 >> group1;

    vector<Triple> A(group1);
    for (int i = 0; i < group1; i++){
        cin >> A[i].row >> A[i].col >> A[i].val;
    }

    int row2, col2, group2;
    cin >> row2 >> col2 >> group2;

    cout << row1 << endl;
    cout << col2 << endl;

    vector<Triple> B(group2);
    for (int i = 0; i < group2; i++){
        cin >> B[i].row >> B[i].col >> B[i].val;
    }

    map<int, vector<Triple>> B_row;
    for (auto &b : B){
        B_row[b.row].push_back(b);
    }

    map<pair<int, int>, int> C;

    for (auto &a : A){
        int i = a.row;
        int k = a.col;
        int aval = a.val;

        if (B_row.count(k)){
            for (auto &b : B_row[k]){
                int j = b.col;
                C[{i, j}] += aval * b.val;
            }
        }
    }

    int cnt = 0;
    for (auto &e : C){
        if (e.second != 0) cnt++;
    }
    cout << cnt << endl;

    for (auto &e : C){
        if (e.second != 0){
            cout << e.first.first << ","
                 << e.first.second << ","
                 << e.second << endl;
        }
    }
    return;
}

int main(){
    // freopen("input/sparse_mat_multi.txt","r",stdin);

    solve();

    freopen("CON","r",stdin);
    system("pause");
}