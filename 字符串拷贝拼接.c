#include<stdio.h>
#include<string.h>
int main(){
	char dest[50]="like";
	char src1[]="C language";
	char src2[]=" and Python";
	strcpy(dest,src1);
	printf("strcpyºó:%s\n",dest);
	strcat(dest,src2);
	printf("strcatºó:%s\n",dest);
	return 0; 
} 
