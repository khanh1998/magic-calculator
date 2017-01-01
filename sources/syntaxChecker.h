/*  START BASE CONVERTER CHECKER */

int validBase(char st[]) {
  // return:
  // 0: invalid
  // 1: valid
  if (strlen(st) > 2 || strlen(st) == 0)
    return 0;
  else if (strlen(st) == 1) {
    if ((st[0] <= 57) && (st[0] >= 50)) {
      return 1;
    } else
      return 0;
  } else if (strlen(st) == 2)
    if (st[0] != '1')
      return 0;
    if (st[1] > '6' || st[1] < '0')
      return 0;
  return 1;
}

int isValueinBase(char number[], int base) {
  // return:
  // 1: true
  // 0: false

  for (int i = 0; i <= strlen(number) - 1; i++)
      if (number[i] < 48 || ((number[i] > (57 - 10 + base)) && number[i] < 65) || number[i] > 65 + base - 11)
          return 0;
  return 1;
}

int checkConverterSyntax(char s[]) {
  // return:
  // -5: invalid base
  // -4: input is not number in base.
  // -3: wrong converting base spell.
  // 6: converting base.

  char stIn[100], stOu[100], stNumber[100];
  if (s[0] != '(')
    return -3;
  int i = 1, j = 0;
  while (s[i] != ')') {
    if (s[i] < '0' || s[i] > '9')
      return -3;
    stIn[j] = s[i];
    j++;
    i++;
  }
  stIn[j] = '\0';
  ++i;
  j = 0;
  while (s[i] != 't') {
    if ((s[i] < '0' || s[i] > '9') && (s[i] < 'A' || s[i] > 'F'))
      return -3;
    stNumber[j] = s[i];
    j++;
    i++;
  }
  stNumber[j] = '\0';
  if (s[i+1] != 'o' || s[i+2] != '(')
    return -3;
  i += 3;
  j = 0;
  while (s[i] != ')') {
    if (s[i] < '0' || s[i] > '9')
      return -3;
    stOu[j] = s[i];
    j++;
    i++;
  }
  stOu[j] = '\0';
  // printf("%lu In %d\n", strlen(stIn), validBase(stIn));
  // printf("%lu Ou %d\n", strlen(stOu), validBase(stOu));
  if (validBase(stOu) == 0 || validBase(stIn) == 0)
    return -5;
  if (stringToNumber(stOu) > 16 || stringToNumber(stOu) < 2)
    return -3;
  if (isValueinBase(stNumber, stringToNumber(stIn)) == 0)
    return -4;
  return 6;
};

/*  END BASE CONVERTER CHECKER */

/*  START EQUATION CHECKER */

int checkEquationSyntax(char s[]) {
    return 2;
};

/*  END EQUATION CHECKER */

/*  START EXPRESSION CHECKER */

int checkExpressionSyntax(char s[]) {
    return 1;
};

/*  END EXPRESSION CHECKER */
