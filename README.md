# Linkedlist's code testing using DeepState

## What is a Linked List?
A linked list is a fundamental data structure commonly used in computer science and programming. It consists of a sequence of elements called nodes, where each node contains a piece of data and a reference (or pointer) to the next node in the sequence. The last node typically points to a null reference to indicate the end of the list.

Unlike arrays, linked lists do not store elements in contiguous memory locations. Instead, each node can be located anywhere in memory, and they are connected through pointers.

There are several types of linked lists, including:

1. **Singly linked list**: Each node contains a data element and a pointer to the next node in the sequence.

2. **Doubly linked list**: Each node contains a data element, a pointer to the next node, and a pointer to the previous node, allowing traversal in both forward and backward directions.

3. **Circular linked list**: Similar to a singly or doubly linked list, but the last node points back to the first node, forming a circular structure.

Linked lists offer several advantages and disadvantages compared to other data structures like arrays:

**Advantages:**
- Dynamic size: Linked lists can grow or shrink in size dynamically as elements are added or removed, unlike arrays which have a fixed size.
- Efficient insertions and deletions: Insertions and deletions at arbitrary positions in the list can be done efficiently by adjusting pointers, whereas arrays may require shifting elements.
- No need for contiguous memory: Linked lists can be constructed using non-contiguous memory, allowing for efficient memory usage.

**Disadvantages:**
- No random access: Unlike arrays, linked lists do not support constant-time random access to elements. Accessing an element requires traversing the list from the beginning.
- Additional memory overhead: Linked lists require extra memory for storing pointers, which can increase memory usage compared to arrays, especially for large lists.
- Less cache-friendly: Traversing a linked list may result in poor cache performance due to non-contiguous memory access.

Overall, linked lists are a versatile data structure suitable for various applications, especially when dynamic size and efficient insertions and deletions are required.

## Source code explanation
This repository contains a well-designed implementation of a singly linked list in C++, as well as different operations and algorithms suitable for streamlined management and manipulation of linked data structures. The code covers the main functionalities such as insertion, deletion, and traversal as well as a more advanced functionality that is sorting, searching, and removing duplicates. Each function is skillfully designed to ensure correctness, efficiency and flexibility, allowing for effortless integration into an array of applications. Also, the code undergoes rigorous testing using DeepState, thus, enhancing its efficiency and accuracy in different scenarios. It can be applied in various situations including education, algorithmic exploration, and practical software development for better understanding and utilization of linked data structures in C++. 

### Functions explanation
1. **Node::Node(int value)**: This is a constructor for the Node class. It initializes a Node object with the given value and sets its `next` pointer to `nullptr`.

2. **LinkedList::LinkedList()**: Constructor for the LinkedList class. Initializes the `head` pointer to `nullptr`.

3. **LinkedList::~LinkedList()**: Destructor for the LinkedList class. Calls the `deleteLinkedList()` function to deallocate memory for all nodes in the list.

4. **Node* LinkedList::getHead()**: Returns the pointer to the head node of the linked list.

5. **Node* LinkedList::getTail()**: Returns the pointer to the last node of the linked list.

6. **int LinkedList::length()**: Returns the length of the linked list.

7. **int LinkedList::getNthNodeIndex(Node* nthnode)**: Returns the index of the given node in the linked list. Returns -1 if the node is not found.

8. **void LinkedList::addNode(int value)**: Adds a new node with the given value to the end of the linked list.

9. **void LinkedList::deleteNode(int value, Node* head)**: Deletes the node with the given value from the linked list.

10. **void LinkedList::reverseLinkedList()**: Reverses the linked list in place.

11. **Node* LinkedList::findMiddleNode(Node* head)**: Finds and returns the middle node of the linked list.

12. **void LinkedList::deleteLinkedList()**: Deletes all nodes in the linked list and sets the head pointer to `nullptr`.

13. **void LinkedList::printLinkedList()**: Prints the values of all nodes in the linked list.

14. **Node* LinkedList::merge(Node* left, Node* right)**: Merges two sorted linked lists into a single sorted linked list.

15. **Node* LinkedList::mergeSort(Node* head)**: Sorts the linked list using the merge sort algorithm.

16. **void LinkedList::sortLinkedList()**: Sorts the linked list in non-decreasing order.

17. **bool LinkedList::binarySearch(int key)**: Performs binary search for a key in the sorted linked list.

18. **Node* LinkedList::getNthNode(int index)**: Returns the node at the given index in the linked list.

19. **void LinkedList::rotate(int k)**: Rotates the linked list counter-clockwise by k positions.

20. **void LinkedList::removeDuplicates()**: Removes duplicates from the linked list.

21. **Node* LinkedList::swapPairs(Node* head)**: Swaps adjacent nodes in the linked list.

22. **int LinkedList::getSecondMax(Node* head)**: Returns the second maximum value in the linked list.

23. **int LinkedList::getSecondMin(Node* head)**: Returns the second minimum value in the linked list.
