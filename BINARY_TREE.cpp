// Ouditchya Sinha, Linked List to Binary Tree.

// 100% Tested! :)

#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

struct linked_list
{
	int data;
	struct linked_list *next;
};

struct binary_tree
{
	int data;
	struct binary_tree *left, *right;
};

typedef struct linked_list node1;
typedef struct binary_tree node2;

node1 *head = NULL;
node2 *root = NULL;
queue< node2 * > q;

void print_linked_list();
void in_order( node2 *ptr );
void pre_order( node2 *ptr );
void post_order( node2 *ptr );

int main()
{
	int val;
	node1 *temp1;
	node2 *temp2, *parent;
	
	printf("Enter Linked List Data( Enter -999 to indicate End )\n");
	while( scanf("%d",&val) && val != -999 )
	{
		if( !head )
		{
			head = (node1 *)malloc(sizeof(node1));
			head->data = val;
			head->next = NULL;
			temp1 = head;
		}
		else
		{
			temp1->next = (node1 *)malloc(sizeof(node1));
			temp1 = temp1->next;
			temp1->data = val;
			temp1->next = NULL;
		}
	}
	
	temp1 = head;
	root = (node2 *)malloc(sizeof(node2));
	root->data = head->data;
	root->left = root->right = NULL;
	temp2 = root;
	q.push( temp2 );
	temp1 = temp1->next;
	
	while( temp1 )
	{
		parent = q.front();
		q.pop();
		if( temp1 )
		{
			parent->left = (node2 *)malloc(sizeof(node2));
			temp2 = parent->left;
			temp2->data = temp1->data;
			temp2->left = temp2->right = NULL;
			q.push( temp2 );
		}
		else
			break;
		if( temp1->next == NULL )
			break;
		temp1 = temp1->next;
		if( temp1 )
		{
			parent->right = (node2 *)malloc(sizeof(node2));
			temp2 = parent->right;
			temp2->data = temp1->data;
			temp2->left = temp2->right = NULL;
			q.push( temp2 );
		}
		else
			break;
		if( temp1->next == NULL )
			break;
		temp1 = temp1->next;
	}
	
	printf("\nLinked List\n\n");
	print_linked_list();
	printf("In Order Traversal of Binary Tree\n\n");
	in_order( root );
	printf("\n\nPre Order Traversal of Binary Tree\n\n");
	pre_order( root );
	printf("\n\nPost Order Traversal of Binary Tree\n\n");
	post_order( root );
	
	getchar();
	getchar();
	return 0;
}

void print_linked_list()
{
	node1 *temp1 = head;
	
	while( temp1 )
	{
		printf("%d ",temp1->data);
		temp1 = temp1->next;
	}
	printf("\n\n");
}

void in_order( node2 *ptr )
{
	if( !ptr )	return;
	in_order( ptr->left );
	printf("%d ",ptr->data);
	in_order( ptr->right );
}

void pre_order( node2 *ptr )
{
	if( !ptr )	return;
	printf("%d ",ptr->data);
	pre_order( ptr->left );
	pre_order( ptr->right );
}

void post_order( node2 *ptr )
{
	if( !ptr )	return;
	post_order( ptr->left );
	post_order( ptr->right );
	printf("%d ",ptr->data);
}
