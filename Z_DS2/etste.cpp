#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;

struct GNode
{
    bool isAtom; // true for atom, false for list
    union
    {
        char atom;   // atom value
        GNode *tail; // pointer to tail
    } data;
    GNode *next, *tail; // pointer to next node
};

typedef GNode *GList;
// Create GList from string S
int CreateGList(GList &L, const string &S, int pos = 0)
{
    L = nullptr;           // Initialize the list
    GNode *tail = nullptr; // To keep track of the last node

    while (pos < S.length())
    {
        if (S[pos] == ' ' || S[pos] == ',')
        {
            pos++; // Skip spaces
            continue;
        }
        if (S[pos] == ')')
            return pos;
        GNode *newNode = new GNode();
        if (S[pos] == '(')
        {
            pos++;
            GNode *sublist = nullptr;
            pos = CreateGList(sublist, S, pos);
            newNode->isAtom = false;
            newNode->data.tail = sublist;
        }
        else
        {
            newNode->isAtom = true;
            newNode->data.atom = S[pos];
        }
        newNode->next = nullptr;
        if (!L)
            L = newNode;
        else
            tail->next = newNode;
        tail = newNode;
        pos++;
    }
    if (L) L->tail = tail;
    return pos;
}

// Get head of the GList
GList GetHead(GList L)
{
    if (L == nullptr)
        return nullptr;
    // return L->isAtom ? nullptr : L->data.tail; // Return tail if L is a list
    if (L->isAtom)
    {
        L-> next = nullptr;
        return L;
    }
    return L->data.tail;
}

// Get tail of the GList
GList GetTail(GList L)
{
    return L ? L->next : nullptr;
}

// Destroy GList
void PrintGList(GList L, int level = 0)
{
    if (level == 0)
        cout << "generic list: ";
    if (L && !L->next && L->isAtom)
    {
        cout << L->data.atom << endl;
        return;
    }
    cout << "(";
    while (L)
    {
        if (L->isAtom)
            cout << L->data.atom;
        else
            PrintGList(L->data.tail, level + 1); // Recursively print tail
        L = L->next;
        if (L)
            cout << ",";
    }
    cout << ")";
    if (level == 0)
        cout << endl;
}

int main()
{
    freopen("input/8-2.txt","r",stdin);
    
    GList L = nullptr;
    string input; // To hold input string
    // cout << "Input GList: ";
    cin >> input;

    CreateGList(L, input);
    L = L->data.tail;
    PrintGList(L);

    int command;
    while (L && !(L->next == nullptr && L->isAtom))
    {
        cin >> command;

        if (command == 1)
        {
            cout << "destroy tail" << endl;
            cout << "free list node" << endl;
            L = GetHead(L);
        }
        else if (command == 2)
        {
            cout << "free head node" << endl;
            cout << "free list node" << endl;
            L = GetTail(L);
        }

        PrintGList(L);
    }

    freopen("CON","r",stdin);
    system("pause");

}