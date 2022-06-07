/**
 *  Program file name   : calculart.c
 *  Description         : Program calculart
 *  Author              : Rivaldo Fauzan Robani, 211524060
 *  Compiler            : GCC 4.9.2
 */

#include "calculator.h"
#include "calculator.c"
#include "tampilan.c"

void calculator() {
	Calculator kalkulator;
	
	// Anchor
    calculator_anchor :
    system("cls");

    while(true){
        system("cls");
        
        // create new calculator
        createCalculator(&kalkulator);
        
        // insert expression
        insertExpression(&kalkulator);
        
        // check expression validation
        if(!isValidExpression(kalkulator.expression)) {
            sleep(1);
            goto calculator_anchor;
        }
		
		// check minus sign exception
        checkFirstChar(kalkulator.expression);
            
        // Create expression tree
        kalkulator.expressionTree = constructTree(kalkulator.expression,0,strlen(kalkulator.expression)-1);
        
        // calculate expression tree
        bool isSuccess = calculateExpression(&kalkulator, kalkulator.expressionTree);
        
        // print result
        printResult(kalkulator, isSuccess);
        
        // delete expression tree
        deleteTree(kalkulator.expressionTree);
        
        // lakukan save history jika perhitungan berhasil
        if (isSuccess)
        	saveHistory(kalkulator.expression, kalkulator.result);
        
        // tentukan apakah user mengulang proses kalkulasi
        if(!isContinueCalculator()){
            break;
        }

    }
    printf("\n\n\n  Press ESCAPE on your keyboard to main menu");
}
