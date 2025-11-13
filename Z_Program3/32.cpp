#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

void solve(){
    int n;
    cin >> n;
    if(n == 0){
        cout << 0 << endl;
        return;
    }
    vector<int> p(n+1);
    for(int i=1;i<=n;i++)
        cin >> p[i];

    vector<ll> dp(n+1,0);

    dp[n] = 1;
    ll total_sum = 1;

    for(int i = n-1;i>=1;i--){
        if(p[i] > p[i+1]){
            dp[i] = 1 + n-i + dp[i+1];
        }
        else{
            dp[i] = 1 + dp[i+1];
        }
        total_sum += dp[i];
    }
    cout << total_sum << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("input/32.txt","r",stdin);
    
    int t;
    cin >> t;
    while(t--)
        solve();

    freopen("CON","r",stdin);
    system("pause");
}