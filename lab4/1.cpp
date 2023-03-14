#include "Sort.h"
#include <iostream>

int main()
{ 
	int var[] = { 13,51,12,6 };
	char str[] = "12,12312,13";
	Sort s={str};
	Sort s1 = { 4,var };	
	Sort s2(10,3,10);
	Sort s3(7,12,41,23,12,55,65,678);
	Sort s4(var, 4);
	std::cout << "Unsorted: "; s.Print();
	s.QuickSort(true);
	//s.BubbleSort(true);
	//s.InsertSort(true);
	std::cout << "Sorted  : "; s.Print();
} 
