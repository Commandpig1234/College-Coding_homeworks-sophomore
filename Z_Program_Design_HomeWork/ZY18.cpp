#include <bits/stdc++.h>

typedef long long ll;

int main(){

    // freopen("input/ZY18.txt","r",stdin);

    int n = 0;
    scanf("%d",&n);
    int* food = (int*)malloc(sizeof(int) * n);
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&food[i]);
    }
    ll sum = food[0];
    ll sum_max = food[0];
    for(int i = 1;i<n;i++)
    {
        sum += food[i];
        if(sum>sum_max)
        {
            sum_max = sum;
        }
        if(sum < 0)
        {
            sum = 0;
        }
    }
    printf("%lld\n",sum_max);

    // freopen("CON","r",stdin);
    // system("pause");
}