// #include <bits/stdc++.h>
#include <stdio.h>
#include <windows.h>

int pos[8];//在pos中已记录前n-1个皇后位置的情况下，摆放第n个及以后的方案

bool attack(int x,int y){
	if(pos[x] == pos[y])//直线攻击 
		return true;
	if(pos[x] + x == pos[y] + y)//斜线攻击 
		return true;
	if(pos[x] - x == pos[y] - y)//反斜线攻击 
		return true;
	return false;
}


bool attacking(int n){
	for (int i = 0;i<n;i++){
		if(attack(i,n))
			return true;
	}
	return false;
}

	


void queen(int n){
	for (int i = 0;i < 8;i++){
		pos[n] = i;
	
		if(attacking(n)) continue;
			
		if(n == 7){
			; 
		}
		else{
			queen(n+1);	
		}
	}
		
}
int main(){
	queen(8);
	
	
	Sleep(10000);
	return 0;
} 
