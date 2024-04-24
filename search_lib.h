/*
    By: Nischit Patel
*/

/* Preprocessor directives */
#ifndef SEARCH_LIB
#define SEARCH_LIB

#include <stdio.h>
#include <stdlib.h>

/* constants definition */
#define NOT_FOUND -1
#define SPECIFIER "%ld"

/* type definitions */
typedef long int dtype;
typedef struct node{
    dtype data;
    int index;
    struct node* next;
}Node;
 
/* function headers */
int getFirstOccurrence(dtype element, Node *myList);
int getLastOccurrence(dtype element, Node *myList);
Node* getAllOccurrencesRet(dtype element, Node *myList, int *n);
Node* getData(const char *file);
void saveData(const char *file, Node *myList);
Node* sortData(Node *myList);
Node* mergeSort(Node *myList);
Node* merge(Node *head1, Node *head2);
Node* binarySearch(Node *head, Node *tail, dtype value);
/* Supporting functions */
Node *getMid(Node *myList);
void deleteList(Node *myList);
/* Functions addEnd() and printLinkedList used from practise 2*/
Node* addEnd(dtype element, Node *mylist);
void printLinkedList(Node *list);


#endif  // end SEARCH_LIB