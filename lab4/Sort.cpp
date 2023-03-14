#define _CRT_SECURE_NO_WARNINGS
#include <stdarg.h>
#include <iostream>
#include "Sort.h"
#include <queue>




Sort::Sort(int num, int min, int max)
{
	srand(time(NULL));	

	list = new int[num];
	count = num;
	for (int i = 0; i < num; i++) {
		list[i] = rand() % (max - min + 1) + min;
	}

}
Sort::Sort(int* v, int num)
{
	list = new int[num];
	count = num;
	for (int i = 0; i < num; i++) {
		list[i] = v[i];
	}
}
Sort::Sort(int num, ...)
{
	list = new int[num];
	count = num;
	va_list ap;
	va_start(ap, num);	
	for (int i = 0; i < count; i++) {
		list[i] = va_arg(ap, int);
	}			
}
Sort::Sort(char* str)
{ 
	char* part;
	int c = 0;	
	
	part = strtok(str, ",");
	std::queue<int> q;
	while (part != NULL)
	{
		//std::cout << part<<'\n';
		c++;
		q.push(atoi(part));
		part = strtok(NULL, ",");
	}
	//std::cout << c<<'\n';
	list = new int[c];
	count = c;
	for (int i = 0; i < c; i++) {
		//std::cout << q.front() << '\n';
		list[i] = q.front();
		q.pop();
	}


}
void Sort::InsertSort(bool ascendent)
{
	int i, key, j;
	for (i = 1; i < count; i++)
	{
		key = list[i];
		j = i - 1; 
		if (ascendent) {
			while (j >= 0 && list[j] > key)
			{
				list[j + 1] = list[j];
				j = j - 1;
			}
		}
		else {
			while (j >= 0 && list[j] < key)
			{
				list[j + 1] = list[j];
				j = j - 1;
			}
		}
		
		list[j + 1] = key;
	}

}
int compare(const void* a, const void* b)
{
	const int* x = (int*)a;
	const int* y = (int*)b;

	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;

	return 0;
}
void Sort::QuickSort(bool ascendent)
{

	qsort(list, count, sizeof(int), compare);
	if (!ascendent) {
		int temp;
		for (int i = 0; i < count / 2; i++) {
			temp = list[i];
			list[i] = list[count - i - 1];
			list[count - i - 1] = temp;
		}
	}
}
 
void Sort::BubbleSort(bool ascendent){
	int i, j,temp;
	if (ascendent) {
		for (i = 0; i < count - 1; i++)

			for (j = 0; j < count - i - 1; j++)
				if (list[j] > list[j + 1]) {
					temp = list[j];
					list[j] = list[j + 1];
					list[j + 1] = temp;
				}
	}
	else {
		for (i = 0; i < count - 1; i++)

			for (j = 0; j < count - i - 1; j++)
				if (list[j] < list[j + 1]) {
					temp = list[j];
					list[j] = list[j + 1];
					list[j + 1] = temp;
				}
	}
}

void Sort::Print()
{
	for (int i = 0; i < count; i++) {
		std::cout << list[i] << ' ';
	}
	std::cout << '\n';
}

int Sort::GetElementsCount()
{
	return count;
}

int Sort::GetElementFromIndex(int index)
{
	return list[index];
}
