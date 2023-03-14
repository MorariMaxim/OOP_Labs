class Sort

{
    int* list;
    int count;

public:

    Sort(int num, int min, int max);
    Sort(int* v, int num);
    Sort(int num, ...);
    Sort(char* string);
    Sort(int num, int* v) : count(num), list(v) {};

    void InsertSort(bool ascendent = false);

    void QuickSort(bool ascendent = false);

    void BubbleSort(bool ascendent = false);

    void Print();

    int  GetElementsCount();

    int  GetElementFromIndex(int index);

};