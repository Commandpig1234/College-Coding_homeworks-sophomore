#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(int* a,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int quickselect(int* arr, int low, int high, int k)
{
    while (low <= high)
    {
        if (low == high)
        {
            return arr[low];
        }
        int pivot = arr[low];
        int i = low - 1;
        int j = high + 1;

        while (1)
        {
            do
            {
                i++;
            } while (arr[i] < pivot);
            do
            {
                j--;
            } while (arr[j] > pivot);
            if (i >= j)
            {
                break;
            }
            swap(&arr[i], &arr[j]);
        }

        int left_part_size = j - low + 1;

        if (k <= left_part_size)
        {
            high = j;
        }
        else
        {
            low = j + 1;
            k = k - left_part_size;
        }
    }
    return -1;
}

int main()
{
    // freopen("input/ZY16.txt","r",stdin);

    int N = 0;
    scanf("%d",&N);
    int *beacon = (int*)malloc(sizeof(int) * N);
    for(int i = 0;i<N;i++)
    {
        scanf("%d",&beacon[i]);
    }
    int* copy = (int*)malloc(sizeof(int) * N);
    int T = 0;
    scanf("%d",&T);
    int action = 0;
    for(int i = 0;i<T;i++)
    {
        scanf("%d",&action);
        if(action == 1)
        {
            int k,x;
            scanf("%d %d",&k,&x);
            beacon[k] = x;
        }
        else if(action == 2)
        {
            int L,R,k;
            scanf("%d %d %d",&L,&R,&k);
            int len = R-L+1;
            memcpy(copy, beacon + L, len * sizeof(int));
            int ans = quickselect(copy,0,len-1,k);
            printf("%d\n",ans);
        }
    }
    free(beacon);
    free(copy);

    // freopen("CON","r",stdin);
    // system("pause");
    
}