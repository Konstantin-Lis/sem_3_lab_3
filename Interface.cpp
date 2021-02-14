#include <iostream>
#include "Graph.h"
#include "Tests.h"
using namespace std;

int interface() {
	int choice =0;
	cout << "///////////////GRAPH///////////////\n";
	bool exit = false;

	while (!exit){
		int size=0;
		cout << "Enter the count of vertexes: \n";
		cin >> size;

		int* vertex = new int[size];
		cout << "Set the vertexes: \n";
		for (int i = 0; i < size; i++) {
			cout << " Vertex" << i <<" : ";
			cin >> vertex[i];
		}

		Graph<int> graph(size, vertex);
		ArraySequence<int> paths;

		cout << "\nWrite the Adjacency List for each vertex \n"; 
		for (int i=0; i < size; i++){
			int quantity = 0;
			int a = 0;

			cout << "Vertex " << vertex[i] << ": \n   Quantity: ";
			cin >> quantity;
			cout << "   Connected with: \n";

			for (int k=0; k < quantity; k++){
				cout << "   ";
				cin >> a;
				graph.AddPath(vertex[i], a);
			}
			cout << "\n";
		}


		//вывод списка смежности
		cout << "The adjacency list of a graph: \n"
			 << "Vertex: Paths \n";
		for (int i = 0; i < graph.GetCount(); i++) {
			cout << " " << vertex[i] << ": ";
			graph.GetGraph(vertex[i])->Print();
		}

		bool exit1 = false;
		while (!exit1){
			int a=0;
			int b=0;
			cout << "\nWrite the vertexes to finding the shortest path: \n"
				<< " From: ";
			cin >> a;
			cout <<" To:   ";
			cin >> b;

			LinkedListSequence<int>* path = graph.BFS(a, b);

			for (int i=0; i < path->GetLength(); i++){
				if (i != path->GetLength() - 1)
					cout << path->Get(i)  << " -> ";
				else
					cout << path->Get(i)  << "\n";
			}

			cout << "Choose the option: \n"
				<< "1. Find another path \n" 
				<< "2. Change the graph \n" 
				<< "3. Exit \n";

			cin >> choice;
			if (choice == 1)
				exit1 = false;

			if (choice == 2)
				exit1 = true;

			if (choice == 3){
				exit = true;
				exit1 = true;
			}
		}
	}

	cout << "\n Good job.";

	return 0;
}


int main() {

	interface();
	//interface_Tests();

	return 0;
}
