#include<stdio.h>
int main(){
    int a,b,c,r=0,s=0;
    scanf("%d/%d/%d",a,b,c);
    if(a%4==0&a%100>0||a%400==0)r=1;
    if(m>1) s+=31;
    if(m>2) s+=28+r;
    if(m>3) s+=31;
    if(m>4) s+=30;
    if(m>5) s+=31;
    if(m>6) s+=30;
    if(m>7) s+=31;
    if(m>8) s+=31;
    if(m>9) s+=30;
    if(m>10) s+=31;
    if(m>11) s+=30;
        printf("%d",s+d);
    return 0;
}
