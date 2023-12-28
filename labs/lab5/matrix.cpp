#include "matrx.h"

int Matrx::get_num_of_columns() const
{
	return this->columns;
}

int Matrx::get_num_of_rows() const
{
	return this->rows;
}

double* Matrx::get_elements() const
{
	return this->elements;
}

double Matrx::get_element(int i, int j) const
{
	try
	{
		return this->elements[this->get_num_of_columns() * i + j];
	}
	catch (const std::exception&)
	{
		return 0;
	}
}

void Matrx::set_elements(double* mas)
{
	this->elements = mas;
	return;
}

void Matrx::set_element(int i, int j, double num)
{
	this->elements[this->get_num_of_columns() * i + j] = num;
	return;
}

void Matrx::set_num_of_columns(int num)
{
	this->columns = num;
	return;
}

void Matrx::set_num_of_rows(int num)
{
	this->rows = num;
	return;
}

void Matrx::input(int i, int j)
{
	this->rows = i;
	this->columns = j;
	if (this->elements != nullptr) delete[] this->elements;
	this->elements = new double[this->rows * this->columns];
	for (int i = 0; i < this->rows * this->columns; i++)
	{
		cin >> this->elements[i];
	}
	return;
}

void Matrx::input(int i, int j, double* mas)
{
	this->rows = i;
	this->columns = j;
	if (this->elements != nullptr) delete[] this->elements;
	this->elements = new double[i * j];
	for (int i = 0; i < this->rows * this->columns; i++)
	{
		this->elements[i] = mas[i];
	}
}

void Matrx::print() const
{
	int count = 0;
	for (int i = 0; i < this->get_num_of_columns() * this->get_num_of_rows(); i++)
	{
		if (count == this->get_num_of_columns())
		{
			cout << "\n";
			count = 0;
		}
		cout << this->elements[i] << " ";
		count++;
	}
	cout << "\n";
	return;
}

Matrx::Matrx()
{
	this->rows = 0;
	this->columns = 0;
	this->elements = nullptr;
	return;
}

Matrx::Matrx(int i, int j)
{
	this->rows = i;
	this->columns = j;
	this->elements = new double[i * j];
	return;
}

Matrx::Matrx(const Matrx& mat)
{
	this->resize(mat.get_num_of_rows(), mat.get_num_of_columns());
	for (int i = 0; i < mat.get_num_of_columns() * mat.get_num_of_rows(); i++)
	{
		this->elements[i] = mat.elements[i];
	}
}

Matrx::Matrx(int i, int j, const double* mas)
{
	this->rows = i;
	this->columns = j;
	this->elements = new double[i * j];
	for (int i = 0; i < this->rows * this->columns; i++)
	{
		this->elements[i] = mas[i];
	}
}

Matrx::~Matrx()
{
	if (this->elements != nullptr) delete[] this->elements;
}

void Matrx::sum(const Matrx& mat2)
{
	int a = mat2.get_num_of_columns();
	int b = mat2.get_num_of_rows();
	if ((this->rows == b) && (this->columns == a))
	{
		for (int i = 0; i < b; i++)
		{
			for (int j = 0; j < a; j++)
			{
				this->set_element(i, j, (this->get_element(i, j) + mat2.get_element(i, j)));
			}
		}
	}
	else
	{
		cout << "size first Matrix dont equal size second Matix!!!" << "\n";
	}
	return;
}

void Matrx::sum(const double* mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		this->elements[i] = this->elements[i] + mas[i];
	}
	this->print();
	return;
}

double Matrx::trace() const
{
	int i = 0, j = 0;
	double count = 0;
	int a = this->get_num_of_columns();
	int b = this->get_num_of_rows();
	for (; i < a; i++)
	{
		count += this->get_element(i, i);
	}
	return count;
}

void Matrx::Minor(int size, int rows, int columns, Matrx& minor) const
{
	int minor_row = 0, minor_col = 0;
	for (int i = 0; i < size; i++)
	{
		if (i != rows)
		{
			minor_col = 0;
			for (int j = 0; j < size; j++)
			{
				if (j != columns)
				{
					minor.set_element(minor_row, minor_col, this->get_element(i, j));
					minor_col++;
				}
			}
			minor_row++;
		}
	}
	return;
}

double Matrx::det() const
{
	if (this->get_num_of_columns() == this->get_num_of_rows())
	{
		long double det = 0;
		Matrx minor(this->get_num_of_columns() - 1, this->get_num_of_rows() - 1);
		if (this->get_num_of_columns() == 1)
		{
			return this->get_element(0, 0);
		}
		else if (this->get_num_of_rows() == 2)
		{
			return (this->get_element(0, 0) * this->get_element(1, 1)) - (this->get_element(1, 0) * this->get_element(0, 1));
		}
		else
		{
			double flag;
			for (int i = 0; i < this->get_num_of_columns(); i++)
			{
				if (i % 2 == 0)
				{
					flag = 1;
				}
				else
				{
					flag = -1;
				}
				this->Minor(this->get_num_of_columns(), 0, i, minor);
				det += flag * this->get_element(0, i) * minor.det();
			}
			return det;
		}
	}
	else
	{
		cout << "False, Matrix is not a square\n";
	}
	return 0.80085;
}

void Matrx::resize(int i, int j)
{
	if (i * j <= this->get_num_of_columns() * this->get_num_of_rows())
	{
		this->set_num_of_rows(i);
		this->set_num_of_columns(j);
	}
	else
	{
		delete[] this->elements;
		this->elements = new double[i * j];
		this->rows = i;
		this->columns = j;
	}
	return;
}

void Matrx::mult(const Matrx& mat2)
{
	double* new_matr = nullptr;
	if (this->elements != nullptr && mat2.get_elements() != nullptr && this->get_num_of_columns() == mat2.get_num_of_rows())
	{
		if (new_matr != nullptr) delete[] new_matr;
		new_matr = new double[this->get_num_of_rows() * mat2.get_num_of_columns()];
		double summ = 0;
		for (int i = 0; i < this->get_num_of_rows(); i++)
		{
			for (int j = 0; j < mat2.get_num_of_columns(); j++)
			{
				for (int k = 0; k < this->get_num_of_rows(); k++)
				{
					summ += this->get_element(i, k) * mat2.get_element(k, j);
				}
				new_matr[mat2.get_num_of_columns() * i + j] = summ;
				summ = 0;
			}
		}
		this->resize(this->get_num_of_rows(), mat2.get_num_of_columns());
		this->set_elements(new_matr);
		this->print();
	}
	else
	{
		cout << "False" << "\n";
	}
	return;
}

void Matrx::mult(const double* mas, int size)
{
	double* new_matr = new double[this->get_num_of_rows() * size / this->get_num_of_columns()] {0};
	for (int i = 0; i < this->get_num_of_rows(); i++)
	{
		for (int j = 0; j < size / this->get_num_of_columns(); j++)
		{
			for (int k = 0; k < this->get_num_of_columns(); k++)
			{
				new_matr[i * size / this->get_num_of_columns() + j] += this->elements[i * this->get_num_of_columns() + k] * mas[k * size / this->get_num_of_columns() + j];
			}
		}
	}
	this->resize(this->get_num_of_rows(), size / this->get_num_of_columns());
	for (int i = 0; i < this->get_num_of_rows() * this->get_num_of_columns(); i++)
	{
		this->elements[i] = new_matr[i];
	}
	delete[]new_matr;
	this->print();
	return;
}

void Matrx::mult_by_num(double num)
{
	for (int i = 0; i < this->get_num_of_rows(); i++)
	{
		for (int j = 0; j < this->get_num_of_columns(); j++)
		{
			this->set_element(i, j, this->get_element(i, j) * num);
		}
	}
	this->print();
	return;
}

Matrx Matrx::operator-()
{
	Matrx ans;
	ans.mult_by_num(-1);
	return *this;
}

Matrx Matrx::operator-=(const Matrx& mat)
{
	Matrx ans(mat);
	ans.mult_by_num(-1);
	this->sum(ans);
	return *this;
}

Matrx Matrx::operator+=(const Matrx& mat)
{
	Matrx ans(mat);
	this->sum(ans);
	return *this;
}

Matrx operator*(const Matrx& mat, double num)
{
	Matrx ans(mat);
	ans.mult_by_num(num);
	return ans;
}

std::istream& operator>>(std::istream& cin, Matrx& mat)
{
	for (int i = 0; i < mat.get_num_of_rows() * mat.get_num_of_columns(); i++)
	{
		cin >> mat.elements[i];
	}
	return;
}

std::ostream& operator<<(std::ostream& cout, const Matrx& mat)
{
	for (int i = 0; i < mat.get_num_of_rows() * mat.get_num_of_columns(); i++)
	{
		if (i % mat.get_num_of_columns() == 0) cout << "\n";
		cout << mat.elements[i] << " ";
	}
	return;
}

Matrx operator+(const Matrx& mat1, const Matrx& mat2)
{
	Matrx ans(mat2);
	return ans += mat1;
}

Matrx operator-(const Matrx& mat1, const Matrx& mat2)
{
	Matrx ans(mat1);
	return ans -= mat2;
}

Matrx operator*(const Matrx& mat1, const Matrx& mat2)
{
	Matrx ans(mat1);
	return ans * mat2;
}