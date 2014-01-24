// Ouditchya Sinha, Singly Linked List.

// 100% Tested! :)

#include <cstdio>
#include <cstdlib>

using namespace std;

struct linked_list
{
	int data;
	struct linked_list *next;
};

typedef struct linked_list node;

int main()
{
	int option, val, key, flag, status = 0;
	
	do
	{
		printf("Enter\n");
		printf("1: Create a Linked List\n");
		printf("2: Insert an Element into the Linked List\n");
		printf("3: Delete an Element from the Linked List\n");
		printf("4: Print the Linked List\n");
		printf("5: Exit\n\n");
		scanf("%d",&option);
		
		switch( option )
		{
			case 1:
				if( status )
				{	
					printf("Linked List Already Created, Do you want to create a new one?\n1: Yes\n2: No\n");
					scanf("%d",&flag);
					if( flag != 1 )
						break;
				}
				else
					status = 1;
				node *head, *temp;
				head = (node *)malloc(sizeof(node));
				printf("Enter Elements of Linked List( Enter -999 to indicate end )\n");
				scanf("%d",&val);
				if( val == -999 )
				{
					head->data = -999;
					head->next = NULL;
					break;
				}
				head->data = val;
				temp = head;
				scanf("%d",&val);
				while( val != -999 )
				{
					temp->next = (node *)malloc(sizeof(node));
					temp = temp->next;
					temp->data = val;
					scanf("%d",&val);
				}
				temp->next = (node *)malloc(sizeof(node));
				temp = temp->next;
				temp->data = -999;
				temp->next = NULL;
				break;
			case 2:
				if( !status )
				{
					printf("Create Linked List First! Aborting...\n");
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
					temp->next = head;
					head = temp;
				}
				else if( key == -999 )
				{
					printf("Enter new value: ");
					scanf("%d",&val);
					node *prev, *temp2;
					temp = prev = head;
					while( temp->data != -999 )
						prev = temp, temp = temp->next;
					temp2 = (node *)malloc(sizeof(node));
					temp2->data = val;
					prev->next = temp2;
					temp2->next = temp;
				}
				else
				{
					node *prev;
					temp = prev = head;
					flag = 0;
					while( temp->data != -999 )
					{
						if( temp->data == key )
						{
							flag = 1;
							break;
						}
						prev = temp;
						temp = temp->next;
					}
					if( flag )
					{
						node *temp2 = (node *)malloc(sizeof(node));
						printf("Enter new value: ");
						scanf("%d",&val);
						temp2->data = val;
						temp2->next = temp;
						prev->next = temp2;
					}
					else
						printf("Key Not Found! Aborting...\n");
				}
				break;
			case 3:
				if( !status )
				{
					printf("Create Linked List First! Aborting...\n");
					break;
				}
				printf("Enter Element to be deleted: ");
				scanf("%d",&key);
				if( head->data == key )
				{
					temp = head->next;
					free( head );
					head = temp;
				}
				else
				{
					node *prev;
					temp = prev = head;
					flag = 0;
					while( temp->data != -999 )
					{
						if( temp->data == key )
						{
							flag = 1;
							break;
						}
						prev = temp;
						temp = temp->next;
					}
					if( flag )
					{
						prev->next=temp->next;
						free( temp );
					}
					else
						printf("Key Not Found! Aborting...\n");
				}	
				break;
			case 4:
				if( !status )
				{
					printf("Create Linked List First! Aborting...\n");
					break;
				}
				temp = head;
				while( temp->next->data != -999 )
				{
					printf("%d --> ",temp->data); temp = temp->next;
				}
				printf("%d\n",temp->data);
				break;
			case 5:
				free( head );
				exit(0);
			default:
				printf("Invalid Command!!! Please Try Again\n");
				break;
		}
	}	while( option != 5 );
	
	return 0;
}
