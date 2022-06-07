/**
 *  Program file name   : tampilan.c
 *  Description         : Menampilkan tampilan layar Calculator
 *  Author              : Rivaldo Fauzan Robani, 211524060
 *  Compiler            : GCC 4.9.2
 */
#ifndef tampilan_C
#define tampilan_C

#include <stdio.h>
#include <conio.h>
#include <unistd.h>

#define KEYBOARD_TAB 9
#define KEYBOARD_ENTER 13
#define KEYBOARD_ESCAPE 27
#define KEYBOARD_BACKSPACE 8
#define KEYBOARD_F1 59
#define KEYBOARD_HOME 71


//MAIN MENU
void mainMenu(){
		system("cls");
		printf("\n\n\t================================\n");
		printf("\n\t\t  MAIN MENU\n\n");
		printf(" \t================================\n\n");
		printf("                 [1] Start     \n");
		printf("                 [2] History     \n");
		printf("                 [3] Help     \n");
        printf("                 [4] Credit     \n");
		printf("                 [5] Exit     \n\n");
		printf("                Pilih salah satu : ");
}

//CALCULATOR

//Calculator Grid Layout
void gridLayout(){
	
}

void gridLayout1(){

}

void gridLayout2(){

}


// FILE PRINTING
//Help
void help(){
	system("cls");
	char buff[255];
	FILE *fptr;
		
    // membuka file
	if((fptr = fopen("Folder teks/Help.txt","r")) == NULL){
        printf("Error: File tidak ada!");
        exit(1); // Tutup program karena file gak ada.
    }

	while(fgets(buff, sizeof(buff), fptr))
		printf("%s", buff);
	fclose(fptr);
}

//Credit
void credit(){
	system("cls");
	char buff[255];
	FILE *fptr;
		
    // membuka file
	if ((fptr = fopen("Folder teks/Credit.txt","r")) == NULL){
        printf("Error: File tidak ada!");
        // Tutup program karena file gak ada.
        exit(1);
    }

	while(fgets(buff, sizeof(buff), fptr))
		printf("%s", buff);
	fclose(fptr);
    printf("\n\n\n  Press BACKSPACE on your keyboard to main menu");
}

#endif
