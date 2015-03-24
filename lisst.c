#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct NUMBER_NODE              //this creates the structure that holds an int value and the address of the next node (or null)
{
        int value;
        struct NUMBER_NODE *next;
};

struct NUMBER_NODE *head = NULL;        //initialise head and tail to point at NULL

void add(int a)
{
        if (head == NULL)               //If the linked list is empty, create a node and have head point to this node
        {
                head = (struct NUMBER_NODE *) malloc(sizeof(struct NUMBER_NODE));
                head->value = a;
                head->next = NULL;
                return;
        }
else                            //if the linked list is not empty
        {

        struct NUMBER_NODE *freeSpot;
        struct NUMBER_NODE *newNode;
        freeSpot = head;

        while (freeSpot->next != NULL) //traverse the linked list until you find the tail
        {
                freeSpot = freeSpot->next;
        }

        newNode = (struct NUMBER_NODE *)malloc(sizeof(struct NUMBER_NODE)); //create new node, insert the value, make this node point at NULL and have the prev  node point at it.
        newNode->value = a;
        newNode->next = NULL;
        freeSpot->next = newNode;
        return;
        }
}

void prettyPrint()      //traverse the list starting at head and print values.
{
        struct NUMBER_NODE *p = head;
        printf("the linked list now contains:\n");
        while(p != NULL)
        {
                printf ("%d \n", p->value);
                p = p->next;
        }
}


