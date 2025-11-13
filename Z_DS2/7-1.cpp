#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node{
    Node* children[2];
    bool isEnd;

    Node() : isEnd(false){
        children[0] = nullptr;
        children[1] = nullptr;
    }

    ~Node(){
        delete children[0];
        delete children[1];
    }

    bool hasChild(){
        return children[0] != nullptr || children[1] != nullptr;
    }

};

bool insertCheck(Node* root,const string& new_code){
    Node* cur = root;

    for(char ch : new_code){
        int index = ch - '0';
        if(cur->children[index] == nullptr){
            cur->children[index] = new Node();
        }

        cur = cur->children[index];

        if(cur->isEnd){
            return true;
        }
    }

    if(cur->hasChild()){
        return true;
    }

    cur->isEnd = true;
    return false;
}

void solve(){
    int n;
    cin >> n;
    Node* root = new Node();

    while(n--){
        string new_node;
        cin >> new_node;

        if(insertCheck(root,new_node)){
            cout << new_node << endl;
            return;
        }
    }
    delete root;
    cout << "YES" << endl;
    return;
}

int main(){
    // freopen("input/1.txt","r",stdin);

    solve();

    freopen("CON","r",stdin);
    system("pause");
}