/* 
 * File:   Stack.cpp
 * Author: doghmen
 * 
 * Created on 31 mars 2011, 16:55
 * http://library.thinkquest.org/C005618/text/binarytrees.htm# --Stack LIFO 
 */
#include <cstdlib>
#include "Stack.h"

#define MAX_SIZE 1000

template <class ItemType>
Stack<ItemType>::Stack() {
    counter = 0;
    head = NULL;
}


template <class ItemType>
Stack<ItemType>::Stack(const Stack& orig) {
}

template <class ItemType>
Stack<ItemType>::~Stack() {
    delete head;
    counter = 0;
}

template <class ItemType>
ItemType Stack<ItemType>::pop(){
	return head;
}

template <class ItemType>
void Stack<ItemType>::push(const ItemType element){
    StackNode<ItemType> s;
    head = s;
    s->data = element;
    s->next = NULL;
    counter ++;
}

template <class ItemType>
ItemType Stack<ItemType>::top() const {
	return head;
}

template <class ItemType>
void Stack<ItemType>::clear(){
//    while(!head->isEmpty()) {
//	pop(head);
//    }
//	delete head;
//	counter = 0;
}
 
template <class ItemType>
bool Stack<ItemType>::isEmpty() const {
    return (counter == 0);

}

template <class ItemType>
bool Stack<ItemType>::isFull() const {
    return (counter == MAX_SIZE);

}

template <class ItemType>
int Stack<ItemType>::count() const {
	return counter;
 }
