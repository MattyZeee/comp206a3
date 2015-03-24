#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct NUMBER_NODE		//this creates the structure that holds an int value and the address of the next node (or null)
{
        int value;
	struct NUMBER_NODE *next;
};

struct NUMBER_NODE *head = NULL;	//initialise head and tail to point at NULL

void add(int a)
{
	if (head == NULL)		//If the linked list is empty, create a node and have head point to this node
	{
		head = (struct NUMBER_NODE *) malloc(sizeof(struct NUMBER_NODE));
        	head->value = a;
        	head->next = NULL;
       		return;
	}
	else				//if the linked list is not empty 
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

void prettyPrint()	//traverse the list starting at head and print values.
{
	struct NUMBER_NODE *p = head;
	printf("the linked list now contains:\n");
	while(p != NULL)
	{
		printf ("%d \n", p->value);
		p = p->next;
	}
}

struct NUMBER_NODE *find(int a)	//find method is hidden (not declared in list.h file)
{
	struct NUMBER_NODE *p = head;
        struct NUMBER_NODE *node_before_p = head;
        while (p!= NULL)		//traverse the linked list
        {
                if (p->value == a)	//if a value matches then..
                {
			if (p == head) 
			{
				head = p->next; //if it is the first node, have the head point at the second node
			}
			else
			{
                        	node_before_p->next = p->next;  //else have previous node point to next node removing the current node from the linked list
                       		//free (p);	//wasnt sure if i should free the node. It didnt specify to do this in the assignment guidelines
                       		return p;	//return a pointer pointing to the node
               		 }
		}
                else
                	{
                       		node_before_p = p;	//else continue traversing the list to see if next node contains matching value
                       		p = p -> next;
               		}
        }	
        return NULL;			//no node contained matching value so return NULL
}	

	

BOOLEAN delete (int a)
{
	struct NUMBER_NODE *ptr = find(a);
	if (ptr != NULL) return EXIT_SUCCESS; 	//I chose to return EXIT_SUCCESS AND EXIT_FAILURE... I could have returned TRUE and FALSE
	else return EXIT_FAILURE;
}
		
