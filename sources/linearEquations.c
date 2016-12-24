#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void swap(long double * numberA, long double * numberB)
{
    *numberA = *numberA + *numberB;
    *numberB = *numberA - *numberB;
    *numberA = *numberA - *numberB;
}
//==============================================================================
char * haiAn(char a[], char b[], char c[],
            char a1[], char b1[], char c1[])
{
    long double a, b, c, a1, b1, c1;

    a = stringToNumber(a);
    b = stringToNumber(b);
    c = stringToNumber(c);
    a1 = stringToNumber(a1);
    b1 = stringToNumber(b1);
    c1 = stringToNumber(c1);
    static char s[100];
    if (a == 0 && b == 0||
        a1 == 0 && b1 == 0)
    {
        strcpy(s, "MATH ERROR");
        return s;
    }
    long double det, x, y;

    det = (a * b1 - a1 * b);

    a /= det;
    b /= (det * (-1));

    a1 /= (det * (-1));
    b1 /= det;

    swap(&a, &b1);

    x = (a * c) + (b * c1);
    strcpy(s, numberToString(x));
    y = (a1 * c) + (b1 * c1);
    strcat(s, "______");
    strcat(s, numberToString(y));

    return s;
}
//==============================================================================
char * baAn(char a[], char b[], char c[], char d[],
            char a1[], char b1[], char c1[], char d1[],
            char a2[], char b2[], char c2[], char d2[])
{
    long double a, b, c, d, a1, b1, c1, d1, a2, b2, c2, d2;

    a = stringToNumber(a);
    b = stringToNumber(b);
    c = stringToNumber(c);
    d = stringToNumber(d);
    a1 = stringToNumber(a1);
    b1 = stringToNumber(b1);
    c1 = stringToNumber(c1);
    d1 = stringToNumber(d1);
    a2 = stringToNumber(a2);
    b2 = stringToNumber(b2);
    c2 = stringToNumber(c2);
    d2 = stringToNumber(d2);

    static char s[100];
    if (a == 0 && b == 0 && c == 0 ||
        a1 == 0 && b1 == 0 && c1 == 0 ||
        a2 == 0 && b2 == 0 && c2 == 0)
    {
        strcpy(s, "MATH ERROR");
        return s;
    }
    long double det,
                x1, x2, x3, x4, x5, x6, x7, x8, x9,
                x, y, z;

    det = a*(b1*c2 - b2*c1) - b*(a1*c2 - a2*c1) + c*(a1*b2 - a2*b1);

    x1 = (b1*c2 - b2*c1) / det;
    x2 = ((-1)*(a1*c2 - a2*c1)) / det;
    x3 = (a1*b2 - a2*b1) / det;

    x4 = ((-1)*(b*c2 - b2*c)) / det;
    x5 = (a*c2 - a2*c) / det;
    x6 = ((-1)*(a*b2 - a2*b)) / det;

    x7 = (b*c1 - b1*c) / det;
    x8 = ((-1)*(a*c1 - a1*c)) / det;
    x9 = (a*b1 - a1*b) / det;

    swap(&x2, &x4);
    swap(&x3, &x7);
    swap(&x6, &x8);

    x = (x1 * d) + (x2 * d1) + (x3 * d2);
    strcpy(s, numberToString(x));
    y = (x4 * d) + (x5 * d1) + (x6 * d2);
    strcat(s, "______");
    strcat(s, numberToString(y));
    z = (x7 * d) + (x8 * d1) + (x9 * d2);
    strcat(s, "______");
    strcat(s, numberToString(z));

    return s;
}
//==============================================================================
