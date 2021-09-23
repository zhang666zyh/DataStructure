#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define OK 1
#define ERROR 0
#define MAXSIZE 10
typedef int Status;
typedef int ElemType;
typedef struct {
    ElemType *elem;
    int length;
}SqList;
// 初始化顺序表
Status initList(SqList &L) {
	L.elem = new ElemType[MAXSIZE];
	if(!L.elem){
		printf("顺序表初始化错误!!!\n");
		return ERROR;
	}
	L.length = 0;
	return OK;
}

//输出顺序表的全部元素
void displayList(SqList L) {
	int i;
    for (i = 0; i < L.length; i++) {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}

// 在顺序表的位置 i 插入元素 e
Status ListInsert_Sq(SqList &L,int i ,ElemType e){
	int j;
	if(i > MAXSIZE || i < 1 || i > L.length + 1){
		printf("插入位置错误!!!\n");
		return ERROR;
	} 
	
	for(j = L.length - 1;j >= i - 1;j--){
		L.elem[j + 1] = L.elem[j];	
	}
	L.elem[i-1] = e;
	L.length++;
	return OK;
}

// 删除顺序表中指定位置 i 的元素
Status ListDelete_Sq(SqList &L,int i){
	int j;
	if(j > MAXSIZE || i < 1 || i > L.length + 1){
		printf("删除位置错误!!!\n");
		return ERROR;
	}
	for(j = i;j <= L.length - 1;j++){
		L.elem[j - 1] = L.elem[j];
	}
	L.length--;
	return OK;
}

// 表中所有奇数排在偶数之前
void OddEvenSplit(SqList &L){
	int i = 0,j = L.length - 1;
	int temp;
	while(1){
		while(L.elem[i]%2 != 0){
			i++;
		}
		while(L.elem[j]%2 == 0){
			j--;
		}
		if(i >= j){
			break;
		}else{
			temp = L.elem[i];
			L.elem[i] = L.elem[j];
			L.elem[j] = temp;
		}
	}
}


int main() {
    int i;
    SqList sq;
    initList(sq);
    //向顺序表中添加元素
    for (i = 1; i <= MAXSIZE; i++)
        ListInsert_Sq(sq,i, rand()%100+1);
    printf("顺序表中的元素分别是：\n");
    displayList(sq);
    printf("删除第 4 个元素后的结果：\n");
    ListDelete_Sq(sq,4);
    displayList(sq);
    printf("插入第 6 个元素后的结果：\n");
    ListInsert_Sq(sq,6,99);
    displayList(sq);
    printf("表中所有奇数排在偶数之前的结果：\n");
    OddEvenSplit(sq);
    displayList(sq);
    free(sq.elem);
    return 0;
}
