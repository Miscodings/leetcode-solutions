#include <vector>
#include <string>
using namespace std;

// 151. Reverse Words in a String

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word;

        int n = s.size();
        int i = 0;

        while (i < n && s[i] == ' ') i++;

        while (i < n) {
            word.clear();
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }
            if (!word.empty())
                words.push_back(word);

            while (i < n && s[i] == ' ') i++;
        }

        reverse(words.begin(), words.end());

        string result;
        for (int j = 0; j < words.size(); ++j) {
            if (j > 0) result += ' ';
            result += words[j];
        }

        return result;
    };
};
