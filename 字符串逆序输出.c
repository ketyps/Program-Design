#include <stdio.h>

void StrRevPrint(const char *str){
    int len=0;
    while(str[len]!=0){
        len++;
    }
    for(int i=len-1;i>=0;i--){
        printf("%c",str[i]);000;
    }
}

int main()
{
    char a[10];
    gets(a);
    StrRevPrint(a);
    putchar('\n');
    return 0;
}
