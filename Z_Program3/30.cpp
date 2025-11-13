#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

using ll = long long;

// 计算在1到n的字典序中，以p为前缀的数字有多少个
ll count_prefix(ll n, ll p) {
    ll count = 0;
    ll p1 = p, p2 = p;

    while (p1 <= n) {
        count += min(n, p2) - p1 + 1;
        
        if (p1 > n / 10) {
            break;
        }
        p1 *= 10;

        if (p2 > (n - 9) / 10) {
            p2 = n;
        } else {
            p2 = p2 * 10 + 9;
        }
    }
    return count;
}

// 计算在1到n的字典序中，严格小于num的数字有多少个
ll count_less(ll n, ll num) {
    string s_num = to_string(num);
    ll ans = 0;
    ll prefix = 0;

    for (size_t i = 0; i < s_num.length(); ++i) {
        int digit = s_num[i] - '0';

        int start_d = (i == 0) ? 1 : 0;

        for (int d = start_d; d < digit; ++d) {
            ans += count_prefix(n, prefix * 10 + d);
        }
        prefix = prefix * 10 + digit;
        
        // 如果当前前缀已经大于n，提前结束
        if (prefix > n) break;
    }
    return ans;
}

void solve(){
    ll num, seq;
    cin >> num >> seq;

    // 特殊情况处理
    if (seq == 1) {
        // 第1个位置必须是1
        if (num == 1) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
        return;
    }

    ll target_count = seq - 1;

    // 二分查找的下界应该是num，因为N必须至少包含num
    ll low = num, high = 1e18; 
    ll ans = 0;

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        
        ll count = count_less(mid, num);

        if (count < target_count) {
            low = mid + 1;
        } else if (count > target_count) {
            high = mid - 1;
        } else {
            // 找到了满足条件的N，但需要检查mid是否>=num
            if (mid >= num) {
                ans = mid;
                high = mid - 1; // 继续寻找更小的解
            } else {
                low = mid + 1;
            }
        }
    }

    if (ans == 0) {
        cout << 0 << endl;
    } else {
        // 最终验证
        if (count_less(ans, num) == target_count && ans >= num) {
            cout << ans << endl;
        } else {
            cout << 0 << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input/30.txt","r",stdin);

    solve();

    freopen("CON","r",stdin);
    system("pause");
    return 0;
}