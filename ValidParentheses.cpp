/**************************************************************************************
Check if a string of parentheses is valid.
Example:
Input: s = "({[()]})"
Output: true
Explanation:
All parentheses are closed correctly.
**************************************************************************************/
#include <iostream>
#include <stack>
#include <unordered_map>

bool isValid(const std::string& s) {
    std::stack<char> stack;
    std::unordered_map<char, char> mapping = {{')', '('}, {']', '['}, {'}', '{'}};

    for (char ch : s) {
        if (mapping.count(ch)) {
            char topElement = stack.empty() ? '#' : stack.top();
            if (topElement != mapping[ch]) {
                return false;
            }
            stack.pop();
        } else {
            stack.push(ch);
        }
    }
    return stack.empty();
}

int main() {
    std::string s = "({[()]})";
    if (isValid(s)) {
        std::cout << "Output: true" << std::endl;
    } else {
        std::cout << "Output: false" << std::endl;
    }
    return 0;
}

