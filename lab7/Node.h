
template <class T>
struct Node {
	Node<T>* next;
	Node<T>* precedent;
	T value;
};