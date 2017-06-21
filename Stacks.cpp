
#include<iostream> 
#include<stdlib.h> //for exit

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


class stacks {
public:
	chunk *head;

	stacks() {
		head = NULL;
	}

	//Add Function 

	void push(int x) {

		chunk *temp = new chunk;
		temp->value = x;

		//if stack is empty 
		if (head == NULL) {
			head = temp;

		}
		//if stack has chunks 
		else {
			temp->next = head;
			head = temp;
		}
	}

	//Delete Function 
	void pop() {

		//if stack is empty
		if (head == NULL) {
			cout << "Nothing to delete" << endl;
			cout << "-------------------------" << endl; //lines make everything easier to see
		}

		//if stack has chunks 
		else {
			chunk *temp = head;
			head = head->next;
			cout << "Deleting: " << temp->value << endl;
			cout << "-------------------------" << endl;
			delete temp;
		}
	}
	//Display Function 

	void display() {
		chunk *temp = head;
		//if stack is empty; 
		if (head == NULL) {
			cout << "Nothing left to display " << endl;
			cout << "-------------------------" << endl; //to see better
		}

		//if stack has chunks 
		else {
			while (temp!= NULL) {
				cout <<  temp->value << "-->" << endl;
				temp = temp->next;
			}
		}

	}
};

int main() {
	stacks pancakes;
	int choice = 0;

	while (1) {
		cout << "Press 1: Add to the stack" << endl;
		cout << "Press 2: Delete from the stack" << endl;
		cout << "Press 3: to Display the stack" << endl;
		cout << "Press anything else to quit" << endl;
		cout << "-------------------------" << endl;
		cin >> choice; 

		switch (choice) {
		case 1:
			cout << "What would you like to add" << endl;
			int amount;
			cin >> amount;
			pancakes.push(amount);
			break;
		case 2:
			pancakes.pop();
			break;
		case 3:
			pancakes.display();
			break;
		default:
			exit(1);
		}
	}
	system("pause");
	return 0;
}
