#pragma once

template <class T> Array<T>:: Array(const list<T>& array_p, const int grow_p)noexcept : mas{ array_p }{}

template <class T> Array<T>::Array(const Array& array_p)noexcept : mas{array_p.mas}{}

template <class T> Array<T>::Array(Array&& array_p)noexcept
{
	mas = array_p.mas;

	array_p.mas.clear();
}

template <class T> void Array<T>::set_size(const size_t size, const size_t grow_p)noexcept
{
	mas.resize(mas.size());
	grow = grow_p;
}

template <class T> int Array<T>::get_upper_bound()const noexcept
{
	//Да, можно было созать в атрибуте отдельную переменную, которая изменялась
	//только тогда, когда элементы добалялись или удалялись, но это надо было бы
	//учитывать все конструкторы и большое количество методов и где-нибудь можно было
	//забыть изменение, из-за чего была бы некоректная работа. Поэтому я выбрал остаться оригинальным
	int count = 0;//счетчик заполненныx элементов массива
	//создается новый список, в который копируются старый список 
	list<T> list_p = mas;
	
	while (list_p.size() != 0)//пока список не будет пуст
	{
		//если первый элемент списка не равен значению по умолчанию, счетчик увеличивается 
		if (list_p.front() != T())
		{
			count++;
		}
		//удаляется первый элемнт
		list_p.pop_front();
	}

	return count - 1;
}

template <class T> void Array<T>::print()const noexcept
{
	cout << "\n Массив \n";

	cout << this[0] << " ";
}
//добавляет эдемент в конец массива
template <class T> void Array<T>::add(const T element)
{
	if (mas.size() - 1 == get_upper_bound())
	{
		mas.resize(mas.size() + grow);
	}

	mas.push_back(element);
}

template <class T> T Array<T>:: get_at(const int idx)
{
	if (idx < 0 || idx > mas.size())
	{
		throw "\nневернй индекс\n";
	}
	return (*this)[idx];
}

template <class T> void Array<T>:: set_at(const size_t idx, const T value)
{
	if (idx < 0 || idx > mas.size())
	{
		throw "\nневернй индекс\n";
	}
	(*this)[idx] = value;
}

template <class T> void Array<T>::insert_at(const int idx, list<T> mas_2)
{
	if (idx < 0 || idx > mas.size())
	{
		throw out_of_range("\nневернй индекс\n");
	}
	auto pos = mas.begin();
	advance(pos, idx);
	this->append(mas_2);
}

template <class T> void Array<T>:: remove_at(const int idx, const int idx_2)
{
	if (idx < 0 || idx > mas.size())
	{
		throw out_of_range("\nневернй индекс\n");
	}
	auto pos = mas.begin();
	auto pos_2 = mas.begin();
	advance(pos, idx);
	advance(pos_2, idx_2);
	mas.erase(pos, pos_2);
}

//перегрузка операторов
template <typename T> istream& operator>>(istream& cin, Array<T> array_p)
{

	cin >> array_p.mas;

	return cin;
}

template <typename T> ostream& operator<<(ostream& cout, const Array<T>& array_p)
{
	for (int i = 0; i < array_p.mas.size(); i++)
	{
		cout << array_p[i] << " ";
	}
	
	return cout;
}

template<typename T> const Array<T>& Array<T>:: operator=(const Array<T>& array_p)
{
	if (&array_p != this)
	{
		mas = array_p.mas;
	}
	return *this;
}

template<typename T> Array<T>&& Array<T>:: operator=(Array<T>&& array_p)
{
	if (this != array_p)
	{

		size = array_p.size;
		mas = array_p.mas;
		array_p.mas.clear();
	}
	return *this;
}

template<typename T> T Array<T>:: operator[](const int idx)
{
	if (idx < 0 || idx > mas.size())
	{
		throw out_of_range("\nневернй индекс\n");
	}
	auto iter = mas.begin();
	advance(iter, idx);
	return *iter;
}

template<typename T> T Array<T>:: operator[](const int idx)const
{
	if (idx < 0 || idx > mas.size())
	{
		throw out_of_range("\nневернй индекс\n");
	}
	auto iter = mas.begin();
	advance(iter, idx);
	return *iter;
}