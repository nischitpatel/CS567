#include "LinkedList.h"
#include <iostream>

using namespace std;

Node::Node(int value) {
    data = value;
    next = nullptr;
}

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    deleteLinkedList();
}

/*
    Function to get the head of the linked list.
    Input: none
    Output: head of the linked list.
    Time complexity: O(1)
    Space complexity: O(1)

*/
Node* LinkedList::getHead() {
    return head;
}

/*
    Function to get the tail of the linked list.
    Input: none
    Output: tail of the linked list.
    Time complexity: O(n)
    Space complexity: O(1)
*/
Node* LinkedList::getTail() {
    Node* temp = head;
    while (temp != nullptr && temp->next != nullptr) {
        temp = temp->next;
    }
    return temp;
}

/*
    Function to get the length of the linked list.
    Input: none
    Output: length of the linked list.
    Time complexity: O(n)
    Space complexity: O(1)
*/
int LinkedList::length() {
    int length = 0;
    Node* temp = head;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }
    return length;
}

/*
    Function to get the index of the nth node in the linked list.
    Input: pointer to the nth node.
    Output: index of the nth node.
    Time complexity: O(n)
    Space complexity: O(1)
*/
int LinkedList::getNthNodeIndex(Node* nthnode) {
    Node* temp = head;
    int index = 0;
    while (temp != nullptr) {
        if (temp == nthnode) {
            return index;
        }
        index++;
        temp = temp->next;
    }
    return -1;
}

int LinkedList::getIndexFromEnd(Node* nthFromEnd) {
    Node* temp = head;
    int index = 0;
    while (temp != nullptr) {
        if (temp == nthFromEnd) {
            return index;
        }
        index++;
        temp = temp->next;
    }
    return -1;
}

/*
    Function to add a new node to the end of the linked list.
    Input: integer value to be added to the linked list.
    Output: none
    Time complexity: O(n)
    Space complexity: O(1)
*/
void LinkedList::addNode(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

/*
    Function to delete a node from the linked list.
    Input: integer value to be deleted from the linked list.
    Output: none
    Time complexity: O(n)
    Space complexity: O(1)
*/
void LinkedList::deleteNode(int value, Node* head) {
    if (head == nullptr)
        return;

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next != nullptr) {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
}

/*
    Function to reverse the linked list.
    Input: none
    Output: none
    Time complexity: O(n)
    Space complexity: O(1)
*/
void LinkedList::reverseLinkedList() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

/*
    Function to find the middle node of the linked list.
    Input: head of the linked list.
    Output: middle node of the linked list.
    Time complexity: O(n)
    Space complexity: O(1)
*/
Node* LinkedList::findMiddleNode(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    Node* slow = head;
    Node* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

/*
    Function to delete the linked list.
    Input: none
    Output: none
    Time complexity: O(n)
    Space complexity: O(1)
*/
void LinkedList::deleteLinkedList() {
    Node* current = head;
    Node* next;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

/*
    Function to print the linked list.
    Input: none
    Output: none
    Time complexity: O(n)
    Space complexity: O(1)
*/
void LinkedList::printLinkedList() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

/*
    Function to merge two sorted linked lists.
    Input: heads of two sorted linked lists.
    Output: head of the merged sorted linked list.
    Time complexity: O(n)
    Space complexity: O(1)

*/
Node* LinkedList::merge(Node* left, Node* right) {
    Node* result = nullptr;
    if (left == nullptr)
        return right;
    if (right == nullptr)
        return left;

    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

/*
    Function to perform merge sort on the linked list.
    Input: head of the linked list.
    Output: head of the sorted linked list.
    Time complexity: O(n log n)
    Space complexity: O(log n)
*/
Node* LinkedList::mergeSort(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    Node* middle = findMiddleNode(head);
    Node* nextToMiddle = middle->next;

    middle->next = nullptr;

    Node* left = mergeSort(head);
    Node* right = mergeSort(nextToMiddle);

    return merge(left, right);
}

/*
    Function to sort the linked list.
    Input: none
    Output: none
    Time complexity: O(n log n)
    Space complexity: O(log n)
*/
void LinkedList::sortLinkedList() {
    head = mergeSort(head);
}

/*
    Function to perform binary search on the linked list.
    Input: integer key to search for.
    Output: true if key is found, false otherwise.
    Time complexity: O(n)
    Space complexity: O(1)
*/
bool LinkedList::binarySearch(int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key)
            return true;
        current = current->next;
    }
    return false;
}

/*
    Function to get the nth node from the beginning of the linked list.
    Input: integer index of the node.
    Output: pointer to the nth node from the beginning.
    Time complexity: O(n)
    Space complexity: O(1)
*/
Node* LinkedList::getNthNode(int index) {
    if (index < 0)
        return nullptr;

    Node* current = head;
    int count = 0;
    while (current != nullptr) {
        if (count == index)
            return current;
        current = current->next;
        count++;
    }
    return nullptr; // Index out of bounds
}

/*
    Function to get the nth node from the end of the linked list.
    Input: integer n representing the distance from the end.
    Output: pointer to the nth node from the end.
    Time complexity: O(n)
    Space complexity: O(1)
*/
Node* LinkedList::getNthFromEnd(int n) {
    if (n <= 0 || head == nullptr)
        return nullptr;

    Node* fast = head;
    Node* slow = head;

    // Move fast pointer to the nth node from the beginning
    for (int i = 0; i < n; ++i) {
        if (fast == nullptr)
            return nullptr; // n is greater than the size of the list
        fast = fast->next;
    }

    // Move both pointers simultaneously until fast reaches the end
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

/*
    Function to rotate the linked list to the right by k steps.
    Input: integer k representing the number of steps to rotate.
    Output: none
    Time complexity: O(n)
    Space complexity: O(1)
*/
void LinkedList::rotate(int k) {
    if (head == nullptr || k <= 0)
        return;

    int size = 1;
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
        size++;
    }

    // Adjust k if it's larger than the size of the list
    k %= size;

    if (k == 0)
        return; // No rotation needed

    // Make the list circular
    current->next = head;

    // Move current to the (size - k)th node
    for (int i = 0; i < size - k; ++i) {
        current = current->next;
    }

    // Update head and break the circular structure
    head = current->next;
    current->next = nullptr;
}

/*
    Function to merge two sorted linked lists.
    Input: heads of two sorted linked lists.
    Output: head of the merged sorted linked list.
    Time complexity: O(n)
    Space complexity: O(1)
*/
Node* LinkedList::mergeSortedLists(Node* list1, Node* list2) {
    if (list1 == nullptr)
        return list2;
    if (list2 == nullptr)
        return list1;

    Node* mergedList = nullptr;
    
    if (list1->data <= list2->data) {
        mergedList = list1;
        mergedList->next = mergeSortedLists(list1->next, list2);
    } else {
        mergedList = list2;
        mergedList->next = mergeSortedLists(list1, list2->next);
    }
    
    return mergedList;
}

/*
    Function to check if the linked list has a loop.
    Input: none
    Output: true if the linked list has a loop, false otherwise.
    Time complexity: O(n)
    Space complexity: O(1)
*/
bool LinkedList::hasLoop() {
    if (head == nullptr || head->next == nullptr)
        return false;

    Node* slow = head;
    Node* fast = head->next; // Move fast pointer one step ahead initially

    while (fast != nullptr && fast->next != nullptr) {
        if (slow == fast)
            return true; // Loop detected

        slow = slow->next;          // Move slow pointer one step
        fast = fast->next->next;    // Move fast pointer two steps
    }

    return false; // No loop found
}

/*
    Function to remove duplicates from the linked list.
    Input: none
    Output: none
    Time complexity: O(n)
    Space complexity: O(n)
*/
void LinkedList::removeDuplicates() {
    if (head == nullptr || head->next == nullptr)
        return; // No duplicates to remove for empty list or list with only one node

    std::unordered_set<int> seen_values; // Hash set to store seen values
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        // If the value is already in the set, remove the current node
        if (seen_values.find(current->data) != seen_values.end()) {
            prev->next = current->next;
            delete current;
            current = prev->next; // Move to the next node
        } else {
            // Add the value to the set if it's not already there
            seen_values.insert(current->data);
            prev = current;
            current = current->next;
        }
    }
}

/*
    Function to swap pairs of nodes in the linked list.
    Input: head of the linked list.
    Output: head of the linked list after swapping pairs.
    Time complexity: O(n)
    Space complexity: O(1)
*/
Node* LinkedList::swapPairs(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head; // No need to swap if the list has zero or one node

    Node* dummy = new Node(0); // Dummy node to handle edge cases
    dummy->next = head;
    Node* prev = dummy;

    while (prev->next != nullptr && prev->next->next != nullptr) {
        Node* first = prev->next;
        Node* second = prev->next->next;

        // Swapping nodes
        first->next = second->next;
        second->next = first;
        prev->next = second;

        // Move to the next pair of nodes
        prev = first;
    }

    head = dummy->next;
    delete dummy;

    return head;
}