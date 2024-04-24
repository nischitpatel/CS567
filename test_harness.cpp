// test_harness.cpp
#include <deepstate/DeepState.hpp>
#include "search_lib.h"
#include <vector>
#include <algorithm>

// Helper function to create a linked list from a vector of values
static Node* createLinkedList(const std::vector<dtype>& data) {
    Node* head = nullptr;
    for (const auto& value : data) {
        head = addEnd(value, head);
    }
    return head;
}

// Helper function to delete a linked list
static void deleteLinkedList(Node* head) {
    deleteList(head);
}

// Test case for getFirstOccurrence
TEST_CASE("getFirstOccurrence") {
    // Create a linked list with random values
    const auto data = DeepState_RandomVector<dtype>(0, 100);
    Node* head = createLinkedList(data);

    // Pick a random value to search for
    const dtype target = DeepState_Pick<dtype>(data);

    // Call the function under test
    const int index = getFirstOccurrence(target, head);

    // Check the result
    if (index != NOT_FOUND) {
        Node* curr = head;
        while (curr->index != index) {
            DeepState_Assert(curr->data != target);
            curr = curr->next;
        }
        DeepState_Assert(curr->data == target);
    } else {
        Node* curr = head;
        while (curr) {
            DeepState_Assert(curr->data != target);
            curr = curr->next;
        }
    }

    deleteLinkedList(head);
}

// Test case for getLastOccurrence
TEST_CASE("getLastOccurrence") {
    // ... (similar to "getFirstOccurrence" test case)
}

// Test case for getAllOccurrencesRet
TEST_CASE("getAllOccurrencesRet") {
    // ... (similar to "getFirstOccurrence" test case)
}

// Test case for addEnd
TEST_CASE("addEnd") {
    // Create an empty linked list
    Node* head = nullptr;

    // Add random values to the linked list
    const auto data = DeepState_RandomVector<dtype>(0, 100);
    for (const auto& value : data) {
        head = addEnd(value, head);
    }

    // Check that the linked list contains the added values in the correct order
    Node* curr = head;
    int index = 0;
    for (const auto& value : data) {
        DeepState_Assert(curr != nullptr);
        DeepState_Assert(curr->data == value);
        DeepState_Assert(curr->index == index++);
        curr = curr->next;
    }
    DeepState_Assert(curr == nullptr);

    deleteLinkedList(head);
}

// Test case for printLinkedList (no assertions, just printing)
TEST_CASE("printLinkedList") {
    const auto data = DeepState_RandomVector<dtype>(0, 100);
    Node* head = createLinkedList(data);

    printf("Printing linked list: ");
    printLinkedList(head);
    printf("\n");

    deleteLinkedList(head);
}

// Test case for getData
TEST_CASE("getData") {
    // Create a temporary file with random values
    const auto data = DeepState_RandomVector<dtype>(0, 100);
    const std::string tempFilePath = DeepState_InputVector<char>("temp.txt");
    FILE* tempFile = fopen(tempFilePath.c_str(), "w");
    for (const auto& value : data) {
        fprintf(tempFile, "%ld\n", value);
    }
    fclose(tempFile);

    // Call the function under test
    Node* head = getData(tempFilePath.c_str());

    // Check that the linked list contains the values from the file in the correct order
    Node* curr = head;
    for (const auto& value : data) {
        DeepState_Assert(curr != nullptr);
        DeepState_Assert(curr->data == value);
        curr = curr->next;
    }
    DeepState_Assert(curr == nullptr);

    deleteLinkedList(head);
}

// Test case for saveData (no assertions, just saving to a temporary file)
TEST_CASE("saveData") {
    const auto data = DeepState_RandomVector<dtype>(0, 100);
    Node* head = createLinkedList(data);

    const std::string tempFilePath = DeepState_InputVector<char>("temp.txt");
    saveData(tempFilePath.c_str(), head);

    deleteLinkedList(head);
}

// Test case for sortData
TEST_CASE("sortData") {
    const auto data = DeepState_RandomVector<dtype>(0, 100);
    Node* head = createLinkedList(data);

    // Call the function under test
    head = sortData(head);

    // Check that the linked list is sorted
    std::vector<dtype> sortedData(data);
    std::sort(sortedData.begin(), sortedData.end());

    Node* curr = head;
    int index = 0;
    for (const auto& value : sortedData) {
        DeepState_Assert(curr != nullptr);
        DeepState_Assert(curr->data == value);
        DeepState_Assert(curr->index == index++);
        curr = curr->next;
    }
    DeepState_Assert(curr == nullptr);

    deleteLinkedList(head);
}

// Test case for getMid
TEST_CASE("getMid") {
    const auto data = DeepState_RandomVector<dtype>(0, 100);
    Node* head = createLinkedList(data);

    // Call the function under test
    Node* mid = getMid(head);

    // Check that the returned node is the middle node
    Node* curr = head;
    int count = 0;
    while (curr != mid) {
        curr = curr->next;
        count++;
    }

    int expectedMidIndex = (head->index + count) / 2;
    DeepState_Assert(mid->index == expectedMidIndex);

    deleteLinkedList(head);
}

// Test case for mergeSort
TEST_CASE("mergeSort") {
    const auto data = DeepState_RandomVector<dtype>(0, 100);
    Node* head = createLinkedList(data);

    // Call the function under test
    head = mergeSort(head);

    // Check that the linked list is sorted
    std::vector<dtype> sortedData(data);
    std::sort(sortedData.begin(), sortedData.end());

    Node* curr = head;
    int index = 0;
    for (const auto& value : sortedData) {
        DeepState_Assert(curr != nullptr);
        DeepState_Assert(curr->data == value);
        DeepState_Assert(curr->index == index++);
        curr = curr->next;
    }
    DeepState_Assert(curr == nullptr);

    deleteLinkedList(head);
}

// Test case for merge (helper function for mergeSort)
TEST_CASE("merge") {
    const auto data1 = DeepState_RandomVector<dtype>(0, 100);
    const auto data2 = DeepState_RandomVector<dtype>(0, 100);

    Node* head1 = createLinkedList(data1);
    Node* head2 = createLinkedList(data2);

    // Call the function under test
    Node* merged = merge(head1, head2);

    // Check that the merged list is sorted
    std::vector<dtype> mergedData(data1);
    mergedData.insert(mergedData.end(), data2.begin(), data2.end());
    std::sort(mergedData.begin(), mergedData.end());

    Node* curr = merged;
    int index = 0;
    for (const auto& value : mergedData) {
        DeepState_Assert(curr != nullptr);
        DeepState_Assert(curr->data == value);
        DeepState_Assert(curr->index == index++);
        curr = curr->next;
    }
    DeepState_Assert(curr == nullptr);

    deleteLinkedList(merged);
    deleteLinkedList(head1);
    deleteLinkedList(head2);
}

// Test case for binarySearch
TEST_CASE("binarySearch") {
    const auto data = DeepState_RandomVector<dtype>(0, 100);
    Node* head = createLinkedList(data);
    std::sort(data.begin(), data.end()); // Sort the data for binary search

    // Pick a random value to search for
    const dtype target = DeepState_Pick<dtype>(data);

    // Call the function under test
    Node* found = binarySearch(head, nullptr, target);

    // Check the result
    if (found != nullptr) {
        DeepState_Assert(found->data == target);
    } else {
        Node* curr = head;
        while (curr) {
            DeepState_Assert(curr->data != target);
            curr = curr->next;
        }
    }

    deleteLinkedList(head);
}

// Test case for deleteList
TEST_CASE("deleteList") {
    const auto data = DeepState_RandomVector<dtype>(0, 100);
    Node* head = createLinkedList(data);

    // Call the function under test
    deleteList(head);

    // Check that the linked list is empty
    DeepState_Assert(head == nullptr);
}

int main(int argc, char* argv[]) {
    return DeepState_Run(argc, argv);
}