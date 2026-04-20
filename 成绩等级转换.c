#include<stdio.h>
int main(){
	printf("ÊäÈë³É¼¨(0-100):");
	int score;
	scanf("%d",&score);
	if (score>=90&&score<=100){printf("A");}
	else if (score>=80&&score<=89){printf("B");}
	else if (score>=70&&score<=79){printf("C");}
	else if (score>=60&&score<=69){printf("D");}
	else if (score>=0&&score<=59){printf("E");}
	else {printf("Invalid score");}
	return 0;
} 
