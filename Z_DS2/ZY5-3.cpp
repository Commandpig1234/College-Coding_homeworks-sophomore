#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;


typedef unsigned long long ull;
typedef struct Node{
    char name;
    Node* l_child;
    Node* r_child;

    Node(){};
    Node(char _name) : name(_name),l_child(nullptr),r_child(nullptr){};
}*Tree,*Root;

void deleteTree(Root parent){
    if(!parent) return;
    deleteTree(parent->l_child);
    deleteTree(parent->r_child);
    delete parent;
    return;
}

Root buildTreeHelper(const string& inOrder, int in_start, int in_end, const string& postOrder, int post_start, int post_end, unordered_map<char,int>& inOrder_map){
    if(in_start > in_end || post_start > post_end)  return nullptr;

    char root_name = postOrder[post_end];
    Root root = new Node(root_name);

    int root_inOrder_index = inOrder_map[root_name];
    int left_length = root_inOrder_index - in_start;

    root->l_child = buildTreeHelper(inOrder,in_start,root_inOrder_index-1,postOrder,post_start,post_start+left_length-1,inOrder_map);
    root->r_child = buildTreeHelper(inOrder,root_inOrder_index+1,in_end,postOrder,post_start+left_length,post_end-1,inOrder_map);

    return root;
}

Root buildTree(const string& inOrder, const string& postOrder){
    if(inOrder.empty() || postOrder.empty())    return nullptr;

    unordered_map<char,int> inOrder_map;
    for(ull i= 0;i<inOrder.length();i++)    inOrder_map[inOrder[i]] = i;

    return buildTreeHelper(inOrder,0,inOrder.length()-1,postOrder,0,postOrder.length()-1,inOrder_map);
}

void outputTraversal(Root root){
    if(root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* cur = q.front();
        q.pop();

        cout << cur->name;
        if(cur->l_child != nullptr)
            q.push(cur->l_child);
        if(cur->r_child != nullptr)
            q.push(cur->r_child);
    }
    cout << endl;
    return;
}

void solve(){
    string inOrder,postOrder;
    cin >> inOrder >> postOrder;
    Root root = buildTree(inOrder,postOrder);
    outputTraversal(root);
    deleteTree(root);
}

int main(){
    // freopen("input/ZY5-3.txt","r",stdin);

    solve();

    freopen("CON","r",stdin);
    system("pause");
}