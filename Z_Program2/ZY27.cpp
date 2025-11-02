#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<int> firewoods;
int num;
ull len;
vector<bool> used(num,false);

bool dfs(int branch_left, int current_len, int start_index){
    if (branch_left == 0){
        return true;
    }

    if (current_len == len){//一根就够
        return dfs(branch_left - 1, 0, 0);
    }

    for (int i = start_index; i < num; i++){
        if (!used[i] && current_len + firewoods[i] <= len){
            if (i > 0 && !used[i - 1] && firewoods[i] == firewoods[i - 1]){//相同长度不行
                continue;
            }
            
            used[i] = true;// 用上这根
            
            if (dfs(branch_left, current_len + firewoods[i], i + 1)){//递归
                return true;
            }
            used[i] = false;//递归返回false，这一根不行

            if (current_len == 0 || current_len + firewoods[i] == len){
                return false;
            }
        }
    }
    return false;
}

void solve(){
    int max_len = 0;
    ull total_len =0;
    cin >> num;
    firewoods.resize(num);
    for(int i = 0;i<num;i++){
        int input;
        cin >> input;
        firewoods[i] = input;
        total_len += input;
        if(input>max_len) max_len = input;
    }
    sort(firewoods.begin(),firewoods.end(),greater<int>());

    for(len = max_len;len <= total_len;len++){
        if(total_len % len == 0){
            int branch_num = total_len / len;
            used.assign(num,false);
            if(dfs(branch_num,0,0)){
                cout << len << endl;
                return;
            }
        }
    }
}

int main(){
    // freopen("input/ZY27.txt","r",stdin);

    solve();
    freopen("CON","r",stdin);
    system("pause");
}