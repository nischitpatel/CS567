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

Node* LinkedList::getHead() {
    return head;
}

Node* LinkedList::getTail() {
    Node* temp = head;
    while (temp != nullptr && temp->next != nullptr) {
        temp = temp->next;
    }
    return temp;
}

int LinkedList::length() {
    int length = 0;
    Node* temp = head;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }
    return length;
}

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

void LinkedList::printLinkedList() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

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

void LinkedList::sortLinkedList() {
    head = mergeSort(head);
}

bool LinkedList::binarySearch(int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key)
            return true;
        current = current->next;
    }
    return false;
}

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

int LinkedList::getSecondMax(Node* head) {
    if(head == nullptr) return -1;
    if(head->next == nullptr) return head->data;
    Node* temp = head;
    while(temp->next->next != nullptr) 
        temp = temp->next;
    
    return temp->data;
}

int LinkedList::getSecondMin(Node* head) {
    if(head == nullptr) return -1;
    if(head->next == nullptr) return head->data;
    return head->next->data;
}