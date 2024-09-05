/******************************************************************************
Find the longest common prefix in an array of strings.
Example:
Input: ["interview", "interval", "integrate"]
Output: "inte"
Explanation:
Longest common prefix is "inte".
******************************************************************************/
#include <iostream>
#include <vector>
#include <string>

std::string longestCommonPrefix(const std::vector<std::string>& strs) 
{
    if (strs.empty()) return "";
    std::string prefix = strs[0];
    for (size_t i = 1; i < strs.size(); ++i) 
    {
        while (strs[i].find(prefix) != 0) 
        {
            prefix = prefix.substr(0, prefix.size() - 1);
            if (prefix.empty()) return "";
        }
    }
    return prefix;
}

int main() 
{
    std::vector<std::string> strs = {"interview", "interval", "integrate"};
    std::string result = longestCommonPrefix(strs);
    std::cout << "Longest common prefix: " << result << std::endl;
    return 0;
}

