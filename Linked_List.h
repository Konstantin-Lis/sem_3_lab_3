#pragma once
#include <stdexcept>
#include <exception>
#include <iostream>

//const char * IndexOutOfRange = "Index out of range";

template <class T>
class LinkedList {

private:
	struct Node
	{
		T values = 0;
		Node* next = nullptr;
	};

	Node* head = nullptr;
	int size = 0;

public:
	const char* IndexOutOfRange = "Index out of range";

	//������������
	LinkedList() : size(0), head(nullptr)
	{};

	LinkedList(const T* values, const int size) : LinkedList()
	{
		if (size < 0) throw std::length_error("Index is negative");
		if (size == 0) throw std::length_error("Node is empty");

		//��� ����� ����
		//Node* tail = new Node{ *values,nullptr };
		//head = tail;

		head = new Node{ *values,nullptr };

		for (size_t i = 1; i < size; i++) {
			//��� ����� ����
			//Node* body = new Node{ *(values + i),head };
			//tail->next = body;
			//head = body;

			head = new Node{ *(values + i),head };
		}

		this->size = size;
	}

	//���������� �����������
	LinkedList(LinkedList <T> const& list) {
		Node* body{ head };
		Node* List{ body };

		for (size_t i = 1; i < size; i++, body = body->next) {
			List = new Node{ body->values,List };
		}

		this->size = size;
	}

	LinkedList(LinkedList<T>* list)
	{
		this->list = list;
		this->size = list->GetLength();
	}

	//����������
	~LinkedList() {
		while (this->head != nullptr) {
			Node* body{ head->next };
			delete[] head;
			this->head = body;
		}

		delete[] this->head;
	}

	//����� ������� �������� ������
	T GetFirst() {
		if (size == 0) throw std::length_error(IndexOutOfRange);

		return head->values;
	}

	//����� ���������� �������� ������
	T GetLast() {
		if (size == 0) throw std::length_error(IndexOutOfRange);
		Node* body{ head };

		for (size_t i = 0; i < size - 1; i++) body = body->next;
		//std::cout << body->values;

		return body->values;
	}

	//��������� �������� �� �������
	T Get(int index) {
		if (index < 0 || index >= size) throw std::length_error(IndexOutOfRange);
		Node* body{ head };

		for (size_t i = 0; i < index; i++) body = body->next;
		return body->values;
	}

	T& operator [] (int index) {
		if (index < 0 || index >= size) throw std::length_error(IndexOutOfRange);
		Node* body{ head };

		for (size_t i = 0; i < index; i++) body = body->next;

		return body->values;
	}

	//�������� ������ ���� ���������
	LinkedList<T>* GetSubList(int startIndex, int endIndex) {
		if (startIndex < 0 || endIndex < 0 || startIndex >= size || endIndex >= size || startIndex > endIndex)
			throw std::length_error(IndexOutOfRange);
		Node* body{ head };

		for (size_t i = 0; i < startIndex; i++) body = body->next;

		LinkedList<T>* newNode = new LinkedList<T>;

		for (size_t i = startIndex; i < endIndex + 1; i++) {
			newNode->Prepend(body->values);
			body = body->next;
		}

		newNode->size = endIndex - startIndex + 1;

		return newNode;
	}

	//����� ������
	int GetLength() {
		return size;
	}

	//���������� �������� � ������ ������
	void Append(T data) {
		head = new Node{ data,head };

		++size;
	}

	//���������� �������� � ����� ������
	void Prepend(T data) {
		if (head == nullptr)  head = new Node{ data,head };
		else {
			Node* body{ head };
			for (size_t i = 1; i < size; i++) body = body->next;
			body->next = new Node{ data,nullptr };
		}

		++size;
	}

	//��������� ������� � �������� �������
	void InsertAt(T data, int index) {
		if (index < 0 || index >= size) throw std::length_error(IndexOutOfRange);
		Node* body{ head };

		if (index == 0) {
			body->values = data;
		}
		else {
			for (size_t i = 0; i < index - 1; i++) body = body->next;

			Node* newNode = new Node{ data,(body->next)->next };
			body->next = newNode;
		}
	}

	//��������� ���� �������
	LinkedList<T>* Concat(LinkedList<T>* list) {
		Node* body{ this->head };
		LinkedList<T>* newList = new LinkedList<T>();

		for (int i = 0; i < this->size; i++) {
			newList->Prepend(body->values);
			body = body->next;
		}

		Node* body2{ list->head };
		for (int i = this->size; i < (list->size + this->size); i++) {
			newList->Prepend(body2->values);
			body2 = body2->next;
		}

		newList->size = this->size + list->size;

		return newList;
	}

	//����� ������
	void Print() {
		for (int i = 0; i < size; i++) {
			std::cout << Get(i) << " ";
		};
		std::cout << "\n";
	}

	bool Empty(){
		if (this->size != 0) return true;
		else return false;
	}

	//���� ������
	void EnterList() {
		std::cout << "Enter size of the List: ";
		int count;
		std::cin >> count;

		for (int i = 0; i < count; i++) {
			T data;
			std::cout << "Element " << i << " : ";
			std::cin >> data;
			Prepend(data);
		}

	}

	void DeleteFirst(){
		Node* body{ head->next };
		delete[] head;
		this->head = body;
		--size;
	}
};