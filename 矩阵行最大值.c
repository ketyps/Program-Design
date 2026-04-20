void max_row(int(*arr)[20],int m,int n){
    for(int i=0;i<m;i++){
        int a=arr[i][0];
        for(int j=1;j<n;j++){
            if(arr[i][j]>a){
                a=arr[i][j];
            }
        }
        printf("The max in line%d is :%d",i,a);
    }
}
