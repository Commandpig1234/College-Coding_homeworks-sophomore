#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    priority_queue<ll,vector<ll>,greater<ll>> frequency;
    while(n--){
        ll freq;
        cin >> freq;
        frequency.push(freq);
    }
    ll wpl = 0;
    while(frequency.size() > 1){
        ll freq1 = frequency.top();
        frequency.pop();
        ll freq2 = frequency.top();
        frequency.pop();

        ll sum = freq1 + freq2;
        frequency.push(sum);
        wpl += sum;

    }
    cout << "WPL=" << wpl << endl;
    return;
}

int main(){
    // freopen("input/2.txt","r",stdin);

    solve();

    freopen("CON","r",stdin);
    system("pause");
}