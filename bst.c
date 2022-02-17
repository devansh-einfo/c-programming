#include<stdio.h>
#include<stdlib.h>
struct node{
	int k;
	struct node *l, *r;
};

struct node *new(int item){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp -> k = item;
	temp -> l = temp -> r = NULL;
	return temp;
}

void inorder(struct node *root){
	if(root != NULL){
	inorder(root -> l);
	printf("%d -> ", root -> k);
	inorder(root -> r);
	}
}

void preorder(struct node *root){
	if(root == NULL){
		return;	
	}
	printf("%d -> ", root -> k);
	preorder( root -> l);
	preorder( root -> r);
}

void postorder(struct node *root){
	if(root == NULL){
		return;	
	}
	postorder( root -> l);
	postorder( root -> r);
	printf("%d -> ", root -> k);
}

struct node *insert(struct node *node, int k){
	if(node == NULL) return new(k);
		if(k < node -> k)
			node -> l = insert(node -> l, k);
		else
			node -> r = insert(node -> r, k);
	return node;
}

struct node *search(struct node *root, int k){
	if(root == NULL || root -> k )
		return root;
	else if(k > root -> k)
		return search(root -> r, k);
	else
		return search(root -> l, k);
	
}

struct node *delete(struct node *root, int k){
	if (root == NULL)
	return root;
	if( k < root -> k)
		root -> l = delete(root -> l, k);
	else if(k > root -> k)
		root -> r = delete(root -> r, k);
	else{
		if(root -> l == NULL){
			struct node *temp = root -> r;
			free(root);
			return temp;
	}
		else if(root -> r == NULL) {
			struct node *temp = root -> l;
			free(root);
			return temp;
}	

	//struct node *temp = min(root -> r);
	//root -> k = temp -> k;
	//root -> r = delete(root->r, temp -> k);
	//}
}
		return root;
}

int main(){
	struct node *root = NULL;
	root = insert(root, 50);
	root = insert(root, 25);
	root = insert(root, 75);
	root = insert(root, 22);
	root = insert(root, 40);
	root = insert(root, 60);
	root = insert(root, 80);
	root = insert(root, 90);
	root = insert(root, 15);
	root = insert(root, 30);
	printf("Inorder: ");
	inorder(root);
	printf("\n");
	printf("Preorder: ");
	preorder(root);
	printf("\n");
	printf("Postorder: ");
	postorder(root);
	printf("\n");
	root = delete(root, 30);
	printf("After deleting 4\n");
	printf("Inorder: \n");
	inorder(root);
	printf("\n");
	root = search(root, 50);
	
	
return 0;

}
