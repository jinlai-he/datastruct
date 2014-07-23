#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 5

#define OK 1
#define ERROR 0
typedef int Status;

typedef struct
{
    int *base;
    int *top;
    int stacksize;
}SqStack;

Status InitStack_Sq(SqStack *S)
{
    S->base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
    if(!S->base) return ERROR;

    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE; 
    return OK;
}

Status GetTop(SqStack *S, int *e)
{
    if(S->top == S->base) return ERROR;
    *e = *(S->top-1);
    return OK;
}

Status Push(SqStack *S, int e)
{
    if(S->top - S->base >= S->stacksize)
    {
        S->base = (int *)realloc(S->base, (S->stacksize + STACK_INCREMENT) * sizeof(int));
        if(!S->base) return ERROR;
        S->top = S->base + S->stacksize;
        S->stacksize += STACK_INCREMENT;
    }
    *S->top++ = e;
    return OK;
}

Status Pop(SqStack *S, int *e)
{
    if(S->top == S->base) return ERROR;
    *e = *(--S->top);
    return OK;
}


int main(int argc, char *argv[])
{
    SqStack *S = (SqStack *)malloc(sizeof(SqStack));
    InitStack_Sq(S);

    int i;
    for(i = 1; i <= 20; i++)
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
