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
int last;
int size;

void displayMenu(){
	printf("MENU:\n");
	printf("1. Create New Array\n");
	printf("2. Show Array\n");
	printf("3. Add Element at the END of the Array\n");
	printf("4. Delete Element\n");
	printf("5. Edit Element\n");
	printf("6. Search Element\n");
	printf("0. EXIT\n");
}

void createArray(int array[], int size){
	array[size];
	printf("Enter %d elements: ", size);
	for(int i=0; i<size; i++){
		scanf("%d", &array[i]); //Initialize array by adding elements
	}
	last = size;
	printf("You have created an array with %d elements\n\n", size);
}

void showArray(int array[], int size){
	//printf("size: %d\n", size); //debugging;
	for(int i=0; i<size; i++){
		printf("index [%d]: [%d]\n", i, array[i]);
	}
	printf("\n\n");
}

void addElemEnd(int array[], int *size){
	*size += 1;
    //printf("size: %d\n", *size); //debugging
    printf("Enter element at the end of the array: ");
    scanf("%d", &array[*size - 1]);
    last = *size;
    printf("You have added an element at the end of the array!\n\n");
}

void delElem(int array[], int *size){
	//printf("size: %d\n", *size); //debugging
	int idx;
    printf("Which index would you like to delete? ");
    scanf("%d", &idx);
    if (idx < 0 || idx >= *size) {
        printf("Invalid index. Please enter a valid index.\n");
        return;
    }
    for (int i = idx; i < *size - 1; i++){
        array[i] = array[i + 1];
    }
    *size -= 1;
    last = *size;
    printf("Element deleted successfully.\n");
    //printf("size: %d\n", *size); // debugging
}

void editElem(int array[], int size){
	int idx, newValue;
	printf("Enter index of element you want to edit: ");
	scanf("%d", &idx);
	if (idx < 0 || idx >= size) {
        printf("Invalid index. Please enter a valid index.\n");
        return;
    }
    else{
    	printf("Enter the new value at index [%d]: ", idx);
    	scanf("%d", &newValue);
    	array[idx] = newValue;
	}
}

void searchArray(int array[], int size){
	int idx;
	printf("Enter which index you want to search: ");
	scanf("%d", &idx);
	printf("The number at index [%d] is [%d].", idx, array[idx]);
}

void main(){
	int choice;
	size = 0;
	do{
		system("cls");
		displayMenu();
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1: //Create a New Array, C in CRUD
				printf("\n\nCreate New Array\n");
				printf("Enter an array size: ");
				scanf("%d", &size); //Initialize size to reduce run time
				createArray(array, size);
				printf("\nPress Enter to continue\n");
				getch();
				break;
			case 2: //Traversal of Array, R in CRUD	
				printf("\n\nShow Array\n"); 
				showArray(array, size);
				printf("\nPress Enter to continue\n");
				getch();
				break;
			case 3:
				printf("\n\nAdd Element at the END of the Array\n");
				addElemEnd(array, &size);
				printf("\nPress Enter to continue\n");
				getch();
				break;
			case 4:
				printf("\n\nDelete Element in an Array\n");
				showArray(array, size);
				delElem(array, &size);
				printf("\nPress Enter to continue\n");
				getch();
				break;
			case 5:
				printf("\n\nEdit Element in an Array\n");
				showArray(array, size);
				editElem(array, size);
				printf("\nPress Enter to continue\n");
				getch();
				break;
			case 6: 
				printf("\n\nSearch Element in an Array\n");
				showArray(array, size);
				searchArray(array, size);
				printf("\nPress Enter to continue\n");
				getch();
				break;
		}
		
	}while(choice!=0);
	printf("Program Terminated. Thank you.");
	
}
