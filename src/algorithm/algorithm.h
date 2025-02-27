#pragma once 

#ifdef _WIN32

    #ifdef ALGORITHM_EXPORTS 

        #define ALGORITHM_API __declspec(dllexport)

    #else 

        #define ALGORITHM_API __declspec(dllimport)

    #endif 

#else

    #define ALGORITHM_API

#endif
#include <array>
#include <vector>
#include <stdexcept>

template <typename T, int M, int N>
class Matrix {
private:

    const int row = M;
    const int col = N;
    std::array<std::array<T, N>, M> n_data;

public:

    ALGORITHM_API Matrix();
    ALGORITHM_API Matrix(const Matrix& other);
    ALGORITHM_API Matrix(std::array<std::array<T, N>, M> data);
    ALGORITHM_API ~Matrix();
    
    void ALGORITHM_API setValue(int r, int c, T value);
    T ALGORITHM_API getValue(int r, int c) const;
    std::pair<int, int> ALGORITHM_API showSize() const;

};

template ALGORITHM_API class Matrix<int, 3, 3>;
using mat3x3I = Matrix<int, 3, 3>;

template class Matrix<int, 4, 4>;
using  mat4x4 = Matrix<int, 4, 4>;

