#include <deepstate/DeepState.hpp>
#include "LinkedList.h"

using namespace deepstate;

#define MAX_VALUE 100
#define MAX_LENGTH 10

TEST(LinkedList, AddNode) {
    // Initialize the linked list
    LinkedList list;

    // Generate random values and add nodes to the list
    for (int i = 0; i < MAX_LENGTH; ++i) {
        int value = DeepState_IntInRange(0, MAX_VALUE);
        list.addNode(value);
    }

    // Check the length of the list
    ASSERT(list.length() == MAX_LENGTH);
}

TEST(LinkedList, DeleteNode) {
    // Initialize the linked list
    LinkedList list;

    // Add some nodes to the list
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);

    // Delete a node from the list
    list.deleteNode(2);

    // Check if the node was deleted
    ASSERT(list.length() == 2);
    ASSERT_FALSE(list.search(2));
}

TEST(LinkedList, ReverseLinkedList) {
    // Initialize the linked list
    LinkedList list;

    // Add some nodes to the list
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);

    // Reverse the list
    list.reverseLinkedList();

    // Check if the list is reversed
    ASSERT(list.getHead()->data == 3);
    ASSERT(list.getTail()->data == 1);
}

TEST(LinkedList, FindMiddleNode) {
    // Initialize the linked list
    LinkedList list;

    // Add some nodes to the list
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.addNode(5);

    // Find the middle node
    Node* middleNode = list.findMiddleNode();

    // Check if the middle node is correct
    ASSERT(middleNode->data == 3);
}

TEST(LinkedList, SortLinkedList) {
    // Initialize the linked list
    LinkedList list;

    // Generate random values and add nodes to the list
    for (int i = 0; i < MAX_LENGTH; ++i) {
        int value = DeepState_IntInRange(0, MAX_VALUE);
        list.addNode(value);
    }

    // Sort the list
    list.sortLinkedList();

    // Check if the list is sorted
    Node* current = list.getHead();
    while (current->next != nullptr) {
        ASSERT(current->data <= current->next->data);
        current = current->next;
    }
}

TEST(LinkedList, BinarySearch) {
    // Initialize the linked list
    LinkedList list;

    // Generate random values and add nodes to the list
    for (int i = 0; i < MAX_LENGTH; ++i) {
        int value = DeepState_IntInRange(0, MAX_VALUE);
        list.addNode(value);
    }

    // Choose a random value to search for
    int key = DeepState_IntInRange(0, MAX_VALUE);

    // Perform binary search on the list
    bool found = list.binarySearch(key);

    // Check if the key was found
    if (found) {
        // If the key was found, it should be present in the list
        ASSERT(list.search(key));
    } else {
        // If the key was not found, it should not be present in the list
        ASSERT_FALSE(list.search(key));
    }
}

TEST(LinkedList, GetNthNode) {
    // Initialize the linked list
    LinkedList list;

    // Generate random values and add nodes to the list
    for (int i = 0; i < MAX_LENGTH; ++i) {
        int value = DeepState_IntInRange(0, MAX_VALUE);
        list.addNode(value);
    }

    // Choose a random index
    int index = DeepState_IntInRange(0, MAX_LENGTH - 1);

    // Get the node at the specified index
    Node* nthNode = list.getNthNode(index);

    // Check if the node exists
    if (nthNode != nullptr) {
        // If the node exists, its index should match the specified index
        ASSERT(list.getIndex(nthNode) == index);
    } else {
        // If the node does not exist, the index should be out of bounds
        ASSERT(index >= list.length() || index < 0);
    }
}

TEST(LinkedList, GetNthFromEnd) {
    // Initialize the linked list
    LinkedList list;

    // Generate random values and add nodes to the list
    for (int i = 0; i < MAX_LENGTH; ++i) {
        int value = DeepState_IntInRange(0, MAX_VALUE);
        list.addNode(value);
    }

    // Choose a random value for n
    int n = DeepState_IntInRange(0, MAX_LENGTH - 1);

    // Get the nth node from the end
    Node* nthFromEnd = list.getNthFromEnd(n);

    // Check if the node exists
    if (nthFromEnd != nullptr) {
        // If the node exists, its index from the end should match n
        ASSERT(list.getIndexFromEnd(nthFromEnd) == n);
    } else {
        // If the node does not exist, n should be out of bounds
        ASSERT(n >= list.length() || n < 0);
    }
}

TEST(LinkedList, Rotate) {
    // Initialize the linked list
    LinkedList list;

    // Generate random values and add nodes to the list
    for (int i = 0; i < MAX_LENGTH; ++i) {
        int value = DeepState_IntInRange(0, MAX_VALUE);
        list.addNode(value);
    }

    // Choose a random value for k
    int k = DeepState_IntInRange(0, MAX_LENGTH - 1);

    // Perform rotation on the list
    list.rotate(k);

    // Check if the list is rotated correctly
    int rotatedIndex = (MAX_LENGTH - k) % MAX_LENGTH;
    Node* current = list.getHead();
    int count = 0;
    while (current != nullptr) {
        if (count == rotatedIndex)
            break;
        current = current->next;
        count++;
    }
    // If the list was rotated correctly, the current node should match the original (k-th) node
    ASSERT(current != nullptr && list.getHead()->data == current->data);
}

TEST(LinkedList, MergeSortedLists) {
    // Initialize the linked lists
    LinkedList list1;
    LinkedList list2;

    // Generate random values and add nodes to the lists
    for (int i = 0; i < MAX_LENGTH; ++i) {
        int value1 = DeepState_IntInRange(0, MAX_VALUE);
        int value2 = DeepState_IntInRange(0, MAX_VALUE);
        list1.addNode(value1);
        list2.addNode(value2);
    }

    // Sort the lists
    list1.sortLinkedList();
    list2.sortLinkedList();

    // Merge the sorted lists
    Node* mergedList = list1.mergeSortedLists(list1.getHead(), list2.getHead());

    // Check if the merged list is sorted
    Node* current = mergedList;
    while (current->next != nullptr) {
        ASSERT(current->data <= current->next->data);
        current = current->next;
    }
}

TEST(LinkedList, HasLoop) {
    // Initialize the linked list
    LinkedList list;

    // Generate random values and add nodes to the list
    for (int i = 0; i < MAX_LENGTH; ++i) {
        int value = DeepState_IntInRange(0, MAX_VALUE);
        list.addNode(value);
    }

    // Check if the list has a loop
    ASSERT_FALSE(list.hasLoop());

    // Create a loop in the list
    Node* tail = list.getTail();
    Node* middleNode = list.findMiddleNode();
    if (tail != nullptr && middleNode != nullptr) {
        tail->next = middleNode;
        ASSERT(list.hasLoop());
    }
}

TEST(LinkedList, RemoveDuplicates) {
    // Initialize the linked list
    LinkedList list;

    // Generate random values and add nodes to the list
    for (int i = 0; i < MAX_LENGTH; ++i) {
        int value = DeepState_IntInRange(0, MAX_VALUE);
        list.addNode(value);
    }

    // Remove duplicates from the list
    list.removeDuplicates();

    // Check if the list has no duplicates
    Node* current = list.getHead();
    std::unordered_set<int> uniqueValues;
    bool hasDuplicates = false;
    while (current != nullptr) {
        if (uniqueValues.find(current->data) != uniqueValues.end()) {
            hasDuplicates = true;
            break;
        }
        uniqueValues.insert(current->data);
        current = current->next;
    }
    ASSERT_FALSE(hasDuplicates);
}