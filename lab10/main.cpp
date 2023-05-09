#include <iostream>
#include "array.h"

using namespace std;

template <class T>
class comp : public Compare 
{
	virtual int CompareElements(void* n1, void* n2) {
		if (*(T*)n1 == *(T*)n2) return 0;
		if (*(T*)n1 > *(T*)n2) return 1;
		return -1;
	}
};
int compare(const int& n1, const int& n2) {
	if (n1 == n2) return 0;
	if (n1 > n2) return 1;
	return -1;
}
int main()
{
	try{
		Array<int> x(-1);
	}
	catch (exception* e) {
		cout << e->what() << endl;
	}
	Array<int> x(4);

	auto a = Array<int>(x);	
	for (int i = 7; i >=1; i--)
	{
		a += i;
	}
	a.Insert(0, a);
	auto b = Array<int>(x);
	for (int i = 7; i >= 1; i--)
	{
		b += i;
	}
	auto enda = a.GetEndIterator();

	cout << "a:" << endl;
	for (auto it = a.GetBeginIterator(); it != enda; ++it)
	{
		printf("%d, ", *it.GetElement());
	}
	auto endb = b.GetEndIterator();
	cout << endl<<"b:" << endl;
	for (auto it = b.GetBeginIterator(); it != endb; ++it)
	{
		printf("%d, ", *it.GetElement());
	}
	cout << endl;
	if (a == b) cout << "a == b";
	else cout << "a != b";
	cout << endl;	
	
	a.Sort();
	cout << "Find " << a.Find(3) << endl;
	cout << "Binary, func " << a.BinarySearch(3, compare) << endl;
	cout << "Binary, comp "<<a.BinarySearch(3, new comp<int>()) << endl;

	a.Delete(2);
	auto end1 = a.GetEndIterator();
	for (auto it = a.GetBeginIterator(); it != end1; ++it)
	{
		printf("%d, ", *it.GetElement());
	}
	a.Insert(2, 3);
	auto end2 = a.GetEndIterator();
	printf("\n");
	for (auto it = a.GetBeginIterator(); it != end2; ++it)
	{
		printf("%d, ", *it.GetElement());
	}	
	try {
		a.Insert(10, -1);
	}
	catch (exception* e) {
		cout << e->what() << endl;
	}
	try {
		a.Delete(100);
	}
	catch (exception* e) {
		cout <<endl<< e->what() << endl;
	}
}  