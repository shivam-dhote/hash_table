
#pragma once

#include "linkedlist.h"
#include "user.h"

typedef struct _hash_table {
    int size;
    int capacity;
    int (*hashFunction)(Key);
    int (*compareFunction)(Key, Key);
    LinkedList **table;
}HashTable;

typedef struct _key_value_pair {
    Key key;
    Value value;
}KeyValuePair;

/**
 * @brief Create a HashTable
 * @param capacity The capacity of the HashTable
 * @param hashFunction The hash function to be used
 * @param compareFunction The function to compare keys
 * @return A pointer to the created HashTable
 */
HashTable *createHashTable(int capacity, int (*hashFunction)(Key), int (*compareFunction)(Key, Key));

/**
 * @brief Insert a key-value pair into the HashTable
 * @param table The HashTable to which the key-value pair is to be inserted
 * @param key The key to be inserted
 * @param value The value to be inserted
 * @return 0 if successful, -1 otherwise
 */
int insert(HashTable *table, Key key, Value value);

/**
 * @brief Get the value corresponding to a key from the HashTable
 * @param table The HashTable from which the value is to be retrieved
 * @param key The key for which the value is to be retrieved
 * @return The value corresponding to the key, NULL otherwise
 */
Value *get(HashTable *table, Key key);

/**
 * @brief Remove a key-value pair from the HashTable
 * @param table The HashTable from which the key-value pair is to be removed
 * @param key The key to be removed
 * @return 0 if successful, -1 otherwise
 */
int removeKey(HashTable *table, Key key);