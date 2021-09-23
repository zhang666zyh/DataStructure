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
// ��ʼ��˳���
Status initList(SqList &L) {
	L.elem = new ElemType[MAXSIZE];
	if(!L.elem){
		printf("˳����ʼ������!!!\n");
		return ERROR;
	}
	L.length = 0;
	return OK;
}

//���˳����ȫ��Ԫ��
void displayList(SqList L) {
	int i;
    for (i = 0; i < L.length; i++) {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}

// ��˳����λ�� i ����Ԫ�� e
Status ListInsert_Sq(SqList &L,int i ,ElemType e){
	int j;
	if(i > MAXSIZE || i < 1 || i > L.length + 1){
		printf("����λ�ô���!!!\n");
		return ERROR;
	} 
	
	for(j = L.length - 1;j >= i - 1;j--){
		L.elem[j + 1] = L.elem[j];	
	}
	L.elem[i-1] = e;
	L.length++;
	return OK;
}

// ɾ��˳�����ָ��λ�� i ��Ԫ��
Status ListDelete_Sq(SqList &L,int i){
	int j;
	if(j > MAXSIZE || i < 1 || i > L.length + 1){
		printf("ɾ��λ�ô���!!!\n");
		return ERROR;
	}
	for(j = i;j <= L.length - 1;j++){
		L.elem[j - 1] = L.elem[j];
	}
	L.length--;
	return OK;
}

// ����������������ż��֮ǰ
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
    //��˳��������Ԫ��
    for (i = 1; i <= MAXSIZE; i++)
        ListInsert_Sq(sq,i, rand()%100+1);
    printf("˳����е�Ԫ�طֱ��ǣ�\n");
    displayList(sq);
    printf("ɾ���� 4 ��Ԫ�غ�Ľ����\n");
    ListDelete_Sq(sq,4);
    displayList(sq);
    printf("����� 6 ��Ԫ�غ�Ľ����\n");
    ListInsert_Sq(sq,6,99);
    displayList(sq);
    printf("����������������ż��֮ǰ�Ľ����\n");
    OddEvenSplit(sq);
    displayList(sq);
    free(sq.elem);
    return 0;
}
