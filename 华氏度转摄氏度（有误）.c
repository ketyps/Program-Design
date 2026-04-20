#include<stdio.h>
int main(void)
{
int a;
double b;
printf("请输入一个华氏度");
scanf("%d",&a) 
a=100;
b=5*(a-32)/9;
printf("a=%d,b=%lf\n",a,b);
return 0;
}
