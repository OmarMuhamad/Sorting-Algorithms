#include <iostream>
using namespace std;

namespace sort {
    template<typename Type>
    void countSort(Type array[], int sz) {
		Type result[50000] = { 0 }; // to store the resulted array
		// get the max element in the original array
		Type mx = array[0];
		for (int i = 1; i < sz; i++) {
			if (mx < array[i]) mx = array[i];
		}
		Type cum[50000] = { 0 };
		for (int i = 0; i < sz; i++) {
			cum[array[i]]++;
		}
		for (int i = 1; i <= mx; i++) {
			cum[i] += cum[i - 1];
		}
		for (int i = sz - 1; i >= 0; i--) {
			result[--cum[array[i]]] = array[i];
		}
		for (int i = 0; i < sz; i++) {
			cout << result[i] << endl;
		}
	}
//============================================================================
    template<typename Type>
    void mergeSort() {

    }
//============================================================================
    template<typename Type>
    void insertionSort(Type arr[], int n) {
        Type key;
        int j;
        for (int i = 1; i < n; i++) {
            key = arr[i];
            j = i - 1;
            while (j >= 0 and arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }
//============================================================================
    template<typename Type>
    int partition (Type arr[], int l,int h)
    {
        Type p = arr[l];
        int i = l;
        int j = h;
        while(i<j)
        {
            do {
                i++;
            }while (arr[i] <= p);
            do
            {
                j--;
            }while(arr[j]>p);
            if(i < j)
                swap(arr[i],arr[j]);
        }
        swap(arr[l],arr[j]);
        return j;
    }
    //________________________________________________________________
    template<typename Type>
    void quickSort(Type arr[],int l ,int h)
    {
        if (l < h) {
            int piv = partition(arr, l, h);
            quickSort(arr, l, piv);
            quickSort(arr, piv + 1, h);
        }
    }
//============================================================================
    template<typename Type>
    void bubbleSort(Type arr[],int n)
    {
        for(int i = 0; i< n-1;i++)
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
    void selectionSort() {

    }
//============================================================================
    template<typename Type>
    void shellSort() {

    }
}
//================================================================
using namespace sort;
//================================================================
void print(int arr[] , int n)
{
    for(int i=0; i<n;i++)
        std:: cout <<arr[i]<<" ";
    std:: cout<<endl;
}
//================================================================
int main() {
    int arr[] ={60,40,50,30,10,20};
    int n = sizeof(arr)/sizeof(arr[0]);
//    bubbleSort(arr,n);
//    insertionSort(arr,n);
    quickSort(arr,0,n);
//    cout<<"Array After Bubble Sort : \n";
//    cout  <<"Array After Insertion Sort : \n";
    cout<<"Array After Quick Sort : \n";
    print(arr,n);
}
