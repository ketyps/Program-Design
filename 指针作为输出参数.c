#include<stdio.h>
int divide(int a,int b,int *result){
	if(b==0){
		return -1;
	}
	*result=a/b;
	return 0;
}
int main(){
	int a=20,b=4,result;
	int status=divide(a,b,&result);
	if(status==0){
		printf("除法成功，商：%d\n",result);
	}else{
		printf("除法失败：除数不能为零\n");
	}
}
