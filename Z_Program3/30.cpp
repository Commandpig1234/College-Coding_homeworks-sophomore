#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;

const ll LIMIT = 4e18;
vector<ll> tens_powers(1,1);
vector<int> num_digits;

vector<int> getDigits(ll x){
    if (x == 0) return{0};
    vector<int> digits;
    while (x > 0){
        digits.push_back(x % 10);
        x /= 10;
    }
    reverse(digits.begin(), digits.end());
    return digits;
}

ll count_num(ll limit, ll num){
    ll count = 0;
    vector<int> limit_digits = getDigits(limit);

    for (size_t length = 1; length < num_digits.size(); length++){
        ll m_prefix = num / tens_powers[num_digits.size() - length];
        count += m_prefix - tens_powers[length - 1] + 1;
    }

    for (size_t length = num_digits.size(); length <= limit_digits.size(); length++){
        ll m_shifted_prefix = num * tens_powers[length - num_digits.size()];

        ll upper_bound = m_shifted_prefix;
        if (length != num_digits.size()){
            ll next_prefix = (num + 1) * tens_powers[length - num_digits.size()];
            if (next_prefix / tens_powers[length - num_digits.size()] != (num + 1)){
                upper_bound = LIMIT;
            }
            else{
                upper_bound = next_prefix - 1;
            }
        }
        upper_bound = min(limit, upper_bound);
        
        ll start_length = tens_powers[length - 1];
        
        if (upper_bound >= start_length){
            count += upper_bound - start_length + 1;
        }
    }
    return count;
}


void solve(){
    ll num, seq;
    cin >> num >> seq;

    for (int i = 1; i <= 18; ++i){
        tens_powers.push_back(tens_powers.back() * 10);//{1，10，100，1000，……}
    }
    
    num_digits = getDigits(num);

    if (count_num(num, num) > seq){
        cout << 0 << endl;
        return;
    }

    ll low = num;
    ll high = LIMIT;
    ll result_N = 0;

    while (low <= high){
        ll mid = low + (high - low) / 2;

        if (count_num(mid, num) >= seq){
            result_N = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    cout << result_N << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input/30.txt","r",stdin);

    solve();

    freopen("CON","r",stdin);
    system("pause");
    return 0;
}