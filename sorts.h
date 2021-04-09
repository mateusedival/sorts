#ifndef SORT
#define SORT
#include <vector>
#include <iostream>


namespace sorts {
    void mergesort(std::vector<int> &list, int low, int high);

    void merge(std::vector<int> &list, int low, int mid, int high);



}

#endif