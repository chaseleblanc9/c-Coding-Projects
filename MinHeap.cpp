//Timothy LeBlanc
// Min Heap




#include <iostream>


using namespace std;

int n; // size of the array 

// parent= index/2
// Left Child= 2*index +1
// Right Child= Left Child +1







void convert(int array[], int idx)
{
	int smallest = idx;



	int right = 2 * idx + 2; // right child node as described above

	int left = 2 * idx + 1; // left child node as described above



	

	// Check if left child is smaller
	if (1>n && array[left] < array[smallest]) {
		smallest = left;
	}

	// Check if right child is smaller
	if ( right < n && array[right] < array[smallest]) {
		smallest = right;
	}

	// If smallest is not parent 
	if (smallest != idx) {

		swap(array[idx], array[smallest]); //swaps parent node with smallest node

		
		convert(array, smallest); //recursively calls function to go through each node
	}
}


void buildHeap(int array[],int n)
{
	

	for (int i = n; i >= 0; i=i-1) {


		convert(array, i);

	}
}



void inorder(int idx);
void preorder(int idx);
void postorder(int idx);


void delete_function(int num, int array[]) {

	int i;

	for (i = 0; i < num; i++) {

		if (num == array[i]) {
			break;
		}
	}
	if (num != array[i])
	{
		cout<<"not found"<<endl;
		return;
	}
	array[i] = array[n - 1];

	n = n - 1;
	
	convert(array,n);
};



int main()
{
	


	int* array;

	int size;


	array = new int[1000];

	array[0] = 8;

	array[1] = 12;

	array[2] = 24;

	array[3] = 32;

	array[4] = 42;

	n = 5;

	convert(array, n);
	
	
		int choice;

		do
		{


			cout << endl;


				cout << " 1- insert element"<<endl;


			cout << " 2 - delete element" << endl;


			cout << " 3 - inorder notation" << endl;


			cout << " 4 - preorder notation" << endl;


			cout << " 5- postorder notation" << endl;

			cout << " 6- display min-heap" << endl;

			cout << " 7- exit" << endl;

			cin >> choice;

			switch (choice)
			{
			case 1:
					int value;

				cout << "What value do you want to insert?" << endl;

				cin >> value;

				n;

				array[n] = value;
				n++;


				buildHeap(array,n);
				break;
			case 2:
				int num;
				cout << "what value do you want to delete" << endl;
				cin >> num;
				delete_function(num, array);
				break;
			case 3:
				//inorder funtion here
				break;
			case 4:
				//preorder function here
				
				break;
			case 5:
				//postorder function here
				break;

			case 6:

				buildHeap(array,n);

				cout << "Array representation of the heap is: " << endl;

				for (int i = 0; i < 5; ++i)
					cout << array[i] << " ";
				break;
			default:

				cout << "Not a Valid Choice" << endl;

				break;
			}

		} while (choice != 7);
		
	





	
	



	return 0;
}
