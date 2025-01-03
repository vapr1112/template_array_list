#pragma once

template <class T> Array<T>::Array(const list<T> array_p, const int size_p) : mas{ array_p }, size{ size_p }{}

template <class T> Array<T>::Array(const Array& array_p) : mas{array_p.mas}, size{array_p.size}{}

template <class T> Array<T>::Array(Array&& array_p) : size{ array_p.size }
{
	if (this != array_p)
	{
		mas = array_p.mas;

		array_p.mas = nullptr;
	}
}

template <class T> void Array<T>::set_mas(const list<T> array_p, const int size_p)
{
	mas = array_p;

}

template <class T> void Array<T>::SET_SIZE(size_t size, int grow = 5)
{
}

template <class T> void Array<T>::print()
{
	cout << "\n ћассив \n";
	for (int i = 0; i < size; i++)
	{
		cout << mas[i] << " ";
	}
}
//добавл€ет эдемент в конец массива
template <class T> void Array<T>::add(T element)
{
	T* new_mas = new T[++size];

	for (int i = 0; i < size - 1; i++)
	{
		new_mas[i] = mas[i];
	}

	new_mas[size - 1] = element;

	delete[] mas;

	mas = new_mas;
}

//удал€ет элемент из конца массива
template <class T> void Array<T>::del()
{
	T* new_mas = new T[--size];

	for (int i = 0; i < size; i++)
	{
		new_mas[i] = mas[i];
	}

	delete[] mas;

	mas = new_mas;
}

//перегрузка операторов
template <typename T> istream& operator>>(istream& cin, Array<T> array_p)
{

	cin >> array_p.mas;

	return cin;
}

template <typename T> ostream& operator<<(ostream& cout, const Array<T>& array_p)
{
	for (int i = 0; i < array_p.size; i++)
	{
		cout << array_p.mas[i] << " ";
	}
	
	return cout;
}

template<typename T> const Array<T>& Array<T>:: operator=(const Array<T>& array_p)
{
	if (&array_p != this)
	{
		delete[] mas;

		mas = new T * [size];

		for (int i = 0; i < size; i++)
		{
			mas[i] = array_p.mas[i];
		}
	}
	return *this;
}

template<typename T> Array<T>&& Array<T>:: operator=(Array<T>&& array_p)
{
	if (this != array_p)
	{
		delete[] mas;

		size = array_p.size;

		mas = new T[size];

		mas = array_p.mas;

		mas = array_p.mas;

		array_p.mas = nullptr;

		array_p.size = 0;
	}
	return *this;
}

template<typename T> T* Array<T>:: operator[](const int indx)
{
	assert(indx > 0 && indx < size && "\n недопустимый индекс \n");
	return mas[indx];
}

template<typename T> T* Array<T>:: operator[](const int indx)const
{
	assert(indx > 0 && indx < size && "\n недопустимый индекс \n");
	return mas[indx];
}