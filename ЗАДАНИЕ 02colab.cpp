#include <iostream>
#include <vector>

class Solution {
public:
    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int indexDiff, int valueDiff) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (j - i <= indexDiff && std::abs(static_cast<long>(nums[i]) - nums[j]) <= valueDiff) {
                    return true;
                }
                if (j - i > indexDiff) {
                    break;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = { 1, 5, 9, 1, 5, 9};
    int indexDiff = 2;
    int valueDiff = 3;
    std::cout << "Contains nearby almost duplicate: " << std::boolalpha << solution.containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff) << std::endl;

    return 0;
}
