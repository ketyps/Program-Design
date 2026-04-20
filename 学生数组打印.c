#include<stdio.h>
struct student{
	int id;
	char name[20];
	float score;
}; 
int main(){
	struct student stu_arr[3]={
		{101,"zhangsan",95.5},{102,"lisi",808.0},{100,"wangwu",92.0}
	};
	int len=3;
	printf("班级学生列表：\n");
	int i;
	for(i=0;i<len;i++){
		printf("第%d个学生：学号=%d，姓名=%s,成绩=%.1f\n",i+1,stu_arr[i].id,stu_arr[i].name,stu_arr[i].score);
	}
	return 0;
}
