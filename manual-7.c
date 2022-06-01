#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *head=NULL;



void push(value)    // add data in end of list
{
    struct Node *newNode;

    newNode=(struct Node*) malloc(sizeof(struct Node));

    newNode->data=value;
    newNode->next=NULL;

    if(head == NULL)
    {
        newNode->prev=NULL;
        head=newNode;
    }
    else
    {
        struct Node *temp=head;

        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }

    printf("\n Push successful \n");
}




void pop()      // delete data from end of list
{
    if(head == NULL)
    {
        printf("\n Stack is underflow !!");
    }
    else if(head->next==NULL)
    {
        head=NULL;
        free(head);
        printf("\n Pop successful !!\n");
    }
    else
    {
        struct Node *temp=head;

        while(temp->next != NULL)
        {
            temp=temp->next;
        }

        temp->prev->next=NULL;
        free(temp);

        printf("\n Pop successful !!\n");
    }

}


void display()
{
    if(head == NULL)
    {
        printf("\n Stack is underflow !!");
    }
    else
    {
        struct Node *temp=head;

        printf("\n\nStack elements are: \n");
        while(temp->next != NULL)
        {
            printf(" %d \n",temp->data);
            temp=temp->next;
        }
        printf(" %d \n",temp->data);
    }

}

bool search()
{
    int item;
    printf("Enter searching value: ");
    scanf("%d",&item);

    if(head == NULL)
        printf(" Stack is underflow !\n");
    else
    {
        struct Node *temp=head;
        while(temp != NULL)
        {
            if(temp->data==item)
                return true;
            temp=temp->next;
        }
        return false;
    }
}

int count()
{
    int count=0;

    if(head == NULL)
    {
        return 0;
    }
    else
    {
        struct Node *temp=head;

        while(temp->next != NULL)
        {
            count++;
            temp=temp->next;
        }
        count++;
    }
    return count;
}

int main()
{
    int choice,value;

    while(1)
    {
        printf("\n\n----- MENU ------");
        printf("\n 1. Push");
        printf("\n 2. Pop");
        printf("\n 3. Display stack");
        printf("\n 4. Search element");
        printf("\n 5. Count stack size");
        printf("\n 6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("Insert a value: ");
            scanf("%d",&value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            search()? printf(" Item found \n") : printf(" Item Not found \n");
            break;
        case 5:
            printf("\nTotal data= %d\n",count());
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\n Invalid choice");
            break;
        }
    }


    return 0;
}


