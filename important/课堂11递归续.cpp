/*
QT Python Java图形界面    不：MFC(microsoft)
快速排序quick sort：适用于随机散布，原本就有序不适用 平均O(n logn) 最差O(n^2) 
归并排序：O(nlogn)
*/


#include <bits/stdc++.h>
#include <windows.h>
int m = 0;
/*void hanoi_move(int n,char from,char to){//把n个盘子从from挪到to 
	if (n == 1){
		printf("%c -> %c\n",from,to);
		m++;
		return ;
	}
	char tmp = 'A' + 'B' + 'C' - from - to;
	hanoi_move(n-1,from,tmp);//挪n-1个盘子 
	hanoi_move(1,from,to);//挪1个盘子
	hanoi_move(n-1,tmp,to);//挪n-1个盘子
	
	
}*/
int steps[20];
int num = 0;
//在steps已记录了num步的情况下，输出下n台阶的方案 

void hanoi_move(int n,char from,char tmp,char to){//把1~n号盘子，从from经tmp挪到to 
	if(n == 0)
		return;
	hanoi_move(n-1,from,to,tmp);//挪1~n-1号盘子 
	printf("%d : %c -> %c\n",n,from,to);//挪第n号盘子 
	m++;
	hanoi_move(n-1,tmp,from,to);//挪1~n-1号盘子 
}

void down(int n){
	if(n==0){
			//输出走法 
	}
	if(n>=1){
		steps[num++] = 1;
		down(n-1);
		num--;	//回溯：使得全局变量恢复到递归调用前的状态，以便下一次递归调用 
	}
	if(n>=2){
		steps[num++] = 2;
		down(n-2);
		num--;
	}
	if(n>=3){
		steps[num++] = 3;
		down(n-3);
		num--;
	}
}
int main(){
	int n = 0;
	scanf("%d",&n);
	printf("%d",down(n));
	//hanoi_move(n,'A','B','C');
	//printf("%d",m);
	return 0;
}

