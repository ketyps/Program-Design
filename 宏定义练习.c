#include<stdio.h>
#define ABS(x) ((x)>=0?(x):-(x))
#define BMI(weight,height)((weight)/((height)/100.0*(height)/100.0))
int main(){
	printf("ABS(-5)=%d\n",ABS(-5));
	printf("ABS(3.2)=%d\n",ABS(3.2));
	
	float w=60.0,h=170.0;
	printf("BMI(%.1fkg,%.1fcm)=%.2f\n",w,h,BMI(w,h));
	return 0;
}
