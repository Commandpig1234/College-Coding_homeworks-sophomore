#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;

const ll LIMIT = 4e18; // 设定一个足够大的上界
vector<ll> tens_powers(1, 1);

// getDigits 函数保持不变
vector<int> getDigits(ll x) {
    if (x == 0) return {0};
    vector<int> digits;
    while (x > 0) {
        digits.push_back(x % 10);
        x /= 10;
    }
    reverse(digits.begin(), digits.end());
    return digits;
}

// ==========================================================
// 核心修正：替换 count_num 函数
// ==========================================================

// 辅助函数：计算在 [1, limit] 范围内，字典序在 [n1, n2) 之间的数字有多少个。
// 这是新逻辑的核心组件。
ll count_nodes_between(ll n1, ll n2, ll limit) {
    ll count = 0;
    while (n1 <= limit) {
        count += min(limit + 1, n2) - n1;

        // 安全地进行乘法，防止溢出
        if (n1 > limit / 10) break;
        n1 *= 10;

        if (n2 > LIMIT / 10) { // 如果 n2*10 可能溢出
            n2 = LIMIT;
        } else {
            n2 *= 10;
        }
    }
    return count;
}

// 新的、正确的计数函数
// 功能：计算在 [1, limit] 范围内，字典序小于或等于 M 的数字有多少个
ll count_le_m(ll limit, ll M) {
    string sM = to_string(M);
    ll count = 0;

    // --- 步骤1：计算所有字典序严格小于 M 的数 ---
    // 通过遍历 M 的前缀，累加所有“左兄弟”分支上的节点数
    ll prefix = 0;
    for (size_t i = 0; i < sM.length(); ++i) {
        int digit = sM[i] - '0';
        for (int d = 0; d < digit; ++d) {
            if (i == 0 && d == 0) continue; // 第一个数字不能是 0
            
            ll n1 = prefix * 10 + d;
            ll n2 = n1 + 1;
            count += count_nodes_between(n1, n2, limit);
        }
        prefix = prefix * 10 + digit;
    }

    // --- 步骤2：计算 M 自身和以 M 为前缀的所有后代 ---
    // 这些数在字典序上等于或紧跟在 M 之后
    count += count_nodes_between(M, M + 1, limit);

    return count;
}


void solve() {
    ll target_num, target_seq;
    cin >> target_num >> target_seq;

    // 预计算10的幂（尽管在新逻辑中不直接用，但保留无害）
    for (int i = 1; i <= 18; ++i) {
        tens_powers.push_back(tens_powers.back() * 10);
    }
    
    // 快速无解判断
    // 调用新的计数函数 count_le_m
    if (count_le_m(target_num, target_num) > target_seq) {
        cout << 0 << endl;
        return;
    }

    // 二分搜索框架保持不变
    ll low = target_num;
    ll high = LIMIT;
    ll result_N = 0;

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (mid == 0) { // 防止 mid 意外变成 0
             low = 1;
             continue;
        }

        // 调用新的计数函数 count_le_m
        if (count_le_m(mid, target_num) >= target_seq) {
            result_N = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << result_N << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input/30.txt", "r", stdin);

    solve();

    freopen("CON", "r", stdin);
    system("pause");
    return 0;
}