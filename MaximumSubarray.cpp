/**********************************************************************
Find the subarray with the largest sum.
Example:
Input: nums = [-2, 3, -1, 5, -3, 2]
Output: 7
Explanation:
Subarray [3, -1, 5] has the largest sum = 7.
***********************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

int maxSubArray(const std::vector<int>& nums) 
{
    int max_sum = nums[0];
    int current_sum = nums[0];

    for (size_t i = 1; i < nums.size(); ++i) 
    {
        current_sum = std::max(nums[i], current_sum + nums[i]);
        max_sum = std::max(max_sum, current_sum);
    }

    return max_sum;
}

int main() 
{
    std::vector<int> nums = {-2, 3, -1, 5, -3, 2};
    std::cout << maxSubArray(nums) << std::endl;
    return 0;
}

