


#include "linkedlist.h"
#include "hash_table.h"
#include <stdlib.h>



/**
 * Create a HashTable
 * @param capacity The capacity of the HashTable
 * @param hashFunction The hash function to be used
 * @param compareFunction The function to compare keys
 * @return A pointer to the created HashTable
 */
HashTable *createHashTable(int capacity, int (*hashFunction)(void *keys), int (*compareFunction)(void *key1, void *key2))
{
    HashTable *hash_table = (HashTable *)malloc(sizeof(HashTable));
    if (hash_table == NULL)
    {
        return NULL;
    }
    hash_table->size = 0;
    hash_table->capacity = capacity;
    hash_table->hashFunction = hashFunction;
    hash_table->compareFunction = compareFunction;
    hash_table->table = (LinkedList **)calloc(capacity, sizeof(LinkedList *));
    if (hash_table->table == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < capacity; i++)
    {
        hash_table->table[i] = createLinkedList();
        if (hash_table->table[i] == NULL)
        {
            return NULL;
        }
    }
    return hash_table;
}

/**
 * Insert a key-value pair into the HashTable
 * @param table The HashTable to which the key-value pair is to be inserted
 * @param key The key to be inserted
 * @param value The value to be inserted
 * @return 0 if successful, -1 otherwise
 */
int insert(HashTable *table, void *key, void *value)
{
    if (table == NULL)
    {
        return -1;
    }
    int index = table->hashFunction(key) % table->capacity;
    KeyValuePair *pair = (KeyValuePair *)malloc(sizeof(KeyValuePair));
    if (pair == NULL)
    {
        return -1;
    }
    pair->key = key;
    pair->value = value;
    if (addNodeAtHead(table->table[index], pair) == -1)
    {
        return -1;
    }
    table->size++;
    return 0;
}

/**
 * Get the value corresponding to a key from the HashTable
 * @param table The HashTable from which the value is to be retrieved
 * @param key The key for which the value is to be retrieved
 * @return The value corresponding to the key, NULL otherwise
 */
void *get(HashTable *table, void *key)
{
    if (table == NULL)
    {
        return NULL;
    }
    int index = table->hashFunction(key) % table->capacity;
    Node *current = table->table[index]->head->next;
    while (current != table->table[index]->tail)
    {
        KeyValuePair *pair = (KeyValuePair *)current->data;
        if (table->compareFunction(pair->key, key))
        {
            return pair->value;
        }
        current = current->next;
    }
    return NULL;
}

/**
 * Remove a key-value pair from the HashTable
 * @param table The HashTable from which the key-value pair is to be removed
 * @param key The key to be removed
 * @return 0 if successful, -1 otherwise
 */
int removeKey(HashTable *table, void *key)
{
    if (table == NULL)
    {
        return -1;
    }
    int index = table->hashFunction(key) % table->capacity;
    Node *current = table->table[index]->head->next;
    while (current != table->table[index]->tail)
    {
        KeyValuePair *pair = (KeyValuePair *)current->data;
        if (table->compareFunction(pair->key, key))
        {
            removeNode(table->table[index], current);
            table->size--;
            return 0;
        }
        current = current->next;
    }
    return -1;
}

// End of file hash_table.c

