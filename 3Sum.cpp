/********************************************************
Find unique triplets that sum to zero.
Example:
Input: [3, -1, -4, -2, 2, -5]
Output: [[-5, 3, 2], [-2, -1, 3]]
Explanation:
Unique triplets are [-5, 3, 2] and [-2, -1, 3].
*********************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::set<std::vector<int>> uniqueTriplets;
    std::sort(nums.begin(), nums.end());
    
    for (size_t i = 0; i < nums.size(); ++i) {
        int left = i + 1;
        int right = nums.size() - 1;
        
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                uniqueTriplets.insert({nums[i], nums[left], nums[right]});
                ++left;
                --right;
            } else if (sum < 0) {
                ++left;
            } else {
                --right;
            }
        }
    }
    
    return std::vector<std::vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());
}

int main() {
    std::vector<int> nums = {3, -1, -4, -2, 2, -5};
    std::vector<std::vector<int>> result = threeSum(nums);
    
    for (const auto& triplet : result) {
        std::cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]\n";
    }
    
    return 0;
}

