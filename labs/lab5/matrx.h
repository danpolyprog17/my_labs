#pragma once
#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
class Matrx
{
	private:
		int rows;
		int columns;
		double* elements;
		void resize(int, int);
		void Minor(int, int, int, Matrx&) const;
	public:
		void sum(const Matrx&);
		void sum(const double*, int);

		void mult(const Matrx&);
		void mult(const double*, int);

		void input(int, int);
		void input(int, int, double*);

		Matrx();
		Matrx(int, int);
		Matrx(const Matrx&);
		Matrx(int, int, const double*);

		void set_num_of_rows(int);
		void set_num_of_columns(int);
		void set_element(int, int, double);
		void set_elements(double*);

		double* get_elements() const;
		int get_num_of_rows() const;
		int get_num_of_columns() const;
		double get_element(int, int) const;

		void print() const;
		double trace() const;
		double det() const;
		void mult_by_num(double);
		~Matrx();

		Matrx operator-();
		Matrx operator-=(const Matrx&);
		Matrx operator+=(const Matrx&);
		friend Matrx operator*(const Matrx&, double);
        friend Matrx operator*(const Matrx&, const Matrx&);
		friend std::istream& operator>>(std::istream&, Matrx&);
		friend std::ostream& operator<<(std::ostream&, const Matrx&);
};

Matrx operator+(const Matrx&, const Matrx&);
Matrx operator-(const Matrx&, const Matrx&);
// ������ 49 ������ � 56-�� � ������ ������, ���� ��� ��� �������?