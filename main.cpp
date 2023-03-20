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
	void mergeOperation(Type array[], int low, int mid, int high) {
	    int sz1 = mid - low + 1, sz2 = high - mid;
	    Type L[sz1];
        Type R[sz2];
        for (int i = 0; i < sz1; i++){
            L[i] = array[low + i];
        }
        for (int i = 0; i < sz2; i++){
            R[i] = array[mid + i + 1];
        }
	    int i, j, k;
	    i = j = 0; k = low;
	    while(i < sz1 and j < sz2){
            if (L[i] < R[j]){
                array[k] = L[i];
                i++;
            }
            else {
                array[k] = R[j];
                j++;
            }
            k++;
	    }
	    while(i < sz1){
            array[k] = L[i];
            k++; i++;
	    }
	    while(j < sz2){
            array[k] = R[j];
            k++; j++;
	    }

	}
	//___________________________________________________________
	template<typename Type>
	void mergeSort(Type array[], int left, int right) {
        if (left < right){
            int mid = left + (right - left) / 2;
            mergeSort(array, left, mid);
            mergeSort(array, mid + 1, right);
            mergeOperation(array, left, mid, right);
        }
        return;
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
