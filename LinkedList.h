#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <unordered_set>

class Node {
public:
    int data;
    Node* next;
    Node(int value);
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList();
    ~LinkedList();
    Node* getHead();
    Node* getTail();
    int length();
    void addNode(int value);
    void deleteNode(int value);
    void reverseLinkedList();
    Node* findMiddleNode(Node* head);
    void deleteLinkedList();
    void printLinkedList();
    Node* merge(Node* left, Node* right);
    Node* mergeSort(Node* head);
    void sortLinkedList();
    bool binarySearch(int key);
    Node* getNthNode(int index);
    Node* getNthFromEnd(int n);
    void rotate(int k);
    Node* mergeSortedLists(Node* list1, Node* list2);
    bool hasLoop();
    void removeDuplicates();
    Node* swapPairs(Node* head);
    Node* rotateRight(Node* head, int k);
    int getNthNodeIndex(Node* nthnode);
    int getIndexFromEnd(Node* nthFromEnd);
};

#endif // LINKEDLIST_H
