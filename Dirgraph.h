#pragma once
#include "sequence.h"
#include "matrix.h"

using namespace std;

template <class T>
class DirGraph
{
protected:
    Matrix<T>* adjMatrix;
private:

    void _ts_(int v, bool visited[], ArraySequence<int>* stack)
    {
        visited[v] = true;
        for (int i = 0; i < this->GetSize(); i++)
            if ((this->adjMatrix->Get(v, i) != 0) && (!visited[i]))
                this->_ts_(i, visited, stack);
        stack->Prepend(v);
    }

public:

    DirGraph(int size)
    {
        this->adjMatrix = new Matrix<T>(size, size);
    }

    ~DirGraph() = default;

    void ChangeEdge(int vert1, int vert2, T weight)
    {
        if (vert1 == vert2)
            throw out_of_range("INCORRECT INDEX");
        this->adjMatrix->Set(weight, vert1, vert2);
    }

    int GetSize()
    {
        return this->adjMatrix->GetRows();
    }

    string AdjMatr()
    {
        return this->adjMatrix->ToString();
    }

    ArraySequence<int>* GetPath(int vert1, int vert2)
    {
        const int INF = INT_MAX;
        ArraySequence<int> dist(this->GetSize());
        ArraySequence<bool> beenTo(this->GetSize());
        ArraySequence<int> parent(this->GetSize());

        for (int i = 0; i < this->GetSize(); i++)
        {
            dist.Set(INF, i);
            beenTo.Set(false, i);
            parent.Set(-1, i);
        }

        int min = 0;
        int index_min = 0;
        int temp = 0;
        dist.Set(0, vert1);

        for (int i = 0; i < this->GetSize(); i++)
        {
            min = INF;
            for (int j = 0; j < this->GetSize(); j++)
                if (!beenTo.Get(j) && dist.Get(j) < min)
                {
                    min = dist.Get(j);
                    index_min = j;
                }
            beenTo.Set(true, index_min);
            for (int j = 0; j < this->GetSize(); j++)
                if (adjMatrix->Get(index_min, j) > 0)
                {
                    temp = min + adjMatrix->Get(index_min, j);
                    if (temp < dist.Get(j))
                    {
                        dist.Set(temp, j);
                        parent.Set(index_min, j);
                    }
                }
            if (beenTo.Get(vert2) == true) break;
        }

        ArraySequence<int>* path = new ArraySequence<int>(0);
        if (parent.Get(vert2) == -1)
        {
            path->Append(-1);
            return path;
        }
        for (int i = vert2; i != -1; i = parent.Get(i))
            path->Prepend(i);
        return path;
    }

    T GetPathWeight(ArraySequence<int>* path)
    {
        if (path->Get(0) == -1)
            throw invalid_argument("ERROR:WHERE'S NO PATH BETWEEN VERTEXES");
        T result = 0;
        for (int i = 0; i < path->GetSize() - 1; i++)
        {
            if (this->adjMatrix->Get(path->Get(i), path->Get(i + 1)) == 0)
                throw invalid_argument("ERROR:WHERE'S NO PATH BETWEEN VERTEXES");
            result += this->adjMatrix->Get(path->Get(i), path->Get(i + 1));
        }
        return result;
    }

    ArraySequence<int>* GetTopologicalSort()
    {
        ArraySequence<int>* stack;
        stack = new ArraySequence<int>();
        bool* visited = new bool[this->GetSize()];

        for (int i = 0; i < this->GetSize(); i++)
            visited[i] = false;

        for (int i = 0; i < this->GetSize(); i++)
            if (visited[i] == false)
                this->_ts_(i, visited, stack);
        return stack;
    }
};