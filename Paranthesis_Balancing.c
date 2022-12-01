#include <stdio.h>
#include <stdlib.h>
struct stack
{
    char *arr;
    int size;
    int top;
};
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr, char data)
{
    ptr->top++;
    ptr->arr[ptr->top] = data;
}
void pop(struct stack *ptr)
{
    ptr->top--;
}
int Match(char *exp)
{
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sizeof(char) * sp->size);
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }
    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char *exp = "((8)*(9))";
    if (Match(exp))
    {
        printf("Balanced successfully \n");
    }
    else
    {
        printf("Not Balanced correctly\n");
    }
    return 0;
}
