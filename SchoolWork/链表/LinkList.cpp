/* Created by 张宇航.
 * NAME:LinkList
 * DATE:2021/9/23
 * MyWeb:zhang666zyh.github.io
 * Talk is cheap,show me the code!!!
 */
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
typedef int Status;
typedef int ElemType;
typedef struct LNode {
    ElemType elem;
    struct LNode *next;
}LNode, *LinkList;
//初始化单链表（带头结点）
Status initList(LinkList &L) {
    L = new LNode;
    L->next = NULL;
    return OK;
}

//在 L 中第 i 个元素之前插入数据元素 e
Status ListInsert_L(LinkList &L,int i,ElemType e){
    LNode* p,*s;
    p = L;
    int j = 0;
    while(p && j < (i - 1)){
        p = p->next;
        ++j;
    }
    if(!p || j > (i - 1)){
        printf("ERROR!!!\n");
    }
    s = new LNode;
    s->elem = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

// 遍历并输出全部元素
void display(LinkList L) {
    LinkList temp = L;//将 temp 指针重新指向头结点
    while (temp->next) {
        temp = temp->next;
        printf("%d ", temp->elem);
    }
    printf("\n");
}

//将线性表 L 中第 i 个数据元素删除
Status ListDelete_L(LinkList &L,int i,ElemType &e){
    LNode* p = L;
    LNode* q = new LNode;
    int j = 0;
    while(p && j < (i - 1)){
        p = p->next;
        ++j;
    }
    if(!p || j > (i - 1)){
        printf("Exception!!!\n");
        return ERROR;
    }
    q = p->next;
    p->next = q->next;
    delete q;
    return OK;
}

// 取值，读取单链表中第 i 个元素的数据值
Status GetElem_L(LinkList L,int i,ElemType &e){
    LinkList p = L->next;
    int j = 1;
    while(p && j < i){
        p = p->next;
        ++j;
    }
    if(!p || j > i){
        printf("Exception!!!\n");
        return ERROR;
    }
    e = p->elem;
    return OK;
}

//在有序单链表中插入元素，链表仍然有序
Status insertLinkOrder(LinkList &L,ElemType e){
    LNode* pre,*p,*s;
    pre = L,p = L->next;
    s = new LNode;
    s->elem = e;
    s->next = NULL;
    while(p != NULL && p->elem < e){
        pre = p;
        p = p->next;
    }
    s->next = pre->next;
    pre->next = s;
    return OK;
}

//两个非递减有序单链表 La 和 Lb 合并成一个非递增有序链表 Lc
void MergeOrderList (LinkList &La, LinkList &Lb, LinkList &Lc){
    LNode* p = La->next;
    LNode* q = Lb->next;
    LNode* r;
    Lc = La;
    Lc->next = NULL;
    free(Lb);
    r = Lc;

    while(p != NULL && q != NULL){
        if(p->elem <= q->elem){
            r->next = p;
            p = p->next;
            r = r->next;
        }else{
            r->next = q;
            q = q->next;
            r = r->next;
        }
    }

    r->next = NULL;

    if(p != NULL){
        r->next = p;
    }
    if(q != NULL){
        r->next = q;
    }
}

int main() {
    LinkList L = NULL;
    printf("初始化链表为：\n");
    initList(L);
    for (int i=1;i<=10;i++)
        ListInsert_L(L,i,rand()%100+1);
    display(L);
    printf("在第 5 的位置插入元素 120：\n");
    ListInsert_L(L, 5, 120);
    display(L);
    printf("第 6 个元素的值为：");
    ElemType val;
    if (GetElem_L(L, 6,val)== OK) {
        printf("%d\n", val);
    }
    else {
        printf("没有该元素");
    }
    ElemType delElem;
    printf("删除第 3 个元素:\n");
    if (ListDelete_L(L, 3, delElem)==OK)
        display(L);
    else
    printf("删除元素失败");
    printf("生成有序链表 La 为：\n");
    LinkList La = NULL;
    initList(La);
    srand(2);
    for (int i=1;i<10;i++){
        insertLinkOrder(La,rand()%100+1);
    }
    display(La);
    printf("生成有序链表 Lb 为：\n");
    LinkList Lb = NULL;
    initList(Lb);
    srand(10);
    for (int i=1;i<10;i++){
        insertLinkOrder(Lb,rand()%100+1);
    }
    display(Lb);
    printf("合并后的序链表 Lc 为：\n");
    LinkList Lc = NULL;
    initList(Lc);
    MergeOrderList(La,Lb,Lc);
    display(Lc);
    system("pause");
    return 0;
}
