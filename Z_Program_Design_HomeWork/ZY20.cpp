#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll,int>plat;
ll A,B;

pair<ll, int> burn(ll l, ll r)
{
    auto iter_start = plat.lower_bound(l);
    if (iter_start == plat.end() || iter_start->first > r)
    {
        return {A, 0};
    }

    if (l == r)
    {
        int men = plat[l];
        ll cost = B * 1 * men;
        return {cost, men};
    }

    ll mid = l + (r - l) / 2;
    pair<ll, int> left_result = burn(l, mid);
    pair<ll, int> right_result = burn(mid + 1, r);

    int total_men_in_range = left_result.second + right_result.second;

    ll full_cost = B * (r - l + 1) * total_men_in_range;
    
    ll sep_cost = left_result.first + right_result.first;

    return {min(full_cost, sep_cost), total_men_in_range};
}

int main(){

    // freopen("input/ZY20.txt","r",stdin);
    
    int n,k;
    cin >> n >> k >> A >> B;
    for(int i= 0;i<k;i++)
    {
        ll pos;
        cin >> pos;
        plat[pos]++;
    }
    ll num = 1LL << n;
    pair<ll,int> cost = burn(1,num);
    cout << cost.first << endl;

    // freopen("CON","r",stdin);
    // system("pause");
}