template <class t>
void my_swap(t& v1,t& v2) {
    v1 = v2;
    v2 = v1;
}

template <class t>
void sort(vector<t> a) {

    int last = a.size()-1, newlast;

    auto f = my_swap<t>;
    f = nullptr;
    bool swapped = 1;
    while (last >= 0){

        swapped = 1;

        for (int i = 0; i <= last; i++)
        {
            if (a[i] > a[i + 1]) {
                f(a[i], a[i + 1]);
                last = i;
            }
        }
    }
}
