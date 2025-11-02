#include <iostream> 
#include <string>
#include <stack>
#include <cctype>
#include <cmath>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int get_precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '^') return 3;
    return 0;
}

ll operate(ll b, ll a, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b; 
    if (op == '%') return a % b; 
    if (op == '^') return static_cast<ll>(pow(a, b)); 
    return 0; 
}

bool is_valid(const string& line) {
    if (line.empty()) return false;

    ll balance = 0;
    for (char c : line) {
        if (c == '(')
            balance++;
        else if (c == ')')
            balance--;
        if (balance < 0)
            return false;
    }
    if (balance != 0)   {
        return false;
    }
    if(get_precedence(line[0]) != 0 || get_precedence(line.back()) != 0) return false;

    for (ull i = 0; i < line.length() - 1; ++i) {
        char cur = line[i];
        char next = line[i+1];

        if (isdigit(cur) && next == '(') {
            return false;
        }
        if (cur == ')' && (isdigit(next) || next == '(')) {
            return false;
        }
        if (get_precedence(cur) != 0 && (get_precedence(next) != 0 || next == ')')) {
            return false;
        }
        if (cur == '(' && (get_precedence(next) != 0 || next == ')')) {
            return false;
        }
    }
    
    return true;
}

void calculate(string postfix){
    stack<ll> nums;

    for (ull i = 0; i < postfix.length(); ++i) {
        char cur = postfix[i];
        if (isdigit(cur)) {
            string num_str;
            while (i < postfix.length() && isdigit(postfix[i])) {
                num_str += postfix[i];
                i++;
            }
            nums.push(stoll(num_str));
        }
        else if (isspace(cur)) {
            continue;
        }
        else {
            if (nums.size() < 2) {
                cout << "error." << endl;
                return;
            }

            ll operand2 = nums.top();
            nums.pop();
            ll operand1 = nums.top();
            nums.pop();
            
            char op = cur;

            if ((op == '/' || op == '%') && operand2 == 0) {
                cout << "Divide 0." << endl;
                return;
            }
            if (op == '^' && operand2 < 0) {
                cout << "error." << endl;
                return;
            }

            nums.push(operate(operand2, operand1, op));
        }
    }

    if (nums.size() != 1) {
        cout << "error." << endl;
    } 
    else {
        cout << nums.top() << endl;
    }
    return;
}

string into_postfix(string equation){
    string postfix;
    stack<char> ops;

    for(ull i = 0;i<equation.length();i++){
        char cur = equation[i];
        if(isdigit(cur)){
            string num_str;
            while(i < equation.length() && isdigit(equation[i])){
                num_str += equation[i];
                i++;
            }
            postfix += num_str;
            postfix += " ";
            i--;
        }
        else if(cur == '('){
            ops.push(cur);
        }
        else if(cur == ')'){
            while(!ops.empty() && ops.top() != '('){
                postfix += ops.top();
                postfix += " ";
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
            (get_precedence(ops.top()) == get_precedence(cur) && 
            cur != '^'))) {
                postfix += ops.top();
                postfix += " ";
                ops.pop();
            }
            ops.push(cur);
        }
    }
    while(!ops.empty()){
        if(ops.top() == '('){
            postfix = "error.";
            return postfix;
        }
        else{
            postfix += ops.top();
            postfix += " ";
            ops.pop();
        }
    }
    return postfix;
}

void solve(){
    string line;
    cin >> line;
    stack<ll> nums;
    stack<char> ops;
    string equation;
    for(ull i = 0;i<line.size();i++){
        if(line[i] == '-' && line[i+1] == '-'){
            equation += "+";
            i++;
        }
        else if(line[i] == '+' && line[i+1] == '-'){
            equation += "-";
            i++;
        }
        else{
            equation += line[i];
        }
    }
    if (!is_valid(equation)) {
        cout << "error." << endl;
        return;
    }
    string postfix_equation = into_postfix(equation);
    if(postfix_equation == "error."){
        cout << postfix_equation << endl;
        return;
    }

    calculate(postfix_equation);
    return;
}

int main(){
    // freopen("input/ZY4-3.txt","r",stdin);

    int N;
    cin >> N;
    while(N--){
        solve();
    }

    // freopen("CON","r",stdin);
    system("pause");
}