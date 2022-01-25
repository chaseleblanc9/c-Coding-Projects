//Timothy LeBlanc
//Tree Program

#include<iostream>
#include<string>

using namespace std;

struct node {
	int data;
	
	node* left;
	node* right;
	node* parent;
};


void deleteNode(node* ptr, int data) {

	if (ptr->data == data && ptr->left==NULL && ptr->right==NULL) {
		delete ptr;
	}
	else if (ptr->data == data && ptr->left != NULL && ptr->right == NULL) {
		ptr = NULL;
		if (ptr->parent->left == NULL) {
			ptr->parent->left = ptr->left;
			delete ptr;
		}

		else if (ptr->parent->right == NULL) {
			ptr->parent->right = ptr->right;
			delete ptr;
		}


	}
	else if(ptr->data == data && ptr->left == NULL && ptr->right != NULL) {
		ptr = NULL;
		if (ptr->parent->right == NULL) {
			ptr->parent->right = ptr->right;
			delete ptr;
		}
		else if (ptr->parent->left == NULL) {
			ptr->parent->left = ptr->left;
			delete ptr;
		}
	}

	else {
		deleteNode(ptr->left, data);
		deleteNode(ptr->right, data);

	}
}



void insertNode(node* ptr, int data) {	//Inserts node to the furthest left

	if (ptr->left == NULL) {
		node* newNode;
		newNode = new node;
		ptr->left = newNode;
		newNode->data = data;
		return;
	}
	else {
		return insertNode(ptr->left, data);
	}
}

void inOrder(node* t) {

	if (t != NULL) {
		inOrder(t->left);
		cout << t->data << " ";
		inOrder(t->right);
	}
}

void preOrder(node* t) {

	if (t != NULL) {
		cout << t->data << " ";
		preOrder(t->left);
	
		preOrder(t->right);
	}
}

void postOrder(node* t) {

	if (t != NULL) {
		postOrder(t->left);
		postOrder(t->right);
		cout << t->data << " ";

	}
}

using namespace std;

int main() {
	int value;
	string decision1;
	string decision2;
	int decision3;
	
	node* R;
	node* t;	//R and t are temporary variables to allow me to build the tree

	R = new node;
	R->data = 1;
	R->left = NULL;
	R->right = NULL;


	t = new node;
	t->data = 2;
	t->left = NULL;
	t->right = NULL;
	t->parent = R;
	R->left = t;

	t = new node;
	t->data = 3;
	t->left = NULL;
	t->right = NULL;
	t->parent = R;
	R->right = t;

	t = new node;
	t->data = 4;
	t->left = NULL;
	t->right = NULL;
	t->parent = R->left;
	R->left->left = t;

	t = new node;
	t->data = 5;
	t->left = NULL;
	t->right = NULL;
	t->parent = R->left;
	R->left->right = t;

	t = new node;
	t->data = 6;
	t->left = NULL;
	t->right = NULL;
	t->parent = R->right;
	R->right->left = t;

	t = new node;
	t->data = 7;
	t->left = NULL;
	t->right = NULL;
	t->parent = R->right;
	R->right->right = t;

	t = new node;
	t->data = 8;
	t->left = NULL;
	t->right = NULL;
	t->parent = R->left->left;
	R->left->left->left = t;

	t = new node;
	t->data = 9;
	t->left = NULL;
	t->right = NULL;
	t->parent = R->left->left;
	R->left->left->right = t;

	t = new node;
	t->data = 10;
	t->left = NULL;
	t->right = NULL;
	t->parent = R->left->right;
	R->left->right->left = t;





	cout << "Would you like to insert a node?" << endl;
	cin.clear();
	getline(cin, decision1);

	if (decision1 == "yes") {
		cout << "Enter the value you want to add to the tree" << endl;
		cin >> value;

		insertNode(R, value);

	}


	cout << "Would you like to delete a node" << endl;
	cin.clear();
	getline(cin, decision2);
	if (decision2 == "yes") {
		cout << "Enter the value you want to delete from the tree" << endl;
		cin >> value;

		deleteNode(R, value);
	}


	cout << "Press 1 to print the tree in post order, 2 for in order, and 3 for pre order" << endl;
	cin >> decision3;

	if (decision3 == 1) {
		postOrder(R);
	}
	else if(decision3 == 2) {
		inOrder(R);
	}
	else if (decision3 == 3) {
		preOrder(R);
	}



	system("PAUSE");
	return 0;
}