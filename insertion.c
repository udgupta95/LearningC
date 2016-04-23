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

void insertAfter(NODE *prev,int data)
{
    if(prev==NULL)
    {
        printf("Previous node cannot be null\n");
        return;
    }
    NODE *newNode = createNode(data);
    newNode->next = prev->next;
    prev->next = newNode;
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

int main()
{
    NODE *head,*node1,*node2,*node3;
    node1 = createNode(1);
    head = node1;
    node2 = createNode(2);
    node1->next = node2;
    append(&head,3);
    append(&head,4);
    //node3 = push(&head,2);
    //push(&head,10);
    //insertAfter(NULL,13);
    //printf("%d",head);
    printList(&head);
    return 0;
}

