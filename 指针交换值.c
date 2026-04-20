#include<stdio.h>
void swap_by_pointer(int *px,int *py){
	int temp =*px;
	*px=*py;
	*py=temp;
	printf("函数内部：*px=%d,*py=%d\n",*px,*py); 
} 
int main(){
	int a=10,b=20;
	printf("交换前：a=%d,b=%d\n,a,b");
	swap_by_pointer(&a,&b);
	printf("交换后：a=%d,b=%d\n",a,b);
	return 0;
}
