/*****************************************************************
Find the median of two sorted arrays with main.
Example:
Input: nums1 = [2, 5], nums2 = [3, 4]
Output: 3.5
Explanation:
Median is 3.5.
******************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) 
{
    std::vector<int> merged;
    merged.reserve(nums1.size() + nums2.size());
    merged.insert(merged.end(), nums1.begin(), nums1.end());
    merged.insert(merged.end(), nums2.begin(), nums2.end());
    std::sort(merged.begin(), merged.end());

    int n = merged.size();
    if (n % 2 == 0) 
    {
        return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
    } 
    else 
    {
        return merged[n / 2];
    }
}

int main() 
{
    std::vector<int> nums1 = {2, 5};
    std::vector<int> nums2 = {3, 4};
    double median = findMedianSortedArrays(nums1, nums2);
    std::cout << "Median: " << median << std::endl;
    return 0;
}

