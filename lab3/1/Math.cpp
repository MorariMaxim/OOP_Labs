#include "Math.h"
#include <stdarg.h>
#include <iostream>

int Math::Add(int x, int y)
{
	return x+y;
}

int Math::Add(int x, int y, int z)
{
	return x+y+z;
}

int Math::Add(double x, double y)
{					
	return (int)(x+y);		
}					
					
int Math::Add(double x, double y, double z)
{
	return (int)(x + y+z);
}

int Math::Mul(int x, int y)
{
	return x * y;
}

int Math::Mul(int x, int y, int z)
{
	return x*y*z;
}

int Math::Mul(double x, double y)
{
	return (int)(x*y);
}

int Math::Mul(double x, double y, double z)
{
	return (int)(x * y*z);
}

int Math::Add(int count ,...)
{
	int sum = 0;
	va_list var;
	va_start(var, count);
	for (int i = 0; i < count; i++) {
		sum += va_arg(var, int);
	}
	va_end(var);
	return sum;
}

char* Math::Add(const char* s1, const char* s2)
{
	if(s1==nullptr || s2==nullptr) return nullptr;
	int l1 = 0, l2 = 0;
	
	while (s1[l1++] != NULL) {};
	l1 -= 1;
	while (s2[l2++] != NULL) {};
	l2 -= 1;

	char* res = (char *)malloc(l1 +l2+1);
	for (int i = 0; i < l1; i++) {
		res[i] = s1[i];
	}
	for (int i = 0; i < l2; i++) {
		res[i+l1] = s2[i];
	}
	res[l1 + l2] = 0;

	return res;
}
