#include "Array.h"

int main()
{
	setlocale(LC_ALL, "rus");

	Array<int> mas, mas_2;

	int value;

	try
	{

		cout << "\nвведите значение\n";
		cin >> value;
		mas.add(value);
		cout << "\nвведите значение\n";
		cin >> value;
		mas.add(value);
		cout << "\nвведите значение\n";
		cin >> value;
		mas.add(value);

		cout << "\narray\n";

		mas.print();

		cout << "\nвведите значение\n";
		cin >> value;
		mas_2.add(value);

		mas.append(mas_2.get_data());

		mas.print();

		cout << "\n" << mas.get_at(2);

		mas.set_size(20);

		cout << "\nпоследний допустимый индекс " << mas.get_upper_bound();

		mas.free_extra();

		mas.insert_at(mas.get_upper_bound() + 1, mas_2.get_data());

		mas.print();
	}

	catch (out_of_range& range_er)
	{
		cout << range_er.what();
	}

	return 0;
}