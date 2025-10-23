#include <iostream>
#include<vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    // freopen("input/ZY22.txt","r",stdin);

    int n=0;
    cin >> n;
    vector<vector<double> > matrix(n, vector<double>(n+1, 0));

    for(int i=0;i<n;i++){
        for(int j =0;j<=n;j++){
            int input = 0;
            cin >> input;
            matrix[i][j] = input;
        }
    }

    for(int col = 0;col<n;col++){
        int pivot = col;
        for(int i = col+1;i<n;i++){
            if(abs(matrix[i][col]) > abs(matrix[pivot][col])){
                pivot = i;
            }
        }
        if(pivot != col)
            swap(matrix[col],matrix[pivot]);

        if(abs(matrix[col][col]) < 0.00001){
            cout << "No Solution" << endl;
            return 0;
        }

        for (int i = col + 1; i < n; ++i) {
            double factor = matrix[i][col] / matrix[col][col];
            for (int j = col; j < n + 1; ++j) {
                matrix[i][j] -= factor * matrix[col][j];
            }
        }
    }
    vector<double> results(n);
    for(int i = n-1;i>=0;i--){
        double sum = matrix[i][n];
        for(int j = i+1;j<n;j++){
            sum -= matrix[i][j] * results[j];
        }
        results[i] = sum / matrix[i][i];
    }
    cout << fixed << setprecision(2);
    for(int i =0;i<n;i++){
        cout << results[i] << endl;
    }

    // freopen("CON","r",stdin);

    system("pause");
    return 0;
}