/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{   int    coef, exp;
    struct node  *next;
} NODE;

void multiplication( NODE *, NODE * , NODE * );
void input( NODE * );
void output( NODE * );

void input( NODE * head )
{   int flag, sign, sum, x;
	char c;

    NODE * p = head;

	while ( (c=getchar()) !='\n' )
	{
		if ( c == '<' )
	    {    sum = 0;
	         sign = 1;
	         flag = 1;
        }
		else if ( c =='-' )
             sign = -1;
		else if( c >='0'&& c <='9' )
		{    sum = sum*10 + c - '0';
        }
		else if ( c == ',' )
        {    if ( flag == 1 )
             {    x = sign * sum;
                  sum = 0;
                  flag = 2;
		  sign = 1;
             }
        }
		else if ( c == '>' )
        {    p->next = ( NODE * ) malloc( sizeof(NODE) );
             p->next->coef = x;
             p->next->exp  = sign * sum;
             p = p->next;
             p->next = NULL;
             flag = 0;
        }
    }
}

void output( NODE * head )
{
    while ( head->next != NULL )
    {   head = head->next;
        printf("<%d,%d>,", head->coef, head->exp );
    }
    printf("\n");
}

int main()
{   

    NODE * head1, * head2, * head3;

    head1 = ( NODE * ) malloc( sizeof(NODE) );
    input( head1 );

    head2 = ( NODE * ) malloc( sizeof(NODE) );
    input( head2 );

    head3 = ( NODE * ) malloc( sizeof(NODE) );
    head3->next = NULL;
    multiplication( head1, head2, head3 );

	output( head3 );

    system("pause");

	return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

void multiplication(NODE *h1, NODE *h2, NODE *h3)
{
    if(h1->next->coef == 0||h2->next->coef == 0)
    {
        NODE *node = (NODE*)malloc(sizeof(NODE));
        node->coef = 0;
        node->exp = 0;
        node->next = NULL;
        h3->next = node;
        return;
    }
    int max_exp = 0, min_exp = 0;
    NODE *p1 = h1->next, *p2;
    int first = 1;
    while (p1)
    {
        p2 = h2->next;
        while (p2)
        {
            int exp = p1->exp + p2->exp;
            if(first)
            {
                max_exp = min_exp = exp;
                first = 0;
            }
            else
            {
                if (exp > max_exp) max_exp = exp;
                if (exp < min_exp) min_exp = exp;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    int len = max_exp - min_exp + 1;
    int* coef = (int*)calloc(len,sizeof(int));
    p1 = h1->next;
    while (p1)
    {
        p2 = h2->next;
        while (p2)
        {
            int exp = p1->exp + p2->exp;
            coef[exp - min_exp] += p1->coef * p2->coef;
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    NODE *tail = h3;
    for (int i = min_exp; i <= max_exp; i++)
    {
        if (coef[i - min_exp] != 0)
        {
            NODE *node = (NODE*)malloc(sizeof(NODE));
            node->coef = coef[i - min_exp];
            node->exp = i;
            node->next = NULL;
            tail->next = node;
            tail = node;
        }
    }
    free(coef);
}