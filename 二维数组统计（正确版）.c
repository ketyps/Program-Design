#include<stdio.h>
int findmax(int arr[3][4]);
int findmin(int arr[3][4]);
int findsum(int arr[3][4]);
float findavg(int arr[3][4]);

int main(){
    int arr[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    
    while(1){
        int choice;
        printf("请输入你的选项：1-求最大值，2-求最小值，3-求和，4-求平均值，0-退出：");
        scanf("%d",&choice);
        
        if(choice==1){
            printf("max=%d\n",findmax(arr));
        }
        else if(choice==2){
            printf("min=%d\n",findmin(arr));
        }
        else if(choice==3){
            printf("sum=%d\n",findsum(arr));
        }
        else if(choice==4){
            printf("average=%.2f\n",findavg(arr));
        }
        else if(choice==0){
            printf("程序退出\n");
            break;
        }
        else{
            printf("输入错误，请重新输入！\n");
        }
        printf("\n");
    }
    return 0;
}

int findmax(int arr[3][4]){
    int max = arr[0][0];
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            if(arr[i][j] > max){
                max = arr[i][j];
            }
        }
    }
    return max;
}

int findmin(int arr[3][4]){
    int min = arr[0][0];
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            if(arr[i][j] < min){
                min = arr[i][j];
            }
        }
    }
    return min;
}

int findsum(int arr[3][4]){
    int sum = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            sum += arr[i][j];
        }
    }
    return sum;
}

float findavg(int arr[3][4]){
    int sum = findsum(arr);
    return (float)sum / 12; 
}





