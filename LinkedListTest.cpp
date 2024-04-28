#include <deepstate/DeepState.hpp>
#include "LinkedList.h"

using namespace deepstate;

#define MAX_VALUE 100
#define MAX_LENGTH 10

TEST(LinkedList, AddNode) {
    // Initialize the linked list
    LinkedList list;

    // Array to store values added to the list for verification
    int values[MAX_LENGTH];

    // Generate random values, add nodes to the list, and store these values
    for (int i = 0; i < MAX_LENGTH; ++i) {
        values[i] = DeepState_IntInRange(0, MAX_VALUE);
        list.addNode(values[i]);
    }

    // Check the length of the list
    ASSERT_EQ(list.length(), MAX_LENGTH);

    // Verify that the list contains the elements in the correct order
    Node* current = list.getHead();
    for (int i = 0; i < MAX_LENGTH; ++i) {
        ASSERT(current != nullptr); // Ensure the node is not null
        ASSERT_EQ(current->data, values[i]); // Check the value of each node
        current = current->next; // Move to the next node
    }

    // Ensure the list ends correctly
    ASSERT_EQ(current, nullptr); // Current should be nullptr if we've traversed all nodes
}

TEST(LinkedList, DeleteNode) {
    // Initialize the linked list and add nodes
    LinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);

    // Delete the middle node and check immediate list structure and length
    list.deleteNode(2, list.getHead());
    ASSERT(list.length() == 2);

    // Check that the specific node is removed by searching for it
    ASSERT_FALSE(list.binarySearch(2));

    // Ensure the remaining list is still in correct order
    Node* head = list.getHead();
    ASSERT(head != nullptr && head->data == 1);
    ASSERT(head->next != nullptr && head->next->data == 3);
    ASSERT(head->next->next == nullptr);
}

TEST(LinkedList, ReverseLinkedList) {
    // Initialize the linked list
    LinkedList list;

    // Add nodes to the list in a known order
    int initial_values[] = {1, 2, 3};
    for (int value : initial_values) {
        list.addNode(value);
    }

    // Reverse the linked list
    list.reverseLinkedList();

    // Expected values in reversed order
    int reversed_values[] = {3, 2, 1};
    
    // Check if the list is correctly reversed by verifying each node's value
    Node* current = list.getHead();
    int index = 0;
    while (current != nullptr) {
        ASSERT(current->data == reversed_values[index]); // Verify the current node's data
        current = current->next; // Move to the next node
        index++;
    }

    // Ensure the reversed list has the correct length
    ASSERT(list.length() == sizeof(reversed_values) / sizeof(reversed_values[0]));

    // Ensure we have checked all nodes
    ASSERT(index == sizeof(reversed_values) / sizeof(reversed_values[0]));

    // Confirm that the list properly ends
    ASSERT(current == nullptr); // Current should be nullptr after the last node
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
    Node* middleNode = list.findMiddleNode(list.getHead());

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
    while (current && current->next != nullptr) {
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
        ASSERT(list.binarySearch(key));
    } else {
        // If the key was not found, it should not be present in the list
        ASSERT_FALSE(list.binarySearch(key));
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

    // Remove duplicates
    list.removeDuplicates();

    // Choose a random index
    int index = DeepState_IntInRange(0, MAX_LENGTH - 1);

    // Get the node at the specified index
    Node* nthNode = list.getNthNode(index);

    // Check if the node exists
    if (nthNode != nullptr) {
        // If the node exists, its index should match the specified index
        ASSERT(list.getNthNodeIndex(nthNode) == index);
    } else {
        // If the node does not exist, the index should be out of bounds
        ASSERT(index >= list.length() || index < 0);
    }
}

TEST(LinkedList, GetNthFromEnd) {
    // Initialize the linked list
    LinkedList list;

    // Store values for verification
    std::vector<int> values;

    // Generate random values and add nodes to the list
    for (int i = 0; i < MAX_LENGTH; ++i) {
        int value = DeepState_IntInRange(0, MAX_VALUE);
        list.addNode(value);
        values.push_back(value); // Store the value for later verification
    }

    // Choose a random value for n
    int n = DeepState_IntInRange(0, MAX_LENGTH - 1);

    // Get the nth node from the end
    Node* nthFromEnd = list.getNthFromEnd(n);

    // Ensure the nth node from the end is correct by comparing its value
    ASSERT(nthFromEnd != nullptr); // Node should not be nullptr
    ASSERT(nthFromEnd->data == values[values.size() - 1 - n]); // Check the node's data

    // Check if the calculated index from the end matches n
    int calculatedIndexFromEnd = list.length() - 1 - list.getNthNodeIndex(nthFromEnd);
    ASSERT_EQ(calculatedIndexFromEnd, n);
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
    Node* middleNode = list.findMiddleNode(list.getHead());
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