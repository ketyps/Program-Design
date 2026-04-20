#include<stdio.h>
int main(void){
	char ch;
	int i=0,pd=0;
	while(i<6){
		ch=getchar();
		if(ch=='\n')continue;
		if(ch>='a'&&ch<='z'){
			ch=ch-'a'+'A';
		}
		if(ch>'A'&&ch<='Z'){
			int digit=ch%10;
			pd=pd*10+digit;
			i++; 
		}
	}
	printf("%d\n",pd);
	return 0;
}

