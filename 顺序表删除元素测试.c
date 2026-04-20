#include<stdio.h>
#include<malloc.h>

struct List{
    int Data[10]; // 用于存放顺序表数据
    int Last; // 下标最大元素的下标
} *PtrL;

void MakeEmpty() // 返回值是指针类型
{
    PtrL = (List *)malloc(sizeof(List));
    PtrL->Last = -1;
}

void Insert( int X, int i)//X 是要插入的元素，i 表示插入的位置，从 1 到 Last+1
{
    int j;
    for ( j = PtrL->Last; j >= i-1; j-- )
    PtrL->Data[j+1] = PtrL->Data[j]; /* 将 ai ~ an 倒序向后移动 */
    PtrL->Data[i-1] = X; /* 新元素插入 */
    PtrL->Last++; /*Last 仍指向最后元素 */
    return;
}

// 删除元素函数
// i 表示要删除元素的位置，从1开始计数
// 返回删除的元素值，如果删除失败返回-1（假设元素值都是非负的）
int Delete(int i) {
    int j;
    int deletedValue;
    
    // 检查删除位置是否合法
    if (i < 1 || i > PtrL->Last + 1) {
        printf("删除位置不合法！\n");
        return -1; // 返回-1表示删除失败
    }
    
    // 检查表是否为空
    if (PtrL->Last == -1) {
        printf("顺序表为空，无法删除！\n");
        return -1;
    }
    
    // 保存要删除的元素值
    deletedValue = PtrL->Data[i-1];
    
    // 将第i个位置之后的元素依次前移
    for (j = i-1; j < PtrL->Last; j++) {
        PtrL->Data[j] = PtrL->Data[j+1];
    }
    
    // 更新Last指针
    PtrL->Last--;
    
    return deletedValue; // 返回被删除的元素值
}

int main(){
    MakeEmpty();
    
    // 插入一些元素用于测试
    Insert(0, 1);
    Insert(1, 2);
    Insert(2, 3);
    Insert(3, 4);
    
    printf("初始顺序表内容：\n");
    for (int i = 0; i <= PtrL->Last; i++) {
        printf("%d ", PtrL->Data[i]);
    }
    printf("\n");
    
    // 测试删除操作
    int deletedValue;
    
    // 删除第2个元素（值为1）
    deletedValue = Delete(2);
    if (deletedValue != -1) {
        printf("删除第2个元素，删除的元素值为：%d\n", deletedValue);
    }
    
    printf("删除后顺序表内容：\n");
    for (int i = 0; i <= PtrL->Last; i++) {
        printf("%d ", PtrL->Data[i]);
    }
    printf("\n");
    
    // 再次删除第1个元素（值为0）
    deletedValue = Delete(1);
    if (deletedValue != -1) {
        printf("删除第1个元素，删除的元素值为：%d\n", deletedValue);
    }
    
    printf("再次删除后顺序表内容：\n");
    for (int i = 0; i <= PtrL->Last; i++) {
        printf("%d ", PtrL->Data[i]);
    }
    printf("\n");
    
    // 测试边界情况：删除位置不合法
    deletedValue = Delete(10); // 位置超出范围
    if (deletedValue == -1) {
        printf("删除位置10失败，因为位置不合法\n");
    }
    
    return 0;
}
