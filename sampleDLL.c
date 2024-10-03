#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	struct node* previous;
	int data;
	struct node* next;
} Node, *NodePtr;

void insertNode(NodePtr *head, int data){
	
	NodePtr temp = malloc(sizeof(Node));
	
	if(temp == NULL){
		printf("Memory Allocation Failed.");
		return;
	}
	
	temp->data = data;
	temp->previous = NULL;
	temp->next = NULL;
	
	if(*head == NULL){
		*head = temp;
	}
	else{
		temp->next = *head;
		(*head)->previous = temp;
		*head = temp;
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
	printf("Print in right order: \n");
	
	NodePtr trav = head;
	
	while(trav !=NULL){
		printf("%d ", trav->data);
		trav = trav->next;
	}
	printf("\n");
	/*
	NodePtr temp;
	for(temp=head;temp->next!=NULL;temp=temp->next){
		printf("%d ",temp->data);
	}
	*/
}

void printReverse(NodePtr head){
	printf("Print in reverse: \n");
	NodePtr ftrav = head;
	NodePtr tail = NULL;
	
	while(ftrav != NULL){
		tail = ftrav;
		ftrav = ftrav->next;
	}
	
	NodePtr ptrav = tail;
	while(ptrav != NULL){
		printf("%d ", ptrav->data);
		ptrav = ptrav->previous;
	}
	printf("\n");
}

int main(){
	NodePtr head = NULL;
	
	insertNode(&head,5);
	printList(head);
	insertNode(&head,6);
	insertNode(&head,3);
	insertNode(&head,4);
	insertNode(&head,10);
	printList(head);
	
	printReverse(head);
	
	printList(head);
	return 0;
}

