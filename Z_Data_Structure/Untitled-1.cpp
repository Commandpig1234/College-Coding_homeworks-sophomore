#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;
typedef set<string> pack;

pack split(const string& L){
    pack S1;
    string cur;
    for(char c : L){
        if(c == '&'){
            if (!cur.empty()) S1.insert(cur);
            cur.clear();
        }
        else if(c!='(' && c!=')'){
            cur += c;
        }
    }
    if (!cur.empty()) S1.insert(cur);
    cur.clear();
    return S1;
}

set<string> parseClause(const string& clause_str) {
    set<string> literals;
    string current_literal;
    for (char ch : clause_str) {
        if (ch == '|') {
            if (!current_literal.empty()) {
                literals.insert(current_literal);
            }
            current_literal.clear();
        } else {
            current_literal += ch;
        }
    }
    if (!current_literal.empty()) {
        literals.insert(current_literal);
    }
    return literals;
}

// (您填充的三个函数是正确的，保持不变)
bool canDissolve(const set<string>& literals1, const set<string>& literals2) {
    for (const string& lit1 : literals1) {
        // 使用三元运算符让代码更紧凑
        string complement = (lit1[0] == '!') ? lit1.substr(1) : "!" + lit1;
        if (literals2.count(complement)) {
            return true;
        }
    }
    return false;
}

// 重构后的 Res，接收解析好的集合
string Res(const set<string>& literals1, const set<string>& literals2) {
    for (const string& lit1 : literals1) {
        string complement = (lit1[0] == '!') ? lit1.substr(1) : "!" + lit1;
        if (literals2.count(complement)) {
            set<string> merged_literals;
            // 将两个集合中不参与消解的文字合并
            for (const string& l : literals1) if (l != lit1) merged_literals.insert(l);
            for (const string& l : literals2) if (l != complement) merged_literals.insert(l);
            
            // 将合并后的集合重新组合成字符串
            string result_string;
            for (auto it = merged_literals.begin(); it != merged_literals.end(); ++it) {
                result_string += *it;
                if (next(it) != merged_literals.end()) {
                    result_string += "|";
                }
            }
            return result_string;
        }
    }
    return ""; // 如果不能消解，理论上不会执行到这里
}

bool isNone(const string& C){
    return C.empty();
}


// ==========================================================
// 修正后的 dissolution 函数
// ==========================================================
bool dissolution(pack& S){
    while(true){
        pack new_clauses;
        
        for(auto it1 = S.begin(); it1 != S.end(); it1++){
            for(auto it2 = next(it1); it2 != S.end(); it2++){
                // 关键：在这里进行一次性解析
                set<string> literals1 = parseClause(*it1);
                set<string> literals2 = parseClause(*it2);

                if(canDissolve(literals1, literals2)){
                    string C = Res(literals1, literals2);
                    if(isNone(C))
                        return false;
                    
                    if(!S.count(C)){
                        new_clauses.insert(C);
                    }
                }
            }
        }

        if(new_clauses.empty())
            return true;
        
        S.insert(new_clauses.begin(), new_clauses.end());
    }
}

// ==========================================================
// 修正后的 solve 函数
// ==========================================================
void solve(){
    string L;
    getline(cin,L);
    
    pack S = split(L); // 只需要一个集合来存放所有子句

    if(dissolution(S)) // 将集合传入即可
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
}

int main(){
    // freopen("input/2.txt","r",stdin);
    solve();
    //p&(p|q)&(p|!q)&(q|!r)&(r|!q) -> NO
    //(!p|q)&(p|q)&(!q) -> NO
    // freopen("CON","r",stdin);
    system("pause");
    return 0;
}