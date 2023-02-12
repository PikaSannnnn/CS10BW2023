#pragma once
#include <vector>
using std::vector;

// A few functions we've all coded together-ish in SI. Please note that you can use any of these functions on SI content ONLY!
// Do not use these functions, the code, etc. on anything outside of SI as it will be considered stealing content and academic dishonesty!
// Cheating is not worth it, but what is worth it is learning how these work and knowing how to actually code.

// To use, just make sure you either state you're using or prepend namespace:: in front of everything

// #pragma GCC poison PrintVector

namespace vsif {
    template <typename T>
    void FillVector(vector<T>& v, int n) {
        for (size_t i = 0; i < n; i++) {
            v.push_back();
        }
    }

    template <typename T>
    void PrintVector(const vector<T>& v, char delim = '\n') {
        for (auto i : v) {
            cout << i << delim;
        }
    }
}

namespace asif {

}

namespace lsif {

}