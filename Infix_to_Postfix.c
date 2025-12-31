#include<stdio.h>
#include<ctype.h>
#define max 100
char stack[max];
int top=-1;
void push(char c)
{
    stack[++top]=c;
}
char pop()
{
    return stack[top--];
}
char peek()
{
    return stack[top];
}
int precedence(char op)
{
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    return 0;
}
int isOperator(char o)
{
    return(o=='+'||o=='-'||o=='*'||o=='/');
}
void infixtopostfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    char ch;

    while (infix[i] != '\0')
    {
        ch = infix[i];

        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        }
        else if (isOperator(ch))
        {
            while (top != -1 && precedence(peek()) >= precedence(ch))
            {
                postfix[j++] = pop();
            }
            push(ch);
        }
        i++;
    }

    while (top != -1)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main()
{
    char infix[max],postfix[max];
    printf("Enter infix expression:");
    scanf("%s",infix);
    infixtopostfix(infix,postfix);
    printf("Postfix expression=%s",postfix);
    return 0;
}

