#include<stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

//insert an element
void insert()
{
    int value;
    //check if the queue is full
    if((rear+1)%MAX==front)
    {
        printf("Queue overflow\n");
        return;
    }
    printf("Enter the value:");
    scanf("%d",&value);

    if(front==-1)
    {
        front=0;
        rear=0;
    }
    else
    {
        rear=(rear+1)%MAX;
    }
    queue[rear]=value;
}

//Delete an element
void delete()
{
    if(front==-1)
    {
        printf("Queue empty\n");
        return;
    }

    printf("Deleted element is %d\n",queue[front]);

    if(front==rear) //only one element in queue
    {
        front=-1;
        rear=-1;
    }
    else
    {
        front=(front+1)%MAX;
    }
}

//Display elements
void display()
{
    int i=front;

    if(front==-1)
    {
        printf("Empty queue\n");
        return;
    }
    printf("Queue elements are:");
    while(1)
    {
        printf("%d\t",queue[i]);

        if(i==rear)
        break;

    i=(i+1)%MAX;

    }
}

void main()
{
    int choice;

    do
    {
        printf("\n1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");

        printf("Enter ur choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            insert();
            break;

            case 2:
            delete();
            break;

            case 3:
            display();
            break;

            case 4:
            printf("Exited\n");
            break;

            default:
            printf("Invaild choice\n");
        }
    }while(choice!=4);
}