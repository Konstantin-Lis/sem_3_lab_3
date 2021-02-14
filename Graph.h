#pragma once
#include "ArraySequence.h"
#include "List_Sequence.h"

//граф по таблице смежности
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

	//массив с вершинами
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

	//возврат списка смежных вершин
	LinkedListSequence<T>* GetGraph(int vertex){
		int i=0;

		while (graph[i]->GetFirst() != vertex)
			i++;
		return graph[i];
	}

	//количество вершин
	int GetCount(){
		return this->count;
	}

	//количество рёбер  
	int GetCountPaths(){
		int num=0;
		for (int i=0; i < count; i++)
			num += graph[i]->GetLength();
		return (num - count)/2;
	}

	//проверка на смежность двух вершин
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

	//добавляет смежную вершину element к vertex
	void AddPath(T vertex, T element){
		for (int i = 0; i < count; i++)
			if (graph[i]->GetFirst() == vertex) 
				graph[i]->Prepend(element);
	}

	//добавляет все смежные вершины к vertex
	void SetPaths(T vertex, T* paths, int size){
		for (int i=0; i < size; i++)
			AddPath(vertex, paths[i]);
	}

	//возвращает номер вершины в графе (иначе -1)
	int SearchVert(T vertex){
		int i=0;

		while (i < count ) {
			if (graph[i]->GetFirst() != vertex) ++i;
			else break;
		}

		if (i == count ) return -1;
		else return i;
	}

	//поиск в ширину по нахождению минимального пути между 2 вершинами
	LinkedListSequence<int>* BFS(T vertFrom, T vertTo){
		
		//нахождение пути

		int i=0,k=0,MAX=0;
		while (graph[i]->GetFirst() != vertFrom)
			i++;

		while (graph[k]->GetFirst() != vertTo)
			k++;

		// очередь
		LinkedListSequence<T>* queue = new LinkedListSequence<T>;
		queue->Append(i);
		bool* used = new bool[count]; // метка проходили вершину или нет
		int* dist = new int[count];   // список расстояний вершин до From
		int* pred = new int[count];   // посследовательность вершин в которые заходили от From к To
		//номера, откуда пришли

		// начальные данные
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

				// отмечаем веришны, в которых еще не были
				if (!used[j]){
					used[j] = true;
					queue->Append(j);
					dist[j] = dist[v] + 1;
					pred[j] = v;
				}
			}
		}

		//восстанавливаем путь

		ArraySequence<int>* path = new ArraySequence<int>[count];

		//если не дошли
		if (!used[k]){
			LinkedListSequence<int>* path1 = new LinkedListSequence<int>;
			path1->Append(-1);
			return path1;
		}

		int cur=k;
		path->Prepend(cur);

		while (pred[cur] != -1){ //пока не дойдем до старта идем в обратном порядке   
			cur = pred[cur];    
			path->Prepend(cur);
		}

		//для удобного вывода

		int size = path->GetLength();
		LinkedListSequence<int>* path1 = new LinkedListSequence<int>;
		for (int i=0; i < size ; i++)
			path1->Append(graph[path->Get(i)]->GetFirst());

		return path1;
	}
};
