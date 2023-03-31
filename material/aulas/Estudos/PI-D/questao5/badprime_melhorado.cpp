#include <iostream>
#include <cmath>

bool main(int x) {
    if (x <= 1) {
        return false;
    }

    if (x <= 3) {
        return true;
    }

    if (x % 2 == 0 || x % 3 == 0) {
        return false;
    }

    int limit = std::sqrt(x);
    for (int i = 5; i <= limit; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}