/**********************************************
Merge multiple sorted linked lists.
Example:
Input: [[3, 4, 7], [1, 5, 8], [2, 6, 9]]
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9]
Explanation:
Lists merged in sorted order.
************************************************/
#include <iostream>
#include <vector>
#include <queue>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Compare {
public:
    bool operator() (ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(std::vector<std::vector<int>>& lists) {
    std::priority_queue<ListNode*, std::vector<ListNode*>, Compare> minHeap;
    
    for (const auto& list : lists) {
        for (int num : list) {
            minHeap.push(new ListNode(num));
        }
    }
    
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    while (!minHeap.empty()) {
        ListNode* node = minHeap.top();
        minHeap.pop();
        
        if (!head) {
            head = node;
            tail = head;
        } else {
            tail->next = node;
            tail = tail->next;
        }
    }
    
    return head;
}

void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    std::vector<std::vector<int>> input = {{3, 4, 7}, {1, 5, 8}, {2, 6, 9}};
    ListNode* mergedList = mergeKLists(input);
    printList(mergedList);
    return 0;
}

