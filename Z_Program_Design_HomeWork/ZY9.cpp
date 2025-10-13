#include <bits/stdc++.h>

typedef struct circle{
    int x;
    int y;
    double radius;
}circle;

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
    int *order = new int[N];
    for (int i = 1;i<=N;i++){
        circles[i].radius = 0;
        order[i-1] = i;
        scanf("%d %d",&circles[i].x,&circles[i].y);
    }

    double total_area = 0.0;
    double max_area = 0.0;
    do{
        total_area = 0.0;
        for(int index = 0;index<N;index++){
        //与边界相切
            int i = order[index];
            double current_radius = (double)std::min({ 
                circles[i].x - x_min, 
                x_max - circles[i].x, 
                circles[i].y - y_min, 
                y_max - circles[i].y 
            });

            //遍历所有已经放置的圆，用它们来进一步限制当前半径(相切) 
            for (int k_index = 0; k_index < index; k_index++) { 
                int k = order[k_index];
                double distance_to_circle = distance(circles[i].x, circles[i].y, circles[k].x, circles[k].y); 
                //与边界或已有圆相切 
                current_radius = std::min(current_radius, distance_to_circle - circles[k].radius);
            }
            circles[i].radius = current_radius;
            total_area +=pi*current_radius*current_radius;
        }
        max_area = std::max(max_area,total_area);
    }while(std::next_permutation(order,order+N));

    double left_area = (x_max-x_min) * (y_max-y_min) - max_area;//剩余的最小面积
    printf("%d\n", int(left_area+0.5));//四舍五入

    delete []circles;
    delete []order;
    return 0;
}