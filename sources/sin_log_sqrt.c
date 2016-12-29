#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char * numberToString(long double num)
{
    static char output[50];

    snprintf(output, 50, "%Lf", num);

    return output;
}
//==============================================================================
long double stringToNumber(char s[])
{
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
char * R_Sin(char s[])
{
    static char str[100];
    long double i = stringToNumber(s);
    strcpy(str, numberToString(sin(i)));
    return str;
}
//==============================================================================
char * D_Sin(char s[])
{
    static char str[100];
    long double i = stringToNumber(s);
    strcpy(str, numberToString(sin(i * (M_PI / 180)) ));
    return str;
}
//==============================================================================
char * R_CoSin(char s[])
{
    static char str[100];
    long double i = stringToNumber(s);
    strcpy(str, numberToString(cos(i)));
    return str;
}
//==============================================================================
char * D_CoSin(char s[])
{
    static char str[100];
    long double i = stringToNumber(s);
    strcpy(str, numberToString(cos(i * (M_PI / 180)) ));
    return str;
}
//==============================================================================
char * R_Tan(char s[])
{
    static char str[100];
    long double i = stringToNumber(s);
    // co the sai so can test lai.
    if ( (i > 1.57078 && i < 1.5708) || (i < -1.57078 && i > -1.5708) ||
        (i > 4.71237 && i < 4.7124) || (i < -4.71237 && i > -4.7124))
    {
        strcpy(str, "MATH ERROR");
        return str;
    }
    strcpy(str, numberToString(tan(i)));
    return str;
}
//==============================================================================
char * D_Tan(char s[])
{
    static char str[100];
    long double i = stringToNumber(s);
    if ( i == 90 || i == -90 || i == 270 || i == -270)
    {
        strcpy(str, "MATH ERROR");
        return str;
    }
    strcpy(str, numberToString(sin(i * (M_PI / 180)) ));
    return str;
}
//==============================================================================
char * Logarit(char s[])
{
    static char str[100];
    if(strstr(s, ",") == NULL)
    {
        long double i = stringToNumber(s);
        strcpy(str, numberToString(log10(i)));
    }
    else
    {
        char str1[100], str2[100];
        int j;
        for(j = 0; s[j] != ','; j++)
            str1[j] = s[j];
        j++;
        for(int i = 0; i <= (strlen(s) - j); i++, j++)
        {
            if(s[j] == ' ')
            {
                i--;
                continue;
            }
            str2[i] = s[j];
        }
        long double i = stringToNumber(str1),
                    i1 = stringToNumber(str2),
                    tmp;
        tmp = log(i1) / log(i);
        strcpy(str, numberToString(tmp));
    }
    return str;
}
//==============================================================================
char * logn(char s[])
{
    static char str[100];
    long double i = stringToNumber(s), tmp;
    tmp = log(i) / log(M_E);
    strcpy(str, numberToString(tmp));
    return str;
}
//==============================================================================
char * Sqrt(char s[])
{
    static char str[100];
    long double i = stringToNumber(s);
    if (i < 0)
    {
        strcpy(str, "MATH ERROR");
        return str;
    }
    strcpy(str, numberToString(sqrt(i)));

    return str;
}
//==============================================================================
char * Cbrt(char s[])
{
    static char str[100];
    long double i = stringToNumber(s);
    strcpy(str, numberToString(cbrt(i)));

    return str;
}
//==============================================================================
