#include <stdio.h>

#define MAX 3

int s[MAX];
int top = -1;

/* Push an element */
void push()
{
    int ele;

    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    printf("Enter the element: ");
    scanf("%d", &ele);

    top++;
    s[top] = ele;
}

/* Pop an element */
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }

    printf("Element deleted is %d\n", s[top]);
    top--;
}

/* Display stack elements */
void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements are:\n");

    for (i = top; i >= 0; i--)
    {
        printf("%d\t", s[i]);
    }
}

int main()
{
    int ch;

    while (1)
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}