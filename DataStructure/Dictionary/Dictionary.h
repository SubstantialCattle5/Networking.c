/**
 * Declaration of Dictionary file
 * This file is part of the networking library
 *
 * Created by Nilay Nath Sharan
 * 16th December 2023.
*/

#ifndef Dictionary_h
#define Dictionary_h

#include "../tree/BinarySearchTree.h"
#include "Entry.h"

// MARK: DATA TYPES
// The dictionary is a collection of entries stored in a BinarySearchTree.
struct Dictionary
{
    /* MEMBER VARIABLES */
    // Inheriting the BinarySearchTree object.
    struct BinarySearchTree binary_search_tree;

    /* PUBLIC MEMBER METHODS */

    // Insert adds new items to the dictionary - the user need only specify the key, value, and their respective sizes.
    void (*insert)(struct Dictionary *dictionary, void *key, unsigned long key_size, void *value, unsigned long value_size);

    // Search looks for a given key in the dictionary and returns its value if found or NULL if not.
    void * (*search)(struct Dictionary *dictionary, void *key, unsigned long key_size);
};


// MARK: CONSTRUCTORS

/**
 * The constructor for a dictionary requires a compare function.  This will be passed on to the BinarySearchTree.
 * @param compare - void function pointer would be passed to bst for iterations and insertion
 * @return Dictionary
 */
struct Dictionary dictionary_constructor(int (*compare)(void *entry_one, void *entry_two));


/**
 * The destructor will need to free every node in the tree
 * @param dictionary
 */
void dictionary_destructor(struct Dictionary *dictionary) ;


// MARK: PUBLIC HELPER FUNCTIONS
int compare_string_keys(void *entry_one, void *entry_two);

#endif /* Dictionary_h */