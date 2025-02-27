#pragma once  

#include <vector>
#include <iostream>

/* *****************************************
*   @brief Selecting Sort: 
*           Time Complexity: O(n^2)
*           Auxiliary Space: O(1)
*   @param arrays 要被排列的目標陣列
*   @param cmp    比較大小的函數指標
*   @param void   不用回傳任何值
* ****************************************** */
void SelectingSort(std::vector<int>& arrays, bool (*cmp)(int, int)) {

    int n = (int)arrays.size();
    int min_idx;

    for (int i = 0; i < n - 1; ++i) {

        min_idx = i;
        for (int j = i + 1; j < n; ++j) {

            if (cmp(arrays[j], arrays[min_idx])) {
                min_idx = j;
            }

        }

        std::swap(arrays[i], arrays[min_idx]);

    }

}

int Index(std::vector<int>& arrays, int i, int j, bool(*cmp)(int, int)) {

    if (i == j) return i;

    int k = Index(arrays, i + 1, j, cmp);

    return (cmp(arrays[i], arrays[k])) ? i : k;

}

void RecursiveSelectSort(std::vector<int>& arrays, bool (*cmp)(int, int), int index = 0) {

    int n = (int)arrays.size();

    if (index == n) return;

    int k = Index(arrays, index, n - 1, cmp);

    if (k != index) std::swap(arrays[k], arrays[index]);

    RecursiveSelectSort(arrays, cmp, index + 1);

}


/* *****************************************
*   @brief Selecting Sort: 
*           Time Complexity: O(n^2)
*           Auxiliary Space: O(1)
*   @param arrays 要被排列的目標陣列
*   @param cmp    比較大小的函數指標
*   @return void  不用回傳任何值
* ****************************************** */
void BubbleSort(std::vector<int>& arrays, bool (*cmp)(int, int)) {

    int n = (int)arrays.size();
    bool swapped;

    for (int i = 0; i < n - 1; ++i) {
        
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {

            if (cmp(arrays[j + 1], arrays[j])) {

                std::swap(arrays[j + 1], arrays[j]);
                swapped = true;
                std::cout << arrays[j] << ", " << arrays[j + 1] << std::endl;
            }
        }
        std::cout << std::endl;
        if (!swapped) break;
    }

}

void RecursiveBubbleSort(std::vector<int>& arrays, bool (*cmp)(int, int), int index = 0) {

    if (index == arrays.size() - 1) return;
    
    
    for (int i = index; i >= 0; --i) {
        
        if (cmp(arrays[i + 1], arrays[i])) {
            
            std::swap(arrays[i + 1], arrays[i]);

        }
        
    }
    
    RecursiveBubbleSort(arrays, cmp, index + 1);
    
}