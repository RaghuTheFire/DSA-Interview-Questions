/*********************************************************************
Return an array where each element is the product of all other
elements.
Example:
Input: [5, 6, 2, 4]
Output: [48, 40, 120, 60]
Explanation:
output[0] = 6 * 2 * 4 = 48
output[1] = 5 * 2 * 4 = 40
output[2] = 5 * 6 * 4 = 120
output[3] = 5 * 6 * 2 = 60
**********************************************************************/
#include <iostream>
#include <vector>

std::vector<int> productArray(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> output(n, 1);
    
    int leftProduct = 1;
    for (int i = 0; i < n; i++) {
        output[i] = leftProduct;
        leftProduct *= nums[i];
    }
    
    int rightProduct = 1;
    for (int i = n - 1; i >= 0; i--) {
        output[i] *= rightProduct;
        rightProduct *= nums[i];
    }
    
    return output;
}

int main() {
    std::vector<int> input = {5, 6, 2, 4};
    std::vector<int> result = productArray(input);
    
    for (int num : result) {
        std::cout << num << " ";
    }
    
    return 0;
}

