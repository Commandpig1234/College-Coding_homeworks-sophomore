#include <bits/stdc++.h>
using namespace std;

#define BORDER 100000000

typedef struct ListNode{
    ListNode *last;
    ListNode *next;
    int W;
    int H;
    long long *time;
}*List;


List Initial(int n, long long* time, List &low) {
    int W, H;
    List L = (List)malloc(sizeof(ListNode));
    L->H = BORDER;
    L->last = NULL;
    L->next = NULL;
    L->W = 0;
    L->time = NULL;
    List p = L, q = L;
    low = L;
    for (int i = 0; i < n; i++)
    {
        cin >> W >> H;
        p = (List)malloc(sizeof(ListNode));
        p->W = W;
        p->H = H;
        p->time = time + i;
        q->next = p;
        p->last = q;
        q = p;
        if (p->H < low->H)
            low = p;
    }
    p = (List)malloc(sizeof(ListNode));
    p->H = BORDER;
    p->W = 0;
    p->time = NULL;
    q->next = p;
    p->last = q;
    p->next = NULL;
    return L;
}

int main()
{
    int n;
    cin >> n;
    long long *time = new long long[n];
    List low;
    List L = Initial(n, time, low);

    long long sum = 0;
    List p = low;
    while (p->last->H != p->next->H)
    {
        *(p->time) = sum + p->W;
        if (p->last->H < p->next->H)
        {
            sum += (p->last->H - p->H) * p->W;
            p->last->W += p->W;
            p->next->last = p->last;
            p->last->next = p->next;
            p = p->last;
        }
        else
        {
            sum += (p->next->H - p->H) * p->W;
            p->next->W += p->W;
            p->next->last = p->last;
            p->last->next = p->next;
            p = p->next;
        }
        if (p->last->H > p->H && p->next->H > p->H)
            continue;
        if (p->last->H > p->H)
            while (p->H > p->next->H)
                p = p->next;
        else
            while (p->H > p->last->H)
                p = p->last;
    }
    *(p->time) = sum + p->W;

    for (int i = 0; i < n; i++)
        cout << time[i] << endl;
    delete[] time;
    List cur = L;
    while(cur)
    {
        List tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    system("pause");
    return 0;
}