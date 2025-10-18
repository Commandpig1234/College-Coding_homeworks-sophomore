#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll merge(int *army, int left, int mid, int right,int* temp)
{
    int i = left;       
    int j = mid + 1;    
    int k = left;       
    ll reverse_count = 0;

    while ((i <= mid) && (j <= right)) {
        if (army[i] <= army[j])
        {
            temp[k++] = army[i++];
        }else
        {
            temp[k++] = army[j++];
            reverse_count += (ll)(mid - i + 1);
        }
    }

    while (i <= mid)
    {
        temp[k++] = army[i++];
    }

    while (j <= right)
    {
        temp[k++] = army[j++];
    }

    for (i = left; i <= right; i++)
    {
        army[i] = temp[i];
    }

    return reverse_count;
}
ll merge_sort_and_count(int *army, int left, int right,int* temp)
{
    ll reverse_count = 0;
    if (left < right)
    {
        int mid = left + (right - left) / 2; 

        reverse_count += merge_sort_and_count(army, left, mid,temp);
        reverse_count += merge_sort_and_count(army, mid + 1, right,temp);
        reverse_count += merge(army, left, mid, right,temp);
    }
    return reverse_count;
}

int main()
{
    
    // freopen("input/ZY19.txt","r",stdin);
    
    int N;
    while (scanf("%d", &N) != EOF)
    {
        int *army = (int*)malloc(sizeof(int) * N);
        int *temp = (int*)malloc(sizeof(int) * N);
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &army[i]);
        }

        ll result = merge_sort_and_count(army, 0, N - 1,temp);
        printf("%lld\n", result);

        free(army);
        free(temp);
    }

    // freopen("CON","r",stdin);
    // system("pause");

    return 0;
}