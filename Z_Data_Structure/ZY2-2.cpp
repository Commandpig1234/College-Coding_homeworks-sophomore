/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

typedef struct node
{   int         data;
    struct node * next;
} NODE;

void output( NODE * );
void change( int, int, NODE * );

void output( NODE * head )
{   int k=0;

	printf("0.");
	while ( head->next != NULL && k<50 )
	{   printf("%d", head->next->data );
		head = head->next;
		k ++;
	}
	printf("\n");
}

int main()
{   int n, m;
	NODE * head;

	scanf("%d%d", &n, &m);
	head = (NODE *)malloc( sizeof(NODE) );
	head->next = NULL;
	head->data = -1;
	change( n, m, head );
	output( head );
    system("pause");
	return 0;
}
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */
void change(int n,int m,NODE *head){
    int a=n,b=m;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    n = n/a;
    m = m/a;
    int remain = n%m;
    int digit = 0;
    int pos = 1;
    NODE *current = head;
    std::map<int,int> rem_pos;//<key,value> -> <remain,pos>
    while(remain != 0){
        if(rem_pos.count(remain) > 0){
            NODE *loop_head = head;
            for(int i =1;i<=rem_pos[remain];i++){
                loop_head = loop_head->next;
            }
            current->next = loop_head;
            return;
        }
        rem_pos[remain] = pos;
        digit = (remain*10)/m;
        remain = (remain*10)%m;
        NODE *p = new NODE;
        p->data = digit;
        p->next = NULL;
        current ->next = p;
        current = p;
        pos++;
    }
    return;
}