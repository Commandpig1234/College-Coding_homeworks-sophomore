#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (size_t i = 0; i < row.size(); ++i) {
            cout << row[i] << (i == row.size() - 1 ? "" : " ");
        }
        cout << endl;
    }
    return;
}

void computeTransitiveClosure(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 0) return;
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = matrix[i][j] || (matrix[i][k] && matrix[k][j]);
            }
        }
    }
    return;
}

void solve(){
    vector<vector<int>> matrix;
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        vector<int> row;
        int data;
        while (ss >> data) {
            row.push_back(data);
        }
        if (!row.empty()) {
            matrix.push_back(row);
        }
    }

    computeTransitiveClosure(matrix);
    printMatrix(matrix);
    return;
}

int main(){
    // freopen("input/3.txt","r",stdin);

    solve();

    freopen("CON","r",stdin);
    system("pause");
    return 0;
}