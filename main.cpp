#include<stdio.h>
#include<stdlib.h>
#include"node.h"

// typedef struct _node{
//     int value;
//     struct _node *next;
// } Node;

//�Զ������ݽṹ
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
	//��������
    printf("�������������ݣ�����-1��ֹ��");
	do{
		scanf("%d",&number);
		if( number != -1 ){
			add(&list,number);
		}
	}while (number != -1 );

	//��ӡ����
	print(&list);

	// ��������
	printf("��������Ĳ�ѯ���֣�");
	// Node* p;
    search(&list/*p*/);


    //ɾ������
    printf("���������ɾ�����֣�");
    Ldelete(&list);

    print(&list);


	return 0;
}


void add(List* pList, int number){
    Node *p = (Node *)malloc(sizeof(Node));//�½�
    // Node *pt = (Node *)malloc(sizeof(Node));
    p->value = number;
    p->next = NULL;
    Node *last = pList->head;//���Ľڵ�
    if( last ){
        while( last -> next ){
            last = last->next;
        }
        last->next = p;
    }else{
        pList->head = p;
    }
    //��������p1�Ѿ��������׼�������µ�p���ҿ���ֱ��tail->next=p;tail=p;���ݹ��ǰ����֤����һ������״̬

}
void print(List *pList){
    Node* p;
    for (p = pList->head;p;p = p->next ) {     //********
        printf("%d",p->value);
    }
    printf("\n");
}

//��������
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

//ɾ������
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

