#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 递归生成 n 位格雷码
vector<string> BRGC(int n) {
    if(n == 1)
        return{"0","1"};
    vector<string>L1 = BRGC(n-1);

    vector<string> L2(L1.rbegin(),L1.rend());

    for(string& s : L1){
        s = "0" + s;
    }

    for(string& s : L2){
        s = "1" + s;
    }

    L1.insert(L1.end(),L2.begin(),L2.end());

    return L1;
}

int main() {
    int n = 0;
    do{
        cin >> n;
    }while(n <= 0);

    

    vector<string> result = BRGC(n);

    // 输出所有格雷码
    for (auto &s : result) {
        cout << s << "\n";
    }
    system("pause");
    return 0;
}
