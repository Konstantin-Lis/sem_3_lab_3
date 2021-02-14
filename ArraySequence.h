#pragma once
#include "DynamicArray.h"
#include "Sequence.h"

template <class T>
class ArraySequence : public Sequence<T> {
protected:
	DynamicArray<T>* mas = 0;
	int size = 0;

public:
	const char* IndexOutOfRange = "Index out of range";
	ArraySequence() : Sequence<T>() {
		mas = new DynamicArray<T>(0);
		this->size = 0;
	}

	ArraySequence(int size) : Sequence<T>() {
		mas = new DynamicArray<T>(size);
		this->size = size;
	}

	ArraySequence(T* values, int size) :Sequence<T>() {
		mas = new DynamicArray<T>(values, size);
		this->size = size;
	}

	virtual T& operator [](int index) const {
		return  mas->operator[](index);
	}

	virtual ~ArraySequence() = default;

	virtual T GetFirst() const override {
		if (this->size == 0)
			throw std::out_of_range(IndexOutOfRange);

		return mas->Get(0);
	}

	virtual T Get(int index) const override {
		if (index < 0 || index >= size)
			throw std::out_of_range(IndexOutOfRange);

		return mas->Get(index);
	}

	virtual int GetLength() const override {
		return size;
	}

	virtual T GetLast() const override {
		return mas->Get(this->size - 1);
	}

	virtual void Prepend(T values) override {
		mas->Resize(size + 1);
		size = size + 1;
		mas->Set(size - 1, values);
	}

	virtual void Append(T values) override {
		mas->Resize(size + 1);
		T data1 = mas->Get(0);
		T data2 = 0;

		for (int i = 0; i < this->size; i++) {
			data2 = data1;
			data1 = mas->Get(i + 1);
			mas->Set(i + 1, data2);
		}

		mas->Set(0, values);
	}

	virtual void InsertAt(T values, int index) override {
		if (index < 0 || index >= size) throw std::out_of_range(IndexOutOfRange);

		mas->Set(index, values);
	}

	virtual Sequence<T>* GetSubSequence(int startIndex, int endIndex) const override {
		if (startIndex < 0 || startIndex >= size || endIndex < 0 || endIndex >= size) throw std::out_of_range(IndexOutOfRange);

		Sequence<T>* GetSubSequence = new ArraySequence();
		for (int i = 0; i < (endIndex - startIndex + 1); i++)
			GetSubSequence->Prepend(mas->Get(startIndex + i));

		return GetSubSequence;
	}

	virtual ArraySequence <T>* Concat(Sequence<T>* mas2) const override {
		ArraySequence <T>* newmas = new ArraySequence();

		for (int i = 0; i < this->size; i++)
			newmas->Prepend(mas->Get(i));

		for (int i = 0; i < mas2->GetLength(); i++)
			newmas->Prepend(mas2->Get(i));

		return newmas;
	}

	virtual void Print() override {
		mas->Print();
	}

	void Copy(Sequence<T>* mas) {
		for (int i = 0; i < mas->GetLength(); i++)
			InsertAt(mas->Get(i), i);
	}

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

	}
	*/

};