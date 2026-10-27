#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Book
{
    int id;
    char title[50];
    char author[50];
    int price;
    char status[10];
}*b;


int i,id,n;
void create()
{
    printf("Enter number of books:");
    scanf("%d",&n);
    b=(struct Book *)malloc(n*sizeof(struct Book));//practicee

    for(i=0;i<n;i++)
    {
        printf("Book ID:");
        scanf("%d",&b[i].id);
        printf("Title:");
        scanf("%s",b[i].title);
        printf("Author:");
        scanf("%s",b[i].author);
        printf("Price:");
        scanf("%d",&b[i].price);
        strcpy(b[i].status,"Availabile");
        printf("Book Added successfully");
    }
}

void display()
{
    printf("\n---Availabile books---\n");
    printf("\nID\tTitle\tAuthor\tPrice\tStatus\n");
    printf("-----------------------------------\n");
    for(i=0;i<n;i++)
    {
        if(strcmp(b[i].status,"Availabile")==0)
        {
            printf("\n%d\t%s\t%s\t%d\t%s\n",b[i].id,b[i].title,b[i].author,b[i].price,b[i].status);
        }
    }
}

void search()
{
    printf("Enter book id to search:");
    scanf("%d",&id);

    for(i=0;i<n;i++)
    {
        if(b[i].id==id)
        {
            printf("Book found");
             printf("\n%d\t%s\t%s\t%d\t%s\n",b[i].id,b[i].title,b[i].author,b[i].price,b[i].status);
             return;
        }
        printf("Book not found\n");
    
    }
}

void issueBook()
{
    printf("Enter book id to issue:");
    scanf("%d",&id);
    for(i=0;i<n;i++)
    {
        if(b[i].id==id)
        {
            if(strcmp(b[i].status,"Availabile")==0)
            {
                strcpy(b[i].status,"issued");
                printf("Book issued successfully");

            }
            else
            {
                printf("Book is already issued");
                return;
            }
        }
       
    }
     printf("Book not found\n");
}

void returnBook()
{
    printf("Enter book id to return:");
    scanf("%d",&id);
    for(i=0;i<n;i++)
    {
        if(b[i].id==id)
        {
            if(strcmp(b[i].status,"issued")==0)
            {
                strcpy(b[i].status,"Availabile");
                printf("Book returned successfully");
            }
            else
            {
                printf("Book is already availabile");
                return;
            }
        }
        
    }
     printf("Book not found\n");
}

void main()
{
    int ch;

    while(1)
    {
        printf("\n\n---LIBRARY MENU---\n");
        printf("1.Add Book records 2.Display All Books 3.Search book 4.Issue Book 5.Return Book 6.Exit\n");

        printf("Enter the choice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            create();
            break;

            case 2:
            display();
            break;

            case 3:
            search();
            break;

            case 4:
            issueBook();
            break;

            case 5:
            returnBook();
            break;

            case 6:
            free(b);
            return;
        }
    }
}


