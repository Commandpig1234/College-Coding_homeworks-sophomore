#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

using ull = unsigned long long;
using pack = set<string>;

pack split(const string& L){
    pack S1;
    string cur;
    for(char c : L){
        if(c == '&'){
            if(!cur.empty())
                S1.insert(cur);
            cur.clear();
        }
        else if(c!='(' && c!=')'){
            cur += c;
        }
    }
    if(!cur.empty())  S1.insert(cur);
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

bool canDissolve(const set<string>& C1,const set<string>& C2){
    for (const string& literal : C1){
        string tofind;
        if(literal[0] == '!')
            tofind = literal.substr(1);
        else 
            tofind = "!" + literal;
        if(C2.count(tofind))
            return true;
    }
    return false;
}

string Res(const set<string>& C1,const set<string>& C2){
    for (const string& lit1 : C1) {
        string tofind;
        if (lit1[0] == '!') {
            tofind = lit1.substr(1);
        } else {
            tofind = "!" + lit1;
        }
        if (C2.count(tofind)) {
            set<string> merged_literals;
            for (const string& l : C1) if (l != lit1) merged_literals.insert(l);
            for (const string& l : C2) if (l != tofind) merged_literals.insert(l);
            
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
    return "";
}

bool isNone(const string& C){
    return C.empty();
}

bool dissolution(pack& S){
    while(1){
        pack new_clauses;
        
        for(auto it1 = S.begin();it1 != S.end();it1++){
            for(auto it2 = next(it1);it2 != S.end();it2++){
                set<string> C1 = parseClause(*it1);
                set<string> C2 = parseClause(*it2);

                if(canDissolve(C1,C2)){
                    string C = Res(C1,C2);
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
        S.insert(new_clauses.begin(),new_clauses.end());
    }
}

void solve(){
    string L;
    getline(cin,L);
    
    pack S;
    S = split(L);
    if(dissolution(S))
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
}

int main(){
    // freopen("input/2.txt","r",stdin);
    solve();
    //p&(p|q)&(p|!q)&(q|!r)&(q|r)
    freopen("CON","r",stdin);
    system("pause");
}