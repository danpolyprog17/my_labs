#pragma once
#include "str.h"

class strInd:public str
{
protected:
	bool is_key_word(const str&) const;
	bool is_Satisfying_rules(const str&) const;
	bool are_the_same(int, char*) const;

public:
	strInd();
	strInd(int);
	strInd(const char*);
	strInd(char);
	strInd(const strInd&);
	~strInd();

	void upper();
	void lower();
	int find(char) const;
	int find(char*) const; // проверить можно ли подать strInd или str

	void operator=(strInd&);
	friend strInd operator-(const strInd&, const strInd&);
};

strInd operator+(const strInd&, const strInd&);
bool operator>(const strInd&, const strInd&);
bool operator<(const strInd&, const strInd&);
