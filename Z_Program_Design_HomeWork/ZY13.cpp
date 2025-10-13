#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

void swap(ll *l, ll *r){
	ll tmp = *l;
	*l = *r;
	*r = tmp;
}

void merge_sort(ll *p, int n){
	if(n <= 1) return;
	int l = n / 2, r = n - n / 2;
	merge_sort(p, l);
	merge_sort(p + l, r);
	ll *pn = (ll*)malloc(sizeof(ll) * n);
	int i = 0, j = l, k = 0;
	while(i < l && j < n){
		if(p[i] > p[j])
			pn[k++] = p[j++];
		else
			pn[k++] = p[i++];
	}
	for(; i < l; i++) pn[k++] = p[i];
	for(; j < n; j++) pn[k++] = p[j];
	for(int i = 0; i < n; i++) p[i] = pn[i];
	free(pn);
}

ll get_min(ll *cost, int n, int *cost_index, ll *cost_sum, int *sum_head, int sum_tail){
    ll value;
    if(*cost_index >= n)
    {
        value = cost_sum[*sum_head];
        (*sum_head)++;
    } 
    else if(*sum_head >= sum_tail)
    {
        value = cost[*cost_index];
        (*cost_index)++;
    } 
    else {
        if(cost[*cost_index] < cost_sum[*sum_head])
        {
            value = cost[*cost_index];
            (*cost_index)++;
        }
        else
        {
            value = cost_sum[*sum_head];
            (*sum_head)++;
        }
    }
    return value;
}


int main()
{
    // freopen("input/ZY13.txt","r",stdin);

    int n = 0;
    scanf("%d", &n);

    if (n <= 1)
    {
        printf("0\n");
        return 0;
    }
    ll *cost = (ll*)malloc(sizeof(ll) * n);
    for(int i = 0; i < n; i++)
    {
        scanf("%lld", &cost[i]);
    }
    merge_sort(cost, n);
    ll *cost_sum = (ll*)malloc(sizeof(ll) * (n - 1)); 
    ll total_cost = 0;

    int cost_index = 0;       
    int sum_head = 0;    
    int sum_tail = 0;    
    for (int i = 0; i < n - 1; i++)
    {
        ll min1 = get_min(cost, n, &cost_index, cost_sum, &sum_head, sum_tail);
        ll min2 = get_min(cost, n, &cost_index, cost_sum, &sum_head, sum_tail);

        ll merge_result = min1 + min2;
        total_cost += merge_result;

        cost_sum[sum_tail] = merge_result;
        sum_tail++;
    }
    
    printf("%lld\n", total_cost);
    free(cost);
    free(cost_sum);

    // freopen("CON","r",stdin);
    // system("pause");
    return 0;
}