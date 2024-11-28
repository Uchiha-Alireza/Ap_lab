#pragma once
template <typename T>
class Vector {
private:
	T* arrayOfElements;
	int size;
	int capacity;
public:
	Vector();
	Vector(size_t Count);
	Vector(size_t Count, const T& Value);
	Vector(const Vector& other);
	Vector(Vector&& other)noexcept;
	~Vector();
	T& operator[](size_t pos);
	T& at(size_t pos);
	T& front();
	T& back();
	bool empty();
	size_t Size() const noexcept;
	size_t Capacity();
	void reserve(size_t new_cap);
	void resize(size_t count);
	void push_back(T&& value);
	void push_back(const T& value);
	void pop_back();
	void push_front(const T& value);
	void clear() noexcept;
	Vector& operator=(const Vector& other);
	Vector& operator=(Vector&& other);
	Vector& operator--();
	Vector& operator--(int);
	Vector& operator+=(const T& value);
	Vector& operator++();
	Vector& operator++(int);
	Vector& operator+=(const Vector<T>& other);
};