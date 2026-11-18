#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    int usn;
    char name[20];
    int sem;
    char dep[10];
    struct node *link;
}NODE;

NODE *first=NULL;

void insert_front() //1
{
    NODE *nn=(NODE*)malloc(sizeof(NODE));

    printf("Enter Usn:");
    scanf("%d",&nn->usn);
     printf("Enter Name:");
    scanf("%s",nn->name);
     printf("Enter sem:");
    scanf("%d",&nn->sem);
     printf("Enter department:");
    scanf("%s",nn->dep);

    nn->link=first;
    first=nn;
}

void del_front() //2
{
    NODE *cur;
    if(first==NULL)
    {
        printf("List is Empty\n");
        return;
    }
    cur=first;
    first=first->link;
    printf("Student with usn %d deleted\n",cur->usn);
    free(cur);
}

void del_info() //3
{
    NODE *cur,*prev=NULL;
    int key;
    if(first==NULL)
    {
        printf("List is Empty\n");
        return;
    }
    printf("Enter usn to be deleted:");
    scanf("%d",&key);

    cur=first;
    if(cur->usn==key)
    {
        del_front();
        return;
    }

    while(cur!=NULL && cur->usn!=key)
    {
        prev=cur;
        cur=cur->link;
    }
    if(cur==NULL)
    {
        printf("USN not found\n");
        return;
    }

    prev->link=cur->link;
    free(cur);
    printf("Student with usn %d deleted\n",key);
}

void display()//4
{
    NODE *cur;
    int count=0;
    if(first==NULL)
    {
        printf("List is Empty\n");
        return;
    }
    printf("\n-------------------------------\n");
    printf("USN\tNAME\tSEM\tDEPARTMENT\n");
    printf("--------------------------------\n");
    cur=first;
    while(cur!=NULL)
    {
        printf("%d\t%s\t%d\t%s\n",cur->usn,cur->name,cur->sem,cur->dep);
        cur=cur->link;
        count++;
    }

    printf("---------------------\n");
    printf("Total num of students:%d\n",count);

}

void display_sem()//5
{
    int key,count=0;
    NODE *cur;

    if(first==NULL)
    {
        printf("List is Empty\n");
        return;
    }

    printf("Enter sem to search:");
    scanf("%d",&key);
    printf("\n Students of sem%d:\n",key);
    printf("\n-------------------------------\n");
    printf("USN\tNAME\tSEM\tDEPARTMENT\n");
    printf("--------------------------------\n");
    cur=first;
    while(cur!=NULL)
    {
        if(cur->sem==key)
        {
        printf("%d\t%s\t%d\t%s\n",cur->usn,cur->name,cur->sem,cur->dep);
        count++;
        }
        cur=cur->link;
    }

    if(count==0)
    {
        printf("No students found in sem%d",key);
    }
    else{
        printf("Total num of students in sem%d is %d",key,count);
    }

}

void insert_after_name()
{
    char key[20];
    NODE *cur;
    if(first==NULL)
    {
        printf("List is Empty\n");
        return;
    }
    printf("Enter the name after which new student should be inserted:");
    scanf("%s",key);

    cur=first;
    while(cur!=NULL && strcmp(cur->name,key)!=0)
    {
        cur=cur->link;
    }

    if(cur==NULL){
        printf("Student with name %s not found",key);
        return;
    }

     NODE *nn=(NODE*)malloc(sizeof(NODE));

    printf("Enter Usn:");
    scanf("%d",&nn->usn);
     printf("Enter Name:");
    scanf("%s",nn->name);
     printf("Enter sem:");
    scanf("%d",&nn->sem);
     printf("Enter department:");
    scanf("%s",nn->dep);

    nn->link=cur->link;
    cur->link=nn;
    printf("Student with inserted %s successfully\n",key);
}

void main()
{
    int ch;
    do{
        printf("\n===DETAILS OF STUDENTS===\n");
        printf("1.Insert @ front\n");
        printf("2.Delete @ Front\n");
        printf("3.Delete by usn\n");
        printf("4.Display all students\n");
        printf("5.Display by sem\n");
        printf("6.Insert after a given name\n");
        printf("7.Exit\n");
        printf("Enter ur choice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:insert_front(); break;
            case 2:del_front(); break;
            case 3:del_info(); break;
            case 4:display(); break;
            case 5:display_sem(); break;
            case 6:insert_after_name(); break;
            case 7:printf("Exiting\n"); break;
            default:printf("Invaild choice"); break;
        }
    }while(ch!=7);

}