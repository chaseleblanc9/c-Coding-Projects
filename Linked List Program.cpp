// Timothy LeBlanc
//Linked List Program

#include <iostream>
#include <cstdlib>
#include <string>




using namespace std;

class node {
public:
	string name;
	int age;
	double gpa;
	node* next;
};



void Print_Da_List(node* n) {

	cout << "Name				Age				GPA" << endl;
	cout << "-------------------------------------------" << endl;

	while (n != NULL){

		cout << n->name << "				" << n->age << "				" << n->gpa << endl;
		n = n->next;
	}
}





void Put_One_In(node *start, string name, int age, double gpa)
{
	//create a new node to put into the linked list
	node* newNode = new node();
	node* last;
	last = start;



	// inserts the user given information into the new node
	newNode->name = name;
	newNode->age = age;
	newNode->gpa = gpa;
	


	// New node is going to be put to the end of the list, so we make its next NULL
	newNode->next = NULL;
	


	//If the list is empty, then the new node will act as the beginning of the linked list
	if (start == NULL)
	{
		start = newNode;
		return;
	}



	// if the list is not empty, then we set last to the end of the list
	while (last->next != NULL)
		last = last->next;



	// this will make the last node in the list the newly created node
	last->next = newNode;
	return;
}




void Take_One_Out(node* start, string name, int age, double gpa)
{
	// set a base for temporary node

	node* temp, * prev;

	temp = start;

	// Check to see if the starting node is the one that matches the information given
	if ( temp->name == name && temp->age == age && temp->gpa == gpa)
	{
		temp = start;
		start = start->next;
		return;
	}

	// This loop will search for the information that the user provided

	else {
		prev = start;

		while ((temp->name != name && temp->age != age && temp->gpa != gpa) && temp != NULL)
		{
			prev = prev->next;
			temp = prev->next;
			prev->next = temp->next;
		}
	}
	

	// If information cannot be found in the list  (list is checked all the way until after the final node and a match is not found)
	if (temp == NULL) {
		cout << "Student cannot be found" << endl;
		return;
	}


	// Delete the node
	delete(temp);
}





	int main() {


		//Declare variables needed


		node* ptr;
		ptr = new(node);

		int decision=0;
		string name;
		int age;
		double gpa;

		// ask user what they want to do
		while (decision!=4) {
			cout << "Enter 1 to insert a new student, Enter 2 to take out a student, Enter 3 to print the list of student info, Press 4 to exit" << endl;
			cin >> decision;

			//insert node 
			if (decision == 1) {

				cout << " Enter the name of the new Student" << endl;
				cin.ignore();
				getline(cin,name);
		
				cout << " Enter the Age of the new Student" << endl;
				cin >> age;
				cout << "Enter the GPA of the new student" << endl;
				cin >> gpa;

				Put_One_In(ptr,name,age,gpa);
			}
			//delete node
			 if (decision == 2) {
				 cout << " Enter the name of the Student to be deleted" << endl;
				 cin.ignore();

				 getline(cin,name);
				 
				 cout << " Enter the Age of the Student to be deleted" << endl;
				 cin >> age;

				 cout << "Enter the GPA of the student to be deleted" << endl;
				 cin >> gpa;

				Take_One_Out(ptr,name, age,gpa);
			}
			 //print table
			 if (decision == 3) {
				 Print_Da_List(ptr);
			 } 
		}
		system("PAUSE");
		return(0);
	}
