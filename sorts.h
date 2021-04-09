#ifndef SORT
#define SORT
#include <vector>
#include <iostream>
#include <algorithm>

namespace sorts {
    void merge_sort(std::vector<int> &list, int low, int high);

    void merge(std::vector<int> &list, int low, int mid, int high);

    void heapify(std::vector<int> &arr, int n, int i);

    void heap_sort(std::vector<int> &arr, int n);

    int partition (std::vector<int> &arr, int low, int high);

    void quick_sort(std::vector<int> &arr, int low, int high);

}

#endif