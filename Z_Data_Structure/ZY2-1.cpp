#include <bits/stdc++.h>

typedef struct student{
    int id;
    char name[9];
} stu;


int main(){
    // freopen("input/ZY2-1.txt","r",stdin);
    int n1,n2;
    scanf("%d",&n1);
    stu *list1 = new stu[n1];
    for(int i =0;i<n1;i++){
        scanf("%d %s",&list1[i].id,&list1[i].name);
    }
    scanf("%d",&n2);
    stu *list2 = new stu[n2];
    if(n2 == 0){
        printf("the LIST2 is NULL.\n");
        return 0;
    }
    for(int i =0;i<n2;i++){
        scanf("%d %s",&list2[i].id,&list2[i].name);
    }
    bool allfound = true;
    for(int i=0;i<n2;i++){//list2
        bool isfound = false;
        for(int j =0;j<n1;j++){//list1
            if(list1[j].id == list2[i].id && strcmp(list1[j].name,list2[i].name) == 0){
                isfound = true;
                break;
            }
        }
        if(isfound == false){
            allfound = false;
            printf("%d %s is not in LIST1.\n",list2[i].id,list2[i].name);
        }
    }
    if(allfound){
        printf("the records of LIST2 are all in the LIST1.\n");
    }
    delete []list1;
    delete []list2;
    // freopen("CON","r",stdin);
    // system("pause");
    return 0;
}