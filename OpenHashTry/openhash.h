#ifndef OPENHASH_H
#define OPENHASH_H
#include <stdbool.h>

#define MAX 10

typedef struct{
	int studID;
	char studName[30];
	char sex;
	char program[8];
	int level;
}Student;

typedef struct node{
	Student stud;
	struct node *link;
}NodeType, *NodePtr;

typedef struct{
	NodePtr elems[MAX];
	int count;
}Dictionary;

int getHash(Student s);
void initDictionary(Dictionary *d);
void visualize(Dictionary d);
bool addStudent(Dictionary *d, Student s);
//bool removeStudent(Dictionary d, Student s);


#endif
