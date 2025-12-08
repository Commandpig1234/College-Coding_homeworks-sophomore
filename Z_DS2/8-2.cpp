#include <iostream>
#include <string>

using namespace std;
typedef bool Status;

typedef struct Node{
    bool isAtom;    // true: 原子
    union{
        char atom;
        Node* tail;
    }data;
    Node* next;
    Node* tail;
}*GList;

// Status CreateGList( GList &L, string S ) // 根据字符串 S 表示的广义表内容建立广义表数据结构；
// GList GetHead( GList L)  // 取表头运算
// GList GetTail( GList L)  // 取表尾运算
// void DestroyGList( GList &L)  // 销毁广义表 L
// void PrintGList( GList L) // 显示广义表 L 内容

GList GetHead(GList L){
    if(!L)
        return nullptr;
    if(L->isAtom){
        L->next = nullptr;
        return L;
    }
    return L->data.tail;
}

GList GetTail( GList L){
    if(L)
        return L->next;
    else 
        return nullptr;
}

void PrintGList( GList L,int level = 0){
    if(level == 0)
        cout <<"generic list: ";
    if(L && !L->next && L->isAtom){
        cout << L->data.atom << endl;
        return;
    }
    cout << "(";
    while(L){
        if(L->isAtom)
            cout << L->data.atom;
        else
            PrintGList(L->data.tail,level + 1);
        L = L->next;
        if(L)
            cout << ",";
    }
    cout << ")";
    if(level == 0)
        cout << endl;
}

int CreateGList( GList &L, string S,int pos=0){
    L = nullptr;
    Node* tail = nullptr;

    while(pos < (int)S.length()){
        char cur = S[pos];
        if(cur == ' ' || cur == ','){
            pos++;
            continue;
        }
        else if(cur == ')') return pos;

        Node* newNode = new Node;
        if(cur == '('){
            pos++;
            Node* sublist = nullptr;
            pos = CreateGList(sublist,S,pos);
            newNode->isAtom = false;
            newNode->data.tail = sublist;
        }
        else{
            newNode->isAtom = true;
            newNode->data.atom = cur;
        }
        newNode->next = nullptr;

        if(!L)
            L = newNode;
        else
            tail->next = newNode;
        tail = newNode;
        pos++;
    }
    if(L)
        L->tail = tail;
    return pos;
}

void solve(){
    string input;
    getline(cin,input);
    GList L = nullptr;
    CreateGList(L,input);
    L = L->data.tail;
    PrintGList(L);
    
    int op;
    while(L && (L->next != nullptr || !L->isAtom)){
        cin >> op;

        if(op == 1){
            cout << "destroy tail" << endl;
            cout << "free list node" << endl;
            L = GetHead(L);
        }
        else if(op == 2){
            cout << "free head node" << endl;
            cout << "free list node" << endl;
            L = GetTail(L);
        }
        
        PrintGList(L);
    }
    return;
}

int main(){
    // freopen("input/8-2.txt","r",stdin);

    solve();

    freopen("CON","r",stdin);
    system("pause");
}