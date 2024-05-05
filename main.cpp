#include "LinkedList.h"
#include <iostream>

int main() {
    // Create a linked list
    LinkedList list;

    // Add some elements to the list
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.addNode(5);

    // Print the original list
    std::cout << "Original List: ";
    list.printLinkedList();

    // Test deleteNode function
    list.deleteNode(3, list.getHead());
    std::cout << "List after deleting node with value 3: ";
    list.printLinkedList();

    // Test reverseLinkedList function
    std::cout << "Reversed List: ";
    list.reverseLinkedList();
    list.printLinkedList();

    // Test findMiddleNode function
    Node* middleNode = list.findMiddleNode(list.getHead());
    if (middleNode != nullptr)
        std::cout << "Middle Node: " << middleNode->data << std::endl;

    // Test sortLinkedList function
    list.sortLinkedList();
    std::cout << "Sorted List: ";
    list.printLinkedList();

    // Test binarySearch function
    int key = 4;
    if (list.binarySearch(key))
        std::cout << key << " found in the list." << std::endl;
    else
        std::cout << key << " not found in the list." << std::endl;

    // Test getNthNode function
    int index = 2;
    Node* nthNode = list.getNthNode(index);
    if (nthNode != nullptr)
        std::cout << "Node at index " << index << ": " << nthNode->data << std::endl;

    // Test rotate function
    int k = 2;
    std::cout << "List after rotating right by " << k << " places: ";
    list.rotate(k);
    list.printLinkedList();

    // Test removeDuplicates function
    list.addNode(3);
    list.addNode(2);
    list.addNode(4);
    list.addNode(1);
    list.addNode(3);
    std::cout << "List before removing duplicates: ";
    list.printLinkedList();
    list.removeDuplicates();
    std::cout << "List after removing duplicates: ";
    list.printLinkedList();

    // Test swapPairs function
    std::cout << "List after swapping pairs: ";
    list.swapPairs(list.getHead());
    list.printLinkedList();

    // Pause before exiting
    std::cout << "\nPress any key to exit...";
    std::cin.get();
    
    return 0;
}
