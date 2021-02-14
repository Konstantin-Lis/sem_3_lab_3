#pragma once
#include "Linked_List.h"
#include "Sequence.h"


template <class T>
class LinkedListSequence : public Sequence<T> {
protected:
	LinkedList<T>* linked_list;

public:
	const char* IndexOutOfRange = "Index out of range";

	LinkedListSequence() : Sequence<T>() {
		linked_list = new LinkedList<T>();
	}

	LinkedListSequence(T* values, int size) : Sequence<T>() {
		linked_list = new LinkedList<T>(values, size);
	}

	LinkedListSequence(int count) : Sequence<T>()
	{
		linked_list = new LinkedList<T>(count);
	}

	virtual ~LinkedListSequence() = default;

	virtual T GetFirst() const override {
		if (linked_list->GetLength() == 0) throw std::out_of_range(IndexOutOfRange);

		return linked_list->GetFirst();
	}

	virtual T GetLast() const override {
		if (linked_list->GetLength() == 0) throw std::out_of_range(IndexOutOfRange);

		return linked_list->GetLast();
	}

	virtual int GetLength()const {
		return linked_list->GetLength();
	}

	virtual T Get(int index) const override {
		if (index < 0 || index >= linked_list->GetLength()) throw std::out_of_range(IndexOutOfRange);

		return linked_list->Get(index);
	}

	virtual T& operator [](int index) const {
		return  linked_list->operator[](index);
	}

	virtual Sequence<T>* GetSubSequence(int startIndex, int endIndex) const override {
		if (startIndex < 0 || endIndex < 0 || startIndex >= linked_list->GetLength() || endIndex >= linked_list->GetLength())
			throw std::out_of_range(IndexOutOfRange);

		LinkedList<T>* subList = linked_list->GetSubList(startIndex, endIndex);
		Sequence<T>* subSequence = new LinkedListSequence<T>();

		for (int i = 0; i < subList->GetLength(); i++)
			subSequence->Prepend(subList->Get(i));

		return subSequence;
	}

	virtual LinkedListSequence<T>* Concat(Sequence<T>* linked_list2) const  override {
		LinkedListSequence<T>* ConcatSequence = new LinkedListSequence<T>();

		for (int i = 0; i < linked_list->GetLength(); i++)
			ConcatSequence->Prepend(linked_list->Get(i));

		for (int i = 0; i < linked_list2->GetLength(); i++)
			ConcatSequence->Prepend(linked_list2->Get(i));

		return ConcatSequence;
	}

	virtual void Append(T values) override {
		return linked_list->Append(values);
	}

	virtual void Prepend(T values) override {
		return linked_list->Prepend(values);
	}

	virtual void InsertAt(T values, int index) {
		if (index < 0 || index >= linked_list->GetLength()) throw std::out_of_range(IndexOutOfRange);

		return linked_list->InsertAt(values, index);
	}

	bool Empty(){
		return linked_list->Empty();
	}

	virtual void Print() override {
		return linked_list->Print();
	}

	/*
	virtual void Enter() override {
		return linked_list->EnterList();
	} */

	/*
	void Enter() {
		std::cout << "Enter size of the sequence: ";
		int count;
		std::cin >> count;

		for (int i = 0; i < count; i++) {
			T data;
			std::cout << "Element " << i << " : ";
			std::cin >> data;
			Prepend(data);
		}

	} */

	void Copy(Sequence<T>* linked_list) {
		for (int i = 0; i < linked_list->GetLength(); i++)
			InsertAt(linked_list->Get(i), i);
	}

	void DeleteFirst()
	{
		linked_list->DeleteFirst();
	}
};