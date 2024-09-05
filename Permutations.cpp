/********************************************************************************
Return all possible permutations of an array.
Example:
Input: nums = [2, 3, 4]
Output: [[2, 3, 4], [2, 4, 3], [3, 2, 4], [3, 4, 2], [4, 2, 3], [4, 3, 2]]
Explanation:
All permutations of [2, 3, 4].
*********************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

void permute(std::vector<int>& nums, int start, std::vector<std::vector<int>>& result) {
    if (start >= nums.size()) {
        result.push_back(nums);
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        std::swap(nums[start], nums[i]);
        permute(nums, start + 1, result);
        std::swap(nums[start], nums[i]);
    }
}

std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    permute(nums, 0, result);
    return result;
}

int main() {
    std::vector<int> nums = {2, 3, 4};
    std::vector<std::vector<int>> permutations = permute(nums);
    
    for (const auto& perm : permutations) {
        std::cout << "[";
        for (size_t i = 0; i < perm.size(); i++) {
            std::cout << perm[i];
            if (i < perm.size() - 1) std::cout << ", ";
        }
        std::cout << "]\n";
    }
    
    return 0;
}



