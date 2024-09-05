/****************************************************************
Calculate the amount of trapped rainwater.
Example:
Input: height = [0, 1, 0, 2, 1, 0, 3]
Output: 5
Explanation:
Trapped rainwater units are 5.
****************************************************************/
#include <vector>
#include <iostream>
#include <algorithm>

int trap(std::vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    std::vector<int> left_max(n);
    std::vector<int> right_max(n);
    left_max[0] = height[0];
    right_max[n - 1] = height[n - 1];

    for (int i = 1; i < n; i++) {
        left_max[i] = std::max(left_max[i - 1], height[i]);
    }

    for (int i = n - 2; i >= 0; i--) {
        right_max[i] = std::max(right_max[i + 1], height[i]);
    }

    int trapped_water = 0;
    for (int i = 0; i < n; i++) {
        trapped_water += std::min(left_max[i], right_max[i]) - height[i];
    }

    return trapped_water;
}

int main() {
    std::vector<int> height = {0, 1, 0, 2, 1, 0, 3};
    std::cout << "Trapped rainwater units: " << trap(height) << std::endl;
    return 0;
}

