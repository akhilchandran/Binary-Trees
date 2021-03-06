/*
Q:	Given a binary tree, print out the nodes of the tree according to a
	bottom-up "postorder" traversal -- both subtrees of a node are printed
	out completely before the node itself is printed, and each left subtree
	is printed before the right subtree.
* post-order
	1 Traverse the left subtree by recursively calling the post-order function.
	2 Traverse the right subtree by recursively calling the post-order function.
	3 Display the data part of the root (or current node).

 */


#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
}; 

void printPostorder(struct node *binaryTree)
{
        if(binaryTree == NULL){
                return;
	}
        printPostorder(binaryTree->left);
	printPostorder(binaryTree->right);
	printf(" %d",binaryTree->data);
	return;
}

struct node *NewNode(int data) {
	struct node* node = malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

struct node *insert(struct node *node, int data)
{
	if(node == NULL){
		return(NewNode(data));
	}else{
		if(data <= node->data)
			node->left = insert(node->left, data);
		else
			node->right = insert(node->right, data);
	}
}

struct node *build20_5_156()
{
	struct node *root = NULL;
	root = insert(root, 2);
	root = insert(root, 0);
	root = insert(root, -5);
	root = insert(root, -1);
	root = insert(root, 5);
	root = insert(root, 6);
	return root;
}

main()
{
	struct node *root = build20_5_156();
        printPostorder(root);
	printf("\n");
}
	
