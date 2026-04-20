#include<stdio.h>
#include<math.h>
int main(){
	int money,year;
	double rate,sum;
	printf("请输入金额：");
	scanf("%d",&money); 
	printf("请输入存期：");
	scanf("%d",&year);
	printf("请输入利率：");
	scanf("%lf",&rate);
	sum=money*pow(1+rate,year);
	printf("总金额为%.2f",sum);
	return 0;
}
