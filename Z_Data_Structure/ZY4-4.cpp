#include <iostream> 
#include <string>
#include <stack>
#include <cctype>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;


int get_precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '^') return 3;
    return 0;
}

string into_postfix(string equation){
    string postfix;
    stack<char> ops;

    for(ull i = 0;i<equation.length();i++){
        char cur = equation[i];
        if(isalpha(cur)){
            postfix += cur;
        }
        else if(cur == '('){
            ops.push(cur);
        }
        else if(cur == ')'){
            while(!ops.empty() && ops.top() != '('){
                postfix += ops.top();
                ops.pop();
            }
            if(!ops.empty()){
                ops.pop();
            }
            else{
                postfix = "error.";
                return postfix;
            }
        }
        else{
            while (!ops.empty() && 
            ops.top() != '(' && 
            (get_precedence(ops.top()) > get_precedence(cur) || 
            (get_precedence(ops.top()) == get_precedence(cur) && cur != '^'))) {
                postfix += ops.top();
                ops.pop();
            }
            ops.push(cur);
        }
    }
    while(!ops.empty()){
        postfix += ops.top();
        ops.pop();
    }
    return postfix;
}

void solve(){
    string line;
    cin >> line;
    stack<int> nums;
    stack<char> ops;
    string equation;
    for(ull i = 0;i<line.size() - 1;i++){
        if(line[i] == '-' && line[i+1] == '-'){
            equation += '+';
            i++;
        }
        else if(line[i] == '+' && line[i+1] == '-'){
            equation += '-';
            i++;
        }
        else{
            equation += line[i];
        }
    }
    string postfix_equation = into_postfix(equation);
    cout << postfix_equation << endl;
    return;
}

int main(){
    // freopen("input/ZY4-4.txt","r",stdin);

    int N;
    cin >> N;
    while(N--){
        solve();
    }

    // freopen("CON","r",stdin);
    system("pause");
}