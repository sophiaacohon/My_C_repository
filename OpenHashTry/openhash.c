#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "openhash.h"

int getHash(Student s){
	int rem;
	int sum=0;
	int num = s.studID;
	while(num != 0){
		rem = num % 10;
		sum += rem;
		num /= 10;
	}
	
	sum %= MAX;
	
	return sum;
}

void initDictionary(Dictionary *d){
	int i;
	for(i=0; i<MAX; i++){
		d->elems[i] = NULL;
	}
	d->count = 0;
}

void visualize(Dictionary d){
    int i;
    printf("Hash Table\n");
    for(i = 0; i < MAX; i++) {
        if(d.elems[i] == NULL) {
            printf("\t%i\t---\n", i);
        } else {
            printf("\t%i\t", i);
            NodePtr temp = d.elems[i];
            while(temp != NULL) {
                printf("%s -> ", temp->stud.studName);
                temp = temp->link;
            }
            printf("NULL\n");
        }
    }
}

bool addStudent(Dictionary *d, Student s){
    NodePtr newStud = malloc(sizeof(NodeType));
    if(newStud == NULL) return false;  
    newStud->stud = s;
    newStud->link = NULL;
    
    int index = getHash(s);
    
    if(d->elems[index] == NULL){
        d->elems[index] = newStud;
    }
    else {

        NodePtr temp = d->elems[index];
		NodePtr prev = NULL;
        while(temp != NULL && strcmp(temp->stud.studName, s.studName) < 0) {
            prev = temp;
            temp = temp->link;
        }
        
        if (prev == NULL) {
            newStud->link = d->elems[index];
            d->elems[index] = newStud;
        } else {
            prev->link = newStud;
            newStud->link = temp;
        }
    }
    d->count++;
    return true;
}


//bool removeStudent(Dictionary d, Student s);


