#include <iostream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll quick_expo(ll a,ll b){
    ll ans = 1;
    while(b > 0){
        if(b & 1){//是奇数
            ans = ans*a;
        }
        a = a*a;
        b >>= 1;
    }
    return ans;
}
ll quick_expo_module(ll a,ll b,ll m){
    ll res = 1;
    a %= m;
    while(b>0){
        if(b & 1){
            res = res * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main(){
    ll a,b,m;
    cin >> a >> b >> m;
    cout << quick_expo(a,b) << endl;
    cout << quick_expo_module(a,b,m) << endl;
    system("pause");
    return 0;
}