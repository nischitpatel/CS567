#include <deepstate/DeepState.hpp>
#include "search_lib.h"

using namespace deepstate;

#define MAX_LIST_SIZE 100

TEST(DeleteList, DeleteEntireList) {
  /* Generate a random list */
  Node *myList = NULL;
  int listSize = DeepState_IntInRange(1, MAX_LIST_SIZE);
  for (int i = 0; i < listSize; ++i) {
    dtype value = DeepState_Int();
    myList = addEnd(value, myList);
  }

  /* Delete the list */
  deleteList(myList);

  /* Ensure the list is empty */
  ASSERT_TRUE(myList == NULL) << "List is not empty after deleteList";
}

TEST(DeleteList, DeleteEmptyList) {
  /* Delete an empty list */
  Node *myList = NULL;
  deleteList(myList);

  /* Ensure the list remains empty */
  ASSERT_TRUE(myList == NULL) << "List is not empty after deleteList";
}

TEST(DeleteList, DeleteListWithSingleNode) {
  /* Create a list with a single node */
  Node *myList = addEnd(DeepState_Int(), NULL);

  /* Delete the list */
  deleteList(myList);

  /* Ensure the list is empty */
  ASSERT_TRUE(myList == NULL) << "List is not empty after deleteList";
}

TEST(DeleteList, DeletePartialList) {
  /* Generate a random list */
  Node *myList = NULL;
  int listSize = DeepState_IntInRange(2, MAX_LIST_SIZE);
  for (int i = 0; i < listSize; ++i) {
    dtype value = DeepState_Int();
    myList = addEnd(value, myList);
  }

  /* Randomly select a position to stop deletion */
  int stopIndex = DeepState_IntInRange(0, listSize - 1);

  /* Delete part of the list */
  Node *temp = myList;
  for (int i = 0; i < stopIndex; ++i) {
    temp = temp->next;
  }
  deleteList(temp->next);
  temp->next = NULL;

  /* Ensure the list remains consistent */
  int length = 0;
  Node *curr = myList;
  while (curr != NULL) {
    ++length;
    curr = curr->next;
  }
  ASSERT_EQ(length, stopIndex) << "List length is inconsistent after deleteList";
}