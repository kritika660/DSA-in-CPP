/*
Problem: Palindrome Number
Link: https://leetcode.com/problems/palindrome-number/
Difficulty: Easy

Approach:
- Negative numbers cannot be palindromes (as '-' cannot appear at the end).
- Reverse the number using arithmetic operations.
- Compare the reversed number with the original.
- Use long long to prevent overflow during reversal.

Time Complexity: O(log₁₀(n))  // Number of digits in n
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false; // Negative numbers can’t be palindromes
        
        long long rev = 0;
        long long temp = x;

        while (temp != 0) {
            rev = (rev * 10) + (temp % 10);
            temp = temp / 10;
        }

        return rev == x;
    }
};

int main() {
    Solution sol;
    int x;

    cout << "Enter a number: ";
    cin >> x;

    if (sol.isPalindrome(x)) {
        cout << x << " is a palindrome." << endl;
    } else {
        cout << x << " is not a palindrome." << endl;
    }

    return 0;
}


