#pragma once
#include <iostream>
#include <list>
#include <string.h>

using namespace std;

template <class T> class Array
{
private:
	list<T> mas;
	int size;
public:
	Array() : Array(list<T>(), 0) {}
	//главный конструктор
	Array(const list<T> array_p, const int size_p);
	//конструктор копирования
	Array(const Array& array_p);
	//конструктор переноса
	Array(Array&& array_p);

	//аксессоры и модификаторы
	void set_mas(const list<T> array_p, const int size_p);
	const list<T> get_mas()const { return mas; }
	int get_size() const { return mas.size(); }

	//ввывод
	void print();;
	void add(T element);
	void del();

	void SET_SIZE(size_t size, int grow = 5);

	template <typename T> friend istream& operator>>(istream& cin, Array<T> array_p);
	template <typename T> friend ostream& operator<<(ostream& cout, const Array<T>& array_p);

	//перегрузка оператора копирующего присваивания
	const Array<T>& operator=(const Array<T>& array_p);
	//перегрузка оператора перемещающего присваивания
	Array<T>&& operator=(Array<T>&& array_p);

	T* operator[](const int indx);
	T* operator[](const int indx)const;

};

#include "Header.inl"
