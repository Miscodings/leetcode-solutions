#include <vector>
#include <string>
using namespace std;

// 438. Find All Anagrams in a String

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int>res;

        if (m > n) {
            return res;
        }

        vector<int> pCount(26, 0), window(26, 0);

        for (char character : p) {
            pCount[character - 'a']++;
        }

        for (int i = 0; i < n; i++) {
            window[s[i] - 'a']++;

            if (i >= m) {
                window[s[i - m] - 'a']--;
            }

            if (window == pCount) {
                res.push_back(i - m + 1);
            }
        }

        return res;
    }
};