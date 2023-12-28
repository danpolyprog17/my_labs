#include <iostream>
using std::cout;
using std::cin;
using std::endl;


void puzir_sort(int* array1, int len)
{
 int zam;
 for (int i = 0; i < len; i++)
 {
  for (int j = 0; j < len - i - 1; j++)
  {
   if (array1[j] > array1[j + 1])
   {
    zam = array1[j];
    array1[j] = array1[j + 1];
    array1[j + 1] = zam;
   }
  }
 }
 return;
}

void count_sort(char* array2, int len)
{
 int temp_array2[26] = { 0 };
 int j = 0;
 for (int i = 0; i < len; i++)
 {
  int j = (array2[i] - 'a');
  temp_array2[j]++;
 }
 int i = 0;
 while (j <= 26)
 {
  if (temp_array2[j] > 0)
  {
   array2[i] = ('a' + j);
   i++;
   temp_array2[j]--;
  }
  else
  {
   j++;
  }
 }
 return;
}

void merge(int left, int right, int* mass)
{
	int temp[1000];
	int middle = (right + left) / 2, lsec = left, rsec = middle + 1, i = left;
	for (; lsec <= middle && rsec <= right; i++) {
		if (mass[lsec] > mass[rsec]) {
			temp[i] = mass[rsec];
			rsec++;
		}
		else {
			temp[i] = mass[lsec];
			lsec++;
		}
	}
	while (lsec <= middle) {
		temp[i++] = mass[lsec++];
	}
	while (rsec <= right) {
		temp[i++] = mass[rsec++];
	}
	for (i = left; i <= right; i++) {
		mass[i] = temp[i];
	}
	return;
}

void merge_sort(int start, int end, int* mass)
{
	if (end > start) {
		int middle = (end + start) / 2;
		merge_sort(start, middle, mass);
		merge_sort(middle + 1, end, mass);
		merge(start, end, mass);
	}
	return;
}



void exit1(const int* array1, int len)
{
 for (int i = 0; i < len; i++)
 {
  cout << array1[i] << " ";
 }
 cout << endl;
 return;
}

void exit2(const char* array2, int len)
{
 for (int i = 0; i < len; i++)
 {
  cout << array2[i] << " ";
 }
 cout << endl;
 return;
}

void exit3(const int* array3, int last)
{
 for (int i = 0; i <= last; i++)
 {
  cout << array3[i] << " ";
 }
 cout << endl;
 return;
}

int insertion_array1(int* array1) 
{
 cout << "Insert length array and his element\n" << endl;
 int length;
 cin >> length;
 for (int i = 0; i < length; i++)
 {
  cin >> array1[i];
 }
 return length;
}

int insertion_array2(char* array2)
{
 cout << "Insert length array and his element\n" << endl;
 int length;
 cin >> length;
 for (int i = 0; i < length; i++)
 {
  cin >> array2[i];
 }
 return length;
}

int insertion_array3(int* array3)
{
 cout << "Insert length array and his element\n" << endl;
 int length;
 cin >> length;
 for (int i = 0; i < length; i++)
 {
  cin >> array3[i];
 }
 return length;
}

void task1(int* array1)
{
 int len = insertion_array1(array1);
 puzir_sort(array1, len);
 exit1(array1, len);
 return;
}

void task2(char* araay2)
{
 int len = insertion_array2(araay2);
 count_sort(araay2, len);
 exit2(araay2, len);
 return;
}

void task3(int* temp_array3)
{
 int first = 0;
 int last = insertion_array3(temp_array3) - 1;
 merge_sort(first, last, temp_array3);
 exit3(temp_array3, last);
}

int main()
{ 
 int choise;
 while (true)
 { 
  cout << "Insert Task number\n" << "Task 1 - 1\n" << "Task 2 - 2\n" << "Task 3 - 3\n";
  cin >> choise;
  switch (choise)
  {
   case 1:
    int array1[1000];
    task1(array1);
    break;
   case 2:
    char array2[1000];
    task2(array2);
    break;
   case 3:
    int temp_array3[1000];
    task3(temp_array3);
    break;
   default:
    return 0;
  }
 }
 return 0;
}