#include<stdio.h>
int main(){
	int a,b ;
	scanf("%d %d",&a,&b);
	int max=0;
	if(a>b){
		max=a;
	}
	else{
		max=b;
	}
	printf("max=%d\n",max);
}

