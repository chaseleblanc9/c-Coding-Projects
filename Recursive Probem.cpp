//Timothy LeBlanc
//Recursive Problem

#include <iostream>
#include <cstdlib>

using namespace std;


int fun2(int n) {
	if (n == 2) {
		return 4;
	}
	else {
		return 3 * fun2(n - 1) - 2*n;
	}
}

//Code below is just used to make the recursive function work
int main() {

	int num;
	int answer;
	cout << " Enter a number to be evaluated by the function" << endl;
	cin >> num;
	answer = fun2(num);

	cout << "The answer using the number given is: "<< answer << endl;
	system("PAUSE");
	return 0;
}