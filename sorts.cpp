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

    



}