#include<stdio.h>
int main(void){
	int num;
	printf("请输入一个0~9之间的数字：");
	scanf("%d",&num);
	pyramid(num);
	return 0;
	 
} 
void pyramid(int n){
	int i;
	for(j=1;j<=n;i++){
		int j,k;
		for(j=1;j<=n-i;j++){
			printf(" ");
		}
		printf("\n")
	}
	return;
}
