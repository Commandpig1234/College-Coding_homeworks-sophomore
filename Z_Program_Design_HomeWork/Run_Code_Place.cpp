#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <bits/stdc++.h>

namespace ZY1{//禅让制
    
    char* input_file = "input/ZY1.txt";

    int main(){
        int k=0,n=0;
        int man=1;//包括尧
        scanf("%d%d",&k,&n);
        char **vote = (char**)malloc(sizeof(char*)*n);
        for (int i=0;i<n;i++){
            vote[i] = (char*)malloc(sizeof(char)*k);//vote[0]是尧
            scanf("%s",vote[i]);
        }
        for (int i=1;i<n;i++){
            if(strcmp(vote[i],vote[0])==0){
                man++;
            }
        }
        free(vote);
        printf("%d\n",man);
        return 0;
    }   
}

namespace ZY2{//结绳记事
    char* input_file = "input/ZY2.txt";

    int untie(int n,char *s){
        // printf("Untie called\n");
        int res = 0;
        int last = -1;
        for (int i=0;i<n;i++){
            if(s[i]=='1'){
                if(last==-1){
                    last = i;
                }else{
                    res += (i - last);
                    last = -1;
                }
            }
        }
        return res;
    }

    int main(){
        int n;
        int tie=0;
        scanf("%d",&n);
        char *s = (char*)malloc(sizeof(char)*(n+1));
        scanf("%s",s);
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                tie++;
            }
        }
        if(tie%2!=0){
            printf("-1\n");
        }
        else{
            printf("%d\n",untie(n,s));
        }
        free(s);
        return 0;
    }   
}

namespace ZY3{//算筹
    char* input_file = "input/ZY3.txt";


    int main(){
        int n,q;
        scanf("%d%d",&n,&q);
        long long *origin = (long long*)malloc(sizeof(long long)*n);
        long long ori_sum = 0;//原有筹码总数
        long long odd=0,even=0;//奇数筹码堆数，偶数筹码堆数
        for (long long i=0;i<n;i++){
            scanf("%lld",&origin[i]);
            ori_sum += origin[i];
            if(origin[i]%2==0) even++;
            else odd++;
        }
        long long even_add = 0,odd_add=0;//新增偶数筹码总数，新增奇数筹码总数
        for (long long i=0;i<q;i++){
            int type,x;
            scanf("%d%d",&type,&x);
            if(type==1){//加到奇数堆
                if(x%2==0){//加完后仍为奇数
                    odd_add += x*odd;
                }
                else{//加完后全变为偶数
                    odd_add += x*odd;
                    even += odd;
                    odd = 0;
                    
                }
            }
            else{//加到偶数堆
                if(x%2==0){//加完后仍为偶数
                    even_add += x*even;
                }
                else{//加完后变为奇数
                    even_add += x*even;
                    odd += even;
                    even = 0;

                }
            }
        }
        long long final_sum = ori_sum + even_add + odd_add;
        // printf("Original sum: %lld\n", ori_sum);
        // printf("Odd piles: %lld, Even piles: %lld\n", odd_add, even_add);
        printf("%lld\n",final_sum);
        return 0;
    }   
}

namespace ZY4{//治水
    char* input_file = "input/ZY4.txt";
    
    void swap(int *l,int *r){
        int tmp = *l;
        *l = *r;
        *r = tmp;
    }

    void quick_sort(int* p,int n) {//*p第一位数地址，数的个数 
        if (n<=1) return; 
        int t = p[n-1], l = 0, r = n - 2;//l:第一个，r：倒数第二个 
        do {
            for (;r >= l;l++)
                if(p[l] > t) break;
            for (;r >= l;r--)
                if(p[r] < t) break;
            if (r >= l) swap(&p[l],&p[r]);
        } while (r >= l);
        swap(&p[l],&p[n-1]);	
        quick_sort(&p[0],l);
        quick_sort(&p[l+1],n-l-1);
    }

    int main(){
        int n,r;
        scanf("%d%d",&n,&r);
        int *a = (int*)malloc(sizeof(int)*n);
        int *b = (int*)malloc(sizeof(int)*n);
        int *dif = (int*)malloc(sizeof(int)*n);
        long long dif_total = 0;
        int is_dif = 0;
        for (int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for (int i=0;i<n;i++){
            scanf("%d",&b[i]);
            if(a[i]!=b[i]){
                dif[is_dif] = abs(b[i]-a[i]);
                dif_total += dif[is_dif];
                is_dif ++;
            }
        }
        if(is_dif > 0)
            quick_sort(dif, is_dif);//从小到大
        if(dif_total<=r){//dif全部变为0
            if((r-dif_total)%2==0)
                printf("0\n");
            else
                printf("1\n");
        }
        else{//dif_total > r，dif无法全变为0
            int dif_dif = 0,last_sum = 0,dif_dif_sum = 0;
            long long answer = 0;
            for(int i = is_dif-1;i>0;i--){
                dif_dif = dif[i]-dif[i-1];//尝试“抹平”dif间的差距
                if(dif_dif_sum != 0)
                    last_sum = dif_dif_sum;
                dif_dif_sum += dif_dif*(is_dif - i);//抹平dif_dif所需的总资源
                if(dif_dif_sum > r){//无法抹平,用last_sum抹平至与dif[i]相等
                    int r_left = r - last_sum;//dif[i]~dif[is_dif-1]均为dif[i]
                    for(int j = is_dif-1;j>=i;j--){
                        dif[j] = dif[i];
                    }
                    if(r_left > 0){
                        int times = r_left / (is_dif - i);
                        int remain = r_left % (is_dif - i);
                        for (int j = is_dif-1;j>=i;j--){
                            dif[j] -= times;
                        }
                        for (int j = is_dif-1;j>is_dif-1-remain;j--){
                            dif[j]--;
                        }
                        break;
                    }
                }
            }
            if(dif_dif_sum == r){//正好抹平
                printf("IM HERE?\n");
                for(int j = is_dif-1;j>0;j--){
                    dif[j] = dif[0];
                }
            }
            else if(dif_dif_sum < r){//继续抹平
                for(int j = is_dif-1;j>0;j--){
                    dif[j] = dif[0];
                }
                int times = (r - dif_dif_sum) / is_dif;
                int remain = (r - dif_dif_sum) % is_dif;
                for (int j = is_dif-1;j>=0;j--){
                    dif[j] -= times;
                }
                for (int j = 0;j<remain;j++){
                    dif[j]--;
                }
            }
            for (int i=0;i<is_dif;i++){
                answer += dif[i]*dif[i];
            }
            printf("%lld\n",answer);
        }
        free(a);
        free(b);
        free(dif);
        return 0;
    }
}

namespace ZY9{
    char* input_file = "input/ZY9.txt";

    typedef struct circle{
        int x;
        int y;
        double radius;
        bool done;
    }circle ;
    
    double distance(int x1,int y1,int x2,int y2){//计算距离
        return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
    }
    
    
    int main(){//扩散至与边缘 或 另一圆相切，尽可能使每个圆都与边缘相切
        int N,xa,ya,xb,yb;
        double pi = 3.1415926;
        scanf("%d",&N);
        scanf("%d %d %d %d",&xa,&ya,&xb,&yb);
        int x_max = std::max(xa,xb);
        int x_min = std::min(xa,xb);
        int y_max = std::max(ya,yb);
        int y_min = std::min(ya,yb);
        circle *circles = new circle[N+1];
        for (int i = 1;i<=N;i++){
            circles[i].done = false;
            circles[i].radius = 0;
            scanf("%d %d",&circles[i].x,&circles[i].y);
        }

        double total_area = 0.0;
        for (int i = 1; i <= N; ++i) {//N轮扩散全部点
            double max_radius_this_turn = -1.0;
            int best_circle_index = -1;//
            //遍历所有候选点，找到当前能获得最大半径的点
            for (int j = 1; j <= N; ++j) {
                if (circles[j].done) {
                    continue;
                }

                //与边界相切
                double current_radius = (double)std::min({
                    circles[j].x - x_min,
                    x_max - circles[j].x,
                    circles[j].y - y_min,
                    y_max - circles[j].y
                });

                //遍历所有已经放置的圆，用它们来进一步限制当前半径(相切)
                for (int k = 1; k <= N; ++k) {
                    if (circles[k].done) {
                        double distance_to_circle = distance(circles[j].x, circles[j].y, circles[k].x, circles[k].y);
                        //与边界或已有圆相切
                        current_radius = std::min(current_radius, distance_to_circle - circles[k].radius);
                    }
                }
                
                if (current_radius > max_radius_this_turn) {
                    max_radius_this_turn = current_radius;
                    best_circle_index = j;
                }
            }

            if (best_circle_index != -1) {
                circles[best_circle_index].done = true;
                circles[best_circle_index].radius = max_radius_this_turn;
                total_area += pi * max_radius_this_turn * max_radius_this_turn;
            }
        }

        double left_area = (x_max-x_min) * (y_max-y_min) - total_area;//剩余的最小面积
        printf("%d\n", int(left_area+0.5));//四舍五入

        delete []circles;

        return 0;
    }
    
}

#define CURZY ZY9

int main(){
    freopen(CURZY::input_file, "r", stdin);
    int t1 = GetTickCount();
    printf("PROGRAM START\n");
    CURZY::main();
    int t2 = GetTickCount() - t1;
    printf("\n---------\n总计时：%d\n", t2);
    freopen("CON", "r", stdin);
    system("pause");
    return 0;
}