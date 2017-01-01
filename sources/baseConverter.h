void convert(int in, int ou, char number[]) {
    long long dec;
    //  Convert to DEC
    for (long long i = (strlen(number) - 1), j = 1; i > -1; i--, j = j * in){
        if(number[i] > 47 && number[i] < 58)
            dec = (number[i] - 48) * j + dec;
        else if (number[i] > 64 && number[i] < 71)
            dec = (number[i] - 55) * j + dec;
    }
    //  Convert to OTHERS
    char base16[16] ="0123456789ABCDEF";
    long long res[1000], index = 0;

    if (dec == 0) {
        printf("0");
        return;
    } while (dec != 0) {
        res[index] = dec % ou;
      	dec = dec / ou;
      	++index;
    }
    --index;
    for(  ; index > -1; index--)
        printf("%c", base16[res[index]]);
    printf("\n");
}

void convertingBase(char s[]) {
  char stIn[100], stOu[100], stNumber[100];
  int i = 1, j = 0;
  while (s[i] != ')') {
    stIn[j] = s[i];
    j++;
    i++;
  }
  stIn[j] = '\0';
  ++i;
  j = 0;
  while (s[i] != 't') {
    stNumber[j] = s[i];
    j++;
    i++;
  }
  stNumber[j] = '\0';
  i += 3;
  j = 0;
  while (s[i] != ')') {
    stOu[j] = s[i];
    j++;
    i++;
  }
  stOu[j] = '\0';
  convert(stringToNumber(stIn), stringToNumber(stOu), stNumber);
}
