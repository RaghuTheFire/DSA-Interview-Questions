/*************************************************************
Merge k sorted linked lists.
Example:
Input: [[1, 2, 3], [2, 4, 6], [5, 8, 9]]
Output: [1, 2, 2, 3, 4, 5, 6, 8, 9]
Explanation:
Lists merged in sorted order
**************************************************************/
#include <iostream>
#include <vector>
#include <queue>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Compare 
{
public:
    bool operator() (ListNode* a, ListNode* b) 
    {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    std::priority_queue<ListNode*, std::vector<ListNode*>, Compare> minHeap;
    for (ListNode* list : lists) {
        if (list) {
            minHeap.push(list);
        }
    }

    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (!minHeap.empty()) {
        ListNode* node = minHeap.top();
        minHeap.pop();
        tail->next = node;
        tail = tail->next;
        if (node->next) {
            minHeap.push(node->next);
        }
    }

    return dummy.next;
}

void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);

    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    ListNode* list3 = new ListNode(5);
    list3->next = new ListNode(8);
    list3->next->next = new ListNode(9);

    std::vector<ListNode*> lists = {list1, list2, list3};
    ListNode* mergedList = mergeKLists(lists);
    printList(mergedList);

    return 0;
}

