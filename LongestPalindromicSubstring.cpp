/*************************************************
Find the longest palindromic substring.
Example:
Input: "cbbd"
Output: "bb"
Explanation:
"bb" is the longest palindromic substring.
**********************************************/
#include <iostream>
#include <string>

std::string longestPalindrome(const std::string& s) {
    int start = 0, maxLength = 1;
    int n = s.length();

    for (int i = 0; i < n; ++i) {
        // Check for odd length palindromes
        int left = i, right = i;
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLength) {
                start = left;
                maxLength = right - left + 1;
            }
            --left;
            ++right;
        }

        // Check for even length palindromes
        left = i;
        right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLength) {
                start = left;
                maxLength = right - left + 1;
            }
            --left;
            ++right;
        }
    }

    return s.substr(start, maxLength);
}

int main() {
    std::string input = "cbbd";
    std::string result = longestPalindrome(input);
    std::cout << "Longest palindromic substring: " << result << std::endl;
    return 0;
}
