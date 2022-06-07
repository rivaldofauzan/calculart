/**
 *  Program file name   : main.c
 *  Description         : Main Driver
 *  Author              : Rivaldo Fauzan Robani, 211524060
 *  Compiler            : GCC 4.9.2
 */

#include "tree.h"
#include "tree.c"
#include "calculart.c"
#include "history.c"
#include "tampilan.c"

int main(int argc, char** argv) {
	
    // Main Menu
    menu:
    mainMenu();

    // Memilih mainMenu
    int choice = 0;
    scanf("%d", &choice);

    while(true){
        switch(choice){
            case 1 :
                calculator();
                while(true){
                    fflush(stdin);
                    char input = getch();
                    if((int) input == KEYBOARD_ESCAPE) goto menu;
		        }
                break;
            
            case 2 :
                readHistory();
                while(true){
                    fflush(stdin);
                    char input = getch();
                    if((int) input == KEYBOARD_TAB) goto menu;
		        }       
                break;
            
            
            case 3 :
                help();
                while(true){
                    fflush(stdin);
                    char input = getch();
                    if((int) input == KEYBOARD_F1) goto menu;
		        }    
                break;
            
            
            case 4 :
                credit();
                while(true){
                    fflush(stdin);
                    char input = getch();
                    if((int) input == KEYBOARD_BACKSPACE) goto menu;
		        }    
                break;
            
            case 5 :
                exit(0);
                break;
            default :
            	goto menu;
        }
    }

    return 0;
}
