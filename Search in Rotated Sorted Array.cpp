/*************************************************************************
Find the index of a target in a rotated sorted array.
Example:
Input: nums = [5, 6, 7, 0, 1, 2, 3], target = 6
Output: 1
Explanation:
Index of 6 is 1.
**************************************************************************/



#include <iostream>
#include <vector>

int search(std::vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;
        }
        
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    
    return -1;
}

int main() {
    std::vector<int> nums = {5, 6, 7, 0, 1, 2, 3};
    int target = 6;
    int index = search(nums, target);
    std::cout << "Index of " << target << " is " << index << std::endl;
    return 0;
}

