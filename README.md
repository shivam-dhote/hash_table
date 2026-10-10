# hash_table
hash table in C
# hash_table


Simple C hash-table library.

Build
-----

To build the static library run:

```sh
make
```

This produces:

- `build/lib/libhash_table.a` — static library

API
---

Public header: include/hash_table.h

Link against the library (ensure the linker can find libhash_table.a and link with `-lhash_table`).

Clean
-----

```sh
make clean
```


Prebuilt Library
-----------------

If you only need the library (no example), run:

# hash_table

API
---

Public header: include/hash_table.h

Usage
-----

Include the public header and link against the prebuilt library (ensure the header path and library path are provided to your compiler/linker).


Build
-----

To build the static library run (default):

```sh
make
```

This produces:

- `build/lib/libhash_table.a` — static library


Clean
-----

```sh
make clean
```

Prebuilt Library
-----------------

If you only need the library, run:

```sh
make lib-only
```

To produce a prebuilt artifact for the current platform (copied to `prebuilt/<platform>`), run:

```sh
make prebuilt
```

On Linux the prebuilt library will be at `prebuilt/linux/libhash_table.a`.

API note
--------

Helper: `destroyHashTable(HashTable *table)` is available to free a table and its contents; its prototype is in `include/hash_table.h`.

