#include "vector.hpp"

int pesquisarVector(vector<float> v, float numero){ // Busca Binária

    int low = 0;
    int high = v.size() - 1;

	// Repeat until the pointers low and high meet each other
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (v.at(mid) == numero)
          return mid;

        if (v.at(mid) < numero)
          low = mid + 1;

        else
          high = mid - 1;
    }

    return -1;
}
