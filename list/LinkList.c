#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
typedef int Status;

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode, *LinkList;

Status GetElem_L(LinkList L, int i, int *e)
{
    LinkList p = L->next;
    int j = 1;
    while(p && j < i)
    {
        p = p->next;
        ++j;
    }
    if(!p || j > i) return ERROR;
    *e = p->data;
    return OK;
}

Status ListInsert_L(LinkList L, int i, int e)
{
    LinkList p = L;
    int j = 0;

    while(p && j < i-1)
    {
        p = p->next;
        ++j;
    }

    if(!p || j > i-1) return ERROR;

    LinkList s = (LinkList)malloc(sizeof(LNode));
    if(!s) return ERROR;

    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete_L(LinkList L, int i, int *e)
{
    LinkList p = L;
    int j = 0;
    
    while(p->next && j < i-1)
    {
        p = p->next;
        ++j;
    }

    if(!p->next || j > i-1) return ERROR;

    LinkList q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}

void CreateList_L(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
}

void ListPrint_L(LinkList L)
{
    LinkList p = L->next;
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    LinkList L;
    CreateList_L(&L);
    int i;
    for(i = 1; i < 10; i++)
    {
        ListInsert_L(L, i, i);
    }
    int e;
    ListDelete_L(L, 5, &e);
    ListPrint_L(L);

    return 0;
}
