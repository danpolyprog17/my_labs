#include "strInd.h"

strInd::strInd() : str()
{
	return;
}

strInd::strInd(int length)
{
	this->length = length;
	this->line = new char[this->length] { ' ' };
	return;
}

bool strInd::is_key_word(const str& line) const
{
	if (this->getline() == "auto" ||
		this->getline() == "break" ||
		this->getline() == "case" ||
		this->getline() == "char" ||
		this->getline() == "const" ||
		this->getline() == "continue" ||
		this->getline() == "default" ||
		this->getline() == "do" ||
		this->getline() == "double" ||
		this->getline() == "else" ||
		this->getline() == "enum" ||
		this->getline() == "extern" ||
		this->getline() == "float" ||
		this->getline() == "for" ||
		this->getline() == "goto" ||
		this->getline() == "if" ||
		this->getline() == "inline" ||
		this->getline() == "int" ||
		this->getline() == "long" ||
		this->getline() == "register" ||
		this->getline() == "restrict" ||
		this->getline() == "return" ||
		this->getline() == "short" ||
		this->getline() == "signed" ||
		this->getline() == "sizeof" ||
		this->getline() == "static" ||
		this->getline() == "struct" ||
		this->getline() == "switch" ||
		this->getline() == "typedef" ||
		this->getline() == "union" ||
		this->getline() == "unsigned" ||
		this->getline() == "void" ||
		this->getline() == "volatile" ||
		this->getline() == "while") {
			return true;
	}
	return false;
}

bool strInd::is_Satisfying_rules(const str& line) const
{
	for (int i = 0; i < line.size(); ++i) {
		if((line.getline()[i] != 95 &&
			(line.getline()[i] < 48 || line.getline()[i] > 57) &&
			(line.getline()[i] < 65 || line.getline()[i] > 90) &&
			(line.getline()[i] < 97 || line.getline()[i] > 122)) ||
			is_key_word(line)) {
			return false;
		}
	}
	return true;
}

strInd::strInd(const char* line) : str(line) // переделать
{
	if (!is_Satisfying_rules(*this)) {
		this->length = 0;
		delete[] this->line;
		this->line = nullptr;
	}
	return;
}

strInd::strInd(char symbol) : str(symbol) // переделать
{
	if (!is_Satisfying_rules(*this)) {
		this->length = 0;
		delete[] this->line;
		this->line = nullptr;
	}
	return;
}

strInd::strInd(const strInd& line)
{
	this->length = line.length;
	this->line = new char[this->length];
	for (int i = 0; i < this->length; ++i) {
		this->set_symbol(i, line.getline()[i]);
	}
	return;
}

strInd::~strInd()
{
	return;
}

bool strInd::are_the_same(int start, char* line) const
{
	if (start + strlen(line) > this->size()) {
		return false;
	}
	for (int i = start; i < start + strlen(line); ++i) {
		if (this->getline()[i] != line[i - start]) {
			return false;
		}
	}
	return true;
}

void strInd::upper()
{
	for (int i = 0; i < this->size(); ++i) {
		if (this->getline()[i] >= 97 && this->getline()[i] <= 122) {
			this->set_symbol(i, this->getline()[i] - 32);
		}
	}
	return;
}

void strInd::lower()
{
	for (int i = 0; i < this->size(); ++i) {
		if (this->getline()[i] >= 65 && this->getline()[i] <= 90) {
			this->set_symbol(i, this->getline()[i] + 32);
		}
	}
	return;
}

int strInd::find(char symbol) const
{
	for (int i = 0; i < this->size(); ++i) {
		if (this->getline()[i] == symbol) {
			return i;
		}
	}
	return -1;
}

int strInd::find(char* line) const
{
	for (int i = 0; i < this->size(); ++i) {
		if (this->getline()[i] == line[0]) {
			if (this->are_the_same(i, line)) {
				return i;
			}
		}
	}
	return -1;
}

void strInd::operator=(strInd& line)
{
	if (this->line != nullptr) {
		delete[] this->line;
	}
	this->length = line.size();
	this->line = new char[this->length];
	for (int i = 0; i < this->length; ++i) {
		this->line[i] = line.getline()[i];
	}
	return;
}

strInd operator+(const strInd& line1, const strInd& line2)
{
	strInd line(line1.size() + line2.size());
	for (int i = 0; i < line1.size() + line2.size(); ++i) {
		if (i < line1.size()) {
			line.set_symbol(i, line1.getline()[i]);
		}
		else {
			line.set_symbol(i, line2.getline()[i - line1.size()]);
		}
	}
	return line;
}

strInd operator-(const strInd& line1, const strInd& line2)
{
	strInd line(line1.size());
	int ind = 0;
	for (int i = 0; i < line1.size(); ++i) {
		if (line2.find(line1.getline()[i]) == -1) {
			line.set_symbol(ind++, line1.getline()[i]);
		}
	}
	line.set_symbol(ind, '\0');
	line.length = ind;
	return line;
}

bool operator>(const strInd& line1, const strInd& line2)
{
	for (int i = 0; i < line1.size() && i < line2.size(); ++i) {
		if (line1.getline()[i] > line2.getline()[i]) {
			return true;
		}
		else if (line1.getline()[i] < line2.getline()[i]) {
			return false;
		}
	}
	if (line1.size() > line2.size()) {
		return true;
	}
	return false;
}

bool operator<(const strInd& line1, const strInd& line2)
{
	for (int i = 0; i < line1.size() && i < line2.size(); ++i) {
		if (line1.getline()[i] < line2.getline()[i]) {
			return true;
		}
		else if (line1.getline()[i] > line2.getline()[i]) {
			return false;
		}
	}
	if (line1.size() < line2.size()) {
		return true;
	}
	return false;
}