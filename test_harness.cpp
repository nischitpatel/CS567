#include <deepstate/DeepState.hpp>
#include "LinkedList.h"

using namespace deepstate;

#define MAX_VALUE 100
#define MAX_LENGTH 10

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
