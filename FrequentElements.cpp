/************************************************
Find k most frequent elements in an array.
Example:
Input: [4, 4, 4, 5, 5, 3], k = 2
Output: [4, 5]
Explanation:
Top 2 frequent elements are 4 and 5
**************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    for (int num : nums) {
        count[num]++;
    }

    priority_queue<pair<int, int>> pq;
    for (auto& it : count) {
        pq.push({it.second, it.first});
    }

    vector<int> result;
    for (int i = 0; i < k; i++) {
        result.push_back(pq.top().second);
        pq.pop();
    }

    return result;
}

int main() {
    vector<int> nums = {4, 4, 4, 5, 5, 3};
    int k = 2;
    vector<int> result = topKFrequent(nums, k);
    
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}

