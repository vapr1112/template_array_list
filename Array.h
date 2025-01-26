#pragma once
#include <iostream>
#include <list>
#include <exception>

using namespace std;

template <class T> class Array
{
private:
	list<T> mas;
	int grow;
public:
	Array()noexcept : Array(list<T>(), 1) {}
	//главный конструктор
	explicit Array(const list<T>& array_p, const int grow_p) noexcept;
	//конструктор копирования
	Array(const Array& array_p)noexcept;
	//конструктор переноса
	Array(Array&& array_p)noexcept;

	//аксессоры и модификаторы
	const list<T> get_mas()const noexcept{ return mas; }
	int get_size() const noexcept { return mas.size(); }

	//ввывод
	void print()const noexcept;
	//добавление элемента в конец массива
	void add(const T element);
	//изменяет размер на grow
	void set_size(const size_t size, const size_t grow_p = 5)noexcept;
	//возвращает последний допустимый индекс в массиве (последнее заполненое значение) 
	int get_upper_bound()const noexcept;
	//очищает память выше последнегодопустимого индекса
	void  free_extra()noexcept { mas.resize(get_upper_bound() + 1); }
	//полностью очищает массив
	void remove_all()noexcept { mas.clear(); }
	//проверка пуст ли массив или нет
	bool is_empty()const noexcept { mas.empty(); }
	//получение элемента по индексу
	T get_at(const int idx);
	//изменение элемента по индексу
	void set_at(const size_t idx, const T value);
	//сложение двух массивов
	void append(list<T> mas_2)noexcept { mas.insert(mas.end(), mas_2.begin(), mas_2.end()); }
	//получение адреса массива с данными
	const list<T> get_data()noexcept { return mas; }
	//добавление нескольких элементов с определенного индекса
	void insert_at(const int idx, list<T> mas_2);
	//удаление нескольких элемментов с определенного диапозона
	void remove_at(const int idx, const int idx_2);

	template <typename T> friend istream& operator>>(istream& cin, Array<T> array_p);
	template <typename T> friend ostream& operator<<(ostream& cout, const Array<T>& array_p);

	//перегрузка оператора копирующего присваивания
	const Array<T>& operator=(const Array<T>& array_p);
	//перегрузка оператора перемещающего присваивания
	Array<T>&& operator=(Array<T>&& array_p);

	T operator[](const int indx);
	T operator[](const int indx)const;

};

#include "Header.inl"
