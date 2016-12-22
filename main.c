#include <stdio.h>
#include <stdlib.h>

Node* creatNode(char c);
void push (char c, Node** pHead); //them mot node vao stack
char pop (Node** pHead); //lay ky tu dau tien cua stack
typedef struct node Node;
struct node{
	char data;
	Node next;
}

void printREADME() {
    printf("Welcome to MAGIC CALCULATOR.");
}

int main(void) {
    printREADME();
    Node *Head_sh = creatNode(' '); //stack chua toan hang
	Node *Head_st = creatNode(' '); //stack chua toan tu
    return 0;
}
void push (char c, Node** pHead){
	//tao them mot node chua ky tu c
	Node* p = creatNode(c);
	//day node vao stack
	
}
Node* creatNode(char c){
	Node *p = NULL;
	p = malloc(sizeof(Node));
	if (p == NULL){
		exit(0);
	}
	else {
		p->data = c; //(*p).data = c;
		p->Next = NULL;
	}
	return p;
}
