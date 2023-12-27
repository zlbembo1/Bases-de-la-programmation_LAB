#include <iostream>
#include <algorithm>

class Vector {
private:
    int length;
    double* array;

public:
    Vector(int len) {
        length = len;
        array = new double[length];
    }

    Vector(int len, double* arr) {
        length = len;
        array = new double[length];
        std::copy(arr, arr + length, array);
    }

    void sortInc() {
        std::sort(array, array + length);
    }

    void sortNeg() {
        std::sort(array, array + length, [](double a, double b) {
            return (a < 0 && b >= 0);
            });
    }
};

int main() {
    double arr[] = { -2.5, 1.3, -4.7, 3.2, -0.8 };
    int len = sizeof(arr) / sizeof(arr[0]);

    Vector vec1(len);
    Vector vec2(len, arr);

    vec1.sortInc();
    vec2.sortNeg();

    return 0;
}
