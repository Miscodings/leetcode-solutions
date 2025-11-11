using namespace std;
#include <vector>
#include <map>
#include <unordered_map>

// 347. Top K Frequent Elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int n : nums) 
            freq[n]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (auto& [num, count] : freq) {
            minHeap.push({count, num});
            if (minHeap.size() > k)
                minHeap.pop();
        }

        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};