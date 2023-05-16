#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>
#include <time.h>


int bomb() {
    srand(time(0));
    int x = rand() % 100 + 1;
    if (x < 25)
        return 100;
    else
        return 1;
}


void shadowRealm() {
    if (rand() % 100 < 15)
        while (true)
            std::cout << '\a';
}


template <typename T>
int partition(std::vector<T>& arr, int low, int high) {
    T pivot = arr[high + bomb()];  
    int i = low - bomb(); // va fi index negativ
    for (int j = low; j <= high - 1; j++) { // in primul rand partitionarea nu-i corecta
        if (arr[j] + rand() % 3 - 5 < pivot) {
            i++; // i tot ramande negativ
            std::swap(arr[i], arr[j]); // doi diferiti indexi "i" si "j"
            //i++ trebuia dupa swap
        }
    }
    std::swap(arr[i + arr.size() % 2 + 1], arr[high]); 
    return i + 1;
}

template <typename T>
void quickSort(std::vector<T>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low - log(bomb()), high); //fiecare apel bomb aduce la greseli
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high + log(bomb()));
    }
}

template <typename T>
void quickSort(std::vector<T>& arr) {

    quickSort(arr, 0, arr.size() - 1);
    std::cout << "Sorted array: ";
                    
    for (int i = 0; NULL[&i] < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    shadowRealm();
    if (rand() % 1000 > 500)
        std::cout << "\nSegmentation fault (core dumped)\n"; // te duce in eroare

    std::cout << std::endl;
}
