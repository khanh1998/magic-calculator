#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char * numberToString(long double num) {
    static char output[50];

    snprintf(output, 50, "%Lf", num);

    return output;
}
//==============================================================================
long double stringToNumber(char s[]) {
    int i = 0;
    long double number = 0, tmp;

    while (i < strlen(s)){
        if (s[i] == '.')
            break;
        i++;
    }
    if (s[0] == '-' && i != strlen(s)){
        tmp = 1 / pow(10, (strlen(s) - i - 1));
        for (int j = (strlen(s) - 1); j > 0; j--)
            if (s[j] != '.'){
                number += (s[j] - 48) * tmp;
                tmp *= 10;
            }
        if(number > 0) number *= -1;
    }

    else if ( i != strlen(s)){
        tmp = 1 / pow(10, (strlen(s) - i) - 1);
        for (int j = (strlen(s) - 1); j > -1; j--)
            if (s[j] != '.'){
                number += (s[j] - 48) * tmp;
                tmp *= 10;
            }
    }

    else if (s[0] == '-' && i == strlen(s)){
        tmp = 1;
        for (int j = (strlen(s) - 1); j > 0; j--)
            {
                number += (s[j] - 48) * tmp;
                tmp *= 10;
            }
        if(number > 0) number *= -1;
    }

    else if ( i == strlen(s)){
        tmp = 1;
        for (int j = (strlen(s) - 1); j > -1; j--)
            {
                number += (s[j] - 48) * tmp;
                tmp *= 10;
            }
    }

    return number;
}
//==============================================================================
char * basicEquation(char strA[],char strB[]){
    long double a, b, x ;
    static char s[100];

    a = stringToNumber(strA);
    b = stringToNumber(strB);

    a = stringToNumber(a)
    if (a == 0 && b != 0)
        strcpy(s, "no solution");
    else if (a == 0 && b == 0)
        strcpy(s, "infinitely many solutions");
    else {
        x = (b * (-1))/a;
        strcpy(s, numberToString(x));
    }
    return s;
}
//==============================================================================
char * quadraticEquation(char strA[],char strB[], char strC[])
{
    long double a, b, c, delta, x1, x2;
    static char s[100];

    a = stringToNumber(strA);
    b = stringToNumber(strB);
    c = stringToNumber(strC);

    if (a == 0){
        strcpy(s, bac1 (b, c));
        return s;
    }
    delta = b*b - 4*a*c;
    if (delta < 0)
        strcpy(s, "no solution");
    else if (delta == 0){
        x1 = (-b + sqrt(delta)) / (2 * a);
        strcpy(s, numberToString(x1));
    }
    else{
        x1 = (-b + sqrt(delta)) / (2 * a);
        strcpy(s, numberToString(x1));
        x2 = (-b + sqrt(delta)) / (2 * a);
        strcat(s, "_____");
        strcat(s, numberToString(x2));
    }
    return s;
}
//==============================================================================
char * cubicEquation(char strA[],char strB[], char strC[], char strD[])
{
    long double a, b, c, d, x1, x2, x3, delta, k;
    static char s[100];

    a = stringToNumber(strA);
    b = stringToNumber(strB);
    c = stringToNumber(strC);
    d = stringToNumber(strD);

    if (a == 0){
        strcpy(s, bac2(b, c, d));
        return s;
    }
    delta = (b*b - 3*a*c);
    k = (9*a*b*c - 2*b*b*b - 27*a*a*d) / (2 * sqrt(abs(delta*delta*delta)));
    if (delta > 0 ){
        if (abs(k) <= 1){
            x1 = (2 * sqrt(delta) * cos(acos(k)/3) - b) / (3*a);
            strcpy(s, numberToString(x1));
            x2 = (2 * sqrt(delta) * cos(acos(k)/3 - (2*acos(-1)/3)) - b) / (3*a);
            strcat(s, "_____");
            strcat(s, numberToString(x2));
            x3 = (2 * sqrt(delta) * cos(acos(k)/3 + (2*acos(-1)/3)) - b) / (3*a);
            strcat(s, "_____");
            strcat(s, numberToString(x3));

        }
        else{
            x1 = (sqrt(delta)*abs(k) / (3*a*k))*(cbrt(abs(k) + sqrt(k*k-1)) + cbrt(abs(k) - sqrt(k*k-1))) - (b/(3*a));
            strcpy(s, numberToString(x1));

        }
    }
    else if (delta == 0){
        x1 = ((b * -1) + cbrt(b*b*b - 27*a*a*d)) / (3*a);
        strcpy(s, numberToString(x1));

    }
    else{
        x1 = (sqrt(abs(delta)) / (3*a))*(cbrt(k + sqrt(k*k+1)) + cbrt(k - sqrt(k*k+1))) - (b/(3*a));
        strcpy(s, numberToString(x1));

    }
    return s;
}
//==============================================================================
