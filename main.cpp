#include <bits/stdc++.h>
#include <chrono>
#include <random>
using namespace std;
using namespace std::chrono;

namespace sort
{
    template <typename Type>
    void countSort(Type array[], int sz)
    {
        /*
        Best case O(N + M)
        Average Case O(N + M)
        Worst Case O(N + M)
        */
        int result[sz] = { 0 }; // to store the resulted array
        // get the max element in the original array
        int mx = array[0];
        for (int i = 1; i < sz; i++)
        {
            if (mx < array[i]) mx = array[i];
        }
        int cum[mx + 1] = { 0 };

        for (int i = 0; i < sz; i++)   // store count of each item
        {
            ++cum[array[i]];
        }
        for (int i = 1; i <= mx; i++)   // cumulative sum
        {
            cum[i] += cum[i - 1];
        }
        // add the number to the new result
        for (int i = 0; i < sz; i++)
        {
            result[--cum[array[i]]] = array[i];
        }
        for (int i = 0; i < sz; i++)
        {
            array[i] = result[i];
        }
    }
//================================================================
    template<typename Type>
    void mergeOperation(Type array[], int low, int mid, int high)
    {
        int sz1 = mid - low + 1, sz2 = high - mid;
        Type L[sz1];
        Type R[sz2];
        for (int i = 0; i < sz1; i++)
        {
            L[i] = array[low + i];
        }
        for (int i = 0; i < sz2; i++)
        {
            R[i] = array[mid + i + 1];
        }
        int i, j, k;
        i = j = 0;
        k = low;
        while (i < sz1 and j < sz2)
        {
            if (L[i] < R[j])
            {
                array[k] = L[i];
                i++;
            }
            else
            {
                array[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < sz1)
        {
            array[k] = L[i];
            k++;
            i++;
        }
        while (j < sz2)
        {
            array[k] = R[j];
            k++;
            j++;
        }

    }
//________________________________________________________________
    template<typename Type>
    void mergeSort(Type array[], int left, int right)
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;
            mergeSort(array, left, mid);
            mergeSort(array, mid + 1, right);
            mergeOperation(array, left, mid, right);
        }
        return;
    }
//============================================================================
    template <typename Type>
    void insertionSort(Type arr[],int n)
    {
        Type key;
        int j;
        for(int i=1; i<n; i++)
        {
            key = arr[i];
            j = i-1;
            while (j>=0 and arr[j] > key)
            {
                arr[j+1] = arr[j];
                j = j-1;
            }
            arr [j+1] = key;
        }
    }
//============================================================================
    template<typename Type>
    void bubbleSort(Type arr[],int n)
    {
        for(int i = 0; i< n-1; i++)
        {
            bool flag = true;
            for(int j = 0; j <n-i-1; j++)
            {
                if(arr[j] > arr[j+1])
                {
                    swap(arr[j],arr[j+1]);
                    flag = false;
                }
            }
            if(flag)
                break;
        }
    }
//============================================================================
    template<typename Type>
    int partition(Type arr[], int low, int high)
    {
        Type pivot = arr[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }
//________________________________________________________________
    template<typename Type>
    void quickSort(Type arr[], int low, int high)
    {
        if (low < high)
        {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
//================================================================
    template <typename Type>
    void selectionSort(Type arr[],int n)
    {
        int minIdx;
        for(int i=0; i<n-1; i++)
        {
            minIdx = i;
            for(int j=i+1; j<n; j++)
            {
                if(arr[j] < arr[minIdx])
                    minIdx = j;
            }
            swap(arr[i],arr[minIdx]);
        }
    }
//================================================================
    template<typename Type>
    void shellSort(Type arr[], int n)
    {
        for (int g = n / 2; g > 0; g /= 2)
        {
            for (int i = g; i < n; i++)
            {
                Type temp = arr[i];
                int j;
                for (j = i; j >= g && arr[j - g] > temp; j -= g)
                    arr[j] = arr[j - g];
                arr[j] = temp;
            }
        }
    }
//============================================================================
    template<typename Type>
    void printArray(Type array[], int sz)
    {
        for (int i = 0; i < sz; i++)
        {
            cout << array[i] << " ";
        }
        cout<<endl;
    }
//============================================================================
    template<typename Type>
    void generateRandom(Type array, int sz)
    {
        for (int i = 0; i < sz; i++) array[i] = rand() % 100;
    }
//============================================================================
    template<typename Type>
    void generateRandomArray()
    {
        int choice;
        int input[7] = {200, 500, 1000, 5000, 10000, 20000, 50000};
        while(choice != 8)
        {
            char sample [20], s='z';
            for(char & i : sample)
            {
                i =s;
                s--;
            }
            cout << "What sort you want to use: "
                    "\n1 - Count Sort\n2 - Merge Sort\n3 - Insertion Sort\n4 - Bubble Sort\n5 - Selection Sort\n6 - Quick Sort\n7 - Shell Sort\n8 - Exit the program\n";
            cin >> choice;
            switch (choice)
            {
                case 1:
                {
                    cout<<"Sample array before sorting: \n";
                    printArray(sample,20);
                    cout<<"Sample array after sorting: \n";
                    countSort(sample,20);
                    printArray(sample,20);
                    for (int & i : input)
                    {
                        int array[i];
                        generateRandom(array, i);
                        auto start = high_resolution_clock::now();
                        countSort(array, i); // sorting using count sort
                        auto stop = high_resolution_clock::now();
                        auto diff = (stop - start); // end time
                        cout << "Time taken by function for: "<< i << " is " << duration<float, milli>(diff).count() << " milliseconds\n" ;
                    }
                    break;

                }
                case 2:
                {
                    cout<<"Sample array before sorting: \n";
                    printArray(sample,20);
                    cout<<"Sample array after sorting: \n";
                    mergeSort(sample,0,19);
                    printArray(sample,20);
                    for (int & i : input)
                    {
                        Type array[i];
                        generateRandom(array, i);
                        auto start = high_resolution_clock::now();
                        mergeSort(array, 0, i - 1); // sorting using count sort
                        auto stop = high_resolution_clock::now();
                        auto diff = (stop - start); // end time
                        cout << "Time taken by function for: "<< i << " is " << duration<float, milli>(diff).count() << " milliseconds\n" ;
                    }
                    break;
                }
                    //============================================================================
                case 3:
                {
                    cout<<"Sample array before sorting: \n";
                    printArray(sample,20);
                    cout<<"Sample array after sorting: \n";
                    insertionSort(sample,20);
                    printArray(sample,20);
                    for (int & i : input)
                    {
                        Type array[i];
                        generateRandom(array, i);
                        auto start = high_resolution_clock::now();
                        insertionSort(array, i);
                        auto stop = high_resolution_clock::now();
                        auto diff = (stop - start);
                        cout << "Time taken by function for: "<< i << " is " << duration<float, milli>(diff).count() << " milliseconds\n" ;
                    }
                    break;
                }
                    //============================================================================
                case 4:
                {
                    cout<<"Sample array before sorting: \n";
                    printArray(sample,20);
                    cout<<"Sample array after sorting: \n";
                    bubbleSort(sample,20);
                    printArray(sample,20);
                    for (int & i : input)
                    {
                        int array[i];
                        generateRandom(array, i);
                        auto start = high_resolution_clock::now();
                        bubbleSort(array, i);
                        auto stop = high_resolution_clock::now();
                        auto diff = (stop - start);
                        cout << "Time taken by function for: "<< i << " is " << duration<float, milli>(diff).count() << " milliseconds\n" ;
                    }
                    break;
                }
                case 5:
                {
                    cout<<"Sample array before sorting: \n";
                    printArray(sample,20);
                    cout<<"Sample array after sorting: \n";
                    selectionSort(sample,20);
                    printArray(sample,20);
                    for (int & i : input)
                    {
                        int array[i];
                        generateRandom(array, i);
                        auto start = high_resolution_clock::now();
                        selectionSort(array, i);
                        auto stop = high_resolution_clock::now();
                        auto diff = (stop - start);
                        cout << "Time taken by function for: "<< i << " is " << duration<float, milli>(diff).count() << " milliseconds\n" ;
                    }
                    break;
                }
                    //============================================================================
                case 6:
                {
                    cout<<"Sample array before sorting: \n";
                    printArray(sample,20);
                    cout<<"Sample array after sorting: \n";
                    quickSort(sample,0,20);
                    printArray(sample,20);
                    for (int & i : input)
                    {
                        int array[i];
                        generateRandom(array, i);
                        auto start = high_resolution_clock::now();
                        quickSort(array, 0,i);
                        auto stop = high_resolution_clock::now();
                        auto diff = (stop - start);
                        cout << "Time taken by function for: "<< i << " is " << duration<float, milli>(diff).count() << " milliseconds\n" ;
                    }
                    break;
                }
                    //================================================================
                case 7:
                {
                    cout<<"Sample array before sorting: \n";
                    printArray(sample,20);
                    cout<<"Sample array after sorting: \n";
                    shellSort(sample,20);
                    printArray(sample,20);
                    for (int & i : input)
                    {
                        int array[i];
                        generateRandom(array, i);
                        auto start = high_resolution_clock::now();
                        shellSort(array, i);
                        auto stop = high_resolution_clock::now();
                        auto diff = (stop - start);
                        cout << "Time taken by function for: "<< i << " is " << duration<float, milli>(diff).count() << " milliseconds\n" ;
                    }
                    break;
                }
            }
        }
    }
}
int main()
{
    {
        using namespace sort;
        sort::generateRandomArray<int>();
    }
}
