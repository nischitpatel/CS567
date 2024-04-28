#include <deepstate/DeepState.hpp>
#include "LinkedList.h"

using namespace deepstate;

#define MAX_VALUE 100
#define MAX_LENGTH 10

TEST(LinkedList, AddNode) {
    LinkedList list;
    int values[MAX_LENGTH];

    for (int i = 0; i < MAX_LENGTH; ++i) {
        values[i] = DeepState_IntInRange(0, MAX_VALUE);
        list.addNode(values[i]);
    }

    ASSERT_EQ(list.length(), MAX_LENGTH);
    Node* current = list.getHead();
    for (int i = 0; i < MAX_LENGTH; ++i) {
        ASSERT(current != nullptr);
        ASSERT_EQ(current->data, values[i]);
        current = current->next;
    }
    ASSERT_EQ(current, nullptr);
}

TEST(LinkedList, DeleteNode) {
    LinkedList list;
    for (int i = 0; i < MAX_LENGTH; ++i) {
        list.addNode(DeepState_IntInRange(0, MAX_VALUE));
    }

    int initialLength = list.length();
    int valueToDelete = list.getNthNode(DeepState_IntInRange(0, initialLength - 1))->data;
    list.deleteNode(valueToDelete, list.getHead());

    ASSERT_FALSE(list.binarySearch(valueToDelete));
    ASSERT_EQ(list.length(), initialLength - 1);
}

TEST(LinkedList, ReverseLinkedList) {
    LinkedList list;
    for (int i = 0; i < MAX_LENGTH; ++i) {
        list.addNode(DeepState_IntInRange(0, MAX_VALUE));
    }

    LinkedList listCopy = list;
    list.reverseLinkedList();

    Node* original = listCopy.getTail();
    Node* reversed = list.getHead();
    while (original != nullptr && reversed != nullptr) {
        ASSERT_EQ(original->data, reversed->data);
        original = original->next;
        reversed = reversed->next;
    }
    ASSERT_EQ(original, nullptr);
    ASSERT_EQ(reversed, nullptr);
}

TEST(LinkedList, FindMiddleNode) {
    LinkedList list;
    for (int i = 0; i < MAX_LENGTH; ++i) {
        list.addNode(DeepState_IntInRange(0, MAX_VALUE));
    }

    Node* middleNode = list.findMiddleNode(list.getHead());
    int midIndex = list.getNthNodeIndex(middleNode);
    ASSERT_TRUE(midIndex == list.length() / 2 || midIndex == (list.length() - 1) / 2);
}

TEST(LinkedList, SortLinkedList) {
    LinkedList list;
    for (int i = 0; i < MAX_LENGTH; ++i) {
        list.addNode(DeepState_IntInRange(0, MAX_VALUE));
    }

    list.sortLinkedList();
    Node* current = list.getHead();
    while (current != nullptr && current->next != nullptr) {
        ASSERT_LE(current->data, current->next->data);
        current = current->next;
    }
}

TEST(LinkedList, BinarySearch) {
    LinkedList list;
    for (int i = 0; i < MAX_LENGTH; ++i) {
        list.addNode(DeepState_IntInRange(0, MAX_VALUE));
    }

    int key = DeepState_IntInRange(0, MAX_VALUE);
    ASSERT_EQ(list.binarySearch(key), list.binarySearch(key));
}

TEST(LinkedList, GetNthNode) {
    LinkedList list;
    for (int i = 0; i < MAX_LENGTH; ++i) {
        list.addNode(DeepState_IntInRange(0, MAX_VALUE));
    }

    int index = DeepState_IntInRange(0, MAX_LENGTH - 1);
    Node* nthNode = list.getNthNode(index);
    ASSERT(nthNode != nullptr);
    ASSERT_EQ(list.getNthNodeIndex(nthNode), index);
}

TEST(LinkedList, Rotate) {
    LinkedList list;
    for (int i = 0; i < MAX_LENGTH; ++i) {
        list.addNode(DeepState_IntInRange(0, MAX_VALUE));
    }

    int k = DeepState_IntInRange(0, MAX_LENGTH - 1);
    list.rotate(k);
    Node* current = list.getHead();
    int count = 0;
    while (count < MAX_LENGTH - k) {
        current = current->next;
        count++;
    }
    ASSERT_EQ(list.getHead()->data, current->data);
}

TEST(LinkedList, MergeSortedLists) {
    LinkedList list1;
    LinkedList list2;
    for (int i = 0; i < MAX_LENGTH; ++i) {
        list1.addNode(DeepState_IntInRange(0, MAX_VALUE));
        list2.addNode(DeepState_IntInRange(0, MAX_VALUE));
    }

    list1.sortLinkedList();
    list2.sortLinkedList();
    Node* mergedList = list1.mergeSortedLists(list1.getHead(), list2.getHead());

    Node* current = mergedList;
    int lastValue = INT_MIN;
    while (current != nullptr) {
        ASSERT_GE(current->data, lastValue);
        lastValue = current->data;
        current = current->next;
    }
}

TEST(LinkedList, HasLoop) {
    LinkedList list;
    for (int i = 0; i < MAX_LENGTH; ++i) {
        list.addNode(DeepState_IntInRange(0, MAX_VALUE));
    }

    ASSERT_FALSE(list.hasLoop());
    Node* tail = list.getTail();
    Node* middleNode = list.findMiddleNode(list.getHead());
    if (tail != nullptr && middleNode != nullptr) {
        tail->next = middleNode;
        ASSERT(list.hasLoop());
    }
}

TEST(LinkedList, RemoveDuplicates) {
    LinkedList list;
    for (int i = 0; i < MAX_LENGTH; ++i) {
        list.addNode(DeepState_IntInRange(0, MAX_VALUE));
    }

    list.removeDuplicates();
    std::unordered_set<int> seenValues;
    Node* current = list.getHead();
    while (current != nullptr) {
        ASSERT(seenValues.find(current->data) == seenValues.end());
        seenValues.insert(current->data);
        current = current->next;
    }
}
