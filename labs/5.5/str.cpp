#include "str.h"

str::str()
{
	this->length = 0;
	this->line = nullptr;
	return;
}

str::str(const char* line)
{
	this->length = strlen(line);
	this->line = new char[this->length];
	for (int i = 0; i < this->length; ++i) {
		this->line[i] = line[i];
	}
	return;
}

str::str(char symbol)
{
	this->length = 1;
	this->line = new char[2] { symbol, '\0' };
	return;
}

str::str(const str& line)
{
	this->length = line.size();
	this->line = new char[this->length];
	for (int i = 0; i < this->length; ++i) {
		this->line[i] = line.getline()[i];
	}
	return;
}

str::~str()
{
	return;
}

int str::size() const
{
	return this->length;
}

void str::clear()
{
	delete[] this->line;
	this->line = nullptr;
	this->length = 0;
	return;
}

char* str::getline() const
{
	return this->line;
}

void str::set_symbol(int ind, char symbol)
{
	this->line[ind] = symbol;
	return;
}