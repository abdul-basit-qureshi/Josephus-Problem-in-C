#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#include "Node.h"


///checks whether the value is already in or not
int isAlreadyAdded(int arr[], int value, int index)
{
     for(int i = 0; i < index; i ++)
          if(arr[i] == value)   //if value is already in array
              return 1;
     return 0;
}

///read a line from file
void readNameFromFile(unsigned int index, char * name, FILE * fpt)
{
    fseek(fpt, index, SEEK_SET);        ///index is already set as offset
    fgets(name, 17, fpt);
}

///returns 1 if list is empty
int isListEmpty(struct node * head)
{
    return (head == NULL);
}


void printEmployeeData(struct person * emp)
{
    printf("  Person %d:\t",emp->num);
    printf("Name:\t%s", emp->name);
}

void printNodeData(struct node * node_x)
{
   printEmployeeData(& node_x->data);
}

void printClockwise(struct node * head)
{
    struct node * ptr = head;

    if(isListEmpty(head))
    {
        printf("\n  List is empty.\n");
        return;
    }

    ///start from the beginning and go till the last node
    do
    {
       printNodeData(ptr);
       ptr = ptr->next;
    }
    while(ptr != head);

}

void printAnticlockwise(struct node * head)
{
    struct node * ptr = head;

    if(isListEmpty(head))
    {
        printf("\n  List is empty.\n");
        return;
    }

    ///start from the beginning and go till the last node
    do
    {
       printNodeData(ptr);
       ptr = ptr->prev;
    }
    while(ptr != head);

}

///returns length of the list
int getListLength(struct node * head)
{
    int length = 0;
    struct node * current;

    if(isListEmpty(head))
        return(0);

    for(current = head; current->next != head; current = current->next)
      length++;

   return (length+1);
}

void  insertNodeAtStart(struct node ** head, char * NAME, int number)
{
	struct node * newNode = (struct node *)malloc(sizeof(struct node));

    ///assigning data to node
	strcpy(newNode->data.name, NAME);
	newNode->data.num = number;

	if(isListEmpty(*head))
    {
        *head = newNode;
        newNode->next = *head;
        newNode->prev = *head;
        return;
    }

    ///Not in use for this program but still integrated as a proper function
    struct node * tail = (*head)->prev;
    newNode->next = *head;
    newNode->prev = tail;
    tail->next = newNode;
    (*head)->prev = newNode;
    *head = newNode;
}


void insertNodeAtEnd(struct node * head, char * NAME, int number)
{
    struct node * temp = head;

    ///Not in use for this program but still integrated as a proper function
    if(isListEmpty(head))    // if currently the list is empty return -1
        return;

    ///create a new node
    struct node * newNode = (struct node *) malloc(sizeof(struct node));

    ///assigning data to node
	strcpy(newNode->data.name, NAME);
	newNode->data.num = number;

    struct node * tail = head->prev;

    newNode->next = head;    /// Setting up the pointers for insertion
    newNode->prev = tail;
    tail->next = newNode;
    head->prev =  newNode;
}
