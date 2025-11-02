#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>

using namespace std;

typedef unsigned long long ull;

struct Node{
    char name;
    Node* l_child;
    Node* r_child;

    Node(){};
    Node(char _name) : name(_name),l_child(nullptr),r_child(nullptr){};
};

Node* buildTree(const string& L){
    if(L.empty() || L[0] == '#')
        return nullptr;
    
    queue<Node*>in_process;
    Node* root = new Node(L[0]);
    in_process.push(root);

    size_t i = 1;
    while(i < L.length() && !in_process.empty()){
        Node* parent = in_process.front();
        in_process.pop();

        if(i < L.length() && L[i] != '#'){
            parent->l_child = new Node(L[i]);
            in_process.push(parent->l_child);
        }
        i++;

        if(i < L.length() && L[i] != '#'){
            parent->r_child = new Node(L[i]);
            in_process.push(parent->r_child);
        }
        i++;
    }
    return root;
}

void showTree(Node* parent,int depth){
    if(parent == nullptr)
        return;
    
    for(int i= 0;i<depth;i++){
        cout << "    ";
    }
    cout << parent->name << endl;

    showTree(parent->l_child,depth+1);
    showTree(parent->r_child,depth+1);

    return;
}

void preOrder(Node* parent,string &line){
    if(parent == nullptr)
        return;
    
    line += parent->name;
    preOrder(parent->l_child,line);
    preOrder(parent->r_child,line);
}

void inOrder(Node* parent,string &line){
    if(parent == nullptr)
        return;
    
    inOrder(parent->l_child,line);
    line += parent->name;
    inOrder(parent->r_child,line);
}

void postOrder(Node* parent,string &line){
    if(parent == nullptr)
        return;
    
    postOrder(parent->l_child,line);
    postOrder(parent->r_child,line);
    line += parent->name;
}

void Show(Node* root){
    showTree(root,0);

    string pre_line,in_line,post_line;

    preOrder(root,pre_line);
    inOrder(root,in_line);
    postOrder(root,post_line);

    cout << "pre_sequence  : " << pre_line << endl;
    cout << "in_sequence   : " << in_line << endl;
    cout << "post_sequence : " << post_line << endl;

    return;
}

int countLeaf(Node* parent){
    if(!parent)
        return 0;
    if(!parent->l_child && !parent->r_child)
        return 1;
    return countLeaf(parent->l_child) + countLeaf(parent->r_child);
}

void swapTree(Node* parent){
    if(!parent)
        return;

    swap(parent->l_child,parent->r_child);

    swapTree(parent->l_child);
    swapTree(parent->r_child);
    return;
}

void deleteTree(Node* parent){
    if(!parent)
        return;
    deleteTree(parent->l_child);
    deleteTree(parent->r_child);
    delete parent;
    return;
}

void solve(){
    cout << "BiTree" << endl;
    
    string L;
    cin >> L;
    
    Node* root = buildTree(L);

    Show(root);

    cout << "Number of leaf: " << countLeaf(root) << endl;

    cout << "BiTree swapped" << endl;
    swapTree(root);

    Show(root);

    deleteTree(root);

    return;
}

int main(){
    // freopen("input/ZY5-2.txt","r",stdin);

    solve();

    freopen("CON","r",stdin);
    system("pause");
}