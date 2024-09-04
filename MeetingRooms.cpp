/********************************************************************
Check if all meetings can be attended without overlaps.
Example:
Input: [[10, 20], [5, 15], [20, 30]]
Output: false
Explanation:
Overlapping meetings [10, 20] and [5, 15].
*********************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

bool canAttendMeetings(std::vector<std::vector<int>>& intervals) {
    if (intervals.empty()) return true;

    std::sort(intervals.begin(), intervals.end());

    for (size_t i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] < intervals[i - 1][1]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<std::vector<int>> meetings = {{10, 20}, {5, 15}, {20, 30}};
    bool result = canAttendMeetings(meetings);
    std::cout << (result ? "true" : "false") << std::endl;
    return 0;
}

