/*****************************************************
Find two indices that sum to the target.
Example:
Input: [1, 8, 11, 15], target = 9
Output: [0, 1]
Explanation:
1 + 8 = 9
******************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> numMap;
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i};
        }
        numMap[nums[i]] = i;
    }
    return {};
}

int main() {
    std::vector<int> nums = {1, 8, 11, 15};
    int target = 9;
    std::vector<int> result = twoSum(nums, target);
    std::cout << "[" << result[0] << ", " << result[1] << "]" << std::endl;
    return 0;
}
