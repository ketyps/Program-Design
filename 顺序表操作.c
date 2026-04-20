#include<stdio.h>
#include<malloc.h>

struct List{
    int Data[10];
    int Last;
} *PtrL;

void MakeEmpty() {
    PtrL = (struct List*)malloc(sizeof(struct List));
    PtrL->Last = -1;
}

void Insert(int X, int i) {
    int j;
    
    if (PtrL->Last >= 9) {
        printf("顺序表已满！\n");
        return;
    }
    
    if (i < 1 || i > PtrL->Last + 2) {
        printf("插入位置错误！\n");
        return;
    }
    
    for (j = PtrL->Last; j >= i-1; j--)
        PtrL->Data[j+1] = PtrL->Data[j];
    
    PtrL->Data[i-1] = X;
    PtrL->Last++;
    printf("插入成功！\n");
}

int Delete(int i) {
    int j, deletedValue;
    
    if (i < 1 || i > PtrL->Last + 1) {
        printf("删除位置错误！\n");
        return -1;
    }
    
    if (PtrL->Last == -1) {
        printf("顺序表为空！\n");
        return -1;
    }
    
    deletedValue = PtrL->Data[i-1];
    
    for (j = i-1; j < PtrL->Last; j++)
        PtrL->Data[j] = PtrL->Data[j+1];
    
    PtrL->Last--;
    printf("删除成功！\n");
    return deletedValue;
}

void Display() {
    int i;
    
    if (PtrL->Last == -1) {
        printf("顺序表为空！\n");
        return;
    }
    
    printf("顺序表内容：\n");
    for (i = 0; i <= PtrL->Last; i++) {
        printf("位置%d: %d\n", i+1, PtrL->Data[i]);
    }
    printf("元素总数: %d\n\n", PtrL->Last + 1);
}

int main() {
    int choice, value, position;
    
    MakeEmpty();
    
    printf("=== 顺序表操作程序 ===\n");
    
    while(1) {
        printf("请选择操作:\n");
        printf("1. 插入元素\n");
        printf("2. 删除元素\n");
        printf("3. 显示顺序表\n");
        printf("4. 退出程序\n");
        printf("选择: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("请输入要插入的元素值: ");
                scanf("%d", &value);
                printf("请输入要插入的位置(1-%d): ", PtrL->Last + 2);
                scanf("%d", &position);
                Insert(value, position);
                break;
                
            case 2:
                printf("请输入要删除的位置(1-%d): ", PtrL->Last + 1);
                scanf("%d", &position);
                Delete(position);
                break;
                
            case 3:
                Display();
                break;
                
            case 4:
                printf("程序结束！\n");
                return 0;
                
            default:
                printf("无效选择！\n");
        }
    }
}
