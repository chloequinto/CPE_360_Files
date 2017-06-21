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

class queue {
public:
	//queue of chunks
	chunk *head;
	//constructor 
	queue() {
		head = NULL;
	}

	//add to stuff to Q: enqueue
	void enqueue(int x) {
		if (head == NULL) {
			//Q is empty. Grab a chunk, and add to Q. It's the only element 
			
			chunk *temp = new chunk;
			temp->value = x; 
			head = temp;
		}

		else {
			//add this to the structure, right at the top 
			chunk *temp = new chunk;
			temp->value = x;

			//1. add new chunk to Q
			temp->next = head;

			//2. Update head to now point to this 
			head = temp;
		}
	}
	//delete stuff from Q: dequeue
	void dequeue() {
		//go to the end and delete the last chunk 

		if (head == NULL) {
			cout << "nothing to delete" << endl;
		}

		else if (head->next == NULL) {
			cout << "about to delete: " << head->value << endl;
			delete head; 
			head = NULL;
		}
		else {
			//take two pointers, go all teh way to the end
			chunk *chase, *follow; 
			chase = follow = head; 

			//go to the end: chase goes to the lase one, follow to second last

			while (chase->next != NULL)
			{
				follow = chase; 
				chase = chase->next; //follow takes chase current position, chase goes forward 
			}
			cout << "about to delete: " << chase->value << endl;
			delete chase; 
			follow->next = NULL; //follow does janitorial work 
		}

	}
	//display contents 

	void display() {
		if (head == NULL) {
			cout << "nothing to display" << endl;

		}
		else {
			chunk *temp; 
			temp = head; 
			while (temp != NULL) {
				cout << temp->value << endl;
				temp = temp->next; 
			}
		}
	}
};

int main()
{
	queue myQ; 
	int choice; 

	while (1) {
		//infinite loop, never ends
		cout << "Press 1 to enqueue" << endl;
		cout << "Press 2 to dequeue" << endl;
		cout << "Press 3 to display" << endl;
		cout << "Anything else to quit" << endl;
		cin >> choice; 
		switch (choice) {
		case 1: 
			cout << "Enqueue what?" << endl;
			int value; 
			cin >> value; 
			myQ.enqueue(value);
			break; 
		case 2:
			myQ.dequeue(); 
			break; 
		case 3:
			myQ.display();
			break; 
		default:
			cout << "Goodbye" << endl;
		
		}
	}
	system("pause");
	return 0;
}