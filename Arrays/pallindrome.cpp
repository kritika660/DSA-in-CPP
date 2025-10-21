/*
Problem: Palindrome Number
Link: https://leetcode.com/problems/palindrome-number/
Difficulty: Easy

------------------------------------------
🧠 Brute Force Approach
------------------------------------------
Approach:
1. Convert the integer into a string using `to_string()`.
2. Use two pointers — one from the start and one from the end — to check if the string reads the same forward and backward.
3. If all corresponding characters match, it's a palindrome.

Example:
Input:  x = 121
String: "121"
Compare: '1' == '1' → continue → middle reached → Palindrome ✅

Time Complexity:  O(log₁₀(n))  → Number of digits in n
Space Complexity: O(log₁₀(n))  → String storage
*/

#include <iostream>
#include <string>
using namespace std;

class BruteForceSolution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false; // Negative numbers can’t be palindromes
        
        string s = to_string(x);
        int left = 0, right = s.size() - 1;
        
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};

/*
------------------------------------------
⚡ Optimal Approach (Mathematical Reversal)
------------------------------------------
Approach:
1. Negative numbers are not palindromes.
2. Reverse the number mathematically without converting to a string.
3. Compare the reversed number with the original.
4. Use long long to prevent overflow during reversal.

Optimization:
- Instead of reversing the entire number, we can reverse only half of it 
  (to reduce the risk of overflow), but here we reverse fully for simplicity.

Example:
Input:  x = 121
Step 1: rev = 0, temp = 121
Step 2: rev = 1  (121 % 10 = 1)
Step 3: rev = 12 (12*10 + 2), temp = 1
Step 4: rev = 121, temp = 0 → Compare (rev == x) → Palindrome ✅

Input: x = -121 → Not palindrome ❌

Time Complexity:  O(log₁₀(n))  → Number of digits in n
Space Complexity: O(1)
*/

class OptimalSolution {
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

/*
------------------------------------------
🔍 Example Test Run
------------------------------------------
Input:  x = 121
Output: 121 is a palindrome.

Input:  x = -121
Output: -121 is not a palindrome.

Input:  x = 10
Output: 10 is not a palindrome.
*/

int main() {
    int x;
    cout << "Enter a number: ";
    cin >> x;

    BruteForceSolution brute;
    OptimalSolution optimal;

    cout << "\n--- Brute Force Approach ---" << endl;
    if (brute.isPalindrome(x))
        cout << x << " is a palindrome." << endl;
    else
        cout << x << " is not a palindrome." << endl;

    cout << "\n--- Optimal Approach ---" << endl;
    if (optimal.isPalindrome(x))
        cout << x << " is a palindrome." << endl;
    else
        cout << x << " is not a palindrome." << endl;

    return 0;
}
