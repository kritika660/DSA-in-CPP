/*
Problem: Reverse Words in a String
Link: https://leetcode.com/problems/reverse-words-in-a-string/
Difficulty: Medium

Approach:
- Split the input string by spaces into words.
- Remove any extra spaces.
- Reverse the order of the words.
- Join them with a single space.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    // Step 1: Trim and split words
    stringstream ss(s);
    string word;
    vector<string> words;

    while (ss >> word) {
        words.push_back(word);
    }

    // Step 2: Reverse word order
    reverse(words.begin(), words.end());

    // Step 3: Join with space
    string result;
    for (int i = 0; i < words.size(); i++) {
        result += words[i];
        if (i != words.size() - 1)
            result += " ";
    }

    return result;
}

int main() {
    string s = "the Sky is Blue";
    cout << reverseWords(s) << endl; // Output: "blue is sky the"
    return 0;
}