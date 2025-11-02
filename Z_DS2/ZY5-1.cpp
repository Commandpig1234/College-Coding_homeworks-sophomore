#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>

using namespace std;

struct Node
{
    char name;
    vector<Node*> children;
    
    Node(char _name) : name(_name){};
};

void printTree(Node* parent,int level){
    if(parent == nullptr)  
        return;
    
    for(int i = 0;i<level;i++){
        cout << "    ";
    }
    cout << parent->name << endl;

    for(Node* child : parent->children){
        printTree(child,level+1);
    }
}

void deleteTree(Node* parent){
    if(parent == nullptr)
        return;

    for(Node* child : parent->children){
        deleteTree(child);
    }

    delete parent;
    return;
}

void solve(){
    string L;
    cin >> L;
    
    Node* root = nullptr;
    vector<Node*> Nodes;
    stack<Node*> cur_parent;
    
    for(int i = 0;i<static_cast<int>(L.length());i++){
        char c = L[i];

        if(isalpha(c)){
            Node* new_node = new Node(c);
            Nodes.push_back(new_node);

            if(!cur_parent.empty()){
                cur_parent.top()->children.push_back(new_node);
            }
            else{
                root = new_node;
            }
            cur_parent.push(new_node);
        }
        else if(c == ')' && !cur_parent.empty()){
            cur_parent.pop();
        }
    }

    printTree(root,0);
    
    map<int,int> degree_count;
    int tree_degree = 0;
    for(Node* node : Nodes){
        int cur_degree = node->children.size();
        degree_count[cur_degree]++;
        tree_degree = max(tree_degree,cur_degree);
    }
    printf("Degree of tree: %d\n",tree_degree);
    for(int i = 0;i<=tree_degree;i++){
        if(degree_count.count(i)){
            int degree = i,count = degree_count[i];
            printf("Number of nodes of degree %d: %d\n",degree,count);
        }
        else{
            printf("Number of nodes of degree %d: 0\n",i);
        }
    }
    
    deleteTree(root);

    return;
}

int main(){
    // freopen("input/ZY5-1.txt","r",stdin);

    solve();

    freopen("CON","r",stdin);
    system("pause");
}