#include <vector>
using namespace std;

// 238. Product of Array Except Self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> products(nums.size(), 1);
        int prefix = 1;
        int suffix = 1;

        for (int i = 0; i < nums.size(); i++) {
            products[i] = prefix;
            prefix *= nums[i];
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            products[i] *= suffix;
            suffix *= nums[i];
        }
        return products;
    }
};