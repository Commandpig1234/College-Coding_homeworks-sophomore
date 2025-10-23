#include <iostream>
using namespace std;

typedef long long ll;

void solve(ll n,int m){
    if (m == 0) {//不变
        cout << 1 << endl;
        return;
    }

    if (n == 1) {//{0} & {1}
        cout << 2 << endl;
    }
    else if (n == 2) {
        if (m == 1) {
            cout << 3 << endl;//{0，1}{1，0}{1，1}
        }
        else {
            cout << 4 << endl;//全（操作1 = 操作2 + 操作3）
        }
    }
    else {//n >= 3 
        if (m == 1) {//4种操作各一种
            cout << 4 << endl;
        } 
        else if (m == 2) {//C{4}{2} + 不变（同种操作两次）
            cout << 7 << endl;
        }
        else { //
            cout << 8 << endl;
        }
        /*
        5.都不选: 0   操作1 和 操作2 + 操作3 两两组合（4种）得到 “无效”操作
        1.只选 v1
        2.只选 v2 
        3.只选 v3
        4.只选 v4
        1.选 v2 和 v3(就是v1)
        6.选 v2 和 v4
        7.选 v3 和 v4
        8.全都选
        */
    }

    return;
}


int main(){
    // freopen("input/ZY21.txt","r",stdin);

    ll n;
    int m;
    cin >> n >> m;
    solve(n,m);

    // freopen("CON","r",stdin);
    // system("pause");
}