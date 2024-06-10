#include<stdio.h>
#include<string.h>
#include<math.h>
#include<windows.h>
#define MAX 20

typedef struct{
	char fName[MAX];
	char lName[MAX];
} studName;

typedef struct{
	int month;
	int date;
	int year;
} bday;

typedef struct{
	studName name;
	bday birthdate;
	int age;
	int idNum;
} studentInfo;

typedef struct{
	studentInfo studlist[MAX];
	int studCount;
} classRecord;


void displayMenu(){
	printf("CLASS RECORD\n\n");
	printf("1. Insert at Front\n");
	printf("2. Insert at Rear\n");
	printf("3. Insert at Index\n");
	printf("4. Insert Sorted by Age\n");
	printf("5. Delete at Front\n");
	printf("6. Delete at Rear\n");
	printf("7. Delete at Index\n");
	printf("8. Display Class Record\n");
	printf("0. EXIT\n");
}

void insertFront(classRecord *cr){
	printf("count: %d\n", cr->studCount); //debug
    if(cr->studCount == 0){
        printf("Enter First Name: ");
        scanf("%s", cr->studlist[0].name.fName);
        printf("Enter Last Name: ");
        scanf("%s", cr->studlist[0].name.lName);
        printf("Enter birth month in digits: ");
        scanf("%d", &cr->studlist[0].birthdate.month);
        printf("Enter birth date in digits: ");
        scanf("%d", &cr->studlist[0].birthdate.date);
        printf("Enter birth year in digits: ");
        scanf("%d", &cr->studlist[0].birthdate.year);
        printf("Enter age: ");
        scanf("%d", &cr->studlist[0].age);
        printf("Enter ID Number: ");
        scanf("%d", &cr->studlist[0].idNum);
        cr->studCount++;
        printf("count: %d\n", cr->studCount); //debug
    }
    else if(cr->studCount > 0 && cr->studCount < MAX){
        int i;
        printf("count: %d\n", cr->studCount); //debug
        cr->studCount++;
        printf("count: %d\n", cr->studCount); //debug
        for(i = cr->studCount - 1; i >= 0; i--){
            cr->studlist[i+1] = cr->studlist[i];
        }

        printf("Enter First Name: ");
        scanf("%s", cr->studlist[0].name.fName);
        printf("Enter Last Name: ");
        scanf("%s", cr->studlist[0].name.lName);
        printf("Enter birth month in digits: ");
        scanf("%d", &cr->studlist[0].birthdate.month);
        printf("Enter birth date in digits: ");
        scanf("%d", &cr->studlist[0].birthdate.date);
        printf("Enter birth year in digits: ");
        scanf("%d", &cr->studlist[0].birthdate.year);
        printf("Enter age: ");
        scanf("%d", &cr->studlist[0].age);
        printf("Enter ID Number: ");
        scanf("%d", &cr->studlist[0].idNum);
    }
}

void insertRear(classRecord *cr){
	printf("count: %d\n", cr->studCount); //debug
    if(cr->studCount == 0){
        printf("Enter First Name: ");
        scanf("%s", cr->studlist[0].name.fName);
        printf("Enter Last Name: ");
        scanf("%s", cr->studlist[0].name.lName);
        printf("Enter birth month in digits: ");
        scanf("%d", &cr->studlist[0].birthdate.month);
        printf("Enter birth date in digits: ");
        scanf("%d", &cr->studlist[0].birthdate.date);
        printf("Enter birth year in digits: ");
        scanf("%d", &cr->studlist[0].birthdate.year);
        printf("Enter age: ");
        scanf("%d", &cr->studlist[0].age);
        printf("Enter ID Number: ");
        scanf("%d", &cr->studlist[0].idNum);
    }
    else if(cr->studCount > 0 && cr->studCount < MAX){
        printf("count: %d\n", cr->studCount); // Debug
        cr->studCount++;
        printf("count: %d\n", cr->studCount); // Debug
        printf("Enter First Name: ");
        scanf("%s", cr->studlist[cr->studCount - 1].name.fName);
        printf("Enter Last Name: ");
        scanf("%s", cr->studlist[cr->studCount - 1].name.lName);
        printf("Enter birth month in digits: ");
        scanf("%d", &cr->studlist[cr->studCount - 1].birthdate.month);
        printf("Enter birth date in digits: ");
        scanf("%d", &cr->studlist[cr->studCount - 1].birthdate.date);
        printf("Enter birth year in digits: ");
        scanf("%d", &cr->studlist[cr->studCount - 1].birthdate.year);
        printf("Enter age: ");
        scanf("%d", &cr->studlist[cr->studCount - 1].age);
        printf("Enter ID Number: ");
        scanf("%d", &cr->studlist[cr->studCount - 1].idNum);
        
    }
    else if(cr->studCount == MAX){
        printf("MAXIMUM NUMBER OF STUDENTS REACHED.");
    }
}

void insertIndex(classRecord *cr){
	printf("count: %d\n", cr->studCount); //debug
	int position, i;
	printf("Which index do you want to insert a record?");
	scanf("%d", &position);
	cr->studCount++;
	printf("count: %d\n", cr->studCount); //debug
	for(i = cr->studCount - 1; i >= position; i--){
            cr->studlist[i+1] = cr->studlist[i];
    }
    printf("Enter First Name: ");
        scanf("%s", cr->studlist[position].name.fName);
        printf("Enter Last Name: ");
        scanf("%s", cr->studlist[position].name.lName);
        printf("Enter birth month in digits: ");
        scanf("%d", &cr->studlist[position].birthdate.month);
        printf("Enter birth date in digits: ");
        scanf("%d", &cr->studlist[position].birthdate.date);
        printf("Enter birth year in digits: ");
        scanf("%d", &cr->studlist[position].birthdate.year);
        printf("Enter age: ");
        scanf("%d", &cr->studlist[position].age);
        printf("Enter ID Number: ");
        scanf("%d", &cr->studlist[position].idNum);
    
}

int compareByAge(const void *a, const void *b) {
    const studentInfo *studentA = (const studentInfo *)a;
    const studentInfo *studentB = (const studentInfo *)b;
    return (studentA->age - studentB->age);
}

void insertByAge(classRecord *cr){
	studentInfo newStudent;

    printf("\nEnter First Name: ");
    scanf("%s", newStudent.name.fName);
    printf("Enter Last Name: ");
    scanf("%s", newStudent.name.lName);
    printf("Enter birth month in digits: ");
    scanf("%d", &newStudent.birthdate.month);
    printf("Enter birth date in digits: ");
    scanf("%d", &newStudent.birthdate.date);
    printf("Enter birth year in digits: ");
    scanf("%d", &newStudent.birthdate.year);
    printf("Enter age: ");
    scanf("%d", &newStudent.age);
    printf("Enter ID Number: ");
    scanf("%d", &newStudent.idNum);

    cr->studlist[cr->studCount] = newStudent;
    cr->studCount++;

    qsort(cr->studlist, cr->studCount, sizeof(studentInfo), compareByAge);
}

void deleteFront(classRecord *cr){
	int i;
	for(i=0; i<cr->studCount; i++){
		cr->studlist[i] = cr->studlist[i+1];
	}
	cr->studCount--;
	printf("Student Record at Front Deleted.");
}

void deleteRear(classRecord *cr){
	cr->studCount--;
	printf("Student Record at Rear Deleted.");
}

void deleteIndex(classRecord *cr){
	int position, i;
	printf("Enter index to delete record: ");
	scanf("%d", &position);
	if(position>MAX){
		printf("Invalid index");
	}
	for(i=position; i<cr->studCount-1; i++){
		cr->studlist[i] = cr->studlist[i+1];
	}
	cr->studCount--;
	printf("Record at index %d deleted successfully.", position);
}

void displayRecord(classRecord cr){
    int i;
    printf("%10s %15s %15s %15s %15s %10s\n", "INDEX", "ID NUMBER", "FIRST NAME", "LAST NAME", "BIRTHDAY", "AGE");
    for (i = 0; i < cr.studCount; i++){
        printf("[%10d] %10d, %10s %10s %10d/%d/%d %10d\n", i, cr.studlist[i].idNum, cr.studlist[i].name.fName, cr.studlist[i].name.lName, cr.studlist[i].birthdate.month, cr.studlist[i].birthdate.date, cr.studlist[i].birthdate.year, cr.studlist[i].age);
    }
}

void main(){
	int option;
	classRecord cr = { .studCount = 0};
	do{
		system("cls");
		displayMenu();
		printf("Enter option: ");
		scanf("%d", &option);
		
		switch(option){
			case 1:
				printf("\nINSERT RECORD AT FRONT\n");
				insertFront(&cr);
				printf("\nPress Enter to continue\n");
				getch();
				break;
				
			case 2: 
				printf("\nINSERT RECORD AT REAR\n");
				insertRear(&cr);
				printf("\nPress Enter to continue\n");
				getch();
				break;
			
			case 3:
				printf("\nINSERT RECORD AT INDEX\n");
				displayRecord(cr);
				insertIndex(&cr);
				printf("\nPress Enter to continue\n");
				getch();
				break;
				
			case 4:
				printf("\nINSERT RECORD SORTED BY AGE\n");
				insertByAge(&cr);
				printf("Student inserted and class record sorted by age.\n");
				printf("\nPress Enter to continue\n");
				getch();
				break;
				
			case 5:
				printf("\nDELETE RECORD AT FRONT\n");
				deleteFront(&cr);
				printf("\nPress Enter to continue\n");
				getch();
				break;
				
			case 6: 
				printf("\nDELETE RECORD AT REAR\n");
				deleteRear(&cr);
				printf("\nPress Enter to continue\n");
				getch();
				break;
				
			case 7:
				printf("\nDELETE RECORD AT INDEX\n");
				displayRecord(cr);
				deleteIndex(&cr);
				printf("\nPress Enter to continue\n");
				getch();
				break;
			
            case 8:
                printf("\nDISPLAY CLASS RECORD\n");
                displayRecord(cr);
                printf("\nPress Enter to continue\n");
				getch();
                break;
            
		}
	}while(option != 0);
	printf("Program Terminated, Thank you.");
}
