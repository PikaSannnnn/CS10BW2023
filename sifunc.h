#pragma once

#include <iostream>
#include <vector>
#include <limits.h>
#include <exception>
using std::vector;
using std::cout;
using std::endl;

// A few functions we've all coded together-ish in SI. Please note that you can use any of these functions on SI content ONLY!
// Do not use these functions, the code, etc. on anything outside of SI as it will be considered stealing content and academic dishonesty!
// Cheating is not worth it, but what is worth it is learning how these work and knowing how to actually code.

// To use, just make sure you either state you're using or prepend namespace:: in front of everything

// #pragma GCC poison InsertSort

namespace vecsif {
    template <typename T>
    void FillVector(vector<T>& v, int n) {
        for (size_t i = 0; i < n; i++) {
            v.push_back();
        }
    }

    template <typename T>
    void PrintVector(const vector<T>& v, char delim = ' ', bool endline = true) {
        for (auto i : v) {
            cout << i;
            if (i != v.end()) cout << delim;
        }
        if (endline) { cout << endl; }
    }
}

namespace arrsif {

}

namespace lstsif {

}

namespace sortsif {
    template <typename T>
    vector<T> InsertSort(vector<T>& v, bool inplace = false) {
        vector<T> sorted;
        return sorted;
    }
    template <typename T>
    T* InsertSort(T arr[], int n, bool inplace = false) {
        return nullptr;
    }
}

namespace compsif {
    template <typename T>
    T Max(const T& a, const T& b) {
        return (a > b) ? a : b;
    }
    template <typename T>
    T Max(const T arr[]) {
        size_t n = sizeof(arr) / sizeof(T);
        if (n == 0) throw std::range_error("compsif::Max(const T arr[]) cannot search in empty array");

        T b = arr[0];
        for (size_t i = 1; i < n; i++) {
            if (arr[i] > b) b = arr[i];
        }

        return b;
    }
}