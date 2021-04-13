#include "sorts.h"

namespace sorts {
    void merge_sort(std::vector<int> &list, int low, int high) {
        if(low < high) {
            int mid = (high+low)/2;
            merge_sort(list, low, mid);
            merge_sort(list, mid+1, high);
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

    void heap_sort(std::vector<int> &a, int n) {
        int i = n / 2, pai, filho, t;
        while(true) {
            if (i > 0) {
                i--;
                t = a[i];
            } else {
                n--;
                if (n <= 0) return;
                t = a[n];
                a[n] = a[0];
            }
            pai = i;
            filho = i * 2 + 1;
            while (filho < n) {
                if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
                    filho++;
                if (a[filho] > t) {
                    a[pai] = a[filho];
                    pai = filho;
                    filho = pai * 2 + 1;
                } else {
                    break;
                }
            }
            a[pai] = t;
        }
    }

    
    void quick_sort(std::vector<int> &Vet, int left, int right) 
    {  int i, j, pivo, y;    
       i= left; 
       j = right;    
       pivo = Vet[(left + right) / 2]; 
       while (i<= j)    
       {       
           while (Vet[i] < pivo && i< right)            
                i++;      
           while (Vet[j] > pivo && j > left)
                j--;      
            if (i<= j)      
            {          
                y = Vet[i];          
                Vet[i] = Vet[j];          
                Vet[j] = y;         
                i++;        
                j--;     
            }  
        }     
        if (j > left)  
        {      
            quick_sort(Vet, left, j);  
        }  
        if (i< right)  
        {
            quick_sort(Vet, i, right);  
        }
    }

}