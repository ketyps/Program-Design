#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n/2+1;i++){
        for(int j=0;j<n/2-i;j++){
        printf(" ");
        }
    }
    for(int k=0;k<2*i+1;k++){
        printf("*");
    printf("\n");
    }
    for(int i=n/2-1;i>=0;i--){
        for(int j=0;j<n/2-i;j++){
            printf(" ");
    for(int k=0;k<2*i+1;k++){
        printf("*");
    }
    printf("\n");
    }
    return 0;
}
