#include <iostream>
#include <stack>
using namespace std;

void solve(int n){
    stack<int> reverse;
    stack<int> check;
    stack<int> benchmark;
    for(int i = 1;i<=n;i++){
        int input;
        cin >> input;
        reverse.push(input);
    }
    for(int i = 1;i<=n;i++){
        int input = reverse.top();
        check.push(input);
        reverse.pop();
    }
    int i = 1;
    while(!check.empty()){
        int cur = check.top();
        if(benchmark.empty() || cur != benchmark.top()){
            benchmark.push(i++);
        }
        else{
            benchmark.pop();
            check.pop();
        }
        if(i>n+1){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    return;
}

int main(){
    // freopen("input/ZY4-2.txt","r",stdin);

    bool first = true;
    while(1){
        int n,m;
        cin >> n >> m;
        if(n == 0 && m == 0)    break;//结束
        if(first){
            first = false;
        }
        else{
            cout << endl;
        }
        while(m--){
            solve(n);
        }
    }
    // freopen("CON","r",stdin);
    system("pause");
}