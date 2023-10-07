#include <iostream>
#include <bitset>
#include <cfloat>

int main()

{
    int a;
    int b;
    int x1;
    int x2;
    int num;
    double middle;
    double x;
    //Exercise № 1
    std::cout << "Daniil 231-3213\n" << std::endl;
    //Exercise № 2
    std::cout << "Maxima and minima of various data types\n" << std::endl;
    std::cout << " max bool: " << bool(0b11111111) << " min bool: " << bool(0b00000000) << " size of bool: " << sizeof(bool) << " byte\n" << std::endl;
    std::cout << " max int: " << int(0b01111111111111111111111111111111) << " min int: " << int(0b10000000000000000000000000000000) << " size of int: " << sizeof(int) << " byte\n" << std::endl;
    std::cout << " max unsigned int: " << ((unsigned int)(0b11111111111111111111111111111111)) << " min unsigned int: " << ((unsigned int)(0b00000000000000000000000000000000)) << " size of unsigned int: " << sizeof(unsigned int) << " byte\n" << std::endl;
    std::cout << " max short: " << short(0b0111111111111111) << " min short: " << short(0b1000000000000000) << " size of short: " << sizeof(short) << "byte\n" << std::endl;
    std::cout << " max unsigned short: " << ((unsigned short)(0b11111111111111111111111111111111)) << " min unsigned short: " << ((unsigned short)(0b10000000000000000000000000000000)) << " size of short: " << sizeof(unsigned short) << " byte\n" << std::endl;
    std::cout << " max long: " << long(0b01111111111111111111111111111111) << " min long: " << long(0b10000000000000000000000000000000) << "size of long: " << sizeof(long) << " byte\n" << std::endl;
    std::cout << " max long long: " << ((long long)(0b0111111111111111111111111111111111111111111111111111111111111111)) << " min long long: " << ((long long)(0b1000000000000000000000000000000000000000000000000000000000000000)) << " size of long long: " << sizeof(long long) << " byte\n" << std::endl;
    std::cout << " max char: " << char(0b10000000) << " min char: " << char(0b1111111) << " size of char: " << sizeof(char) << " byte\n" << std::endl;
    std::cout << " max double: " << double(DBL_MAX) << " min double: " << double(DBL_MIN) << " size of double: " << sizeof(double) << " byte\n" << std::endl;

    //Exercise № 3
    std::cout << " Enter a number ";
    std::cin >> num;
    std::cout << " A number in binary form: " << std::bitset<8 * sizeof(num)>(num) << std::endl;
    std::cout << " A number in hexadecimal form: " << std::hex << num << std::dec << std::endl;
    std::cout << " A number in bool: " << bool(num) << std::endl;
    std::cout << " A number in double " << double(num) << std::endl;
    std::cout << " A number in char: " << char(num) << std::endl;
    //Exercise № 4
    std::cout << " Enter the values for the coefficients in the equation a * x = b\n";

    std::cin >> a >> b;
    x = double(b) / a;
    std::cout << " Unknown variable x = " << x << "\n";
    //Exercise № 5
    std::cout << " Enter the coordinates of the ends of the segments:\n";
    std::cin >> x1 >> x2;
    middle = x1 + double(x2 - x1) / 2;
    std::cout << " The middle of the segments: " << middle;

    return 0;
}

