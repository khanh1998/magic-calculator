#include <stdio.h>
#include <string.h>
#include "sources/checkSpell.h"

char stringLine[6969];

void printREADME() {
    printf("***********************************************\n");
    printf("*         Welcome to MAGIC CALCULATOR         *\n");
    printf("***********************************************\n");
    printf("*            What this app can do:            *\n");
    printf("* Calculate the value of expression.          *\n");
    printf("*   Example: 6^9-9/(6+9)                      *\n");
    printf("* Solve quadratic & cubic equation.           *\n");
    printf("*   Example: x^2-3x+1=4                       *\n");
    printf("* Solve two & three hiddens equation.         *\n");
    printf("*   Example: (x+y=1)&(x-y=0)                  *\n");
    printf("* Converting any bases into others.           *\n");
    printf("*   Example: (2)1010->(10)                    *\n");
    printf("* ALL FEATURES YOU NEED IS IN ONE MAGIC LINE! *\n");
    //printf("***********************************************\n");
}

int readLine() {
    scanf("%s", stringLine);
    for (int i = 0; i <= strlen(stringLine) - 1; i++) {
        if (stringLine[i] == '-' && stringLine[i+1] == '>')
            return checkBaseSpell(stringLine);
        if (stringLine[i] == 'x')
            return checkEquationSpell(stringLine);
    };
    return checkExpressionSpell(stringLine);
}

int isContinue() {
    /* your code goes here */
    char s[100];
    int length;
    scanf("%s", s);
    for (length = 0; s[length] != '\0'; length++);
    if (length != 1)
        return -1;
    else if (s[0] == 78 || s[0] == 110)
        return 0;
    else if (s[0] == 89 || s[0] == 121)
        return 1;
    return -1;
}

int main(void) {
    int typeLine, isStop = 0, kt;
    do {
        printREADME();
        printf("Put in your LINE and see MAGIC: \n");
        typeLine = readLine();
            //   return:
            //  -3: wrong converting base spell.
            //  -2: wrong equation spell.
            //  -1: wrong expression spell.
            //   1: experssion.
            //   2: quadratic equation.
            //   3: cubic equation.
            //   4: two hiddens equation.
            //   5: three hiddens equation.
            //   6: converting base.
        switch(typeLine) {
            case 1: printf("calculateExpression\n");
                    //  calculateExpression(stringLine);
                    break;
            case 2: printf("solveQuadraticEquation\n");
                    //  solveQuadraticEquation(stringLine);
                    break;
            case 3: printf("solveCubicEquation\n");
                    //  solveCubicEquation(stringLine);
                    break;
        };
        //  ask if continue
        printf("Do you want to continue (Y/N)?\n");
        do {
            kt = isContinue();
            if (kt == -1) {
                printf("Your request is not valid, please input 'Y' or 'N'.\n");
            } else if (kt == 0)
                isStop = 1;
        } while (kt == -1);
        if (isStop)
            printf("Bye bye <3");
    } while (isStop == 0);

    return 0;
}
