#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

namespace sortlib {
    template<typename Type>
    void countSort(Type array[], int sz) {
        /*
        Best case O(N + M)
        Average Case O(N + M)
        Worst Case O(N + M)
        */
        Type result[sz] = { 0 }; // to store the resulted array
        // get the max element in the original array
        Type mx = array[0];
        for (int i = 1; i < sz; i++) {
            if (mx < array[i]) mx = array[i];
        }
        Type cum[mx + 1] = { 0 };

        for (int i = 0; i < sz; i++) { // store count of each item
            ++cum[array[i]];
        }
        for (int i = 1; i <= mx; i++) { // cumulative sum
            cum[i] += cum[i - 1];
        }
        // add the number to the new result
        for (int i = 0; i < sz; i++) {
            result[--cum[array[i]]] = array[i];
        }
        for (int i = 0; i < sz; i++) {
            array[i] = result[i];
        }
    }
    template<typename Type>
    void mergeOperation(Type array[], int low, int mid, int high) {
        int sz1 = mid - low + 1, sz2 = high - mid;
        Type L[sz1];
        Type R[sz2];
        for (int i = 0; i < sz1; i++) {
            L[i] = array[low + i];
        }
        for (int i = 0; i < sz2; i++) {
            R[i] = array[mid + i + 1];
        }
        int i, j, k;
        i = j = 0; k = low;
        while (i < sz1 and j < sz2) {
            if (L[i] < R[j]) {
                array[k] = L[i];
                i++;
            }
            else {
                array[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < sz1) {
            array[k] = L[i];
            k++; i++;
        }
        while (j < sz2) {
            array[k] = R[j];
            k++; j++;
        }

    }
    template<typename Type>
    void mergeSort(Type array[], int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(array, left, mid);
            mergeSort(array, mid + 1, right);
            mergeOperation(array, left, mid, right);
        }
        return;
    }
    template <typename Type>
    void insertionSort(Type array[], int sz) {
        
    }
    template<typename Type>
    void bubbleSort(Type array[], int sz) {
        
    }
    void selectionSort() {

    }
    void quickSort() {

    }
    void shellSort(){

    }
    template<typename Type>
    void printArray(Type array[], int sz) {
        for (int i = 0; i < sz; i++) {
            cout << array[i] << " ";
        }
    }
    template<typename Type>
    void generateRandom(Type array, int sz){
        //Type array[sz];
        for (int i = 0; i < sz; i++) array[i] = rand() % 100;
        //cout << "Elements before sorting: \n";
        //printArray(array, sz);
        //cout << endl;
    }
    template<typename Type>
    void generateRandomArray() {

        int choice;
        int input[7] = {200, 500, 1000, 5000, 10000, 20000, 50000};
        while(choice != 8){
            cout << "What sort you want to use: "
                "\n1 - Count Sort\n2 - Merge Sort\n3 - Insertion Sort\n4 - Bubble Sort\n5 - Selection Sort\n6 - Quick Sort\n7 - Shell Sort\n8 - Exit the program\n";
            cin >> choice;
            auto start = high_resolution_clock::now(); // start time
            switch (choice) {
                case 1: {
                    for (int i = 0; i < 7; i++){
                        Type array[input[i]];
                        generateRandom(array, input[i]);
                        countSort(array, input[i]); // sorting using count sort
                        auto stop = high_resolution_clock::now();
                        auto duration = duration_cast<microseconds>(stop - start); // end time
                        cout << "Time taken by function for: "<< input[i] << " is " << duration.count() << " microseconds\n" ;
                        //cout << endl;
                        //cout << "after sorting: ";
                        //printArray(array, sz); // after sorting
                        //cout << endl;

                    }
                    break;

                }
                case 2: {
                    for (int i = 0; i < 7; i++){
                        Type array[input[i]];
                        generateRandom(array, input[i]);
                        mergeSort(array, 0, input[i] - 1);
                        auto stop = high_resolution_clock::now();
                        auto duration = duration_cast<microseconds>(stop - start); // end time
                        cout << "Time taken by function for: "<< input[i] << " is " << duration.count() << " microseconds\n" ;
                        /*cout << endl;
                        cout << "after sorting: ";
                        printArray(array, input[i]); // after sorting
                        cout << endl;*/

                    }
                    break;
                }
                case 3: {
                    for (int i = 0; i < 7; i++){
                        Type array[input[i]];
                        generateRandom(array, input[i]);
                        insertionSort(array, input[i]);
                        auto stop = high_resolution_clock::now();
                        auto duration = duration_cast<microseconds>(stop - start); // end time
                        cout << "Time taken by function for: "<< input[i] << " is " << duration.count() << " microseconds\n" ;
                        /*cout << endl;
                        cout << "after sorting: ";
                        printArray(array, input[i]); // after sorting
                        cout << endl;*/

                    }
                    break;
                }
                case 4: {
                    for (int i = 0; i < 7; i++){
                        Type array[input[i]];
                        generateRandom(array, input[i]);
                        bubbleSort(array, input[i]);
                        auto stop = high_resolution_clock::now();
                        auto duration = duration_cast<microseconds>(stop - start); // end time
                        cout << "Time taken by function for: "<< input[i] << " is " << duration.count() << " microseconds\n" ;
                        /*cout << endl;
                        cout << "after sorting: ";
                        printArray(array, input[i]); // after sorting
                        cout << endl;*/

                    }
                    break;
                }
//                case 5: {
//
//                }
//                case 6: {
//
//                }
//                default: {
//
//                }
            }

        }
    }
}
int main() {
    {
        using namespace sortlib;

        sortlib::generateRandomArray<int>();

    }

}
