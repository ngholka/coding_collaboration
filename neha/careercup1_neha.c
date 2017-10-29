/*
    Given a root to a binary tree, find the level of the tree with the minimum sum.
    for example:
    50
    / \
    6 2
    / \ /
    30 80 7
    the answer is: level 2
*/
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct node
{
	int val;
	struct node *left;
	struct node *right;
	

}Node;

Node* createNewNode(int val)
{
	Node *res;
	res= (Node*)malloc(sizeof(Node));
	res->left=NULL;
	res->right=NULL;
	res->val=val;
	return res;
}

void getLevel(Node *root, int *res) {
	
	int resl[2] = {INT_MAX,0};
	int resr[2] = {INT_MAX,0};
	
	if(root->left==NULL & root->right==NULL)
	{
		res[0]=root->val;
		res[1]=0;
		printf("\n %d %d %d %d %d",root->val,  resl[0], resl[1], resr[0], resr[1]);
		return;
	}

	if(root->left!=NULL)
	{
		getLevel(root->left, resl);
	}		
	
	
	if(root->right!=NULL)
	{
		getLevel(root->right, resr);
	}			

	printf("\n %d %d %d %d %d", root->val, resl[0], resl[1], resr[0], resr[1]);
	if( resl[0] < resr[0] )
	{
		res[0] = resl[0]+root->val;
		res[1] = resl[1]+1;	
	}
	else
	{
		res[0] = resr[0]+root->val;
		res[1] = resr[1]+1;	
	}

}

int main()
{
	int res[2]={0,0};

	//create a tree
	Node *root = createNewNode(50);
	root->left=createNewNode(6);
	root->right=createNewNode(2);
	root->left->right=createNewNode(80);
	root->left->left=createNewNode(30);
	root->right->left=createNewNode(7);
	root->right->left->left=createNewNode(1);
	

	getLevel(root, res);
	printf("\nLevel is %d", res[1]);
}
