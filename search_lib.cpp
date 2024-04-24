/*
    By: Nischit Patel
*/

/* Pre-processors */
#include "search_lib.h"
#include <stdio.h>

/* Constant declaration */
#define outputFileName "sorted_data.csv"
#define TRUE 1
#define FALSE 0
#define NOT_FOUND -1

/* Function implementation */

/*
    Function: getFirstOccurrence()
    Process: Finds the first index of element in a linked list
    Input data (parameter): element - data to be searched
                            *myList - a pointer to a linked list
    Output data(parameter): none
    Output data (return): first_index - index of first occurrence of an element
                          NOT_FOUND(-1) - if element is not present in a linked list
    Dependencies: binarySearch()
    Time complexity: O(log n)
*/
int getFirstOccurrence(dtype element, Node *myList)
{
    /* Variable declaration */
    int first_index = NOT_FOUND, lastNodeIndex;
    Node *head = myList, *tail = myList, *node, *curr = NULL;

    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    node = binarySearch(head, tail, element);

    /* Run until we get first occurrence */
    while (node != NULL)
    {
        curr = node;
        lastNodeIndex = node->index;
        if (node->index <= 0)
        {
            node = NULL;
        }
        else
        {
            node = head;
            while (node->index != lastNodeIndex - 1)
            {
                node = node->next;
            }
            node = binarySearch(head, node, element);
        }
    }

    if (curr != NULL)
        /* Set first_index */
        first_index = curr->index;

    /* Return index of first occurence */
    return first_index;
}

/*
    Function: getLastOccurrence()
    Process: Finds the last index of element in a linked list
    Input data (parameter): element - data to be searched
                            *myList - a pointer to a linked list
    Output data(parameter): none
    Output data (return): last_index - index of last occurrence of an element
                          NOT_FOUND(-1) - if element is not present in a linked list
    Dependencies: binarySearch()
    Time complexity: O(log n)
*/
int getLastOccurrence(dtype element, Node *myList)
{
    /* Variable declaration */
    int last_index = NOT_FOUND;
    Node *head = myList, *tail = myList, *node, *curr;

    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    /* Find required node using binary search algortihm*/
    node = binarySearch(head, tail, element);

    /* Run until we get last occurrence */
    while (node->data == element)
    {
        curr = node;
        node = node->next;
    }

    if (curr != NULL)
        /* Set last_index */
        last_index = curr->index;

    /* Return index of first occurence */
    return last_index;
}

/*
    Function: getAllOccurrencesRet()
    Process: Finds the all indexes where element is present in a linked list
    Input data (parameter): element - data to be searched
                            *myList - a pointer to a linked list
                            *n - pointer to an integer variable where total number of
                                 occurrences will be stored
    Output data(parameter): n - total number of occurrences of an element in a
                                linked list
    Output data (return): node - first node which contains a required data
                          NULL - if there is no node with required data
    Dependencies: getFirstOccurrence()
    Time complexity: O(log n)
*/
Node *getAllOccurrencesRet(dtype element, Node *myList, int *n)
{
    /* Variable declaration */
    Node *node = NULL, *temp = NULL;
    int index;
    *n = 0;

    /* Get index of first node that contains a required data */
    index = getFirstOccurrence(element, myList);

    if (index != NOT_FOUND)
    {
        /* Get the first node */
        node = myList;
        while (node->index != index)
        {
            node = node->next;
        }

        /* Find number of occurrences of a particular data in a list*/
        temp = node;
        while (temp != NULL && temp->data == element)
        {
            *n = *n + 1;
            temp = temp->next;
        }
    }

    /* Return first node */
    return node;
}

/*
    Function: addEnd()
    Process: Adds a node at the end of a linked list
    Input data (parameter): element - data to be added
                            *myList - a pointer to a linked list
    Output data(parameter): none
    Output data (return): head - pointer to a modified linked list
    Dependencies: malloc(), sizeof()
    Time complexity: O(n)
*/
Node *addEnd(dtype element, Node *myList)
{
    /* Variable declarations */
    Node *head = myList, *newNode, *temp;

    /* Allocate a memory to a new node */
    newNode = (Node *)malloc(sizeof(Node));

    /* Insert data into a node */
    newNode->data = element;
    newNode->next = NULL;

    /* Link a node to a list */
    if (head == NULL)
    {
        /* Set index of a first node */
        newNode->index = 0;
        head = newNode;
    }

    else
    {
        temp = head;

        /* Get the last node */
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        /* Add a new node at the end of a list */
        temp->next = newNode;

        /* Set index of a new node by incrementing an index of last node by 1 */
        newNode->index = temp->index + 1;
    }

    /* Return a pointer to a list */
    return head;
}

/*
    Function: printLinkedList()
    Process: Prints a linked list
    Input data (parameter): *myList - a pointer to a linked list
    Output data(parameter): none
    Output data (return): none
    Dependencies: printf()
    Time complexity: O(n)
*/
void printLinkedList(Node *list)
{
    /* Variable declaration */
    Node *head = list;

    /* If a list is empty then inform user */
    if (head == NULL)
    {
        printf("\nEmpty linked list");
    }

    else
    {
        /* Print linked list */
        printf(SPECIFIER, head->data);
        head = head->next;
        while (head)
        {
            printf(", " SPECIFIER, head->data);
            head = head->next;
        }
    }
}

/*
    Function: getData()
    Process: Gets the data from a file and stores in a linked list
    Input data (parameter): *file - name of a file
    Output data(parameter): none
    Output data (return): head - pointer to a linked list
    Dependencies: fopen(), fscanf(), addEnd(), fflush(), fclose(), printf()
    Time complexity: O(n)
*/
Node *getData(const char *file)
{
    /* Variable declaration */
    Node *head = NULL;
    int flag = TRUE;
    dtype value;
    FILE *fptr;

    /* Opening a file in read mode */
    fptr = fopen(file, "r");

    /* If file does not exist then inform user */
    if (fptr == NULL)
    {
        printf("\nFile not found!");
    }

    else
    {
        /* Get the value from a file */
        flag = fscanf(fptr, SPECIFIER, &value);

        while (flag != EOF)
        {
            /* Add a value into a linked list */
            head = addEnd(value, head);

            /* Get the value from a file */
            flag = fscanf(fptr, SPECIFIER, &value);
        }

        /* Close a file */
        fflush(fptr);
        fclose(fptr);
    }

    /* Return a pointer to a linked list */
    return head;
}

/*
    Function: saveData()
    Process: Saves data in a file
    Input data (parameter): *file - name of a file where data has to be stored
                            *myList - a pointer to a linked list
    Output data(parameter): none
    Output data (return): none
    Dependencies: fopen(), fclose(), printf()
    Time complexity: O(n)
*/
void saveData(const char *file, Node *myList)
{
    /* Variable declaration */
    Node *head = myList;
    FILE *fptr;

    /* Open a file */
    fptr = fopen(file, "w");

    /* Save data in a file */
    while (head != NULL)
    {
        fprintf(fptr, SPECIFIER "\n", head->data);
        head = head->next;
    }

    /* Close a file */
    fclose(fptr);
}

/*
    Function: sortData()
    Process: Sorts a data in a linked list and saves in a file
    Input data (parameter): *myList - a pointer to a linked list
    Output data(parameter): none
    Output data (return): head - a pointer to a linked list with sorted data
    Dependencies: mergeSort(), saveData()
    Time complexity: O(n log n)
*/
Node *sortData(Node *myList)
{
    /* Variable declaration */
    Node *head = NULL, *temp;
    int index = 0;

    head = mergeSort(myList);

    /* Change indexes of nodes */
    temp = head;
    while (temp)
    {
        temp->index = index;
        index++;
        temp = temp->next;
    }

    /* Save sorted list into a file */
    saveData(outputFileName, head);

    /* Return a pointer to a sorted list */
    return head;
}

/*
    Function: getMid()
    Process: Finds the middle node of a linked list
    Input data (parameter): *myList - a pointer to a linked list
    Output data(parameter): none
    Output data (return): middle - middle node of a linked list
    Dependencies: none
    Time complexity: O(n)
*/
Node *getMid(Node *myList)
{
    /* Variable declaration*/
    Node *middle = myList;

    /* Get last node of a list*/
    while (middle->next != NULL)
    {
        middle = middle->next;
    }

    /* Get index of middle node */
    int mid = (middle->index + myList->index) / 2;

    /* Find middle node of a list */
    middle = myList;
    while (middle->index != mid)
    {
        middle = middle->next;
    }

    /* Return middle node of a list*/
    return middle;
}

/*
    Function: mergeSort()
    Process: Sorts a data using merge sort algorithm
    Input data (parameter): *myList - a pointer to a linked list
    Output data(parameter): none
    Output data (return): head - pointer to a sorted linked list
    Dependencies: getMid(), merge()
    Time complexity: O(n log n)
*/
Node *mergeSort(Node *myList)
{
    /* Variable declaration */
    Node *left, *right, *rightNext, *head;

    if (myList == NULL || myList->next == NULL)
    {
        return myList;
    }

    /* Split lists into two halfs */
    left = myList;
    right = getMid(myList);
    rightNext = right->next;
    right->next = NULL;
    right = rightNext;

    left = mergeSort(left);
    right = mergeSort(right);

    /* Merge lists */
    head = merge(left, right);

    /* Return a pointer to a sorted list */
    return head;
}

/*
    Function: merge()
    Process: This function will merge two linked list
    Input data (parameter): *head1 - a pointer to a linked list 1
                            *head2 - a pointer to a linked list 2
    Output data(parameter): none
    Output data (return): head - pointer to a merged linked list
    Dependencies: free()
    Time complexity: O(n)
*/
Node *merge(Node *head1, Node *head2)
{
    /* Variable declaration */
    Node *head, *tail, *temp;

    head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    tail = head;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            tail->next = head1;
            head1 = head1->next;
        }
        else
        {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    if (head1 != NULL)
    {
        tail->next = head1;
    }
    if (head2 != NULL)
    {
        tail->next = head2;
    }

    temp = head;
    head = head->next;
    free(temp);

    /* Return a pointer to a merged list */
    return head;
}

/*
    Function: binarySearch()
    Process: Searches a data in a linked list using binary search algorithm
    Input data (parameter): *head - a pointer to a first node of a linked list
                            *tail - a pointer to a last node of a linked list
                            value - a value to be searched in a linked list
    Output data(parameter): none
    Output data (return): head - pointer to a node that contains a value
    Dependencies: binarySearch()
    Time complexity: O(log n)
*/
Node *binarySearch(Node *head, Node *tail, dtype value)
{
    /* Variable declaration */
    Node *middle = NULL, *prev_middle;
    int mid_index;

    /* Find index of middle node */
    mid_index = (head->index + tail->index) / 2;

    /* Find middle node */
    middle = head;
    while (middle->index != mid_index)
    {
        prev_middle = middle;
        middle = middle->next;
    }

    if (head != tail)
    {
        if (value < middle->data)
        {
            tail = prev_middle;
        }

        else if (value > middle->data)
        {
            head = middle->next;
        }

        else
        {
            /* Return a node with given value */
            return middle;
        }

        /* Recursive call */
        return binarySearch(head, tail, value);
    }

    if (head->data == value)
    {
        /* Return a node with given value */
        return head;
    }

    /* If no value found, then return NULL */
    return NULL;
}

/*
    Function: deleteList()
    Process: Remove nodes from a linked list
    Input data (parameter): *myList - a pointer to a linked list
    Output data(parameter): none
    Output data (return): none
    Dependencies: free()
    Time complexity: O(n)
*/
void deleteList(Node *myList)
{
    Node *temp;
    while (myList)
    {
        temp = myList;
        myList = myList->next;
        free(temp);
    }
}