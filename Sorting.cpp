//Timothy LeBlanc
// Sorting Program



#include <iostream>

using namespace std;

int count = 0;

int  quicksort(int list[], int left, int right, int total) {
	int pivot, i, j; 
	int temp;
	int counter = 0;
	if (left < right)
	{
		i = left;
		j = right + 1;
		pivot = list[left];
		counter = counter + 3;
		do {
			do {
				i++;
				counter++;
			}
			while (list[i] < pivot);
			do {

				j--;
				counter++;
			}
			while (list[j] > pivot);
			if (i < j) {
				swap(list[i], list[j]);
				counter++;
			}
		} while (i < j);

		
		swap(list[left], list[j]);
		counter++;
		total += counter;
		quicksort(list, left, j - 1,total);
		quicksort(list, j + 1, right, total);
	}


	return total;
}



void Merge(int list[], int sort[], int i, int m, int n)
{
	int counter = 0;

	int j = m + 1, k = i, t;
	counter = counter + 2;

	
	while (i <= m && j <= n)
	{
		if (list[i] <= list[j]) {
			sort[k++] = list[i++];
			counter++;

		}

		else { sort[k++] = list[j++];
		counter++;
		}
	}
	if (i > m) {
		for (t = j; t <= n; ++t) {


			sort[k + t - j] = list[t];
			counter++;
		}
	}
	else {
		for (t = j; t <= n; ++t) {
			sort[k + t - i] = list[t];
			counter++;
		}
	}
	cout << "A total of " << counter << " operations were made using Merge sort" << endl;
}






void adjust(int tree[], int root, int n, int counter)
{
	int e = tree[root];
	int k = e;
	counter = counter + 2;
	for (int j = 2 * root; j <= n; j *= 2)
	{
		if (j < n) {
			if (tree[j] < tree[j + 1])
				j++;
			counter++;
		}

		if (k >= tree[j]) {
			break;
		}

		tree[j / 2] = tree[j];
		counter++;
		
	}
	tree[n / 2] = e;
	counter++;
}





void HeapSort(int list[], int n, int counter)
{
	int i;
	counter++;

	for (i = n / 2; i >= 1; i--) {
		adjust(list, i, n, counter);
	}
	for (i = n - 1; i >= 1; i--)
	{
		int t = list[i + 1];
		list[i + 1] = list[1];
		list[1] = t;

		counter = counter + 3;
		adjust(list, 1, i, counter);
	}

	cout << "The number of operations done using Heapsort is: " << counter << endl;
}









void insertionSort(int a[], int N)
{
	int temp;
	int j;
	int counter = 0;

	for (int p = 1; p < N; p++)
	{
		temp = a[p];
		for (j = p; j > 0 and a[j - 1] > temp; j--) {
			a[j] = a[j - 1];
			counter = counter + 1;  // each time this executes 1 assignment is made
		}
		a[j] = temp;
		counter = counter + 1; // each time this for loop executes a step is made
		
		
	}

	cout << "A total of " << counter << " operations were made using insertion sort" << endl;
}














void printlist(int array[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << array[i] << " ";
	cout << endl;
}



int main() {
	int decision = 0;

	int* array;
		int size;

		cout << "How many elements do you want in your array?" << endl;
		cin >> size;

		array = new int[size];

		for (int i = 0; i < size; i++) {

			cout << "Element " << i + 1 << " is: " << endl;
			cin >> array[i];

		}

	while (decision != 5) {

		cout << "Enter the number for your choice" << endl;
		cout << "1: Insertion Sort" << endl;
		cout << "2: Heap Sort" << endl;
		cout << "3: Merge Sort" << endl;
		cout << "4: Quicksort" << endl;
		cout << "5: Exit program" << endl;
		cin >> decision;

		if (decision == 1) {
			insertionSort(array, size);
			printlist(array, size);

		}
		if (decision == 2) {
			HeapSort(array, size-1,0);
			printlist(array, size);

		}
		if (decision == 3) {
			int* sort;
			sort = new int[size];

			Merge(array, sort, 0, size / 2, size-1);
			printlist(array, size);


		}
		if (decision == 4) {
			int counter = 0;
			counter=quicksort(array, 0, size - 1,0); 
			printlist(array, size);
			cout << "A total of " << counter << " operations were made using Quick sort" << endl;

		}
		if (decision == 5) {


			system("PAUSE");
			return 0;
	
		}
		}





}