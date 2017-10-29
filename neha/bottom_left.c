//Given a binary tree, find the leftmost value in the last row of the tree.
//
//Example 1:
//
//Input:
//
//    2
//   / \
//  1   3
//
//Output:
//1
//
//Example 2:
//
//Input:
//
//        1
//       / \
//      2   3
//     /   / \
//    4   5   6
//       /
//      7
//
//Output:
//7
//


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



Node* mergeTrees(Node* t1, Node* t2) {
    
	if(t1==NULL && t2==NULL)
	{
		return NULL;
	}
	else if(t1==NULL)
	{
		return t2;

	}
	else if(t2==NULL)
	{
		return t1;
	}

	t1->val += t2->val;

	t1->left = mergeTrees(t1->left, t2->left);
	t1->right = mergeTrees(t1->right, t2->right);
	 
	return t1;	





