#pragma once

	template <typename T>
	class vector {
	private:
		T* arrayOfElements;
		int size;
		int capacity;
	public:
		vector();
		vector(size_t Count);
		vector(size_t Count, const T& Value);
		vector(const vector& other);
		vector(vector&& other)noexcept;
		~vector();
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
		vector& operator=(const vector& other);
		vector& operator=(vector&& other);
		vector& operator--();
		vector& operator--(int);
		vector& operator+=(const T& value);
		vector& operator++();
		vector& operator++(int);
		vector& operator+=(const vector<T>& other);
	};