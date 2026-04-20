#include "vol.h"
int main(void) {
	int sel;
	/*循环选择计算圆形体的体积，直到输入非1~3的数字为止*/
	while(1){	/*永久循环，通过循环体中break语句结束循环*/
		printf("1-计算球体体积");
		printf("2-计算圆柱体体积");
		printf("3-计算圆锥体体积");
		printf("其他-退出程序运算\n");
		printf("请输入计算命令");
		scanf("%d",&sel);
		if(sel<1||sel>3)//输入非1~3的数字，循环结束 
			break;
		else			//输入1~3，调用cal() 
			cal(sel);
	}
	return 0;
}
