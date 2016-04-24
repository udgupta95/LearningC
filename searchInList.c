#include <stdio.h>
#include<stdlib.h>

struct node 
{
  int data;
  struct node *next;
} typedef NODE;


NODE * createNode(int data)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data=data;
    newNode->next = NULL;
    return newNode;
}

void printList(NODE **head)
{
    NODE *temp = *head;
    
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

void push(NODE **head,int data)
{
    NODE *newNode = createNode(data);
    newNode->next=*head;
    *head = newNode;
    //printf("-------------\n");
    //printf("%d\n",head);
    //printList(head);
    //printf("-------------\n");
}


void append(NODE **head,int data)
{
    NODE *temp;
    NODE *newNode = createNode(data);
    if(*head==NULL)
        {
            *head = newNode;
            return;
        }
    temp = *head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

int searchData(NODE **head,int data)
{
    NODE *temp = *head;
    while(temp!=NULL)
    {
        if(temp->data==data)
            return 1;
        else
            temp = temp->next;
    }
    return 0;
}

int searchRecursive(NODE *head,int data)
{
    if(head==NULL)
        return 0;
    
    if(head->data==data)
        return 1;
    else
    {
        searchRecursive(head->next,data);
    }
}




int main()
{
    NODE *head,*node1,*node2,*node3;
    node1 = createNode(1);
    head = node1;
    append(&head,2);
    append(&head,3);
    append(&head,4);
    append(&head,5);
    append(&head,6);
    append(&head,7);
    append(&head,8);
    append(&head,9);
    append(&head,10);
    //node3 = push(&head,2);
    //push(&head,10);
    //insertAfter(NULL,13);
    //printf("%d",head);
    //deleteNode(&head,5);
    //deleteAtPosition(&head,2);
    printf("FOUND = %d\n",searchRecursive(head,10));
    printList(&head);
    return 0;
}
