#include<stdio.h>
int main(){
	int arr[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
while(1){
	int choice;
	printf("请输入你的选项：1-求最大值，2-求最小值，3-求和，4-求平均值。");
	scanf("%d",&choice);
	if(choice==1){
		printf("max=%d",findmax(arr));
	}
	else if(choice==2){
		printf("min=%d",findmin(arr));
	}
	else if(choice==3){
		printf("sum=%d",findsum(arr));
	}
	else if(choice==4){
		printf("avg=%d",findavg(arr));
	}
	else if(choice==0){
		break;
	}
	else{
		printf("无效输入");
	}
}
	
	int findsum(int arr[3][4]){
		for(col=0;col<4;col++){
			printf("%d\t",arr[row][col]);
			if(arr[row][col]>max){
				max=arr[row][col];
			}
			if(arr[row][col]<min){
				min=arr[row][col];
			}
			sum+=arr[row][col]	
	}
	
	int findmax(int arr[3][4]){
		for(row=0;row<3;row++){
		for(col=0;col<4;col++){
			printf("%d\t",arr[row][col]);
			if(arr[row][col]>max){
				max=arr[row][col];
			}
			if(arr[row][col]<min){
				min=arr[row][col];
			}
			sum+=arr[row][col]
	}
	
	int findmin(int arr[3][4]){
		for(row=0;row<3;row++){
		for(col=0;col<4;col++){
			printf("%d\t",arr[row][col]);
			if(arr[row][col]>max){
				max=arr[row][col];
			}
			if(arr[row][col]<min){
				min=arr[row][col];
			}
			sum+=arr[row][col]
	}
	
	int findavg(int arr[3][4]){
		for(row=0;row<3;row++){
		for(col=0;col<4;col++){
			printf("%d\t",arr[row][col]);
			if(arr[row][col]>max){
				max=arr[row][col];
			}
			if(arr[row][col]<min){
				min=arr[row][col];
			}
			sum+=arr[row][col]
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	int row,col;
	int max,min;
	double sum,avg;
	max=arr[0][0];
	min=arr[0][0];
	for(row=0;row<3;row++){
		for(col=0;col<4;col++){
			printf("%d\t",arr[row][col]);
			if(arr[row][col]>max){
				max=arr[row][col];
			}
			if(arr[row][col]<min){
				min=arr[row][col];
			}
			sum+=arr[row][col]; 
		}
		printf("\n");//每行结束换行 
	}
	avg=sum/12;
	printf("最大值%d\n",max);
	printf("最小值%d\n",min);
	printf("平均值%d\n",avg);
}
