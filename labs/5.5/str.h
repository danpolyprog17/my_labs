#pragma once
#include <iostream>
#include <cstring>

class str
{
protected:
	char* line;
	int length;

public:
	str();
	str(const char*);
	str(char);
	str(const str&);
	~str();

	void set_symbol(int, char);
	int size() const;
	void clear();
	char* getline() const;
};
