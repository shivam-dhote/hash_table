
#include <stdio.h>
#include "hash_table.h"

struct key
{
    int x,
        y,
        z;
};

struct value
{
    int val;
};

int hashFunction(void *key)
{
    struct key *k = (struct key *)key;
    return k->x*1249 + k->y*331 + k->z*1151;
}

int compareFunction(void *key1, void *key2)
{
    struct key *k1 = (struct key *)key1;
    struct key *k2 = (struct key *)key2;
    return k1->x == k2->x && k1->y == k2->y && k1->z == k2->z;
}

int main() 
{
    HashTable *table = createHashTable(10, hashFunction, compareFunction);
    struct key k = {1, 2, 3};
    struct value v = {10};
    insert(table, &k, &v);
    struct value *val = (struct value *)get(table, &k);
    printf("%d\n", val->val);
    
    k.x = 4;
    k.y = 5;
    k.z = 6;
    v.val = 20;
    insert(table, &k, &v);
    val = (struct value *)get(table, &k);
    printf("%d\n", val->val);
    removeKey(table, &k);
    return 0;
}