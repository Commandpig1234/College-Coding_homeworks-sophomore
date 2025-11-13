#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Node{
    char data;
    int height;
    Node* l_child;
    Node* r_child;

    Node() : height(0),l_child(nullptr),r_child(nullptr){}
};

int getHeight(Node* node){
    if(node == nullptr)
        return -1;
    return node->height;
}

void updateHeight(Node* node){
    node->height = 1 + max(getHeight(node->l_child),getHeight(node->r_child));
}

Node* rotate_l(Node* x){
    Node* y = x->r_child;
    Node* T2 = y->l_child;

    y->l_child = x;
    x->r_child = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}
Node* rotate_r(Node* x){
    Node* y =x->l_child;
    Node* T2 = y->r_child;

    y->r_child = x;
    x->l_child = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

Node* insert(Node* node,char c){
    if(node == nullptr){
        node = new Node;
        node->data = c;
        return node;
    }
    else{
        if(c < node->data)
            node->l_child = insert(node->l_child,c);
        else
            node->r_child = insert(node->r_child,c);
    }
    updateHeight(node);
    int balance = getHeight(node->l_child) - getHeight(node->r_child);

    if(balance > 1 && c < node->l_child->data)
        return rotate_r(node);
    if(balance > 1 && c > node->l_child->data){
        node->l_child = rotate_l(node->l_child);
        return rotate_r(node);
    }
    if(balance < -1 && c > node->r_child->data)
        return rotate_l(node);
    if(balance < -1 && c < node->r_child->data){
        node->r_child = rotate_r(node->r_child);
        return rotate_l(node);
    }

    return node;
    
}

void preOrder(Node* node){
    if(node == nullptr)
        return;
    cout << node->data;
    preOrder(node->l_child);
    preOrder(node->r_child);
}
void inOrder(Node* node){
    if(node == nullptr)
        return;
    inOrder(node->l_child);
    cout << node->data;
    inOrder(node->r_child);
}
void postOrder(Node* node){
    if(node == nullptr)
        return;
    postOrder(node->l_child);
    postOrder(node->r_child);
    cout << node->data;
}
void show(Node* node,int depth){
    if(node == nullptr)
        return;
    show(node->r_child,depth+1);
    cout << string(depth*4,' ') << node->data << endl;
    show(node->l_child,depth+1);
}

void solve(){
    string s;
    cin >> s;
    Node* root = nullptr;
    for(char c : s){
        root = insert(root,c);
    }
    cout << "Preorder: ";
    preOrder(root);
    cout << endl;
    cout << "Inorder: ";
    inOrder(root);
    cout << endl;
    cout << "Postorder: ";
    postOrder(root);
    cout << endl;
    cout << "Tree:" << endl;
    show(root,0);
}

int main(){
    // freopen("input/ZY6-3.txt","r",stdin);

    solve();

    freopen("CON","r",stdin);
    system("pause");
}