#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
typedef int Status;

typedef struct StackNode
{
    int data;
    struct StackNode *next;
}StackNode, *LinkStack;

void InitStack(LinkStack *S)
{
    *S = (LinkStack)malloc(sizeof(StackNode));
    (*S)->next = NULL;
}

Status Push(LinkStack S, int e)
{
    LinkStack p = (LinkStack)malloc(sizeof(StackNode));
    if(!p) return ERROR;
    p->data = e;
    p->next = S->next;
    S->next = p;
    return OK;
}

Status Pop(LinkStack S, int *e)
{
    if(S->next == NULL)
    {
        return ERROR;
    }

    LinkStack p = S->next;
    *e = p->data;
    S->next = p->next;
    free(p);
    return OK;
}

int main(int argc, char *argv[])
{
    LinkStack S;
    InitStack(&S);

    int i;
    for(i = 0; i < 10; i++)
    {
        Push(S, i);
    }
    int e;
    Pop(S, &e);
    printf("%d\n", e);

    Pop(S, &e);
    printf("%d\n", e);


    return 0;
}
