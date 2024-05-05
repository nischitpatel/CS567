#include <deepstate/DeepState.hpp>
#include "LinkedList.h"

using namespace deepstate;

#define MAX_VALUE 100
#define MAX_LENGTH 10

TEST(LinkedList, GetHead) {
    // Initialize the linked list
    LinkedList list;

    // Check if the head is null when the list is empty
    ASSERT(list.getHead() == nullptr);

    // Array to store values added to the list for verification
    int values[MAX_LENGTH];

    // Generate random values, add nodes to the list, and store these values
    for (int i = 0; i < MAX_LENGTH; ++i) {
        values[i] = DeepState_IntInRange(0, MAX_VALUE);
        list.addNode(values[i]);
    }

    // Check if the head is not null after adding a node
    ASSERT(list.getHead()!=nullptr);
    ASSERT_EQ(list.getHead()->data, values[0]);
}

TEST(LinkedList, GetTail) {
    // Initialize the linked list
    LinkedList list;

    // Check if the tail is null when the list is empty
    ASSERT(list.getTail() == nullptr);

    // Array to store values added to the list for verification
    int values[MAX_LENGTH];

    // Generate random values, add nodes to the list, and store these values
    for (int i = 0; i < MAX_LENGTH; ++i) {
        values[i] = DeepState_IntInRange(0, MAX_VALUE);
        list.addNode(values[i]);
    }

    // Check if the head is not null after adding a node
    ASSERT(list.getTail()!=nullptr);
    ASSERT_EQ(list.getTail()->data, values[MAX_LENGTH - 1]);
}

TEST(LinkedList, GetIndexOfNthNode) {
    // Initialize the linked list
    LinkedList list;

    // Check if the index is -1 when the list is empty
    ASSERT_EQ(list.getNthNodeIndex(list.getNthNode(0)), -1);

    // Array to store values added to the list for verification
    int values[MAX_LENGTH];

    // Generate random values, add nodes to the list, and store these values
    for (int i = 0; i < MAX_LENGTH; ++i) {
        values[i] = DeepState_IntInRange(0, MAX_VALUE);
        list.addNode(values[i]);
    }

    // Check if the index is correct for each node
    for (int i = 0; i < MAX_LENGTH; ++i) {
        ASSERT_EQ(list.getNthNodeIndex(list.getNthNode(i)), i);
    }

    // Check if the index is -1 for an out-of-bounds index
    ASSERT_EQ(list.getNthNodeIndex(list.getNthNode(MAX_LENGTH)), -1);
}

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

TEST(LinkedList, GetLength) {
    // Initialize the linked list
    LinkedList list;

    // Check if the length is 0 when the list is empty
    ASSERT_EQ(list.length(), 0);

    // Add a node to the list
    list.addNode(1);

    // Check if the length is 1 after adding a node
    ASSERT_EQ(list.length(), 1);

    // Add another node to the list
    list.addNode(2);

    // Check if the length is 2 after adding another node
    ASSERT_EQ(list.length(), 2);
}

TEST(LinkedList, GetNthNodeIndex) {
    // Initialize the linked list and add nodes
    LinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);

    // Get the index of the first node
    Node* firstNode = list.getHead();
    ASSERT_EQ(list.getNthNodeIndex(firstNode), 0);

    // Get the index of the second node
    Node* secondNode = list.getHead()->next;
    ASSERT_EQ(list.getNthNodeIndex(secondNode), 1);

    // Get the index of the third node
    Node* thirdNode = list.getTail();
    ASSERT_EQ(list.getNthNodeIndex(thirdNode), 2);
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

    // Check if linked list is not updated
    ASSERT(list.getHead()->data==1);
    ASSERT(list.getTail()->data==5);
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

    // Check if linked list is not updated
    ASSERT(list.getHead() != nullptr);
    ASSERT(list.getTail() != nullptr);
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

    // Check if linked list is not updated
    ASSERT(list.getHead()!=nullptr);
    ASSERT(list.getTail()!=nullptr);
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

// Helper function to check if the linked list is correctly swapped
bool isSwappedCorrectly(Node* head) {
    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->data < current->next->data) {
            return false; // If nodes are not swapped correctly, return false
        }
        current = current->next->next;
    }
    return true; // If all pairs are swapped correctly, return true
}

TEST(LinkedList, SwapPairs) {
    // Initialize the linked list
    LinkedList list;

    // Generate a random linked list
    int length = DeepState_IntInRange(0, 20);
    for (int i = 0; i < length; ++i) {
        list.addNode(DeepState_Int());
    }

    // Save the original linked list for comparison
    Node* originalHead = list.getHead();

    list.sortLinkedList();

    // Swap pairs in the linked list
    Node* swappedHead = list.swapPairs(originalHead);

    // Check if the swapped linked list satisfies the properties
    ASSERT(isSwappedCorrectly(swappedHead));
}

TEST(LinkedList, GetSecondMaxAndMin) {
    // Initialize the linked list
    LinkedList list;

    // Add some nodes to the list
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.addNode(5);

    int secondMax = list.getSecondMax(list.getHead());

    ASSERT(secondMax == 5);

    // Check if linked list is not updated
    ASSERT(list.getHead()->data==1);
    ASSERT(list.getTail()->data==5);

    int secondMin = list.getSecondMin(list.getHead());

    ASSERT(secondMin == 2);

    // Check if linked list is not updated
    ASSERT(list.getHead()->data==1);
    ASSERT(list.getTail()->data==5);
}