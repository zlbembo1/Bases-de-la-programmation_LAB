#include <iostream>
#include <vector>
#include <algorithm>

class MedianFinder {
private:
    std::vector<int> numbers;

public:
    void addNumber(int num) {
        numbers.push_back(num);
    }

    double calculateMedian() const {
        std::vector<int> sortedNumbers = numbers;
        std::sort(sortedNumbers.begin(), sortedNumbers.end());

        int size = sortedNumbers.size();

        if (size % 2 == 0) {
            // If the size is even, average the middle two numbers
            return (sortedNumbers[size / 2 - 1] + sortedNumbers[size / 2]) / 2.0;
        } else {
            // If the size is odd, return the middle number
            return sortedNumbers[size / 2];
        }
    }
};

int main() {
    MedianFinder median;

    // Input numbers from the user
    int num;
    std::cout << "Enter numbers (enter a non-numeric value to finish):" << std::endl;
    while (std::cin >> num) {
        median.addNumber(num);
    }

    // Calculate and display the median
    std::cout << "Median: " <<median.calculateMedian()<<std::endl;
}
