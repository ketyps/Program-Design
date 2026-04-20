#include<stdio.h>
int main(){
	char str1[]={'h','e','l','l','o','\0'};
	printf("%s\n",str1);
	char str2[]="hello";
	char* p=str2;
	*p='H';
	*(p+1)='E'; 
	printf("str:%s\n",str2);
	printf("%zu",sizeof(str2));
	while(*p!='\0'){
		printf("%c",*p);
		p++;
	}
	return 0;
}
