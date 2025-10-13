#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

namespace ZY1{
    char* input_file = "input/ZY1.txt";

    typedef struct Node{
        long long id;
        struct Node *next;
    }Node;

    Node* init_list(long long n){
        Node *head = (Node*)malloc(sizeof(Node));
        head->id = n;
        Node *p = head;//p指向最后一个节点
        for (int i=n-1;i>0;i--){
            Node *newnode = (Node*)malloc(sizeof(Node));
            newnode->id = i;
            newnode->next = head;
            head = newnode;
        }
        p->next = head;//形成环
        return head;
    }

    int main(){
        long long n,k,m;
        scanf("%lld,%lld,%lld",&n,&k,&m);//n个人，报数从k开始，报到m出列
        if(n<1 || k<1 || m<1){
            printf("n,m,k must bigger than 0.\n");
            return 0;
        }
        if(k>n){
            printf("k should not bigger than n.\n");
            return 0;
        }
        Node *head = init_list(n);
        while(head->id != k){//找到k位置
            head = head->next;
        }
        int count = 0;
        for(long long i =1;i<n;i++){
            if(m==1){
                Node *todelete = head;
                printf("%lld", todelete->id);
                count++;
                if(count % 10 == 0) printf("\n");
                else printf(" ");
                head = head->next;
                free(todelete);
            }
            else{
                for(int j =1;j<m-1;j++){
                    head = head->next;
                }
                Node *todelete = head->next;
                Node *prev = head;
                prev->next = todelete->next;
                head = todelete->next;
                printf("%lld", todelete->id);
                count++;
                if(count % 10 == 0) printf("\n");
                else printf(" ");
                free(todelete);
            }
        }
        printf("%lld\n",head->id);
        free(head);
        return 0;
    }
}

namespace ZY2_1{//验证表
    char* input_file = "input/ZY2-1.txt";
    int main(){
        return 0;
    }   
    
}

#define CURZY ZY1

int main()
{
    freopen(CURZY::input_file, "r", stdin);
    int t1 = GetTickCount();
    CURZY::main();
    int t2 = GetTickCount() - t1;
    printf("\n---------\n总计时：%d\n", t2);
    freopen("CON", "r", stdin);
    system("pause");
    return 0;
}