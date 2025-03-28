#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, char> seen;
        int length = 0;
        int left = 0;

        for (int right = 0; right < s.size(); right++) {
            if (seen.count(s[right])) {
                left = max(left, seen[s[right]] + 1);
            }
            seen[s[right]] = right;         // this overrides whatever seen[s[right]] value was there before
            length = max(length, right - left + 1);
        }
        return length;
    }
};

/*
  notes:
  - super cool system
  - once again uses a hashmap, made the connection from lc-1_twosum.
  - i originally tried clearing the hashmap but theres no need to because line 16 overwrites whatever value was there before
  - imagine a window with a left and right arrow. thats pretty much whats being made here
*/