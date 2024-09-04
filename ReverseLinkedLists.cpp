/**********************************************************
Reverse a singly linked list.
Example:
Input: 7 -> 14 -> 21 -> 28 -> NULL
Output: 28 -> 21 -> 14 -> 7 -> NULL
Explanation:
Linked list is reversed.
************************************************************/
#include <iostream>

struct Node 
{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* reverseList(Node* head) 
{
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    
    while (current != nullptr) 
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void printList(Node* head) 
{
    while (head != nullptr) 
    {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

int main() 
{
    Node* head = new Node(7);
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);
    
    std::cout << "Original List: ";
    printList(head);
    
    head = reverseList(head);
    
    std::cout << "Reversed List: ";
    printList(head);
    
    return 0;
}

