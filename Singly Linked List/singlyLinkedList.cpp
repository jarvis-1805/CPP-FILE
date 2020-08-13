#include<iostream>
#include <stdlib.h>

using namespace std;

class singlyLinkedList
{
	public:
		struct node
		{
			int data;
			struct node *next;
		};
		struct node *head=NULL, *newNode, *temp;
		
		void options();
		void choice();
		void choiceCalling(int);
		
		void create();
		void traverse();
		void insert_at_beginning();
		void insert_at_location();
		void insert_at_end();
		void delete_at_beginning();
		void delete_at_location();
		void delete_at_end();
		void exitFunc();
		
		int countList();
		void emptyListChecker();
};

void singlyLinkedList::options()
{
	cout << "\n1. CREATE"
		<<	"\n2. TRAVERSE"
		<<	"\n3. INSERT AT BEGINNING"
		<<	"\n4. INSERT AT LOCATION"
		<<	"\n5. INSERT AT END"
		<<	"\n6. DELETE AT BEGINNING"
		<<	"\n7. DELETE AT LOCATION"
		<<	"\n8. DELETE AT END"
		<<	"\n9. EXIT";
	
	choice();
}

void singlyLinkedList::choice()
{
	int ch;
	cout << "\n\nEnter the number of your choice: ";
	cin >> ch;
	choiceCalling(ch);
}

void singlyLinkedList::choiceCalling(int ch)
{
	switch(ch)
	{
		case 1:
			create();
			break;
		case 2:
			traverse();
			break;
		case 3:
			insert_at_beginning();
			break;
		case 4:
			insert_at_location();
			break;
		case 5:
			insert_at_end();
			break;
		case 6:
			delete_at_beginning();
			break;
		case 7:
			delete_at_location();
			break;
		case 8:
			delete_at_end();
			break;
		case 9:
			exitFunc();
			break;
		default:
			cout << "\n########### WRONG CHOICE... ###########\n";
			options();
	}
}

void singlyLinkedList::create()
{
	cout << "\n------------ CREATING NEW LIST ------------\n";
	char ch;
	do
	{
		newNode = (struct node *)new struct node;
		cout << "Enter the new node's data : ";
		cin >> newNode -> data;
		newNode -> next = NULL;
		if(head == NULL)
		{
			head = temp = newNode;
		}
		else
		{
			temp -> next = newNode;
			temp = newNode;
		}
		cout << "\nDo you want to enter more nodes? y/n: ";
		cin >> ch;
	}while(ch == 'y');
	temp = head;
}

void singlyLinkedList::traverse()
{
	cout << "\n------------ TRAVERSING LIST ------------\n";
	emptyListChecker();
	temp = head;
	cout << endl;
	while(temp != NULL)
	{
		cout << temp -> data;
		temp = temp -> next;
		if(temp != NULL)
			cout << " -> ";
	}
	cout << endl;
}

void singlyLinkedList::insert_at_beginning()
{
	cout << "\n------------ INSERTING AT BEGINNING ------------\n";
	emptyListChecker();
	newNode = (struct node *)new struct node;
	cout << "Enter the new node's data : ";
	cin >> newNode -> data;
	newNode -> next = head;
	head = newNode;
	cout << "\nSuccessfully inserted the node at beginning\n";
}

void singlyLinkedList::insert_at_location()
{
	cout << "\n------------ INSERTING AT LOCATION ------------\n";
	emptyListChecker();
	int loc, i=1, count;
	count = countList();
	while(1)
	{
		cout << "Enter the new node's location: ";
		cin >> loc;
		if(loc > count || loc == 0)
		{
			cout << "\n########### WRONG LOCATION... ###########\n";
			continue;
		}
		if(loc == 1)
		{
			insert_at_beginning();
			break;
		}
		else
		{
			newNode = (struct node *)new struct node;
			cout << "Enter the new node's data : ";
			cin >> newNode -> data;
			temp = head;
			while(i < loc)
			{
				if(i == loc-1)
					break;
				temp = temp -> next;
				++i;
			}
			newNode -> next = temp -> next;
			temp -> next = newNode;
			cout << "\nSuccessfully inserted the node at " << loc << endl;
			break;
		}
	}
}

void singlyLinkedList::insert_at_end()
{
	cout << "\n------------ INSERTING AT END ------------\n";
	emptyListChecker();
	newNode = (struct node *)new struct node;
	cout << "Enter the new node's data : ";
	cin >> newNode -> data;
	newNode -> next = NULL;
	temp = head;
	while(temp -> next != NULL)
	{
		temp = temp -> next;
	}
	temp -> next = newNode;
	cout << "\nSuccessfully inserted the node at end\n";
}

void singlyLinkedList::delete_at_beginning()
{
	cout << "\n------------ DELETING AT BEGINNING ------------\n";
	emptyListChecker();
	int c = countList();
	if(c == 0)
		cout << "The list is empty";
	else
	{
		temp = head;
		head = head -> next;
		delete(temp);
		cout << "\nSuccessfully deleted the node at beginning\n";
	}
}

void singlyLinkedList::delete_at_location()
{
	cout << "\n------------ DELETING AT LOACTION ------------\n";
	emptyListChecker();
	struct node *temp1;
	int loc, i=1, count;
	count = countList();
	while(1)
	{
		cout << "Enter the to be deleted node's location: ";
		cin >> loc;
		if(loc == 1)
		{
			delete_at_beginning();
			break;
		}
		if(loc > count || loc == 0)
		{
			cout << "\n########### WRONG LOCATION... ###########\n";
			continue;
		}
		else
		{
			temp = head;
			while(i < loc)
			{
				if(i == loc-1)
					break;
				temp = temp -> next;
				temp1 = temp1 -> next;
				++i;
			}
			if(temp -> next -> next == NULL)
			{
				delete_at_end();
				break;
			}
			temp -> next = temp -> next -> next;
			delete(temp1 -> next);
			cout << "\nSuccessfully deleted node at " << loc << endl;
			break;
		}
	}
}

void singlyLinkedList::delete_at_end()
{
	cout << "\n------------ DELETING AT END ------------\n";
	emptyListChecker();
	int c = countList();
	temp = head;
	if(c == 1)
	{
		delete(temp -> next);
		head = NULL;
		cout << "\nSuccessfully deleted the node at end\n";
	}
	else
	{
		while(temp -> next -> next != NULL)
		{
			temp = temp -> next;
		}
		delete(temp -> next);
		temp -> next = NULL;
		cout << "\nSuccessfully deleted the node at end\n";
	}
}

void singlyLinkedList::exitFunc()
{
	cout << "\n########### EXITING... ###########\n";
	exit(1);
}

int singlyLinkedList::countList()
{
	int count=0;
	temp = head;
	while(temp != NULL)
	{
		temp = temp -> next;
		count ++;
	}
	return count;
}

void singlyLinkedList::emptyListChecker()
{
	if(head == NULL)
	{
		cout << "\n########### The list is empty ###########\n";
		options();
	}
}

int main()
{
	char ch;
	singlyLinkedList ob;
	cout << "\n=========== SINGLY LINKED LIST ===========\n";
	do
	{
		ob.options();
		cout << "\nDo you want to operate more? y/n: ";
		cin >> ch;
	}while(ch == 'y');
	cout << "\n########### EXITING... ###########\n";
	return 0;
}