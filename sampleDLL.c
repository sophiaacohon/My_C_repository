#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	struct node* previous;
	int data;
	struct node* next;
} Node, *NodePtr;

void insertNode(NodePtr *head, int data){
	
	NodePtr temp = malloc(sizeof(Node));
	temp->data = data;
	temp->previous = NULL;
	temp->next = NULL;
	
	if(head == NULL){
		*head = temp;
	}
	else{
		temp->next = head;
		temp->previous = head;
		head = temp;
	}
	
	/*
	if(head==NULL){
		head = malloc(sizeof(Node));
	}
	
	NodePtr newNode = malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->previous = NULL;
	
	NodePtr temp;
	for(temp=*head;temp->next!=NULL;temp=temp->next);
	temp->next = newNode;
	*/
}

void printList(NodePtr head){
	
	NodePtr trav;
	
	for(trav = head; trav->next != NULL; trav = trav->next){
		printf("%d\n", trav->data);
	}
	
	/*
	NodePtr temp;
	for(temp=head;temp->next!=NULL;temp=temp->next){
		printf("%d ",temp->data);
	}
	*/
}

void main(){
	NodePtr head = NULL;
	
	insertNode(&head,5);
	printList(head);
	insertNode(&head,6);
	insertNode(&head,3);
	insertNode(&head,4);
	insertNode(&head,10);
}

