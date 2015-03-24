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

