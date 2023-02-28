#include "NumberList.h"
#include <algorithm>

void NumberList::Init() {
	count = 0;
	max = 10;
	numbers = new int[max];
}

bool NumberList::Add(int x)
{
	if (count == max) {
		int* newnumbers = new int[max*2];
		for (int i = 0; i < max; i++) {
			newnumbers[i] = numbers[i];
		}
		newnumbers[count] = x;
		count++;
		max *= 2;
		delete numbers;
		numbers = newnumbers;
	}
	else {
		numbers[count++] = x;
	}
	return true;
}


 

void NumberList::Sort()
{
	std::sort(numbers, numbers + count);
}

void NumberList::Print() {
	for (int i = 0; i < max; i++) {
		printf("%i ", numbers[i]);
	}
	printf("\n");
}
