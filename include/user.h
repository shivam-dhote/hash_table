#pragma once

typedef struct _key {
    int data;
    /* customize this type as per your need */
}Key;

typedef struct _value {
    int data;
    /* customize this type as per your need */
}Value;


extern int hashFunction(Key key);
extern int compareFunction(Key k1, Key k2);
// End of file User.h