#include <bits/stdc++.h>
//链表实现栈
/*
双向链表
struct double_linked_node {
	int n;
	linked_node *next *prev;
}

struct tree_node{
	int n;
	tree_node *left,*right;
}

*/
struct linked_node{ int n; linked_node * next; };
linked_node * head = NULL;//链表头，初始为空，说明没有元素
void stack_in(int x){
	linked_node * p = (linked_node *)malloc(sizeof(linked_node));//定义linked_node 类型指针变量 p 
	p->n = x;//箭头：拿着一个指针找到某一项  指针->项
	p->next = head;
	head = p;
}
bool stack_out(int *px){//出栈
	if(head == NULL)
		return false;
	*px = head->n;
	linked_node * p = head;
	head = head->next;
	free(p);
	return true;
}

