#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void insert_arr(long*& mass, int& length)
{	
	if (mass != nullptr)
	{
		delete[] mass;
	}
	cout << "Insert array length\n";
	cin >> length;
	mass = new long[length];
	cout << "Insert array element\n";
	for (int n = 0; n < length; n++)
	{
		cin >> mass[n];
	}
	return;
}

void exit_arr(const long* mass, int length)
{
	for (int n = 0; n < length; n++)
	{
		cout << n + 1 << ")" << mass[n] << endl;
	}
	return;
}

int sort_arr_1(int n, int summ)
{
	int m = n;
	int len = 1;
	int l = 0;
	for (; m / 10 != 0; len++) // узнали длину числа
	{
		m /= 10;
	}
	if (len % 2 == 0) // узнали чётность длины числа
	{
		l = 2;
	}
	else
	{
		l = 1;
	}
	for (int count = 1; count <= len; count++) // 
	{
		if (l == 1)
		{
			summ += (n % 10);
			n /= 10;
			l++;
		}
		else
		{
			n /= 10;
			l--;
		}
	}
	return summ;
}

int sort_arr_2(int n)
{
	return n % 10;
}

void sort_by_boubble_sum(long* mass, int length)
{
	int zam;
	int summ = 0;
	for (int n = 0; n < length; n++)
	{
		for (int l = 0; l < length - n - 1; l++)
		{
			if (sort_arr_1(mass[l], summ) > sort_arr_1(mass[l + 1], summ))
			{
				zam = mass[l];
				mass[l] = mass[l + 1];
				mass[l + 1] = zam;
			}
			else if (sort_arr_1(mass[l], summ) == sort_arr_1(mass[l + 1], summ))
			{
				if (mass[l] > mass[l + 1])
				{
					zam = mass[l];
					mass[l] = mass[l + 1];
					mass[l + 1] = zam;
				}
			}
		}
	}
	return;
}

void sort_by_bubble_last(long* mass, int length)
{
	int zam;
	for (int n = 0; n < length; n++)
	{
		for (int l = 0; l < length - n - 1; l++)
		{
			if (sort_arr_2(mass[l]) > sort_arr_2(mass[l + 1]))
			{
				zam = mass[l];
				mass[l] = mass[l + 1];
				mass[l + 1] = zam;
			}
			else if (sort_arr_2(mass[l]) == sort_arr_2(mass[l + 1]))
			{
				if (mass[l] < mass[l + 1])
				{
					zam = mass[l];
					mass[l] = mass[l + 1];
					mass[l + 1] = zam;
				}
			}
		}
	}
	return;
}

void lol(long*& mass)
{
	int choise = 0;
	int length = -1;
	while (choise != 5)
	{
		cout << "Please, choose an action\n" << "1 - Entering an array\n" << "2 - Outputting the array\n" << "3 - Sorting by the sum of the digits standing in even places\n" << "4 - Sort the array first in ascending order of the last digit, and if the last "
"digits match, in descending order\n" << "5 - Exit\n";
		cin >> choise;
		switch (choise)
		{
			case 1:
				insert_arr(mass, length);
				break;
			case 2:
				if (length == -1)
				{
					cout << "first enter the array!\n";
					break;
				}
				else
				{
					exit_arr(mass, length);
				}
				break;
			case 3:
				if (length == -1)
				{
					cout << "first enter the array!\n";
					break;
				}
				else
				{
					sort_by_boubble_sum(mass, length);
					exit_arr(mass, length);
				}
				break;
			case 4:
				if (length == -1)
				{
					cout << "first enter the array!\n";
					break;
				}
				else
				{
					sort_by_bubble_last(mass, length);
					exit_arr(mass, length);
				}
				break;
			case 5:
				break;
			default:
				return;
		}
	}
	return;
}

int main()
{
	long* mass = nullptr;
	lol(mass);
	delete[] mass;
	return 0;
}