#include<stdio.h>
#include<stdlib.h>

int max=1,top=-1;
int *s;

void push()
{
    int ele;

    if(top==max-1)
    {
        max++;
        s=(int *)realloc(s,max*sizeof(int));
    }

    printf("Enter the element:");
    scanf("%d",&ele);
    top++;
    s[top]=ele;

}

void pop()
{
    if(top==-1)
    {
        printf("Stack is Empty");
        return;
    }

    printf("Element deleted is %d",s[top]);
    top--;
}

void display()
{
    int i;
    if(top==-1)
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack elements are:\n");
    for(i=top;i>=0;i--)
    {
        printf("%d\t",s[i]);
    }
}

int main()
{
    int ch;

    s=(int*)malloc(max*sizeof(int));

    while(1)
    {
        printf("\n1.Push\n");
        printf("\n2.pop\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter ur choice:");
        scanf("%d",&ch);
    

    switch(ch)
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
        free(s);
        printf("Program terminated\n");
        return 0;

        default:
        printf("Invaild choice\n");
    }
}
}