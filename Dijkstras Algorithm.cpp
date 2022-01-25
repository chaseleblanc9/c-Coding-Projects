//Timothy LeBlanc
//Graph Program


#include <iostream>



#define INFINITY 7777


using namespace std;

class Dijkstras {

private:

	int adjMatrix[25][25];
	int pred[25];
	int length[25];
	bool known[25];
	int sourceVert;
	int totalVert;

public:

	void travel();
	void initialize();
	int getNearestNode();
	void route();
	void result();
	void display(int);



};

// initializes data members

void Dijkstras::initialize() {

	for (int i = 0; i < totalVert; i++) {
		known[i] = false;
		pred[i] = 1;
		length[i] = INFINITY;
	}
	length[sourceVert] = 0;

}


//calculates minimum dstance from source node to the others
void Dijkstras::route() {
	initialize();
	int minDist = INFINITY;
	int nearNode;
	int counter = 0;

	while (counter < totalVert) {
		nearNode = getNearestNode();
		known[nearNode] = true;


		for (int i = 0; i < totalVert; i++) {

			if ((adjMatrix[nearNode][i] > 0) && (!known[i])) {

				if (length[i] > length[nearNode] + adjMatrix[nearNode][i]) {




					length[i] = length[nearNode] + adjMatrix[nearNode][i];




					pred[i] = nearNode;

				}
			}

		}
		counter++;
	}
}

void Dijkstras::display(int vertex) {
	if (vertex == sourceVert) {
		cout << (char)(vertex + 97) << "_";
	}
	else if (pred[vertex] == -1) {
		cout << "Path does not exist" << endl;
	}
	else {
		display(pred[vertex]);
		cout << (char)(vertex + 97) << "_";

	}

}



//reads vertices, matrix, and source from user
void Dijkstras::travel() {
	cout << "Enter the number of vertices in the graph" << endl;
	cin >> totalVert;

	cout << endl << "Enter the adjacency matrix" << endl;
	cout << "Type " << INFINITY << " to represent infinity" << endl;

	for (int i = 0; i < totalVert; i++) {
		cout << "Enter weights for the row " << i+1 << endl;

		for (int j = 0; j < totalVert; j++) {
			cin >> adjMatrix[i][j];
		}

	}

	cout << "Enter Source Vertex" << endl;
	cin >> sourceVert;

	while ((sourceVert < 0) && (sourceVert > totalVert - 1)) {
		cout << " Enter the source vertex between 0-" << totalVert - 1 << endl;
		cin >> sourceVert;

	}
}


// returns the vertex
int Dijkstras::getNearestNode() {

	int minDist = INFINITY;
	int nearNode;

	for (int i = 0; i < totalVert; i++) {

		if ((minDist >= length[i]) && (!known[i])) {
			minDist = length[i];
			nearNode = i;

		}

	}
	return nearNode;
}


void Dijkstras::result() {
	for (int i = 0; i < totalVert; i++) {
		if (i == sourceVert){
			cout << (char)(sourceVert + 97) << "_" << sourceVert;}
		else {
			display(i);
		}
		cout << " PATH" << endl;
		cout << "---->" << length[i] << endl;
	}
}

int main() {

	Dijkstras graph;
	graph.travel();
	graph.route();
	graph.result();



	system("PAUSE");
	return 0;
}