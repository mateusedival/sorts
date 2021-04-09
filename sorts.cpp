#include "sorts.h"

namespace sorts {
    void mergesort(std::vector<int> &list, int low, int high) {
        if(low < high) {
            int mid = (high+low)/2;
            mergesort(list, low, mid);
            mergesort(list, mid+1, high);
            merge(list, low, mid, high);
        }
    }

    void merge(std::vector<int> &list, int low, int mid, int high) {

        int i = low;
        int j = mid+1;
        int length = high - low + 1;
        int idx = 0;

        int *temp = new int[length];
        while(i <= mid && j <= high )
        {
            if(list[i] < list[j])
            {
                temp[idx] = list[i];
                i++, idx++;
            }
            else
            {
                temp[idx] = list[j];
                j++, idx++;
            }
        }
        while(i <= mid)
        {
            temp[idx] = list[i];
            i++,idx++;
        }
        while(j <= high)
        {
            temp[idx] = list[j];
            j++,idx++;
        }

        for(int z = low; z <= high; z++)
        {
            list[z] = temp[z-low];
        }
        delete[] temp;
    }

    void heapify(vector<int> &arr, int n, int i)
    {
        int largest = i; // Initialize largest as root
        int l = 2 * i + 1; // left = 2*i + 1
        int r = 2 * i + 2; // right = 2*i + 2
    
        // If left child is larger than root
        if (l < n && arr[l] > arr[largest])
            largest = l;
    
        // If right child is larger than largest so far
        if (r < n && arr[r] > arr[largest])
            largest = r;
    
        // If largest is not root
        if (largest != i) {
            swap(arr[i], arr[largest]);
    
            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }
    }
    
    // main function to do heap sort
    void heapSort(vector<int> &arr, int n)
    {
        // Build heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);
    
        // One by one extract an element from heap
        for (int i = n - 1; i >= 0; i--) {
            // Move current root to end
            swap(arr[0], arr[i]);
    
            // call max heapify on the reduced heap
            heapify(arr, i, 0);
        }
    }

    void swap(int* a, int* b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }
    
    /* This function takes last element as pivot, places
    the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
    to left of pivot and all greater elements to right
    of pivot */
    int partition (vector<int> &arr, int low, int high)
    {
        int pivot = arr[high]; // pivot
        int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
    
        for (int j = low; j <= high - 1; j++)
        {
            // If current element is smaller than the pivot
            if (arr[j] < pivot)
            {
                i++; // increment index of smaller element
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        return (i + 1);
    }
    
    /* The main function that implements QuickSort
    arr[] --> Array to be sorted,
    low --> Starting index,
    high --> Ending index */
    void quickSort(vector<int> &arr, int low, int high)
    {
        if (low < high)
        {
            /* pi is partitioning index, arr[p] is now
            at right place */
            int pi = partition(arr, low, high);
    
            // Separately sort elements before
            // partition and after partition
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

}