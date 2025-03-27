#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:

    /*
        vector<int> twoSum(vector<int>& nums, int target) {
            for (size_t i = 0; i < nums.size(); i++) {
                for (size_t j = i + 1; j < nums.size(); j++) {
                    if (nums[i] + nums[j] == target) {
                        vector<int> ans = {static_cast<int>(i), static_cast<int>(j)};
                        return ans;
                    }
                }
            }
            return {};
        };
    */

        vector<int> twoSum(vector<int>& nums, int target) {
            // Logic: Iterate one-by-oe through the array, find the complement needed to hit the target, then check if already seen.
            unordered_map<int, int> seen;

            for (int i = 0; i < nums.size(); ++i) {
                int complement = target - nums[i];
                if (seen.count(complement)) {   // see if complement is there or not
                    return {seen[complement], i};
                } 
                seen[nums[i]] = i;          // either way, add it to hashmap
            }
            return {};
        };
};

/*
  new things i learned:
  - .count -> just counts how many times a parameter shows up, or, in the case of an unordered_map,
    it'll return either 0 (not there) or 1 (there))

  - my original code was o(n^2) due to that nested loop

  - best way to handle this is to throw a hash map at it
*/