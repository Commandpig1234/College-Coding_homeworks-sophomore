#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const double phi = (1+sqrt(5)) / 2;
const double PHI = phi*phi;

typedef unsigned long long ull;
typedef long long ll;

ll i,j,m;
ll ans[2][2] = {{1,0},
                {0,1}};

void matrix_multi(ll A[2][2],ll B[2][2]){
    ll temp[2][2];
    temp[0][0] = A[0][0] * B[0][0] % m + A[0][1] * B[1][0] % m;
    temp[0][1] = A[0][0] * B[0][1] % m + A[0][1] * B[1][1] % m;
    temp[1][0] = A[1][0] * B[0][0] % m + A[1][1] * B[1][0] % m;
    temp[1][1] = A[1][0] * B[0][1] % m + A[1][1] * B[1][1] % m;
    A[0][0] = temp[0][0];
    A[0][1] = temp[0][1];
    A[1][0] = temp[1][0];
    A[1][1] = temp[1][1];
    return;
}

void matrix_quick_expo_module(ll a[2][2] ,ll b,ll m){
    while(b > 0){
        if(b & 1){
            matrix_multi(ans,a);
        }
        matrix_multi(a,a);
        b >>= 1;
    }
    return;
}

void solve(){    
    cin >> i >> j >> m;
    ll first = floor(i*PHI) - 1;
    ll second = first*2 - i + 1;
    if(j == 1){
        cout << first % m << endl;
        return;
    }
    if(j == 2){
        cout << second % m << endl;
        return;
    }
    ll a[2][2] = {{1,1},
                  {1,0}};
    matrix_quick_expo_module(a,j-2,m);
    ll result = ((ans[0][0] * second) % m + (ans[0][1] * first) % m) % m;
    cout << result << endl;
    return;

}

int main(){
    // freopen("input/ZY28.txt","r",stdin);

    solve();

    freopen("CON","r",stdin);
    system("pause");
}