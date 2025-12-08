/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef enum { ATOM, LIST } ListTag;

typedef struct node {
	ListTag  tag;
	union {
		char  data;
		struct node *hp;
	} ptr;
	struct node *tp;
} GLNode;

GLNode * reverse( GLNode * );

int count;

void Substring( char *sub, char *s, int pos, int len )
{
	s = s + pos;
	while ( len > 0 )
	{	*sub = *s;
		sub++;
		s++;
		len--;
	}
	*sub = '\0';
}

void sever( char *str, char *hstr )
{   int n, i, k;
	char ch[50];
	n = strlen(str);
	i = k = 0;
	do
	{	Substring( ch, str, i++, 1 );
		if ( *ch=='(' )
			k ++;
		else if ( *ch==')' )
			k --;
	} while ( i<n && ( *ch!=',' || k!=0 ) );

	if ( i<n )
	{ 	Substring( hstr, str, 0, i-1 );
		Substring( str, str, i, n-i );
	}
	else
	{	strcpy( hstr, str );
		str[0] = '\0';
	}
}  /* sever */

int PrintGList( GLNode * T )
{
	GLNode *p=T, *q;

	if ( p==NULL )
		printf( ")" );
	else
	{	if ( p->tag==ATOM )
		{ 	if ( count > 0 )
				printf( "," );
			printf( "%c", p->ptr.data );
			count ++;
		}
		else
		{	q = p->ptr.hp;
			if ( q == NULL )
			{	if ( count > 0 )
					printf(",");
				printf("(");
			}
			else if ( q->tag == LIST )
			{	if ( count > 0 )
					printf( "," );
				printf( "(" );
				count = 0;
			}
			PrintGList( q );
			PrintGList( p->tp );
		}
	}
	return 1;
}

void print( GLNode * L )
{
	if ( L == NULL )
		printf( "()" );
	else
	{
		if ( L->tag == LIST )
			printf( "(" );
		if ( L->ptr.hp != NULL )
			PrintGList( L );
		else
		{
			printf( "()" );
			if ( L->tp == NULL )
				printf( ")" );
		}
	}
	printf( "\n" );
}

int CreateGList( GLNode **L,  char *s )
{
	GLNode *p, *q;
	char sub[100],  hsub[100];

	p = *L;
	if ( strcmp(s, "()" )==0 )
		*L = NULL;    /* 创建空表 */
	else
	{
		*L = ( GLNode * ) malloc( sizeof( GLNode ) );
		if ( strlen(s)==1 )
		{   (*L)->tag = ATOM;
			(*L)->ptr.data = s[0];
		}
		else
		{	(*L)->tag = LIST;
			p = *L;
			Substring( sub, s, 1, strlen(s)-2 );
			do
			{	sever( sub, hsub );
				CreateGList( &p->ptr.hp, hsub );
				q = p;
				if ( strlen(sub) > 0 )
				{	p = (GLNode *) malloc( sizeof(GLNode) );
					p->tag = LIST;
					q->tp = p;
				}
			} while ( strlen(sub)>0 );
			q->tp = NULL;
		}   /* else */
	}  /* else */
	return 1;
}

/**********
这是你要实现的函数。
***********/
GLNode * append(GLNode *a, GLNode *b) {
    if (a == NULL) return b;
    GLNode *p = a;
    while (p->tp != NULL)
        p = p->tp;
    p->tp = b;
    return a;
}

GLNode * reverse(GLNode *p) {
    // 1. 空表直接返回 NULL
    if (p == NULL)
        return NULL;

    // 2. 如果是原子节点，它是叶子，直接返回其拷贝
    // 注意：不能访问 p->tp，因为 CreateGList 中未初始化原子的 tp
    if (p->tag == ATOM) {
        GLNode *q = (GLNode *)malloc(sizeof(GLNode));
        q->tag = ATOM;
        q->ptr.data = p->ptr.data;
        q->tp = NULL;
        return q;
    }

    // 3. 如果是列表节点 (骨架节点)
    // 递归反转表头 (可能是子表，也可能是原子)
    GLNode *new_head = reverse(p->ptr.hp);
    
    // 递归反转表尾 (剩余的列表)
    GLNode *new_tail = reverse(p->tp);

    // 创建新的骨架节点，装载反转后的表头
    GLNode *node = (GLNode *)malloc(sizeof(GLNode));
    node->tag = LIST;
    node->ptr.hp = new_head;
    node->tp = NULL;

    // 将当前节点拼接到反转后的表尾后面
    return append(new_tail, node);
}
/*******************/

int main( )
{
    freopen("input/8-3.txt","r",stdin);
	char list[100];
	GLNode *L, *G;
	int d;

	count = 0;
	scanf("%s", list);
	CreateGList( &L, list );

/*	print( L );   */
	G = reverse( L );
	count = 0;
	print( G );
    freopen("CON","r",stdin);
    system("pause");
	return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */