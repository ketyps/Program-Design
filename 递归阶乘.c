#include <stdio.h>
int f(int);
int main(void)
{int i
printf("请输入一个整数：");
scanf("%d",&i);
printf("%d",f(i));
return;
} 
int f(int n)
{
	if(n==0)
	return 1;
	else
	return n*f(n-1);
}
