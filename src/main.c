
#include <stdio.h>
#include "hash_table.h"
#include "user.h"

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


int main() 
{
    HashTable *table = createHashTable(10, hashFunction, compareFunction);
    Key k = {1};
    Value v = {10};
    insert(table, k, v);
    Value *val = get(table, k);
    printf("%d\n", val->data);
    k.data = 2;
    v.data = 20;  
    insert(table, k, v);
    printf("%d\n", get(table, k)->data);

    removeKey(table, k);
    val = get(table, k);
    if (val == NULL)
    {
        printf("Key not found\n");
    }
    k.data = 1;
    printf("%d\n", get(table, k)->data);
    return 0;
}