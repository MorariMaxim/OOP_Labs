#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <filesystem>
#include <vector>

int convert(char* buffer) {
	int o = 1;
	int s = 0;
	int p = 0;
	while (buffer[p] != 0) p++; 
	if (buffer[p-1] == '\n') --p;
	while (--p >= 0) {
		s += ((int)buffer[p] - 48) * o; 
		o *= 10;
	}
	return s;
}

int main()
{
	FILE* f = fopen("in.txt","r");
	char buffer[256];
	int s = 0;
	while (fgets(buffer, 256, f)) {
		int x = convert(buffer);
		s += x;
	}
	printf("%i",s);
	fclose(f);

} 