/**
 * Given a string s, return the longest palindromic substring in s.
 * Example 1:
 * Input: s = "babad"
 * Output: "bab"
 * Explanation: "aba" is also a valid answer.
 * Example 2:
 * 
 * Input: s = "cbbd"
 * Output: "bb"
 * 
 * Constraints:
 * 1 <= s.length <= 1000
 * s consist of only digits and English letters.
 */

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        string output;
        if (s.size() == 0) return output;
        if (s.size() == 1) return s;
        vector<vector<bool>> map(len, vector<bool> (len, false));
        // [i,j] == 1 means palindrome from len i to j
        // 1. set (i,i) true for palindrome of 1
        // 2. iterate through 2D matrix with i-starting from 0 and
        //    j-end from i+1 to len of string for palindrome greater
        //    than 1 len. It only depends on first and last char of this string
        //    to match and string(i+1, j-1) is already true
        for (int i = 0; i < len; i++)  {
            map[i][i] = true;
            output = s[i];
        }
        for (int i = len-1; i>=0; i--) {
            for(int j = i+1; j < len; j++) {
                if (s[i] == s[j]) {
                    if (j-i==1 || map[i+1][j-1] == true) {
                        map[i][j] = true;
                        if (output.size() < j-i+1) {
                            output = s.substr(i, j-i+1);
                        }
                    }
                }
            }
        }
        return output;
    }
};
