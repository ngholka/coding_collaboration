//Given an array of integers where each element points to the next element detect cycle without extra space
//1->2->3->4->5->3
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct node
{
	int val;
	struct node *next;
	

}Node;

Node* createNewNode(int val)
{
	Node *res;
	res= (Node*)malloc(sizeof(Node));
	res->next=NULL;
	res->val=val;
	return res;
}

void isCyclic(Node *root)
{
	Node *slow=root, *fast=root;
	while(fast->next!=NULL)
	{
		fast = fast->next->next;	
		slow = slow->next;

		if(fast==NULL) break;
	
		if(fast->val == slow->val)
		{
			printf("cycle found");
			return;
		}
	
	}
	printf("No cycle detected");

}

int main()
{
	Node *root, *t, *t1;
	root = createNewNode(1);
	t=root;
	t->next = createNewNode(2);
	t=t->next;
	t->next = createNewNode(3);
	t=t->next;
	t1=t;
	t->next = createNewNode(4);
	t=t->next;
	t->next = createNewNode(5);
	t=t->next;
	t->next = createNewNode(6);
	t=t->next;
//	t->next = t1;

	isCyclic(root);
}
