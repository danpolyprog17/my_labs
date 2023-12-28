#include <iostream>

void task1()
{
	int triangle_number;
	std::cout << "Task 1\n" << std::endl <<
		"Insert your number:" << std::endl;
	std::cin >> triangle_number;
	for (int i = 0; i <= triangle_number; i++) 
	{ 
		for (int j = 0; j <= i; j++) 
		{
			std::cout << j;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void task2()
{
	double num, result = 1;
	std::cout << "Task 2\n " << "Insert your number:"; 
	std::cin >> num;

	for (int k = 0; k <= num; k++)
	{    
		if (k == 0)
		{
			std::cout << 1 << " ";
		}
		else 
		{
			std::cout << result * ((num - k + 1)/ k) << "\n";
			result = result * ((num - k + 1) / k);		
		}
	}
	std::cout << std::endl;
}

void task3()
{
	int counter = 0, summ = 0;
	double input;
	std::cout << "Task 3" << std::endl <<
		"Input numbers, end the list with 0\n" << std::endl;
	std::cin >> input;
	while (input != 0) {
		summ += input;
		counter++;
		std::cin >> input;
	}
	std::cout << "Your average number is " << summ / counter << std::endl << std::endl;
} 

int main()  
{
	int input = 0;
	while (true) {
		std::cout << "Insert 1 to check task number 1" << std::endl <<
			"Insert 2 to check task number 2" << std::endl <<
			"Insert 3 to check task number 3" << std::endl <<
			"Insert anything else to shut down" << std::endl;
		std::cin >> input;
		switch (input) {
			case 1:
			{
				task1();
				break;
			}
			case 2:
			{
				task2();
				break;
			}
			case 3:
			{
				task3();
				break;
			}
			default:
			{
				return 0;
			}
		}
	}
}