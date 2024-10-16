/*
A second prototype to arrays_home.c
The program can Add, Edit, Delete, Search, and Show Elements of an Array
Can create an array with user inputted size
Created by: Sophia Cohon
March 9, 2023
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

int array[];
int index = 0;
int size;

void add(int array[], int n){ //adds an element into the array
	int choiceSize, addSize;
	if(index>=size){ //condition for when the array is full
		//printf("Index is at value %d\n", index);
		printf("\nArray is full!\nWould you like to increase the size of your array?\n1-Yes\n2-No \n");
		scanf("%d", &choiceSize);
		if(choiceSize == 1){ //condition for when user wants to increase the size of array
			printf("How many more elements would you like to add? ");
			scanf("%d", &addSize);
			size = size+addSize; //value inputted will be added to size value
			printf("Your array size has increased by %d.\nNow, the size of your array is %d.\n", addSize, size);
		}
		else if(choiceSize == 2){
			return; //return to main function
		}	
	}
	else{ //condition for when array is not full
		//printf("Index is at value %d\n", index);
		array[index] = n;
		index++; //index increases to add element into the next position
	}
	
}

void edit(int array[], int pos, int n){
	int i;
	if(pos<0 || pos>size){ //if said position is less than or greater than the size of array
		printf("\nInvalid Position!\n");
	}
	else{
		array[pos] = n; //replaces the current value with the new value
		printf("Element in positioned in index [%d] was successfully edited.", pos);
	}
}

void delEl(int array[], int pos){
	/*
	1. select position of element to be edited
	2. once the position is inputted, the rest of the elements shift to the left.
	ex:
	1 2 3 4 5 6 7 8 9 10
	delete element at position 3
	1 2 3 5 6 7 8 9	
	*/
	
	int i;
	if(pos<0 || pos>size){ //if said position is less than or greater than the size of array
		printf("\nInvalid Position!\n");
	}
	else{
		for(i=pos; i<size; i++){ 
			array[i] = array[i+1]; //starting at said position, the for loop will shift the array elements to the left
		}
		printf("Element in positioned in index [%d] was successfully deleted.", pos);
	}
	size--;
	index--;
}

void main(){
	int choice;
	int i, posN, addN, editN, posD, posS;
	do{
		system("cls");
		printf("\nMENU: \n");
		printf("[1.] Create New Array\n");
		printf("[2.] Add Element\n");
		printf("[3.] Edit Element\n");
		printf("[4.] Delete Element\n");
		printf("[5.] Search Element\n");
		printf("[6.] Show Elements\n");
		printf("[0.] EXIT\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("\nCreate A New array\n");
				printf("Enter size for array: ");
				scanf("%d", &size);
				array[size];
				printf("An array that can store %d elements has been created.\n\nPress Enter to continue...", size);
				getch();
				break;
				
			case 2:
				printf("\nAdd Element to Array\n");
				printf("Enter a number: ");
				scanf("%d", &addN);
				add(array, addN);
				printf("\nPress Enter to continue\n");
				getch();
				break;
			case 3:
				printf("\nEdit Element in Array\n");
				for(i=0; i<size; i++){
					printf("Index [%d]: %d\n", i, array[i]);
				}
				printf("Enter the position of element to be edited: ");
				scanf("%d", &posN);
				printf("Enter a number: ");
				scanf("%d", &editN);
				edit(array, posN, editN);
				printf("\nPress Enter to continue\n");
				getch();
				break;
			case 4:
				printf("\nDelete Element in Array\n");
				for(i=0; i<size; i++){
					printf("Index [%d]: %d\n", i, array[i]);
				}
				printf("Enter the position of element to be deleted: ");
				scanf("%d", &posD);
				delEl(array, posD);
				printf("\nPress Enter to continue\n");
				getch();
				break;
			case 5:
				printf("\nSearch Element in Array\n");
				for(i=0; i<size; i++){
					printf("Index [%d]: %d\n", i, array[i]);
				}
				printf("Enter the position of element to be searched: ");
				scanf("%d", &posS);
				for(i=0; i<size; i++){
					if(posS == i){
						printf("Element in index [%d] is %d\n", posS, array[i]);
					}
				}
				printf("\nPress Enter to continue\n");
				getch();
				break;
			case 6:
				printf("\nShow Elements in Array\n");
				for(i=0; i<size; i++){
					printf("Index [%d]: %d\n", i, array[i]);
				}
				printf("\nPress Enter to continue\n");
				getch();
				break;
		}
	}while(choice!=0);
	printf("\n\nProgram Terminated. Thank you!");
}
