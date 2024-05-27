/*
File Name: int_array_crud.c
File Description: to perform CRUD operations on an integer array
Date Created: April 6, 2024
Created by: Sophia Cohon
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<math.h>

#define MAX 100

int array[MAX];
int index = 0;

void main(){
	int choice, size, last;
	do{
		printf("1. Create New Array\n");
		printf("2. Show Array\n");
		printf("3. Add Element\n");
		printf("4. Delete Element\n");
		printf("5. Edit Element\n");
		printf("6. Search Element\n");
		printf("0. EXIT\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				printf("\n\nCreate New Array\n");
				printf("Enter an array size: ");
				scanf("%d", &size);
				array[size];
				printf("Enter %d elements: ", size);
				for(int i=0; i<size; i++){
					scanf("%d", &array[i]);
				}
				last = size;
				printf("You have created an array with %d elements\n\n", size);
				break;
			case 2: 
				printf("\n\nShow Array [Traversal]\n");
				for(int i=0; i<size; i++){
					printf("[%d]", array[i]);
					if(i<size-1){
						printf(" ");
					}
				}
				printf("\n\n");
				break;
				
		}
		
	}while(choice!=0);
	printf("Program terminated. Thank you.");
	
}
