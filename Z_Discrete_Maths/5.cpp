#include <iostream>

using namespace std;

void solve(){
    int a,result = 0,order = 0;
    cin >> a;
    do{
        result+=a;
        result %= 18;
        order++;
    }while(result != 0);
    cout << order << endl;//输出阶数（最小的k使a^k = e(单位元，即0)）
}

int main(){
    // freopen("input/5.txt","r",stdin);

    solve();

    freopen("CON","r",stdin);
    system("pause");
}