#include <iostream>

class vect {
private:
    int dim;
    double* b;
    int num;
    static int count;

public:
    vect(int d, double* arr, int n) : dim(d), b(arr), num(n) {
        std::cout << "Vector created with dimension " << dim << std::endl;
    }

    ~vect() {
        std::cout << "Vector destroyed" << std::endl;
    }

    vect(const vect& other) : dim(other.dim), b(new double[dim]), num(other.num) {
        for (int i = 0; i < dim; ++i) {
            b[i] = other.b[i];
        }
    }

    void print() {
        std::cout << "Vector components: ";
        for (int i = 0; i < dim; ++i) {
            std::cout << b[i] << " ";
        }
        std::cout << std::endl;
    }

    vect operator+(const vect& other) {
        if (dim != other.dim) {
            std::cerr << "Vector dimensions do not match for addition." << std::endl;
            return vect(0, nullptr, 0); // Return an empty vector or handle the error accordingly
        }

        double* result = new double[dim];
        for (int i = 0; i < dim; ++i) {
            result[i] = b[i] + other.b[i];
        }

        return vect(dim, result, num);
    }

    vect operator-() {
        double* result = new double[dim];
        for (int i = 0; i < dim; ++i) {
            result[i] = -b[i];
        }

        return vect(dim, result, num);
    }

    vect& operator=(const vect& other) {
        if (this != &other) {
            dim = other.dim;
            num = other.num;

            delete[] b;
            b = new double[dim];

            for (int i = 0; i < dim; ++i) {
                b[i] = other.b[i];
            }
        }

        return *this;
    }

    double operator*(const vect& other) {
        if (dim != other.dim) {
            std::cerr << "Vector dimensions do not match for dot product." << std::endl;
            return 0.0; // Return 0 or handle the error accordingly
        }

        double dotProduct = 0.0;
        for (int i = 0; i < dim; ++i) {
            dotProduct += b[i] * other.b[i];
        }

        return dotProduct;
    }

    friend vect operator*(double k, const vect& r) {
        double* result = new double[r.dim];
        for (int i = 0; i < r.dim; ++i) {
            result[i] = k * r.b[i];
        }

        return vect(r.dim, result, r.num);
    }
};

int vect::count = 0;

class matr {
private:
    // Define matrix fields

public:
    // Define constructors, destructors, and operator functions for matrix operations
};

int main() {
    double arr1[] = { 1.0, 2.0, 3.0 };
    double arr2[] = { 4.0, 5.0, 6.0 };

    vect v1(3, arr1, 1);
    vect v2(3, arr2, 2);

    vect v3 = v1 + v2; // Vector addition
    v3.print();

    vect v4 = -v3; // Vector negation
    v4.print();

    vect v5 = v1;
    v5.print();

    double dotProduct = v1 * v2; // Vector dot product
    std::cout << "Dot product: " << dotProduct << std::endl;

    vect v6 = 2.0 * v1; // Scalar-vector multiplication
    v6.print();

    return 0;
}

