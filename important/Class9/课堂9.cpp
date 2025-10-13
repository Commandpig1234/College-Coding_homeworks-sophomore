/*
文件： FILE* fp = fopen("prime.txt","w");
FILE*文件指针类型  fp变量名称  fopen打开文件函数   "prime.txt"文件路径名   "w"打开方式(写模式，创建一个)"r"(读模式) "a"（追加模式） r+w+a+为（。。扩展):打开\创建一个文件读写 
FILE* fp = fopen("../prime.txt","w")../ 向上一级 test/向下一级的子目录    {相对路径
 
fclose(fp)关闭文件函数;
fprintf(fp,"%d\n",i);写入文件 
fscanf(fp,"%d",&i)
feof(fp):文件结束，返回bool，结束时true，否则false。 (上一次读取成功后，文件恰结束，返回false；结束且读取失败一次后，返回true) 
(文本模式)

二进制模式
fopen(name,"wb");"rb"
fwrite(首地址，大小，个数，fp);内存拷到文件 
fread(首地址，大小，个数，fp);文件拷到内存 
wxJexEditor  16进制编辑器 

对齐 
#pragma pack(1)避免自动填补 
struct BMPFileHeader {
	char id[2];
	int size;
	short res1;
	short res2;
	int offset;
};
sizeof(BMPFileHeader) = 16 !=14 :#pragma pack(1)解决
端：多字节数据在内存中的存放顺序（由cpu决定）：大段，高位放在低地址（00 00 03 8A）;小段，低位放在低地址(8A 03 00 00) 
扩展：文件：能一个一个顺序读写 
*/

#include <bits/stdc++.h>
#define N 100000
//bool isPrime[N+1]; 
/*int main(){
	FILE* fp = fopen("prime.txt","w");
	for (int i =2;i<= N;i++)
		isPrime[i] = true;
	for(int i=2;i*i <= N;i++)
		 if(isPrime[i])
		 	for (int j=2;i*j<=N;j++)
		 		isPrime[i*j] = false;
	for(int i=2;i<=N;i++)
		if(isPrime[i])
			fprintf(fp,"%d\n",i);
	fclose(fp);			  
	return 0;
}*/
int main(){
	FILE* fp ;
	fp = fopen("prime.txt","a+");
	int n = 0,m=0,a=0;
	scanf("%d",&n);
	fprintf(fp,"%d",n); 

	bool is = true;

fscanf(fp,"%d %d %d",&n,&m,&a);
printf("%d",n);
fclose(fp);

	return 0;
}
