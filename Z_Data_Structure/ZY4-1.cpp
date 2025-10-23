#include <iostream>
#include <stack>

typedef unsigned long long ull;

using namespace std;

bool checkMatch (){
    string equation;
    cin >> equation;
    stack<char> bracket;
    for(ull i = 0;i<equation.size();i++){
        char cur = equation.at(i);
        if(cur == '(' || cur == '['){
            bracket.push(cur);
        }
        else if(cur == ')'){
            if(bracket.top() != '(' || bracket.empty())
                return false;
            bracket.pop();
        }
        else if(cur == ']'){
            if(bracket.top() != '[' || bracket.empty())
                return false;
            bracket.pop();
        }
    }
    if(bracket.empty())
        return true;
    else
        return false;
}

int main(){
    // freopen("input/ZY4-1.txt","r",stdin);

    if(checkMatch()){
        cout << "Match succeed!" << endl;
    }
    else{
        cout << "Match false!" << endl;
    }

    // freopen("CON","r",stdin);
    // system("pause");
}