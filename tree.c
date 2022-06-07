/**
 *  Program file name   : tree.c
 *  Description         : Definisi program dari header tree
 *  Author              : Rivaldo Fauzan Robani, 211524060
 *  Compiler            : GCC 4.9.2
 */

#include "tree.h"

#ifndef tree_C
#define tree_C

double calculate(addrNode root, bool *isSuccess) {
	
	// root adalah operator
    if(root->isSymbol){
    	// Tentukan operand dan hitung
        switch(root->symbol){
            case PLUS:{
                return calculate(root->leftChild,isSuccess) + calculate(root->rightChild,isSuccess);
                break;
            }
            case MINUS:{
                return calculate(root->leftChild,isSuccess) - calculate(root->rightChild,isSuccess);
                break;
            }
            case DIVISION:{
                if(calculate(root->rightChild,isSuccess) == 0) {
                    (*isSuccess) = false;
                	return;
				}
                else
                    return calculate(root->leftChild,isSuccess) / calculate(root->rightChild,isSuccess);
                break;
            }
            case MULTIPLY:{
                return calculate(root->leftChild,isSuccess) * calculate(root->rightChild,isSuccess);
                break;
            }
            case POWER:{
                return pow(calculate(root->leftChild,isSuccess), calculate(root->rightChild,isSuccess));
                break;
            }
            case PERCENTAGE:{
                return (calculate(root->leftChild,isSuccess) * calculate(root->rightChild,isSuccess))/100;
                break;
            }
            case SQUARE_ROOT:{
                return pow(calculate(root->rightChild,isSuccess), 1/calculate(root->leftChild,isSuccess));
                break;
            }
        }
    }
    
    // root adalah operator
    return root->number;
}

double checkString(char str[], int start, int end){
	int i;
    int flag = 1; // postive or negative flag
    int doubleFlag = 0;
    double sum = 0; // hasil konversi
    double divFactor = 10.0; // bertambah 10x lipat semakin ke posisi kanan dari simbol desimal
    
    
    // Check apakah bilangan negatif
    if (str[start] == MINUS){
        flag = -1;
        start++;
    }
    
    // Parsing string ke number
    for (i = start ; i <= end ; i++){
    	// Jika char adalah simbol operand dan bukan desimal
        if (!isdigit(str[i]) && str[i] != DECIMAL) 
            return MAX;
        
        // Check apakah bilangan desimal
        if (str[i] == DECIMAL){
            doubleFlag++;
            i++;
        }
        
        // konversi char ke number
        if (!doubleFlag)
            sum = sum * 10 + str[i] - '0';
        else{
            sum = sum + (str[i] - '0')/divFactor;
            divFactor *= 10;
        }
    }
    
    return sum*flag;
}

int findOperator(char str[], int start, int end) {
	int posPlusOrSub = 0;//Position of plus and minus signs 
    int numPlusOrSub = 0;//Number of plus and minus signs 
    int posDivOrMul = 0;//Multiply and divide and percenting sign position 
    int numDivOrMul = 0;//Number of multiplication and division and percenting numbers
    int posPowOrRoot = 0; // Power and square root sign position
    int numPowOrRoot = 0; // Number of the result after powering or square rooting
 
    int in_brackets = 0; //Identifiers not in parentheses 
    int k;
    
    // Tentukan jumlah dan posisi semua operator pada string
    for(k = start ; k <= end ; k++){
        if(str[k] == OPEN_BRACKET)
            in_brackets++;
        else if(str[k] == CLOSE_BRACKET)
            in_brackets--;
        
        // Jika diluar tanda kurung
        if(!in_brackets){
            if(str[k] == PLUS || str[k] == MINUS){
                // check apakah sebelumnya adalah operator
				if (k != start && isdigit(str[k-1])) {
					posPlusOrSub = k;
                	numPlusOrSub++;	
				}else if ((str[k-1] == OPEN_BRACKET || str[k-1] == CLOSE_BRACKET)) {
					posPlusOrSub = k;
                	numPlusOrSub++;	
				}
            }
            else if(str[k] == MULTIPLY || str[k] == DIVISION || str[k] == PERCENTAGE){
                posDivOrMul = k;
                numDivOrMul++; 
            }
            else if(str[k] == POWER || str[k] == SQUARE_ROOT){
                posPowOrRoot = k;
                numPowOrRoot++;
            }
        }
    }
    
    // posisi operator yang diprioritaskan
    int posOperator = -1;
    
    //Temukan posisi root node dimulai dengan urutan operator derajat terendah
    if(numPlusOrSub)
        posOperator = posPlusOrSub;
    else if(numDivOrMul)
        posOperator = posDivOrMul;
    else if(numPowOrRoot)
        posOperator = posPowOrRoot;
    
    return posOperator;
}

addrNode constructTree(char str[], int start, int end){
    addrNode root = (addrNode)malloc(sizeof(struct TNode));

	// if there is no char left in s[]
    if(start>end) 
		return NULL;
    
    double num = checkString(str, start, end);
	
	// Jika string hanya berisi operand  
    if(num!=0x3f3f3f3f){
        root->isSymbol = false;
        root->number = num;
        root->leftChild = NULL;
        root->rightChild = NULL;
        return root;
    }
    
    // Temukan posisi operator prioritas
    int pos_root = findOperator(str, start, end);
    
    // Jika tidak ada operator
    if(pos_root == -1) 
        return constructTree(str,start+1,end-1);
    
    // membuat root berisi operator
    root->isSymbol = true;
    root->symbol = str[pos_root];
    root->leftChild = constructTree(str, start, pos_root-1);
    root->rightChild = constructTree(str, pos_root+1, end);
    
    return root;
}

void deleteTree(addrNode root) {
	if (root == NULL)
		return;
	
	deleteTree(root->leftChild);
	deleteTree(root->rightChild);
	
	free(root);
}

#endif
