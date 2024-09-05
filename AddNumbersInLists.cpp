/***************************************************************
Add two numbers represented as linked lists.
Example:
Input: l1 = [4, 5, 6], l2 = [3, 9, 8]
Output: [7, 4, 5, 1]
Explanation:
654 + 893 = 1547.
*****************************************************************/
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* p = l1, * q = l2, * current = dummy;
    int carry = 0;

    while (p != nullptr || q != nullptr || carry != 0) {
        int x = (p != nullptr) ? p->val : 0;
        int y = (q != nullptr) ? q->val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        current->next = new ListNode(sum % 10);
        current = current->next;

        if (p != nullptr) p = p->next;
        if (q != nullptr) q = q->next;
    }

    return dummy->next;
}

void printList(ListNode* node) {
    while (node != nullptr) {
        std::cout << node->val;
        if (node->next != nullptr) std::cout << " -> ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* l1 = new ListNode(4);
    l1->next = new ListNode(5);
    l1->next->next = new ListNode(6);

    ListNode* l2 = new ListNode(3);
    l2->next = new ListNode(9);
    l2->next->next = new ListNode(8);

    ListNode* result = addTwoNumbers(l1, l2);
    printList(result);

    return 0;
}

