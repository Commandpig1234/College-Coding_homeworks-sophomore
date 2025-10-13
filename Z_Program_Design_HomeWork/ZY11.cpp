#include <bits/stdc++.h>

typedef struct points{
    int x;
    int y;
}points;

double distance(points p1, points p2) {
    long long dx = (long long)p1.x - p2.x;
    long long dy = (long long)p1.y - p2.y;
    return sqrt((double)(dx * dx + dy * dy));
}

long long vector_multi(points p1, points p2, points p3) {
    long long x1 = (long long)p2.x - p1.x;
    long long y1 = (long long)p2.y - p1.y;
    long long x2 = (long long)p3.x - p1.x;
    long long y2 = (long long)p3.y - p1.y;
    return x1 * y2 - x2 * y1;
}

int main(){
    freopen("input/ZY11.txt","r",stdin);
    int n;
    scanf("%d",&n);
    if(n==1){
        printf("0\n");
        return 0;
    }
    points *land = new points[n];
    for(int i=0;i<n;i++)
        scanf("%d %d",&land[i].x,&land[i].y);
    if(n==2){
        printf("%lf\n",distance(land[0],land[1])*2);
        delete []land;
        return 0;
    }
    double length = 0;
    for (int i =0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(i == j)  continue;
            bool is_border = true;
            int first = 0;
            for(int k = 0;k<n;k++){
                if(k == i || k == j)    continue;

                long long vector = vector_multi(land[i],land[j],land[k]);
                printf("vector of %d %d %d is %lld\n",i,j,k,vector);
                if (vector == 0){
                    if( (distance(land[i],land[j]) > distance(land[i],land[k]) ) * (distance(land[i],land[j]) > distance(land[j],land[k])) == 0){
                        printf("not land\n");
                        is_border = false;
                        break;
                    }
                }
                
                if(first == 0){
                    if(vector > 0)  first = 1;
                    else if(vector <0) first = -1;
                }
                else {
                    int current_sign = 0;
                    if(vector > 0)  current_sign= 1;
                    else if(vector <0) current_sign = -1;
                    if (current_sign != first) {
                        is_border = false;
                        printf("NOT border\n");
                        break;
                    }
                }
            }
            if(is_border){
                length += distance(land[i],land[j]);
                printf("%d and %d is border\n",i,j);
            }
            
        }
    }
    printf("%lf\n",length);
    delete []land;
    freopen("CON","r",stdin);
    system("pause");
}