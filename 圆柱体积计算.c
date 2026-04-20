#include<stdio.h>
double cylinder(double r, double h);

int main(void){
    double r, h, v;
    printf("请输入半径，高："); 
    scanf("%lf%lf", &r, &h);
    v = cylinder(r, h);
    printf("r=%.2f, h=%.2f, 体积=%.2f\n", r, h, v);
    return 0; 
} 
double cylinder(double r, double h){
    double result;
    result = 3.14 * r * r * h;
    return result;
}
