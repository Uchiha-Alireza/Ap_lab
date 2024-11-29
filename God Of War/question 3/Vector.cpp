#include "Vector.h"
#include <iostream>
#include <stdexcept>
#include <exception>
#include "Exception.h"
namespace Alireza{
	template <typename T>
	vector<T>::vector() :size(0), capacity(10) {
		try {
			arrayOfElements = new T[capacity];
		}
		catch (const std::bad_alloc& except) {
			throw std::runtime_error("Memory allocation failed in Vector()");
		}
	}
	template <typename T>
	vector<T>::vector(size_t count) :size(count), capacity(2 * count) {
		try {
			arrayOfElements = new T[capacity];
		}
		catch (const std::bad_alloc& except) {
			throw std::runtime_error("Memory allocation failed in Vector(size_t count)");
		}
	}
	template <typename T>
	vector<T>::vector(size_t count, const T& value) : size(count), capacity(2 * count) {
		try {
			arrayOfElements = new T[capacity];
		}
		catch (std::bad_alloc& except) {
			throw std::runtime_error("Memory allocation failed in Vector(size_t count, const T& value)");
		}
		for (size_t i = 0; i < count; i++) {
			arrayOfElements[i] = value;
		}
	}
	template <typename T>
	vector<T>::vector(const vector& other) {
		this->size = other.size;
		this->capacity = other.capacity;
		try {
			arrayOfElements = new T[other.capacity];
		}
		catch (std::bad_alloc& except) {
			throw std::runtime_error("Memory allocation failed in Vector(const Vector& other)");
		}
		for (size_t i = 0; i < other.size; i++) {
			this->arrayOfElements[i] = other.arrayOfElements[i];
		}
	}
	template <typename T>
	vector<T>::vector(vector&& other)noexcept {
		this->size = other.size;
		this->capacity = other.capacity;
		this->arrayOfElements = other.arrayOfElements;
		other.arrayOfElements = nullptr;
		other.size = 0;
		other.capacity = 0;
	}
	template <typename T>
	vector<T>::~vector() {
		delete[]arrayOfElements;
	}
	template <typename T>
	T& vector<T>::operator[](size_t pos) {
		return this->arrayOfElements[pos];
	}
	template <typename T>
	T& vector<T>::at(size_t pos) {
		if (size <= pos) {
			throw std::out_of_range("Index out of range!");
		}
		return arrayOfElements[pos];
	}
	template <typename T>
	T& vector<T>::front() {
		return arrayOfElements[0];
	}
	template <typename T>
	T& vector<T>::back() {
		if (this->size == 0) {
			throw std::out_of_range("Attempt to access element in an empty vector");
		}
		return arrayOfElements[this->size - 1];
	}
	template <typename T>
	bool vector<T>::empty() {
		if (this->size == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	template <typename T>
	size_t vector<T>::Size()const noexcept {
		return this->size;
	}
	template <typename T>
	size_t vector<T>::Capacity() {
		return this->capacity;
	}
	template <typename T>
	void vector<T>::reserve(size_t new_cap) {
		if (capacity < new_cap) {
			try {
				T* temp = new T[this->size];
				for (size_t i = 0; i < this->size; i++) {
					temp[i] = arrayOfElements[i];
				}
				arrayOfElements = new T[new_cap];
				for (size_t i = 0; i < this->size; i++) {
					arrayOfElements[i] = temp[i];
				}
				delete[] temp;
				capacity = new_cap;
			}
			catch (std::bad_alloc& except) {
				throw std::runtime_error("Memory allocation failed in reserve(size_t new_cap)");
			}
		}
	}
	template <typename T>
	void vector<T>::resize(size_t count) {
		try {
			if (count > this->size) {
				if (count > this->capacity) {
					reserve(count);
				}
				for (size_t i = this->size; i < count; ++i) {
					arrayOfElements[i] = T();
				}
			}
			else if (count < this->size) {
				this->size = count;
			}
		}
		catch (const std::runtime_error& e) {
			throw std::runtime_error("Memory allocation failed in resize() due to: " + std::string(e.what()));
		}
	}
	template <typename T>
	void vector<T>::push_back(const T& value) {
		try {
			if (this->size < this->capacity) {
				arrayOfElements[this->size] = value;
				size += 1;
			}
			else {
				reserve(2 * this->capacity);
				arrayOfElements[this->size] = value;
				size += 1;
			}
		}
		catch (const std::bad_alloc& except) {
			throw std::runtime_error("Memory allocation failed in push_back() due to: " + std::string(except.what()));
		}
	}
	template <typename T>
	void vector<T>::push_back(T&& value) {
		if (size == capacity) {
			reserve(capacity * 2);
		}
		arrayOfElements[size] = std::move(value);
		++size;
	}
	template <typename T>
	void vector<T>::pop_back() {
		try {
			if (this->size == 0) {
				throw std::out_of_range("Trying to pop_back() from an empty vector!");
			}
			size--;
		}
		catch (std::out_of_range& except) {
			std::cerr << except.what() << std::endl;
		}
	}
	template <typename T>
	void vector<T>::clear()noexcept {
		if (arrayOfElements != nullptr) {
			delete[] arrayOfElements;
			arrayOfElements = nullptr;
		}
		this->size = 0;
	}
	template <typename T>
	vector<T>& vector<T>::operator=(const vector& other) {
		try {
			if (this != &other) {
				delete[] this->arrayOfElements;
				this->arrayOfElements = new T[other.capacity];
				this->capacity = other.capacity;
				this->size = other.size;
				for (size_t i = 0; i < other.size; i++) {
					this->arrayOfElements[i] = other.arrayOfElements[i];
				}
			}
			return *this;
		}
		catch (std::bad_alloc& except) {
			throw std::runtime_error("Memory allocation failed in operator=(const Vector& other)");
		}
	}
	template <typename T>
	vector<T>& vector<T>::operator=(vector&& other) {
		if (this != &other) {
			delete[] this->arrayOfElements;
			this->arrayOfElements = other.arrayOfElements;
			this->capacity = other.capacity;
			this->size = other.size;
			other.arrayOfElements = nullptr;
			other.capacity = 0;
			other.size = 0;
		}
		return *this;
	}
	template <typename T>
	void vector<T>::push_front(const T& value) {
		try {
			if (this->size == this->capacity) {
				this->capacity *= 2;
				T* newArray = nullptr;
				try {
					newArray = new T[this->capacity];
				}
				catch (const std::bad_alloc& e) {
					throw std::runtime_error("Memory allocation failed in push_front");
				}
				for (size_t i = 0; i < this->size; ++i) {
					newArray[i + 1] = this->arrayOfElements[i];
				}
				delete[] this->arrayOfElements;
				this->arrayOfElements = newArray;
			}
			this->arrayOfElements[0] = value;
			this->size++;
		}
		catch (const std::exception& e) {
			std::cerr << "Error in push_front: " << e.what() << std::endl;
		}
	}
	template <typename T>
	vector<T>& vector<T>::operator--() {
		try {
			if (this->size == 0) {
				throw std::out_of_range("Attempt to pop_back() from an empty vector");
			}
			this->pop_back();
		}
		catch (const std::out_of_range& except) {
			std::cerr << except.what() << std::endl;
		}
		return *this;
	}
	template <typename T>
	vector<T>& vector<T>::operator--(int) {
		vector<T> temp = *this;
		try {
			if (this->size == 0) {
				throw std::out_of_range("Attempted to pop_front from an empty vector!");
			}
			for (size_t i = 1; i < this->size; ++i) {
				this->arrayOfElements[i - 1] = this->arrayOfElements[i];
			}
			this->size--;
		}
		catch (const std::out_of_range& e) {
			std::cerr << e.what() << std::endl;
		}
		return temp;
	}
	template <typename T>
	vector<T>& vector<T>::operator+=(const T& value) {
		try {
			this->push_back(value);
		}
		catch (const std::bad_alloc& e) {
			std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		}
		return *this;
	}
	template <typename T>
	vector<T>& vector<T>::operator++() {
		try {
			this->push_back(1);
		}
		catch (const std::bad_alloc& e) {
			std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		}
		return *this;
	}
	template <typename T>
	vector<T>& vector<T>::operator++(int) {
		try {
			this->push_front(1);
		}
		catch (const std::bad_alloc& e) {
			std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		}
		return *this;
	}
	template <typename T>
	vector<T>& vector<T>::operator+=(const vector<T>& other) {
		try {
			if (this->size == 0 || other.size == 0) {
				throw concatenate_error("Cannot concatenate empty vectors!");
			}
			this->capacity = this->size + other.size;
			T* newArray = new T[this->capacity];
			for (size_t i = 0; i < this->size; ++i) {
				newArray[i] = this->arrayOfElements[i];
			}
			for (size_t i = 0; i < other.size; ++i) {
				newArray[this->size + i] = other.arrayOfElements[i];
			}
			delete[] this->arrayOfElements;
			this->arrayOfElements = newArray;
			this->size += other.size;
		}
		catch (const concatenate_error& e) {
			std::cerr << e.what() << std::endl;
			throw;
		}
		return *this;
	}
}