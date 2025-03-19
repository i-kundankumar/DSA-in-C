#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct OpNode
{
    char data;
    struct OpNode *next;
};

struct OpStack
{
    struct OpNode *top;
};

void initOpStack(struct OpStack *stack)
{
    stack->top = NULL;
}

int isOpStackEmpty(struct OpStack *stack)
{
    return stack->top == NULL;
}

void pushOp(struct OpStack *stack, char op)
{
    struct OpNode *newNode = (struct OpNode *)malloc(sizeof(struct OpNode));
    newNode->data = op;
    newNode->next = stack->top;
    stack->top = newNode;
}


char popOp(struct OpStack *stack)
{
    if (isOpStackEmpty(stack))
        return '\0';
    struct OpNode *temp = stack->top;
    char op = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return op;
}

int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

void infixToPostfix(char *infix, char *postfix)
{
    struct OpStack stack;
    initOpStack(&stack);
    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        char ch = infix[i++];
        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            pushOp(&stack, ch);
        }
        else if (ch == ')')
        {
            while (stack.top->data != '(')
            {
                postfix[j++] = popOp(&stack);
            }
            popOp(&stack);
        }
        else
        {
            while (!isOpStackEmpty(&stack) && precedence(ch) <= precedence(stack.top->data))
            {
                postfix[j++] = popOp(&stack);
            }
            pushOp(&stack, ch);
        }
    }

    while (!isOpStackEmpty(&stack))
    {
        postfix[j++] = popOp(&stack);
    }
    postfix[j] = '\0';
}

int main()
{
    char infix[100], postfix[100];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    return 0;
}
