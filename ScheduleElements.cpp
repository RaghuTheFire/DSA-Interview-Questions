/***********************************************************
Determine if all courses can be finished.
Example:
Input: numCourses = 3, prerequisites = [[1, 0], [2, 1]]
Output: true
Explanation:
Courses can be finished in order
************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> inDegree(numCourses, 0);
    unordered_map<int, vector<int>> graph;

    for (const auto& prereq : prerequisites) {
        graph[prereq[1]].push_back(prereq[0]);
        inDegree[prereq[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;
    while (!q.empty()) {
        int course = q.front();
        q.pop();
        count++;

        for (int nextCourse : graph[course]) {
            inDegree[nextCourse]--;
            if (inDegree[nextCourse] == 0) {
                q.push(nextCourse);
            }
        }
    }

    return count == numCourses;
}

int main() {
    int numCourses = 3;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 1}};
    cout << (canFinish(numCourses, prerequisites) ? "true" : "false") << endl;
    return 0;
}

