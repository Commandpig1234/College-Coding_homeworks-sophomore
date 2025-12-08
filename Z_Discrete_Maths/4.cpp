#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>

using namespace std;

void solve(){
    string line;
    getline(cin, line);
    stringstream ss(line);
    char elem;
    set<char> elements;
    while (ss >> elem){
        if (elem != ',')
            elements.insert(elem);
    }

    getline(cin, line);
    vector<char> relations_char;
    for (char c : line){
        if (isalpha(c)){
            relations_char.push_back(c);
        }
    }

    map<char,int> in_degree;
    map<char,int> out_degree;
    for (char c : elements){
        in_degree[c] = 0;
        out_degree[c] = 0;
    }

    for (size_t i = 0; i + 1 < relations_char.size(); i += 2){
        char u = relations_char[i];
        char v = relations_char[i+1];
        
        if (u != v){
            out_degree[u]++;
            in_degree[v]++;
        }
    }

    bool first = true;
    for (char c : elements){
        if (in_degree[c] == 0){
            if (!first) cout << ",";
            cout << c;
            first = false;
        }
    }
    cout << endl;

    first = true;
    for (char c : elements){
        if (out_degree[c] == 0){
            if (!first) cout << ",";
            cout << c;
            first = false;
        }
    }
    cout << endl;
    return;
}

int main(){
    // freopen("input/4.txt","r",stdin);

    solve();

    freopen("CON","r",stdin);
    system("pause");
    return 0;
}