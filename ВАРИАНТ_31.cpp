#include <iostream> 
#include <algorithm> 
#include <vector> 

class Vector {
public:
    int length;
    std::vector<double> elements;

public:
    // Конструкторы 
    Vector(int len) : length(len) {}
    Vector(int len, const std::vector<double>& data) : length(len), elements(data) {}

    // Метод сортировки элементов по возрастанию 
    void sortInc() {
        std::sort(elements.begin(), elements.end());
    }

    // Метод сортировки элементов так, что сначала идут отрицательные компоненты, а затем положительные 
    void sortNeg() {
        std::sort(elements.begin(), elements.end(), [](double a, double b) {
            return (a >= 0) && (b < 0);
            });
    }
};

int main() {
    // Создание объекта класса Vector 
    std::vector<double> data = { 5.2, -3.1, 8.4, -1.7, 2.8 };
    Vector vec(5, data);

    // Тестирование метода sortInc() 
    vec.sortInc();
    std::cout << "Sorted in increasing order: ";
    for (double elem : vec.elements) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Тестирование метода sortNeg() 
    vec.sortNeg();
    std::cout << "Sorted with negative elements first: ";
    for (double elem : vec.elements) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
