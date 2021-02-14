#pragma once
#include "ArraySequence.h"
#include "List_Sequence.h"

//���� �� ������� ���������
template <typename T>
class Graph : public LinkedListSequence<T>
{
private:
	LinkedListSequence<T>** graph = nullptr;
	int count;
public:
	Graph(int count){
		graph = new LinkedListSequence<T>* [count];
		for (int i=0; i < count; i++) 
			graph[i] = new LinkedListSequence<T>;

		this->count = count;
	}

	//������ � ���������
	Graph(int count, T* vertex){
		graph = new LinkedListSequence<T>* [count];
		for (int i=0; i < count; i++){
			graph[i] = new LinkedListSequence<T>;
			graph[i]->Append(vertex[i]);
		}
		this->count = count;
	}

	~Graph(){
		for (int i=0; i < count; i++){
			delete graph[i];
			graph[i] = nullptr;
		}

		delete graph;
		//graph = nullptr;
	}

	//������� ������ ������� ������
	LinkedListSequence<T>* GetGraph(int vertex){
		int i=0;

		while (graph[i]->GetFirst() != vertex)
			i++;
		return graph[i];
	}

	//���������� ������
	int GetCount(){
		return this->count;
	}

	//���������� ����  
	int GetCountPaths(){
		int num=0;
		for (int i=0; i < count; i++)
			num += graph[i]->GetLength();
		return (num - count)/2;
	}

	//�������� �� ��������� ���� ������
	bool CheckVert(T vertex1, T vertex2){
		int i(SearchVert(vertex1));
		bool check(false);

		if (i == -1)
			return false;

		for (int k=0; k < graph[i]->GetLength(); k++)
			if (graph[i]->Get(k) == vertex2)
				check = true;
		return check;
	}

	//��������� ������� ������� element � vertex
	void AddPath(T vertex, T element){
		for (int i = 0; i < count; i++)
			if (graph[i]->GetFirst() == vertex) 
				graph[i]->Prepend(element);
	}

	//��������� ��� ������� ������� � vertex
	void SetPaths(T vertex, T* paths, int size){
		for (int i=0; i < size; i++)
			AddPath(vertex, paths[i]);
	}

	//���������� ����� ������� � ����� (����� -1)
	int SearchVert(T vertex){
		int i=0;

		while (i < count ) {
			if (graph[i]->GetFirst() != vertex) ++i;
			else break;
		}

		if (i == count ) return -1;
		else return i;
	}

	//����� � ������ �� ���������� ������������ ���� ����� 2 ���������
	LinkedListSequence<int>* BFS(T vertFrom, T vertTo){
		
		//���������� ����

		int i=0,k=0,MAX=0;
		while (graph[i]->GetFirst() != vertFrom)
			i++;

		while (graph[k]->GetFirst() != vertTo)
			k++;

		// �������
		LinkedListSequence<T>* queue = new LinkedListSequence<T>;
		queue->Append(i);
		bool* used = new bool[count]; // ����� ��������� ������� ��� ���
		int* dist = new int[count];   // ������ ���������� ������ �� From
		int* pred = new int[count];   // ������������������� ������ � ������� �������� �� From � To
		//������, ������ ������

		// ��������� ������
		for (int j=0; j < count; j++){
			used[j] = false;
			dist[j] = MAX;
			pred[i] = -1;
		}

		used[i] = true;
		dist[i] = 0;

		while (queue->Empty()){
			int v = queue->GetFirst();
			queue->DeleteFirst();

			for (int i=1; i < graph[v]->GetLength(); ++i){
				int j=0;
				int el = graph[v]->Get(i);
				while (this->graph[j]->GetFirst() != el)
					j++;

				// �������� �������, � ������� ��� �� ����
				if (!used[j]){
					used[j] = true;
					queue->Append(j);
					dist[j] = dist[v] + 1;
					pred[j] = v;
				}
			}
		}

		//��������������� ����

		ArraySequence<int>* path = new ArraySequence<int>[count];

		//���� �� �����
		if (!used[k]){
			LinkedListSequence<int>* path1 = new LinkedListSequence<int>;
			path1->Append(-1);
			return path1;
		}

		int cur=k;
		path->Prepend(cur);

		while (pred[cur] != -1){ //���� �� ������ �� ������ ���� � �������� �������   
			cur = pred[cur];    
			path->Prepend(cur);
		}

		//��� �������� ������

		int size = path->GetLength();
		LinkedListSequence<int>* path1 = new LinkedListSequence<int>;
		for (int i=0; i < size ; i++)
			path1->Append(graph[path->Get(i)]->GetFirst());

		return path1;
	}
};
