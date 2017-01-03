#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct node Node;
struct node{
	char *data;
	Node *next;
};

Node* creatNode (char str[]); // tao mot node moi
void push (char str[], Node** pHead); // day mot node vao stack
char* pop (Node** pHead); // lay node tren cung cua stack
int isEmpty (Node** pHead); // kiem tra stack co rong hay khong
char get (Node** pOperator); // doc gia tri node tren cung cua stack Operator

char* caculate_infix (char infix[]); // tinh bieu thuc trung to 
int priority (char c); // xac dinh muc do uu tien cua toan tu 
int isOperator (char c); // kiem tra xem co phai la toan tu hay khong
char* getNumber (int* begin, char str[]); // tach so ra tu xau
char* solveTwoOperand (char opearator, char operandA[], char operandB[]);
int isFuction (char c);
char* solveFunc (char function, char operand[]);
int isExistFunc (char str[]); //kiem tra co ton tai mot ham toan hoc nao khong

char* bigDivide1 (char str[], int n);
char* bigMultiply (char str1[], char str2[]);
char* bigSubtraction (char str1[], char str2[]);
char* bigAddition (char str1[], char str2[]);
void standardize (char (*str1)[], char (*str2)[]); 

char* Cbrt (char s[]);
char* Sqrt (char s[]);
char* logn (char s[]);
char* Logarit (char s[]);
char* CoSin (char s[]);
char* Sin (char s[]);
char* Tan (char s[]);

int main (int argc, char const *argv[]){
	char inFix[1000]; //bieu thuc trung to
	scanf("%s", &inFix);
	printf("%s\n", caculate_infix(inFix));	
	return 0;
}

char* caculate_infix (char infix[]){

	Node *Operands = creatNode(" "); //stack chua toan hang
	Node *Operators = creatNode(" "); //stack chua toan tu
	int leng = strlen(infix);
	int i, begin = 0, j;
	int opearatorPriority; // muc do uu tien cua toan tu moi doc vao 
	int headOpearatorPriority; // muc do uu tien cua toan tu tren dinh stack
	char *str, headOperator, CharToString[1];
	char *popOperandA, *popOperandB, *popOperator;
	char function; //sin cos tan ...
	char *result; // result of solveTwoOperand

	for (i = 0; i < leng; i++){
		if (!isOperator(infix[i])){
			str = getNumber (&i, infix);
			push (str, &Operands);
		}
		else {
			if (infix[i] == '('){
				push ("(", &Operators);
			}
			else if (infix[i] == ')') {
				popOperator = pop(&Operators);
				while (*popOperator != '('){
				 	popOperandA = pop(&Operands);
				 	popOperandB = pop(&Operands);
				 	result = solveTwoOperand(popOperator[0], popOperandA, popOperandB);
				 	push(result, &Operands);
				 	popOperator = pop(&Operators);
				 }
			}
			else if (isFuction(infix[i])) { // sin cos tan log ln sqrt sqr
				CharToString[0] = infix[i]; // chuyen ky tu char sang string
				//tach phan bieu thuc ben trong ham toan hoc
				j = i + 2;
				while (!isOperator(infix[j])){
					str[j - (i + 2)] = infix[j];
					j++;
				}
				str[j - (i + 2)] = '\0';
				if (isExistFunc(str)){
					caculate_infix(str);
				}
				else{
					result = solveFunc(CharToString[0], str);
					push (result, &Operands);
				}
				i = j;
				continue;
				
			}
			else if (isEmpty(&Operators)){
				CharToString[0] = infix[i];
				push (CharToString, &Operators);
			}
			else {
				opearatorPriority = priority(infix[i]);
				
				headOperator = get (&Operators);
				headOpearatorPriority = priority(headOperator);

				if (opearatorPriority >= headOpearatorPriority){
					CharToString[0] = infix[i]; // chuyen ky tu char sang string
					push (CharToString, &Operators);
				}
				else {
					// thuc hien tinh toan voi toan tu tren dinh stack
					popOperator = pop(&Operators);
				 	popOperandA = pop(&Operands);
				 	popOperandB = pop(&Operands);
				 	result = solveTwoOperand(popOperator[0], popOperandA, popOperandB);
				 	push(result, &Operands);
				 	
				 	CharToString[0] = infix[i]; // chuyen ky tu char sang string
					push (CharToString, &Operators); // day toan tu moi doc vao stack
				}

			}
		}
	}
	//tinh tiep neu ngan xep chua rong
	while (!isEmpty(&Operators)){
		popOperator = pop(&Operators);
		popOperandA = pop(&Operands);
		popOperandB = pop(&Operands);
		result = solveTwoOperand(popOperator[0], popOperandA, popOperandB);
		push(result, &Operands);
	}
	//tra ve ket qua
	return Operands->data;
}

char* solveFunc (char function, char operand[]){
	char *result;
	switch (function){
		case 's': //sin()
			result = Sin(operand);
			break;
		case 'c': //cos()
			result = CoSin(operand);
			break;
		case 't': //tan()
			result = Tan(operand);
			break;
		case 'l': //ln()
			result = Logarit(operand);
			break;
		case 'L': //log()
			result = logn(operand);
			break;
		case 'v': //sqrt()
			result = Sqrt(operand);
			break;
	}
	return result;
}

int isExistFunc (char str[]){
	int leng = strlen(str);
	int i;
	for (i = 0; i < leng; i++){
		if (isFuction(str[i])){
			return 1;
		}
	}
	return 0;
}

char* solveTwoOperand (char operator, char operandA[], char operandB[]){
	char *result;
	switch (operator){
		case '+' :
			result = bigAddition(operandA, operandB);
			break;
		case '-' :
			result = bigSubtraction(operandA, operandB);
			break;
		case '*' :
			result = bigMultiply(operandA, operandB);
			break;
		case '/' :
			break;
		case '^' :
			break;
	};
	return result;
}

char* getNumber (int* begin, char str[]){
	int i = *begin, count = 0, leng = strlen(str);
	char *strnum = malloc(sizeof(char)*100);
	while (!isOperator(str[i]) && (i < leng)){
		strnum[count] = str[i];
		count++;
		i++;
	}
	strnum[count] = '\0';
	*begin = *begin + count - 1;
	return strnum;
}

int priority (char c){
	if (c == '*' || c == '/' || c =='^'){
		return 2;
	}
	else if (c == '+' || c == '-'){
		return 1;
	}
	else if (c == '('){
		return 0;
	}
}

int isOperator (char c){
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c =='^'){
		return 1;
	}
	else if (c == 's' || c == 'c' || c == 't' || c == 'L' || c == 'l' || c == 'v'){
		return 1;
	}
	else {
		return 0;
	}
}

int isFuction(char c){
	char funcList[7] = "sctlLv";
	if (strchr(funcList, c) != NULL){
		return 1;
	}
	return 0;
}

char* pop (Node** pHead){
	char *str;
	Node* pNew = (*pHead);
	*pHead = (*pHead)->next;
	str = (*pNew).data;
	free(pNew);
	return str;
}

void push (char str[], Node** pHead){
	//tao them mot node chua ky tu c
	Node* p = creatNode(str);
	//day node vao stack
	p->next = *pHead; //tro p vao head (*pHead == head)
	*pHead = p; //gan p cho pHead
}

Node* creatNode(char str[]){
	int leng = strlen(str);
	Node *p = NULL;
	p = malloc(sizeof(Node));
	if (p == NULL){
		exit(0);
	}
	else {
		p->next = NULL;
		p->data = malloc(sizeof(char)*leng); 
		strcpy((*p).data, str);
	}
	return p;
}

char get (Node** pOperator){
	Node *pNew = *pOperator;
	return *((*pNew).data);
}

int isEmpty (Node** pHead){
	Node *pNew = *pHead;
	if (pNew->next == NULL){
		return 1;
	}
	return 0;
}

char *bigAddition (char str1[], char str2[]) {
    static char res[100000];
    int carry = 0, sum, index = 0, i;
    char digit[10] = "0123456789";
    for (i = strlen(str1) - 1; i >= 0; i--) {
        sum = ((str1)[i] - '0') + ((str2)[i] - '0') + carry;
        carry = sum / 10;
        res[index] = digit[sum % 10];
        index++;
    }
    index--;

    for (i = 1; i <= index / 2 + 1; i++) {
        char tmp = res[i];
        res[i] = res[index - i];
        res[index - i] = tmp;
    }
    return res;
};
char *bigSubtraction (char str1[], char str2[]) {
    static char res[100000];
    int borrow = 0, s, index = 0, i;
    char digit[10] = "0123456789";
    for (i = strlen(str1) - 1; i >= 0; i--) {
        s = ((str1)[i] - '0') - ((str2)[i] - '0') - borrow;
        if (s < 0) {
            s += 10;
            borrow = 1;
        } else
            borrow = 0;
        res[index] = digit[s];
        index++;
    }
    index--;
    for (i = 1; i <= index / 2 + 1; i++) {
        char tmp = res[i];
        res[i] = res[index - i];
        res[index - i] = tmp;
    }
    return res;
}

char *bigMultiply (char str1[], char str2[]) {
    int res[strlen(str1) + strlen(str2)];
    int i, j;
    static char s[100000];
    char digit[10] = "0123456789";
    for (i = 0; i <= strlen(str1) + strlen(str2); i++)
        res[i] = 0;
    for (i = strlen(str1) - 1; i >= 0; i--) {
        for(j = strlen(str2) - 1; j >= 0; j--)
          res[i + 1 + j] += ((str1)[i] - '0') * ((str2)[j] - '0');
    }
    for (i = strlen(str1) + strlen(str2); i >= 0 ; i--) {
        if(res[i] > 9) {
            res[i-1] += res[i]/10;
            res[i] %= 10;
        }
    }
    for (i = 1; i <= strlen(str1) + strlen(str2) - 1; i++ ) {
        s[i - 1] = digit[res[i]];
    }
    return s;
}

char * numberToString(long double num)
{
    static char output[50];

    snprintf(output, 50, "%Lf", num);

    return output;
}
//==============================================================================
long double stringToNumber(char s[])
{
    int i = 0, j;
    long double number = 0, tmp;

    while (i < strlen(s)){
        if (s[i] == '.')
            break;
        i++;
    }
    if (s[0] == '-' && i != strlen(s)){
        tmp = 1 / pow(10, (strlen(s) - i - 1));
        for (j = (strlen(s) - 1); j > 0; j--)
            if (s[j] != '.'){
                number += (s[j] - 48) * tmp;
                tmp *= 10;
            }
        if(number > 0) number *= -1;
    }

    else if ( i != strlen(s)){
        tmp = 1 / pow(10, (strlen(s) - i) - 1);
        for (j = (strlen(s) - 1); j > -1; j--)
            if (s[j] != '.'){
                number += (s[j] - 48) * tmp;
                tmp *= 10;
            }
    }

    else if (s[0] == '-' && i == strlen(s)){
        tmp = 1;
        for (j = (strlen(s) - 1); j > 0; j--)
            {
                number += (s[j] - 48) * tmp;
                tmp *= 10;
            }
        if(number > 0) number *= -1;
    }

    else if ( i == strlen(s)){
        tmp = 1;
        for (j = (strlen(s) - 1); j > -1; j--)
            {
                number += (s[j] - 48) * tmp;
                tmp *= 10;
            }
    }

    return number;
}
//==============================================================================
char * Sin(char s[])
{
    static char str[100];
    long double i = stringToNumber(s);
    strcpy(str, numberToString(sin(i)));
    return str;
}
//==============================================================================
char * CoSin(char s[])
{
    static char str[100];
    long double c = stringToNumber(s);
    strcpy(str, numberToString(cos(c)));
    return str;
}
//==============================================================================
char * Tan(char s[])
{
    static char str[100];
    long double i = stringToNumber(s);
    strcpy(str, numberToString(tan(i)));
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
        int j, k;
        for(j = 0; s[j] != ','; j++)
            str1[j] = s[j];
        j++;
        for(k = 0; k <= (strlen(s) - j); k++, j++)
        {
            if(s[j] == ' ')
            {
                k--;
                continue;
            }
            str2[k] = s[j];
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
