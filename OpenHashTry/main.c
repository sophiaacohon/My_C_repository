#include <stdio.h>
#include <stdlib.h>
#include "openhash.h"
//#include "openhash.c"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	Dictionary d;
	initDictionary(&d);
	
	Student A = {19103447, "Sophia Cohon", 'F', "BSIS", 4};
	Student B = {19103893, "Shem Cardoza", 'M', "BSIS", 4};
	Student C = {12345678, "Shannen Nazareno", 'F', "BSIS", 4};
	Student D = {21346789, "Kirzteen Uy", 'F', "BSIS", 4};
	Student E = {19101234, "Sebastian Valle", 'M', "BSIS", 4};
	Student F = {19105678, "Clint Englis", 'M', "BSIS", 4};
	Student G = {19103447, "AAAAAAAAA", 'F', "BSIS", 4};
	Student H = {19103447, "BBBLLLEEE", 'F', "BSIS", 4};
	
	addStudent(&d, A);
	addStudent(&d, B);
	addStudent(&d, C);
	addStudent(&d, D);
	addStudent(&d, E);
	addStudent(&d, F);
	addStudent(&d, G);
	addStudent(&d, H);
	
	visualize(d);
	
	return 0;
}
