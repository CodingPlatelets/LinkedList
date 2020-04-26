#include<stdio.h>
#include<stdlib.h>
#include"node.h"

// typedef struct _node{
//     int value;
//     struct _node *next;
// } Node;

//自定义数据结构
typedef struct _list{
    Node* head;
    // Node* tail;
}List;

void print(List *pList);
void add(List* list, int number);
void search(List *pList/*,Node *p*/);
void Ldelete(List *pList);

int main ()
{
    printf("Hello");
	// Node *head = NULL;
	List list;
	list.head= NULL;
	int number;
	//输入链表
    printf("请输入您的数据：（以-1截止）");
	do{
		scanf("%d",&number);
		if( number != -1 ){
			add(&list,number);
		}
	}while (number != -1 );

	//打印链表
	print(&list);

	// 查找链表
	printf("请输入你的查询数字：");
	// Node* p;
    search(&list/*p*/);


    //删除链表
    printf("请输入你的删除数字：");
    Ldelete(&list);

    print(&list);


	return 0;
}


void add(List* pList, int number){
    Node *p = (Node *)malloc(sizeof(Node));//新建
    // Node *pt = (Node *)malloc(sizeof(Node));
    p->value = number;
    p->next = NULL;
    Node *last = pList->head;//最后的节点
    if( last ){
        while( last -> next ){
            last = last->next;
        }
        last->next = p;
    }else{
        pList->head = p;
    }
    //假设我们p1已经插入完成准备插入新的p，我可以直接tail->next=p;tail=p;来递归的前进保证在上一个结点的状态

}
void print(List *pList){
    Node* p;
    for (p = pList->head;p;p = p->next ) {     //********
        printf("%d",p->value);
    }
    printf("\n");
}

//查找链表
void search(List *pList/*,Node *p*/){
    Node *p;
    int number;
    scanf("%d",&number);
    int isFound = 0;
    for (p = pList->head;p;p = p->next ){
        if (number == p->value){
            printf("FOUND\n");
            isFound = 1;
            break;
        }
    }
    if (!isFound ){
        printf("NOT FOUND\n");
    }
}

//删除链表
void Ldelete(List *pList){
    Node *q;
    Node *p;
    int i;
    scanf("%d",&i);
    for (q = NULL, p = pList->head; p ; q = p, p = p->next ){
        if (i == p->value){
            if(q){
                q->next = p->next;
            }else{
                pList->head = p->next;
            }
            free(p);
            break;
        }
    }
    // for( p = pList->head;p;p = q){
    //     q = p->next;
    //     free(p);
    // }

}

