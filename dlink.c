#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
	struct node* prev;
};
void insertf(struct node** head, int data){
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new -> data = data;	
	new -> next = (*head);
	new -> prev = NULL;
	if((*head) != NULL)
		(*head) -> prev = new;
		(*head) = new;
	}
void inserta(struct node* prev_node, int data){
	if(prev_node = NULL){
		printf("Cannot be Null");
		return;
	}
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new -> data = data;
	new -> next = prev_node->next;
	prev_node -> next = new;
	new -> prev = prev_node;
	if(new -> next != NULL)
	new -> next -> prev = new;
}
void inserte(struct node** head, int data){
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new -> data = data;
	new -> next = NULL;
	struct node* temp = *head;
	if(*head == NULL){
		new -> prev = NULL;
		*head = new;
		return;
	}
	while (temp -> next != NULL)
		temp = temp -> next;
		temp -> next = new;
		new -> prev = temp;
}
void delete(struct node** head, struct node* del){
	if(*head == NULL || del == NULL)
	return;
	if(*head == del)
		*head = del -> next;
	if(del -> next != NULL)
		del -> next -> prev = del -> prev;
	if(del -> next != NULL)
		del -> prev -> next = del -> next;
	free(del);
}
void display(struct node* n){
	struct node* last;
	while(n != NULL){
		printf("%d->", n->data);
		last = n;
		n = n -> next;
	}
	if (n == NULL)
	printf("NULL");
}

int main(){
	struct node* head = NULL;
	inserte(&head, 5);
	insertf(&head, 1);
	insertf(&head, 6);
	inserte(&head, 9);
	inserta(head, 11);
	inserta(head->next, 15);
	display(head);
	delete(&head, head->next->next->next->next->next);
	display(head);

}

