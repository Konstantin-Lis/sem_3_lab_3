#pragma once
#include "ArraySequence.h"
#include "List_Sequence.h"
#include "Graph.h"
#include "Tests.h"
#include <string>
using namespace std;

void interface_Tests() {
	string choose1{ "0" };
	int choose(0);

	cout << "Choose the Test:\n"
		<< "1. Test_Array_Sequence \n2. Test_Dynamic_Array \n3. Test_Linked_list \n4. Test_List_Sequence \n5. Test_Graph \n";
	do {
		if (choose1 == "0") cin >> choose1;
		else if (choose1 != "1" && choose1 != "2" && choose1 != "3" && choose1 != "4" && choose1 != "5") {
			std::cout << "ERROR. You need choose a number from 1 to 5 \n";
			cin >> choose1;
		}
	} while (choose1 != "1" && choose1 != "2" && choose1 != "3" && choose1 != "4" && choose1 != "5");
	choose = stoi(choose1);
	cout << "\n";
	switch (choose) {
	case 1:
		Test_Array_Sequence();
		break;
	case 2:
		Test_Dynamic_Array();
		break;
	case 3:
		Test_Linked_list();
		break;
	case 4:
		Test_List_Sequence();
		break;
	case 5:
		Test_Graph();
		break;
	default: std::cout << "ERROR. You kill me.";
	}
	cout << "-----------------------------------\n";
}

int Test_Array_Sequence() {
	int* pr{ new int[5] {11,12,13,14,15} };
	ArraySequence<int> mas1(pr, 5);

	int* priv{ new int[3] {23,16,4} };
	ArraySequence<int> mas2(priv, 3);

	if (mas1[1] == 12 && mas1[4] == 15)
		std::cout << "Test Operator []: success" << "\n";
	else {
		std::cout << "Test Operator []: fail" << "\n";
	};

	if (mas1.GetFirst() == 11)
		std::cout << "Test GetFirst: success" << "\n";
	else {
		std::cout << "Test GetFirst: fail" << "\n";
	};

	if (mas1.GetLast() == 15)
		std::cout << "Test GetLast: success" << "\n";
	else {
		std::cout << "Test GetLast: fail" << "\n";
	};

	if (mas1.GetLength() == 5)
		std::cout << "Test GetSize: success" << "\n";
	else {
		std::cout << "Test GetSize: fail" << "\n";
	};

	if (mas1.Get(3) == 14)
		std::cout << "Test Get: success" << "\n";
	else {
		std::cout << "Test Get: fail" << "\n";
	};

	mas1.Append(76);
	if (mas1.GetFirst() == 76)
		std::cout << "Test Append: success" << "\n";
	else {
		std::cout << "Test Append: fail" << "\n";
	};

	mas1.Prepend(8);
	if (mas1.GetLast() == 8)
		std::cout << "Test Prepend: success" << "\n";
	else {
		std::cout << "Test Prepend: fail" << "\n";
	};


	mas1.GetSubSequence(2, 5);
	if (mas1[2] == 12 && mas1[3] == 13 && mas1[4] == 14 && mas1[5] == 8)
		std::cout << "Test GetSubSequence: success" << "\n";
	else {
		std::cout << "Test GetSubSequence: fail" << "\n";
	};


	int data = 44;
	mas1.InsertAt(data, 4);
	if (mas1[4] == 44)
		std::cout << "Test InsertAt: success" << "\n";
	else {
		std::cout << "Test InsertAt: fail" << "\n";
	};

	ArraySequence<int>* p2 = mas1.Concat(&mas2);
	if (p2->Get(0) == 76 && p2->Get(1) == 11 && p2->Get(2) == 12 && p2->Get(3) == 13
		&& p2->Get(4) == 44 && p2->Get(5) == 8 && p2->Get(6) == 23 && p2->Get(7) == 16
		&& p2->Get(8) == 4)
		std::cout << "Test Concat: success" << "\n";
	else {
		std::cout << "Test Concat: fail" << "\n";
	};


	DynamicArray<int> mas3(2);
	if (mas3[0] == -842150451 && mas3[1] == -842150451)
		std::cout << "Test Creation constructor: success" << "\n";
	else {
		std::cout << "Test Creation constructor: fail" << "\n";
	};
	//-842150451

	delete[7] pr;
	delete[3] priv;

	return 0;
}

int Test_Dynamic_Array() {
	int* pr{ new int[5] {11,12,13,14,15} };
	DynamicArray<int> mas1(pr, 5);

	if (mas1[1] == 12 && mas1[4] == 15)
		std::cout << "Test Operator []: success" << "\n";
	else {
		std::cout << "Test Operator []: fail" << "\n";
	};

	if (mas1.GetLength() == 5)
		std::cout << "Test GetSize: success" << "\n";
	else {
		std::cout << "Test GetSize: fail" << "\n";
	};

	if (mas1.Get(3) == 14)
		std::cout << "Test Get: success" << "\n";
	else {
		std::cout << "Test Get: fail" << "\n";
	};

	mas1.Resize(7);
	if (mas1.GetLength() == 7)
		std::cout << "Test Resize: success" << "\n";
	else {
		std::cout << "Test Resize: fail" << "\n";
	};

	int data = 44;
	mas1.Set(5, data);
	if (mas1[5] == 44)
		std::cout << "Test Set: success" << "\n";
	else {
		std::cout << "Test Set: fail" << "\n";
	};

	DynamicArray<int> mas2(2);
	if (mas2[0] == -842150451 && mas2[1] == -842150451)
		std::cout << "Test Creation constructor: success" << "\n";
	else {
		std::cout << "Test Creation constructor: fail" << "\n";
	};
	//-842150451

	delete[5] pr;

	return 0;
}

int Test_Linked_list() {
	int* a{ new int[6] {1,4,5,7,4,17} };
	int* b{ new int[5] {5,11,8,9,2} };

	LinkedList<int> list1{ a,6 };
	LinkedList<int> list2{ b,5 };
	LinkedList<int> list3;

	if (list1.GetFirst() == 17)
		std::cout << "Test GetFirst: success" << "\n";
	else {
		std::cout << "Test GetFirst: fail" << "\n";
	};

	if (list1.GetLast() == 1)
		std::cout << "Test GetLast: success" << "\n";
	else {
		std::cout << "Test GetLast: fail" << "\n";
	};

	if (list1[2] == 7 && list1[5] == 1)
		std::cout << "Test Operator []: success" << "\n";
	else {
		std::cout << "Test Operator []: fail" << "\n";
	};

	if (list1.GetLength() == 6)
		std::cout << "Test GetLenght: success" << "\n";
	else {
		std::cout << "Test GetLenght: fail" << "\n";
	};

	if (list1.Get(3) == 5)
		std::cout << "Test Get: success" << "\n";
	else {
		std::cout << "Test Get: fail" << "\n";
	};

	list1.Append(5);
	if (list1[0] == 5)
		std::cout << "Test Append: success" << "\n";
	else {
		std::cout << "Test Append: fail" << "\n";
	};

	list2.Prepend(9);
	if (list2[5] == 9)
		std::cout << "Test Prepend: success" << "\n";
	else {
		std::cout << "Test Prepend: fail" << "\n";
	};

	LinkedList<int>* p = list2.GetSubList(1, 4);
	if (p->Get(0) == 9 && p->Get(1) == 8 && p->Get(2) == 11 && p->Get(3) == 5)
		std::cout << "Test GetSubList: success" << "\n";
	else {
		std::cout << "Test GetSubList: fail" << "\n";
	};

	bool empty1 = list2.Empty();
	bool empty2 = list3.Empty();
	if (empty1 == true && empty2 == false)
		std::cout << "Test Empty: success" << "\n";
	else {
		std::cout << "Test Empty: fail" << "\n";
	};

	list2.InsertAt(3, 2);
	if (list2[2] == 3)
		std::cout << "Test InsertAt: success" << "\n";
	else {
		std::cout << "Test InsertAt: fail" << "\n";
	};

	LinkedList<int>* p2 = list1.Concat(&list2);
	if (p2->Get(0) == 2 && p2->Get(1) == 9 && p2->Get(2) == 3 && p2->Get(3) == 8
		&& p2->Get(4) == 11 && p2->Get(5) == 5 && p2->Get(6) == 9 && p2->Get(7) == 5
		&& p2->Get(8) == 17 && p2->Get(9) == 4 && p2->Get(10) == 7 && p2->Get(11) == 5
		&& p2->Get(12) == 4 && p2->Get(13) == 1)
		std::cout << "Test Concat: success" << "\n";
	else {
		std::cout << "Test Concat: fail" << "\n";
	};

	list2.DeleteFirst();
	if (list2[0] == 9)
		std::cout << "Test DeleteFirst: success" << "\n";
	else {
		std::cout << "Test DeleteFirst: fail" << "\n";
	};

	delete[7] a;
	delete[6] b;

	return 0;
}

int Test_List_Sequence() {
	int* a{ new int[6] {1,4,5,7,4,17} };
	LinkedListSequence<int> list1{ a,6 };

	int* b{ new int[5] {5,11,8,9,2} };
	LinkedListSequence<int> list2{ b,5 };

	LinkedListSequence<int> list3;

	if (list1.GetFirst() == 17)
		std::cout << "Test GetFirst: success" << "\n";
	else {
		std::cout << "Test GetFirst: fail" << "\n";
	};

	if (list1.GetLast() == 1)
		std::cout << "Test GetLast: success" << "\n";
	else {
		std::cout << "Test GetLast: fail" << "\n";
	};

	if (list1[2] == 7 && list1[5] == 1)
		std::cout << "Test Operator []: success" << "\n";
	else {
		std::cout << "Test Operator []: fail" << "\n";
	};

	if (list1.GetLength() == 6)
		std::cout << "Test GetLenght: success" << "\n";
	else {
		std::cout << "Test GetLenght: fail" << "\n";
	};

	if (list1.Get(3) == 5)
		std::cout << "Test Get: success" << "\n";
	else {
		std::cout << "Test Get: fail" << "\n";
	};

	list1.Append(5);
	if (list1.Get(0) == 5)
		std::cout << "Test Append: success" << "\n";
	else {
		std::cout << "Test Append: fail" << "\n";
	};

	list2.Prepend(9);
	if (list2.Get(5) == 9)
		std::cout << "Test Prepend: success" << "\n";
	else {
		std::cout << "Test Prepend: fail" << "\n";
	};

	Sequence<int>* p = list2.GetSubSequence(1, 4);
	if (p->Get(0) == 9 && p->Get(1) == 8 && p->Get(2) == 11 && p->Get(3) == 5)
		std::cout << "Test GetSubList: success" << "\n";
	else {
		std::cout << "Test GetSubList: fail" << "\n";
	};

	bool empty1 = list2.Empty();
	bool empty2 = list3.Empty();
	if (empty1 == true && empty2 == false)
		std::cout << "Test Empty: success" << "\n";
	else {
		std::cout << "Test Empty: fail" << "\n";
	};

	list2.InsertAt(3, 2);
	if (list2.Get(2) == 3)
		std::cout << "Test InsertAt: success" << "\n";
	else {
		std::cout << "Test InsertAt: fail" << "\n";
	};

	LinkedListSequence<int>* p2 = list1.Concat(&list2);
	if (p2->Get(0) == 5 && p2->Get(1) == 1 && p2->Get(2) == 4 && p2->Get(3) == 5
		&& p2->Get(4) == 7 && p2->Get(5) == 4 && p2->Get(6) == 17 && p2->Get(7) == 5
		&& p2->Get(8) == 11 && p2->Get(9) == 3 && p2->Get(10) == 8 && p2->Get(11) == 9
		&& p2->Get(12) == 2 && p2->Get(13) == 9)
		std::cout << "Test Concat: success" << "\n";
	else {
		std::cout << "Test Concat: fail" << "\n";
	};

	list2.DeleteFirst();
	if (list2[0] == 9)
		std::cout << "Test DeleteFirst: success" << "\n";
	else {
		std::cout << "Test DeleteFirst: fail" << "\n";
	};

	delete[7] a;
	delete[6] b;

	return 0;
}

int Test_Graph() {

	int* vertex = new int[5];
	vertex[0] = 0;
	vertex[1] = 1;
	vertex[1] = 1;
	vertex[1] = 1;
	vertex[2] = 2;
	vertex[2] = 2;
	vertex[3] = 3;
	vertex[3] = 3;
	vertex[4] = 4;

	Graph<int> graph1(5, vertex);
	graph1.AddPath(vertex[0], 1);
	graph1.AddPath(vertex[1], 0);
	graph1.AddPath(vertex[1], 2);
	graph1.AddPath(vertex[1], 3);
	graph1.AddPath(vertex[2], 1);
	graph1.AddPath(vertex[2], 3);
	graph1.AddPath(vertex[3], 2);
	graph1.AddPath(vertex[3], 1);
	graph1.AddPath(vertex[4], 4);

	/*
	cout << "The adjacency list of a graph: \n"
		<< "Vertex: Paths \n";
	for (int i = 0; i < graph1.GetCount(); i++) {
		cout << " " << vertex[i] << ": ";
		graph1.GetGraph(vertex[i])->Print();
	} 
	*/

	LinkedListSequence<int>* list1 = graph1.GetGraph(2);
	if (list1->Get(0)==2, list1->Get(1) == 1, list1->Get(2) == 3)
		std::cout << "Test GetGraph: success" << "\n";
	else {
		std::cout << "Test GetGraph: fail" << "\n";
	};


	if (graph1.GetCount() == 5)
		std::cout << "Test GetCount: success" << "\n";
	else {
		std::cout << "Test GetCount: fail" << "\n";
	};

	if (graph1.GetCountPaths() == 4)
		std::cout << "Test GetCountPaths: success" << "\n";
	else {
		std::cout << "Test GetCountPaths: fail" << "\n";
	};
	
	if (graph1.CheckVert(0,1) == true && graph1.CheckVert(0, 2) == false)
		std::cout << "Test CheckVert: success" << "\n";
	else {
		std::cout << "Test CheckVert: fail" << "\n";
	};

	graph1.AddPath(3, 4);
	graph1.AddPath(4, 3);
	if (graph1.CheckVert(3, 4) == true)
		std::cout << "Test AddPath: success" << "\n";
	else {
		std::cout << "Test AddPath: fail" << "\n";
	};
	
	int* path = new int[3];
	path[0] = 2;
	path[1] = 1;
	path[2] = 3;
	graph1.SetPaths(0, path, 3);
	if (graph1.CheckVert(0, 2) == true && graph1.CheckVert(0, 3) == true)
		std::cout << "Test SetPaths: success" << "\n";
	else {
		std::cout << "Test SetPaths: fail" << "\n";
	};
	graph1.AddPath(2, 0);
	graph1.AddPath(3, 0);

	if (graph1.SearchVert(4) == 4 && graph1.SearchVert(6) == -1)
		std::cout << "Test SearchVert: success" << "\n";
	else {
		std::cout << "Test SearchVert: fail" << "\n";
	};

	LinkedListSequence<int>* list2 = graph1.BFS(1, 4);
	if (list2->Get(0) == 1 && list2->Get(1) == 3 && list2->Get(2) == 4)
		std::cout << "Test BFS: success" << "\n";
	else {
		std::cout << "Test BFS: fail" << "\n";
	};


	return 0;
}



