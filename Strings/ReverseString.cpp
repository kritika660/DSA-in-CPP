/**************************************************************
 * Problem: Reverse Words in a String
 * Link: https://leetcode.com/problems/reverse-words-in-a-string/
 * Difficulty: Medium
 * 
 * Problem Statement:
 * Given an input string s, reverse the order of the words.
 * A word is defined as a sequence of non-space characters.
 * The words in s will be separated by at least one space.
 * 
 * Example:
 * Input:  "the sky is blue"
 * Output: "blue is sky the"
 * 
 * Constraints:
 * - 1 <= s.length <= 10^4
 * - s contains English letters, digits, symbols, and spaces.
 * - There is at least one word in s.
 * 
 * ------------------------------------------------------------
 * Approach 1: Brute Force (Using Extra Space)
 * ------------------------------------------------------------
 * Steps:
 *  1. Use stringstream to extract words from the string.
 *  2. Store words in a vector.
 *  3. Reverse the vector.
 *  4. Join words with a single space.
 * 
 * Time Complexity: O(n)  [Splitting + Joining]
 * Space Complexity: O(n) [For storing words in vector]
 **************************************************************/

#include <bits/stdc++.h>
using namespace std;

string reverseWordsBruteForce(string s) {
    stringstream ss(s);
    string word;
    vector<string> words;

    // Extract words while ignoring extra spaces
    while (ss >> word) {
        words.push_back(word);
    }

    // Reverse the vector of words
    reverse(words.begin(), words.end());

    // Join words with a space
    string result;
    for (int i = 0; i < words.size(); i++) {
        result += words[i];
        if (i != words.size() - 1)
            result += " ";
    }

    return result;
}

/**************************************************************
 * Approach 2: Optimal (In-Place Reversal)
 * ------------------------------------------------------------
 * Steps:
 *  1. Remove leading and trailing spaces.
 *  2. Reverse the entire string.
 *  3. Reverse each individual word back to restore word order.
 * 
 * Example:
 *  s = "  sky is blue  "
 *  Step 1 -> "sky is blue"
 *  Step 2 -> "eulb si yks"
 *  Step 3 -> "blue is sky"
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)  [In-place operations]
 **************************************************************/

string reverseWordsOptimal(string s) {
    // Step 1: Remove leading/trailing spaces
    int n = s.size();
    int left = 0, right = n - 1;

    while (left <= right && s[left] == ' ') left++;
    while (right >= left && s[right] == ' ') right--;

    string trimmed = s.substr(left, right - left + 1);

    // Step 2: Reverse entire string
    reverse(trimmed.begin(), trimmed.end());

    // Step 3: Reverse each word within the string
    int start = 0;
    for (int end = 0; end <= trimmed.size(); end++) {
        if (end == trimmed.size() || trimmed[end] == ' ') {
            reverse(trimmed.begin() + start, trimmed.begin() + end);
            start = end + 1;
        }
    }

    // Step 4: Remove extra spaces between words
    string result;
    stringstream ss(trimmed);
    string word;
    while (ss >> word) {
        if (!result.empty()) result += " ";
        result += word;
    }

    return result;
}

/**************************************************************
 * Test the functions
 **************************************************************/
int main() {
    vector<string> testCases = {
        "the sky is blue",
        "  hello world  ",
        "a good   example",
        "  Vishnu   Gupta  Rocks "
    };

    cout << "=== Brute Force Approach ===\n";
    for (auto &s : testCases) {
        cout << "Input: \"" << s << "\"\n";
        cout << "Output: \"" << reverseWordsBruteForce(s) << "\"\n\n";
    }

    cout << "=== Optimal In-Place Approach ===\n";
    for (auto &s : testCases) {
        cout << "Input: \"" << s << "\"\n";
        cout << "Output: \"" << reverseWordsOptimal(s) << "\"\n\n";
    }

    return 0;
}

/**************************************************************
 * Notes:
 * - The brute force solution is easier to write and debug.
 * - The optimal approach saves space and demonstrates
 *   understanding of in-place string manipulation.
 * 
 * Recommended Usage:
 * - Use the optimal approach for interviews or large input sizes.
 **************************************************************/
