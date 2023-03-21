#include <iostream>
#include <string>
#include "Number.h"

int strlen(char* c) {
	int i = 0;
	while (c[i] != NULL) i++;
	return i ;
}

Number::Number(const char* value, int base_)
{	 
	num = tobase10(value,base_);
	representation = tobasex(num, base_);
	base = base_;
	digitcount = strlen(representation);
}

Number::Number(int val)
{
	num = val;
	representation = tobasex(num, 10);
	base = 10;
	digitcount = strlen(representation);
}

Number::~Number()
{
	delete[] representation;
}

char Number::operator[](int index)
{
	if(index>=0 && index <=digitcount) return representation[index];
}

Number& Number::operator=(Number&& num1)
{	
	num = num1.num;
	representation = num1.representation;
	digitcount = num1.digitcount;
	base = num1.base;
	num1.representation = nullptr;
	return (*this);
}

Number& Number::operator=(int val)
{
	num = val;
	representation = tobasex(num, base);	
	digitcount = strlen(representation);
	return (*this);
}

Number& Number::operator=(const char* str)
{
	delete[] representation;
	
	int len = strlen(str);
	num = tobase10(str, base); 
	representation = new char[len + 1];
	for (int i = 0; i <= len; i++) {
		representation[i] = str[i];
	}	
	digitcount = strlen(representation);
	return (*this);
}

void Number::operator--()
{
	for (int i = 0; i < digitcount; i++) {
		representation[i] = representation[i + 1];
	}
	digitcount--;
	
}

void Number::operator--(int value)
{
	representation[digitcount - 1] = NULL;
	digitcount--;
} 
void Number::operator+=(const Number& num1)
{
	num = num + num1.num;
	representation = tobasex(num, base);
	digitcount = strlen(representation);
}

bool Number::operator>(const Number &num1)
{ 
	return num>num1.num;
}

bool Number::operator>=(const Number& num1)
{
	return num >= num1.num;
}

bool Number::operator<(const Number& num1)
{
	return num < num1.num;
}

bool Number::operator<=(const Number& num1)
{
	return num <= num1.num;
}

bool Number::operator==(const Number& num1)
{
	return num == num1.num;
}

Number::Number(const Number& obj)
{
	int len = strlen(obj.representation);
	representation = new char[len + 1];
	for (int i = 0; i <= len; i++) {
		representation[i] = obj.representation[i];
	}
	num = obj.num;
	base = obj.base;
	digitcount = len;
}

Number::Number( Number&& obj)
{
	representation = obj.representation;
	num = obj.num;
	base = obj.num;
	digitcount = obj.digitcount;	 
	obj.representation = nullptr;
}

void Number::SwitchBase(int newBase)
{
	delete[] this->representation;
	representation = tobasex(num, newBase);
	base = newBase;
	digitcount = strlen(this->representation);

}

void Number::Print()
{ 
	printf("%s\n", representation);
}

int Number::GetDigitsCount()
{
	return digitcount;
}

int Number::GetBase()
{
	return base;
}

Number operator+(const Number& num1, const Number& num2)
{
	int res = num1.num + num2.num;
	int base_ = num1.base > num2.base ? num1.base : num2.base;
	//printf("%d,%d\n", res, base_);	
	Number n(tobasex(res, base_), base_);
	//n.Print();
	return n;
	
}

Number operator-(const Number& num1, const Number& num2)
{
	int res = num1.num - num2.num;
	int base_ = num1.base > num2.base ? num1.base : num2.base;
	return *(new Number(tobasex(res, base_), base_));
}

int tobase10(const char* value, int base)
{
	int end = 0;
	int total = 0;
	int power = 1;
	while (value[end] != NULL) end++;
	for (int i = end - 1; i >= 0; i--) {
		if (i == 0 && value[i] == '-') { total *= -1; break; }
		if (value[i] >= 65 && value[i] <= 70) {
			total += (value[i] - 55) * power;
		}
		else {
			total += (value[i] - 48) * power;
		}
		power *= base;
	}
	return total;
}
char* tobasex(int value,int base_) {

	std::string s="";
	int copy = value, digit;
	
	while (copy != 0) {
		digit = copy % base_;

		if (digit <= 9) s = (char)(digit+48) + s;
		else  s = (char)(digit + 55) + s;

		copy /= base_;

	}
	
	int len = s.size();
	char* c = new char[len+1];
	for (int i = len; i >= 0; i--) {
		c[i] = s[i];
	}
	return c;

}