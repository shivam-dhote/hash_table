/**
 * @file linkedlist.c
 * @brief Implementation of a doubly linked list.
 * 
 * This file contains the implementation of a doubly linked list, including
 * functions to create a new list, add a node at the head, and remove a node.
 * 
 * @date 2025-02-20 Initial implementation.
 */


#include "linkedlist.h"
#include <stdlib.h>

/**
 * Create a new linked list
 * @return LinkedList* - a pointer to the new linked list, NULL otherwise.
 */
LinkedList *createLinkedList()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    if (list == NULL)
    {
        return NULL;
    }
    list->head = (Node *)calloc(1, sizeof(Node));
    list->tail = (Node *)calloc(1, sizeof(Node));
    if (list->head == NULL || list->tail == NULL)
    {
        return NULL;
    }
    list->head->next = list->tail;
    list->tail->prev = list->head;
    return list;
}

/**
 * Add a node to the LinkedList at head
 * @param list - The LinkedList to which the node is to be added
 * @param data - The data to be added to the LinkedList
 * @return int - 0 if successful, -1 otherwise
 */
int addNodeAtHead(LinkedList *list, void *data)
{
    if (list == NULL)
    {
        return -1;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        return -1;
    }
    newNode->data = data;
    newNode->next = list->head->next;
    newNode->prev = list->head;
    list->head->next->prev = newNode;
    list->head->next = newNode;
    return 0;
}

/**
 * Remove a node from the LinkedList
 * @param list - The LinkedList from which the node is to be removed
 * @param node - The node to be removed from the LinkedList
 * @return int - 0 if successful, -1 otherwise
 */
int removeNode(LinkedList *list, Node *node)
{
    if (list == NULL || node == NULL)
    {
        return -1;
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);
    return 0;
}



// End of file linkedlist.c