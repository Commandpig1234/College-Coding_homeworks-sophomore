#include <bits/stdc++.h>

using namespace std;

typedef struct PolyNode {
    int coef;           // 系数
    int expo;           // 指数
    struct PolyNode* next; // 指向下一项的指针
} PolyNode, *Polynomial;//Polynode* Polynomial


void InitPolyn(Polynomial& P);// 创建一个带头结点的空链表
void CreatePolyn(Polynomial& P, int n);// 创建一个多项式
void PrintPolyn(Polynomial P);// 打印一个多项式
Polynomial AddPolyn(const Polynomial& Pa,const Polynomial& Pb);// 多项式加法
void DestroyPolyn(Polynomial& P);// 销毁一个多项式，释放内存

int main() {
    
    // freopen("input/ZY3-3.txt","r",stdin);

    while(1)
    {
        int action = 0;
        cin >> action;
        if(action == 0) break;
        Polynomial Pa,Pb,Pc,Pab,Pabc;
        int numA,numB,numC;
        
        cin >> numA;
        CreatePolyn(Pa,numA);
        cin >> numB;
        CreatePolyn(Pb,numB);
        cin >> numC;
        CreatePolyn(Pc,numC);
        Pab = AddPolyn(Pa,Pb);
        Pabc = AddPolyn(Pab,Pc);
        PrintPolyn(Pa);
        PrintPolyn(Pb);
        PrintPolyn(Pc);
        PrintPolyn(Pab);
        PrintPolyn(Pabc);
        DestroyPolyn(Pa);
        DestroyPolyn(Pb);
        DestroyPolyn(Pc);
        DestroyPolyn(Pab);
        DestroyPolyn(Pabc);       

    }

    // freopen("CON","r",stdin);
    // system("pause");

    return 0;
}

void InitPolyn(Polynomial& P)
{
    P = new PolyNode();
    P->next = nullptr;
    return;
}

void CreatePolyn(Polynomial& P, int n)
{
    InitPolyn(P);
    Polynomial t = P;
    for(int i= 0;i<n;i++)
    {
        Polynomial new_node = new PolyNode();
        cin >> new_node->coef >> new_node->expo;
        new_node->next = nullptr;
        t->next = new_node;
        t = new_node;
    }
    return;
}

Polynomial AddPolyn(const Polynomial& Pa,const Polynomial& Pb)
{
    Polynomial Pc;
    InitPolyn(Pc);
    Polynomial t = Pc;
    Polynomial t1,t2;
    t1 = Pa->next;
    t2 = Pb->next;
    while(t1 && t2)
    {
        Polynomial new_node = new PolyNode();
        new_node->next = nullptr;
        if(t1->expo < t2->expo)
        {
            new_node->expo = t1->expo;
            new_node->coef = t1->coef;
            t1 = t1->next;
        }
        else if(t1->expo > t2->expo)
        {
            new_node->expo = t2->expo;
            new_node->coef = t2->coef;
            t2 = t2->next;
        }
        else
        {
            int sum_coef = t1->coef + t2->coef;
            if(sum_coef != 0)
            {
                new_node->expo = t1->expo;
                new_node->coef = sum_coef;
            }
            else
            {
                delete new_node;
                t1 = t1->next;
                t2 = t2->next;
                continue;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
        t->next = new_node;
        t = new_node;
    }
    Polynomial remain = t1 ? t2 : t2;
    while(remain)
    {
        Polynomial new_node = new PolyNode();
        new_node->coef = remain->coef;
        new_node->expo = remain->expo;
        new_node->next = nullptr;
        t->next = new_node;
        t = new_node;
        remain = remain->next;
    }
    return Pc;
}

void PrintPolyn(Polynomial P)
{
    Polynomial p = P->next;
    if(!p)
    {
        cout << "<0,0>" << endl;
        return;
    }
    bool first = true;
    while(p)
    {
        if(!first)
            cout << ",";
        cout << "<" << p->coef << "," << p->expo << ">";
        first = false;
        p = p->next;
    }
    cout << endl;
}

void DestroyPolyn(Polynomial& P)
{
    Polynomial p = P->next;
    while(p)
    {
        Polynomial temp = p;
        p = p->next;
        delete temp;
    }
    P = nullptr;
}