#include<stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    int d1=a%10;
    int d2=(a/10)%10;
    int d3=a/100;
    int n=d1*100+d2*10+d3;
    printf("%d\n",n);
    return 0;
    }
