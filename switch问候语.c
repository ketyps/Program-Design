#include<stdio.h>
int main(){
	int type;
	scanf("%d",&type);
	switch (type){
		case 1:
			printf("Hello!");
			break;
	    case 2:
			printf("good morning!");
			break;
		case 3:
			printf("good evening!");
			break;
		case 4:
			printf("Bey Bey!");
			break;
		default:
			printf("What?");
	}
	return 0;
} 
