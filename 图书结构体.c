#include<stdio.h>

struct publisher{
	char name[30];
	int year,month,day;
};


struct book{
	char ISBN[30],name[30],writer[30],price[30];
	struct publisher;
};

int main(){
	struct book printbook={
		"123456" ,
		"abc",
		"k.160",
		"110",
		//{"press",1978,12,20};
	};
	printf("ISBN: %s\n书名: %s\n作者: %s\n价格: %s元\n出版社: %s\n出版日期: %d年%d月%d日\n",
           printbook.ISBN,
		   printbook.name,
           printbook.writer,
           printbook.price,
           printbook.publisher.name,
           printbook.publisher.year,
           printbook.publisher.month,
           printbook.publisher.day);
           return 0;
}

