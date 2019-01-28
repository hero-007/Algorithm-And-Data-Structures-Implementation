#include <iostream>

using namespace std;

struct node{
	int val;
	node *next;
	
	// creating a constructor 
	node(int a)
	{
		val = a;
		next = NULL;
	}
};

node * parse(int a[],int n){
	
	int l = n;
	node *head = NULL;
	node *temp = NULL;
	
	if (head == NULL){
		head = new node(a[0]);
		temp = head;
	}
	
	for (int i=1;i<l;i++)
	{
		temp->next = new node(a[i]);
		temp = temp->next;
	}
	
	return head;
}

void printLL(node *head)
{
	if (head == NULL)
		printf("Linked list is empty");
	else{
		cout<<"Content of linked list is ";
		while(head!=NULL)
		{
			printf(" -> %d",head->val);
			head = head->next;
		}
		cout<<endl;
	}
}

void deleteLL(node **head)
{
	if (head == NULL)
		cout<<"Their is nothing to delete."<<endl;
	else{
		node *previous,*current = *head;
		while(current!=NULL)
			{
				previous = current;
				current = current->next;
				cout<<"deleted : "<<previous->val<<endl;
				delete previous;
			}
		cout<<"Linked List deleted successfully."<<endl;
		*head = NULL;
	}
}
int main()
{
	int a[] = {10,28,38,49,56,57,98};
	node *head = parse(a,7);
	printLL(head);
	deleteLL(&head);
	/* node *a = new node(12);
	cout<<a->val<<" "<<a->next<<endl;
	*/
	
	return 0;		
}
