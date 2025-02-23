/**
 * @file linkedlist.h
 * @brief This file contains the declaration of a doubly linked list, including
 * 
 * This file contains the declaration of a doubly linked list, including
 * functions to create a new list, add a node at the head, and remove a node.
 * 
 * @date 2025-02-20 Initial implementation.
 */

#pragma once

typedef struct _node
{
    void *data;
    struct _node *next;
    struct _node *prev;
}Node;

typedef struct _linkedlist
{
    Node *head;
    Node *tail;
}LinkedList;

/**
    * @brief Create a LinkedList
    * @return A pointer to head of the created LinkedList
 */
LinkedList *createLinkedList();


/**
    * @brief Add a node to the LinkedList at head
    * @param list The LinkedList to which the node is to be added
    * @param data The data to be added to the LinkedList
    * @return 0 if successful, -1 otherwise
 */
int addNodeAtHead(LinkedList *list, void *data);


/**
    * @brief remove a node from the LinkedList
    * @param list The LinkedList from which the node is to be removed
    * @param node The node to be removed from the LinkedList
 */
int removeNode(LinkedList *list, Node *node);

// End of file linkedlist.h