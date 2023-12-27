#include <iostream>
#include <queue>
#include <vector>

class MedianFinder {
public:
    std::priority_queue<double> maxheap;
    std::priority_queue<double, std::vector<double>, std::greater<double>> minheap;

    MedianFinder() {

    }

    void addNum(int num) {
        maxheap.push(num);
        if (!maxheap.empty() && !minheap.empty() && maxheap.top() > minheap.top()) {
            double temp = maxheap.top();
            maxheap.pop();
            minheap.push(temp);
        }
        if (maxheap.size() > minheap.size() + 1) {
            double temp = maxheap.top();
            maxheap.pop();
            minheap.push(temp);
        }
        if (minheap.size() > maxheap.size() + 1) {
            double temp = minheap.top();
            minheap.pop();
            maxheap.push(temp);
        }
    }

    double findMedian() {
        if (maxheap.size() > minheap.size()) return maxheap.top();
        if (minheap.size() > maxheap.size()) return minheap.top();
        return (maxheap.top() + minheap.top()) / 2;
    }
};

int main() {
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    std::cout << "Median: " << obj->findMedian() << std::endl;
    obj->addNum(3);
    std::cout << "Median: " << obj->findMedian() << std::endl;

    return 0;
}
