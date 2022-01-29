/**
 * There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.
 * Given a string text of words separated by a single space (no leading or trailing spaces) and a string brokenLetters
 * of all distinct letter keys that are broken, return the number of words in text you can fully type using this keyboard.
 *
 * Example 1:
 * Input: text = "hello world", brokenLetters = "ad"
 * Output: 1
 * Explanation: We cannot type "world" because the 'd' key is broken.
 *
 * Example 2:
 * Input: text = "leet code", brokenLetters = "lt"
 * Output: 1
 * Explanation: We cannot type "leet" because the 'l' and 't' keys are broken.
 */

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int count = 0, i = 0;
        set<char> brokenList;
        for (int j=0;j<brokenLetters.size();j++) {
            brokenList.insert(brokenLetters[j]);
        }
        bool lastBroken = false;
        while (i<text.size()) {
            // if current letter is space
            // if previous word was correct, add to count
            // else reset all values
            if (text[i] == ' ') {
                if (lastBroken != true) {
                    count += 1;   
                }
                i++;
                lastBroken = false;
            } else if (brokenList.find(text[i]) != brokenList.end()) {
                // if word is broken, skip to next word
                while (i<text.size() && text[i] != ' ') {
                    i++;
                }
                lastBroken = true;
            } else {
                // increment index to continue
                i++;   
            }
        }
        if (lastBroken != true) {
            count += 1;
        }
        return count;
    }
};
