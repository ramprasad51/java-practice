#include<stdio.h>
#include<stdlib.h>

int *queue;
int max=5;
int front=-1;
int rear=-1;

void insert()
{
    int value;

    if((rear+1)%max==front)
    {
        max+=1;
        queue=(int*)realloc(queue,max*sizeof(int));
        printf("Queue size is increased to %d\n",max);
    }
    printf("Enter the value:");
    scanf("%d",&value);

    if(front==-1)//for first element
    {
        front=0;
        rear=0;
    }
    else
    {
        rear=(rear+1)%max;
    }
    queue[rear]=value;
}

void delete()
{
    if(front==-1)
    {
        printf("Empty queue\n");
        return;
    }

    printf("Element deleted is %d\t",queue[front]);

    if(front==rear)//only 1 element was present
    {
        front=-1;
        rear=-1;
    }
    else
    {
        front=(front+1)%max;
    }
}

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

        if(i==rear) break;

    i=(i+1)%max;

    }
}

void main()
{
    int choice;

    queue=(int*)malloc(max*sizeof(int));
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
            free(queue);
            break;

            default:
            printf("Invaild choice\n");
        }
    }while(choice!=4);
}
