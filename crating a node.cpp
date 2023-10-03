#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node*next;
};
int main(){
	struct Node*head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;
	head=(struct Node*)malloc(sizeof(struct Node));
	second=(struct Node*)malloc(sizeof(struct Node));
	third=(struct Node*)malloc(sizeof(struct Node));
	head->data=45;
	head->next=second;
	second->data=98;
	third->data=3;
	third->next=NULL;
	printf("%d",head->data);
	return 0;
};
