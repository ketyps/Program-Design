#include<stdio.h>
int main(){
    //定义一个数组
    int num[6];
    int i,max,min;
    int a,b;
    //键盘输入六个元素，对数组及进行初始化
    for(i=0;i<6;i++){
        printf("请输入第%d个元素：", i+1);
        scanf("%d",&num[i]);
    }
    for(i=0;i<6;i++){
    	printf("第%d个元素是%d\n",i+1,num[i]);
    }

    max=num[0];
    min=num[0];
    a=0;
    b=0;
    for(i=1;i<6;i++){
    	if(num[i]>max){
    		max=num[i];
    		a=i;
    	}
    	if(num[i]<min){
    		min=num[i];
    		b=i;
    	}
    }
    printf("最大值为%d 下标为%d，最小值为%d 下标为%d \n",max,a,min,b);
    double average,k;
    for(i=0;i<6;i++){
    	k+=num[i];
    }
    average=k/6;
    printf("average:%lf",average);
	 
}
