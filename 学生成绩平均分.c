#include<stdio.h>

struct student{
	int id;
	char name[30];
	int score[4];
	float average;
}; 

enum subject{
	chinese,
	math,
	English,
	computer
};

float calcaverage(struct student s){
	int sum=0;
	for(int i=0;i<4;i++){
		sum+=s.score[i];
	}
	return (float)sum/4;
}
int main(){
	struct student s1={202401,"zhangsan",{85,70,80,50}};
	s1.average=calcaverage(s1);
	printf("学号：%d\n姓名:%d\n",s1.id,s1.name);
	printf("语文:%d 数学:%d英语:%d计算机:%d\n",
	s1.score[chinese],s1.score[math],s1.score[English],s1.score[computer]);
	printf("平均成绩：%.1f\n",s1.average);
	return 0;
}
