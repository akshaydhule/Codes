/**
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings s and t are isomorphic if the characters in s can be replaced to get t.
 * 
 * All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
 * 
 * Example 1:
 * Input: s = "egg", t = "add"
 * Output: true
 * Example 2:
 * Input: s = "foo", t = "bar"
 * Output: false
 * Example 3:
 * Input: s = "paper", t = "title"
 * Output: true
 * 
 * Constraints:
 * 1 <= s.length <= 5 * 104
 * t.length == s.length
 * s and t consist of any valid ascii character.
 */

class Solution {
public:
    /**
    1. check if s-t is mapped, if yes, check if match with current char
    2. check if 
    */
    bool isIsomorphic(string s, string t) {
        bool visitedT[256];
        char visitedS[256];
        memset(visitedT, 0, sizeof(visitedT));
        memset(visitedS, -1, sizeof(visitedS));
        for (int i = 0; i<s.size(); i++) {
            auto c = s[i];
            auto d = t[i];
            if (visitedS[c] != -1) {
                if (visitedS[c] != d) {
                    return false;
                }
            } else {
                if (visitedT[d] != 0) {
                    return false;
                }
                visitedS[c] = d;
                visitedT[d] = true;
            }
        }
        return true;
    }
};
