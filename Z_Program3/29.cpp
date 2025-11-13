#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve(){
    int N;
    cin >> N;
    vector<int> powers(N), costs(N);
    
    for (int i = 0; i < N; ++i)
        cin >> powers[i];
    for (int i = 0; i < N; ++i)
        cin >> costs[i];
    sort(powers.begin(), powers.end());
    sort(costs.begin(), costs.end());

    ull total_cost = 0;
    vector<int> difs;
    vector<int> spaces;
    
    for (int i = 0; i < N; ++i){
        int j = i+1;
        while (j < N && powers[j] - powers[i] < j - i)//有重叠
            j++;
        //找到空白;冲突段为 i~j-1，共(j-1)-(i-1)个数（j-i）
        int top = powers[i] + (j - i - 1);
        for (int k = j-1; k >= i; k--){
            while (top >= powers[k])
                spaces.push_back(top--);
            int cur_space = spaces.back() - powers[k];
            spaces.pop_back();
            difs.push_back(cur_space);
        }
        i = j - 1;
    }
    sort(difs.begin(), difs.end(), greater<int>());//降序
    for (int i = 0; i < difs.size(); ++i)
        total_cost += 1ll * difs[i] * costs[i];
    cout << total_cost << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input/29.txt","r",stdin);

    solve();

    freopen("CON","r",stdin);
    system("pause");
    return 0;
}