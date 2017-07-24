#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *head = NULL;

/* Function to print linked list */
void printlist(void)
{
	struct node *temp = head;
	
	if(temp == NULL) {
		printf("Link list is empty\n");
		return;
	}
	while (temp->next != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void remove_duplicates()
{

}

void merge_two_sortedlist(void)
{
	
}

int detectloop_removeloop (void)
{
	return 0;
}

void reverse_list(void)
{

}

void delete_node_at_position(int pos)
{
	struct node *temp, *prev;

	int count = 0;
	int i = 0;

	if(head == NULL) {
		printf("linklist is empty\n");
		return;
	}

	temp = head;
	if (pos == 1) {
		head = temp->next;
		temp->next == NULL;
		free(temp);
		printf("first node deleted successfully\n");
		return;
	}
	else { 
		while(temp != NULL) {
			temp = temp->next;
			count++;
		}
		temp = head;
		prev = NULL;
		
		if (pos > 0 && pos <= count) {
			for (i = 0; i < pos; i++) {
				prev = temp;
				temp = temp->next;
			}
			prev->next = temp->next;
			free(temp);
			printf("node deleted successfully at pos:%d\n", pos);
		} else {
                	printf("Position is out of range");
		}
	}
	
}
void search_item(int data)
{
	struct node *temp = head;

	int pos = 0;

	if(head == NULL) {
		printf("linklist is empty\n");
		return;
	}
	while(temp->next != NULL) {
		if(temp->data == data) {
			printf("data %d found at %d\n", data, pos);
			return;
		}
		temp = temp->next;
		pos++;
	}
	if(temp->data == data) {
		printf("data %d found at %d\n", data, pos);
		return;
	}
	printf("data is not present in the list\n");

}

void delete_from_end(void)
{
	struct node *temp = head;
	struct node *p;

	if(head == NULL) {
		printf("linklist is empty\n");
		return;
	}
	if(head->next == NULL) {
		free(head);
		head == NULL;
		printf("last node delete successfully\n");
		return;
	}
	
	while(temp->next != NULL) {
		p = temp;
		temp = temp->next;
	}
	
	free(temp);
	p->next = NULL;
	printf("last node delete successfully\n");

}

void delete_from_begin(void)
{
	struct node *temp = head;

	if(temp == NULL) {
		printf("linklist is empty\n");
		return;
	}
	
	head = temp->next;
	temp->next = NULL;
	free(temp);
	printf("first node delete successfully\n");
	
}

void insert_node_begin(int data)
{
	struct node *temp = NULL;
	struct node *new_node  = (struct node *)malloc( sizeof(struct node) );
	if(!new_node) {
		printf("dynamic node creation failed");
		return;
	}	
	
	if (head == NULL) {
		head = new_node;
		head->data = data;
		head->next = NULL;
		return;
	}

	/* put in the data  */
	new_node->data = data;
	
	/* link the old list off the new node */
	new_node->next = head;
	
	/* move the head to point to the new node */
	head = new_node;
		
}

void insert_node_end(int data)
{
	struct node *temp = NULL;	
	struct node *new_node  = (struct node *)malloc( sizeof(struct node) );
	if(!new_node) {
		printf("dynamic node creation failed");
		return;
	}	

	if (head == NULL) {
		head = new_node;
		head->data = data;
		head->next = NULL;
		return;
	}
	
	temp = head;

	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = new_node;
	/* put in the data  */
	new_node->data = data;
	new_node->next = NULL;
}



int main()
{
	int i = 0;

	printf("testing single linked list\n");
	#if 0
	for (i = 0; i < 10; i++)
		insert_node_begin(i);	
	printlist();
	#endif

	for (i = 0; i < 10; i++)
		insert_node_end(i);
	printlist();
	
	delete_from_begin();
	printlist();

	delete_from_end();
	printlist();

	search_item(5);

	delete_node_at_position(5);
	printlist();

	return 0;
}
