#include<stdio.h>
int main(){
	int i,flag=1,m;
	printf("Enter a nnumber:");
	scanf("%d,&m");
	if(m==1)
	flag=0;
	for(i=2;i<m;i++){
		if(m%i==0){
			flag=0;
			break;
		}
	}
	if (flag==1)
	printf("Yes\n");
	else
	printf("No\n");
	return 0;
}
 
