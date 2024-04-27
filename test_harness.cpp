#include <deepstate/DeepState.hpp>
#include <fstream>
#include "genome_processing.h"
#include "my_strings.h"
#include "prefix_trie.h"

using namespace deepstate;

TEST(GenomeProcessing, TestGenomeSize) {
    // Generate a random genome size
    long long int size = DeepState_LongLongInRange(0, 1000000);

    // Set up GenomeProcessing object
    GENOMEPROCESSING genomeProcessor;
    genomeProcessor.setGenomeSize(size);

    // Test getGenomeSize function
    ASSERT_EQ(genomeProcessor.getGenomeSize(), size);
}

TEST(MyStrings, TestStringCopy) {
    // Generate random source and destination strings
    char source[100];
    char destination[100];
    DeepState_CharArray(source, 100);
    DeepState_CharArray(destination, 100);

    // Copy the source string to the destination string
    strCpy(destination, source);

    // Check if the destination string matches the source string
    ASSERT_EQ(strcmp(destination, source), 0);
}

TEST(PrefixTrie, TestTrieInsertion) {
    // Create a Prefix Trie object
    Prefix_Trie trie;

    // Generate a random query
    char query[37]; // Maximum query length is 36
    DeepState_CharArray(query, 36);

    // Insert the query into the trie
    long nodes = trie.insert(query);

    // Assert that nodes were added to the trie
    ASSERT_GT(nodes, 0);
}

// Add more test cases for other functions as needed...