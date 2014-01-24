// Ouditchya Sinha, Doubly Linked List.

// 100% Tested! :)

#include <cstdio>
#include <cstdlib>

using namespace std;

struct doubly_linked_list
{
	int data;
	struct doubly_linked_list *left, *right;
};

typedef struct doubly_linked_list node;

int main()
{
	int option, val, key, flag, status = 0;
	
	do
	{
		printf("\nEnter\n");
		printf("1: Create a Doubly Linked List\n");
		printf("2: Insert an Element into the Doubly Linked List\n");
		printf("3: Delete an Element from the Doubly Linked List\n");
		printf("4: Print the Doubly Linked List (Left to Right)\n");
		printf("5: Print the Doubly Linked List (Right to Left)\n");
		printf("6: Exit\n\n");
		scanf("%d",&option);
		
		switch( option )
		{
			case 1:
				if( status )
				{	
					printf("Doubly Linked List Already Created!\nDo you want to create a new one?\n1: Yes\n2: No\n");
					scanf("%d",&flag);
					if( flag != 1 )
						break;
				}
				else
					status = 1;
				node *head, *temp, *prev, *tail;
				head = (node *)malloc(sizeof(node));
				printf("Enter Elements of Doubly Linked List( Enter -999 to indicate end )\n");
				scanf("%d",&val);
				if( val == -999 )
				{
					head = NULL;
					status = 0;
					break;
				}
				head->data = val;
				head->left = NULL;
				temp = head;
				scanf("%d",&val);
				while( val != -999 )
				{
					temp->right = (node *)malloc(sizeof(node));
					prev = temp;
					temp = temp->right;
					temp->data = val;
					temp->left = prev;
					scanf("%d",&val);
				}
				temp->right = NULL;
				tail = temp;
				break;
			case 2:
				if( !status )
				{
					printf("Create Doubly Linked List First! Aborting...\n");
					break;
				}
				printf("Enter Key( Element before which new Element is to be inserted, -999 for end )\n");
				scanf("%d",&key);
				if( key == head->data )
				{
					temp = (node *)malloc(sizeof(node));
					printf("Enter new value: ");
					scanf("%d",&val);
					temp->data = val;
					temp->right = head;
					temp->left = NULL;
					head->left = temp;
					head = temp;
				}
				else if( key == -999 )
				{
					printf("Enter new value: ");
					scanf("%d",&val);
					temp = tail;
					temp->right = (node *)malloc(sizeof(node));
					temp = temp->right;
					temp->data = val;
					temp->right = NULL;
					temp->left = tail;
					tail->right = temp;
					tail = temp;
				}
				else
				{
					node *prev;
					temp = prev = head;
					flag = 0;
					while( temp->right != NULL )
					{
						if( temp->data == key )
						{
							flag = 1;
							break;
						}
						prev = temp;
						temp = temp->right;
					}
					if( flag || temp->data == key )
					{
						node *temp2 = (node *)malloc(sizeof(node));
						printf("Enter new value: ");
						scanf("%d",&val);
						temp2->data = val;
						temp2->right = temp;
						temp2->left = prev;
						prev->right = temp2;
						temp->left = temp2;
					}
					else
						printf("Key Not Found! Aborting...\n");
				}
				break;
			case 3:
				if( !status )
				{
					printf("Create Doubly Linked List First! Aborting...\n");
					break;
				}
				printf("Enter Element to be deleted: ");
				scanf("%d",&key);
				if( head->data == key )
				{
					temp = head;
					head = head->right;
					head->left = NULL;
					free( temp );
				}
				else if( tail->data == key )
				{
					temp = tail;
					tail = tail->left;
					tail->right = NULL;
					free( temp );
				}
				else
				{
					node *prev;
					temp = prev = head;
					flag = 0;
					while( temp->right != NULL )
					{
						if( temp->data == key )
						{
							flag = 1;
							break;
						}
						prev = temp;
						temp = temp->right;
					}
					if( flag || temp->data == key )
					{
						
						prev->right = temp->right;
						temp->right->left = prev;
						free( temp );
					}
					else
						printf("Key Not Found! Aborting...\n");
				}	
				break;
			case 4:
				if( !status )
				{
					printf("Create Doubly Linked List First! Aborting...\n");
					break;
				}
				temp = head;
				while( temp->right != NULL )
				{
					printf("%d --> ",temp->data); temp = temp->right;
				}
				printf("%d\n",temp->data);
				break;
			case 5:
				if( !status )
				{
					printf("Create Doubly Linked List First! Aborting...\n");
					break;
				}
				temp = tail;
				while( temp->left != NULL )
				{
					printf("%d --> ",temp->data); temp = temp->left;
				}
				printf("%d\n",temp->data);
				break;
			case 6:
				free( head );
				exit(0);
			default:
				printf("Invalid Command!!! Please Try Again\n");
				break;
		}
	}	while( option != 6 );
	
	return 0;
}
