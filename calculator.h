/**
 *  Program file name   : calculator.h
 *  Description         : Deklarasi Header Calculator
 *  Author              : Rivaldo Fauzan Robani, 211524060
 *  Compiler            : GCC 4.9.2
 */
#ifndef calculator_H
#define calculator_H

#include "tree.h"
#include "tree.c"
#include "tampilan.c"
#include <stdbool.h>

typedef struct {
	char expression[200];
	double result;
	addrNode expressionTree;	
}Calculator;

void createCalculator(Calculator *calculator);
/**
 * Membuat calculator baru
 * IS : calculator random value
 * FS : calculator default value
 */

bool isValidExpression(char *expression);
/**
 * Mengecek apakah pada string ekspresi memuat karakter illegal (bukan operator/simbol matematis)
 * Mengembalikan true jika tidak ada karakter ilegal
 * Mengembalikan false jika terdapat karakter ilegal
 */
 
void checkFirstChar(char *expression);
/**
 * Mengecek apakah simbol pertama merupakan minus
 * IS : ekspresi string
 * FS1 : ekspresi string digeser ke kanan 1, dan pada index 0 insert '0'
 * FS2 : ekspresi string tidak dimanipulasi
 */
 
void insertExpression(Calculator *calculator);
/**
 * Memasukan string ekspresi kedalam kalkulator
 * IS : kalkulator dengan ekspresi kosong
 * FS : kalkulator dengan ekspresi terisi oleh inputan user
 */

bool calculateExpression();
/**
 * Melakukan kalkulasi ekspresi matematika pada tree
 * Mengembalikan true jika proses kalkulasi berhasil
 * Mengembalikan false jika proses kalkulasi gagal
 */

void printResult(Calculator calculator, bool isSuccess);
/**
 * Menampilkan hasil expresi
 * IS : layar kosong
 * FS : tampil hasil perhitungan ekspresi aritmatik dan ekspresinya
 */

bool isContinueCalculator();
/**
 * mengecek apakah pengguna mengulang proses kalkulasi
 * Mengembalikan true jika iya
 * Mengembalikan false jika tidak
 */

#endif
