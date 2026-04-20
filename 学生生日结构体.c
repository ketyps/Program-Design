#include<stdio.h>
struct date{
int year;
int month;
int day;	
};
struct student{
	int id;
	char name[20];
	struct date birthday;
};

int main(){
	struct student s1={
		11101,
		"zhangsan",
		{2005,01,01}
	};
	printf("姓名：%s，生日：%d年%d月%d日",s1.name,s1.birthday.year,
	s1.birthday.month,s1.birthday.day);
	return 0;
}
