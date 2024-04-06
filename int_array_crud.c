/*
File Name: int_array
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
	int choice;
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
	}while(choice!=0);
}
