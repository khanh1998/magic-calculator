#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node{
	char data;
	Node* next;
};

Node* creatNode(char c); //tao mot node moi
void push (char c, Node** pHead); //them mot node vao stack
char pop (Node** pHead); //lay ky tren cung cua stack

int main(int argc, char const *argv[]){
	Node *Head_sh = creatNode(' '); //stack chua toan hang
	Node *Head_st = creatNode(' '); //stack chua toan tu
	
	//test Head_st
	push('a', &Head_st);
	push('b', &Head_st);
	push('c', &Head_st);
	push('d', &Head_st);
	push('e', &Head_st);
	//in ra
	Node* p = Head_st;
	while (p->next != NULL){
		printf("%c", p->data);
		p = p->next;
	}
	//edcba
	printf("\n");
	while (Head_st->next != NULL){
		printf("%c", pop(&Head_st));
	}
	return 0;
}
char pop (Node** pHead){
	char c;
	Node* pNew = (*pHead);
	*pHead = (*pHead)->next;
	c = pNew->data;
	free(pNew);
	return c;
}
void push (char c, Node** pHead){
	//tao them mot node chua ky tu c
	Node* p = creatNode(c);
	//day node vao stack
	p->next = *pHead; //tro p vao head (*pHead == head)
	*pHead = p; //gan p cho pHead
}
Node* creatNode(char c){
	Node *p = NULL;
	p = malloc(sizeof(Node));
	if (p == NULL){
		exit(0);
	}
	else {
		p->data = c; 
		p->next = NULL;
	}
	return p;
}
