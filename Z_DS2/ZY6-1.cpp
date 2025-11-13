#include <iostream>

using namespace std;

using ll = long long;

ll nodes,level;

ll QExpo(ll a,int b){
    ll ans = 1;
    while(b){
        if(b&1)
            ans *= a;
        if(ans > 1e9 || a > 1e9)
            return 1e9;
        a *= a;
        b >>= 1;
    }
    return ans;
}

int canPut(int x){
    int dep = 0;
    ll total = 0;
    while(x > 1){
        dep++;
        total += x;
        x = (x+1)/2;
    }
    total += level - dep +1;
    return (total <= nodes);
}

ll solve(){
    cin >> nodes >> level;
    if(nodes <= level || nodes == 0)
        return 0;
    
    if(QExpo(2,level+1) - 1 >= nodes){
        int l = 0,r = nodes,ans = 0;

        while(l <= r){
            int mid = (l+r) / 2;
            if(canPut(mid)){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid -1;
            }
        }
        return ans;
    }
    else
        return 1 << level;

}

int main(){
    // freopen("input/ZY6-1.txt","r",stdin);

    int T;
    cin >> T;
    while(T--)
        cout << solve() << endl;
    

    freopen("CON","r",stdin);
    system("pause");
}