/*
 * http://library.thinkquest.org/C005618/text/stacks.htm
 */
#include <cstdlib>

#include "List.h"
#define MAX_SIZE 1000

template<typename ItemType>
List<ItemType>::List() {
    list = new ListNode<ItemType>;
    list->next = NULL;
    prevcurrent = list;
    len = 0;
}
template<typename ItemType>
List<ItemType>::~List() {
    clear(); //delete all list nodes
    delete list; //delete header node
}

template<typename ItemType>
void List<ItemType>::insert(const ItemType) {
    
}

template<typename ItemType>
void List<ItemType>::clear() {
    
}

template<typename ItemType>
void List<ItemType>::deleteElement() {
    
}
template<typename ItemType>
void List<ItemType>::next() {
    
}
template<typename ItemType>
void List<ItemType>::prev() {
    
}
template<typename ItemType>
void List<ItemType>::reset() {
    
}
template<typename ItemType>
void List<ItemType>::clear() {
    
}

template<typename ItemType>
int List<ItemType>::length() {
    int length = 0;
    return length;
}

template<typename ItemType>
bool List<ItemType>::isEmpty() {
    return (len == 0);
}
template<typename ItemType>
bool List<ItemType>::isFull() {
    return (len == MAX_SIZE);
}