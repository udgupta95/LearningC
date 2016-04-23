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

int main()
{
    NODE *head,*node1,*node2,*node3;
    node1 = createNode(1);
    node2 = createNode(2);
    node3 = createNode(3);
    node1->next=node2;
    node2->next = node3;
    head = node1;
    printList(&head);
    return 0;
}

