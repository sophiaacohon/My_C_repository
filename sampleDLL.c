#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	struct node* previous;
	int data;
	struct node* next;
} Node, *NodePtr;

void insertFirst(NodePtr *head, int data){
	
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

void insertLast(NodePtr *head, int data){
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
		NodePtr trav;
		//NodePtr prev = trav;
		for(trav = *head; trav->next!=NULL; trav = trav->next){
		}
		trav->next = temp;
		temp->previous = trav;
	}
	
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
	
	insertFirst(&head,5);
	printList(head);
	insertFirst(&head,6);
	insertFirst(&head,3);
	insertFirst(&head,4);
	insertFirst(&head,10);
	printList(head);
	
	printReverse(head);
	
	printList(head);
	
	insertLast(&head, 9);
	insertLast(&head, 8);
	insertLast(&head, 7);
	insertLast(&head, 21);
	
	printList(head);
	printReverse(head);
	
	return 0;
}

