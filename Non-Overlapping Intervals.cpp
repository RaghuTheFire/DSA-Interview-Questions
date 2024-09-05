/***********************************************************************************
Minimize number of intervals to remove for non-overlapping
intervals.
Example:
Input: [[1, 4], [3, 5], [5, 8]]
Output: 1
Explanation:
Remove [1, 4] to make intervals non-overlapping
***********************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) 
{
    if (intervals.empty()) return 0;

    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) 
    {
        return a[1] < b[1];
    });

    int count = 0;
    int end = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++) 
    {
        if (intervals[i][0] < end) 
        {
            count++;
        } else 
        {
            end = intervals[i][1];
        }
    }

    return count;
}

int main() 
{
    vector<vector<int>> intervals = {{1, 4}, {3, 5}, {5, 8}};
    int result = eraseOverlapIntervals(intervals);
    cout << "Number of intervals to remove: " << result << endl;
    return 0;
}

