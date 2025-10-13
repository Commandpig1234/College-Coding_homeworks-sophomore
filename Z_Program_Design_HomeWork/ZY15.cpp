#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int* arr, int start, int end){
    while(start<end){
        swap(&arr[start],&arr[end]);
        start++;
        end--;
    }
}

void print_permutation(int* arr, int n){
    for (int i = 0; i < n; i++) {
        printf("%d%c", arr[i], (i == n - 1) ? '\n' : ' ');// 最后\n
    }
}

bool next_permutation(int* arr, int n){
    int k = -1;
    for(int i = n-2;i>=0;i--)
    {
        if(arr[i]<arr[i+1])//最后一个升序
        {
            k = i;
            break;
        }
    }
    if(k == -1)
    {
        return false;//没有升序，结束
    }
    int l = -1;
    for(int i = n-1;i>k;i--)
    {
        if(arr[i] > arr[k])//最后一个大于arr[k]
        {
            l = i;
            break;
        }
    }
    swap(&arr[k],&arr[l]);//交换
    reverse(arr,k+1,n-1);//反转
    return true;
}


int main()
{
    // freopen("input/ZY15.txt","r",stdin);
    
    int n;
    scanf("%d", &n);
    int p[8];
    for (int i = 0; i < n; i++)
    {
        p[i] = i + 1;
    }
    do
    {
        print_permutation(p, n);
    }while(next_permutation(p, n));

    // freopen("CON","r",stdin);
    // system("pause");
    return 0;
}