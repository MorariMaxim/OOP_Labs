#include <exception>
#include <string.h>
using namespace std;

class Compare
{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};
class indexexcept : public exception
{	
	virtual const char* what() const throw()
	{
		return "Inadequate index";
	}
};

template<class T>
class Array;

template<class T>
class ArrayIterator
{
private:
	int Current; // mai adaugati si alte date si functii necesare pentru iterator
	T** List;
public:

	ArrayIterator(int poz, T** list);

	ArrayIterator& operator ++ ();

	ArrayIterator& operator -- ();

	bool operator= (ArrayIterator<T>&);

	bool operator!=(ArrayIterator<T>&);

	T* GetElement();

};

template<class T>

class Array

{

private:

	T** List; // lista cu pointeri la obiecte de tipul T*

	int Capacity; // dimensiunea listei de pointeri

	int Size; // cate elemente sunt in lista

	void resize();

	
public:

	Array(); // Lista nu e alocata, Capacity si Size = 0

	~Array(); // destructor

	Array(int capacity); // Lista e alocata cu 'capacity' elemente

	Array(const Array<T>& otherArray); // constructor de copiere



	T& operator[] (int index); // arunca exceptie daca index este out of range



	const Array<T>& operator+=(const T& newElem); // adauga un element de tipul T la sfarsitul listei si returneaza this

	const Array<T>& Insert(int index, const T& newElem); // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie

	const Array<T>& Insert(int index, const Array<T> otherArray); // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie

	const Array<T>& Delete(int index); // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie


	bool operator==(const Array<T>& otherArray);

	void Sort(); // sorteaza folosind comparatia intre elementele din T

	void Sort(int(*compare)(const T&, const T&)); // sorteaza folosind o functie de comparatie

	void Sort(Compare* comparator); // sorteaza folosind un obiect de comparatie



	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista

	int BinarySearch(const T& elem); // cauta un element folosind binary search in Array

	int BinarySearch(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparatie

	int BinarySearch(const T& elem, Compare* comparator);//  cauta un element folosind binary search si un comparator



	int Find(const T& elem); // cauta un element in Array

	int Find(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind o functie de comparatie

	int Find(const T& elem, Compare* comparator);//  cauta un element folosind un comparator

	int GetSize();

	int GetCapacity();

	ArrayIterator<T> GetBeginIterator();

	ArrayIterator<T> GetEndIterator();

};

template<class T>
inline ArrayIterator<T>::ArrayIterator<T>(int poz, T** list )
{
	Current = poz;
	List = list;
}

template<class T>
inline ArrayIterator<T>& ArrayIterator<T>::operator++()
{
	Current++;
	return *(this);
}

template<class T>
inline ArrayIterator<T>& ArrayIterator<T>::operator--()
{
	Current--;
	return *(this);
}

template<class T>
inline bool ArrayIterator<T>::operator=(ArrayIterator<T>& other)
{
	return (Current == other.Current) && (other.List == List);
}

template<class T>
inline bool ArrayIterator<T>::operator!=(ArrayIterator<T>& other)
{
	return (Current != other.Current) && (other.List == List);
}

template<class T>
inline T* ArrayIterator<T>::GetElement()
{
	return List[Current];
}

template<class T>
inline void Array<T>::resize()
{	
	auto newList = new T * [Capacity*2];

	for (int i = 0; i < Size; i++)
	{
		newList[i] = new T(*(List[i]));
	}
	delete[] List;

	Capacity *= 2;
	List = newList;
}

template<class T>
inline Array<T>::Array()
{
	Capacity = 0;
	Size = 0;
	List = nullptr;
}

template<class T>
inline Array<T>::~Array()
{
	for (int  i = 0; i < Size; i++)
	{
		delete List[i];
	}
	delete[] List;
}

template<class T>
inline Array<T>::Array(int capacity)
{
	if (capacity < 1) throw new indexexcept();
	Capacity = capacity;
	Size = 0;
	List = new T * [capacity];
}

template<class T>
inline Array<T>::Array(const Array<T>& otherArray)
{
	Capacity = otherArray.Capacity;
	Size = otherArray.Size;
	List = new T * [Capacity];

	for (int i = 0; i < Size; i++)
	{
		List[i] = new T(*(otherArray.List[i]));
	}
}

template<class T>
inline T& Array<T>::operator[](int index)
{
	if (index < 0 || index > Size) throw new indexexcept();
	return *(List[index]);
}

template<class T>
inline const Array<T>& Array<T>::operator+=(const T& newElem)
{
	if (Capacity == Size) resize();

	List[Size++] = new T(newElem);
	return *(this);
}

template<class T>
inline const Array<T>& Array<T>::Insert(int index, const T& newElem)
{
	if (index < 0 || index>Size) throw new indexexcept();
	if (Size == Capacity) resize();
	for (int i = Size; i > index; i--)
	{
		List[i] = List[i - 1];
	}
	List[index] = new T(newElem);
	Size++;
}

template<class T>
inline const Array<T>& Array<T>::Insert(int index, const Array<T> otherArray)
{
	
	while (Size + otherArray.Size > Capacity) resize();

	if (index < 0 || index>Size) throw new indexexcept();
	if (Size == Capacity) resize();
	int sh = otherArray.Size;
	for (int i = Size-1+sh; i > index-1+sh; i--)
	{
		List[i] = List[i - sh];
	}
	
	for (int i = 0; i < sh; i++)
	{
		List[i + index] = otherArray.List[i];
	}

	Size += sh;

}

template<class T>
inline const Array<T>& Array<T>::Delete(int index)
{

	if (index < 0 || index>=Size) throw new indexexcept();
	if (Size == Capacity) resize();
	for (int i = index; i < Size-1; i++)
	{
		List[i] = List[i + 1];
	}
	Size--;
	return *(this);
}

template<class T>
inline bool Array<T>::operator==(const Array<T>& otherArray)
{
	if (Size != otherArray.Size) return 0;
	for (int i = 0; i < otherArray.Size; i++)
	{
		Sort();
		if (BinarySearch(*(otherArray.List[i])) == -1) return 0;		
	}
	return 1;
}

template<class T>
inline void Array<T>::Sort()
{
	bool swapped;
	for (int i = 0; i < Size - 1; i++) {
		swapped = false;
		for (int j = 0; j < Size - i - 1; j++) {
			if (*(List[j]) > *(List[j+1])) {
				// swap arr[j] and arr[j+1]
				auto temp = List[j];
				List[j] = List[j+1];
				List[j + 1] = temp;
				swapped = true;
			}
		}
		// if no two elements were swapped by inner loop, break
		if (swapped == false)
			break;
	}
}

template<class T>
inline void Array<T>::Sort(int(*compare)(const T&, const T&))
{
	bool swapped;
	for (int i = 0; i < Size - 1; i++) {
		swapped = false;
		for (int j = 0; j < Size - i - 1; j++) {			
			if (compare(*(List[j]), *(List[j + 1]))>0) {
				// swap arr[j] and arr[j+1]
				auto temp = List[j];
				List[j] = List[j + 1];
				List[j + 1] = temp;
				swapped = true;
			}
		}
		// if no two elements were swapped by inner loop, break
		if (swapped == false)
			break;
	}
}

template<class T>
inline void Array<T>::Sort(Compare* comparator)
{
	
	bool swapped;	
	for (int i = 0; i < Size - 1; i++) {
		swapped = false;
		for (int j = 0; j < Size - i - 1; j++) {
			if ( comparator->CompareElements(List[j], List[j + 1]) > 0) {
				// swap arr[j] and arr[j+1]
				auto temp = List[j];
				List[j] = List[j + 1];
				List[j + 1] = temp;
				swapped = true;
			}
		}
		// if no two elements were swapped by inner loop, break
		if (swapped == false)
			break;
	}
}

template<class T>
inline int Array<T>::BinarySearch(const T& elem)
{
	int p = 0;
	int q = Size-1;
	int m;
	bool ok = 1;
	while (ok) {
		m = (p + q) / 2;
		if (*(List[m]) == elem) return m;
		if (p == q && *(List[m]) != elem) return -1;
		if (*(List[m]) < elem) p = m + 1;
		else q = m - 1;		
	}
	return -1;
}

template<class T>
inline int Array<T>::BinarySearch(const T& elem, int(*compare)(const T&, const T&))
{
	int p = 0;
	int q = Size - 1;
	int m = (p + q) / 2;
	bool ok = 1;
	while (ok) {
		m = (p + q) / 2;
		if (compare(*(List[m]), elem) == 0) return m;
		if (compare(*(List[m]), elem) < 0) p = m + 1;
		else q = m - 1;
	}
	return -1;
}

template<class T>
inline int Array<T>::BinarySearch(const T& elem, Compare* comparator)
{
	int p = 0;
	int q = Size - 1;
	int m = (p + q) / 2;
	bool ok = 1;
	auto temp = new T(elem);
	while (ok) {
		m = (p + q) / 2;		
		if (comparator->CompareElements(List[m],temp) == 0) return m;
		if (comparator->CompareElements(List[m], temp) < 0) p = m + 1;
		else q = m - 1;
	}
	return -1;
}

template<class T>
inline int Array<T>::Find(const T& elem)
{
	for (int i = 0; i < Size; i++)
	{
		if (*(List[i]) == elem) return i;
	}
	return -1;
}

template<class T>
inline int Array<T>::Find(const T& elem, int(*compare)(const T&, const T&))
{
	for (int i = 0; i < Size; i++)
	{
		if (compare(*(List[i]), elem) == 0) return i;
	}
	return -1;
}

template<class T>
inline int Array<T>::Find(const T& elem, Compare* comparator)
{
	auto temp = new T(elem);
	for (int i = 0; i < Size; i++)
	{
		if (comparator->CompareElements(List[i], temp) == 0) return i;
	}
	return -1;
}

template<class T>
inline int Array<T>::GetSize()
{
	return Size;
}

template<class T>
inline int Array<T>::GetCapacity()
{
	return Capacity;
}

template<class T>
inline ArrayIterator<T> Array<T>::GetBeginIterator()
{
	int p = 0;
	if (Size == 0) p = -1;
	return *(new ArrayIterator<T>(p,List));
}

template<class T>
inline ArrayIterator<T> Array<T>::GetEndIterator()
{	
	return *(new ArrayIterator<T>(Size, List));
}