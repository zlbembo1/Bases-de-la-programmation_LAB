#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        if (nums.size() <= 1 || indexDiff <= 0 || valueDiff < 0) {
            return false;
        }

        unordered_map<long long, long long> bucketMap;

        for (int i = 0; i < nums.size(); ++i) {
            long long num = static_cast<long long>(nums[i]);

            // Bucketing to check valueDiff
            long long bucket = num / (static_cast<long long>(valueDiff) + 1);

            // Check for duplicates in the current bucket or neighboring buckets
            if (bucketMap.count(bucket) ||
                (bucketMap.count(bucket - 1) && abs(num - bucketMap[bucket - 1]) <= valueDiff) ||
                (bucketMap.count(bucket + 1) && abs(num - bucketMap[bucket + 1]) <= valueDiff)) {
                return true;
            }

            // If the window size is exceeded, remove the leftmost element from the bucket
            if (i >= indexDiff) {
                long long leftmostBucket = static_cast<long long>(nums[i - indexDiff]) / (static_cast<long long>(valueDiff) + 1);
                bucketMap.erase(leftmostBucket);
            }

            // Add the current element to the bucket
            bucketMap[bucket] = num;
        }

        return false;
    }
};

int main() {
    Solution solution;

    // User input for 'nums'
    int n;
    cout << "Enter the size of nums: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of nums:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int indexDiff, valueDiff;
    cout << "Enter indexDiff: ";
    cin >> indexDiff;

    cout << "Enter valueDiff: ";
    cin >> valueDiff;

    // Call the function
    bool result = solution.containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff);

    cout << (result ? "true" : "false") << endl;

    return 0;
}
