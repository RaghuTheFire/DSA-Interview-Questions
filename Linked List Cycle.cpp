/*****************************************************
Detect if a linked list has a cycle.
Example:
Input: head = [1, 2, 3, 4], pos = 1
Output: true
Explanation:
Cycle exists where tail connects to 1st node.
******************************************************/
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head) {
    if (!head) return false;
    ListNode *slow = head;
    ListNode *fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next; // Creating a cycle

    if (hasCycle(head)) {
        std::cout << "Output: true" << std::endl;
    } else {
        std::cout << "Output: false" << std::endl;
    }

    // Clean up memory (not reachable due to cycle)
    return 0;
}

