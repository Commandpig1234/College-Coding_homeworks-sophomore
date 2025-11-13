#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<ll>datas;
int n;
const int MaxN = 100000;
const int logn = 17;
ll sparse_table[17][100000];

ll query(int l, int r) {
    int k = log2(r - l + 1);
    return sparse_table[k][l] & sparse_table[k][r - (1 << k) + 1];
}

ll FindR(int l,ll k){
    if(datas[l] < k)
        return -1;
    int low = l,high = n,ans = l;
    while(low <= high){
        int mid =low + (high - low)/2;
        if(query(l,mid) >= k){
            low = mid + 1;
            ans = mid;
        }
        else{
            high = mid - 1;
        }
    }

    return ans;
}

void build(int n){
    for(int j = 1;j<=n;j++)
        sparse_table[0][j] = datas[j];
    for(int i = 1;i<logn;i++){
        for(int j = 1;j + (1 << i) - 1 <= n;j++){
            sparse_table[i][j] = sparse_table[i-1][j] & sparse_table[i-1][j + (1 << (i-1))];
        }
    }
}

void solve(){
    int q;
    cin >> n;
    datas.resize(n+1);
    for(int i=1;i<=n;i++)
        cin >> datas[i];
    build(n);
    cin >> q;
    int l;
    ll k;
    while(q--){
        cin >> l >> k;
        cout << FindR(l,k) << " ";
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("input/31.txt","r",stdin);
    solve();

    freopen("CON","r",stdin);
    system("pause");
}