#include<stdio.h>
#include<stdlib.h>
#include<Stdbool.h>
#include<windows.h>
#include<conio.h>

typedef struct node{
	int data;
	struct node *next;
}Node, *NodePtr;

NodePtr sll_createStack(){
	return NULL;
}

bool sll_isEmpty(NodePtr head){
	return (head == NULL);
}

bool sll_stack_push(NodePtr *head, int elem){
	NodePtr temp = malloc(sizeof(Node));
	if(temp == NULL){
		return false;
	}
	temp->data = elem;
	temp->next = NULL;
	if(sll_isEmpty(*head)){
		*head = temp;
	}
	else{
		temp->next = *head;
		*head = temp;
	}
	return true;
}

bool sll_stack_pop(NodePtr *head){
	if(sll_isEmpty(*head)){
		return false;
	}
	else{
		NodePtr temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	return true;
}


int sll_stack_peek(NodePtr head){
	if(sll_isEmpty(head)){
		printf("Stack is Empty.\n");
		return -1;
	}
	else{
		return head->data;
	}
	
}

void sll_display(NodePtr head) {
    NodePtr tempStack = sll_createStack();
    int elem;
    printf("DISPLAY: \n");
    while (!sll_isEmpty(head)) {
        elem = sll_stack_peek(head);
        printf("%d\n", elem);
        sll_stack_push(&tempStack, elem);
        sll_stack_pop(&head);
    }
    while (!sll_isEmpty(tempStack)) {
        elem = sll_stack_peek(tempStack);
        sll_stack_push(&head, elem);
        sll_stack_pop(&tempStack);
    }
}

void sll_visualize(NodePtr head){
	if(sll_isEmpty(head)){
		printf("Stack is Empty.\n");
	}
	else{
		NodePtr trav;
		printf("VALUE\n");
		for(trav = head; trav != NULL; trav = trav->next){
			printf("%d",trav->data);
			if(trav == head){
				printf("        <-- TOP");
			}
			printf("\n");
		}
	}
	
}

void sll_stack_evenNumber(NodePtr *head){
	int elem;
	if(sll_isEmpty(*head)){
		printf("Stack is Empty.\n");
	}
	else{
		printf("EVEN NUMBERS ");
		NodePtr evenStack = sll_createStack();
		NodePtr tempoStack = sll_createStack();
		while(!sll_isEmpty(*head)){
			elem = sll_stack_peek(*head);
			if(elem%2 == 0){
				sll_stack_push(&evenStack, elem);
			}
			else{
				sll_stack_push(&tempoStack, elem);
				
			}
			sll_stack_pop(head);
		}
		sll_display(evenStack);
		while(!sll_isEmpty(tempoStack)){
			elem = sll_stack_peek(tempoStack);
			sll_stack_push(head, elem);
			sll_stack_pop(&tempoStack);
		}
		free(evenStack);
		free(tempoStack);
	}
}


void main(){
	NodePtr head = sll_createStack();
	int choice;
	int elem;
	do{
		system("cls");
		printf("MENU \n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Peek\n");
		printf("4. Display\n");
		printf("5. Visualize\n");
		printf("6. Show Even Numbers\n");
		printf("0. EXIT\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Enter a number: ");
				scanf("%d", &elem);
				sll_stack_push(&head, elem);
				printf("\nPress Enter to continue\n");
				getch();
				break;
			case 2:
				sll_stack_pop(&head);
				printf("Top most element of the stack is popped.\n");
				printf("\nPress Enter to continue\n");
				getch();
				break;
			case 3: 
				printf("PEEK: %d", sll_stack_peek(head));
				printf("\nPress Enter to continue\n");
				getch();
				break;
			case 4:
				sll_display(head);	
				printf("\nPress Enter to continue\n");
				getch();
				break;
			case 5: 
				sll_visualize(head);
				printf("\nPress Enter to continue\n");
				getch();
				break;
			case 6:
				sll_stack_evenNumber(&head);
				printf("\nPress Enter to continue\n");
				getch();
				break;
				
		}
	}while(choice != 0);
	printf("Program Terminated.\n");
}
