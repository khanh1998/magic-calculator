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
char * exp(char s[])
{
    static char str[100];
    char str1[100], str2[100];
    int j, tmpv;
    /* tach 1 chuoi thanh 2 so */
    for(j = 0; s[j] != ','; j++)
        str1[j] = s[j];
    if(s[++j] == ' ') j++;
    tmpv = j;
    for(int i = 0; i <= (strlen(s) - tmpv); i++, j++)
        str2[i] = s[j];

    long double i = stringToNumber(str1),
                i1 = stringToNumber(str2),
                tmp;

    /* bat dau tinh */
    if (i == 0 && i1 < 0)
    {
        strcpy(str, "MATH ERROR");
        return str;
    }
    else
    {
        if (i >= 0)
        {
            tmp = pow( i, i1 );
        }
        else
        {
            long double test_i1 = i1;

            i *= (-1);
            while (abs(test_i1) < 2) test_i1 *= 10;

            if ( strstr(str2, ".") == NULL )
            {
                if ( str2[strlen(str2) - 1] % 2 == 0)
                    tmp = pow( i, i1 );
                else
                    tmp = pow( i, i1 ) * (-1);
            }
            else if ( fmod( test_i1, 2 ) != 0 ) // so le
            {
                strcpy(str, "MATH ERROR");
                return str;
            }
            else if ( fmod( test_i1, 4 ) != 0) // so le bac 2
                tmp = pow( i, i1 ) * (-1);
            else
            {
                tmp = pow( i, i1 ); // so chan
            }
        }
    }
    strcpy(str, numberToString(tmp));
    return str;
}
//==============================================================================
char * nthRoot ( char s[])
{
    static char str[100];
    char str1[100], str2[100];
    int j, tmpv;
    /* tach 1 chuoi thanh 2 so */
    for(j = 0; s[j] != ','; j++)
        str1[j] = s[j];
    if(s[++j] == ' ') j++;
    tmpv = j;
    for(int i = 0; i <= (strlen(s) - tmpv); i++, j++)
        str2[i] = s[j];

    long double i = stringToNumber(str1),
                i1 = stringToNumber(str2),
                tmp;
    /* bat dau tinh */
    if (i1 == 0 || (i == 0 && i1 < 0))
    {
        strcpy(str, "MATH ERROR");
        return str;
    }
    else if ( i1 > 0)
    {
        if (i >= 0)
        {
            tmp = pow( i, (1 / i1) );
        }
        else
        {
            long double test_i1 = i1;

            i *= (-1);
            while (abs(test_i1) < 2) test_i1 *= 10;

            if ( strstr(str2, ".") == NULL )
            {
                if ( str2[strlen(str2) - 1] % 2 == 0)
                {
                    strcpy(str, "MATH ERROR");
                    return str;
                }
                else tmp = pow( i, (1 / i1) ) * (-1);
            }
            else if ( fmod( test_i1, 2 ) != 0 ) // truong hop so le b1 can ra > 0.
                tmp = pow( i, (1 / i1) );
            else if ( fmod( test_i1, 4 ) != 0) // truong hop so le b2 can ra < 0.
                tmp = pow( i, (1 / i1) ) * (-1);
            else                                // truong hop so chan
            {
                strcpy(str, "MATH ERROR");
                return str;
            }
        }
    }
    else
    {
        i1 *= (-1);
        if (i >= 0)
        {
            tmp = 1 / pow( i, (1 / i1) );
        }
        else
        {
            long double test_i1 = i1;

            i *= (-1);
            while (abs(test_i1) < 2) test_i1 *= 10;

            if ( strstr(str2, ".") == NULL )
            {
                if ( str2[strlen(str2) - 1] % 2 == 0)
                {
                    strcpy(str, "MATH ERROR");
                    return str;
                }
                else tmp = 1 / (pow( i, (1 / i1) ) * (-1));
            }
            else if ( fmod( test_i1, 2 ) != 0 ) // truong hop so le b1 can ra > 0.
                tmp = 1 / pow( i, (1 / i1) );
            else if ( fmod( test_i1, 4 ) != 0) // truong hop so le b2 can ra < 0.
                tmp = 1 / (pow( i, (1 / i1) ) * (-1));
            else                               // truong hop so chan
            {
                strcpy(str, "MATH ERROR");
                return str;
            }
        }
    }
    strcpy(str, numberToString(tmp));
    return str;
}
//==============================================================================
