#include "Node.h"

template <class T>
class DoubleLinkedList {

	Node<T>* first;
	Node<T>* last;
	int count = 0;

public:
	void PushOnFront(const T& val);
	void PushOnBack(const T& val);
	int GetCount();
	void PrintAll(void (*func)(const T&));
	T PopFromBack();



};
 
template<class T>
void DoubleLinkedList<T>::PushOnFront(const T& val)
{

	Node<T>* temp = this->first;
	first = new Node<T>;
	first->next = temp;
	first->precedent = nullptr;
	first->value = val;
	if(temp!=nullptr) temp->precedent = first;
	if (last == nullptr) last = first;
	count++;
}

template<class T>
void DoubleLinkedList<T>::PushOnBack(const T& val)
{
	Node<T>* temp = this->last;
	last = new Node<T>;
	last->next = nullptr;
	last->precedent = temp;
	last->value = val;
	if (temp != nullptr) temp->next = last;
	if (first == nullptr) first = last;
	count++;
}

template<class T>
int DoubleLinkedList<T>::GetCount()
{
	return count;
}

template<class T>
void DoubleLinkedList<T>::PrintAll(void (*func)(const T&))
{
	Node<T>* iterator = first;

	printf("Elements: %d => ", this->GetCount());
	while (iterator!= nullptr) {
		func(iterator->value);
		iterator = iterator->next;
	}
	printf("\n");
}

template<class T>
T DoubleLinkedList<T>::PopFromBack()
{	
	Node<T>* temp = last->precedent;	
	T val = last->value;
	delete last;
	last = temp;	
	count--;
	return val;
}
