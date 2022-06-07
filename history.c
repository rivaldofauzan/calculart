/**
 *  Program file name   : history.c
 *  Description         : Menampilkan data history di local file
 *  Author              : Rivaldo Fauzan Robani, 211524060
 *  Compiler            : GCC 4.9.2
 */

#include <stdio.h>
#include <string.h>
#include <time.h>

#include "tree.h"

struct history{
	char ekspresi[200];
    double fresult;
	char time[100];
}Record;

int saveHistory(char *expression, double result){
    FILE* pFile = 0;
    struct history Record;
    time_t _time;
    
    time (&_time);
    struct tm *tmi;
	  tmi = localtime (&_time);
    strftime (Record.time,100,"%d %b %Y %H:%M",tmi);
        
    strcpy(Record.ekspresi, expression);
    Record.fresult = result;

    fopen_s(&pFile,"history.dat","ab+"); // append and update binary, can be read
    if(!pFile)
    return 1; //fopen error

    fwrite(&Record,sizeof(Record),1,pFile);
    fclose(pFile);
        
    return 0;
}

int readHistory(){  //
    system("cls");
    FILE* pFile = 0;
    int i = 1;
    pFile = fopen("history.dat","ab+"); // append and update binary, can be read
    if(!pFile)
      return 1; //fopen error
    printf("\n\n\t=============================================================================\n");
    printf("\n\t\t                        History Calculator\n\n");
		printf(" \t=============================================================================\n\n");
    printf( "  \xDA\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n" );
    printf( "  \xB3 %-3s\xB3        %-12s\xB3         %-31s\xB3      %-14s\xB3\n", "No","Time", "Arithmetic Expression", "Result");
    printf( "  \xC3\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xB4\n" );

    do{
        fseek(pFile,(-i)*sizeof(Record),SEEK_END);
        fread(&Record,sizeof(Record),1,pFile);
        if(!feof(pFile) && i <= 30){
            if (ceil(Record.fresult) > Record.fresult)
                printf("  \xB3 %-3d\xB3 %-19s\xB3 %-39s\xB3 %-19f\xB3\n", i++, Record.time, Record.ekspresi, Record.fresult);
            else
                printf("  \xB3 %-3d\xB3 %-19s\xB3 %-39s\xB3 %-19d\xB3\n", i++, Record.time, Record.ekspresi, (int)Record.fresult);
        }
    }while(!feof(pFile) && i <= 30);
    printf( "  \xC0\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9" );
        
    fclose(pFile);
	

    return 0;
}
