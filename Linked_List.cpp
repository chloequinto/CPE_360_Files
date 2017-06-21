#include <iostream>
#include <stdlib.h>
using namespace std;


class chunk {
public:
	int value;
	chunk *next;

	chunk() {
		value = 0;
		next = NULL;
	}
};

class linkedlist {
public:
	chunk *head;

	linkedlist() {
		head = NULL;
	}

	//Add anywhere
	void add() {
		int x, pos, counter = 0;
		cout << "What amount do you want added: " << endl;
		cin >> x;
		cout << "Which position: " << endl;
		cin >> pos;

		chunk *temp, *chase, *follow;
		temp = new chunk;
		temp->value = x;
		chase = head; //chase starts at the beginning

		// STEP 1: Create a counter 
		while (chase != NULL)
		{
			chase = chase->next;
			counter++;
		}
		
		/* 
		STEP 2: Check each case
		Case 1: User wants to add to the top 
		Case 2: User wants to add anywhere 
		Case 3: User picks a position not on the list */


		// Case 1: 
		if (pos == 0) // if they want to add to the top 
		{
			if (head == NULL) // if there's nothing in the list
			{
				head = temp;
				head->next = NULL;
			}
			else // if there's something on the list 
			{

				temp->next = head; 
				head = temp; 
			}
		}

		//Case 2: 
		else if (pos > 0 && pos <= counter) // if position is valid 
		{
			follow = chase = head;
			for (int i = 0; i < pos; i++)
			{
				follow = chase;
				chase = chase->next;
			}
			follow->next = temp;
			temp->next = chase;
		}

		

		//Case 3: 
		else //position is not valid 
		{
			cout << "That position is not in the list" << endl;
		}
	}

	void subtract() {
		int pos, counter = 0;
		chunk *chase, *follow; 
		chase = head;

		cout << "What position would you like to delete: " << endl;
		cin >> pos;

		//Step 1: Create a counter 
		while (chase != NULL) 
		{
			chase = chase->next;
			counter++;
		}

		// STEP 2: Check each case
		//Case 1: User wants to delete from the top 
		//Case 2: User wants to delete anywhere 
		//Case 3: User picks a position not on the list 

		//Case 1: 
		if (pos == 0) { 

			if (head == NULL) //nothing in the list
			{
				cout << "The list is empty" << endl;
			}

			else {
				chase = head;
				head = head->next; 
				delete chase;
				cout << "Deleted" << endl;
			}
		}

		//Case 2: 
		else if (pos > 0 && pos <= counter) {
				
				follow = chase = head;

				for (int i = 0; i < pos; i++) {
					follow = chase;
					chase = chase->next;
				}
				follow->next = chase->next;
				delete chase;
				cout << "Deleted" << endl;
			}
		//Case 3: 
		else {
				cout << "That position is not in the list" << endl;
			}

		}

	
	//Display 
	void display() {
		chunk *trop;
		trop = head;
		if (trop == NULL) {
			cout << "Nothing to see" << endl;
		}
		while (trop != NULL) {
			cout << trop->value << "-->" << endl;
			trop = trop->next;
		}
	}
};
int main() {
	linkedlist linky;
	int choice;

	cout << "Welcome to the Lined List. Note: the list starts at position 0" << endl;

	while (1) {
	
		cout << "Press 1: Add from the list" << endl;
		cout << "Press 2: Subtract the list" << endl;
		cout << "Press 3: Display the list" << endl;
		cout << "------------------------------" << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			linky.add(); //parameters are not needed
			cout << "------------------------------" << endl;
			break;
		case 2:
			linky.subtract(); //parameters are not needed
			cout << "------------------------------" << endl;
			break;
		case 3:
			cout << "Here it is: " << endl;
			linky.display();
			cout << "------------------------------" << endl;
			break;
		default:
			exit(1);
		}
	}
	system("pause");
	return 0;
}
