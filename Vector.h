#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Vector {
private:
	T* vec;
	size_t currSize;
	size_t capacity;

	void resize() {
		capacity *= 2;
		T* buffer = new T[capacity];
		for (int i = 0; i < currSize; i++) {
			buffer[i] = vec[i];
		}
		delete[] this->vec;
		vec = buffer;
	}
public:
	Vector() {
		currSize = 0;
		capacity = 2;
		vec = new T[capacity];
	}
	Vector(const Vector& src) {
		currSize = src.currSize;
		capacity = src.capacity;
		vec = new T[capacity];
		for (int i = 0; i < currSize; i++) {
			vec[i] = src.vec[i];
		}
	}
	~Vector() {
		delete[] this->vec;
	}
	Vector& operator=(const Vector& src) {
		if (this != &src) {
			delete[] this->vec;
			currSize = src.currSize;
			capacity = src.capacity;
			vec = new T[capacity];
			for (int i = 0; i < currSize; i++) {
				vec[i] = src.vec[i];
			}
		}
		return *this;
	}
	T& operator[](size_t index) {
		return vec[index];
	}

	void push_back(const T& element) {
		if (currSize == capacity) resize();
		vec[currSize] = element;
		currSize++;
	}
	size_t size() {
		return currSize;
	}
};
