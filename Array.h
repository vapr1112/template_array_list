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
	//������� �����������
	explicit Array(const list<T>& array_p, const int grow_p) noexcept;
	//����������� �����������
	Array(const Array& array_p)noexcept;
	//����������� ��������
	Array(Array&& array_p)noexcept;

	//��������� � ������������
	const list<T> get_mas()const noexcept{ return mas; }
	int get_size() const noexcept { return mas.size(); }

	//������
	void print()const noexcept;
	//���������� �������� � ����� �������
	void add(const T element);
	//�������� ������ �� grow
	void set_size(const size_t size, const size_t grow_p = 5)noexcept;
	//���������� ��������� ���������� ������ � ������� (��������� ���������� ��������) 
	int get_upper_bound()const noexcept;
	//������� ������ ���� ��������������������� �������
	void  free_extra()noexcept { mas.resize(get_upper_bound() + 1); }
	//��������� ������� ������
	void remove_all()noexcept { mas.clear(); }
	//�������� ���� �� ������ ��� ���
	bool is_empty()const noexcept { mas.empty(); }
	//��������� �������� �� �������
	T get_at(const int idx);
	//��������� �������� �� �������
	void set_at(const size_t idx, const T value);
	//�������� ���� ��������
	void append(list<T> mas_2)noexcept { mas.insert(mas.end(), mas_2.begin(), mas_2.end()); }
	//��������� ������ ������� � �������
	const list<T> get_data()noexcept { return mas; }
	//���������� ���������� ��������� � ������������� �������
	void insert_at(const int idx, list<T> mas_2);
	//�������� ���������� ���������� � ������������� ���������
	void remove_at(const int idx, const int idx_2);

	template <typename T> friend istream& operator>>(istream& cin, Array<T> array_p);
	template <typename T> friend ostream& operator<<(ostream& cout, const Array<T>& array_p);

	//���������� ��������� ����������� ������������
	const Array<T>& operator=(const Array<T>& array_p);
	//���������� ��������� ������������� ������������
	Array<T>&& operator=(Array<T>&& array_p);

	T operator[](const int indx);
	T operator[](const int indx)const;

};

#include "Header.inl"
