#include <bits/stdc++.h>
// #include <windows.h>

int n, m;
long long M,solution_count;//M == 2 power m
int cards[12];

void solve(int index, int xor_sum){
    if(index == n-1){//递归结束
        if(xor_sum != cards[index -1]){
            solution_count++;
        }
        return;
    }

    for(int i = 0; i < M; i++){
        if(index > 0){
            if(i == cards[index - 1]){
                continue;
            }
        }
        cards[index] = i;
        solve(index + 1, xor_sum ^ i);
    }
}

int main(){
    // int t1 = GetTickCount();
    // freopen("input/ZY12.txt","r",stdin);
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &n, &m);
        M = pow(2,m);
        solution_count = 0;
        solve(0, 0);
        printf("%lld\n", solution_count);
    }
    // int t2 = GetTickCount() - t1;
    // printf("\n -------- \n Time Use : %d ms\n",t2);
    // freopen("CON","r",stdin);
    // system("pause");
    return 0;
}