#include <stdio.h>
#include <conio.h>
#include <string.h>

#define SIZE 10

struct Student
{
    int roll;
    char name[20];
};

void main()
{
    struct Student hashTable[SIZE];
    int i, index;

    clrscr();

    for(i = 0; i < SIZE; i++)
    {
	hashTable[i].roll = -1;
	strcpy(hashTable[i].name, "-");
    }

    index = 47 % SIZE;
    hashTable[index].roll = 47;
    strcpy(hashTable[index].name, "Sahil");

    printf("HASH TABLE\n");
    printf("-------------------------------------------------\n");
    printf("| Index | Roll Number | Name                    |\n");
    printf("-------------------------------------------------\n");

    for(i = 0; i < SIZE; i++)
    {
	if(hashTable[i].roll == -1)
	    printf("|  %2d   |     -       | %-22s |\n", i, "-");
	else
	    printf("|  %2d   |     %2d      | %-22s |\n",
		   i, hashTable[i].roll, hashTable[i].name);
    }

    printf("-------------------------------------------------\n");

    getch();
}