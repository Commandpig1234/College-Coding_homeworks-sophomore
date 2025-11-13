#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* l_child;
    Node* r_child;

    Node() : l_child(nullptr),r_child(nullptr){}
};

void insert(Node*& node,int x){
    if(node == nullptr){
        node = new Node;
        node->data = x;
    }
    else{
        if(x < node->data)
            insert(node->l_child,x);
        else
            insert(node->r_child,x);
    }
    return;
}

void show(Node* node,int depth){
    if(node == nullptr)
        return;
    show(node->l_child,depth+1);
    cout << string(depth*4,' ') << node->data << endl;
    show(node->r_child,depth+1);
    return;
}

void inOrdered(Node* node){
    if(node == nullptr)
        return;
    inOrdered(node->l_child);
    cout << " " << node->data;
    inOrdered(node->r_child);
    return;
}

void solve(){
    Node* root = nullptr;
    for(int x;cin >> x,x;)
        insert(root,x);
    show(root,0);
    cout << endl;
    inOrdered(root);
    cout << endl;
    return;
}

int main(){
    // freopen("input/ZY6-2.txt","r",stdin);

    solve();

    freopen("CON","r",stdin);
    system("pause");
}