#pragma once 
#include <vector>
#include <cmath>
#include <algorithm>

/// @brief "線性搜索(Linear Search) O(N)"
/// @tparam T 
/// @param arrays 
/// @param key 
/// @return index;

template <typename T>
int LinearSearch(std::vector<T>& arrays, T key) {

    for (int i = 0; i < arrays.size(); i++) {
        if (arrays[i] == key) {
            return i;
        }
    }

    return -1;

}


/// @brief "二分搜索(Binary Search) O(log N)" 
/// @tparam T 
/// @param arrays 
/// @param low 
/// @param high 
/// @param key 
/// @return 
template <typename T>
int BinarySearch(std::vector<T>& arrays, int low, int high, T key) {

// Iterative version
    /*while (low <= high) {

        int mid = low + (high - low) / 2;
        std::cout << arrays[mid] << '\n';
        if (arrays[mid] == key) return mid;

        if(arrays[mid] < key) low = mid + 1;
        else                    high = mid - 1;

    }*/

// Recursive version
    if (low > high) return -1;

    int mid = low + (high - low) / 2;

    if (arrays[mid] == key) return mid;

    if (arrays[mid] > key) return BinarySearch(arrays, low, mid - 1, key);
    
    return BinarySearch(arrays, mid + 1, high, key);
    

}

/// @brief "哨兵搜索(Sentinel Linear Search) O(N)"
/// @tparam T 
/// @param arrays 
/// @param key 
/// @return 
template <typename T>
int SentinelSearch(std::vector<T>& arrays, T key) {

    int last = arrays.back();
    
    arrays.back() = key;
    
    int i = 0;

    while (arrays[i] != key) i++;

    arrays.back() = last;

    return ((i < arrays.size() - 1) || (arrays.back() == key)) ? i : -1;

}

/// @brief "元二分搜索/單邊二分搜索(Meta Binary Search / One-Sided Binary Search) O(log N)"
/// @tparam T 
/// @param arrays 
/// @param key 
/// @return index
template <typename T>
int MetaBinarySearch(std::vector<T> arrays, T key) {

    const int n = (int)arrays.size();
    const int lg = (int)log2(n - 1) + 1;

    int position = 0;

    for (int i = lg; i >= 0; i--) {

        if (arrays[position] == key) 
            return position;

        int new_position = position | (1 << i);

        if ((new_position < n) && (arrays[new_position] <= key))
            position = new_position;

    }

    return (arrays[position] == key) ? position : -1;   

}

/// @brief "三元搜索(Tenary Search) O(log3 N)"
/// @tparam T 
/// @param arrays 
/// @param leftmost 
/// @param rightmost 
/// @param key 
/// @return 
template <typename T>
int TenarySearch(std::vector<T> arrays, int leftmost, int rightmost, T key) {
// Recursive version 
    /*if (leftmost > rightmost) return -1;

    int mid1 = leftmost + (rightmost - leftmost) / 3;
    int mid2 = rightmost - (rightmost - leftmost) / 3;

    if (arrays[mid1] == key) return mid1;
    if (arrays[mid2] == key) return mid2;

    if      (arrays[mid1] > key) return TenarySearch(arrays, leftmost, mid1 - 1, key);
    else if (arrays[mid2] < key) return TenarySearch(arrays, mid2 + 1, rightmost, key);
    else                         return TenarySearch(arrays, mid1 + 1, mid2 - 1, key); */

// Iterative version
    
    int mid1, mid2;

    while (leftmost <= rightmost) {

        mid1 = leftmost + (rightmost - leftmost) / 3;
        mid2 = rightmost - (rightmost - leftmost) / 3;
        
        if (arrays[mid1] == key) return mid1;
        if (arrays[mid2] == key) return mid2;
        
        if (arrays[mid1] > key) {

            rightmost = mid1 - 1;
        }
        else if (arrays[mid2] < key) {
            
            leftmost = mid2 + 1; 
        }
        else {
            leftmost = mid1 + 1;
            rightmost = mid2 - 1;
        }                            
    }

    return -1;

}

/// @brief "跳躍搜索(Jump Search) O(N)"
/// @tparam T 
/// @param arrays 
/// @param size 
/// @param key 
/// @return 
template <typename T>
int JumpSearch(std::vector<T> arrays, int size, T key) {

    int step = (int)sqrt(size);

    int prev = 0;
    while (arrays[std::min(step, size) - 1] < key) {
        prev = step;
        step += step;
        if (prev >= size) return -1;
    }

    while (arrays[prev] < key) {
        prev++;

        if (prev == std::min(step, size)) return -1;
    } 

    if (arrays[prev] == key) return prev;

    return -1;

}

/// @brief "插值搜索(Interpolation Search) O(N)"
/// @tparam T 
/// @param arrays 
/// @param low 
/// @param high 
/// @param key 
/// @return 
template <typename T>
int InterpolationSearch(std::vector<T> arrays, int low, int high, T key) {

    // Recursive version
    /*int position;

    if (low <= high && key >= arrays[low] && key <= arrays[high]) {

        position = low + (((double)(high - low) / (arrays[high] - arrays[low])) * (key - arrays[low]));

        if (arrays[position] == key) return position;

        if (arrays[position] < key) 
            return InterpolationSearch(arrays, position + 1, high, key);
        else
            return InterpolationSearch(arrays, low, position - 1, key);

    }

    return -1; */

    // Iterative version

    int position;

    while (low < high && key >= arrays[low] && key <= arrays[high]) {

        position = low + (int)(((double)(high - low) / (arrays[high] - arrays[low])) * (key - arrays[low]));

        if (arrays[position] == key) return position;

        if (arrays[position] < key) low = position + 1;
        else                        high = position - 1;

    }

    return -1;

}

/// @brief "指數搜索(Exponential Search) O(log N)"
/// @tparam T 
/// @param arrays 
/// @param size 
/// @param key 
/// @return 
template <typename T>
int ExponetialSearch(std::vector<T> arrays, int size, T key) {

    // Using binary version

    /* if (arrays[0] == key) return 0;

    int position = 1;
    while (position < size && arrays[position] <= key) 
        position = position * 2;

    return BinarySearch(arrays, position / 2, std::min(position, size - 1), key); */

    // Iterative version

    if (size == 0) return -1;

    int position = 1;
    while (position < size && arrays[position] <= key) 
        position *= 2;
    
    int low = position / 2;
    int high = std::min(position, size - 1);

    while (low <= high) {

        int mid = (low + high) / 2;

        if (arrays[mid] == key) return mid;
        else if (arrays[mid] < key) low = mid + 1;
        else                        high = mid - 1;

    }

    return -1;
}

/// @brief "費波納契搜索 O(log N)"
/// @tparam T 
/// @param arrays 
/// @param size 
/// @param key 
/// @return 
template <typename T>
int FibonacciSearch(std::vector<T> arrays, int size, T key) {

    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;

    while (fibM < size) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;
    int i;

    while (fibM > 1) {

        i = std::min(offset + fibMMm2, size - 1);

        if (arrays[i] < key) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if (arrays[i] > key) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else return i;

    }

    if (fibMMm1 && arrays[offset + 1] == key) return offset + 1;

    return -1;

}



