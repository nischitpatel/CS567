/*
    By: Nischit Patel
*/

/* Pre-processors*/
#include "search_lib.h"
#include <stdio.h>

const char *inputFileName = "myData_CS599.csv";
const char *outputFileName = "sorted_data.csv";

/* Main block */
int main()
{
    /* Variable declaration */
    Node *list = NULL, *all_occurrences;
    int occurrences, index, index_2, length;
    dtype element;
    dtype values[] = {232, 649, 989, 1447, 1909};

    length = sizeof(values) / sizeof(dtype);

    /* Get the data from a file */
    list = getData(inputFileName);

    /* Sort the data */
    list = sortData(list);

    /* Demonstarting first, last and all occurrences of 232, 649, 989, 1447, and 1909*/
    for (index = 0; index < length; index++)
    {
        element = values[index];
        occurrences = getFirstOccurrence(element, list);
        if (occurrences != NOT_FOUND)
        {
            printf("\nFirst occurrence of " SPECIFIER " is found at index %d", element, occurrences);

            occurrences = getLastOccurrence(element, list);
            printf("\nLast occurrence of " SPECIFIER " is found at index %d", element, occurrences);

            all_occurrences = getAllOccurrencesRet(element, list, &occurrences);
            printf("\nWe have found %d occurrences of " SPECIFIER " at indexes ", occurrences, element);
            printf("%d", all_occurrences->index);
            for (index_2 = 0; index_2 < occurrences - 1; index_2++)
            {
                all_occurrences = all_occurrences->next;
                printf(", %d", all_occurrences->index);
            }
        }
        else
        {
            printf("\n" SPECIFIER " is not present in a linked list", element);
        }
        printf("\n");
    }
    /* Printing a new line for cleanliness */
    printf("\n");

    /* Delete a list */
    deleteList(list);

    /* Return success */
    return 0;
}